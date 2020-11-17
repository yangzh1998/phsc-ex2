/**
 * @file symbol/scope-stack.h
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

#ifndef SYMBOL_SCOPE_STACK_H
#define SYMBOL_SCOPE_STACK_H

#include <vector>
#include <string>
#include <memory> // unique_ptr shared_ptr

namespace phsc {

class Scope;
class Symbol;
class location;

class ScopeStack {
public:
  ScopeStack() {}
  
  bool containsInTopScope(const std::string&) const;
  const std::shared_ptr<Symbol> lookUpInTopScope(const std::string&) const;
  bool containsInAllScope(const std::string&) const;
  const std::shared_ptr<Symbol> lookUpInAllScope(const std::string&) const;
  bool containsBeforeLocation(const std::string&, const phsc::location&) const;
  const std::shared_ptr<Symbol> lookUpBeforeLocation(const std::string&,
                                                      const phsc::location&) const;
  
  void declare(const std::shared_ptr<Symbol>&);
  
  const std::shared_ptr<Scope>& getGlobalScope() const {
    return _scopes[0];
  }
  const std::shared_ptr<Scope>& getCurrentScope() const {
    return _scopes.back();
  }
  void open(const std::shared_ptr<Scope>& scope) {
    _scopes.push_back(scope);
  }
  void close() { _scopes.pop_back(); }
  
private:
  std::vector<std::shared_ptr<Scope>> _scopes;
}; // ScopeStack

} // namespace phsc

#endif /* SYMBOL_SCOPE_STACK_H */
