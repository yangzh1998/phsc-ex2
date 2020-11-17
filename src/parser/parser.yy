%{
#include <iostream>
#include <vector>
#include <string>
#include <memory> // unique_ptr
#include "../ast/includes.h"

namespace phsc {
  class HamsicLexer;
  class HamsicReport;
}

%}

/* start symbol is named "Program" */
%start Program

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="phsc"

/* set the parser's class identifier */
%define "parser_class_name" "HamsicParser"

%parse-param { phsc::HamsicLexer& _lexer }
%parse-param { std::unique_ptr<phsc::ASTRoot>& _tree }
%parse-param { std::vector<std::unique_ptr<phsc::HamsicReport>>& _errors }

/* keep track of the current position within the input */
%locations

/* verbose error messages */
%error-verbose

%union {
  std::string* ident;
  phsc::ASTRoot* tree;
  phsc::Keyword* keyword;
  phsc::Expr* expr;
  phsc::VarDef* vdef;
  phsc::StructDef* sdef;
  phsc::FuncDef* fdef;
  phsc::ASTNode* def;
  phsc::TypeLiteral* type;
  phsc::ASTNode* stmt;
  phsc::Block* block;
  phsc::LeftValue* lvalue;
  phsc::Assignment::AssignOp assop;
  phsc::VarDefAssign* vdefass;
  
  std::vector<std::unique_ptr<phsc::VarDef>>* vdefs;
  std::vector<std::unique_ptr<phsc::ASTNode>>* defs;
  std::vector<std::unique_ptr<phsc::ASTNode>>* stmts;
  std::vector<std::unique_ptr<phsc::Expr>>* exprs;
  // ...
}

%token <keyword> I32 F64 STR MUT OWN STRUCT NEW FN RET NULL_
%token <keyword> IF ELSE WHILE FOR BREAK CONTINUE

%token <keyword> SHIFT_LEFT SHIFT_RIGHT
%token <keyword> EQUAL NOT_EQUAL GREATER_EQUAL LESS_EQUAL
%token <keyword> AND OR
%token <keyword> ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token <keyword> AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHIFT_LEFT_ASSIGN SHIFT_RIGHT_ASSIGN

%token <keyword> '+' '-' '*' '/' '%' '<' '>' '!' '&' '|' '^' '~'
%token <keyword> '[' ']' '(' ')' '{' '}' ';' ',' '.' '='

%left OR
%left AND
%left '|'
%left '^'
%left '&'
%nonassoc EQUAL NOT_EQUAL
%nonassoc '<' '>' GREATER_EQUAL LESS_EQUAL
%left SHIFT_LEFT SHIFT_RIGHT
%left '+' '-'
%left '*' '/' '%'
%nonassoc NEG '!' '~'
%nonassoc '['
%left '.'
%nonassoc NOELSE
%nonassoc ELSE

%token <ident> IDENTIFIER
%token <expr> LITERAL_I32
%token <expr> LITERAL_F64
%token <expr> LITERAL_STR

%type <tree> Program
%type <assop> AssignmentOp
%type <expr> Constant Expr
%type <vdef> VariableDef Variable
%type <sdef> StructDef
%type <fdef> FunctionDef
%type <def> Definition
%type <type> Type PureType
%type <stmt> Stmt SimpleStmt Call IfStmt WhileStmt ForStmt ElseClause
%type <block> StmtBlock
%type <lvalue> LValue
%type <vdefass> VarDefAssign
%type <vdefs> VariableDefList VariableList
%type <defs> DefinitionList
%type <stmts> StmtList
%type <exprs> ExprList

%{
#include "hamsic-lexer.h"
#include "../report/syntax-error.h"

#ifdef yylex
#undef yylex
#endif
#define yylex _lexer.lex
%}

%%

Program         : DefinitionList {
                    $$ = new phsc::ASTRoot(@$, *($1));
                    _tree.reset($$);
                  }
                ;
          
DefinitionList  : DefinitionList Definition {
                    $$ = $1;
                    $$->emplace_back($2);
                  }
                | /* empty */ {
                    $$ = new std::vector<std::unique_ptr<phsc::ASTNode>>();
                  }
                ;
                
Definition      : StructDef { $$ = $1; }
                | FunctionDef { $$ = $1; }
                ;
                
StructDef       : STRUCT IDENTIFIER '{' VariableDefList '}' {
                    $$ = new phsc::StructDef(@2, *($2), *($4));
                  }
                ;
              
VariableDefList : VariableDefList VariableDef {
                    $$ = $1;
                    $$->emplace_back($2);
                  }
                | /* empty */ {
                    $$ = new std::vector<std::unique_ptr<phsc::VarDef>>();
                  }
                ;
                
