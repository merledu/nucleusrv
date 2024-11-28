// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vinstructioncache_sramTop__Syms.h"
#include "Vinstructioncache_sramTop.h"
#include "Vinstructioncache_sramTop___024root.h"

// FUNCTIONS
Vinstructioncache_sramTop__Syms::~Vinstructioncache_sramTop__Syms()
{
}

Vinstructioncache_sramTop__Syms::Vinstructioncache_sramTop__Syms(VerilatedContext* contextp, const char* namep, Vinstructioncache_sramTop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
