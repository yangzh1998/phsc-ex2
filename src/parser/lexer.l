%{
#include <stdint.h> // int64_t INT32_MAX INT32_MIN
#include <string>
#include <assert.h>
#include <cstdlib> // atof atoll exit
#include "parser.hpp"
#include "hamsic-lexer.h"
#include "../driver/option.h" // warning option
#include "../ast/includes.h"
#include "../report/lexical-error.h"
#include "../report/overflow-warning.h"

#ifndef TOKEN
#define TOKEN phsc::HamsicParser::token
#endif

#ifndef YY_DECL
#define YY_DECL \
  int phsc::HamsicLexer::lex( \
  phsc::HamsicParser::semantic_type* yylval, \
  phsc::HamsicParser::location_type* yylloc \
)
#endif

#ifndef NEW_KEYWORD
#define NEW_KEYWORD(token) { yylval->keyword = new phsc::Keyword(*yylloc, token); }
#endif
%}

/* Otherwise there's a fatal error. */
%option noyywrap

/* To generate a C++ file, not a C one. */
%option c++

NEWLINE       (\r|\n|\r\n)
DIGIT         [0-9]
VALUE_FLOAT   (-?{DIGIT}+\.{DIGIT}+)
VALUE_INT     (-?{DIGIT}+)
IDENTIFIER    ([_A-Za-z][_0-9A-Za-z]*)
LINE_COMMENT  (\/\/[^\n\r]*{NEWLINE})
/* BLOCK_COMMENT (\/\*[.\n]*\*\/) */
WHITESPACE    ([ \t]+)
SINGLE_SYM    ("+"|"-"|"*"|"/"|"%"|"|"|"&"|"~"|"^"|"!"|","|"."|";"|"="|">"|"<"|"("|")"|"["|"]"|"{"|"}")

/* The start contition for string literal. */
%x S

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%%

%{
  /* code to place at the beginning of yylex() */
  // reset location
  yylloc->step();
%}

{WHITESPACE}        { yylloc->step(); }
{NEWLINE}           { yylloc->lines(); yylloc->step(); }
{LINE_COMMENT}      { yylloc->lines(); yylloc->step(); }

"i32"               { NEW_KEYWORD(TOKEN::I32); return TOKEN::I32; }
"f64"               { NEW_KEYWORD(TOKEN::F64); return TOKEN::F64; }
"str"               { NEW_KEYWORD(TOKEN::STR); return TOKEN::STR; }
"mut"               { NEW_KEYWORD(TOKEN::MUT); return TOKEN::MUT; }
"own"               { NEW_KEYWORD(TOKEN::OWN); return TOKEN::OWN; }
"struct"            { NEW_KEYWORD(TOKEN::STRUCT); return TOKEN::STRUCT; }
"new"               { NEW_KEYWORD(TOKEN::NEW); return TOKEN::NEW; }
"fn"                { NEW_KEYWORD(TOKEN::FN); return TOKEN::FN; }
"ret"               { NEW_KEYWORD(TOKEN::RET); return TOKEN::RET; }
"null"              { NEW_KEYWORD(TOKEN::NULL_); return TOKEN::NULL_; }
"if"                { NEW_KEYWORD(TOKEN::IF); return TOKEN::IF; }
"else"              { NEW_KEYWORD(TOKEN::ELSE); return TOKEN::ELSE; }
"while"             { NEW_KEYWORD(TOKEN::WHILE); return TOKEN::WHILE; }
"for"               { NEW_KEYWORD(TOKEN::FOR); return TOKEN::FOR; }
"break"             { NEW_KEYWORD(TOKEN::BREAK); return TOKEN::BREAK; }
"continue"          { NEW_KEYWORD(TOKEN::CONTINUE); return TOKEN::CONTINUE; }

