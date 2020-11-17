/**
 * @file ast/expr.h
 * @brief Base class of all expression types.
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-23
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef AST_EXPR_H
#define AST_EXPR_H

#include <memory> // shared_ptr
#include "ast-node.h"
#include "../type/type.h"

namespace phsc {

class Expr : public ASTNode {
public:
  Expr(int tag, const phsc::location& loc): ASTNode(tag, loc) {}
  const std::shared_ptr<phsc::Type>& getType() const { return _type; }
  void setType(const std::shared_ptr<phsc::Type>& type) { _type = type; }
  
private:
  std::shared_ptr<phsc::Type> _type;
  
}; // Expr

} // namespace phsc

#endif /* AST_EXPR_H */
