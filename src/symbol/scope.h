/**
 * @file symbol/scope.h
 * @brief Classes for all symbol scopes.
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-12
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef SYMBOL_SCOPE_H
#define SYMBOL_SCOPE_H

#include <string>
#include <unordered_map>
#include <vector>
//#include <algorithm> // make_heap
#include <memory> // shared_ptr

namespace phsc {

class Symbol;

#ifndef PHSC_LITE
class IndentPrintWriter;
#endif
/**
 * @attention All objects based on Scope use shared_ptr and weak_ptr.
 * You know, STL containers don't allow reference types as template, and I hate raw pointer,
 * so I have to use shared_ptr to use STL containers without offering them ownership.
 */
class Scope {
public:
  enum class Kind {
    GLOBAL_STRUCT,
    GLOBAL_FUNC,
    STRUCT,
    FORMAL,
    LOCAL
  };
  
  explicit Scope(Kind k): _kind(k) {
    //std::make_heap(_symbols.begin(), _symbols.end());
  }
  virtual ~Scope() {}
  
  Kind getKind() const { return _kind; }
  
  bool contains(const std::string&) const;
  const std::shared_ptr<Symbol> getSymbol(const std::string&);
  void declare(const std::shared_ptr<Symbol>&);
  
#ifndef PHSC_LITE
  virtual void printTo(IndentPrintWriter&) const = 0;
#endif
  
protected:
  std::unordered_map<std::string, std::shared_ptr<Symbol>> _symbolMap;
  std::vector<std::shared_ptr<Symbol>> _symbols; // make symbols in order
  // Symbols are added in location order, so there's no need to make_heap.
  
private:
  Kind _kind;
}; // Scope

class GlobalStructScope : public Scope {
public:
  GlobalStructScope(): Scope(Scope::Kind::GLOBAL_STRUCT) {}
#ifndef PHSC_LITE
  virtual void printTo(IndentPrintWriter&) const override;
#endif
}; // GlobalStructScope


class GlobalFuncScope : public Scope {
public:
  GlobalFuncScope(): Scope(Scope::Kind::GLOBAL_FUNC) {}
#ifndef PHSC_LITE
  virtual void printTo(IndentPrintWriter&) const override;
#endif
}; // GlobalFuncScope


class StructSymbol;
class StructScope : public Scope {
public:
  explicit StructScope(const std::shared_ptr<phsc::StructSymbol>& owner):
      Scope(Scope::Kind::STRUCT), _owner(owner) {}
  const std::shared_ptr<StructSymbol> getOwner() const { return _owner.lock(); }
#ifndef PHSC_LITE
  virtual void printTo(IndentPrintWriter&) const override;
#endif
private:
  std::weak_ptr<StructSymbol> _owner;
}; // StructScope


class FuncSymbol;
class Block;
class FormalScope : public Scope {
public:
  FormalScope(const std::shared_ptr<phsc::FuncSymbol>& owner,
              const phsc::Block& block):
      Scope(Scope::Kind::FORMAL), _owner(owner), _block(block) {}
  const phsc::Block& getBlock() const { return _block; }
  const std::shared_ptr<FuncSymbol> getOwner() const { return _owner.lock(); }
#ifndef PHSC_LITE
  virtual void printTo(IndentPrintWriter&) const override;
#endif
private:
  std::weak_ptr<FuncSymbol> _owner;
  const phsc::Block& _block;
}; // FormalScope


class LocalScope : public Scope {
public:
  using SubscopeList = std::vector<std::shared_ptr<LocalScope>>;
  explicit LocalScope(const phsc::Block& block): Scope(Scope::Kind::LOCAL),
      _block(block) {}
  const phsc::Block& getBlock() const { return _block; }
  const SubscopeList& getSubscopes() const { return _subscopes; }
  void append(const std::shared_ptr<LocalScope>& ls) { _subscopes.push_back(ls); }
#ifndef PHSC_LITE
  virtual void printTo(IndentPrintWriter&) const override;
#endif
private:
  const phsc::Block& _block;
  SubscopeList _subscopes;
}; // LocalScope

} // namespace phsc

#endif /* SYMBOL_SCOPE_H */