"<<"          { NEW_KEYWORD(TOKEN::SHIFT_LEFT); return TOKEN::SHIFT_LEFT; }
">>"          { NEW_KEYWORD(TOKEN::SHIFT_RIGHT); return TOKEN::SHIFT_RIGHT; }
"=="          { NEW_KEYWORD(TOKEN::EQUAL); return TOKEN::EQUAL; }
"!="          { NEW_KEYWORD(TOKEN::NOT_EQUAL); return TOKEN::NOT_EQUAL; }
">="          { NEW_KEYWORD(TOKEN::GREATER_EQUAL); return TOKEN::GREATER_EQUAL; }
"<="          { NEW_KEYWORD(TOKEN::LESS_EQUAL); return TOKEN::LESS_EQUAL; }
"&&"          { NEW_KEYWORD(TOKEN::AND); return TOKEN::AND; }
"||"          { NEW_KEYWORD(TOKEN::OR); return TOKEN::OR; }
"+="          { NEW_KEYWORD(TOKEN::ADD_ASSIGN); return TOKEN::ADD_ASSIGN; }
"-="          { NEW_KEYWORD(TOKEN::SUB_ASSIGN); return TOKEN::SUB_ASSIGN; }
"*="          { NEW_KEYWORD(TOKEN::MUL_ASSIGN); return TOKEN::MUL_ASSIGN; }
"/="          { NEW_KEYWORD(TOKEN::DIV_ASSIGN); return TOKEN::DIV_ASSIGN; }
"%="          { NEW_KEYWORD(TOKEN::MOD_ASSIGN); return TOKEN::MOD_ASSIGN; }
"&="          { NEW_KEYWORD(TOKEN::AND_ASSIGN); return TOKEN::AND_ASSIGN; }
"^="          { NEW_KEYWORD(TOKEN::XOR_ASSIGN); return TOKEN::XOR_ASSIGN; }
"|="          { NEW_KEYWORD(TOKEN::OR_ASSIGN); return TOKEN::OR_ASSIGN; }
"<<="         { NEW_KEYWORD(TOKEN::SHIFT_LEFT_ASSIGN);
                return TOKEN::SHIFT_LEFT_ASSIGN; }
">>="         { NEW_KEYWORD(TOKEN::SHIFT_RIGHT_ASSIGN);
                return TOKEN::SHIFT_RIGHT_ASSIGN; }

{SINGLE_SYM}        { NEW_KEYWORD((int)(*yytext)); return (int)(*yytext); }

<INITIAL>"\""       { BEGIN(S); _buffer.clear(); }
<S>{NEWLINE}        {
  std::string s;
  s.assign(_buffer.begin(), _buffer.end());
  _errors.emplace_back(new phsc::NewlineInStrError(*yylloc, s));
}
<S><<EOF>>          {
  std::string s;
  s.assign(_buffer.begin(), _buffer.end());
  _errors.emplace_back(new phsc::UnterminatedStrError(*yylloc, s));
}
<S>"\""             {
  BEGIN(INITIAL);
  std::string s;
  s.assign(_buffer.begin(), _buffer.end());
  yylval->expr = new phsc::StrLiteral(*yylloc, s);
  return TOKEN::LITERAL_STR;
}
<S>"\\n"            { _buffer.push_back('\n'); }
<S>"\\t"            { _buffer.push_back('\t'); }
<S>"\\\""           { _buffer.push_back('\"'); }
<S>"\\\\"           { _buffer.push_back('\\'); }
<S>.                { _buffer.push_back(*yytext); }

{VALUE_FLOAT}       {
  double f64 = atof(yytext);
  if (_option.m_overflow_warning && f64==atof("inf")) {
    if (_option.m_warning_as_error) {
      _errors.emplace_back(new phsc::F64OverflowWarning(*yylloc,
      std::string(yytext)));
    } else {
      _warnings.emplace_back(new phsc::F64OverflowWarning(*yylloc,
      std::string(yytext)));
    }
  }
  yylval->expr = new phsc::F64Literal(*yylloc, f64);
  return TOKEN::LITERAL_F64;
}

{VALUE_INT}         {
  /* If a string exceeds the range of int64_t, atoll returns INT64_MAX or
   * INT64_MIN. So it's ok to judge int32_t overflow in this way.
   */
  int64_t i64 = atoll(yytext);
  if (_option.m_overflow_warning && (i64 > INT32_MAX || i64 < INT32_MIN)) {
    if (_option.m_warning_as_error) {
      _errors.emplace_back(new phsc::I32OverflowWarning(*yylloc,
      std::string(yytext)));
    } else {
      _warnings.emplace_back(new phsc::I32OverflowWarning(*yylloc,
      std::string(yytext)));
    }
  }
  yylval->expr = new phsc::I32Literal(*yylloc, static_cast<int32_t>(i64));
  return TOKEN::LITERAL_I32;
}

{IDENTIFIER}        {
  yylval->ident = new std::string(yytext, yyleng);
  return TOKEN::IDENTIFIER;
}

.                   {
  _errors.emplace_back(new phsc::UnrecognizedCharError(*yylloc, *yytext));
}

%%

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int yyFlexLexer::yylex()
{
  assert(false);
  return 0;
}
