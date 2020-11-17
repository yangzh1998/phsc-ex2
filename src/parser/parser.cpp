/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   phsclex

#include "parser.hpp"

/* User implementation prologue.  */
#line 113 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"

#include "hamsic-lexer.h"
#include "../report/syntax-error.h"

#ifdef yylex
#undef yylex
#endif
#define yylex _lexer.lex


/* Line 317 of lalr1.cc.  */
#line 54 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace phsc
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  HamsicParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  HamsicParser::HamsicParser (phsc::HamsicLexer& _lexer_yyarg, std::unique_ptr<phsc::ASTRoot>& _tree_yyarg, std::vector<std::unique_ptr<phsc::HamsicReport>>& _errors_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      _lexer (_lexer_yyarg),
      _tree (_tree_yyarg),
      _errors (_errors_yyarg)
  {
  }

  HamsicParser::~HamsicParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  HamsicParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  HamsicParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  HamsicParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  HamsicParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  HamsicParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  HamsicParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  HamsicParser::debug_level_type
  HamsicParser::debug_level () const
  {
    return yydebug_;
  }

  void
  HamsicParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  HamsicParser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
#line 125 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.tree) = new phsc::ASTRoot((yyloc), *((yysemantic_stack_[(1) - (1)].defs)));
                    _tree.reset((yyval.tree));
                  ;}
    break;

  case 3:
#line 131 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.defs) = (yysemantic_stack_[(2) - (1)].defs);
                    (yyval.defs)->emplace_back((yysemantic_stack_[(2) - (2)].def));
                  ;}
    break;

  case 4:
#line 135 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.defs) = new std::vector<std::unique_ptr<phsc::ASTNode>>();
                  ;}
    break;

  case 5:
#line 140 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.def) = (yysemantic_stack_[(1) - (1)].sdef); ;}
    break;

  case 6:
#line 141 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.def) = (yysemantic_stack_[(1) - (1)].fdef); ;}
    break;

  case 7:
#line 144 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.sdef) = new phsc::StructDef((yylocation_stack_[(5) - (2)]), *((yysemantic_stack_[(5) - (2)].ident)), *((yysemantic_stack_[(5) - (4)].vdefs)));
                  ;}
    break;

  case 8:
#line 149 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.vdefs) = (yysemantic_stack_[(2) - (1)].vdefs);
                    (yyval.vdefs)->emplace_back((yysemantic_stack_[(2) - (2)].vdef));
                  ;}
    break;

  case 9:
#line 153 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.vdefs) = new std::vector<std::unique_ptr<phsc::VarDef>>();
                  ;}
    break;

  case 10:
#line 158 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.vdef) = (yysemantic_stack_[(2) - (1)].vdef); ;}
    break;

  case 11:
#line 159 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.vdef) = (yysemantic_stack_[(3) - (2)].vdef);
                    (yysemantic_stack_[(3) - (2)].vdef)->setOwnership(true);
                  ;}
    break;

  case 12:
#line 165 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.vdef) = new VarDef((yylocation_stack_[(2) - (2)]), *((yysemantic_stack_[(2) - (2)].ident)), *((yysemantic_stack_[(2) - (1)].type)));
                  ;}
    break;

  case 13:
#line 170 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.type) = (yysemantic_stack_[(1) - (1)].type); ;}
    break;

  case 14:
#line 171 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.type) = (yysemantic_stack_[(2) - (2)].type);
                    (yyval.type)->setMutable(true);
                  ;}
    break;

  case 15:
#line 177 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.type) = new phsc::TypeBasic((yyloc), phsc::TypeBasic::TypeTag::I32);
                  ;}
    break;

  case 16:
#line 180 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.type) = new phsc::TypeBasic((yyloc), phsc::TypeBasic::TypeTag::F64);
                  ;}
    break;

  case 17:
#line 183 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.type) = new phsc::TypeBasic((yyloc), phsc::TypeBasic::TypeTag::STR);
                  ;}
    break;

  case 18:
#line 186 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.type) = new phsc::TypeStruct((yyloc), *((yysemantic_stack_[(2) - (2)].ident)));
                  ;}
    break;

  case 19:
