/**
 * @file symbol/scope.cpp
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

#include "scope.h"
#include "symbol.h"
#include "struct-symbol.h"
#include "func-symbol.h"
#include "../ast/statement.h" // Block If ForLoop WhileLoop

#ifndef PHSC_LITE
#include <sstream>
#include "../utils/indent-print-writer.h"
#endif

bool phsc::Scope::contains(const std::string& name) const {
  return _symbolMap.find(name) != _symbolMap.end();
}

const std::shared_ptr<phsc::Symbol>
phsc::Scope::getSymbol(const std::string& name) {
  auto iterator = _symbolMap.find(name);
  if (iterator == _symbolMap.end()) {
    return std::shared_ptr<phsc::Symbol>();
  }
  return iterator->second;
}

void phsc::Scope::declare(const std::shared_ptr<phsc::Symbol>& symbol) {
  _symbolMap[symbol->getName()] = symbol;
  _symbols.push_back(symbol);
  //_symbols.push_heap(_symbols.begin(), _symbols.end());
}

#ifndef PHSC_LITE

void phsc::GlobalStructScope::printTo(IndentPrintWriter& ipw) const {
  ipw.println("GLOBAL STRUCT SCOPE:");
  ipw.incIndent();
  for (const std::shared_ptr<phsc::Symbol>& symbol : _symbols) {
    ipw.println(symbol->toString());
  }
  for (const std::shared_ptr<phsc::Symbol>& symbol : _symbols) {
    const phsc::StructSymbol& ss = static_cast<const phsc::StructSymbol&>(*symbol);
    ss.getAssociatedScope()->printTo(ipw);
  }
  ipw.decIndent();
}

void phsc::GlobalFuncScope::printTo(IndentPrintWriter& ipw) const {
  ipw.println("GLOBAL FUNC SCOPE:");
  ipw.incIndent();
  for (const std::shared_ptr<phsc::Symbol>& symbol : _symbols) {
    ipw.println(symbol->toString());
  }
  for (const std::shared_ptr<phsc::Symbol>& symbol : _symbols) {
    const phsc::FuncSymbol& fs = static_cast<const phsc::FuncSymbol&>(*symbol);
    fs.getAssociatedScope()->printTo(ipw);
  }
  ipw.decIndent();
}

void phsc::StructScope::printTo(IndentPrintWriter& ipw) const {
  ipw.print("STRUCT SCOPE: ");
  ipw.println(_owner.lock()->getName());
  ipw.incIndent();
  for (const std::shared_ptr<phsc::Symbol>& symbol : _symbols) {
    ipw.println(symbol->toString());
  }
  ipw.decIndent();
}

void phsc::FormalScope::printTo(IndentPrintWriter& ipw) const {
  ipw.print("FORMAL SCOPE: ");
  ipw.println(_owner.lock()->getName());
  ipw.incIndent();
  for (const std::shared_ptr<phsc::Symbol>& symbol : _symbols) {
    ipw.println(symbol->toString());
  }
  _block.getAssociatedScope()->printTo(ipw);
  ipw.decIndent();
}

void phsc::LocalScope::printTo(IndentPrintWriter& ipw) const {
  ipw.print("LOCAL SCOPE: ");
  std::stringstream ss;
  ss << _block.getLocation();
  ipw.println(ss.str());
  ipw.incIndent();
  for (const std::shared_ptr<phsc::Symbol>& symbol : _symbols) {
    ipw.println(symbol->toString());
  }
  for (const std::shared_ptr<phsc::LocalScope>& subscope : _subscopes) {
    subscope->printTo(ipw);
  }
  ipw.decIndent();
}

#endif /* DPHSC_LLVM */
