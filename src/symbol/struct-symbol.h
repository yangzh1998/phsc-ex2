/**
 * @file symbol/struct-symbol.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-14
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef SYMBOL_STRUCT_SYMBOL_H
#define SYMBOL_STRUCT_SYMBOL_H

#include <sstream>
#include "symbol.h"

namespace phsc {

class StructScope;

class StructSymbol : public Symbol {
public:
  StructSymbol(const std::string& name, const phsc::location& loc):
      Symbol(Symbol::Kind::STRUCT, name, loc) {}

  void setAssociatedScope(const std::shared_ptr<phsc::StructScope>& assScope) {
    _associatedScope = assScope;
  }
  const std::shared_ptr<phsc::StructScope>& getAssociatedScope() const {
    return _associatedScope;
  }
  
  virtual std::string toString() const override {
    std::stringstream ss;
    ss << _loc << " -> struct " << _name;
    return ss.str();
  }

private:
  std::shared_ptr<phsc::StructScope> _associatedScope;
}; // StructSymbol

} // namespace phsc

#endif /* SYMBOL_STRUCT_SYMBOL_H */
