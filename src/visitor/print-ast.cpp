/**
 * @file visitor/print-ast.cpp
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-27
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef PHSC_LITE

#include "print-ast.h"
#include "../ast/includes.h"

void phsc::PrintAST::visitASTRoot(phsc::ASTRoot& root) {
  _ipw.println("<program>");
  _ipw.incIndent();
  for (std::unique_ptr<phsc::ASTNode>& def : root.getDefinitions()) {
    def->accept(*this);
  }
  _ipw.decIndent();
}

void phsc::PrintAST::visitKeyword(phsc::Keyword& keyword) {
  _ipw.println("<token> " + std::to_string(keyword.getToken()));
}

void phsc::PrintAST::visitI32Literal(phsc::I32Literal& i32Literal) {
  _ipw.println("<i32literal> " + std::to_string(i32Literal.getValue()));
}

void phsc::PrintAST::visitF64Literal(phsc::F64Literal& f64Literal) {
  _ipw.println("<f64literal> " + std::to_string(f64Literal.getValue()));
}

void phsc::PrintAST::visitStrLiteral(phsc::StrLiteral& strLiteral) {
  _ipw.println("<strliteral> \"" + strLiteral.getValue() + "\"");
}

void phsc::PrintAST::visitNullLiteral(phsc::NullLiteral& nullLiteral) {
  _ipw.println("<null>");
}

void phsc::PrintAST::visitTypeBasic(phsc::TypeBasic& type) {
  if (type.isMutable()) _ipw.print("<mutable> ");
  switch (type.getTypeTag()) {
    case phsc::TypeBasic::TypeTag::I32:
      _ipw.print("<i32type>"); break;
    case phsc::TypeBasic::TypeTag::F64:
      _ipw.print("<f64type>"); break;
    case phsc::TypeBasic::TypeTag::STR:
      _ipw.print("<strtype>"); break;
  }
}

void phsc::PrintAST::visitTypeStruct(phsc::TypeStruct& type) {
  if (type.isMutable()) _ipw.print("<mutable> ");
  _ipw.print("<structtype> " + type.getName());
}

void phsc::PrintAST::visitTypeArray(phsc::TypeArray& type) {
  if (type.isMutable()) _ipw.print("<mutable> ");
  if (type.elementHasOwnership()) _ipw.print("<eleown> ");
  _ipw.print("<arrtype> ");
  type.getElementType().accept(*this);
}

void phsc::PrintAST::visitVarDef(phsc::VarDef& varDef) {
  if (varDef.hasOwnership()) _ipw.print("<ownership> ");
  _ipw.print("<vardef> " + varDef.getName() + " ");
  varDef.getTypeLiteral().accept(*this);
  _ipw.println();
}

void phsc::PrintAST::visitStructDef(phsc::StructDef& structDef) {
  _ipw.println("<struct> " + structDef.getName());
  _ipw.incIndent();
  for (std::unique_ptr<phsc::VarDef>& varDef : structDef.getFields()) {
    varDef->accept(*this);
  }
  _ipw.decIndent();
}

void phsc::PrintAST::visitFuncDef(phsc::FuncDef& funcDef) {
  _ipw.println("<func> " + funcDef.getName());
  _ipw.incIndent();
  _ipw.println("<formals>");
  _ipw.incIndent();
  for (std::unique_ptr<phsc::VarDef>& vdef : funcDef.getFormals()) {
    vdef->accept(*this);
  }
  _ipw.decIndent();
  funcDef.getBody().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitBlock(phsc::Block& block) {
  _ipw.println("<stmtblock>");
  _ipw.incIndent();
  for (std::unique_ptr<phsc::ASTNode>& stmt : block.getStmts()) {
    stmt->accept(*this);
  }
  _ipw.decIndent();
}

void phsc::PrintAST::visitEmptyStmt(phsc::EmptyStmt& EmptyStmt) {
  _ipw.println("<empty>");
}

void phsc::PrintAST::visitBreak(phsc::Break& breakStmt) {
  _ipw.println("<break>");
}

void phsc::PrintAST::visitContinue(phsc::Continue& continueStmt) {
  _ipw.println("<continue>");
}

void phsc::PrintAST::visitReturn(phsc::Return& returnStmt) {
  _ipw.println("<return>");
}

void phsc::PrintAST::visitIf(phsc::If& ifStmt) {
  _ipw.println("<if>");
  _ipw.incIndent();
  ifStmt.getCondition().accept(*this);
  ifStmt.getTrueBranch().accept(*this);
  _ipw.decIndent();
  _ipw.println("<else>");
  _ipw.incIndent();
  ifStmt.getFalseBranch().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitWhileLoop(phsc::WhileLoop& whileLoop) {
  _ipw.println("<while>");
  _ipw.incIndent();
  whileLoop.getCondition().accept(*this);
  whileLoop.getLoopBody().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitForLoop(phsc::ForLoop& forLoop) {
  _ipw.println("<for>");
  _ipw.incIndent();
  forLoop.getInit().accept(*this);
  forLoop.getCondition().accept(*this);
  forLoop.getUpdate().accept(*this);
  forLoop.getLoopBody().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitCall(phsc::Call& call) {
  _ipw.println("<call> " + call.getFuncName());
  _ipw.incIndent();
  for (std::unique_ptr<phsc::Expr>& expr : call.getActuals()) {
    expr->accept(*this);
  }
  _ipw.decIndent();
}

void phsc::PrintAST::visitAssignment(phsc::Assignment& assign) {
  switch (assign.getOp()) {
    case phsc::Assignment::AssignOp::ASSIGN:
      _ipw.println("<assign>"); break;
    case phsc::Assignment::AssignOp::ADD_ASSIGN:
      _ipw.println("<addass>"); break;
    case phsc::Assignment::AssignOp::SUB_ASSIGN:
      _ipw.println("<subass>"); break;
    case phsc::Assignment::AssignOp::MUL_ASSIGN:
      _ipw.println("<mulass>"); break;
    case phsc::Assignment::AssignOp::DIV_ASSIGN:
      _ipw.println("<divass>"); break;
    case phsc::Assignment::AssignOp::MOD_ASSIGN:
      _ipw.println("<modass>"); break;
    case phsc::Assignment::AssignOp::AND_ASSIGN:
      _ipw.println("<andass>"); break;
    case phsc::Assignment::AssignOp::XOR_ASSIGN:
      _ipw.println("<xorass>"); break;
    case phsc::Assignment::AssignOp::OR_ASSIGN:
      _ipw.println("<orass>"); break;
    case phsc::Assignment::AssignOp::SHIFT_LEFT_ASSIGN:
      _ipw.println("<slaass>"); break;
    case phsc::Assignment::AssignOp::SHIFT_RIGHT_ASSIGN:
      _ipw.println("<sraass>"); break;
  }
  _ipw.incIndent();
  assign.getLeft().accept(*this);
  assign.getRight().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitDirectVar(phsc::DirectVar& directVar) {
  _ipw.println("<varref> " + directVar.getName());
}

void phsc::PrintAST::visitMemberVar(phsc::MemberVar& memberVar) {
  _ipw.println("<varref> " + memberVar.getName());
  _ipw.incIndent();
  memberVar.getOwner().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitIndexed(phsc::Indexed& indexed) {
  _ipw.println("<arrref>");
  _ipw.incIndent();
  indexed.getArray().accept(*this);
  indexed.getIndex().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitVarDefAssign(phsc::VarDefAssign& vdefass) {
  vdefass.getDefinition().accept(*this);
  vdefass.getAssignment().accept(*this);
}

void phsc::PrintAST::visitNewStruct(phsc::NewStruct& newStruct) {
  _ipw.println("<newstruct> " + newStruct.getName());
}

void phsc::PrintAST::visitNewArray(phsc::NewArray& newArray) {
  _ipw.print("<newarray> ");
  newArray.getElementType().accept(*this);
  _ipw.println();
  _ipw.incIndent();
  newArray.getLength().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitBinary(phsc::Binary& binary) {
  switch (binary.getOp()) {
    case phsc::Binary::BinaryOp::ADD:
      _ipw.println("<add>"); break;
    case phsc::Binary::BinaryOp::SUB:
      _ipw.println("<sub>"); break;
    case phsc::Binary::BinaryOp::MUL:
      _ipw.println("<mul>"); break;
    case phsc::Binary::BinaryOp::DIV:
      _ipw.println("<div>"); break;
    case phsc::Binary::BinaryOp::MOD:
      _ipw.println("<mod>"); break;
    case phsc::Binary::BinaryOp::EQ:
      _ipw.println("<eq>"); break;
    case phsc::Binary::BinaryOp::NEQ:
      _ipw.println("<neq>"); break;
    case phsc::Binary::BinaryOp::LES:
      _ipw.println("<les>"); break;
    case phsc::Binary::BinaryOp::GTR:
      _ipw.println("<gtr>"); break;
    case phsc::Binary::BinaryOp::LEQ:
      _ipw.println("<leq>"); break;
    case phsc::Binary::BinaryOp::GEQ:
      _ipw.println("<geq>"); break;
    case phsc::Binary::BinaryOp::AND:
      _ipw.println("<and>"); break;
    case phsc::Binary::BinaryOp::OR:
      _ipw.println("<or>"); break;
    case phsc::Binary::BinaryOp::BITWISE_AND:
      _ipw.println("<bitand>"); break;
    case phsc::Binary::BinaryOp::BITWISE_OR:
      _ipw.println("<bitor>"); break;
    case phsc::Binary::BinaryOp::BITWISE_XOR:
      _ipw.println("<bitxor>"); break;
    case phsc::Binary::BinaryOp::SLA:
      _ipw.println("<sla>"); break;
    case phsc::Binary::BinaryOp::SRA:
      _ipw.println("<sra>"); break;
  }
  _ipw.incIndent();
  binary.getLeft().accept(*this);
  binary.getRight().accept(*this);
  _ipw.decIndent();
}

void phsc::PrintAST::visitUnary(phsc::Unary& unary) {
  switch (unary.getOp()) {
    case phsc::Unary::UnaryOp::NEG:
      _ipw.println("<neg>"); break;
    case phsc::Unary::UnaryOp::NOT:
      _ipw.println("<not>"); break;
    case phsc::Unary::UnaryOp::BITWISE_NOT:
      _ipw.println("<bitnot>"); break;
  }
  _ipw.incIndent();
  unary.getExpr().accept(*this);
  _ipw.decIndent();
}

#endif /* DPHSC_LLVM */
