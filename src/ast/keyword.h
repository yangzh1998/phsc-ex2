/**
 * @file ast/keyword.h
 * @brief Base class of all expression types.
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

#ifndef AST_KEYWORD_H
#define AST_KEYWORD_H

#include <string>
#include "ast-node.h"
#include "../visitor/visitor.h"

namespace phsc {

class Keyword : public ASTNode {
public:
  Keyword(const phsc::location& loc, int token): ASTNode(ASTNode::KEYWORD, loc),
      _token(token) {}
  int getToken() const { return _token; }
  
  virtual void accept(Visitor& v) override {
    v.visitKeyword(*this);
  }
  
private:
  int _token;
}; // Keyword

} // namespace phsc

#endif /* AST_KEYWORD_H */
