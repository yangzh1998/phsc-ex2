/**
 * @file type/struct-type.h
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

#ifndef TYPE_STRUCT_TYPE_H
#define TYPE_STRUCT_TYPE_H

#include <string>
#include "type.h"

namespace phsc {

class StructType : public Type {
public:
  StructType(const std::string& name, bool mut):
      Type(Type::SubType::StructType, mut), _name(name) {}
  
  const std::string& getName() const { return _name; }
  
  virtual bool isCompatible(const Type& type) const override {
    return false;
  }
  
  virtual bool operator==(const Type& type) const override {
    return false;
  }
  
  virtual const std::string toString() const override {
    if (isMutable()) {
      return std::string("(mut struct ") + _name + ")";
    } else {
      return std::string("struct ") + _name;
    }
  }

private:
  std::string _name;
}; // StructType

} // namespace phsc

#endif /* TYPE_STRUCT_TYPE_H */