#line 189 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.type) = new phsc::TypeArray((yyloc), *((yysemantic_stack_[(3) - (1)].type)), false);
                  ;}
    break;

  case 20:
#line 192 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.type) = new phsc::TypeArray((yyloc), *((yysemantic_stack_[(4) - (1)].type)), true);
                  ;}
    break;

  case 21:
#line 195 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.type) = (yysemantic_stack_[(3) - (2)].type); ;}
    break;

  case 22:
#line 198 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.fdef) = new phsc::FuncDef((yylocation_stack_[(6) - (2)]), *((yysemantic_stack_[(6) - (2)].ident)), *((yysemantic_stack_[(6) - (4)].vdefs)), *((yysemantic_stack_[(6) - (6)].block)));
                  ;}
    break;

  case 23:
#line 203 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.vdefs) = (yysemantic_stack_[(3) - (1)].vdefs);
                    (yyval.vdefs)->emplace_back((yysemantic_stack_[(3) - (3)].vdef));
                  ;}
    break;

  case 24:
#line 207 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.vdefs) = new std::vector<std::unique_ptr<phsc::VarDef>>();
                    (yyval.vdefs)->emplace_back((yysemantic_stack_[(1) - (1)].vdef));
                  ;}
    break;

  case 25:
#line 211 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.vdefs) = new std::vector<std::unique_ptr<phsc::VarDef>>();
                  ;}
    break;

  case 26:
#line 216 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.block) = new phsc::Block((yyloc), *((yysemantic_stack_[(3) - (2)].stmts)));
                  ;}
    break;

  case 27:
#line 221 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmts) = (yysemantic_stack_[(2) - (1)].stmts);
                    (yyval.stmts)->emplace_back((yysemantic_stack_[(2) - (2)].stmt));
                  ;}
    break;

  case 28:
#line 225 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmts) = new std::vector<std::unique_ptr<phsc::ASTNode>>();
                  ;}
    break;

  case 29:
#line 230 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].vdef); ;}
    break;

  case 30:
#line 231 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].vdefass); ;}
    break;

  case 31:
#line 232 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = new phsc::Break((yylocation_stack_[(2) - (1)])); ;}
    break;

  case 32:
#line 233 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = new phsc::Continue((yylocation_stack_[(2) - (1)])); ;}
    break;

  case 33:
#line 234 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = new phsc::Return((yylocation_stack_[(2) - (1)])); ;}
    break;

  case 34:
#line 235 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].block); ;}
    break;

  case 35:
#line 236 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(2) - (1)].stmt); ;}
    break;

  case 36:
#line 237 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].stmt); ;}
    break;

  case 37:
#line 238 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].stmt); ;}
    break;

  case 38:
#line 239 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].stmt); ;}
    break;

  case 39:
#line 240 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].stmt); ;}
    break;

  case 40:
#line 244 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    phsc::LeftValue* lvalue = new phsc::DirectVar((yylocation_stack_[(4) - (1)]),
                        (yysemantic_stack_[(4) - (1)].vdef)->getName());
                    phsc::Assignment* assign = new phsc::Assignment((yylocation_stack_[(4) - (2)]), *lvalue,
                        *((yysemantic_stack_[(4) - (3)].expr)), phsc::Assignment::AssignOp::ASSIGN);
                    (yyval.vdefass) = new phsc::VarDefAssign((yylocation_stack_[(4) - (1)]), *((yysemantic_stack_[(4) - (1)].vdef)), *assign);
                  ;}
    break;

  case 41:
#line 251 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yysemantic_stack_[(5) - (2)].vdef)->setOwnership(true);
                    phsc::LeftValue* lvalue = new phsc::DirectVar((yylocation_stack_[(5) - (2)]),
                        (yysemantic_stack_[(5) - (2)].vdef)->getName());
                    phsc::Assignment* assign = new phsc::Assignment((yylocation_stack_[(5) - (3)]), *lvalue,
                        *((yysemantic_stack_[(5) - (4)].expr)), phsc::Assignment::AssignOp::ASSIGN);
                    (yyval.vdefass) = new phsc::VarDefAssign((yylocation_stack_[(5) - (2)]), *((yysemantic_stack_[(5) - (2)].vdef)), *assign);
                  ;}
    break;

  case 42:
