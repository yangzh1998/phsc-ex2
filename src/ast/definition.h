/**
 * @file ast/definition.h
 * @brief Classes of all definition node in AST..
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-26
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef AST_DEFINITION_H
#define AST_DEFINITION_H

#include <string>
#include <sstream>
#include <memory> // unique_ptr shared_ptr
#include "ast-node.h"
#include "type-literal.h"
#include "../visitor/visitor.h"

namespace phsc {

class VarDef : public ASTNode {
public:
  VarDef(const phsc::location& loc, const std::string& name,
         TypeLiteral& tl):
  ASTNode(ASTNode::VAR_DEF, loc), _name(name), _typeLiteral(&tl), _own(false) {}
  
  const std::string& getName() const { return _name; }
  TypeLiteral& getTypeLiteral() const { return *(_typeLiteral.get()); }
  bool hasOwnership() const { return _own; }
  void setOwnership(bool own) { _own = own; }
  
  virtual void accept(Visitor& v) override {
    v.visitVarDef(*this);
  }
  
private:
  std::string _name;
  std::unique_ptr<TypeLiteral> _typeLiteral;
  bool _own;
}; // VarDef


class StructSymbol;
class StructDef : public ASTNode {
public:
  using FieldList = std::vector<std::unique_ptr<VarDef>>;
  
  StructDef(const phsc::location& loc, const std::string& name,
            FieldList& fields):
  ASTNode(ASTNode::STRUCT_DEF, loc), _name(name), _fields(&fields) {}
  
  const std::string& getName() const { return _name; }
  FieldList& getFields() const { return *(_fields.get()); }
  
  void setSymbol(const std::shared_ptr<phsc::StructSymbol>& sym) {
    _symbol = sym;
  }
  const std::shared_ptr<phsc::StructSymbol>& getSymbol() const {
    return _symbol;
  }
  
  virtual void accept(Visitor& v) override {
    v.visitStructDef(*this);
  }
  
private:
  std::string _name;
  std::unique_ptr<FieldList> _fields;
  std::shared_ptr<phsc::StructSymbol> _symbol;
}; // StructDef


class Block;
class FuncSymbol;
class FuncDef : public ASTNode {
public:
  using FormalList = std::vector<std::unique_ptr<VarDef>>;
  
  FuncDef(const phsc::location& loc, const std::string& name,
          FormalList& vdefs, Block& body):
  ASTNode(ASTNode::FUNC_DEF, loc), _name(name), _formals(&vdefs),
  _body(&body) {
    std::stringstream ss;
    ss << "$" << _name;
    for (std::unique_ptr<VarDef>& vdef : *_formals) {
      TypeLiteral& tlit = vdef->getTypeLiteral();
      ss << "$" << tlit.toString();
    }
    _hashString = ss.str();
  }
  
  const std::string& getName() const { return _name; }
  const std::string& getHashString() const { return _hashString; }
  FormalList& getFormals() const { return *(_formals.get()); }
  Block& getBody() const { return *(_body.get()); }
  
  void setSymbol(const std::shared_ptr<phsc::FuncSymbol>& sym) {
    _symbol = sym;
  }
  const std::shared_ptr<phsc::FuncSymbol>& getSymbol() const {
    return _symbol;
  }
  
  virtual void accept(Visitor& v) override {
    v.visitFuncDef(*this);
  }
  
private:
  std::string _name;
  std::string _hashString;
  std::unique_ptr<FormalList> _formals;
  std::unique_ptr<Block> _body;
  std::shared_ptr<phsc::FuncSymbol> _symbol;
}; // FuncDef


class Assignment;
class VarDefAssign : public ASTNode {
public:
  VarDefAssign(const phsc::location& loc, VarDef& vdef, Assignment& assign):
  ASTNode(ASTNode::VAR_DEF_ASSIGN, loc), _vdef(&vdef), _assign(&assign) {}
  
  VarDef& getDefinition() const { return *(_vdef.get()); }
  Assignment& getAssignment() const { return *(_assign.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitVarDefAssign(*this);
  }
  
private:
  std::unique_ptr<VarDef> _vdef;
  std::unique_ptr<Assignment> _assign;
}; // VarDefAssign

} // namespace phsc

#endif /* AST_DEFINITION_H */
