/**
 * @file opt/llvm-opt.h
 *
 * @author YANG Zehai
 *
 * E-mail: yangzh1998@hotmail.com
 *
 * Github: yangzh1998
 *
 * @date 2020-11-3
 * @version 0.0.1
 * @copyright Copyright © 2020 YANG Zehai. All rights reserved.
 */

#ifndef OPT_LLVM_OPT_H
#define OPT_LLVM_OPT_H

namespace llvm {
class Module;
class PassRegistry;
} // namespace llvm

namespace phsc {

class LLVMOpt {
public:
  LLVMOpt();
  ~LLVMOpt();
  int opt(llvm::Module& module, unsigned optLevel, unsigned sizeLevel);
  
private:
  llvm::PassRegistry& _registry; // Destroyed by llvm_shutdown()
}; // LLVMOpt

} // namespace phsc

#endif /* OPT_LLVM_OPT_H */
