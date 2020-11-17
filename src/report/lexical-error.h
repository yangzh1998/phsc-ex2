/**
 * @file report/lexical-error.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-11
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef REPORT_LEXICAL_ERROR_H
#define REPORT_LEXICAL_ERROR_H

#include <string>
#include "hamsic-report.h"

namespace phsc {

class NewlineInStrError : public HamsicError {
public:
  NewlineInStrError(const phsc::location& loc, const std::string& str):
      HamsicError(loc), _str(str) {}
  virtual void printTo(std::ostream& os) const override {
    os << "illegal newline in string constant \"" << _str << "\"";
  }
private:
  std::string _str;
}; // NewlineInStrError

class UnrecognizedCharError : public HamsicError {
public:
  UnrecognizedCharError(const phsc::location& loc, char c):
      HamsicError(loc), _unrecognizedChar(c) {}
  virtual void printTo(std::ostream& os) const override {
    os << "unrecognized character '" << _unrecognizedChar << "'";
  }
private:
  char _unrecognizedChar;
}; // UnrecognizedCharError

class UnterminatedStrError : public HamsicError {
public:
  UnterminatedStrError(const phsc::location& loc, const std::string& str):
      HamsicError(loc), _str(str) {}
  virtual void printTo(std::ostream& os) const override {
    os << "unterminated string constant \"" << _str << "\"";
  }
private:
  std::string _str;
}; // UnterminatedStrError

} // namespace phsc

#endif /* REPORT_LEXICAL_ERROR_H */
