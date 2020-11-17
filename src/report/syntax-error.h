/**
 * @file report/syntax-error.h
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

#ifndef REPORT_SYNTAX_ERROR_H
#define REPORT_SYNTAX_ERROR_H

#include <string>
#include "hamsic-report.h"

namespace phsc {

class SyntaxError : public HamsicError {
public:
  SyntaxError(const phsc::location& loc, const std::string& msg):
      HamsicError(loc), _msg(msg) {}
  virtual void printTo(std::ostream& os) const override {
    os << _msg;
  }
private:
  std::string _msg;
}; // SyntaxError

} // namespace phsc

#endif /* REPORT_SYNTAX_ERROR_H */
