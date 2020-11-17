/**
 * @file ast/binary.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-28
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef AST_BINARY_H
#define AST_BINARY_H

#include <memory> // unique_ptr
#include "expr.h"
#include "../visitor/visitor.h"

namespace phsc {

class Binary : public Expr {
public:
  enum class BinaryOp {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    EQ,
    NEQ,
    LES,
    GTR,
    LEQ,
    GEQ,
    AND,
    OR,
    BITWISE_AND,
    BITWISE_OR,
    BITWISE_XOR,
    SLA,
    SRA
  };
  
  Binary(const phsc::location& loc, Expr& left, Expr& right, BinaryOp op):
      Expr(ASTNode::BINARY, loc), _left(&left), _right(&right), _op(op) {}
  
  Expr& getLeft() const { return *(_left.get()); }
  Expr& getRight() const { return *(_right.get()); }
  BinaryOp getOp() const { return _op; }
  
  virtual void accept(Visitor& v) override {
    v.visitBinary(*this);
  }
  
private:
  std::unique_ptr<Expr> _left;
  std::unique_ptr<Expr> _right;
  BinaryOp _op;
}; // Binary

} // namespace phsc

#endif /* AST_BINARY_H */
