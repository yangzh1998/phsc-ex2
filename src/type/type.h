/**
 * @file type/type.h
 * @brief Type for the hamsic expression.
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

#ifndef TYPE_TYPE_H
#define TYPE_TYPE_H

#include <string>

namespace phsc {

/**
 * @class Type
 * @brief An abstract base class for all the type of the hamsic expression.
 *
 * @attention All objects based on Type use shared_ptr.
 * I hate raw pointer, and the ownership of Type objects is really complicated,
 * so this can hardly be done by using unique_ptr only.
 */
class Type {
public:
  enum class TypeTag {
    BasicType,
    ArrayType,
    StructType,
    FuncType,
    NullType,
    //UnknownType,
    ErrorType
  };
  
  explicit Type(TypeTag tag, bool mut = false): _tag(tag), _mutable(mut) {}
  virtual ~Type() {}
  TypeTag getTypeTag() const { return _tag; }
  bool isMutable() const { return _mutable; }
  
  virtual bool isCompatible(const Type& type) const {
    return (*this == type);
  }
  virtual bool operator==(const Type& type) const = 0;
  virtual const std::string toString() const = 0;
  
private:
  TypeTag _tag;
  bool _mutable;
}; // Type

/**
 * @class NullType
 */
class NullType : public Type {
public:
  NullType(): Type(Type::TypeTag::ErrorType, true) {}
  virtual bool operator==(const Type& type) const override {
    return (type.getTypeTag() == Type::TypeTag::NullType
            && type.isMutable() == true);
  }
  virtual const std::string toString() const override {
    return "null";
  }
}; // NullType

/**
 * @class UnknownType
 * @brief Default type of an expression.
 * The type of a non-literal expression is not certained until a type-check pass.
 */
//class UnknownType : public Type {
//public:
//  UnknownType(): Type(Type::TypeTag::UnknownType, false) {}
//  virtual bool isCompatible(const Type& type) const override {
//    return true;
//  }
//  virtual bool operator==(const Type& type) const override {
//    return (type.getTypeTag() == Type::TypeTag::UnknownType
//            && type.isMutable() == false);
//  }
//  virtual const std::string toString() const override {
//    return "unknown";
//  }
//}; // UnknownType

/**
 * @class ErrorType
 * @brief When an error occurred in a type-check pass,
 * types of the related expressions are set error-type.
 */
class ErrorType : public Type {
public:
  ErrorType(): Type(Type::TypeTag::ErrorType, false) {}
  virtual bool operator==(const Type& type) const override {
    return (type.getTypeTag() == Type::TypeTag::ErrorType
            && type.isMutable() == false);
  }
  virtual const std::string toString() const override {
    return "error";
  }
}; // ErrorType

} // namespace phsc

#endif /* TYPE_TYPE_H */
