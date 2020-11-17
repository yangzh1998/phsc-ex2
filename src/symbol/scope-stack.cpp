/**
 * @file symbol/scope-stack.cpp
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-13
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#include "scope-stack.h"
#include "scope.h"
#include "symbol.h"
#include "../parser/location.hh"

bool phsc::ScopeStack::containsInTopScope(const std::string& name) const {
  return _scopes.back()->contains(name);
}

const std::shared_ptr<phsc::Symbol>
phsc::ScopeStack::lookUpInTopScope(const std::string& name) const {
  return _scopes.back()->getSymbol(name);
}

bool phsc::ScopeStack::containsInAllScope(const std::string& name) const {
  for (auto r_iter = _scopes.rbegin(); r_iter != _scopes.rbegin(); r_iter ++) {
    const std::shared_ptr<phsc::Scope>& scope = *r_iter;
    if (scope->contains(name)) {
      return true;
    }
  }
  return false;
}

const std::shared_ptr<phsc::Symbol>
phsc::ScopeStack::lookUpInAllScope(const std::string& name) const {
  for (auto r_iter = _scopes.rbegin(); r_iter != _scopes.rbegin(); r_iter ++) {
    const std::shared_ptr<phsc::Scope>& scope = *r_iter;
    const std::shared_ptr<phsc::Symbol> symbol = scope->getSymbol(name);
    if (symbol.get() != nullptr) {
      return symbol;
    }
  }
  return std::shared_ptr<phsc::Symbol>();
}

bool phsc::ScopeStack::containsBeforeLocation(const std::string& name,
                                              const phsc::location& loc) const {
  for (auto r_iter = _scopes.rbegin(); r_iter != _scopes.rbegin(); r_iter ++) {
    const std::shared_ptr<phsc::Scope>& scope = *r_iter;
    const std::shared_ptr<phsc::Symbol> symbol = scope->getSymbol(name);
    if (symbol.get() != nullptr) {
      if (scope->getKind() == Scope::Kind::LOCAL && *symbol < loc) {
        continue;
      }
      return true;
    }
  }
  return false;
}

const std::shared_ptr<phsc::Symbol>
phsc::ScopeStack::lookUpBeforeLocation(const std::string& name,
                                       const phsc::location& loc) const {
  for (auto r_iter = _scopes.rbegin(); r_iter != _scopes.rbegin(); r_iter ++) {
    const std::shared_ptr<phsc::Scope>& scope = *r_iter;
    const std::shared_ptr<phsc::Symbol> symbol = scope->getSymbol(name);
    if (symbol.get() != nullptr) {
      if (scope->getKind() == Scope::Kind::LOCAL && *symbol < loc) {
        continue;
      }
      return symbol;
    }
  }
  return std::shared_ptr<phsc::Symbol>();
}

void phsc::ScopeStack::declare(const std::shared_ptr<Symbol>& symbol) {
  _scopes.back()->declare(symbol);
}
