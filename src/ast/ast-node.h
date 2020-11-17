/**
 * @file ast/ast-node.h
 * @brief Base class of all absract syntax tree(AST) types.
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

#ifndef AST_AST_NODE_H
#define AST_AST_NODE_H

#include "../parser/location.hh"

namespace phsc {

class Visitor;
class ASTNode {
public:
  ASTNode(int tag, const phsc::location& loc): _tag(tag), _loc(loc) {}
  virtual ~ASTNode() {}
  int getTag() const { return _tag; }
  const phsc::location& getLocation() const { return _loc; }
  virtual void accept(Visitor& v) = 0;
  
private:
  int _tag;
  phsc::location _loc;
  
public:
  static const int AST_ROOT = 1;
  static const int KEYWORD = AST_ROOT + 1;
  static const int I32_LITERAL = KEYWORD + 1;
  static const int F64_LITERAL = I32_LITERAL + 1;
  static const int STR_LITERAL = F64_LITERAL + 1;
  static const int NULL_LITERAL = STR_LITERAL + 1;
  static const int TYPE_BASIC = NULL_LITERAL + 1;
  static const int TYPE_STRUCT = TYPE_BASIC + 1;
  static const int TYPE_ARRAY = TYPE_STRUCT + 1;
  static const int VAR_DEF = TYPE_ARRAY + 1;
  static const int STRUCT_DEF = VAR_DEF + 1;
  static const int FUNC_DEF = STRUCT_DEF + 1;
  static const int BLOCK = STRUCT_DEF + 1;
  static const int EMPTY_STMT = BLOCK + 1;
  static const int BREAK = EMPTY_STMT + 1;
  static const int CONTINUE = BREAK + 1;
  static const int RETURN = CONTINUE + 1;
  static const int IF = RETURN + 1;
  static const int WHILE_LOOP = IF + 1;
  static const int FOR_LOOP = WHILE_LOOP + 1;
  static const int CALL = FOR_LOOP + 1;
  static const int ASSIGNMENT = CALL + 1;
  static const int DIRECT_VAR = ASSIGNMENT + 1;
  static const int MEMBER_VAR = DIRECT_VAR + 1;
  static const int INDEXED = MEMBER_VAR + 1;
  static const int VAR_DEF_ASSIGN = INDEXED + 1;
  static const int NEW_STRUCT = VAR_DEF_ASSIGN + 1;
  static const int NEW_ARRAY = NEW_STRUCT + 1;
  static const int BINARY = NEW_ARRAY + 1;
  static const int UNARY = BINARY + 1;
}; // ASTNode

} // namespace phsc

#endif /* AST_AST_NODE_H */
