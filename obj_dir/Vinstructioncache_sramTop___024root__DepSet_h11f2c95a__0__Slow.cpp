// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinstructioncache_sramTop.h for the primary calling header

#include "verilated.h"

#include "Vinstructioncache_sramTop___024root.h"

VL_ATTR_COLD void Vinstructioncache_sramTop___024root___eval_initial(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_i = vlSelf->rst_i;
}

VL_ATTR_COLD void Vinstructioncache_sramTop___024root___eval_settle(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___eval_settle\n"); );
}

VL_ATTR_COLD void Vinstructioncache_sramTop___024root___final(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___final\n"); );
}

VL_ATTR_COLD void Vinstructioncache_sramTop___024root___ctor_var_reset(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_i = VL_RAND_RESET_I(1);
    vlSelf->csb_i = VL_RAND_RESET_I(1);
    vlSelf->addr_i = VL_RAND_RESET_I(13);
    vlSelf->wdata_i = VL_RAND_RESET_I(32);
    vlSelf->wmask_i = VL_RAND_RESET_I(4);
    vlSelf->we_i = VL_RAND_RESET_I(1);
    vlSelf->rdata_o = VL_RAND_RESET_I(32);
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__csb0_reg = VL_RAND_RESET_I(1);
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__web0_reg = VL_RAND_RESET_I(1);
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__wmask0_reg = VL_RAND_RESET_I(4);
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg = VL_RAND_RESET_I(11);
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__din0_reg = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<2048; ++__Vi0) {
        vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
}