VariableDef     : Variable ';' { $$ = $1; }
                | OWN Variable ';' {
                    $$ = $2;
                    $2->setOwnership(true);
                  }
                ;
              
Variable        : Type IDENTIFIER {
                    $$ = new VarDef(@2, *($2), *($1));
                  }
                ;
                
Type            : PureType { $$ = $1; }
                | MUT PureType {
                    $$ = $2;
                    $$->setMutable(true);
                  }
                ;
                
PureType        : I32 {
                    $$ = new phsc::TypeBasic(@$, phsc::TypeBasic::TypeTag::I32);
                  }
                | F64 {
                    $$ = new phsc::TypeBasic(@$, phsc::TypeBasic::TypeTag::F64);
                  }
                | STR {
                    $$ = new phsc::TypeBasic(@$, phsc::TypeBasic::TypeTag::STR);
                  }
                | STRUCT IDENTIFIER {
                    $$ = new phsc::TypeStruct(@$, *($2));
                  }
                | PureType '[' ']' {
                    $$ = new phsc::TypeArray(@$, *($1), false);
                  }
                | PureType OWN '[' ']' {
                    $$ = new phsc::TypeArray(@$, *($1), true);
                  }
                | '(' Type ')' { $$ = $2; }
                ;
                
FunctionDef     : FN IDENTIFIER '(' VariableList ')' StmtBlock {
                    $$ = new phsc::FuncDef(@2, *($2), *($4), *($6));
                  }
                ;
                
VariableList    : VariableList ',' Variable {
                    $$ = $1;
                    $$->emplace_back($3);
                  }
                | Variable {
                    $$ = new std::vector<std::unique_ptr<phsc::VarDef>>();
                    $$->emplace_back($1);
                  }
                | /* empty */ {
                    $$ = new std::vector<std::unique_ptr<phsc::VarDef>>();
                  }
                ;
                
StmtBlock       : '{' StmtList '}' {
                    $$ = new phsc::Block(@$, *($2));
                  }
                ;
                
StmtList        : StmtList Stmt {
                    $$ = $1;
                    $$->emplace_back($2);
                  }
                | /* empty */ {
                    $$ = new std::vector<std::unique_ptr<phsc::ASTNode>>();
                  }
                ;
                
Stmt            : VariableDef { $$ = $1; }
                | VarDefAssign { $$ = $1; }
                | BREAK ';' { $$ = new phsc::Break(@1); }
                | CONTINUE ';' { $$ = new phsc::Continue(@1); }
                | RET ';' { $$ = new phsc::Return(@1); }
                | StmtBlock { $$ = $1; }
                | SimpleStmt ';' { $$ = $1; }
                | Call { $$ = $1; }
                | IfStmt { $$ = $1; }
                | WhileStmt { $$ = $1; }
                | ForStmt { $$ = $1; }
                ;
                
                
VarDefAssign    : Variable '=' Expr ';' {
                    phsc::LeftValue* lvalue = new phsc::DirectVar(@1,
                        $1->getName());
                    phsc::Assignment* assign = new phsc::Assignment(@2, *lvalue,
                        *($3), phsc::Assignment::AssignOp::ASSIGN);
                    $$ = new phsc::VarDefAssign(@1, *($1), *assign);
                  }
                | OWN Variable '=' Expr ';' {
                    $2->setOwnership(true);
                    phsc::LeftValue* lvalue = new phsc::DirectVar(@2,
                        $2->getName());
                    phsc::Assignment* assign = new phsc::Assignment(@3, *lvalue,
                        *($4), phsc::Assignment::AssignOp::ASSIGN);
                    $$ = new phsc::VarDefAssign(@2, *($2), *assign);
                  }
                ;
                
SimpleStmt      : LValue AssignmentOp Expr {
                    $$ = new phsc::Assignment(@2, *($1), *($3), $2);
                  }
                | /* empty */ {
                    $$ = new phsc::EmptyStmt(@$);
                  }
                ;
                
LValue          : IDENTIFIER {
                    $$ = new phsc::DirectVar(@$, *($1));
                  }
                | Expr '.' IDENTIFIER {
                    $$ = new phsc::MemberVar(@$, *($3), *($1));
                  }
                | Expr '[' Expr ']' {
                    $$ = new phsc::Indexed(@$, *($1), *($3));
                  }
                ;
                
Call            : IDENTIFIER '(' ExprList ')' ';' {
                    $$ = new phsc::Call(@1, *($1), *($3));
                  }
                ;
                
ExprList        : ExprList ',' Expr {
                    $$ = $1;
                    $$->emplace_back($3);
                  }
                | Expr {
                    $$ = new std::vector<std::unique_ptr<phsc::Expr>>();
                    $$->emplace_back($1);
                  }
                | /* empty */ {
                    $$ = new std::vector<std::unique_ptr<phsc::Expr>>();
                  }
                ;
                
