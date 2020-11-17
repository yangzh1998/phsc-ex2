/**
 * @file ast/assignment.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-28
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef AST_ASSIGNMENT_H
#define AST_ASSIGNMENT_H

#include <string>
#include <memory> // unique_ptr
#include "expr.h"
#include "keyword.h"

namespace phsc {

class LeftValue : public Expr {
public:
  LeftValue(int tag, const phsc::location& loc): Expr(tag, loc) {}
}; // LeftValue


class Assignment : public ASTNode {
public:
  enum class AssignOp {
    ASSIGN,
    ADD_ASSIGN,
    SUB_ASSIGN,
    MUL_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN,
    AND_ASSIGN,
    XOR_ASSIGN,
    OR_ASSIGN,
    SHIFT_LEFT_ASSIGN,
    SHIFT_RIGHT_ASSIGN
  };
  
  Assignment(const phsc::location& loc, LeftValue& lvalue, Expr& expr,
             AssignOp op):
  ASTNode(ASTNode::ASSIGNMENT, loc), _left(&lvalue), _right(&expr), _op(op) {}
  
  LeftValue& getLeft() const { return *(_left.get()); }
  Expr& getRight() const { return *(_right.get()); }
  AssignOp getOp() const { return _op; }
  
  virtual void accept(Visitor& v) override {
    v.visitAssignment(*this);
  }
  
private:
  std::unique_ptr<LeftValue> _left;
  std::unique_ptr<Expr> _right;
  AssignOp _op;
}; // Assignment


class Variable : public LeftValue {
public:
  Variable(int tag, const phsc::location& loc, const std::string& name):
      LeftValue(tag, loc), _name(name) {}
  const std::string& getName() { return _name; }
protected:
  std::string _name;
}; // Variable


class DirectVar : public Variable {
public:
  DirectVar(const phsc::location& loc, const std::string& name):
      Variable(ASTNode::DIRECT_VAR, loc, name) {}
  
  virtual void accept(Visitor& v) override {
    v.visitDirectVar(*this);
  }
  
}; // DirectVar


class MemberVar : public Variable {
public:
  MemberVar(const phsc::location& loc, const std::string& name,
            Expr& owner):
      Variable(ASTNode::MEMBER_VAR, loc, name), _owner(&owner) {}
  
  Expr& getOwner() const { return *(_owner.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitMemberVar(*this);
  }
  
private:
  std::unique_ptr<Expr> _owner;
}; // MemberVar


class Indexed : public LeftValue {
public:
  Indexed(const phsc::location& loc, Expr& array, Expr& index):
      LeftValue(ASTNode::INDEXED, loc), _array(&array), _index(&index) {}
  
  Expr& getArray() const { return *(_array.get()); }
  Expr& getIndex() const { return *(_index.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitIndexed(*this);
  }
  
private:
  std::unique_ptr<Expr> _array;
  std::unique_ptr<Expr> _index;
}; // Indexed

} // namespace phsc

#endif /* AST_ASSIGNMENT_H */
