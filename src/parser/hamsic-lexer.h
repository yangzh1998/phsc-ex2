/**
 * @file parser/hamsic-lexer.h
 * @brief Subclass of the auto-generated lexer
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-22
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef PARSER_HAMSIC_LEXER_H
#define PARSER_HAMSIC_LEXER_H

// really ugly implement! Shit
#ifndef __FLEX_LEXER_H
#define yyFlexLexer yyFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
#endif

#include <vector>
#include <memory> // unique_ptr
#include "parser.hpp"

namespace phsc {

class HamsicReport;
class HamsicWarning;
class Option;

class HamsicLexer : public yyFlexLexer {
public:
  HamsicLexer(std::vector<std::unique_ptr<phsc::HamsicReport>>& errors,
              std::vector<std::unique_ptr<phsc::HamsicWarning>>& warnings,
              const phsc::Option& option,
              std::istream* input = 0, std::ostream* output = 0):
      yyFlexLexer(input, output), _errors(errors), _warnings(warnings),
      _option(option) {}
  
  int lex(phsc::HamsicParser::semantic_type* yylval,
          phsc::HamsicParser::location_type* yylloc);
  
private:
  std::vector<char> _buffer;
  std::vector<std::unique_ptr<phsc::HamsicReport>>& _errors;
  std::vector<std::unique_ptr<phsc::HamsicWarning>>& _warnings;
  const phsc::Option& _option;
}; // HamsicLexer

} // namespace phsc

#endif /* PARSER_HAMSIC_LEXER_H */