IfStmt          : IF '(' Expr ')' Stmt ElseClause {
                    $$ = new phsc::If(@1, *($3), *($5), *($6));
                  }
                ;

ElseClause      : ELSE Stmt { $$ = $2; }
                | /* empty */ %prec NOELSE {
                    $$ = new phsc::EmptyStmt(@$);
                  }
                ;
                
WhileStmt       : WHILE '(' Expr ')' Stmt {
                    $$ = new phsc::WhileLoop(@1, *($3), *($5));
                  }
                ;

ForStmt         : FOR '(' SimpleStmt ';' Expr ';' SimpleStmt ')' Stmt {
                    $$ = new phsc::ForLoop(@1, *($3), *($5), *($7), *($9));
                  }
                ;
                                
Expr            : Constant { $$ = $1; }
                | LValue { $$ = $1; }
                | '(' Expr ')' { $$ = $2; }
                | NEW STRUCT IDENTIFIER '(' ')' {
                    $$ = new phsc::NewStruct(@1, *($3));
                  }
                | NEW PureType '[' Expr ']' {
                    $$ = new phsc::NewArray(@1, *($2), *($4));
                  }
                | Expr '+' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::ADD);
                  }
                | Expr '-' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::SUB);
                  }
                | Expr '*' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::MUL);
                  }
                | Expr '/' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::DIV);
                  }
                | Expr '%' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::MOD);
                  }
                | Expr EQUAL Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::EQ);
                  }
                | Expr NOT_EQUAL Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::NEQ);
                  }
                | Expr '<' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::LES);
                  }
                | Expr '>' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::GTR);
                  }
                | Expr LESS_EQUAL Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::LEQ);
                  }
                | Expr GREATER_EQUAL Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::GEQ);
                  }
                | Expr AND Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::AND);
                  }
                | Expr OR Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::OR);
                  }
                | Expr '&' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::BITWISE_AND);
                  }
                | Expr '|' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::BITWISE_OR);
                  }
                | Expr '^' Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::BITWISE_XOR);
                  }
                | Expr SHIFT_LEFT Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::SLA);
                  }
                | Expr SHIFT_RIGHT Expr {
                    $$ = new phsc::Binary(@2, *($1), *($3),
                        phsc::Binary::BinaryOp::SRA);
                  }
                | '-' Expr  %prec NEG {
                    $$ = new phsc::Unary(@1, *($2), phsc::Unary::UnaryOp::NEG);
                  }
                | '!' Expr {
                    $$ = new phsc::Unary(@1, *($2), phsc::Unary::UnaryOp::NOT);
                  }
                | '~' Expr {
                    $$ = new phsc::Unary(@1, *($2),
                        phsc::Unary::UnaryOp::BITWISE_NOT);
                  }
                ;
                
Constant        : LITERAL_I32 { $$ = $1; }
                | LITERAL_F64 { $$ = $1; }
                | LITERAL_STR { $$ = $1; }
                | NULL_ { $$ = new phsc::NullLiteral(@$); }
                ;
                
AssignmentOp    : '=' { $$ = phsc::Assignment::AssignOp::ASSIGN; }
                | ADD_ASSIGN { $$ = phsc::Assignment::AssignOp::ADD_ASSIGN; }
                | SUB_ASSIGN { $$ = phsc::Assignment::AssignOp::SUB_ASSIGN; }
                | MUL_ASSIGN { $$ = phsc::Assignment::AssignOp::MUL_ASSIGN; }
                | DIV_ASSIGN { $$ = phsc::Assignment::AssignOp::DIV_ASSIGN; }
                | MOD_ASSIGN { $$ = phsc::Assignment::AssignOp::MOD_ASSIGN; }
                | AND_ASSIGN { $$ = phsc::Assignment::AssignOp::AND_ASSIGN; }
                | XOR_ASSIGN { $$ = phsc::Assignment::AssignOp::XOR_ASSIGN; }
                | OR_ASSIGN { $$ = phsc::Assignment::AssignOp::OR_ASSIGN; }
                | SHIFT_LEFT_ASSIGN {
                    $$ = phsc::Assignment::AssignOp::SHIFT_LEFT_ASSIGN;
                  }
                | SHIFT_RIGHT_ASSIGN {
                    $$ = phsc::Assignment::AssignOp::SHIFT_RIGHT_ASSIGN;
                  }
                ;

%%

void phsc::HamsicParser::error(const phsc::HamsicParser::location_type& loc,
    const std::string& msg) {
  _errors.emplace_back(new phsc::SyntaxError(loc, msg));
}
