/**
 * @file visitor/build-sym.h
 * @brief The pass to build symbol table of the AST.
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

#ifndef VISITOR_BUILD_SYM_H
#define VISITOR_BUILD_SYM_H

#include "visitor.h"
#include "../symbol/scope-stack.h"

namespace phsc {

class BuildSym : public Visitor {
public:
  BuildSym() {}
  virtual ~BuildSym() {}
  
  virtual void visitASTRoot(phsc::ASTRoot&) override;
  virtual void visitKeyword(phsc::Keyword&) override;
  virtual void visitI32Literal(phsc::I32Literal&) override;
  virtual void visitF64Literal(phsc::F64Literal&) override;
  virtual void visitStrLiteral(phsc::StrLiteral&) override;
  virtual void visitNullLiteral(phsc::NullLiteral&) override;
  virtual void visitTypeBasic(phsc::TypeBasic&) override;
  virtual void visitTypeStruct(phsc::TypeStruct&) override;
  virtual void visitTypeArray(phsc::TypeArray&) override;
  virtual void visitVarDef(phsc::VarDef&) override;
  virtual void visitStructDef(phsc::StructDef&) override;
  virtual void visitFuncDef(phsc::FuncDef&) override;
  virtual void visitBlock(phsc::Block&) override;
  virtual void visitEmptyStmt(phsc::EmptyStmt&) override;
  virtual void visitBreak(phsc::Break&) override;
  virtual void visitContinue(phsc::Continue&) override;
  virtual void visitReturn(phsc::Return&) override;
  virtual void visitIf(phsc::If&) override;
  virtual void visitWhileLoop(phsc::WhileLoop&) override;
  virtual void visitForLoop(phsc::ForLoop&) override;
  virtual void visitCall(phsc::Call&) override;
  virtual void visitAssignment(phsc::Assignment&) override;
  virtual void visitDirectVar(phsc::DirectVar&) override;
  virtual void visitMemberVar(phsc::MemberVar&) override;
  virtual void visitIndexed(phsc::Indexed&) override;
  virtual void visitVarDefAssign(phsc::VarDefAssign&) override;
  virtual void visitNewStruct(phsc::NewStruct&) override;
  virtual void visitNewArray(phsc::NewArray&) override;
  virtual void visitBinary(phsc::Binary&) override;
  virtual void visitUnary(phsc::Unary&) override;
  
private:
  phsc::ScopeStack _stack;
  
}; // BuildSym

} // namespace phsc

#endif /* VISITOR_BUILD_SYM_H */
