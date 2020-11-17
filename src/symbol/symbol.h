/**
 * @file symbol/symbol.h
 * @brief Abstract base class for all symbols.
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-25
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef SYMBOL_SYMBOL_H
#define SYMBOL_SYMBOL_H

#include <string>
#include <memory> // weak_ptr shared_ptr
#include "scope.h"
#include "../parser/location.hh"

namespace phsc {

class Type;

/**
 * @attention All objects based on Symbol use shared_ptr.
 * You know, STL containers don't allow reference types as template, and I hate raw pointer,
 * so I have to use shared_ptr to use STL containers without offering them ownership.
 */
class Symbol {
public:
  enum class Kind {
    STRUCT,
    FUNC,
    VAR
  };
  
  Symbol(Kind k, const std::string& name, const phsc::location& loc):
      _kind(k), _name(name), _loc(loc) {}
  virtual ~Symbol() {}
  
  Kind getKind() const { return _kind; }
  const std::string& getName() const { return _name; }
  const phsc::location& getLocation() const { return _loc; }
  const std::shared_ptr<phsc::Type>& getType() const { return _type; }
  void setType(const std::shared_ptr<phsc::Type>& type) { _type = type; }
  
  const std::shared_ptr<phsc::Scope> getScope() const {
    return _scope.lock();
  }
  void setScope(const std::shared_ptr<phsc::Scope>& scope) {
    _scope = scope;
  }
  
  virtual std::string toString() const = 0;
  
  bool operator<(const phsc::location& loc) const {
    const phsc::position& posLeft = getLocation().begin;
    const phsc::position& posRight = loc.begin;
    if (posLeft.filename && posRight.filename) {
      int ans = posLeft.filename->compare(*(posRight.filename));
      if (ans != 0) return ans < 0;
    }
    if (posLeft.line != posRight.line) return posLeft.line < posRight.line;
    return posLeft.column < posRight.column;
  }
  
  bool operator<(const Symbol& sym) const {
    return (*this) < sym.getLocation();
  }
  
protected:
  Kind _kind;
  std::string _name;
  phsc::location _loc;
  std::weak_ptr<phsc::Scope> _scope;
  std::shared_ptr<phsc::Type> _type;

}; // Symbol

} // namespace phsc

#endif /* SYMBOL_SYMBOL_H */
