/**
 * @file utils/indent-print-writer.h
 * @brief Add indent control to an ostream.
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-24
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef UTILS_INDENT_PRINT_WRITER_H
#define UTILS_INDENT_PRINT_WRITER_H

#include <iostream>
#include <string>

namespace phsc {

class IndentPrintWriter {
public:
  explicit IndentPrintWriter(std::ostream& os = std::cout): _level(0),
      _newLine(true), _ostream(os) {}
  void incIndent() { _level ++; }
  void decIndent() { if (_level > 0) _level --; }
  
  void println(const std::string& str) {
    if (_newLine) __printIndent();
    _ostream << str << std::endl;
    _newLine = true;
  }
  
  void println() {
    if (_newLine) __printIndent();
    _ostream << std::endl;
    _newLine = true;
  }
  
  void print(const std::string& str) {
    if (_newLine) __printIndent();
    _ostream << str;
    _newLine = false;
  }
  
private:
  int _level;
  bool _newLine;
  std::ostream& _ostream;
  
  void __printIndent() {
    for (int i = 0; i < _level; i ++) {
      _ostream << "    ";
    }
  }
}; // IndentPrintWriter

} // namespace phsc

#endif /* UTILS_INDENT_PRINT_WRITER_H */
