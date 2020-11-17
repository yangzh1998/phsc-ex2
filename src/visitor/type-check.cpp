/**
 * @file visitor/type-check.cpp
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-12
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#include "type-check.h"
#include "../ast/includes.h"
#include "../symbol/scope.h"
#include "../symbol/symbol.h"
//#include "../parser/location.hh"

void phsc::TypeCheck::visitASTRoot(phsc::ASTRoot&) {
  
}

void phsc::TypeCheck::visitKeyword(phsc::Keyword&) {
  
}

void phsc::TypeCheck::visitI32Literal(phsc::I32Literal&) {
  
}

void phsc::TypeCheck::visitF64Literal(phsc::F64Literal&) {
  
}

void phsc::TypeCheck::visitStrLiteral(phsc::StrLiteral&) {
  
}

void phsc::TypeCheck::visitNullLiteral(phsc::NullLiteral&) {
  
}

void phsc::TypeCheck::visitTypeBasic(phsc::TypeBasic&) {
  
}

void phsc::TypeCheck::visitTypeStruct(phsc::TypeStruct&) {
  
}

void phsc::TypeCheck::visitTypeArray(phsc::TypeArray&) {
  
}

void phsc::TypeCheck::visitVarDef(phsc::VarDef&) {
  
}

void phsc::TypeCheck::visitStructDef(phsc::StructDef&) {
  
}

void phsc::TypeCheck::visitFuncDef(phsc::FuncDef&) {
  
}

void phsc::TypeCheck::visitBlock(phsc::Block&) {
  
}

void phsc::TypeCheck::visitEmptyStmt(phsc::EmptyStmt&) {
  
}

void phsc::TypeCheck::visitBreak(phsc::Break&) {
  
}

void phsc::TypeCheck::visitContinue(phsc::Continue&) {
  
}

void phsc::TypeCheck::visitReturn(phsc::Return&) {
  
}

void phsc::TypeCheck::visitIf(phsc::If&) {
  
}

void phsc::TypeCheck::visitWhileLoop(phsc::WhileLoop&) {
  
}

void phsc::TypeCheck::visitForLoop(phsc::ForLoop&) {
  
}

void phsc::TypeCheck::visitCall(phsc::Call&) {
  
}

void phsc::TypeCheck::visitAssignment(phsc::Assignment&) {
  
}

void phsc::TypeCheck::visitDirectVar(phsc::DirectVar&) {
  
}

void phsc::TypeCheck::visitMemberVar(phsc::MemberVar&) {
  
}

void phsc::TypeCheck::visitIndexed(phsc::Indexed&) {
  
}

void phsc::TypeCheck::visitVarDefAssign(phsc::VarDefAssign&) {
  
}

void phsc::TypeCheck::visitNewStruct(phsc::NewStruct&) {
  
}

void phsc::TypeCheck::visitNewArray(phsc::NewArray&) {
  
}

void phsc::TypeCheck::visitBinary(phsc::Binary&) {
  
}

void phsc::TypeCheck::visitUnary(phsc::Unary&) {
  
}
