/**
 * @file type/array-type.h
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

#ifndef TYPE_ARRAY_TYPE_H
#define TYPE_ARRAY_TYPE_H

#include <memory> // shared_ptr
#include "type.h"

namespace phsc {

class ArrayType : public Type {
public:
  ArrayType(const std::shared_ptr<phsc::Type>& elementType,
            bool elementOwnership, bool mut):
      Type(Type::SubType::ArrayType, mut), _elementType(elementType),
      _elementOwnership(elementOwnership) {}
  
  const std::shared_ptr<phsc::Type>& getElementType() { return _elementType; }
  bool elementHasOwnership() { return _elementOwnership; }
  
  virtual bool isCompatible(const Type& type) const override {
    if (type.getSubType() == Type::SubType::NullType) return true;
    if (isMutable() && !(type.isMutable())) return false;
    if (type.getSubType() != Type::SubType::ArrayType) return false;
    const ArrayType& arrayType = static_cast<const ArrayType&>(type);
    return (_elementType.isCompatible(arrayType.getElementType()));
    // TODO: What about element ownership?
  }
  
  virtual bool operator==(const Type& type) const override {
    if (isMutable() != type.getMutable()) return false;
    if (type.getSubType() != Type::SubType::ArrayType) return false;
    const ArrayType& arrayType = static_cast<const ArrayType&>(type);
    return (_elementType == arrayType.getElementType());
    // TODO: What about element ownership?
  }
            
  virtual const std::string toString() const override {
    if (isMutable()) {
      return std::string("mut ") + _elementType.toString() + "[]";
    } else {
      return _elementType.toString() + "[]";
    }
    // TODO: What about element ownership?
  }
  
private:
  std::shared_ptr<phsc::Type> _elementType;
  bool _elementOwnership;
}; // ArrayType

} // namespace phsc

#endif /* TYPE_ARRAY_TYPE_H */
