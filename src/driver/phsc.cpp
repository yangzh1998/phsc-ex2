/**
 * @file driver/phsc.cpp
 * @brief Entrance of the compiler
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-10-21
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#include "driver.h"

phsc::Driver driver;
int main(int argc, const char** argv) {
  driver.run(argc, argv);
  return 0;
}
