/**
 * @file report/hamsic-report.h
 * @brief Report includes both warnings and errors.
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-9
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef REPORT_HAMSIC_REPORT_H
#define REPORT_HAMSIC_REPORT_H

#include <iostream>
#include <string>
#include "../parser/location.hh"
#include "../utils/console-color.h"

namespace phsc {

class HamsicReport {
public:
  explicit HamsicReport(const phsc::location& loc): _loc(loc) {}
  virtual ~HamsicReport() {}
  const phsc::location& getLocation() const { return _loc; }
  
  virtual void printTo(std::ostream&) const = 0;
  friend std::ostream& operator<<(std::ostream& os, const HamsicReport& report) {
    os << CONSOLE_BOLD << report.getLocation() << CONSOLE_BOLD_RED
       << " error: " << CONSOLE_RESET;
    report.printTo(os);
    return os;
  }
  
  bool operator<(const HamsicReport& right) const {
    const phsc::position& posLeft = getLocation().begin;
    const phsc::position& posRight = right.getLocation().begin;
    if (posLeft.filename && posRight.filename) {
      int ans = posLeft.filename->compare(*(posRight.filename));
      if (ans != 0) return ans < 0;
    }
    if (posLeft.line != posRight.line) return posLeft.line < posRight.line;
    return posLeft.column < posRight.column;
  }
  
protected:
  phsc::location _loc;
}; // HamsicReport


class HamsicWarning : public HamsicReport {
public:
  explicit HamsicWarning(const phsc::location& loc): HamsicReport(loc) {}
  
  /* I love this implementation.
   * If you want a Warning object printed like an Error, just use a Report pointer.
   * Which overloaded "<<" function is called is only determined by pointer,
   * not working as a virtual function
   */
  friend std::ostream& operator<<(std::ostream& os, const HamsicWarning& warning) {
    os << CONSOLE_BOLD << warning.getLocation() << CONSOLE_BOLD_MAGENTA
       << " warning: " << CONSOLE_RESET;
    warning.printTo(os);
    return os;
  }
}; // HamsicWarning


class HamsicError : public HamsicReport {
public:
  explicit HamsicError(const phsc::location& loc): HamsicReport(loc) {}
}; // HamsicError

} // namespace phsc

#endif /* REPORT_HAMSIC_REPORT_H */
