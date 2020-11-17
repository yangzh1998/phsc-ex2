/**
 * @file ast/literal.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-24
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef AST_LITERAL_H
#define AST_LITERAL_H

#include <stdint.h> // int32_t
#include <string>
#include "expr.h"
#include "../visitor/visitor.h"
#include "../type/type.h"
#include "../type/basic-type.h"

namespace phsc {

class I32Literal : public Expr {
public:
  I32Literal(const phsc::location& loc, int32_t val):
      Expr(ASTNode::I32_LITERAL, loc), _value(val) {}
  int32_t getValue() const { return _value; }
  virtual void accept(Visitor& v) override {
    v.visitI32Literal(*this);
  }
  
private:
  int32_t _value;
  
}; // I32Literal

class F64Literal : public Expr {
public:
  F64Literal(const phsc::location& loc, double val):
      Expr(ASTNode::F64_LITERAL, loc), _value(val) {}
  double getValue() const { return _value; }
  virtual void accept(Visitor& v) override {
    v.visitF64Literal(*this);
  }
  
private:
  double _value;
  
}; // F64Literal

class StrLiteral : public Expr {
public:
  StrLiteral(const phsc::location& loc, std::string val):
      Expr(ASTNode::STR_LITERAL, loc), _value(val) {}
  const std::string& getValue() const { return _value; }
  virtual void accept(Visitor& v) override {
    v.visitStrLiteral(*this);
  }
  
private:
  std::string _value;
  
}; // StrLiteral

class NullLiteral : public Expr {
public:
  explicit NullLiteral(const phsc::location& loc):
      Expr(ASTNode::NULL_LITERAL, loc) {}
  virtual void accept(Visitor& v) override {
    v.visitNullLiteral(*this);
  }
}; // Null

} // namespace phsc

#endif /* AST_LITERAL_H */
