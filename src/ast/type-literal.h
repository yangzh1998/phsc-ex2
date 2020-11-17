/**
 * @file ast/type-literal.h
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

#ifndef AST_TYPE_LITERAL_H
#define AST_TYPE_LITERAL_H

#include <string>
#include <memory> // unique_ptr
#include "ast-node.h"
#include "../visitor/visitor.h"

namespace phsc {

class TypeLiteral : public ASTNode {
public:
  TypeLiteral(int tag, const phsc::location& loc): ASTNode(tag, loc), _mut(false) {}
  bool isMutable() const { return _mut; }
  void setMutable(bool mut) { _mut = mut; }
  
  /**
   * @attention I won't add mutablilty info into this string.
   * This string is used to generate a unique identifier for a function definition,
   * and functions with arguments in all the same types but different mutability are still considered duplicated.
   */
  virtual const std::string toString() const = 0;
private:
  bool _mut;
}; // TypeLiteral


class TypeBasic : public TypeLiteral {
public:
  enum class TypeTag {
    I32,
    F64,
    STR
  };
  
  TypeBasic(const phsc::location& loc, TypeTag type):
      TypeLiteral(ASTNode::TYPE_BASIC, loc), _type(type) {}
  TypeTag getTypeTag() const { return _type; }
  
  virtual void accept(Visitor& v) override {
    v.visitTypeBasic(*this);
  }
  
  virtual const std::string toString() const override {
    switch (_type) {
      case TypeTag::I32: return "i32";
      case TypeTag::F64: return "f64";
      case TypeTag::STR: return "str";
    }
  }
  
private:
  TypeTag _type;
}; // TypeBasic


class TypeStruct : public TypeLiteral {
public:
  TypeStruct(const phsc::location& loc, const std::string& name):
      TypeLiteral(ASTNode::TYPE_STRUCT, loc), _name(name) {}
  const std::string& getName() const { return _name; }
  
  virtual void accept(Visitor& v) override {
    v.visitTypeStruct(*this);
  }
  
  virtual const std::string toString() const override {
    return getName();
  }
  
private:
  std::string _name;
}; // TypeStruct


class TypeArray : public TypeLiteral {
public:
  TypeArray(const phsc::location& loc, TypeLiteral& eleType, bool eleOwn):
      TypeLiteral(ASTNode::TYPE_ARRAY, loc), _elementType(&eleType),
      _elementOwn(eleOwn) {}
  TypeLiteral& getElementType() const { return *(_elementType.get()); }
  bool elementHasOwnership() const { return _elementOwn; }
  
  virtual void accept(Visitor& v) override {
    v.visitTypeArray(*this);
  }
  
  virtual const std::string toString() const override {
    return _elementType->toString() + "[]";
  }
  
private:
  std::unique_ptr<TypeLiteral> _elementType;
  bool _elementOwn;
}; // TypeArray

} // namespace phsc

#endif /* AST_TYPE_LITERAL_H */
