/**
 * @file visitor/build-sym.cpp
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

#include <memory>
#include "build-sym.h"
#include "../ast/includes.h"
#include "../symbol/scope.h"
#include "../symbol/symbol.h"
#include "../symbol/struct-symbol.h"
#include "../symbol/func-symbol.h"
#include "../symbol/var-symbol.h"

void phsc::BuildSym::visitASTRoot(phsc::ASTRoot& root) {
  // collect struct name information
  for (std::unique_ptr<phsc::ASTNode>& def : root.getDefinitions()) {
    if (def->getTag() == ASTNode::STRUCT_DEF) {
      phsc::StructDef& sdef = static_cast<phsc::StructDef&>(*def);
      if (root.getGlobalStructScope()->contains(sdef.getName())) {
        // TODO: error
      } else {
        std::shared_ptr<phsc::StructSymbol> ssym =
        std::make_shared<phsc::StructSymbol>(sdef.getName(), sdef.getLocation());
        ssym->setAssociatedScope(std::make_shared<phsc::StructScope>(ssym));
        ssym->setScope(root.getGlobalStructScope());
        ssym->getScope()->declare(ssym);
        sdef.setSymbol(ssym);
        //ssym->setType(std::make_shared<phsc::ClassType>()); // TODO: ...
      }
    }
  }
  
  // I divide struct name collection and struct member collection into
  // two loops in order to let the member in former struct be able to
  // use the struct type defined latter.
  for (std::unique_ptr<phsc::ASTNode>& def : root.getDefinitions()) {
    if (def->getTag() == ASTNode::STRUCT_DEF) {
      def->accept(*this); // To collect member variables in the struct
    }
  }
  
  // collect function information
  for (std::unique_ptr<phsc::ASTNode>& def : root.getDefinitions()) {
    if (def->getTag() == ASTNode::FUNC_DEF) {
      phsc::FuncDef& fdef = static_cast<phsc::FuncDef&>(*def);
      if (root.getGlobalStructScope()->contains(fdef.getHashString())) {
        // TODO: error
      } else {
        std::shared_ptr<phsc::FuncSymbol> fsym =
        std::make_shared<phsc::FuncSymbol>(fdef.getHashString(),
                                           fdef.getLocation());
        fsym->setAssociatedScope(
          std::make_shared<phsc::FormalScope>(fsym, fdef.getBody())
        );
        fsym->setScope(root.getGlobalFuncScope());
        fsym->getScope()->declare(fsym);
        fdef.setSymbol(fsym);
        //fsym->setType(...) // TODO: ...
        def->accept(*this);
      }
    }
  }
}

void phsc::BuildSym::visitKeyword(phsc::Keyword&) {
  
}

void phsc::BuildSym::visitI32Literal(phsc::I32Literal&) {
  
}

void phsc::BuildSym::visitF64Literal(phsc::F64Literal&) {
  
}

void phsc::BuildSym::visitStrLiteral(phsc::StrLiteral&) {
  
}

void phsc::BuildSym::visitNullLiteral(phsc::NullLiteral&) {
  
}

void phsc::BuildSym::visitTypeBasic(phsc::TypeBasic&) {
  
}

void phsc::BuildSym::visitTypeStruct(phsc::TypeStruct&) {
  
}

void phsc::BuildSym::visitTypeArray(phsc::TypeArray&) {
  
}

void phsc::BuildSym::visitVarDef(phsc::VarDef& vdef) {
  // TODO: vdef.type.accept(this)
  //std::shared_ptr<phsc::VarSymbol> vsym =
  //std::make_shared<phsc::VarSymbol>(vdef.getName(), vdef.getLocation());
}

void phsc::BuildSym::visitStructDef(phsc::StructDef& sdef) {
  _stack.open(sdef.getSymbol()->getAssociatedScope());
  for (std::unique_ptr<phsc::VarDef>& vdef : sdef.getFields()) {
    vdef->accept(*this);
  }
  _stack.close();
}

void phsc::BuildSym::visitFuncDef(phsc::FuncDef& fdef) {
  _stack.open(fdef.getSymbol()->getAssociatedScope());
  for (std::unique_ptr<phsc::VarDef>& vdef : fdef.getFormals()) {
    vdef->accept(*this);
  }
  fdef.getBody().accept(*this);
  _stack.close();
}

void phsc::BuildSym::visitBlock(phsc::Block& block) {
  block.setAssociatedScope(std::make_shared<phsc::LocalScope>(block));
  // put the new local scope into the upper local scope's subscope list.
  const std::shared_ptr<phsc::Scope>& upperScope = _stack.getCurrentScope();
  if (upperScope->getKind() == phsc::Scope::Kind::LOCAL) {
    phsc::LocalScope& upperLS = static_cast<phsc::LocalScope&>(*upperScope);
    upperLS.append(block.getAssociatedScope());
  }
  
  _stack.open(block.getAssociatedScope());
  for (std::unique_ptr<phsc::ASTNode>& stmt : block.getStmts()) {
    stmt->accept(*this);
  }
  _stack.close();
}

void phsc::BuildSym::visitEmptyStmt(phsc::EmptyStmt&) {
  
}

void phsc::BuildSym::visitBreak(phsc::Break&) {
  
}

void phsc::BuildSym::visitContinue(phsc::Continue&) {
  
}

void phsc::BuildSym::visitReturn(phsc::Return&) {
  
}

void phsc::BuildSym::visitIf(phsc::If& ifStmt) {
  ifStmt.getTrueBranch().accept(*this);
  ifStmt.getFalseBranch().accept(*this);
}

void phsc::BuildSym::visitWhileLoop(phsc::WhileLoop& whileLoop) {
  whileLoop.getLoopBody().accept(*this);
}

void phsc::BuildSym::visitForLoop(phsc::ForLoop& forLoop) {
  forLoop.getLoopBody().accept(*this);
}

void phsc::BuildSym::visitCall(phsc::Call&) {
  
}

void phsc::BuildSym::visitAssignment(phsc::Assignment&) {
  
}

void phsc::BuildSym::visitDirectVar(phsc::DirectVar&) {
  
}

void phsc::BuildSym::visitMemberVar(phsc::MemberVar&) {
  
}

void phsc::BuildSym::visitIndexed(phsc::Indexed&) {
  
}

void phsc::BuildSym::visitVarDefAssign(phsc::VarDefAssign&) {
  // TODO: ...
}

void phsc::BuildSym::visitNewStruct(phsc::NewStruct&) {
  
}

void phsc::BuildSym::visitNewArray(phsc::NewArray&) {
  
}

void phsc::BuildSym::visitBinary(phsc::Binary&) {
  
}

void phsc::BuildSym::visitUnary(phsc::Unary&) {
  
}
