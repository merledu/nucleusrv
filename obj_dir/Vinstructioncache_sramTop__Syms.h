// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VINSTRUCTIONCACHE_SRAMTOP__SYMS_H_
#define VERILATED_VINSTRUCTIONCACHE_SRAMTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vinstructioncache_sramTop.h"

// INCLUDE MODULE CLASSES
#include "Vinstructioncache_sramTop___024root.h"

// SYMS CLASS (contains all model state)
class Vinstructioncache_sramTop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vinstructioncache_sramTop* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vinstructioncache_sramTop___024root TOP;

    // CONSTRUCTORS
    Vinstructioncache_sramTop__Syms(VerilatedContext* contextp, const char* namep, Vinstructioncache_sramTop* modelp);
    ~Vinstructioncache_sramTop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