#line 261 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmt) = new phsc::Assignment((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].lvalue)), *((yysemantic_stack_[(3) - (3)].expr)), (yysemantic_stack_[(3) - (2)].assop));
                  ;}
    break;

  case 43:
#line 264 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmt) = new phsc::EmptyStmt((yyloc));
                  ;}
    break;

  case 44:
#line 269 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.lvalue) = new phsc::DirectVar((yyloc), *((yysemantic_stack_[(1) - (1)].ident)));
                  ;}
    break;

  case 45:
#line 272 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.lvalue) = new phsc::MemberVar((yyloc), *((yysemantic_stack_[(3) - (3)].ident)), *((yysemantic_stack_[(3) - (1)].expr)));
                  ;}
    break;

  case 46:
#line 275 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.lvalue) = new phsc::Indexed((yyloc), *((yysemantic_stack_[(4) - (1)].expr)), *((yysemantic_stack_[(4) - (3)].expr)));
                  ;}
    break;

  case 47:
#line 280 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmt) = new phsc::Call((yylocation_stack_[(5) - (1)]), *((yysemantic_stack_[(5) - (1)].ident)), *((yysemantic_stack_[(5) - (3)].exprs)));
                  ;}
    break;

  case 48:
#line 285 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.exprs) = (yysemantic_stack_[(3) - (1)].exprs);
                    (yyval.exprs)->emplace_back((yysemantic_stack_[(3) - (3)].expr));
                  ;}
    break;

  case 49:
#line 289 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.exprs) = new std::vector<std::unique_ptr<phsc::Expr>>();
                    (yyval.exprs)->emplace_back((yysemantic_stack_[(1) - (1)].expr));
                  ;}
    break;

  case 50:
#line 293 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.exprs) = new std::vector<std::unique_ptr<phsc::Expr>>();
                  ;}
    break;

  case 51:
#line 298 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmt) = new phsc::If((yylocation_stack_[(6) - (1)]), *((yysemantic_stack_[(6) - (3)].expr)), *((yysemantic_stack_[(6) - (5)].stmt)), *((yysemantic_stack_[(6) - (6)].stmt)));
                  ;}
    break;

  case 52:
#line 303 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.stmt) = (yysemantic_stack_[(2) - (2)].stmt); ;}
    break;

  case 53:
#line 304 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmt) = new phsc::EmptyStmt((yyloc));
                  ;}
    break;

  case 54:
#line 309 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmt) = new phsc::WhileLoop((yylocation_stack_[(5) - (1)]), *((yysemantic_stack_[(5) - (3)].expr)), *((yysemantic_stack_[(5) - (5)].stmt)));
                  ;}
    break;

  case 55:
#line 314 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.stmt) = new phsc::ForLoop((yylocation_stack_[(9) - (1)]), *((yysemantic_stack_[(9) - (3)].stmt)), *((yysemantic_stack_[(9) - (5)].expr)), *((yysemantic_stack_[(9) - (7)].stmt)), *((yysemantic_stack_[(9) - (9)].stmt)));
                  ;}
    break;

  case 56:
#line 319 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr); ;}
    break;

  case 57:
#line 320 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.expr) = (yysemantic_stack_[(1) - (1)].lvalue); ;}
    break;

  case 58:
#line 321 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr); ;}
    break;

  case 59:
#line 322 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::NewStruct((yylocation_stack_[(5) - (1)]), *((yysemantic_stack_[(5) - (3)].ident)));
                  ;}
    break;

  case 60:
#line 325 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::NewArray((yylocation_stack_[(5) - (1)]), *((yysemantic_stack_[(5) - (2)].type)), *((yysemantic_stack_[(5) - (4)].expr)));
                  ;}
    break;

  case 61:
#line 328 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::ADD);
                  ;}
    break;

  case 62:
#line 332 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::SUB);
                  ;}
    break;

  case 63:
#line 336 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::MUL);
                  ;}
    break;

  case 64:
#line 340 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::DIV);
                  ;}
    break;

  case 65:
#line 344 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::MOD);
                  ;}
    break;

  case 66:
#line 348 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::EQ);
                  ;}
    break;

  case 67:
#line 352 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::NEQ);
                  ;}
    break;

  case 68:
