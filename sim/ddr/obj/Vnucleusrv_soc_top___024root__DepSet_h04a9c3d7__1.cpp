// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnucleusrv_soc_top.h for the primary calling header

#include "Vnucleusrv_soc_top__pch.h"
#include "Vnucleusrv_soc_top___024root.h"

VL_INLINE_OPT void Vnucleusrv_soc_top___024root___nba_sequent__TOP__1(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*2:0*/ __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync;
    __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync = 0;
    CData/*3:0*/ __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10;
    __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 = 0;
    CData/*0:0*/ __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced;
    __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced = 0;
    // Body
    __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync;
    __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced;
    __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10;
    __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync 
        = ((6U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync) 
                  << 1U)) | (IData)(vlSelf->hdmi_tx_clk_p));
    if (vlSelf->nucleusrv_soc_top__DOT__sys_rst) {
        __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 = 0U;
        __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red = 0U;
    } else {
        if (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced) {
            __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 
                = ((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10))));
        } else if ((1U == (3U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync) 
                                 >> 1U)))) {
            __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 = 0U;
            __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced = 1U;
        }
        if (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_load) {
            vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue 
                = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_blue;
            vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green 
                = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_green;
            vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red 
                = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_red;
        } else {
            vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue 
                = (0x1ffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue) 
                             >> 1U));
            vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green 
                = (0x1ffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green) 
                             >> 1U));
            vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red 
                = (0x1ffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red) 
                             >> 1U));
        }
    }
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced 
        = __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync 
        = __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 
        = __Vdly__nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_load 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10));
    vlSelf->hdmi_tx_p = ((4U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red) 
                                << 2U)) | ((2U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green) 
                                                  << 1U)) 
                                           | (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue))));
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_p = vlSelf->hdmi_tx_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_p 
        = vlSelf->hdmi_tx_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_p 
        = vlSelf->hdmi_tx_p;
    vlSelf->hdmi_tx_n = (7U & (~ (IData)(vlSelf->hdmi_tx_p)));
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_n = vlSelf->hdmi_tx_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_n 
        = vlSelf->hdmi_tx_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_n 
        = vlSelf->hdmi_tx_n;
}

VL_INLINE_OPT void Vnucleusrv_soc_top___024root___nba_sequent__TOP__2(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*2:0*/ __Vdly__nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt;
    __Vdly__nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt = 0;
    // Body
    __Vdly__nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt 
        = vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt;
    if ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt))) {
        vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg 
            = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg)));
        __Vdly__nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt = 0U;
    } else {
        __Vdly__nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt 
            = (7U & ((IData)(1U) + (IData)(vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt)));
    }
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt 
        = __Vdly__nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt;
    vlSelf->hdmi_tx_clk_n = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg)));
    vlSelf->hdmi_tx_clk_p = vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg;
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_clk_n = vlSelf->hdmi_tx_clk_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_clk_n 
        = vlSelf->hdmi_tx_clk_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_clk_n 
        = vlSelf->hdmi_tx_clk_n;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__clk 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__cpu_clk 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__clk_25mhz 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_clk_p = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__clk25MHz = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_clock 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_clk_p 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_clk_p 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__clk_pixel_forwarded 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__clk 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__clk 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__clk 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pixclk 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__clk;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__clk;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__clk;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__clk;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pixclk;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk;
}

VL_INLINE_OPT void Vnucleusrv_soc_top___024root___nba_sequent__TOP__3(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_blue 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__tmds_out;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_green 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__tmds_out;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_red 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__tmds_out;
    vlSelf->nucleusrv_soc_top__DOT__sys_rst = (1U & 
                                               ((IData)(vlSelf->nucleusrv_soc_top__DOT__rst_sync) 
                                                >> 1U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__cpu_rst 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__reset_n 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__sys_rst)));
    if (vlSelf->nucleusrv_soc_top__DOT__sys_rst) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_reset = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__rst = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_19 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_13 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[0U] = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[1U] = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[2U] = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_30 = 0ULL;
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rst = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rst = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rst = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pix_rst = 1U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_reset = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__rst = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_19 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_6;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_13 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[2U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_30 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_16;
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rst = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rst = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rst = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pix_rst = 0U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_4 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg)) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_1) 
              | (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__sys_rst))));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pix_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_14 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_12)
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_13));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_15 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_9)
            ? 2U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_14));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__next_state 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_4)
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_15));
}

void Vnucleusrv_soc_top___024root___nba_sequent__TOP__0(Vnucleusrv_soc_top___024root* vlSelf);

