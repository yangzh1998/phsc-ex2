/**
 * @file report/overflow-warning.h
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

#ifndef REPORT_OVERFLOW_WARNING_H
#define REPORT_OVERFLOW_WARNING_H

#include <string>
#include "hamsic-report.h"

namespace phsc {

class I32OverflowWarning : public HamsicWarning {
public:
  I32OverflowWarning(const phsc::location& loc, const std::string& literal):
      HamsicWarning(loc), _literal(literal) {}
  
  virtual void printTo(std::ostream& os) const override {
    os << "[-Woverflow] exceeds range of i32: \"" << _literal << "\"";
  }
  
private:
  std::string _literal;
}; // I32OverflowWarning


class F64OverflowWarning : public HamsicWarning {
public:
  F64OverflowWarning(const phsc::location& loc, const std::string& literal):
      HamsicWarning(loc), _literal(literal) {}
  
  virtual void printTo(std::ostream& os) const override {
    os << "[-Woverflow] exceeds range of f64: \"" << _literal << "\"";
  }
  
private:
  std::string _literal;
}; // F64OverflowWarning

} // namespace phsc

#endif /* REPORT_OVERFLOW_WARNING_H */