#line 356 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::LES);
                  ;}
    break;

  case 69:
#line 360 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::GTR);
                  ;}
    break;

  case 70:
#line 364 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::LEQ);
                  ;}
    break;

  case 71:
#line 368 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::GEQ);
                  ;}
    break;

  case 72:
#line 372 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::AND);
                  ;}
    break;

  case 73:
#line 376 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::OR);
                  ;}
    break;

  case 74:
#line 380 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::BITWISE_AND);
                  ;}
    break;

  case 75:
#line 384 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::BITWISE_OR);
                  ;}
    break;

  case 76:
#line 388 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::BITWISE_XOR);
                  ;}
    break;

  case 77:
#line 392 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::SLA);
                  ;}
    break;

  case 78:
#line 396 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Binary((yylocation_stack_[(3) - (2)]), *((yysemantic_stack_[(3) - (1)].expr)), *((yysemantic_stack_[(3) - (3)].expr)),
                        phsc::Binary::BinaryOp::SRA);
                  ;}
    break;

  case 79:
#line 400 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Unary((yylocation_stack_[(2) - (1)]), *((yysemantic_stack_[(2) - (2)].expr)), phsc::Unary::UnaryOp::NEG);
                  ;}
    break;

  case 80:
#line 403 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Unary((yylocation_stack_[(2) - (1)]), *((yysemantic_stack_[(2) - (2)].expr)), phsc::Unary::UnaryOp::NOT);
                  ;}
    break;

  case 81:
#line 406 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.expr) = new phsc::Unary((yylocation_stack_[(2) - (1)]), *((yysemantic_stack_[(2) - (2)].expr)),
                        phsc::Unary::UnaryOp::BITWISE_NOT);
                  ;}
    break;

  case 82:
#line 412 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr); ;}
    break;

  case 83:
#line 413 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr); ;}
    break;

  case 84:
#line 414 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr); ;}
    break;

  case 85:
#line 415 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.expr) = new phsc::NullLiteral((yyloc)); ;}
    break;

  case 86:
#line 418 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::ASSIGN; ;}
    break;

  case 87:
#line 419 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::ADD_ASSIGN; ;}
    break;

  case 88:
#line 420 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::SUB_ASSIGN; ;}
    break;

  case 89:
#line 421 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::MUL_ASSIGN; ;}
    break;

  case 90:
#line 422 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::DIV_ASSIGN; ;}
    break;

  case 91:
#line 423 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::MOD_ASSIGN; ;}
    break;

  case 92:
#line 424 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::AND_ASSIGN; ;}
    break;

  case 93:
#line 425 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::XOR_ASSIGN; ;}
    break;

  case 94:
#line 426 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    { (yyval.assop) = phsc::Assignment::AssignOp::OR_ASSIGN; ;}
    break;

  case 95:
#line 427 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.assop) = phsc::Assignment::AssignOp::SHIFT_LEFT_ASSIGN;
                  ;}
    break;

  case 96:
