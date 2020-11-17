/**
 * @file ast/call.h
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

#ifndef AST_CALL_H
#define AST_CALL_H

#include <string>
#include <vector>
#include <memory> // unique_ptr
#include "expr.h"
#include "../visitor/visitor.h"

namespace phsc {

class Call : public ASTNode {
public:
  using ExprList = std::vector<std::unique_ptr<Expr>>;
  
  Call(const phsc::location& loc, const std::string& funcName,
       ExprList& actuals):
      ASTNode(ASTNode::CALL, loc), _funcName(funcName), _actuals(&actuals) {}
  
  const std::string& getFuncName() const { return _funcName; }
  ExprList& getActuals() const { return *(_actuals.get()); }
  
  virtual void accept(Visitor& v) override {
    v.visitCall(*this);
  }
  
private:
  std::string _funcName;
  std::unique_ptr<ExprList> _actuals;
}; // Call

} // namespace phsc

#endif /* AST_CALL_H */
