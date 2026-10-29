// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnucleusrv_soc_top.h for the primary calling header

#include "Vnucleusrv_soc_top__pch.h"
#include "Vnucleusrv_soc_top__Syms.h"
#include "Vnucleusrv_soc_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__ico(Vnucleusrv_soc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vnucleusrv_soc_top___024root___eval_triggers__ico(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnucleusrv_soc_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__act(Vnucleusrv_soc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vnucleusrv_soc_top___024root___eval_triggers__act(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->hdmi_tx_clk_p) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__hdmi_tx_clk_p__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->nucleusrv_soc_top__DOT__clk_tmds) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__nucleusrv_soc_top__DOT__clk_tmds__0))));
    vlSelf->__Vtrigprevexpr___TOP__hdmi_tx_clk_p__0 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__nucleusrv_soc_top__DOT__clk_tmds__0 
        = vlSelf->nucleusrv_soc_top__DOT__clk_tmds;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnucleusrv_soc_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