void Vnucleusrv_soc_top___024root___eval_nba(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vnucleusrv_soc_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vnucleusrv_soc_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vnucleusrv_soc_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vnucleusrv_soc_top___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void Vnucleusrv_soc_top___024root___eval_triggers__act(Vnucleusrv_soc_top___024root* vlSelf);
void Vnucleusrv_soc_top___024root___eval_act(Vnucleusrv_soc_top___024root* vlSelf);

bool Vnucleusrv_soc_top___024root___eval_phase__act(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vnucleusrv_soc_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vnucleusrv_soc_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vnucleusrv_soc_top___024root___eval_phase__nba(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vnucleusrv_soc_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__ico(Vnucleusrv_soc_top___024root* vlSelf);
#endif  // VL_DEBUG
bool Vnucleusrv_soc_top___024root___eval_phase__ico(Vnucleusrv_soc_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__nba(Vnucleusrv_soc_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__act(Vnucleusrv_soc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vnucleusrv_soc_top___024root___eval(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vnucleusrv_soc_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/nucleusrv_soc_top.v", 9, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vnucleusrv_soc_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vnucleusrv_soc_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/nucleusrv_soc_top.v", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vnucleusrv_soc_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/nucleusrv_soc_top.v", 9, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vnucleusrv_soc_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vnucleusrv_soc_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vnucleusrv_soc_top___024root___eval_debug_assertions(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->btn_rst & 0xfeU))) {
        Verilated::overWidthError("btn_rst");}
    if (VL_UNLIKELY((vlSelf->uart_rxd & 0xfeU))) {
        Verilated::overWidthError("uart_rxd");}
    if (VL_UNLIKELY((vlSelf->btn & 0xf0U))) {
        Verilated::overWidthError("btn");}
    if (VL_UNLIKELY((vlSelf->sw & 0xf8U))) {
        Verilated::overWidthError("sw");}
    if (VL_UNLIKELY((vlSelf->DDR_addr & 0x8000U))) {
        Verilated::overWidthError("DDR_addr");}
    if (VL_UNLIKELY((vlSelf->DDR_ba & 0xf8U))) {
        Verilated::overWidthError("DDR_ba");}
    if (VL_UNLIKELY((vlSelf->DDR_cas_n & 0xfeU))) {
        Verilated::overWidthError("DDR_cas_n");}
    if (VL_UNLIKELY((vlSelf->DDR_ck_n & 0xfeU))) {
        Verilated::overWidthError("DDR_ck_n");}
    if (VL_UNLIKELY((vlSelf->DDR_ck_p & 0xfeU))) {
        Verilated::overWidthError("DDR_ck_p");}
    if (VL_UNLIKELY((vlSelf->DDR_cke & 0xfeU))) {
        Verilated::overWidthError("DDR_cke");}
    if (VL_UNLIKELY((vlSelf->DDR_cs_n & 0xfeU))) {
        Verilated::overWidthError("DDR_cs_n");}
    if (VL_UNLIKELY((vlSelf->DDR_dm & 0xf0U))) {
        Verilated::overWidthError("DDR_dm");}
    if (VL_UNLIKELY((vlSelf->DDR_dqs_n & 0xf0U))) {
        Verilated::overWidthError("DDR_dqs_n");}
    if (VL_UNLIKELY((vlSelf->DDR_dqs_p & 0xf0U))) {
        Verilated::overWidthError("DDR_dqs_p");}
    if (VL_UNLIKELY((vlSelf->DDR_odt & 0xfeU))) {
        Verilated::overWidthError("DDR_odt");}
    if (VL_UNLIKELY((vlSelf->DDR_ras_n & 0xfeU))) {
        Verilated::overWidthError("DDR_ras_n");}
    if (VL_UNLIKELY((vlSelf->DDR_reset_n & 0xfeU))) {
        Verilated::overWidthError("DDR_reset_n");}
    if (VL_UNLIKELY((vlSelf->DDR_we_n & 0xfeU))) {
        Verilated::overWidthError("DDR_we_n");}
    if (VL_UNLIKELY((vlSelf->FIXED_IO_ddr_vrn & 0xfeU))) {
        Verilated::overWidthError("FIXED_IO_ddr_vrn");}
    if (VL_UNLIKELY((vlSelf->FIXED_IO_ddr_vrp & 0xfeU))) {
        Verilated::overWidthError("FIXED_IO_ddr_vrp");}
    if (VL_UNLIKELY((vlSelf->FIXED_IO_mio & 0ULL))) {
        Verilated::overWidthError("FIXED_IO_mio");}
    if (VL_UNLIKELY((vlSelf->FIXED_IO_ps_clk & 0xfeU))) {
        Verilated::overWidthError("FIXED_IO_ps_clk");}
    if (VL_UNLIKELY((vlSelf->FIXED_IO_ps_porb & 0xfeU))) {
        Verilated::overWidthError("FIXED_IO_ps_porb");}
    if (VL_UNLIKELY((vlSelf->FIXED_IO_ps_srstb & 0xfeU))) {
        Verilated::overWidthError("FIXED_IO_ps_srstb");}
}
#endif  // VL_DEBUG
