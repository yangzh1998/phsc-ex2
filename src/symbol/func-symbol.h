/**
 * @file symbol/func-symbol.h
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

#ifndef SYMBOL_FUNC_SYMBOL_H
#define SYMBOL_FUNC_SYMBOL_H

#include <sstream>
#include "symbol.h"

namespace phsc {

class FormalScope;

class FuncSymbol : public Symbol {
public:
  FuncSymbol(const std::string& name, const phsc::location& loc):
      Symbol(Symbol::Kind::FUNC, name, loc) {}

  void setAssociatedScope(const std::shared_ptr<phsc::FormalScope>& assScope) {
    _associatedScope = assScope;
  }
  const std::shared_ptr<phsc::FormalScope>& getAssociatedScope() const {
    return _associatedScope;
  }
  
  virtual std::string toString() const override {
    std::stringstream ss;
    ss << _loc << " -> func " << _name;
    return ss.str();
  }

private:
  std::shared_ptr<phsc::FormalScope> _associatedScope;
}; // FuncSymbol

} // namespace phsc

#endif /* SYMBOL_FUNC_SYMBOL_H */
