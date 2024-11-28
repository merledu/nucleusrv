// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinstructioncache_sramTop.h for the primary calling header

#include "verilated.h"

#include "Vinstructioncache_sramTop___024root.h"

VL_INLINE_OPT void Vinstructioncache_sramTop___024root___sequent__TOP__1(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__csb0_reg 
        = vlSelf->csb_i;
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__web0_reg 
        = vlSelf->we_i;
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__wmask0_reg 
        = vlSelf->wmask_i;
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg 
        = (0x7ffU & (IData)(vlSelf->addr_i));
    vlSelf->instructioncache_sramTop__DOT__memory__DOT__din0_reg 
        = vlSelf->wdata_i;
}

VL_INLINE_OPT void Vinstructioncache_sramTop___024root___sequent__TOP__2(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___sequent__TOP__2\n"); );
    // Body
    if ((1U & ((~ (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__csb0_reg)) 
               & (~ (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__web0_reg))))) {
        if ((1U & (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem[vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg] 
                = ((0xffffff00U & vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem
                    [vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg]) 
                   | (0xffU & vlSelf->instructioncache_sramTop__DOT__memory__DOT__din0_reg));
        }
        if ((2U & (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem[vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg] 
                = ((0xffff00ffU & vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem
                    [vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg]) 
                   | (0xff00U & vlSelf->instructioncache_sramTop__DOT__memory__DOT__din0_reg));
        }
        if ((4U & (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem[vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg] 
                = ((0xff00ffffU & vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem
                    [vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg]) 
                   | (0xff0000U & vlSelf->instructioncache_sramTop__DOT__memory__DOT__din0_reg));
        }
        if ((8U & (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem[vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg] 
                = ((0xffffffU & vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem
                    [vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg]) 
                   | (0xff000000U & vlSelf->instructioncache_sramTop__DOT__memory__DOT__din0_reg));
        }
    }
    if (((~ (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__csb0_reg)) 
         & (IData)(vlSelf->instructioncache_sramTop__DOT__memory__DOT__web0_reg))) {
        vlSelf->rdata_o = vlSelf->instructioncache_sramTop__DOT__memory__DOT__mem
            [vlSelf->instructioncache_sramTop__DOT__memory__DOT__addr0_reg];
    }
}

void Vinstructioncache_sramTop___024root___eval(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vinstructioncache_sramTop___024root___sequent__TOP__1(vlSelf);
    }
    if (((~ (IData)(vlSelf->clk_i)) & (IData)(vlSelf->__Vclklast__TOP__clk_i))) {
        Vinstructioncache_sramTop___024root___sequent__TOP__2(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_i = vlSelf->rst_i;
}

#ifdef VL_DEBUG
void Vinstructioncache_sramTop___024root___eval_debug_assertions(Vinstructioncache_sramTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstructioncache_sramTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstructioncache_sramTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_i & 0xfeU))) {
        Verilated::overWidthError("rst_i");}
    if (VL_UNLIKELY((vlSelf->csb_i & 0xfeU))) {
        Verilated::overWidthError("csb_i");}
    if (VL_UNLIKELY((vlSelf->addr_i & 0xe000U))) {
        Verilated::overWidthError("addr_i");}
    if (VL_UNLIKELY((vlSelf->wmask_i & 0xf0U))) {
        Verilated::overWidthError("wmask_i");}
    if (VL_UNLIKELY((vlSelf->we_i & 0xfeU))) {
        Verilated::overWidthError("we_i");}
}
#endif  // VL_DEBUG
