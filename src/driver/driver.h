/**
 * @file driver/driver.h
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

#ifndef DRIVER_DRIVER_H
#define DRIVER_DRIVER_H

#include <vector>
#include <memory> // unique_ptr
#include <cstdlib> // exit
#include <algorithm> // sort
#include "option.h"
#include "../report/hamsic-report.h"
#include "../parser/hamsic-lexer.h"
#include "../parser/parser.hpp"
#include "../visitor/build-sym.h"
#include "../visitor/type-check.h"
//#include "../opt/llvm-opt.h"

#ifndef PHSC_LITE
#include "../utils/indent-print-writer.h"
#include "../visitor/print-ast.h"
#endif

namespace phsc {

class Driver {
public:
  Driver() {}
  ~Driver() {}
  
  void run(int argc, const char** argv) {
    if (_option.parseArg(argc, argv) != 0) return;
    _lexer.reset(new phsc::HamsicLexer(_errors, _warnings, _option,
                                       &(_option.m_ifs)));
    _parser.reset(new phsc::HamsicParser(*_lexer, _tree, _errors));
    
    int ret = _parser->parse(); // _tree constructed here
    _parser.reset();
    _lexer.reset();
    _checkErrors();
    if (ret != 0) return;
#ifndef PHSC_LITE
    if (_option.m_goal == Option::Goal::AST) {
      phsc::PrintAST printer(_option.m_ofs);
      printer.visitASTRoot(*_tree);
      _printWarnings();
      return;
    }
#endif
    
    _buildSym.reset(new phsc::BuildSym());
    _buildSym->visitASTRoot(*_tree);
    _buildSym.reset();
    _checkErrors();
    _typeCheck.reset(new phsc::TypeCheck());
    _typeCheck->visitASTRoot(*_tree);
    _typeCheck.reset();
    _checkErrors();
#ifndef PHSC_LITE
    if (_option.m_goal == Option::Goal::SYM_TBL) {
      phsc::IndentPrintWriter ipw(_option.m_ofs);
      _tree->getGlobalStructScope()->printTo(ipw);
      _tree->getGlobalFuncScope()->printTo(ipw);
      _printWarnings();
      return;
    }
#endif
    
    _tree.reset();
    
    if (_option.m_optLevel || _option.m_sizeLevel) {
      //_llvmOpt.opt(module, _option.m_optLevel, _option.m_sizeLevel);
    }
    
    _printWarnings();
  }
  

  
private:
  Option _option;
  
  // Use Report instead of Error
  // because if -Werror is on, warnings should be treated as errors.
  std::vector<std::unique_ptr<phsc::HamsicReport>> _errors;
  std::vector<std::unique_ptr<phsc::HamsicWarning>> _warnings;
  
  std::unique_ptr<phsc::ASTRoot> _tree;
  std::unique_ptr<phsc::HamsicLexer> _lexer;
  std::unique_ptr<phsc::HamsicParser> _parser;
  
  std::unique_ptr<phsc::BuildSym> _buildSym;
  std::unique_ptr<phsc::TypeCheck> _typeCheck;
  
  phsc::LLVMOpt _llvmOpt;
  
private:
  void _checkErrors() {
    if (_errors.size() > 0) {
      std::sort(_errors.begin(), _errors.end(),
                [] (std::unique_ptr<phsc::HamsicReport>& errA,
                    std::unique_ptr<phsc::HamsicReport>& errB) -> bool {
        return *(errA.get()) < *(errB.get());
      });
      for (std::unique_ptr<phsc::HamsicReport>& error : _errors) {
        std::cerr << *error << std::endl;
      }
      _printWarnings();
      std::cerr << _errors.size() << " errors occurred." << std::endl;
      exit(0);
    }
  }
  
  void _printWarnings() {
    if (_warnings.size() > 0) {
      std::sort(_warnings.begin(), _warnings.end(),
                [] (std::unique_ptr<phsc::HamsicWarning>& warningA,
                    std::unique_ptr<phsc::HamsicWarning>& warningB) -> bool {
        return *(warningA.get()) < *(warningB.get());
      });
      for (std::unique_ptr<phsc::HamsicWarning>& warning : _warnings) {
        std::cerr << *warning << std::endl;
      }
      std::cerr << _warnings.size() << " warnings occurred." << std::endl;
    }
  }
  
}; // Driver

} // namespace phsc

#endif /* DRIVER_DRIVER_H */
