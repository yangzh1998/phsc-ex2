/**
 * @file driver/option.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-30
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef DRIVER_OPTION_H
#define DRIVER_OPTION_H

#include <iostream> // ios::in ios::out cerr
#include <fstream> // ifstream ofstream
#include <cstring> // strncmp
#include <cstdio> // exit
#include <string>

#include "../utils/console-color.h"

#ifndef ARG_MAX_LENGTH
#define ARG_MAX_LENGTH 256
#endif

namespace phsc {

class Option {
public:
  enum class Goal {
#ifndef PHSC_LITE
    AST,
    SYM_TBL,
#endif
    LLVM_IR,
    LLVM_BC,
    OPT_IR,
    OPT_BC,
    ASM,
    OBJ,
    EXE
  };
  
public:
  std::ifstream m_ifs;
  std::ofstream m_ofs;
  unsigned m_optLevel = 0;
  unsigned m_sizeLevel = 0;
  Goal m_goal;
  
  bool m_warning_as_error = false;
  bool m_overflow_warning = true;
  
public:
  Option(): m_goal(Goal::EXE), _emit_llvm(false) {}
  
  int parseArg(int argc, const char** argv) {
    bool hasInput = false;
    bool hasOutput = false;
    for (int index = 1; index < argc; index ++) {
      // output file
      if (strncmp(argv[index], "-o", ARG_MAX_LENGTH) == 0) {
        m_ofs.open(argv[++index], std::ios::out);
        if (m_ofs.fail()) {
          _printErr(std::string("fail to create output file: no such dir ") +
                    std::string("or duplicated output files"));
          return -1;
        }
        hasOutput = true;
        continue;
      }
      // optimization options
      if (strncmp(argv[index], "-O0", ARG_MAX_LENGTH) == 0) {
        m_optLevel = 0;
        m_sizeLevel = 0;
        continue;
      }
      if (strncmp(argv[index], "-O", ARG_MAX_LENGTH) == 0) {
        m_optLevel = 1;
        m_sizeLevel = 0;
        continue;
      }
      if (strncmp(argv[index], "-O1", ARG_MAX_LENGTH) == 0) {
        m_optLevel = 1;
        m_sizeLevel = 0;
        continue;
      }
      if (strncmp(argv[index], "-O2", ARG_MAX_LENGTH) == 0) {
        m_optLevel = 2;
        m_sizeLevel = 0;
        continue;
      }
      if (strncmp(argv[index], "-O3", ARG_MAX_LENGTH) == 0) {
        m_optLevel = 3;
        m_sizeLevel = 0;
        continue;
      }
      if (strncmp(argv[index], "-Os", ARG_MAX_LENGTH) == 0) {
        m_optLevel = 2;
        m_sizeLevel = 1;
        continue;
      }
      if (strncmp(argv[index], "-Oz", ARG_MAX_LENGTH) == 0) {
        m_optLevel = 2;
        m_sizeLevel = 2;
        continue;
      }
      // To which step
#ifndef PHSC_LITE
      if (strncmp(argv[index], "-build-syntax-tree", ARG_MAX_LENGTH) == 0) {
        m_goal = Goal::AST;
        continue;
      }
      if (strncmp(argv[index], "-build-symbol-table", ARG_MAX_LENGTH) == 0) {
        m_goal = Goal::SYM_TBL;
        continue;
      }
#endif
      if (strncmp(argv[index], "-emit-llvm", ARG_MAX_LENGTH) == 0) {
        _emit_llvm = true;
        continue;
      }
      if (strncmp(argv[index], "-??", ARG_MAX_LENGTH) == 0) { // TODO: ??
        m_goal = Goal::OPT_IR;
        continue;
      }
      if (strncmp(argv[index], "-???", ARG_MAX_LENGTH) == 0) { // TODO: ???
        m_goal = Goal::OPT_BC;
        continue;
      }
      if (strncmp(argv[index], "-S", ARG_MAX_LENGTH) == 0) {
        m_goal = _emit_llvm ? Goal::LLVM_IR : Goal::ASM;
        continue;
      }
      if (strncmp(argv[index], "-c", ARG_MAX_LENGTH) == 0) {
        m_goal = _emit_llvm ? Goal::LLVM_BC : Goal::OBJ;
        continue;
      }
      if (strncmp(argv[index], "-h", ARG_MAX_LENGTH) == 0) {
        _printHelp();
        continue;
      }
      if (strncmp(argv[index], "--help", ARG_MAX_LENGTH) == 0) {
        _printHelp();
        continue;
      }
      if (strncmp(argv[index], "-v", ARG_MAX_LENGTH) == 0) {
        _printVersion();
        continue;
      }
      if (strncmp(argv[index], "--version", ARG_MAX_LENGTH) == 0) {
        _printVersion();
        continue;
      }
      // warning options
      if (strncmp(argv[index], "-Werror", ARG_MAX_LENGTH) == 0) {
        m_warning_as_error = true;
        continue;
      }
      if (strncmp(argv[index], "-Wall", ARG_MAX_LENGTH) == 0) {
        m_overflow_warning = true;
        // TODO: more
        continue;
      }
      if (strncmp(argv[index], "-Woverflow", ARG_MAX_LENGTH) == 0) {
        m_overflow_warning = true;
        continue;
      }
      if (strncmp(argv[index], "-Wno-overflow", ARG_MAX_LENGTH) == 0) {
        m_overflow_warning = false;
        continue;
      }
      // TODO: more options of warning and optimizing
      // other options
      // input file
      m_ifs.open(argv[index], std::ios::in);
      if (m_ifs.fail())  {
        _printErr(std::string("fail to open input file: no such file ") +
                  std::string("or duplicated input files"));
        return -1;
      }
      hasInput = true;
    } // for
    
    if (!hasInput) {
      _printErr("no input file");
      return -1;
    }
    if (!hasOutput) {
      _printErr("no output file");
      return -1;
    }
    return 0;
  }
  
private:
  bool _emit_llvm;
  
  void _printErr(const std::string& msg) {
    std::cerr << "phsc: " << CONSOLE_BOLD_RED << "error: "
              << CONSOLE_RESET << msg << std::endl;
    std::cerr << "Use -h or --help to see the usage." << std::endl;
  }
  
  void _printVersion() {
    std::cout << "phsc version 0.0.1" << std::endl;
    exit(0);
  }
  
  void _printHelp() {
    // TODO: print help
    exit(0);
  }

}; // Option

} // namespace phsc

#endif /* DRIVER_OPTION_H */
