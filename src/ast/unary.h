/**
 * @file ast/unary.h
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

#ifndef AST_UNARY_H
#define AST_UNARY_H

#include <memory> // unique_ptr
#include "expr.h"
#include "../visitor/visitor.h"

namespace phsc {

class Unary : public Expr {
public:
  enum class UnaryOp {
    NEG,
    NOT,
    BITWISE_NOT
  };
  
  Unary(const phsc::location& loc, Expr& expr, UnaryOp op):
      Expr(ASTNode::UNARY, loc), _expr(&expr), _op(op) {}
  
  Expr& getExpr() const { return *(_expr.get()); }
  UnaryOp getOp() const { return _op; }
  
  virtual void accept(Visitor& v) override {
    v.visitUnary(*this);
  }
  
private:
  std::unique_ptr<Expr> _expr;
  UnaryOp _op;
}; // Unary

} // namespace phsc

#endif /* AST_BINARY_H */
