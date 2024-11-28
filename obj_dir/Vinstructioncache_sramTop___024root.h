// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vinstructioncache_sramTop.h for the primary calling header

#ifndef VERILATED_VINSTRUCTIONCACHE_SRAMTOP___024ROOT_H_
#define VERILATED_VINSTRUCTIONCACHE_SRAMTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vinstructioncache_sramTop__Syms;

class Vinstructioncache_sramTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_i,0,0);
    VL_IN8(csb_i,0,0);
    VL_IN8(wmask_i,3,0);
    VL_IN8(we_i,0,0);
    CData/*0:0*/ instructioncache_sramTop__DOT__memory__DOT__csb0_reg;
    CData/*0:0*/ instructioncache_sramTop__DOT__memory__DOT__web0_reg;
    CData/*3:0*/ instructioncache_sramTop__DOT__memory__DOT__wmask0_reg;
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    CData/*0:0*/ __Vclklast__TOP__rst_i;
    VL_IN16(addr_i,12,0);
    SData/*10:0*/ instructioncache_sramTop__DOT__memory__DOT__addr0_reg;
    VL_IN(wdata_i,31,0);
    VL_OUT(rdata_o,31,0);
    IData/*31:0*/ instructioncache_sramTop__DOT__memory__DOT__din0_reg;
    VlUnpacked<IData/*31:0*/, 2048> instructioncache_sramTop__DOT__memory__DOT__mem;

    // INTERNAL VARIABLES
    Vinstructioncache_sramTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vinstructioncache_sramTop___024root(Vinstructioncache_sramTop__Syms* symsp, const char* name);
    ~Vinstructioncache_sramTop___024root();
    VL_UNCOPYABLE(Vinstructioncache_sramTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
