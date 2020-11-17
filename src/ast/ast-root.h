/**
 * @file ast/ast-root.h
 * @brief Root node of the whole AST.
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

#ifndef AST_AST_ROOT_H
#define AST_AST_ROOT_H

#include <vector>
#include <string>
#include <memory> // unique_ptr shared_ptr
#include "ast-node.h"
#include "../visitor/visitor.h"
#include "../symbol/scope.h"

namespace phsc {

class ASTRoot : public ASTNode {
public:
  using DefList = std::vector<std::unique_ptr<ASTNode>>;
  
  ASTRoot(const phsc::location& loc, DefList& defs):
      ASTNode(ASTNode::AST_ROOT, loc), _defs(&defs) {
    _globalStructScope = std::make_shared<phsc::GlobalStructScope>();
    _globalFuncScope = std::make_shared<phsc::GlobalFuncScope>();
  }
  
  DefList& getDefinitions() const { return *(_defs.get()); }
  
  const std::shared_ptr<phsc::GlobalStructScope>& getGlobalStructScope() {
    return _globalStructScope;
  }
  const std::shared_ptr<phsc::GlobalFuncScope>& getGlobalFuncScope() {
    return _globalFuncScope;
  }
  
  virtual void accept(Visitor& v) override {
    v.visitASTRoot(*this);
  }
  
private:
  std::unique_ptr<DefList> _defs;
  std::shared_ptr<phsc::GlobalStructScope> _globalStructScope;
  std::shared_ptr<phsc::GlobalFuncScope> _globalFuncScope;
}; // ASTRoot

} // namespace phsc

#endif /* AST_AST_ROOT_H */
