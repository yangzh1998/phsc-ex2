/**
 * @file symbol/var-symbol.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-15
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef SYMBOL_VAR_SYMBOL_H
#define SYMBOL_VAR_SYMBOL_H

#include <sstream>
#include "symbol.h"
#include "scope.h"

namespace phsc {

class VarSymbol : public Symbol {
public:
  VarSymbol(const std::string& name, const phsc::location& loc):
      Symbol(Symbol::Kind::VAR, name, loc) {}
  
  void setOffset(int offset) { _offset = offset; }
  int getOffset() const { return _offset; }
  bool isMemberVar() const { return getScope()->getKind() == Scope::Kind::STRUCT; }
  bool isParam() const { return getScope()->getKind() == Scope::Kind::FORMAL; }
  bool isLocalVar() const { return getScope()->getKind() == Scope::Kind::LOCAL; }
  
  virtual std::string toString() const override {
    std::stringstream ss;
    ss << _loc << " -> variable ";
    if (isParam()) ss << '@';
    ss << _name << " : ";
    //ss << _type; // FIXME: print type
    return ss.str();
  }

private:
  int _offset;
}; // VarSymbol

} // namespace phsc

#endif /* SYMBOL_VAR_SYMBOL_H */
