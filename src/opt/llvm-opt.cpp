/**
 * @file opt/llvm-opt.cpp
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

#include "llvm-opt.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/InitializePasses.h"
#include "llvm/PassRegistry.h"
#include "llvm/Support/ManagedStatic.h" // llvm_shutdown
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

/// In addition to setting up the basic passes, PassManagerBuilder allows
/// frontends to vend a plugin API, where plugins are allowed to add extensions
/// to the default pass manager.  They do this by specifying where in the pass
/// pipeline they want to be added, along with a callback function that adds
/// the pass(es).  For example, a plugin that wanted to add a loop optimization
/// could do something like this:
///
/// static void addMyLoopPass(const PMBuilder &Builder, PassManagerBase &PM) {
///   if (Builder.getOptLevel() > 2 && Builder.getOptSizeLevel() == 0)
///     PM.add(createMyAwesomePass());
/// }
///   ...
///   Builder.addExtension(PassManagerBuilder::EP_LoopOptimizerEnd,
///                        addMyLoopPass);
///   ...

phsc::LLVMOpt::LLVMOpt(): _registry(*llvm::PassRegistry::getPassRegistry()) {
  llvm::InitializeAllTargets();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmPrinters();
  llvm::InitializeAllAsmParsers();
  
  // Initialize passes in different kinds
  llvm::initializeCore(_registry);
  llvm::initializeCoroutines(_registry);
  llvm::initializeScalarOpts(_registry);
  llvm::initializeObjCARCOpts(_registry);
  llvm::initializeVectorization(_registry);
  llvm::initializeIPO(_registry);
  llvm::initializeAnalysis(_registry);
  llvm::initializeTransformUtils(_registry);
  llvm::initializeInstCombine(_registry);
  llvm::initializeAggressiveInstCombine(_registry);
  llvm::initializeInstrumentation(_registry);
  llvm::initializeTarget(_registry);
  //llvm::initializeGlobalISel(_registry);
  //llvm::initializeCodeGen(_registry); // all CodeGen passes? no
  
  // For codegen passes, only those which do IR-IR transformation are supported.
  llvm::initializeExpandMemCmpPassPass(_registry);
  llvm::initializeScalarizeMaskedMemIntrinPass(_registry);
  llvm::initializeCodeGenPreparePass(_registry);
  llvm::initializeAtomicExpandPass(_registry);
  llvm::initializeRewriteSymbolsLegacyPassPass(_registry);
  llvm::initializeWinEHPreparePass(_registry);
  llvm::initializeDwarfEHPreparePass(_registry);
  llvm::initializeSafeStackLegacyPassPass(_registry);
  llvm::initializeSjLjEHPreparePass(_registry);
  llvm::initializePreISelIntrinsicLoweringLegacyPassPass(_registry);
  llvm::initializeGlobalMergePass(_registry);
  llvm::initializeIndirectBrExpandPassPass(_registry);
  llvm::initializeInterleavedLoadCombinePass(_registry);
  llvm::initializeInterleavedAccessPass(_registry);
  llvm::initializeEntryExitInstrumenterPass(_registry);
  llvm::initializePostInlineEntryExitInstrumenterPass(_registry);
  llvm::initializeUnreachableBlockElimLegacyPassPass(_registry);
  llvm::initializeExpandReductionsPass(_registry);
  llvm::initializeWasmEHPreparePass(_registry);
  llvm::initializeWriteBitcodePassPass(_registry);
  llvm::initializeHardwareLoopsPass(_registry);
  llvm::initializeTypePromotionPass(_registry);
  
  //llvm::initializeMyPass(_registry);
}

phsc::LLVMOpt::~LLVMOpt() {
  llvm::llvm_shutdown();
}

int phsc::LLVMOpt::opt(llvm::Module& module, unsigned optLevel,
                       unsigned sizeLevel) {
  llvm::PassManagerBuilder builder;
  builder.OptLevel = optLevel;
  builder.SizeLevel = sizeLevel;
  
  llvm::legacy::PassManager modulePM;
  llvm::legacy::FunctionPassManager funcPM(&module);
  
  builder.populateFunctionPassManager(funcPM);
  builder.populateModulePassManager(modulePM);
  
  funcPM.doInitialization();
  for (llvm::Function& func : module)
    funcPM.run(func);
  funcPM.doFinalization();
  modulePM.run(module);

  return 0;
}
