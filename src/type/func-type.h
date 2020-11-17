/**
 * @file type/func-type.h
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

#ifndef TYPE_FUNC_TYPE_H
#define TYPE_FUNC_TYPE_H

#include <vector>
#include "type.h"

namespace phsc {

class FuncType : public Type {
public:
  FuncType(): Type(Type::SubType::FuncType, false) {}
  
  virtual bool isCompatible(const Type& type) const override {
    return false;
  }
  
  virtual bool operator==(const Type& type) const override {
    return false;
  }
  
  virtual const std::string toString() const override {
    return "hhh";
  }
  
  void appendParam(const std::shared_ptr<Type>& type) {
    _argTypes.push_back(type);
  }
  
private:
  std::vector<std::shared_ptr<Type>> _argTypes;
}; // FuncType

} // namespace phsc
  
} // namespace std

#endif /* TYPE_FUNC_TYPE_H */