#line 430 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"
    {
                    (yyval.assop) = phsc::Assignment::AssignOp::SHIFT_RIGHT_ASSIGN;
                  ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 1039 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.cpp"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse look-ahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  HamsicParser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char HamsicParser::yypact_ninf_ = -80;
  const short int
  HamsicParser::yypact_[] =
  {
       -80,     9,     5,   -80,   -49,   -35,   -80,   -80,   -80,   -18,
     -15,   -80,    40,   246,   -80,   -80,   -80,    26,    -9,    40,
     -80,    12,     0,   -19,    40,   -80,   -80,   -13,     0,   -80,
      35,   -80,    29,    54,    56,    40,    52,   -80,   -80,    61,
     -80,   -80,   -80,   -80,   -80,   -80,    77,    40,   119,    58,
     -80,    63,    68,    69,    71,    74,   197,   197,   197,   160,
     -80,    82,   -80,   -80,   -80,   -80,    47,   -80,   -80,   -80,
      80,   -11,   -80,   -80,   -80,   -80,   556,   -80,    48,    75,
       1,   -80,   197,   197,   197,   -80,   -80,   197,   -80,   -80,
     -43,   -43,   -43,   244,   197,   197,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,    88,   197,
     102,   169,   283,   322,   103,   -80,    23,   556,   361,   556,
      59,    59,   711,   711,   769,   769,   618,   587,   187,   187,
     -43,   -43,   -43,   769,   769,   742,   649,   680,   400,   -80,
     439,   109,   478,   139,   139,   197,   107,   197,   -80,   -80,
     -80,   -80,   -80,   153,   -80,   517,   -80,   556,   139,   -80,
     197,   -80,   123,   139,   -80
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  HamsicParser::yydefact_[] =
  {
         4,     0,     2,     1,     0,     0,     3,     5,     6,     0,
       0,     9,    25,     0,    15,    16,    17,     0,     0,     0,
      24,     0,    13,     0,     0,     7,     8,     0,    14,    18,
       0,    12,     0,     0,     0,     0,     0,    10,    21,     0,
      19,    28,    22,    23,    11,    20,    43,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    44,    82,    83,    84,    29,     0,    34,    27,    30,
       0,    57,    36,    37,    38,    39,     0,    56,     0,     0,
       0,    33,     0,     0,    43,    31,    32,     0,    44,    57,
      79,    80,    81,     0,    50,     0,    35,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,    58,     0,    49,     0,    42,
      77,    78,    66,    67,    71,    70,    72,    73,    61,    62,
      63,    64,    65,    68,    69,    74,    75,    76,     0,    45,
       0,     0,     0,    43,    43,     0,     0,     0,    40,    46,
      41,    59,    60,    53,    54,     0,    47,    48,    43,    51,
      43,    52,     0,    43,    55
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  HamsicParser::yypgoto_[] =
  {
       -80,   -80,   -80,   -80,   -80,   -80,   163,   147,    -8,    -7,
     -80,   -80,   145,   -80,    10,   -80,   -79,   -46,   -80,   -80,
     -80,   -80,   -80,   -80,   -55,   -80,   -80
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  HamsicParser::yydefgoto_[] =
  {
        -1,     1,     2,     6,     7,    13,    65,    66,    21,    22,
       8,    23,    67,    46,    68,    69,    70,    89,    72,   136,
      73,   179,    74,    75,    76,    77,   108
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char HamsicParser::yytable_ninf_ = -1;
  const short int
  HamsicParser::yytable_[] =
  {
        71,    90,    91,    92,    93,   134,   127,    32,    32,     3,
      28,    30,     9,     4,   128,     5,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    10,   132,   133,    14,
      15,    16,    93,    34,    18,    11,    12,    35,    71,   137,
     138,    80,    37,    14,    15,    16,    17,   107,    18,    33,
     131,    30,    29,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    31,   160,   166,   162,    19,    39,   167,
      14,    15,    16,    17,    47,    18,    48,    38,    49,    50,
      51,    19,    52,    53,    54,    55,   117,   118,   119,   120,
     121,   182,    37,    44,    40,    95,   129,    44,   127,    41,
     175,    45,   177,    81,    82,    56,   128,    71,    71,    83,
      84,    57,    14,    15,    16,    58,    85,    79,    59,    86,
      41,    60,    71,    94,    71,    96,   130,    71,    61,    62,
      63,    64,    14,    15,    16,    17,    47,    18,    48,   159,
      49,    50,    51,   161,    52,    53,    54,    55,   165,    20,
      27,   171,   176,    14,    15,    16,    17,   178,    18,    48,
      19,    36,    50,   173,   174,   183,    26,    56,    48,    42,
       0,    50,    43,    57,     0,     0,     0,    58,   181,     0,
      59,     0,    41,   184,    78,     0,     0,     0,    56,     0,
      61,    62,    63,    64,    57,     0,    48,    56,    58,    50,
       0,    59,     0,    57,     0,     0,     0,    58,     0,    40,
      87,    88,    62,    63,    64,     0,   119,   120,   121,     0,
      88,    62,    63,    64,     0,    56,   127,     0,     0,     0,
       0,    57,     0,     0,   128,    58,     0,     0,    87,    14,
      15,    16,    17,    24,    18,     0,     0,     0,    88,    62,
      63,    64,     0,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,     0,   124,
     125,   126,     0,   127,     0,     0,   135,    19,     0,     0,
      25,   128,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,     0,   124,   125,
     126,     0,   127,     0,     0,   163,     0,     0,     0,     0,
     128,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,     0,   124,   125,   126,
       0,   127,     0,     0,   164,     0,     0,     0,     0,   128,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,     0,   124,   125,   126,     0,
     127,     0,     0,     0,     0,     0,   168,     0,   128,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,     0,   124,   125,   126,     0,   127,
     169,     0,     0,     0,     0,     0,     0,   128,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,     0,   124,   125,   126,     0,   127,     0,
       0,     0,     0,     0,   170,     0,   128,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,     0,   124,   125,   126,     0,   127,   172,     0,
       0,     0,     0,     0,     0,   128,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,     0,   124,   125,   126,     0,   127,     0,     0,     0,
       0,     0,   180,     0,   128,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
       0,   124,   125,   126,     0,   127,   109,   110,   111,   112,
     113,   114,   115,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,     0,   124,   125,   126,     0,   127,   109,   110,   111,
     112,   113,   114,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,     0,   124,   125,   126,     0,   127,   109,   110,
     111,   112,   113,   114,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,     0,   124,     0,   126,     0,   127,   109,
     110,   111,   112,   113,   114,     0,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,     0,   124,     0,     0,     0,   127,
     109,   110,    -1,    -1,   113,   114,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
     127,   109,   110,   111,   112,   113,   114,     0,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,     0,     0,   109,   110,
       0,   127,    -1,    -1,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   117,   118,   119,   120,
     121,    -1,    -1,     0,     0,     0,     0,     0,   127,     0,
       0,     0,     0,     0,     0,     0,   128
  };

  /* YYCHECK.  */
  const short int
  HamsicParser::yycheck_[] =
  {
        46,    56,    57,    58,    59,    84,    49,     7,     7,     0,
      17,    19,    61,     8,    57,    10,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    61,    82,    83,     3,
       4,     5,    87,    52,     8,    53,    51,    56,    84,    94,
      95,    48,    55,     3,     4,     5,     6,    58,     8,    49,
      49,    59,    61,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    61,   129,    52,   131,    51,    49,    56,
       3,     4,     5,     6,     7,     8,     9,    52,    11,    12,
      13,    51,    15,    16,    17,    18,    37,    38,    39,    40,
      41,   180,    55,    55,    50,    58,    58,    55,    49,    53,
     165,    50,   167,    55,    51,    38,    57,   163,   164,    51,
      51,    44,     3,     4,     5,    48,    55,     8,    51,    55,
      53,    54,   178,    51,   180,    55,    61,   183,    61,    62,
      63,    64,     3,     4,     5,     6,     7,     8,     9,    61,
      11,    12,    13,    51,    15,    16,    17,    18,    55,    12,
      13,    52,    55,     3,     4,     5,     6,    14,     8,     9,
      51,    24,    12,   163,   164,    52,    13,    38,     9,    34,
      -1,    12,    35,    44,    -1,    -1,    -1,    48,   178,    -1,
      51,    -1,    53,   183,    47,    -1,    -1,    -1,    38,    -1,
      61,    62,    63,    64,    44,    -1,     9,    38,    48,    12,
      -1,    51,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      51,    61,    62,    63,    64,    -1,    39,    40,    41,    -1,
      61,    62,    63,    64,    -1,    38,    49,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    57,    48,    -1,    -1,    51,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    52,    51,    -1,    -1,
      54,    57,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      57,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    57,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    57,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    47,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    57,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    -1,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    57,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    46,    47,    -1,    49,    19,    20,    21,    22,
      23,    24,    25,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    -1,    49,    19,    20,    21,
      22,    23,    24,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    -1,    49,    19,    20,
      21,    22,    23,    24,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    -1,    47,    -1,    49,    19,
      20,    21,    22,    23,    24,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    49,
      19,    20,    21,    22,    23,    24,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    19,    20,    21,    22,    23,    24,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    19,    20,
      -1,    49,    23,    24,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  HamsicParser::yystos_[] =
  {
         0,    66,    67,     0,     8,    10,    68,    69,    75,    61,
      61,    53,    51,    70,     3,     4,     5,     6,     8,    51,
      72,    73,    74,    76,     7,    54,    71,    72,    74,    61,
      73,    61,     7,    49,    52,    56,    72,    55,    52,    49,
      50,    53,    77,    72,    55,    50,    78,     7,     9,    11,
      12,    13,    15,    16,    17,    18,    38,    44,    48,    51,
      54,    61,    62,    63,    64,    71,    72,    77,    79,    80,
      81,    82,    83,    85,    87,    88,    89,    90,    72,     8,
      74,    55,    51,    51,    51,    55,    55,    51,    61,    82,
      89,    89,    89,    89,    51,    58,    55,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    58,    91,    19,
      20,    21,    22,    23,    24,    25,    26,    37,    38,    39,
      40,    41,    42,    43,    45,    46,    47,    49,    57,    58,
      61,    49,    89,    89,    81,    52,    84,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    61,
      89,    51,    89,    52,    52,    55,    52,    56,    55,    50,
      55,    52,    50,    79,    79,    89,    55,    89,    14,    86,
      55,    79,    81,    52,    79
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  HamsicParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    43,    45,    42,
      47,    37,    60,    62,    33,    38,   124,    94,   126,    91,
      93,    40,    41,   123,   125,    59,    44,    46,    61,   292,
     293,   294,   295,   296,   297
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  HamsicParser::yyr1_[] =
  {
         0,    65,    66,    67,    67,    68,    68,    69,    70,    70,
      71,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    75,    76,    76,    76,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    81,    81,    82,    82,    82,    83,    84,    84,
      84,    85,    86,    86,    87,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  HamsicParser::yyr2_[] =
  {
         0,     2,     1,     2,     0,     1,     1,     5,     2,     0,
       2,     3,     2,     1,     2,     1,     1,     1,     2,     3,
       4,     3,     6,     3,     1,     0,     3,     2,     0,     1,
       1,     2,     2,     2,     1,     2,     1,     1,     1,     1,
       4,     5,     3,     0,     1,     3,     4,     5,     3,     1,
       0,     6,     2,     0,     5,     9,     1,     1,     3,     5,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const HamsicParser::yytname_[] =
  {
    "$end", "error", "$undefined", "I32", "F64", "STR", "MUT", "OWN",
  "STRUCT", "NEW", "FN", "RET", "NULL_", "IF", "ELSE", "WHILE", "FOR",
  "BREAK", "CONTINUE", "SHIFT_LEFT", "SHIFT_RIGHT", "EQUAL", "NOT_EQUAL",
  "GREATER_EQUAL", "LESS_EQUAL", "AND", "OR", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT_ASSIGN", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "'!'", "'&'", "'|'", "'^'", "'~'",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','", "'.'", "'='",
  "NEG", "NOELSE", "IDENTIFIER", "LITERAL_I32", "LITERAL_F64",
  "LITERAL_STR", "$accept", "Program", "DefinitionList", "Definition",
  "StructDef", "VariableDefList", "VariableDef", "Variable", "Type",
  "PureType", "FunctionDef", "VariableList", "StmtBlock", "StmtList",
  "Stmt", "VarDefAssign", "SimpleStmt", "LValue", "Call", "ExprList",
  "IfStmt", "ElseClause", "WhileStmt", "ForStmt", "Expr", "Constant",
  "AssignmentOp", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const HamsicParser::rhs_number_type
  HamsicParser::yyrhs_[] =
  {
        66,     0,    -1,    67,    -1,    67,    68,    -1,    -1,    69,
      -1,    75,    -1,     8,    61,    53,    70,    54,    -1,    70,
      71,    -1,    -1,    72,    55,    -1,     7,    72,    55,    -1,
      73,    61,    -1,    74,    -1,     6,    74,    -1,     3,    -1,
       4,    -1,     5,    -1,     8,    61,    -1,    74,    49,    50,
      -1,    74,     7,    49,    50,    -1,    51,    73,    52,    -1,
      10,    61,    51,    76,    52,    77,    -1,    76,    56,    72,
      -1,    72,    -1,    -1,    53,    78,    54,    -1,    78,    79,
      -1,    -1,    71,    -1,    80,    -1,    17,    55,    -1,    18,
      55,    -1,    11,    55,    -1,    77,    -1,    81,    55,    -1,
      83,    -1,    85,    -1,    87,    -1,    88,    -1,    72,    58,
      89,    55,    -1,     7,    72,    58,    89,    55,    -1,    82,
      91,    89,    -1,    -1,    61,    -1,    89,    57,    61,    -1,
      89,    49,    89,    50,    -1,    61,    51,    84,    52,    55,
      -1,    84,    56,    89,    -1,    89,    -1,    -1,    13,    51,
      89,    52,    79,    86,    -1,    14,    79,    -1,    -1,    15,
      51,    89,    52,    79,    -1,    16,    51,    81,    55,    89,
      55,    81,    52,    79,    -1,    90,    -1,    82,    -1,    51,
      89,    52,    -1,     9,     8,    61,    51,    52,    -1,     9,
      74,    49,    89,    50,    -1,    89,    37,    89,    -1,    89,
      38,    89,    -1,    89,    39,    89,    -1,    89,    40,    89,
      -1,    89,    41,    89,    -1,    89,    21,    89,    -1,    89,
      22,    89,    -1,    89,    42,    89,    -1,    89,    43,    89,
      -1,    89,    24,    89,    -1,    89,    23,    89,    -1,    89,
      25,    89,    -1,    89,    26,    89,    -1,    89,    45,    89,
      -1,    89,    46,    89,    -1,    89,    47,    89,    -1,    89,
      19,    89,    -1,    89,    20,    89,    -1,    38,    89,    -1,
      44,    89,    -1,    48,    89,    -1,    62,    -1,    63,    -1,
      64,    -1,    12,    -1,    58,    -1,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  HamsicParser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,     9,    11,    13,    19,    22,
      23,    26,    30,    33,    35,    38,    40,    42,    44,    47,
      51,    56,    60,    67,    71,    73,    74,    78,    81,    82,
      84,    86,    89,    92,    95,    97,   100,   102,   104,   106,
     108,   113,   119,   123,   124,   126,   130,   135,   141,   145,
     147,   148,   155,   158,   159,   165,   175,   177,   179,   183,
     189,   195,   199,   203,   207,   211,   215,   219,   223,   227,
     231,   235,   239,   243,   247,   251,   255,   259,   263,   267,
     270,   273,   276,   278,   280,   282,   284,   286,   288,   290,
     292,   294,   296,   298,   300,   302,   304
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  HamsicParser::yyrline_[] =
  {
         0,   125,   125,   131,   135,   140,   141,   144,   149,   153,
     158,   159,   165,   170,   171,   177,   180,   183,   186,   189,
     192,   195,   198,   203,   207,   211,   216,   221,   225,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     244,   251,   261,   264,   269,   272,   275,   280,   285,   289,
     293,   298,   303,   304,   309,   314,   319,   320,   321,   322,
     325,   328,   332,   336,   340,   344,   348,   352,   356,   360,
     364,   368,   372,   376,   380,   384,   388,   392,   396,   400,
     403,   406,   412,   413,   414,   415,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   430
  };

  // Print the state stack on the debug stream.
  void
  HamsicParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  HamsicParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  HamsicParser::token_number_type
  HamsicParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    41,    45,     2,
      51,    52,    39,    37,    56,    38,    57,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
      42,    58,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    46,    54,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    59,    60,    61,    62,    63,    64
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int HamsicParser::yyeof_ = 0;
  const int HamsicParser::yylast_ = 826;
  const int HamsicParser::yynnts_ = 27;
  const int HamsicParser::yyempty_ = -2;
  const int HamsicParser::yyfinal_ = 3;
  const int HamsicParser::yyterror_ = 1;
  const int HamsicParser::yyerrcode_ = 256;
  const int HamsicParser::yyntokens_ = 65;

  const unsigned int HamsicParser::yyuser_token_number_max_ = 297;
  const HamsicParser::token_number_type HamsicParser::yyundef_token_ = 2;

} // namespace phsc

#line 435 "/Users/yangzehai/Desktop/myfun/hamsic/phsc/src/parser/parser.yy"


void phsc::HamsicParser::error(const phsc::HamsicParser::location_type& loc,
    const std::string& msg) {
  _errors.emplace_back(new phsc::SyntaxError(loc, msg));
}

