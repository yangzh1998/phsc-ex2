/**
 * @file visitor/visitor.h
 * @brief Base class of all visitor types.
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-23
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef VISITOR_VISITOR_H
#define VISITOR_VISITOR_H

namespace phsc {

class ASTRoot;
class Keyword;
class I32Literal;
class F64Literal;
class StrLiteral;
class NullLiteral;
class TypeBasic;
class TypeStruct;
class TypeArray;
class VarDef;
class StructDef;
class FuncDef;
class Block;
class EmptyStmt;
class Break;
class Continue;
class Return;
class If;
class WhileLoop;
class ForLoop;
class Call;
class Assignment;
class DirectVar;
class MemberVar;
class Indexed;
class VarDefAssign;
class NewStruct;
class NewArray;
class Binary;
class Unary;

class Visitor {
public:
  virtual ~Visitor() {}
  virtual void visitASTRoot(phsc::ASTRoot&) = 0;
  virtual void visitKeyword(phsc::Keyword&) = 0;
  virtual void visitI32Literal(phsc::I32Literal&) = 0;
  virtual void visitF64Literal(phsc::F64Literal&) = 0;
  virtual void visitStrLiteral(phsc::StrLiteral&) = 0;
  virtual void visitNullLiteral(phsc::NullLiteral&) = 0;
  virtual void visitTypeBasic(phsc::TypeBasic&) = 0;
  virtual void visitTypeStruct(phsc::TypeStruct&) = 0;
  virtual void visitTypeArray(phsc::TypeArray&) = 0;
  virtual void visitVarDef(phsc::VarDef&) = 0;
  virtual void visitStructDef(phsc::StructDef&) = 0;
  virtual void visitFuncDef(phsc::FuncDef&) = 0;
  virtual void visitBlock(phsc::Block&) = 0;
  virtual void visitEmptyStmt(phsc::EmptyStmt&) = 0;
  virtual void visitBreak(phsc::Break&) = 0;
  virtual void visitContinue(phsc::Continue&) = 0;
  virtual void visitReturn(phsc::Return&) = 0;
  virtual void visitIf(phsc::If&) = 0;
  virtual void visitWhileLoop(phsc::WhileLoop&) = 0;
  virtual void visitForLoop(phsc::ForLoop&) = 0;
  virtual void visitCall(phsc::Call&) = 0;
  virtual void visitAssignment(phsc::Assignment&) = 0;
  virtual void visitDirectVar(phsc::DirectVar&) = 0;
  virtual void visitMemberVar(phsc::MemberVar&) = 0;
  virtual void visitIndexed(phsc::Indexed&) = 0;
  virtual void visitVarDefAssign(phsc::VarDefAssign&) = 0;
  virtual void visitNewStruct(phsc::NewStruct&) = 0;
  virtual void visitNewArray(phsc::NewArray&) = 0;
  virtual void visitBinary(phsc::Binary&) = 0;
  virtual void visitUnary(phsc::Unary&) = 0;
}; // Visitor

} // namespace phsc

#endif /* VISITOR_VISITOR_H */
