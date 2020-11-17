/**
 * @file ast/statement.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-27
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef AST_STATEMENT_H
#define AST_STATEMENT_H

#include <vector>
#include <memory> // unique_ptr shared_ptr
#include "ast-node.h"
#include "expr.h"
#include "../visitor/visitor.h"

namespace phsc {

class LocalScope;
class Block : public ASTNode {
public:
  using StmtList = std::vector<std::unique_ptr<ASTNode>>;
  
  Block(const phsc::location& loc, StmtList& stmts):
      ASTNode(ASTNode::BLOCK, loc), _stmts(&stmts) {}
  StmtList& getStmts() const { return *(_stmts.get()); }
  
  void setAssociatedScope(const std::shared_ptr<phsc::LocalScope>& assScope) {
    _associatedScope = assScope;
  }
  const std::shared_ptr<phsc::LocalScope>& getAssociatedScope() const {
    return _associatedScope;
  }
  
  virtual void accept(Visitor& v) override {
    v.visitBlock(*this);
  }
  
private:
  std::unique_ptr<StmtList> _stmts;
  std::shared_ptr<phsc::LocalScope> _associatedScope;
}; // Block


class EmptyStmt : public ASTNode {
public:
  explicit EmptyStmt(const phsc::location& loc):ASTNode(ASTNode::EMPTY_STMT, loc){}
  virtual void accept(Visitor& v) override {
    v.visitEmptyStmt(*this);
  }
}; // EmptyStmt


class Break : public ASTNode {
public:
  explicit Break(const phsc::location& loc): ASTNode(ASTNode::BREAK, loc) {}
  virtual void accept(Visitor& v) override {
    v.visitBreak(*this);
  }
}; // Break


class Continue : public ASTNode {
public:
  explicit Continue(const phsc::location& loc): ASTNode(ASTNode::CONTINUE, loc) {}
  virtual void accept(Visitor& v) override {
    v.visitContinue(*this);
  }
}; // Continue


class Return : public ASTNode {
public:
  explicit Return(const phsc::location& loc): ASTNode(ASTNode::RETURN, loc) {}
  virtual void accept(Visitor& v) override {
    v.visitReturn(*this);
  }
}; // Return


class If : public ASTNode {
public:
  If(const phsc::location& loc, Expr& cond, ASTNode& trueBranch,
     ASTNode& falseBranch):
      ASTNode(ASTNode::IF, loc), _condition(&cond), _trueBranch(&trueBranch),
      _falseBranch(&falseBranch) {}
  
  Expr& getCondition() const { return *(_condition.get()); }
  ASTNode& getTrueBranch() const { return *(_trueBranch.get()); }
  ASTNode& getFalseBranch() const { return *(_falseBranch.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitIf(*this);
  }
  
private:
  std::unique_ptr<Expr> _condition;
  std::unique_ptr<ASTNode> _trueBranch;
  std::unique_ptr<ASTNode> _falseBranch;
}; // If


class WhileLoop : public ASTNode {
public:
  WhileLoop(const phsc::location& loc, Expr& cond, ASTNode& stmt):
      ASTNode(ASTNode::WHILE_LOOP, loc), _condition(&cond), _loopBody(&stmt) {}
  
  Expr& getCondition() const { return *(_condition.get()); }
  ASTNode& getLoopBody() const { return *(_loopBody.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitWhileLoop(*this);
  }
  
private:
  std::unique_ptr<Expr> _condition;
  std::unique_ptr<ASTNode> _loopBody;
}; // WhileLoop


class ForLoop : public ASTNode {
public:
  ForLoop(const phsc::location& loc, ASTNode& init, Expr& cond,
          ASTNode& update, ASTNode& stmt):
      ASTNode(ASTNode::FOR_LOOP, loc), _init(&init), _condition(&cond),
      _update(&update), _loopBody(&stmt) {}
  
  ASTNode& getInit() const { return *(_init.get()); }
  Expr& getCondition() const { return *(_condition.get()); }
  ASTNode& getUpdate() const { return *(_update.get()); }
  ASTNode& getLoopBody() const { return *(_loopBody.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitForLoop(*this);
  }
  
private:
  std::unique_ptr<ASTNode> _init;
  std::unique_ptr<Expr> _condition;
  std::unique_ptr<ASTNode> _update;
  std::unique_ptr<ASTNode> _loopBody;
}; // ForLoop

} // namespace phsc

#endif /* AST_STATEMENT_H */
