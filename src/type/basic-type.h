/**
 * @file type/basic-type.h
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

#ifndef TYPE_BASIC_TYPE_H
#define TYPE_BASIC_TYPE_H

#include "type.h"

namespace phsc {

class I32Type;
class F64Type;
class StrType;

class BasicType : public Type {
public:
  enum class PrimitiveType {
    I32,
    F64,
    STR
  };
  
  BasicType(PrimitiveType pt, bool mut): Type(Type::TypeTag::BasicType, mut),
      _primitiveType(pt) {}
  
  PrimitiveType getPrimitiveType() const { return _primitiveType; }
  
  virtual bool isCompatible(const Type& type) const override {
    if (isMutable() && !(type.isMutable())) return false;
    if (type.getTypeTag() != Type::TypeTag::BasicType) return false;
    const BasicType& basicType = static_cast<const BasicType&>(type);
    return (getPrimitiveType() == basicType.getPrimitiveType());
  }
  
  virtual bool operator==(const Type& type) const override {
    if (isMutable() != type.isMutable()) return false;
    if (type.getTypeTag() != Type::TypeTag::BasicType) return false;
    const BasicType& basicType = static_cast<const BasicType&>(type);
    return (getPrimitiveType() == basicType.getPrimitiveType());
  }
  
private:
  PrimitiveType _primitiveType;
}; // BasicType

class I32Type : public BasicType {
public:
  explicit I32Type(bool mut): BasicType(PrimitiveType::I32, mut) {}
  
  virtual bool isCompatible(const Type& type) const override {
    if (isMutable() && !(type.isMutable())) return false;
    if (type.getTypeTag() != Type::TypeTag::BasicType) return false;
    const BasicType& basicType = static_cast<const BasicType&>(type);
    return (basicType.getPrimitiveType() == BasicType::PrimitiveType::I32) ||
        (basicType.getPrimitiveType() == BasicType::PrimitiveType::F64);
  }
  
  virtual const std::string toString() const override {
    return isMutable() ? "(mut i32)" : "i32";
  }
}; // I32Type

class F64Type : public BasicType {
public:
  explicit F64Type(bool mut): BasicType(PrimitiveType::F64, mut) {}
  
  virtual bool isCompatible(const Type& type) const override {
    if (isMutable() && !(type.isMutable())) return false;
    if (type.getTypeTag() != Type::TypeTag::BasicType) return false;
    const BasicType& basicType = static_cast<const BasicType&>(type);
    return (basicType.getPrimitiveType() == BasicType::PrimitiveType::I32) ||
        (basicType.getPrimitiveType() == BasicType::PrimitiveType::F64);
  }

  virtual const std::string toString() const override {
    return isMutable() ? "(mut f64)" : "f64";
  }
}; // F64Type

class StrType : public BasicType {
public:
  explicit StrType(bool mut): BasicType(PrimitiveType::STR, mut) {}

  virtual const std::string toString() const override {
    return isMutable() ? "(mut str)" : "str";
  }
}; // StrType

} // namespace phsc

#endif /* TYPE_BASIC_TYPE_H */
