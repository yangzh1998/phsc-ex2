/**
 * @file ast/new.h
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

#ifndef AST_NEW_H
#define AST_NEW_H

#include <string>
#include <memory> // unique_ptr
#include "expr.h"
#include "../visitor/visitor.h"

namespace phsc {

class NewStruct : public Expr {
public:
  NewStruct(const phsc::location& loc, const std::string& name):
      Expr(ASTNode::NEW_STRUCT, loc), _name(name) {}
  
  const std::string& getName() const { return _name; }
  
  virtual void accept(Visitor& v) override {
    v.visitNewStruct(*this);
  }
  
private:
  std::string _name;
}; // NewStruct


class TypeLiteral;
class NewArray : public Expr {
public:
  NewArray(const phsc::location& loc, TypeLiteral& elementType, Expr& length):
      Expr(ASTNode::NEW_ARRAY, loc), _elementType(&elementType),
      _length(&length) {}
  
  TypeLiteral& getElementType() const { return *(_elementType.get()); }
  Expr& getLength() const { return *(_length.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitNewArray(*this);
  }
  
private:
  std::unique_ptr<TypeLiteral> _elementType;
  std::unique_ptr<Expr> _length;
}; // NewArray

} // namespace phsc

#endif /* AST_NEW_H */
