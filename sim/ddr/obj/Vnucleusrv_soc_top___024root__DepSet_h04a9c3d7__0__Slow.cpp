// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnucleusrv_soc_top.h for the primary calling header

#include "Vnucleusrv_soc_top__pch.h"
#include "Vnucleusrv_soc_top___024root.h"

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_static__TOP(Vnucleusrv_soc_top___024root* vlSelf);

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_static(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_static\n"); );
    // Body
    Vnucleusrv_soc_top___024root___eval_static__TOP(vlSelf);
}

extern const VlWide<16>/*511:0*/ Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0;

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_static__TOP(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->nucleusrv_soc_top__DOT__rst_sync = 3U;
    vlSelf->nucleusrv_soc_top__DOT__boot_imem_rdata = 0U;
    vlSelf->nucleusrv_soc_top__DOT__boot_imem_rsp_val = 0U;
    vlSelf->nucleusrv_soc_top__DOT__imem_src_boot = 1U;
    vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rdata = 0U;
    vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rsp_val = 0U;
    vlSelf->nucleusrv_soc_top__DOT__hb_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__led2_stretcher = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[0U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[1U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[1U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[2U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[2U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[3U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[3U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[4U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[4U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[5U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[5U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[6U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[6U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[7U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[7U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[8U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[8U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[9U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[9U];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[0xaU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xaU];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[0xbU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xbU];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[0xcU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xcU];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[0xdU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xdU];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[0xeU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xeU];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[0xfU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xfU];
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_addr = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__resp_word = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__beat = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__len = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__read_pending = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__cycle_cnt = 0ULL;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__ms_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__ms_subcnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_byte = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_start = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_wr_ptr = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_rd_ptr = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_count = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_pop = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__bus_state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__clk_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__bit_idx = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__data_buf = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rxd_sync = 7U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__clk_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__bit_idx = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__data_buf = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bus_state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__h_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__byte_sel_d1 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d1 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_vis_d1 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_vis_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d1 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync_d1 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_data = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_r_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_g_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_b_d2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__dmem_rd_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__dmem_wr_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__imem_rd_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_st = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_addr = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_len = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_have_aw = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_st = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_addr = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_len = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[0U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[1U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[1U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[2U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[2U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[3U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[3U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[4U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[4U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[5U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[5U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[6U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[6U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[7U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[7U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[8U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[8U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[9U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[9U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[0xaU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xaU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[0xbU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xbU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[0xcU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xcU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[0xdU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xdU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[0xeU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xeU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[0xfU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xfU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[0U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[1U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[1U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[2U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[2U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[3U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[3U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[4U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[4U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[5U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[5U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[6U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[6U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[7U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[7U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[8U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[8U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[9U] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[9U];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[0xaU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xaU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[0xbU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xbU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[0xcU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xcU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[0xdU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xdU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[0xeU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xeU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty[0xfU] 
        = Vnucleusrv_soc_top__ConstPool__CONST_h93e1b771_0[0xfU];
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_addr = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wdata = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wmask = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_write = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__resp_word = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__victim_tag = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wb_cnt = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__state = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__beat = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__len = 0U;
}

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_initial__TOP(Vnucleusrv_soc_top___024root* vlSelf);

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_initial(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_initial\n"); );
    // Body
    Vnucleusrv_soc_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__hdmi_tx_clk_p__0 
        = vlSelf->hdmi_tx_clk_p;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__nucleusrv_soc_top__DOT__clk_tmds__0 
        = vlSelf->nucleusrv_soc_top__DOT__clk_tmds;
}

extern const VlWide<10>/*319:0*/ Vnucleusrv_soc_top__ConstPool__CONST_h1e5af339_0;

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_initial__TOP(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = 4U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = 5U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = 6U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = 7U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = 8U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = 4U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = 5U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = 6U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = 7U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = 8U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = 4U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = 5U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = 6U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = 7U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = 8U;
    vlSelf->nucleusrv_soc_top__DOT__boot_ram[0U] = 0x100002b7U;
    vlSelf->nucleusrv_soc_top__DOT__boot_ram[1U] = 0x280e7U;
    vlSelf->nucleusrv_soc_top__DOT__i = 2U;
    while (VL_GTS_III(32, 0x1000U, vlSelf->nucleusrv_soc_top__DOT__i)) {
        vlSelf->nucleusrv_soc_top__DOT__boot_ram[(0xfffU 
                                                  & vlSelf->nucleusrv_soc_top__DOT__i)] = 0x13U;
        vlSelf->nucleusrv_soc_top__DOT__i = ((IData)(1U) 
                                             + vlSelf->nucleusrv_soc_top__DOT__i);
    }
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(10, Vnucleusrv_soc_top__ConstPool__CONST_h1e5af339_0)
                 ,  &(vlSelf->nucleusrv_soc_top__DOT__boot_ram)
                 , 0, ~0ULL);
    vlSelf->nucleusrv_soc_top__DOT__s0_req_ready = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_ready = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_dataRequest = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_activeByteLane = 0xfU;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_isWrite = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MISA_i_value = 0x40001104U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MHARTID_i_value = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MARCHID_i_value = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_0 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_1 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_2 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_3 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_4 = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awsize = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awburst = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awcache = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awprot = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arsize = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arburst = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arcache = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arprot = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_init_i = 0U;
    while (VL_GTS_III(32, 0x4000U, vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_init_i)) {
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_mem[(0x3fffU 
                                                              & vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_init_i)] = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_init_i 
            = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_init_i);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init)) {
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[(0xffU 
                                                                   & vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init)] 
            = ((0xff0000U & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init 
                             << 0x10U)) | ((0xff00U 
                                            & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init 
                                               << 8U)) 
                                           | (0xffU 
                                              & vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init)));
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init 
            = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[0U] = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[1U] = 0xff0000U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[2U] = 0xff00U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[3U] = 0xffU;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[4U] = 0xffff00U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[5U] = 0xffffU;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[6U] = 0xff00ffU;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[7U] = 0xffffffU;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bresp = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rresp = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rresp = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awready = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wready = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bresp = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bvalid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awsize = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awburst = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awcache = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awprot = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arsize = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arburst = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arcache = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arprot = 0U;
    vlSelf->nucleusrv_soc_top__DOT__pll_locked = 1U;
    vlSelf->DDR_addr = 0U;
    vlSelf->DDR_ba = 0U;
    vlSelf->DDR_cas_n = 0U;
    vlSelf->DDR_ck_n = 0U;
    vlSelf->DDR_ck_p = 0U;
    vlSelf->DDR_cke = 0U;
    vlSelf->DDR_cs_n = 0U;
    vlSelf->DDR_dm = 0U;
    vlSelf->DDR_dq = 0U;
    vlSelf->DDR_dqs_n = 0U;
    vlSelf->DDR_dqs_p = 0U;
    vlSelf->DDR_odt = 0U;
    vlSelf->DDR_ras_n = 0U;
    vlSelf->DDR_reset_n = 0U;
    vlSelf->DDR_we_n = 0U;
    vlSelf->FIXED_IO_ddr_vrn = 0U;
    vlSelf->FIXED_IO_ddr_vrp = 0U;
    vlSelf->FIXED_IO_mio = 0ULL;
    vlSelf->FIXED_IO_ps_clk = 0U;
    vlSelf->FIXED_IO_ps_porb = 0U;
    vlSelf->FIXED_IO_ps_srstb = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__rst = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_stall = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_write = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_len = 7U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__wr_data = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__wr_strb = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awready = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wdata = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wstrb = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wready = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_bresp = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_bvalid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__control_data = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__TMDS_code = 0x354U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__control_data = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__TMDS_code = 0x354U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awlock = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awqos = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arlock = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arqos = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awaddr = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awlen = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awsize = 2U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awburst = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awlock = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awcache = 3U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awprot = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awqos = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awvalid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wdata = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wstrb = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wlast = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wvalid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bready = 1U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arlock = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arqos = 0U;
}

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_final(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__stl(Vnucleusrv_soc_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vnucleusrv_soc_top___024root___eval_phase__stl(Vnucleusrv_soc_top___024root* vlSelf);

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_settle(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vnucleusrv_soc_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/nucleusrv_soc_top.v", 9, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vnucleusrv_soc_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__stl(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___stl_sequent__TOP__0(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT____VdfgTmp_h1a4a4b1b__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT____VdfgTmp_h1a4a4b1b__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT____VdfgTmp_h57bd0bc5__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT____VdfgTmp_h57bd0bc5__0 = 0;
    CData/*4:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h63fb53c5__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h63fb53c5__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT____VdfgTmp_h46ae23c6__0;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT____VdfgTmp_h46ae23c6__0 = 0;
    CData/*4:0*/ nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT____VdfgTmp_hd104829c__0;
    nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT____VdfgTmp_hd104829c__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_he71e7d91__0;
    nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_he71e7d91__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_h93af1d9c__0;
    nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_h93af1d9c__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_hb36ceaa9__0;
    nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_hb36ceaa9__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h29370b46__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h29370b46__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h283210de__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h283210de__0 = 0;
    CData/*7:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcfc558ec__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcfc558ec__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb01d673c__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb01d673c__0 = 0;
    CData/*7:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he97e1a07__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he97e1a07__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb00d4ce4__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb00d4ce4__0 = 0;
    CData/*7:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hd012719c__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hd012719c__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb3680d89__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb3680d89__0 = 0;
    SData/*15:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcec61ad5__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcec61ad5__0 = 0;
    SData/*15:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he87f56f4__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he87f56f4__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h787a05cb__0;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h787a05cb__0 = 0;
    CData/*1:0*/ nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT____VdfgTmp_h738a7907__0;
    nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT____VdfgTmp_h738a7907__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h768ca2b9__0;
    nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h768ca2b9__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h5138ab69__0;
    nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h5138ab69__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_hde455ca6__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_hde455ca6__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_h329f2e42__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_h329f2e42__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_hde455ca6__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_hde455ca6__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_h329f2e42__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_h329f2e42__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_hde455ca6__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_hde455ca6__0 = 0;
    CData/*0:0*/ nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_h329f2e42__0;
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_h329f2e42__0 = 0;
    CData/*2:0*/ __VdfgTmp_hae267436__0;
    __VdfgTmp_hae267436__0 = 0;
    CData/*7:0*/ __VdfgTmp_hea002d6a__0;
    __VdfgTmp_hea002d6a__0 = 0;
    SData/*8:0*/ __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__Vfuncout;
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__a;
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__a = 0;
    CData/*2:0*/ __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__Vfuncout;
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__a;
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__a = 0;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_12;
    // Body
    vlSelf->nucleusrv_soc_top__DOT__btn_rst = vlSelf->btn_rst;
    vlSelf->nucleusrv_soc_top__DOT__sw = vlSelf->sw;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MISA_i_value 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MISA_i_value;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MHARTID_i_value 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MHARTID_i_value;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MARCHID_i_value 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MARCHID_i_value;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_4 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_4;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_valid 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_addr 
        = (((IData)(1U) << 0x1cU) | (((0x7fffffU & 
                                       (vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_addr 
                                        >> 5U)) << 5U) 
                                     | 0U));
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s0_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__sw_in 
        = vlSelf->sw;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__tx_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_byte;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__tx_valid 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_start;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hsync 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d2;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__vsync 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync_d2;
    vlSelf->nucleusrv_soc_top__DOT__bram_word_addr 
        = (0xfffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result 
                     >> 2U));
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__locked 
        = vlSelf->nucleusrv_soc_top__DOT__pll_locked;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FRM_WIRE 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MCYCLEH_REG_T_1 
        = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLEH_REG);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIMEH_REG_T_1 
        = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIMEH_REG);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MINSTRET_REG_T_1 
        = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRET_REG);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MINSTRETH_REG_T_1 
        = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRETH_REG);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_sb 
        = ((0x800U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                      >> 0x14U)) | ((0x400U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                               << 3U)) 
                                    | ((0x3f0U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                  >> 0x15U)) 
                                       | (0xfU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                  >> 8U)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_uj 
        = ((0x80000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                        >> 0xcU)) | ((0x7f800U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                  >> 1U)) 
                                     | ((0x400U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                   >> 0xaU)) 
                                        | (0x3ffU & 
                                           (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                            >> 0x15U)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___counter_T_1 
        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__counter)));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_word 
        = (7U & (vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_addr 
                 >> 2U));
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__reg_offset 
        = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_word_addr 
        = (0x3fffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result 
                      >> 2U));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__is_pal_addr 
        = ((0x50010000U <= vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result) 
           & (0x50010400U > vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_idx_cpu 
        = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result 
                    >> 2U));
    vlSelf->nucleusrv_soc_top__DOT__imem_req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_dataRequest;
    vlSelf->nucleusrv_soc_top__DOT__imem_req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_activeByteLane;
    vlSelf->nucleusrv_soc_top__DOT__imem_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_isWrite;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__mst_done 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__done;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awaddr 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awaddr;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awlen 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awlen;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awsize 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awsize;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awburst 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awburst;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awcache 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awcache;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awprot 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awprot;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wstrb 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wstrb;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_full 
        = (0x40U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_count));
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_empty 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_count));
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rx_valid 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rx_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rx_byte 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rx_data;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_ready 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__tx_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rxd_clean 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rxd_sync) 
                 >> 2U));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync 
        = (0x60U > (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__h_cnt));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync 
        = (2U > (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_load 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_red 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__tmds_out;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_green 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__tmds_out;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_blue 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__tmds_out;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__mst_done 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__done;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__control_data 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync_d2) 
            << 1U) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d2));
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_peek 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_mem
        [vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_rd_ptr];
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__TMDS_code 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync_d2)
            ? ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d2)
                ? 0x2abU : 0x154U) : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d2)
                                       ? 0xabU : 0x354U));
    vlSelf->nucleusrv_soc_top__DOT__clk = vlSelf->clk;
    vlSelf->nucleusrv_soc_top__DOT__btn = vlSelf->btn;
    vlSelf->nucleusrv_soc_top__DOT__DDR_addr = vlSelf->DDR_addr;
    vlSelf->nucleusrv_soc_top__DOT__DDR_ba = vlSelf->DDR_ba;
    vlSelf->nucleusrv_soc_top__DOT__DDR_cas_n = vlSelf->DDR_cas_n;
    vlSelf->nucleusrv_soc_top__DOT__DDR_ck_n = vlSelf->DDR_ck_n;
    vlSelf->nucleusrv_soc_top__DOT__DDR_ck_p = vlSelf->DDR_ck_p;
    vlSelf->nucleusrv_soc_top__DOT__DDR_cke = vlSelf->DDR_cke;
    vlSelf->nucleusrv_soc_top__DOT__DDR_cs_n = vlSelf->DDR_cs_n;
    vlSelf->nucleusrv_soc_top__DOT__DDR_dm = vlSelf->DDR_dm;
    vlSelf->nucleusrv_soc_top__DOT__DDR_dq = vlSelf->DDR_dq;
    vlSelf->nucleusrv_soc_top__DOT__DDR_dqs_n = vlSelf->DDR_dqs_n;
    vlSelf->nucleusrv_soc_top__DOT__DDR_dqs_p = vlSelf->DDR_dqs_p;
    vlSelf->nucleusrv_soc_top__DOT__DDR_odt = vlSelf->DDR_odt;
    vlSelf->nucleusrv_soc_top__DOT__DDR_ras_n = vlSelf->DDR_ras_n;
    vlSelf->nucleusrv_soc_top__DOT__DDR_reset_n = vlSelf->DDR_reset_n;
    vlSelf->nucleusrv_soc_top__DOT__DDR_we_n = vlSelf->DDR_we_n;
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ddr_vrn 
        = vlSelf->FIXED_IO_ddr_vrn;
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ddr_vrp 
        = vlSelf->FIXED_IO_ddr_vrp;
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_mio = vlSelf->FIXED_IO_mio;
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_clk 
        = vlSelf->FIXED_IO_ps_clk;
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_porb 
        = vlSelf->FIXED_IO_ps_porb;
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_srstb 
        = vlSelf->FIXED_IO_ps_srstb;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_valid = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_len = 7U;
    if ((3U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
        if ((5U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
            if ((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
                vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_len = 0U;
            }
        }
    }
    vlSelf->nucleusrv_soc_top__DOT__s0_rsp_valid = vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rsp_val;
    vlSelf->nucleusrv_soc_top__DOT__s0_rsp_rdata = vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rdata;
    vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isLR 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isLR;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isSC 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isSC;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcAddress 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_pc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Ex_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_csr_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Mem_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_csr_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Wb_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_csr_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_is_comp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_is_comp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_immediate 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_imm;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_rd1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_rd2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_pcAddress 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_pc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_func7 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f7;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluSrc1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isLR 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isLR;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isSC 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isSC;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nx 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_uf 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_of 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_dz 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nv 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_frm 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_ready 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word_uh 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__stateReg;
    vlSelf->nucleusrv_soc_top__DOT__s1_req_ready = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_ready;
    vlSelf->nucleusrv_soc_top__DOT__s1_rsp_valid = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__s1_rsp_rdata = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__s2_req_ready = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_ready;
    vlSelf->nucleusrv_soc_top__DOT__s2_rsp_valid = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__s2_rsp_rdata = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cmd_ready 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_bready 
        = (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_ready 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_write = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeEnable_0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_is_csr));
    vlSelf->nucleusrv_soc_top__DOT__s0_rsp_ready = 
        ((0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target)) 
         | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_ready));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wlast 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__beat) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__len));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pixel_index 
        = (0xffU & ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__byte_sel_d1))
                     ? vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_data
                     : ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__byte_sel_d1))
                         ? (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_data 
                            >> 8U) : ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__byte_sel_d1))
                                       ? (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_data 
                                          >> 0x10U)
                                       : (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_data 
                                          >> 0x18U)))));
    vlSelf->nucleusrv_soc_top__DOT__uart_rxd = vlSelf->uart_rxd;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__is_fb_addr 
        = ((0x50000000U <= vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result) 
           & (0x50010000U > vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result));
    vlSelf->uart_txd = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__txd;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_araddr 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_araddr;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arlen 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arlen;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arsize 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arsize;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arburst 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arburst;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arcache 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arcache;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arprot 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arprot;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arvalid;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arready 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arready;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rresp 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rresp;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rlast 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rlast;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rvalid;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awaddr 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awaddr;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awlen 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awlen;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awsize 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awsize;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awburst 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awburst;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awcache 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awcache;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awprot 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awprot;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awvalid;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awready 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awready;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wvalid;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wready 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wready;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bresp 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bresp;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bvalid;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rvalid;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_araddr 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_araddr;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arlen 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arlen;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arsize 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arsize;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arburst 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arburst;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arcache 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arcache;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arprot 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arprot;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arvalid;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arready 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arready;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rresp 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rresp;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rlast 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rlast;
    vlSelf->led = (1U | ((8U & (((~ (IData)(vlSelf->uart_rxd)) 
                                 | ((0U != (IData)(vlSelf->btn)) 
                                    | (0U != (IData)(vlSelf->sw)))) 
                                << 3U)) | (((0U != vlSelf->nucleusrv_soc_top__DOT__led2_stretcher) 
                                            << 2U) 
                                           | (2U & 
                                              (vlSelf->nucleusrv_soc_top__DOT__hb_cnt 
                                               >> 0x17U)))));
    vlSelf->nucleusrv_soc_top__DOT__s1_rsp_ready = 
        ((1U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target)) 
         | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_ready));
    vlSelf->nucleusrv_soc_top__DOT__s2_rsp_ready = 
        ((2U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target)) 
         | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_ready));
    vlSelf->nucleusrv_soc_top__DOT__s3_rsp_ready = 
        ((3U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target)) 
         | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_ready));
    nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h768ca2b9__0 
        = ((0x90U <= (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__h_cnt)) 
           & (0x310U > (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__h_cnt)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__video_enable 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_vis_d2;
    vlSelf->nucleusrv_soc_top__DOT__clk_tmds = vlSelf->clk;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_wb_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrExecute 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_regWrite_0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrWriteback 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_is_csr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_mem_memRead 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memRead;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrExecute 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_is_csr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrMemory 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_is_csr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_memData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_amoOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp;
    vlSelf->hdmi_tx_clk_n = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg)));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_idx 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__beat;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bready 
        = (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wlast 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__beat) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__len));
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rdata;
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__a 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_addr;
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__Vfuncout 
        = (7U & (__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__a 
                 >> 2U));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_word 
        = __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__6__Vfuncout;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__y_screen 
        = (0x3ffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt) 
                     - (IData)(0x4bU)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelWriteback 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_wra;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isAMO;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_mem_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_src2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_strb_mux = 0xfU;
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rready 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_regWrite_0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0;
    vlSelf->hdmi_tx_p = ((4U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red) 
                                << 2U)) | ((2U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green) 
                                                  << 1U)) 
                                           | (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__stateReg)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT___io_pc4_T_2 
        = ((IData)(4U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT___io_pc2_T_2 
        = ((IData)(2U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg);
    vlSelf->nucleusrv_soc_top__DOT__imem_req_addr = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg;
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_ready 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__x_screen 
        = (0x3ffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__h_cnt) 
                     - (IData)(0x90U)));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_idx 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__beat;
    vlSelf->nucleusrv_soc_top__DOT__is_boot_imem = 
        (0x10000000U > vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rready 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_1 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value 
           + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_2 
        = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                    >> 8U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_3 
        = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                    >> 0x10U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_18 
        = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                    >> 0x10U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_28 
        = (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_quotient));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_2 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value 
           ^ vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_3 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value 
           & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_4 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value 
           | vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_6 
        = (VL_LTS_III(32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_8 
        = (VL_GTS_III(32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_24 
        = (0x200007fU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_10 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value 
            < vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_12 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value 
            > vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_4 
        = (0x3fU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_counter) 
                    - (IData)(1U)));
    if (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) {
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                        >> 0x10U));
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                        >> 8U));
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2);
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out = 0U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_u 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
           >> 0xcU);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_5 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg));
    if ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
         >> 0x1fU)) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_sb_T_2 = 0x7ffffU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_uj_T_2 = 0x7ffU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_i_T_2 = 0xfffffU;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_sb_T_2 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_uj_T_2 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_i_T_2 = 0U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[0U] 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_dividend;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[1U] = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[2U] = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeRegAddress 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                    >> 7U));
    vlSelf->hdmi_tx_clk_p = vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg;
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_0));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_1));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_2));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_3));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_4));
    vlSelf->nucleusrv_soc_top__DOT__sys_rst = (1U & 
                                               ((IData)(vlSelf->nucleusrv_soc_top__DOT__rst_sync) 
                                                >> 1U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_hde455ca6__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
           & vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2);
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_hde455ca6__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
           & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
              >> 8U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_hde455ca6__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
           & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
              >> 0x10U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_20 
        = (0xf800007fU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MCYCLE_REG_T_1 
        = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLE_REG);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_0 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLEH_REG 
           + (0U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLE_REG));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1 
        = ((IData)(1U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIME_REG);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_f3 
        = (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ins 
                 >> 0xcU));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIMEH_REG 
           + (0U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIME_REG));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___T_3 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offsetSW 
        = (3U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result);
    __VdfgTmp_hae267436__0 = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG) 
                               << 2U) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_WIRE 
        = (QData)((IData)((((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG) 
                            << 0xbU) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG) 
                                         << 7U) | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG) 
                                                   << 3U)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_WIRE 
        = (QData)((IData)((((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MEIE_REG) 
                            << 0xbU) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MTIE_REG) 
                                         << 7U) | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MSIE_REG) 
                                                   << 3U)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_WIRE_hi 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TSR_REG) 
            << 0xdU) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TW_REG) 
                         << 0xcU) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TVM_REG) 
                                      << 0xbU) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MXR_REG) 
                                                   << 0xaU) 
                                                  | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SUM_REG) 
                                                      << 9U) 
                                                     | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPRV_REG) 
                                                         << 8U) 
                                                        | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPP_REG) 
                                                           << 2U)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_opr 
        = (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                 >> 0xcU));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h63fb53c5__0 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG) 
            << 4U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG) 
                       << 3U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG) 
                                  << 2U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG) 
                                             << 1U) 
                                            | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri 
        = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg 
                 >> 1U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_5 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_is_csr)));
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_rdata 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__state))
            ? vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__resp_word
            : vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_q);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_line 
        = (0x1ffU & (vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_addr 
                     >> 5U));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_tag 
        = (0x3fffU & (vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_addr 
                      >> 0xeU));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_10 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_5 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_is_csr)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_3 
        = (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_wra));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
           >> 0x14U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_5 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_is_csr)));
    vlSelf->nucleusrv_soc_top__DOT__s3_req_ready = 
        (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_38 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_issued)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_writeEnable_T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_read_done) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_matchAddr 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__reservedValid) 
           & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__reservedAddr 
              == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_5 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isSC)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_3 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_readEnable_T_1 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_read_done)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO));
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__addr_prefix 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result 
           >> 0x1cU);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ins 
                    >> 7U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode 
        = (0x7fU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en) 
           & ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__f7_reg)) 
              & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_ready)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_22 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memRead) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3 
        = (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                 >> 0xcU));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T 
        = (0x7fU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_7 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_counter));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_8 
        = (- vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_quotient);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_12 
        = (- vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_24 
        = (0x20U > (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__counter));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_26 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offset));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_24 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offset));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_25 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offset));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
           >> 0x1bU);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_4 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_2 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? 9U : 0xfU);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f7 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f7) 
                 >> 5U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                    >> 0x14U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_2 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_3 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc1));
    vlSelf->nucleusrv_soc_top__DOT__s3_rsp_rdata = 
        ((8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))
          ? vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__resp_word
          : vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_q);
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__a 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_addr;
    __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__Vfuncout 
        = (0x1ffU & (__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__a 
                     >> 5U));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line 
        = __Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__5__Vfuncout;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isAMO) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isLR) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isSC)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___wb_data_T_1 
        = ((IData)(4U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_pc);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___wb_data_T_3 
        = ((IData)(2U) + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_pc);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                    >> 0xfU));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs2 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ins 
                    >> 0x14U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs1 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ins 
                    >> 0xfU));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ins 
                    >> 7U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory 
        = (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ins 
                    >> 7U));
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_in 
        = vlSelf->nucleusrv_soc_top__DOT__clk;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__btn_in 
        = vlSelf->nucleusrv_soc_top__DOT__btn;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_addr 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ba 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_ba;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_cas_n 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_cas_n;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ck_n 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_ck_n;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ck_p 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_ck_p;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_cke 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_cke;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_cs_n 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_cs_n;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dm 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_dm;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dq 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_dq;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dqs_n 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_dqs_n;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dqs_p 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_dqs_p;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_odt 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_odt;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ras_n 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_ras_n;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_reset_n 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_reset_n;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_we_n 
        = vlSelf->nucleusrv_soc_top__DOT__DDR_we_n;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ddr_vrn 
        = vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ddr_vrn;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ddr_vrp 
        = vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ddr_vrp;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_mio 
        = vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_mio;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ps_clk 
        = vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_clk;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ps_porb 
        = vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_porb;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ps_srstb 
        = vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_srstb;
    if ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_valid = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_valid 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_len 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_len;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_valid 
            = vlSelf->nucleusrv_soc_top__DOT__s0_rsp_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_rdata 
            = vlSelf->nucleusrv_soc_top__DOT__s0_rsp_rdata;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_rsp_ready 
            = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isLR 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isLR;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isSC 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isSC;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcAddress 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcAddress;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Ex_data 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Ex_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Mem_data 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Mem_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Wb_data 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Wb_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_comp 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_is_comp;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_immediate 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_immediate;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_readData1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_readData2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_pcAddress 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_pcAddress;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_func7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_func7;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ctl_aluSrc1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluSrc1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isLR 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isLR;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isSC 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isSC;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_nx 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nx;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_uf 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_uf;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_of 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_of;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_dz 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_dz;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_nv 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nv;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_frm 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_frm;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_ready 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_misaligned_word_uh 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word_uh;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_ready 
            = vlSelf->nucleusrv_soc_top__DOT__s1_req_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_valid 
            = vlSelf->nucleusrv_soc_top__DOT__s1_rsp_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_rdata 
            = vlSelf->nucleusrv_soc_top__DOT__s1_rsp_rdata;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_ready 
            = vlSelf->nucleusrv_soc_top__DOT__s2_req_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_valid 
            = vlSelf->nucleusrv_soc_top__DOT__s2_rsp_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_rdata 
            = vlSelf->nucleusrv_soc_top__DOT__s2_rsp_rdata;
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_ready 
            = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cmd_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_bready 
            = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_bready;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_ready 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_write = 1U;
    } else {
        if ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
            vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_valid = 1U;
        } else if ((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
            vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_valid = 1U;
        }
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_valid 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_len 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_len;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_valid 
            = vlSelf->nucleusrv_soc_top__DOT__s0_rsp_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_rdata 
            = vlSelf->nucleusrv_soc_top__DOT__s0_rsp_rdata;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_rsp_ready 
            = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isLR 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isLR;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isSC 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isSC;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcAddress 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcAddress;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Ex_data 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Ex_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Mem_data 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Mem_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Wb_data 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Wb_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_comp 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_is_comp;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_immediate 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_immediate;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_readData1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_readData2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_pcAddress 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_pcAddress;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_func7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_func7;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ctl_aluSrc1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluSrc1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isLR 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isLR;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isSC 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isSC;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_nx 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nx;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_uf 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_uf;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_of 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_of;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_dz 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_dz;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_nv 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nv;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_frm 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_frm;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_ready 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_misaligned_word_uh 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word_uh;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_ready 
            = vlSelf->nucleusrv_soc_top__DOT__s1_req_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_valid 
            = vlSelf->nucleusrv_soc_top__DOT__s1_rsp_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_rdata 
            = vlSelf->nucleusrv_soc_top__DOT__s1_rsp_rdata;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_ready 
            = vlSelf->nucleusrv_soc_top__DOT__s2_req_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_valid 
            = vlSelf->nucleusrv_soc_top__DOT__s2_rsp_valid;
        vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_rdata 
            = vlSelf->nucleusrv_soc_top__DOT__s2_rsp_rdata;
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_ready 
            = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cmd_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_bready 
            = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_bready;
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_ready 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_ready;
        if ((5U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
            if ((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
                vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_write 
                    = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_write;
            }
        }
    }
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_write 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_writeEnable_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeEnable_0;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s0_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wlast 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wlast;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram
        [vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pixel_index];
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rxd 
        = vlSelf->nucleusrv_soc_top__DOT__uart_rxd;
    vlSelf->nucleusrv_soc_top__DOT__uart_txd = vlSelf->uart_txd;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__txd 
        = vlSelf->uart_txd;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_araddr 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_araddr;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_araddr 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_araddr;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arlen 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arlen;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arlen 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arlen;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arsize 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arsize;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arsize 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arsize;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arburst 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arburst;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arburst 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arburst;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arcache 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arcache;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arcache 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arcache;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arprot 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arprot;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arprot 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arprot;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arvalid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arvalid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_arready;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rresp 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rresp;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rlast 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rlast;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rvalid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awaddr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awaddr;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awaddr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awaddr;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awlen 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awlen;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awlen 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awlen;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awsize 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awsize;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awsize 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awsize;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awburst 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awburst;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awburst 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awburst;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awcache 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awcache;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awcache 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awcache;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awprot 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awprot;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awprot 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awprot;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awready;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bresp 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bresp;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_araddr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_araddr;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_araddr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_araddr;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arlen 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arlen;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arlen 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arlen;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arsize 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arsize;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arsize 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arsize;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arburst 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arburst;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arburst 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arburst;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arcache 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arcache;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arcache 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arcache;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arprot 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arprot;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arprot 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arprot;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arvalid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rresp 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rresp;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rlast 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rlast;
    vlSelf->nucleusrv_soc_top__DOT__led = vlSelf->led;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s1_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s1_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s2_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s2_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s3_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s3_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_window 
        = ((IData)(nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h768ca2b9__0) 
           & ((0x4bU <= (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt)) 
              & (0x1dbU > (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_visible_window 
        = ((IData)(nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h768ca2b9__0) 
           & ((0x23U <= (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt)) 
              & (0x203U > (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__video_enable 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__video_enable;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__video_enable 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__video_enable;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__video_enable 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__video_enable;
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_tmds 
        = vlSelf->nucleusrv_soc_top__DOT__clk_tmds;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__clk_tmds 
        = vlSelf->nucleusrv_soc_top__DOT__clk_tmds;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_mem_wb_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_wb_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_mem_wb_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_wb_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_mem_wb_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_wb_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_id_ex_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_id_ex_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ex_mem_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ex_mem_ins 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_ins;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_id_ex_regWr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_regWrExecute 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_id_ex_regWr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Wb 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrWrWriteback 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Wb 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_mem_read 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_mem_memRead;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ex_mem_memRead 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_mem_memRead;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_mem_read 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_mem_memRead;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Ex 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrWrExecute 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Ex 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Mem 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrWrMemory 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Mem 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_func3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_f3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_func3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ctl_aluSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluSrc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_aluSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluSrc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluSrc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ctl_aluOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_aluOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_memData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_memData;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_memData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_memData;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_memData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_memData;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_op_code 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_amoOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_amoOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_amoOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_op_code 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_amoOp;
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_clk_n = vlSelf->hdmi_tx_clk_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_clk_n 
        = vlSelf->hdmi_tx_clk_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_clk_n 
        = vlSelf->hdmi_tx_clk_n;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__wr_idx 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_idx;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__wr_idx_unused 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_idx;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rd_idx 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_idx;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_bready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bready;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wlast 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wlast;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wlast 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wlast;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wlast 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wlast;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_data 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rd_data 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__y_doom 
        = (0xffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__y_screen) 
                    >> 1U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeReg 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rdSelWriteback 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_writeAddress 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_writeReg 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeAddress 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ex_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isAMO 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isAMO 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_mem_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_mem_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_mem_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_mem_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isAMO 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_mem_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_mem_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isAMO 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_mem_is_amo;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_src2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_src2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_src2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_src2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_writeData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_src2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_src2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_src2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_writeData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_src2;
    if (((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)) 
         | (0xaU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_strb_mux 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wmask;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__wr_strb 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_strb_mux;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wstrb 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_strb_mux;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rready;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rready;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_axi_rready;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_beat_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__imem_axi_rready) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rvalid));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_data 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rd_data 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_id_instruction 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_instr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_in 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_instruction 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_id_instruction 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_in 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate_io_instruction 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_regWr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_regWrMemory 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ex_mem_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_ex_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_regWr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ex_mem_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_ex_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_writeEnable_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_regWrWriteback 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_mem_wb_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_mem_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_writeEnable_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_mem_wb_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback;
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_p = vlSelf->hdmi_tx_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_p 
        = vlSelf->hdmi_tx_p;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_p 
        = vlSelf->hdmi_tx_p;
    vlSelf->hdmi_tx_n = (7U & (~ (IData)(vlSelf->hdmi_tx_p)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_18 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_address 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_address_i 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_addrRequest 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_out 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_address 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_address_i 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrReq_bits_addrRequest 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrReq_bits_addrRequest 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_out 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_req_ready 
        = vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__x_doom 
        = (0x1ffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__x_screen) 
                     >> 1U));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx 
        = (7U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__x_screen) 
                 >> 7U));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_idx 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_idx;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__wr_idx 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_idx;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rd_idx 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_idx;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_data_mux 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__line_buf
        [vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_idx];
    if (((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)) 
         | (0xaU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_data_mux 
            = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wdata;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_beat_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rready) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rvalid));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_addr_mem 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_addr_mem 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_mem_result 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_aluResultIn 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_addrIn 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__s0_req_addr = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_addrRequest 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_addr_mem 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_mem_result 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_aluResultIn 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_addrIn 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_addrRequest 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_mem 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_addrRequest 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__s1_req_addr = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__s2_req_addr = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_addr 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__s3_req_addr = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_25 
        = (0x2fU == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_24);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_0 
        = ((0x1cU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_12
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_quotient_T_2 
        = (1ULL << (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_4));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__red 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__green 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__blue 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_u 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_u 
           << 0xcU);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_sb 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_sb_T_2 
            << 0xdU) | ((0x1000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                    >> 0x13U)) | ((0x800U 
                                                   & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                           >> 7U))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_uj 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_uj_T_2) 
            << 0x15U) | ((0x100000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                       >> 0xbU)) | 
                         ((0xff000U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins) 
                          | ((0x800U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                        >> 9U)) | (0x7feU 
                                                   & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                                                      >> 0x14U))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_writeRegAddress 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeRegAddress;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_s 
        = ((0xfe0U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
                      >> 0x14U)) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeRegAddress));
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
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_reset 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pix_rst 
        = vlSelf->nucleusrv_soc_top__DOT__sys_rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__Nb1s 
        = (0xfU & ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_hde455ca6__0) 
                   + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                       & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                          >> 1U)) + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                      & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                         >> 2U)) + 
                                     (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                       & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                          >> 3U)) + 
                                      (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                        & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                           >> 4U)) 
                                       + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                           & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                              >> 5U)) 
                                          + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                              & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                 >> 6U)) 
                                             + ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                                & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                   >> 7U))))))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__Nb1s 
        = (0xfU & ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_hde455ca6__0) 
                   + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                       & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                          >> 9U)) + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                      & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                         >> 0xaU)) 
                                     + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                         & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                            >> 0xbU)) 
                                        + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                            & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                               >> 0xcU)) 
                                           + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                               & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                  >> 0xdU)) 
                                              + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                                  & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                     >> 0xeU)) 
                                                 + 
                                                 ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                                  & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                     >> 0xfU))))))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__Nb1s 
        = (0xfU & ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_hde455ca6__0) 
                   + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                       & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                          >> 0x11U)) + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                         & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                            >> 0x12U)) 
                                        + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                            & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                               >> 0x13U)) 
                                           + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                               & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                  >> 0x14U)) 
                                              + (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                                  & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                     >> 0x15U)) 
                                                 + 
                                                 (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                                   & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                      >> 0x16U)) 
                                                  + 
                                                  ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2) 
                                                   & (vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 
                                                      >> 0x17U))))))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_s_T_2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_i_T_2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_23 
        = (0x1800002fU == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_21 
        = (0x1000002fU == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_20);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLEH_REG;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MCYCLE_REG_T_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_0;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_f3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_f3;
    if ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offsetSW))) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_6 = 4U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_4 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_5 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_6 = 8U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_4 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_5 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_8 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offsetSW));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_7 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offsetSW));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_WIRE 
        = __VdfgTmp_hae267436__0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_WIRE 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_WIRE_hi 
            << 9U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SPP_REG) 
                       << 8U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPIE_REG) 
                                  << 7U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_UBE_REG) 
                                             << 6U) 
                                            | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SPIE_REG) 
                                                << 5U) 
                                               | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MIE_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SIE_REG) 
                                                     << 1U)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_opr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_opr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FFLAGS_WIRE 
        = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h63fb53c5__0;
    __VdfgTmp_hea002d6a__0 = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG) 
                               << 5U) | (IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h63fb53c5__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_addri 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_addri 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_addri 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__addri 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_rsp_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__hit 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid[
            ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_line) 
             >> 5U)] >> (0x1fU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_line))) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__tag_q) 
              == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_tag)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_addr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_addr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_addr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_i 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_i 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_i_T_2 
            << 0xcU) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_8 
        = (0x342U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_40 
        = (0xc81U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_6 
        = (0x300U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_1 
        = ((0x301U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MISA_REG
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_38 
        = (0xc01U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_10 
        = (0x305U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_36 
        = (0x320U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_12 
        = (0x341U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_34 
        = (0xb82U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_32 
        = (0xb02U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_14 
        = (0x340U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_30 
        = (0xb80U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_28 
        = (0xb00U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_24 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_16 
        = (0x343U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_26 
        = (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_18 
        = (0x304U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_20 
        = (0x344U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_22 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s3_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_ready 
        = vlSelf->nucleusrv_soc_top__DOT__s3_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_46 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_writeEnable_T_4;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_matchAddr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_matchAddr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_success 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_matchAddr) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isSC));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_44 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_3;
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h787a05cb__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_3) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_45 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memWrite) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_5) 
              & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_3)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readEnable 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memRead) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_readEnable_T_1) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isLR)));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__uncached 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__addr_prefix));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_id_ex_rd 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rdSelExecute 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_id_ex_rd 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_ex 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_regWrite_0) 
           & (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_3 
        = (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__opcode 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___T_16 
        = (0x23U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr 
        = (0x73U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT____VdfgTmp_h46ae23c6__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isAMO) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_22));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_opr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_funct3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_func3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_func3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_opr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_funct3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_46 
        = (5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT____VdfgTmp_h57bd0bc5__0 
        = ((0x2fU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
           & (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_17 
        = (0x6fU == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_19 
        = (0x67U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_13 
        = (0x37U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_15 
        = (0x17U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1 
        = (0x33U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3 
        = (0x13U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5 
        = (0x73U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_7 
        = (3U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_9 
        = (0x23U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_11 
        = (0x63U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_23 
        = ((2U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           & (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___T_3 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_1 
        = ((0x1cU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_2 
        = ((0x18U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (0x1cU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_4) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_ready));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_12 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_4) 
           & ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3)) 
              | ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3)) 
                 | ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3)) 
                    | (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_23 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_4) 
           & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en)) 
              & ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3)) 
                 | ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3)) 
                    | ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3)) 
                       | (7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_3 
        = ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_f7 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f7;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___T_4 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f7)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f7)
            ? 8U : 7U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readAddress_1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_8 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_wra) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___io_readData_1_T 
        = (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_97 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_1
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_0);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_rsp_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__s3_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rsp_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__s3_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_addr = 0U;
    if ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_addr 
            = (0x10000000U | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__victim_tag) 
                               << 0xeU) | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line) 
                                           << 5U)));
    } else if ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_addr 
            = (0x10000000U | (0xfffffe0U & vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_addr));
    } else if ((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_addr 
            = (0x10000000U | (0xffffffcU & vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_addr));
    }
    vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__imem_src_boot)
            ? vlSelf->nucleusrv_soc_top__DOT__boot_imem_rdata
            : vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_rdata);
    vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target))
            ? vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rdata
            : ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target))
                ? vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_rdata
                : ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target))
                    ? vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_rdata
                    : vlSelf->nucleusrv_soc_top__DOT__s3_rsp_rdata)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__op_reg)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_5 
        = ((0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_counter))
            ? (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_counter))
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_ready));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_13 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__sys_rst)
            ? 0U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_addr 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))
            ? (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line) 
                << 3U) | (7U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wb_cnt)))
            : ((([&]() {
                        vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__7__a 
                            = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
                        vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__7__Vfuncout 
                            = (0x1ffU & (vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__7__a 
                                         >> 5U));
                    }(), (IData)(vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__7__Vfuncout)) 
                << 3U) | ([&]() {
                    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__8__a 
                        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr;
                    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__8__Vfuncout 
                        = (7U & (vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__8__a 
                                 >> 2U));
                }(), (IData)(vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__8__Vfuncout))));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__hit 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid[
            ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line) 
             >> 5U)] >> (0x1fU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line))) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__tag_q) 
              == ([&]() {
                    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__tag_of__10__a 
                        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_addr;
                    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__tag_of__10__Vfuncout 
                        = (0x3fffU & (vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__tag_of__10__a 
                                      >> 0xeU));
                }(), (IData)(vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__tag_of__10__Vfuncout))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_op 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T 
        = (5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T_1 
        = (7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T 
        = (4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T_1 
        = (6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_1 
        = (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_4 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_11 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_67 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_memToReg))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___wb_data_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_result);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_imm 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rs1SelDecode 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readAddress_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registerRs1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rs1SelDecode 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_4 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___io_readData_0_T 
        = (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_65 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_1
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_0);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_wra) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_reg_rs2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_reg_rs1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_mem_reg_rd 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_mem_wb 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0) 
           & (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_15 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_7 
        = (1U & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0)) 
                 | (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_rd 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rdSelMemory 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_ex_reg_rd 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_rd 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_ex_reg_rd 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_3 
        = (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_ex_mem 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_regWrite_0) 
           & (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_10 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory) 
           == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_2 
        = (1U & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_regWrite_0)) 
                 | (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory))));
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rxd 
        = vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rxd;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arready 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arready;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rresp 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rresp;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rlast 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rlast;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awready 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wready 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_bresp 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bresp;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_bvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rvalid 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rvalid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arready 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arready;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rresp 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rresp;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rlast 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rlast;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__clk_tmds 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__clk_tmds;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wstrb 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wstrb;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wstrb 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wstrb;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wstrb 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wstrb;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rd_beat_valid 
        = vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_beat_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rdata;
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_n = vlSelf->hdmi_tx_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_n 
        = vlSelf->hdmi_tx_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_n 
        = vlSelf->hdmi_tx_n;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_byte_addr 
        = (0xffffU & (VL_SHIFTL_III(16,16,32, (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__y_doom), 8U) 
                      + (VL_SHIFTL_III(16,16,32, (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__y_doom), 6U) 
                         + (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__x_doom))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_g 
        = (((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
            | ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
               | ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
                  | (7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)))))
            ? 0xffU : 0U);
    nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h5138ab69__0 
        = ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
           | (7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)));
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__wr_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_data_mux;
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_data_mux;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rd_beat_valid 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_beat_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_1 
        = ((0x18U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_10
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_0);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_quotient_T_4 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_28 
           + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_quotient_T_2);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__video_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__red;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__video_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__green;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__video_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__blue;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_0 
        = ((0x63U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_sb
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_uj);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_s 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_i_T_2 
            << 0xcU) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_s));
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
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR 
        = ((4U < (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__Nb1s)) 
           | ((~ (IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_hde455ca6__0)) 
              & (4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__Nb1s))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR 
        = ((4U < (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__Nb1s)) 
           | ((~ (IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_hde455ca6__0)) 
              & (4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__Nb1s))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR 
        = ((4U < (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__Nb1s)) 
           | ((~ (IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_hde455ca6__0)) 
              & (4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__Nb1s))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_39 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_23)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_25));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_8) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_11 = 2U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_17 = 6U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_7 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 8U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_8 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_9 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x10U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_10 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_19 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_20 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 8U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_21 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_11 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_6;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_17 = 0xcU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_7 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_2));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_8 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_3));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_9 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_4));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_10 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_5));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_19 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_20 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_21 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 8U));
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_7) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_23 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_12 = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_22 = 3U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_13 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_14 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 8U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_15 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x10U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_16 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_24 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 8U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_25 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x10U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_26 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_23 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_18));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_12 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_11;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_22 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_17;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_13 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_7));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_14 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_8));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_15 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_9));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_16 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_10));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_24 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_19));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_25 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_20));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_26 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_21));
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_WIRE 
        = __VdfgTmp_hea002d6a__0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemRsp_bits_dataResponse 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrResp_bits_dataResponse 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrResp_bits_dataResponse 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_valid 
        = (((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__state)) 
            & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__hit)) 
           | (4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__state)));
    vlSelf->nucleusrv_soc_top__DOT__imem_rsp_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__imem_src_boot)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__boot_imem_rsp_val)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_valid));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_3 
        = ((0xf14U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MHARTID_REG
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_53 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_success) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_matched));
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_45) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_writeEnable_T_4) 
              | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isSC) 
                 & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_38) 
                    & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_success)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_readEnable 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readEnable;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__addr_prefix))
            ? 1U : ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__addr_prefix))
                     ? 2U : ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__addr_prefix))
                              ? 3U : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__uncached)
                                       ? 3U : 0U))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_28 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_ex) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm) 
              == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrInstDecode 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_is_csr 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrInstDecode 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___T_11 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
           | ((0xfU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
              | ((0x13U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
                 | ((0x1bU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
                    | ((0x67U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
                       | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_stall_T_7 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3)) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_46) 
              | ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3)) 
                 | (7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_47 
        = ((0x13U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_46));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_65 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_19)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_21));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_83 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_7)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_9));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_57 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_11)) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_13) 
              | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_15) 
                 | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_17) 
                    | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_19) 
                       | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_21) 
                          | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_23) 
                             | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_25))))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_34 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_9)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_11));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isSC 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT____VdfgTmp_h57bd0bc5__0) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_23));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isLR 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT____VdfgTmp_h57bd0bc5__0) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___T_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_3 
        = ((0x18U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_4 
        = ((0x14U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_23) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_23)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f7)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__f7_reg));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_23) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en) 
              & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_24)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_23) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_12));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_4 
        = ((7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? 0U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_0 
        = ((1U & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc)) 
                  | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___T_4)))
            ? 2U : 3U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_6) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_98 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_2
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_97);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_bits_dataResponse 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_dmem_data 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmRsp_bits_dataResponse 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_dmem_data 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmRsp_bits_dataResponse 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_rsp_rdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_addr 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_addr;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__we = 0U;
    if ((((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)) 
          & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_write)) 
         & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__hit))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__we = 1U;
    } else if ((7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__we = 1U;
    } else if (((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)) 
                & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_beat_valid))) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__we = 1U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wm 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wd 
        = vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wa 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line) 
            << 3U) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_word));
    if ((1U & (~ (((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)) 
                   & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_write)) 
                  & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__hit))))) {
        if ((7U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state))) {
            if (((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)) 
                 & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_beat_valid))) {
                vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wm = 0xfU;
                vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wd 
                    = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rdata;
                vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wa 
                    = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line) 
                        << 3U) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_idx));
            }
        }
    }
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__lookup_hit_load 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)) 
           & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_write)) 
              & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__hit)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_op 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_op;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_18 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T_1)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_dividend
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_1));
    nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_hb36ceaa9__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_11) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_1) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_4)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_69 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_memToReg))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___wb_data_T_1
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_67);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_w_en 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___io_readData_0_T));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_66 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_2
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_65);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_3 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_24 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_mem_wb) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1) 
              == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_16 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_mem_wb) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm) 
              == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_18 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_15) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_8 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_5) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_20 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_ex_mem) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1) 
              == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_12 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_ex_mem) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm) 
              == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_13 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_10) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_3 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_2));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_word 
        = (0x3fffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_byte_addr) 
                      >> 2U));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_byte_sel 
        = (3U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_byte_addr));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_r 
        = (((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
            | ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
               | (IData)(nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h5138ab69__0)))
            ? 0xffU : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_b 
        = (((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
            | ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx)) 
               | (IData)(nucleusrv_soc_top__DOT__u_video__DOT____VdfgTmp_h5138ab69__0)))
            ? 0xffU : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_2 
        = ((0x14U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_8
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___T_16)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_s
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_0);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__clk 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__rst 
        = vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x1feU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out)));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)
                  ? (~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                        ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                           >> 1U))) : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                       ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                          >> 1U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x1fdU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0) 
              << 1U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                         >> 1U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                   >> 2U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                >> 1U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                                  >> 2U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x1fbU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0) 
              << 2U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                         >> 2U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                   >> 3U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                >> 2U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                                  >> 3U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x1f7U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0) 
              << 3U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                         >> 3U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                   >> 4U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                >> 3U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                                  >> 4U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x1efU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0) 
              << 4U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                         >> 4U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                   >> 5U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                >> 4U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                                  >> 5U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x1dfU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0) 
              << 5U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                         >> 5U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                   >> 6U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                >> 5U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                                  >> 6U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x1bfU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0) 
              << 6U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                         >> 6U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                   >> 7U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                >> 6U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out) 
                                                  >> 7U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m 
        = ((0x7fU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
           | ((0x100U & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR)) 
                         << 8U)) | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____Vlvbound_h643ed853__0) 
                                    << 7U)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x1feU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out)));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)
                  ? (~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                        ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                           >> 1U))) : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                       ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                          >> 1U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x1fdU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0) 
              << 1U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                         >> 1U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                   >> 2U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                >> 1U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                                  >> 2U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x1fbU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0) 
              << 2U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                         >> 2U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                   >> 3U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                >> 2U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                                  >> 3U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x1f7U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0) 
              << 3U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                         >> 3U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                   >> 4U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                >> 3U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                                  >> 4U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x1efU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0) 
              << 4U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                         >> 4U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                   >> 5U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                >> 4U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                                  >> 5U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x1dfU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0) 
              << 5U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                         >> 5U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                   >> 6U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                >> 5U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                                  >> 6U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x1bfU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0) 
              << 6U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                         >> 6U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                   >> 7U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                >> 6U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out) 
                                                  >> 7U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m 
        = ((0x7fU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
           | ((0x100U & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR)) 
                         << 8U)) | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____Vlvbound_h643ed853__0) 
                                    << 7U)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x1feU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out)));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)
                  ? (~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                        ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                           >> 1U))) : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                       ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                          >> 1U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x1fdU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0) 
              << 1U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                         >> 1U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                   >> 2U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                >> 1U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                                  >> 2U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x1fbU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0) 
              << 2U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                         >> 2U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                   >> 3U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                >> 2U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                                  >> 3U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x1f7U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0) 
              << 3U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                         >> 3U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                   >> 4U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                >> 3U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                                  >> 4U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x1efU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0) 
              << 4U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                         >> 4U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                   >> 5U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                >> 4U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                                  >> 5U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x1dfU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0) 
              << 5U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                         >> 5U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                   >> 6U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                >> 5U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                                  >> 6U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x1bfU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0) 
              << 6U));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0 
        = (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)
                  ? (~ (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                         >> 6U) ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                   >> 7U))) : (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                >> 6U) 
                                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out) 
                                                  >> 7U))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m 
        = ((0x7fU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
           | ((0x100U & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR)) 
                         << 8U)) | ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____Vlvbound_h643ed853__0) 
                                    << 7U)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_40 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_21) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_39));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_19) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_101 = 2U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_41 = 2U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_101 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_41 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_40;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_rsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_5 
        = ((0xf12U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MARCHID_REG
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_result 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_53)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_writeEnable 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__s0_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_isWrite 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_writeEnable 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_isWrite 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_isWrite 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__s1_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__s2_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__s3_req_is_write 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write;
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readEnable) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write));
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h29370b46__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write) 
           & ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_f3)) 
              & (IData)(nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h787a05cb__0)));
    nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h283210de__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write) 
           & ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_f3)) 
              & (IData)(nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h787a05cb__0)));
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__s0_req_ready)
            : ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target))
                ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_ready)
                : ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target))
                    ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_ready)
                    : (IData)(vlSelf->nucleusrv_soc_top__DOT__s3_req_ready))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_48 
        = ((0x33U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_47));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_66 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_17)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_65));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_17) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_102 = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_42 = 2U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_102 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_101;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_42 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_41;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_128 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_13)
            ? 2U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_121 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3)
            ? 2U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_84 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_83));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_58 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_9)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_57));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_35 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_7)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_34));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_isSC 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isSC;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_isSC 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isSC;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_isSC 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isSC;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_isLR 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isLR;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_isLR 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isLR;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_isLR 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isLR;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_5 
        = ((0x14U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_6 
        = ((0x10U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_12 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_24) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_stall 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_stall 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___ex_reg_ctl_regWrite_0_T 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_stall 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_11 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_24) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_5 
        = ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_1)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_99 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_98);
    vlSelf->nucleusrv_soc_top__DOT__s3_rsp_valid = 
        ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__lookup_hit_load) 
         | (8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state)));
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__slave_rsp_valid 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rsp_val)
            : ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target))
                ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_valid)
                : ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target))
                    ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_valid)
                    : (IData)(vlSelf->nucleusrv_soc_top__DOT__s3_rsp_valid))));
    nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_h93af1d9c__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u));
    vlSelf->nucleusrv_soc_top__DOT__core_pin = ((1U 
                                                 == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_memToReg))
                                                 ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_rd
                                                 : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_69);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_w_en 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_w_en;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_w_en 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_w_en;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_w_en 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_w_en;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_67 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_66);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_19 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_18) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_9 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_8) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_14 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_13) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_3) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_regWrite_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_3 
        = ((0x10U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_6
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_2 
        = (((0x17U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)) 
            | (0x37U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_u
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance 
        = (0xfU & (((1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
                    + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                              >> 1U)) + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                >> 2U)) 
                                         + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                   >> 3U)) 
                                            + ((1U 
                                                & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                   >> 4U)) 
                                               + ((1U 
                                                   & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                      >> 5U)) 
                                                  + 
                                                  ((1U 
                                                    & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                       >> 6U)) 
                                                   + 
                                                   (1U 
                                                    & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                                       >> 7U))))))))) 
                   - (IData)(4U)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance 
        = (0xfU & (((1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
                    + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                              >> 1U)) + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                >> 2U)) 
                                         + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                   >> 3U)) 
                                            + ((1U 
                                                & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                   >> 4U)) 
                                               + ((1U 
                                                   & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                      >> 5U)) 
                                                  + 
                                                  ((1U 
                                                    & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                       >> 6U)) 
                                                   + 
                                                   (1U 
                                                    & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                                       >> 7U))))))))) 
                   - (IData)(4U)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance 
        = (0xfU & (((1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
                    + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                              >> 1U)) + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                >> 2U)) 
                                         + ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                   >> 3U)) 
                                            + ((1U 
                                                & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                   >> 4U)) 
                                               + ((1U 
                                                   & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                      >> 5U)) 
                                                  + 
                                                  ((1U 
                                                    & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                       >> 6U)) 
                                                   + 
                                                   (1U 
                                                    & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                                       >> 7U))))))))) 
                   - (IData)(4U)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemRsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrResp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrResp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_6)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_WIRE
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_5);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__s0_req_valid = 
        ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid) 
         & (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target)));
    vlSelf->nucleusrv_soc_top__DOT__s1_req_valid = 
        ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid) 
         & (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target)));
    vlSelf->nucleusrv_soc_top__DOT__s3_req_valid = 
        ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid) 
         & (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target)));
    vlSelf->nucleusrv_soc_top__DOT__s2_req_valid = 
        ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid) 
         & (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target)));
    if (nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h283210de__0) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_27 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_22;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_28 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_23));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_29 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_24));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_30 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_25));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_31 
            = (0xffU & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_26));
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_27 = 0xfU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_28 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_29 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 8U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_30 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x10U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_31 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd 
                        >> 0x18U));
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_ready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_ready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_ready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_ready 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_36 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_is_csr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_5) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_is_csr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_5) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecEx_T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_is_csr));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_5) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_51 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_48) 
           | (0x53U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_67 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_15)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_66));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_15) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_103 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_43 = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_103 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_102;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_43 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_42;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_13) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_104 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_44 = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_104 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_103;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_44 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_43;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_11) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_129 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_105 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_45 = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_129 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_128;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_105 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_104;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_45 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_44;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_9) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_130 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_106 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_46 = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_130 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_129;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_106 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_105;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_46 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_45;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluOp 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1)
            ? 2U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_121));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_aluOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_aluOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_aluOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_85 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_84));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_regWrite 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3) 
              | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5) 
                 | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_7) 
                    | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_58)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_36 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_35));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_7 
        = ((0x10U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_8 
        = ((8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_6));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_6 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? 5U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_100 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_4
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_99);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_rsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s3_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s3_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeData 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_mem_wb_result 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_wb_result 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_pin 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__wb_data 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_writeData 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_wb_result 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_wb_result 
        = vlSelf->nucleusrv_soc_top__DOT__core_pin;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeData 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_is_csr)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_csr_data
            : vlSelf->nucleusrv_soc_top__DOT__core_pin);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_8)
            ? 0U : vlSelf->nucleusrv_soc_top__DOT__core_pin);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_4)
            ? 0U : vlSelf->nucleusrv_soc_top__DOT__core_pin);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_68 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_4
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_67);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___GEN_2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_19)
            ? 2U : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___GEN_0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_9)
            ? 2U : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_4 
        = ((8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_4
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_3 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___T_11)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_i
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_2);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_sign_eq 
        = ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance) 
                  >> 3U)) == (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc) 
                                    >> 3U)));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_h329f2e42__0 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance)) 
           | (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_sign_eq 
        = ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance) 
                  >> 3U)) == (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc) 
                                    >> 3U)));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_h329f2e42__0 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance)) 
           | (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_sign_eq 
        = ((1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance) 
                  >> 3U)) == (1U & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc) 
                                    >> 3U)));
    nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_h329f2e42__0 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance)) 
           | (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_9 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_8)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCAUSE_REG
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_7);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s0_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s1_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s1_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s3_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s3_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__accept 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__s3_req_valid) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__s3_req_ready));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s2_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__s2_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_write_en 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__s2_req_valid) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_ready) 
              & ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write) 
                 & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__is_fb_addr))));
    if (nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_h29370b46__0) {
        vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_12;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_0 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_13;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_14;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_15;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_3 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_16;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_27;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_0 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_28;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_29;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_30;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_3 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_31;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_clear 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isSC) 
            & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_36) 
               | ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_success)) 
                  & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_38)))) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_45));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_5) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_8 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_6) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_5) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_8 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_6) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecEx_T_5) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_6) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_func7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_51)
            ? (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins 
               >> 0x19U) : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_68 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_13)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_67));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_7) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_131 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_107 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_47 = 1U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_131 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_130;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_107 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_106;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_47 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_46;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memWrite 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_85));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_regWrite 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_regWrite;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_37 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_36));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_9 
        = ((8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_10 
        = ((0xcU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_8));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_11)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_valid 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_8 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_valid)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_12 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_valid)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_7 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? 4U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_6));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_101 
        = ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_100);
    vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__read_pending) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__slave_rsp_valid));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_writeData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeData;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__writeData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeData;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_69 
        = ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_68);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardB 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_14)
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___GEN_2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardA 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_4)
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___GEN_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_5 
        = ((0xcU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_out 
        = ((0x2fU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode))
            ? 0U : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_3);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc_inc 
        = (0xfU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance) 
                   - (1U & ((~ (IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_h329f2e42__0)) 
                            & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_sign_eq)) 
                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                  >> 8U))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__invert_q_m 
        = (1U & ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT____VdfgTmp_h329f2e42__0)
                  ? (~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                        >> 8U)) : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_sign_eq)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc_inc 
        = (0xfU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance) 
                   - (1U & ((~ (IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_h329f2e42__0)) 
                            & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_sign_eq)) 
                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                  >> 8U))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__invert_q_m 
        = (1U & ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT____VdfgTmp_h329f2e42__0)
                  ? (~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                        >> 8U)) : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_sign_eq)));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc_inc 
        = (0xfU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance) 
                   - (1U & ((~ (IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_h329f2e42__0)) 
                            & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_sign_eq)) 
                               ^ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                  >> 8U))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__invert_q_m 
        = (1U & ((IData)(nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT____VdfgTmp_h329f2e42__0)
                  ? (~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                        >> 8U)) : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_sign_eq)));
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__s0_req_wmask = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_activeByteLane 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_activeByteLane 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_activeByteLane 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__s1_req_wmask = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__s2_req_wmask = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_wmask 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__s3_req_wmask = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___writeDataFinal_T_1 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_3) 
            << 0x18U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_2) 
                          << 0x10U) | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_1) 
                                        << 8U) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_0))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_clear 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_clear;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_8 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_9 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_func7 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_func7;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_stall 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_func7)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_stall_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_69 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_11)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_68));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_132 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_108 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_48 = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_132 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_131;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_108 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_107;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_48 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_47;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_133 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_109 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_49 = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_133 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_132;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_109 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_108;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_49 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_48;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc1 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memToReg = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_133;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_109;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memToReg 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_49;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_memWrite 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memWrite;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_37));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_37));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_11 
        = ((0xcU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_9));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_12 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_10));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_17 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_h93af1d9c__0) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_12));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_8 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? 6U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_102 
        = ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_6
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_101);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmRsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmRsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_rsp_valid 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_47 
        = ((~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_writeEnable_T_4) 
               & (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid))) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_writeEnable_T_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_set 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isLR) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__amo_transition_stall 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid) 
              & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readEnable)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_2 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid) 
            & (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
               >> 7U)) ? 0xffffffU : 0U);
    if (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid) {
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcfc558ec__0 
            = (0xffU & vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata);
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he97e1a07__0 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
                        >> 8U));
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcec61ad5__0 
            = (0xffffU & vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata);
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hd012719c__0 
            = (0xffU & (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
                        >> 0x10U));
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he87f56f4__0 
            = (0xffffU & (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
                          >> 8U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__rdata 
            = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb01d673c__0 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
                     >> 0xfU));
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb00d4ce4__0 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
                     >> 0x17U));
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb3680d89__0 
            = (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
               >> 0x1fU);
    } else {
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcfc558ec__0 = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he97e1a07__0 = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcec61ad5__0 = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hd012719c__0 = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he87f56f4__0 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__rdata = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb01d673c__0 = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb00d4ce4__0 = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb3680d89__0 = 0U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_70 
        = ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_6
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_69);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_forwardB 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardB;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardB));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_1 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardB));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_2 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardB));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_forwardA 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardA;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardA));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_1 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardA));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_2 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardA));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_6 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_2
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_immediate 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_out;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_immediate 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_out;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate_io_out 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_out;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_1 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_out 
           + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_pc);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__TMDS_data 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__invert_q_m) 
            << 9U) | ((0x100U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m)) 
                      | (0xffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m) 
                                  ^ (- (IData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__invert_q_m)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc_new 
        = (0xfU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__invert_q_m)
                    ? ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc) 
                       - (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc_inc))
                    : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc) 
                       + (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc_inc))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__TMDS_data 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__invert_q_m) 
            << 9U) | ((0x100U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m)) 
                      | (0xffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m) 
                                  ^ (- (IData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__invert_q_m)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc_new 
        = (0xfU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__invert_q_m)
                    ? ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc) 
                       - (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc_inc))
                    : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc) 
                       + (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc_inc))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__TMDS_data 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__invert_q_m) 
            << 9U) | ((0x100U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m)) 
                      | (0xffU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m) 
                                  ^ (- (IData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__invert_q_m)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc_new 
        = (0xfU & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__invert_q_m)
                    ? ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc) 
                       - (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc_inc))
                    : ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc) 
                       + (IData)(vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc_inc))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_9 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_8) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_8) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_10 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_9) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_8));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecMem 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_9) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_8));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_stall 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_stall;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_70 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_9)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_69));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_aluSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_aluSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_aluSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_13 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_11));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_14 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_12));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_23 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_hb36ceaa9__0) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_17));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_9 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_0)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_8));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_103 
        = ((7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_7
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_102);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_49 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_readEnable_T_1) 
            & (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_47));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_set 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_set;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT___GEN_1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_set) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__reservedValid));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_stall 
        = (((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready)) 
            & (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write)) 
           | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T) 
               & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readEnable)) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__amo_transition_stall)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_4 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_2 
            << 8U) | (IData)(nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcfc558ec__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_22 
        = nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcfc558ec__0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_25 
        = nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he97e1a07__0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_34 
        = nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcec61ad5__0;
    if (nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb01d673c__0) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_7 = 0xffffffU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_43 = 0xffffU;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_7 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_43 = 0U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_28 
        = nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hd012719c__0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_37 
        = nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he87f56f4__0;
    if (nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb00d4ce4__0) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_12 = 0xffffffU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_48 = 0xffffU;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_12 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_48 = 0U;
    }
    if (nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hb3680d89__0) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_17 = 0xffffffU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_53 = 0xffffU;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_17 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_53 = 0U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_31 
        = VL_SHIFTR_III(32,32,32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__rdata, 0x18U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_40 
        = VL_SHIFTR_III(32,32,32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__rdata, 0x10U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_71 
        = ((7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_7
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_70);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_3 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_2)
            ? vlSelf->nucleusrv_soc_top__DOT__core_pin
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_3 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_2)
            ? vlSelf->nucleusrv_soc_top__DOT__core_pin
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_7 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_6);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_5 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecWb 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_9) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecMem) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecWb 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_10;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_3 = 2U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecWb = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_3 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_72 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5)) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_7) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_70)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_15 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_13));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_16 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_14));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_23));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_10 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluOp))
            ? 0xfU : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_9));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_104 
        = ((8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_8
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_103);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_stall 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_stall;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_2 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_stall)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_9 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_7 
            << 8U) | (IData)(nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he97e1a07__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_45 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_43) 
            << 0x10U) | (IData)(nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hcec61ad5__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_14 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_12 
            << 8U) | (IData)(nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_hd012719c__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_50 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_48) 
            << 0x10U) | (IData)(nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT____VdfgTmp_he87f56f4__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_19 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_17 
            << 8U) | ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid)
                       ? (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
                          >> 0x18U) : 0U));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_55 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_53) 
            << 0x10U) | ((IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid)
                          ? (vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata 
                             >> 0x10U) : 0U));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_26) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_43 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_28;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_39 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_14;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_43 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_31;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_39 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_19;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_25) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_47 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_37;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_50 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_50;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_44 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_25;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_40 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_9;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_47 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_40;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_50 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_55;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_44 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_43;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_40 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_39;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_72 
        = ((8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_8
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_71);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_1)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_1)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_1
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecWb)
            ? 3U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_73 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_72));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_aluSrc1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_aluSrc1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_aluSrc1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_17 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? 0U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_20 
        = ((3U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_16));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_output_valid 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluOp))
            ? 2U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_10));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_105 
        = ((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_9
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_104);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_51 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_2) 
            & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isSC)) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_issued));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_24) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_48 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_34;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_51 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_45;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_45 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_22;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_41 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_48 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_47;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_51 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_50;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_45 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_44;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_41 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_40;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_73 
        = ((9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_9
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_72);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_writeData 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_rd2
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__inputMux1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_rd1
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_amo_alu_result_in 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_result 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_amo_alu_result_in 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_result 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_result 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result;
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO) 
            & (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___writeDataFinal_T_1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx)
            ? 4U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memRead 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_73));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_19 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5))
            ? 3U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_17));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_24 
        = ((2U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_20));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_aluCtl 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_out 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_aluCtl 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T 
        = (0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_2 
        = (1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_4 
        = (2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_7 
        = (3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_10 
        = (4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_14 
        = (5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_16 
        = (6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_19 
        = (7U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_22 
        = (8U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_27 
        = (9U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_106 
        = ((0xaU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_10
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_105);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_74 
        = ((0xaU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_10
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_73);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_writeData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_writeData;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__inputMux2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_writeData;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn2_T_2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_writeData
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_imm);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_3)
            ? 0U : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__inputMux1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__s0_req_wdata = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_dataRequest 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_dataRequest 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__s1_req_wdata = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__s2_req_wdata = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_wdata 
        = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__s3_req_wdata = vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_9 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem)
            ? 5U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_7));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_memRead 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memRead;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memRead 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memRead;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_memRead 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memRead;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_22 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___T_3)
            ? 2U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_19));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT____VdfgTmp_h57bd0bc5__0) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_24));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_107 
        = ((0xbU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_11
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_106);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_53 
        = ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__funct3))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_48
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_51);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_75 
        = ((0xbU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_11
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_74);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_1) {
        nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT____VdfgTmp_hd104829c__0 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2 = 0U;
    } else {
        nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT____VdfgTmp_hd104829c__0 
            = (0x1fU & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn2_T_2);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn2_T_2;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_2)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_pc
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_1)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__inputMux1
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_5);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__src_b_reg;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__src_a_reg;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecWb)
            ? 6U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_9));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_jump 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_jump 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_jump 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_jump 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_jump 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_amoOp 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT____VdfgTmp_h57bd0bc5__0)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_22)
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_id_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_isAMO 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_isAMO 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_isAMO 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_id_is_amo 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_108 
        = ((0xcU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_12
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_107);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_54 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__funct3))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_45
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_53);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_76 
        = ((0xcU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_12
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_75);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_input2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluIn2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_amoOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_amoOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_amoOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_amoOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_amoOp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_amoOp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_109 
        = ((0xdU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_13
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_108);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_55 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__funct3))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_41
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_54);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_77 
        = ((0xdU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_13
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_76);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_src_b 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___divisor_T_3 
        = (- vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_6 
        = (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_input1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluIn1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_1 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
           & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_3 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
           | vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_6 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
           + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_9 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
           - vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_13 
        = VL_LTS_III(32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_15 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
           < vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___GEN_0 
        = (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_21 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
           >> (IData)(nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT____VdfgTmp_hd104829c__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_26 
        = VL_SHIFTRS_III(32,32,5, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1, (IData)(nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT____VdfgTmp_hd104829c__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_28 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 
           ^ vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_memToReg 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memToReg;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_ctl_memToReg_T_1 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memToReg)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_is_comp));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_110 
        = ((0xeU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_14
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_109);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_readData 
        = (((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__funct3)) 
            | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO) 
               | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isLR)))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__rdata
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_55);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_78 
        = ((0xeU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_14
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_77);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__divisor 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
            & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b 
               >> 0x1fU)) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___divisor_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_18 
        = (0x7fffffffffffffffULL & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___GEN_0 
                                    << (IData)(nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT____VdfgTmp_hd104829c__0)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_29 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_27)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_28
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_src_a 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___dividend_T_3 
        = (- vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_9 
        = ((((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a 
              >> 0x1fU) != (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b 
                            >> 0x1fU)) & (0U != vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_8
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_quotient);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_13 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a 
            >> 0x1fU) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_12
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_3 
        = ((QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a)) 
           * (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b)));
    VL_EXTENDS_WI(65,32, __Vtemp_3, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a);
    __Vtemp_4[0U] = __Vtemp_3[0U];
    __Vtemp_4[1U] = __Vtemp_3[1U];
    __Vtemp_4[2U] = (1U & __Vtemp_3[2U]);
    VL_EXTENDS_WQ(65,33, __Vtemp_6, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_6);
    __Vtemp_7[0U] = __Vtemp_6[0U];
    __Vtemp_7[1U] = __Vtemp_6[1U];
    __Vtemp_7[2U] = (1U & __Vtemp_6[2U]);
    VL_MULS_WWW(65, __Vtemp_8, __Vtemp_4, __Vtemp_7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_7[0U] 
        = __Vtemp_8[0U];
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_7[1U] 
        = __Vtemp_8[1U];
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_7[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_15 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a), 
                      VL_EXTENDS_QI(64,32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memToReg 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_ctl_memToReg_T_1)
            ? 3U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memToReg));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_111 
        = ((0xfU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_15
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_110);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readData 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_readData;
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memRead) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_readData;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_52 
            = vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_52 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_79 
        = ((0xfU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_15
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_78);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_2[0U] 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__divisor;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_2[1U] = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_2[2U] = 0U;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_30 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_22)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_26
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_29);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__dividend 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
            & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a 
               >> 0x1fU)) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___dividend_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_19 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T_1)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_13
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_18);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_10 
        = (((QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_7[1U])) 
            << 0x20U) | (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_7[0U])));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_16 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_11)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_15
            : 0ULL);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_memToReg 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memToReg;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_11 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_10)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_9);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_13 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_12)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_11);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_15 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_14)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSCRATCH_REG
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_13);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_16)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVAL_REG
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_15);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_19 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_18)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_WIRE
            : (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_21 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_20)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_WIRE
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_19);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_23 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_22)
            ? (QData)((IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h63fb53c5__0))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_21);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_25 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_24)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_23);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_112 
        = ((0x10U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_16
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_111);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_result 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_80 
        = ((0x10U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_16
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_79);
    VL_SHIFTL_WWI(95,95,6, __Vtemp_10, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_2, (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_5[0U] 
        = __Vtemp_10[0U];
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_5[1U] 
        = __Vtemp_10[1U];
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_5[2U] 
        = (0x7fffffffU & __Vtemp_10[2U]);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_31 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_19)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_21
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_30);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_20 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_quotient
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_19);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_17 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_4)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_10
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_16);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_113 
        = ((0x11U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_17
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_112);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_81 
        = ((0x11U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_17
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_80);
    VL_SUB_W(3, __Vtemp_12, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_dividend_T_4[0U] 
        = __Vtemp_12[0U];
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_dividend_T_4[1U] 
        = __Vtemp_12[1U];
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_dividend_T_4[2U] 
        = (0x7fffffffU & __Vtemp_12[2U]);
    nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_he71e7d91__0 
        = VL_GTE_W(3, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_32 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_16)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_18
            : (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_31)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_21 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_9
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__result 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_2)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_17);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_114 
        = ((0x12U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_18
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_113);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_82 
        = ((0x12U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_18
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_81);
    if (nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_he71e7d91__0) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_quotient_T_4;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_dividend_T_4[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_dividend_T_4[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_dividend_T_4[2U];
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_28;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[2U];
    }
    if ((0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_counter))) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_4 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0[2U];
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_4 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_28;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[2U];
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_33 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_14)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_15))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_22 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_hb36ceaa9__0)
            ? (IData)((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__result 
                       >> 0x20U)) : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_21);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_115 
        = ((0x13U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_19
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_114);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_83 
        = ((0x13U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_19
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_82);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_34 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_10)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_13))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_bits 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__result)
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_22);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_27 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_26)
            ? (QData)((IData)(__VdfgTmp_hea002d6a__0))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_25);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_29 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_28)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLE_REG))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_27);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_31 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_30)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLEH_REG))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_29);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_33 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_32)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRET_REG))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_31);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_35 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_34)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRETH_REG))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_37 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_36)
            ? (QData)((IData)(__VdfgTmp_hae267436__0))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_35);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_116 
        = ((0x14U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_20
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_115);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_84 
        = ((0x14U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_20
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_83);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_valid) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_11 = 0ULL;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__dividend;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[1U] = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[2U] = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_11 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_4;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3[2U];
    }
    if (nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT____VdfgTmp_h93af1d9c__0) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_13 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_8;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_16 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_11;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10[2U];
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_13 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_ready;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_16 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_28;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26[2U];
    }
    if (vlSelf->nucleusrv_soc_top__DOT__sys_rst) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_19 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_30 = 0ULL;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[0U] = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[1U] = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[2U] = 0U;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_19 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_6;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_30 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_16;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[0U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[0U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[1U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[1U];
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29[2U] 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15[2U];
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_35 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_7)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_9))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_34);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_output_bits 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_bits;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_3 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_valid)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_bits
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_39 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_38)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIME_REG))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_37);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_117 
        = ((0x15U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_21
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_116);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_85 
        = ((0x15U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_21
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_84);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_36 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_4)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_6))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_35);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_41 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_40)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIMEH_REG))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_39);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data 
        = (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_41);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_118 
        = ((0x16U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_22
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_117);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_86 
        = ((0x16U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_22
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_85);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_37 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_2)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_3))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_36);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_o_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_o_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_o_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_o_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_o_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__r_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_119 
        = ((0x17U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_23
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_118);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_87 
        = ((0x17U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_23
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_86);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_38 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T)
            ? (QData)((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_1))
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_37);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_120 
        = ((0x18U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_24
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_119);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_88 
        = ((0x18U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_24
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_87);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_result 
        = (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_38);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_121 
        = ((0x19U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_25
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_120);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_89 
        = ((0x19U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_25
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_88);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_result 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_result;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_5)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_result);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_122 
        = ((0x1aU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_26
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_121);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_90 
        = ((0x1aU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_26
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_89);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_2)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_123 
        = ((0x1bU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_27
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_122);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_91 
        = ((0x1bU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_27
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_90);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_result 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_addr_ex 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_addr_ex 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ALUresult 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_result 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_addr_ex 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ALUresult 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_124 
        = ((0x1cU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_28
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_123);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_92 
        = ((0x1cU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_28
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_91);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_125 
        = ((0x1dU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_29
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_124);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_93 
        = ((0x1dU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_29
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_92);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_126 
        = ((0x1eU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_30
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_125);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_94 
        = ((0x1eU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_30
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_93);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_127 
        = ((0x1fU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_31
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_126);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_95 
        = ((0x1fU == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_31
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_94);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___io_readData_1_T)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_127
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___io_readData_0_T)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_95
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readData_1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__readData2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_7)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_4
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readData_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_1 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_0);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_3)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_2
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_0);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_12 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_24)
            ? vlSelf->nucleusrv_soc_top__DOT__core_pin
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__readData2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_3 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_52
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_addr_id 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__readData1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_2 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id 
           != vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_23 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id 
           == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_10 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_16)
            ? vlSelf->nucleusrv_soc_top__DOT__core_pin
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_24 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex 
           == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_20)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_5 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1))
            ? vlSelf->nucleusrv_soc_top__DOT__core_pin
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_22) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_3 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_22) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_23));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_12)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_10);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_12 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_24)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_2));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isAMO) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_24));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_11 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_24)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_23));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_rd2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_7 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_csr_data
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_rd1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__input1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__j_offset 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_28)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___check_T_9 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1 
           >= vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2);
    if (nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT____VdfgTmp_h46ae23c6__0) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_15 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_12;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_13 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_24;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_14 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_11;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_15 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_4;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_13 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_6;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_14 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_3;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_9 
        = ((5U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_csr_data
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_3 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__j_offset 
           + vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_out);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_1 
        = ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3))
            ? (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1 
               < vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___check_T_9));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardEX 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_13));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardMEM 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_14));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_data 
        = ((6U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_csr_data
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_9);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_17 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_2 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_46)
            ? VL_GTES_III(32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_1));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_operandForwardEX 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardEX;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__forward_EX 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardEX;
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardMEM) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_operandForwardMEM = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__forward_MEM = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_6 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_operandForwardMEM = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__forward_MEM = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_6 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__readData2;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_16 
        = (((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardEX)) 
            & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardMEM)) 
               & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memRead) 
                  | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO) 
                     | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isAMO))))) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data 
        = ((0x4000U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm)
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_data);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcPlusOffset 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_1
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_17);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_3 
        = ((4U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3))
            ? VL_LTS_III(32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_2));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardEX) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData1 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_6;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_7;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_17 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex 
            == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_16));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_data 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___clear_data_T 
        = (~ vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__set_data 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data 
           | vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___w_data_T_1 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_opr))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data
            : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcPlusOffset 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcPlusOffset;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_4 
        = ((1U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3))
            ? (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1 
               != vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_3));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_readData1 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData1;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_readData2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_18 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO) 
            & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isAMO))
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_17)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_16));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__clear_data 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___clear_data_T 
           & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___w_data_T_3 
        = ((2U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_opr))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__set_data
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___w_data_T_1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__check 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3))
            ? (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1 
               == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__amo_stall 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_18));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
        = ((3U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_opr))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__clear_data
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___w_data_T_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_40)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_38) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_8 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_8 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_6;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_36) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_9 
            = (1U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_10 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 2U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_11 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_12 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_9 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_10 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_11 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_7;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_12 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_8;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_34) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_14 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_15 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_16 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_14 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_9;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_15 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_10;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_16 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_11;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_32) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_20 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_21 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_22 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_20 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_14;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_21 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_15;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_22 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_16;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_30) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_24 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_27 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_24 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_27 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_20;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_21;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_22;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_28) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_37 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_24;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_27;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_37 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_24) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_39 
            = (7U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_40 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_41 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_44 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_45 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_46 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_39 
            = (7U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_40 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_41 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_44 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_45 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_46 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_37;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_22) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_48 
            = (1U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_49 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 1U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_50 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 2U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_51 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 3U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_52 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 4U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_53 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_54 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_55 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_58 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_59 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_60 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_48 
            = (1U & (IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_49 
            = (1U & (IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_50 
            = (1U & (IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_51 
            = (1U & (IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_52 
            = (1U & (IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_53 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_39;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_54 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_40;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_55 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_41;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_58 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_44;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_59 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_45;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_60 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_46;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_26) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_62 
            = (1U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_63 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 1U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_64 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 2U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_65 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 3U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_66 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 4U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_67 
            = (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 5U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_68 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_69 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_72 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_73 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_74 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_62 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_48));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_63 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_49));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_64 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_50));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_65 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_51));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_66 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_52));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_67 
            = (7U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_53));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_68 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_54;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_69 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_55;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_72 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_58;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_73 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_59;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_74 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_60;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_20) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_76 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 0xbU));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_77 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 7U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_78 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 3U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_79 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_80 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_81 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_82 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_83 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_84 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_85 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_86 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_89 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_90 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_91 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_76 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_77 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_78 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_79 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_62;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_80 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_63;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_81 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_64;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_82 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_65;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_83 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_66;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_84 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_67;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_85 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_68;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_86 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_69;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_89 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_72;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_90 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_73;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_91 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_74;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_18) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_93 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 0xbU));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_94 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 7U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_95 
            = (1U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                     >> 3U));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_96 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_97 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_98 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_99 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_100 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_101 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_102 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_103 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_104 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_105 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_106 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_109 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_110 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_111 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_93 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MEIE_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_94 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MTIE_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_95 
            = (1U & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MSIE_REG));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_96 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_76;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_97 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_77;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_98 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_78;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_99 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_79;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_100 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_80;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_101 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_81;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_102 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_82;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_103 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_83;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_104 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_84;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_105 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_85;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_106 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_86;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_109 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_89;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_110 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_90;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_111 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_91;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_16) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_113 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_114 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MEIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_115 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MTIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_116 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MSIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_117 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_118 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_119 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_120 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_121 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_122 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_123 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_124 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_125 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_126 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_127 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_130 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_131 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_132 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_113 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVAL_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_114 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_93;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_115 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_94;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_116 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_95;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_117 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_96;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_118 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_97;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_119 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_98;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_120 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_99;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_121 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_100;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_122 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_101;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_123 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_102;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_124 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_103;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_125 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_104;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_126 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_105;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_127 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_106;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_130 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_109;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_131 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_110;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_132 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_111;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_14) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_134 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_135 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVAL_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_136 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MEIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_137 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MTIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_138 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MSIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_139 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_140 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_141 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_142 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_143 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_144 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_145 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_146 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_147 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_148 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_149 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_152 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_153 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_154 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_134 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSCRATCH_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_135 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_113;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_136 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_114;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_137 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_115;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_138 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_116;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_139 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_117;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_140 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_118;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_141 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_119;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_142 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_120;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_143 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_121;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_144 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_122;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_145 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_123;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_146 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_124;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_147 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_125;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_148 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_126;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_149 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_127;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_152 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_130;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_153 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_131;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_154 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_132;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__amo_stall)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_take_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_hdu_if_reg_write 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_hdu_pcWrite 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_hdu_pcWrite 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_hdu_if_reg_write 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_pc_write 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_take_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_take_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ctl_mux 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_pc_write 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ctl_mux 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_take_branch 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_17 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_2) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write));
    nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT____VdfgTmp_h1a4a4b1b__0 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write) 
           & (0x13U != vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_taken 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__check) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write) 
              & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_19 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_17));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_regWrite_0 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT____VdfgTmp_h1a4a4b1b__0) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_regWrite));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memWrite 
        = ((IData)(nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT____VdfgTmp_h1a4a4b1b__0) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memWrite));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_taken 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_taken;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_taken 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_taken;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_taken 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_taken;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_taken) 
           | (0U != (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_regWrite_0 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_regWrite_0;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_memWrite 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memWrite;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ifid_flush 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcSrc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ifid_flush 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ifid_flush 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired 
        = ((0U != vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ins) 
           & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush)) 
              & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_2) 
                 & ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_memToReg)) 
                    | (IData)(vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_stall 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_stall) 
              | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush) 
                 | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_stall))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_2) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_i_instr_retired 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_instr_retired 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MINSTRET_i_instr_retired 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_i_instr_retired 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_instr_retired 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRET_REG 
           + ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___T_3) 
              & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_17 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_34)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_12);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_32) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_23 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_18 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_23 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_17;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_18 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_30) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_25 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_23;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_25 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_18;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_28) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_38 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_38 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_25;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_24) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_47 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_42 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_47 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_38;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_42 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_22) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_61 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_56 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_61 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_47;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_56 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_42;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_26) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_75 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_70 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_75 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_61;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_70 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_56;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_20) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_92 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_87 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_92 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_75;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_87 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_70;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_18) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_112 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_107 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_112 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_92;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_107 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_87;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_16) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_133 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_128 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_133 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_112;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_128 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_107;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_14) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_155 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_150 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_155 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_133;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_150 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_128;
    }
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_12) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_156 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_157 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSCRATCH_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_158 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVAL_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_159 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MEIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_160 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MTIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_161 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MSIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_162 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_163 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_164 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_165 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_166 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_167 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_168 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_169 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_170 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_171 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_172 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_175 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_176 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_177 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_178 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_173 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_156 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_157 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_134;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_158 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_135;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_159 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_136;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_160 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_137;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_161 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_138;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_162 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_139;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_163 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_140;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_164 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_141;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_165 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_142;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_166 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_143;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_167 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_144;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_168 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_145;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_169 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_146;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_170 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_147;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_171 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_148;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_172 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_149;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_175 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_152;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_176 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_153;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_177 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_154;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_178 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_155;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_173 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_150;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5 
        = (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRETH_REG 
           + ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired) 
              & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___T_3) 
                 & (0U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRET_REG))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_13 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_34)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_19 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_32)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_13);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_26 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_30)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_19);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_28)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_26);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_43 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_24)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_57 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_22)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_43);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_71 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_26)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_57);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_88 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_20)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_71);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_108 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_18)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_88);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_129 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_16)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_108);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_151 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_14)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_129);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_174 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_12)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_151);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_10) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_179 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_180 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_181 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSCRATCH_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_182 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVAL_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_183 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MEIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_184 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MTIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_185 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MSIE_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_186 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_187 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_188 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_189 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h2361916d__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_190 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_hfc5a30bb__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_191 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h05c928b2__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_192 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h387f5c83__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_193 
            = nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT____VdfgTmp_h8e098bb6__0;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_194 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_195 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_196 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_199 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_200 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_201 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_202 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_197 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_198 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_179 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_180 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_156;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_181 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_157;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_182 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_158;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_183 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_159;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_184 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_160;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_185 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_161;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_186 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_162;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_187 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_163;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_188 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_164;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_189 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_165;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_190 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_166;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_191 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_167;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_192 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_168;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_193 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_169;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_194 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_170;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_195 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_171;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_196 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_172;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_199 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_175;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_200 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_176;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_201 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_177;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_202 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_178;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_197 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_173;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_198 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_174;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_stall 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_stall;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_1 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_stall)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_redirect 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_jmp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_3 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_jmp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_4 
        = ((0U == (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg)) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_1) 
              | (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__sys_rst))));
    vlSelf->nucleusrv_soc_top__DOT__imem_req_valid 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_1) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_5));
    vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_10) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__kill) 
              | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_1) 
                 | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_valid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrReq_valid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrReq_valid 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_valid 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__is_boot_imem)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__imem_req_valid));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemRsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrResp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrResp_ready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT____Vcellinp__u_icache__rsp_ready 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__imem_src_boot)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready));
    vlSelf->nucleusrv_soc_top__DOT__boot_imem_req_ready 
        = (1U & (~ ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready)) 
                    & (IData)(vlSelf->nucleusrv_soc_top__DOT__boot_imem_rsp_val))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_11 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__imem_rsp_valid));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_req_valid 
        = vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__accept 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_valid) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_ready));
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rsp_ready 
        = vlSelf->nucleusrv_soc_top__DOT____Vcellinp__u_icache__rsp_ready;
    vlSelf->nucleusrv_soc_top__DOT__imem_req_ready 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__is_boot_imem)
            ? (IData)(vlSelf->nucleusrv_soc_top__DOT__boot_imem_req_ready)
            : (IData)(vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_ready));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___GEN_0 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_11)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__kill));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_12 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_10) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_11));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid 
        = ((~ ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect) 
               | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__kill))) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_11));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_ready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrReq_ready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrReq_ready 
        = vlSelf->nucleusrv_soc_top__DOT__imem_req_ready;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_8 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__imem_req_ready) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__imem_req_valid));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___GEN_1 
        = (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_10) 
            & ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_11)) 
               & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect))) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___GEN_0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_14 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_12)
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_13));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_inst_valid 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__deliver 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_waiting 
        = ((~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid)) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_10));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__conc_instr 
        = ((((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid)
              ? ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid)
                  ? (0xffffU & vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata)
                  : 0U) : 0U) << 0x10U) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__lhw_reg));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_instruction 
            = vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata;
        nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT____VdfgTmp_h738a7907__0 
            = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid)
                ? (3U & (vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata 
                         >> 0x10U)) : 0U);
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_i 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_instruction;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_instruction = 0U;
        nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT____VdfgTmp_h738a7907__0 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_i = 0U;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_9 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__imem_req_valid) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_8));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_waiting 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_waiting;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_halt 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_stall) 
              | ((IData)(vlSelf->nucleusrv_soc_top__DOT__imem_req_valid) 
                 | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_waiting) 
                    | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_stall)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_instruction 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_instruction;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_1 
        = (0U == (IData)(nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT____VdfgTmp_h738a7907__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_3 
        = (1U == (IData)(nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT____VdfgTmp_h738a7907__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_5 
        = (2U == (IData)(nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT____VdfgTmp_h738a7907__0));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_15 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_9)
            ? 2U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_14));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_halt) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_halt = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_stall = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__halt = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_stall = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc4 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_halt = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_stall = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__halt = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_stall = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc4 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT___io_pc4_T_2;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT___io_pc2_T_2;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_i 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_i;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_reg_T 
        = (0U != vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_i);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__uh_is_comp 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_1) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_3) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_5)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__next_state 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_4)
            ? 1U : (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_15));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_pc4 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc4;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_pc2 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc2;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__stateReg) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_reg_T));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T_2 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__uh_is_comp)));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_misaligned_word = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__conc_sel = 1U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___io_ral_instruction_o_T_2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__conc_instr;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_misaligned_word = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__conc_sel = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___io_ral_instruction_o_T_2 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_i;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_nop_sel 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T) 
           & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri) 
              & ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T_2) 
                 & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_reg_T))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___io_ral_instruction_o_T_1 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T_2) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_nop_sel 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_nop_sel;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__nop_sel 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_nop_sel;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_22 
        = (1U & (~ (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_nop_sel)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_o 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___io_ral_instruction_o_T_1)
            ? 0x13U : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___io_ral_instruction_o_T_2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_23 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_22) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_17));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_i 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_o;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_o 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_o;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_instruction_i 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_o;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri)
            ? VL_SHIFTR_III(32,32,32, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_o, 0x10U)
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_o);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_5 
        = (0x10413U | ((0x3c000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x13U)) | 
                       ((0x3000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0xdU)) | 
                        ((0x800000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x12U)) | 
                         ((0x400000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x10U)) 
                          | (0x380U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 5U)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_12 
        = (0x42403U | ((0x4000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 0x15U)) | 
                       ((0x3800000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0xdU)) | 
                        ((0x400000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x10U)) | 
                         ((0x38000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 8U)) | (0x380U 
                                                  & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                     << 5U)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_134 
        = (0x1013U | ((0x1f00000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                     << 0x12U)) | (
                                                   (0xf8000U 
                                                    & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                       << 8U)) 
                                                   | (0xf80U 
                                                      & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_33 
        = (0xefU | ((0x80000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                    << 0x13U)) | ((0x40000000U 
                                                   & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                      << 0x16U)) 
                                                  | ((0x30000000U 
                                                      & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                         << 0x13U)) 
                                                     | ((0x8000000U 
                                                         & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                            << 0x15U)) 
                                                        | ((0x4000000U 
                                                            & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                               << 0x13U)) 
                                                           | ((0x2000000U 
                                                               & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                                  << 0x17U)) 
                                                              | ((0x1000000U 
                                                                  & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                                     << 0xdU)) 
                                                                 | ((0xe00000U 
                                                                     & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                                        << 0x12U)) 
                                                                    | ((0x100000U 
                                                                        & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                                           << 8U)) 
                                                                       | (((0x1000U 
                                                                            & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)
                                                                            ? 0xffU
                                                                            : 0U) 
                                                                          << 0xcU)))))))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_2 
        = (0x2023U | ((0x38000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                   << 8U)) | ((0xc00U 
                                               & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i) 
                                              | (0x200U 
                                                 & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                    << 3U)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_140 
        = (0x12003U | ((0xc000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 0x18U)) | 
                       ((0x2000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0xdU)) | 
                        ((0x1c00000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x12U)) 
                         | (0xf80U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_46 
        = (1U & (~ (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                    >> 0xfU)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_164 
        = (0x12023U | ((0xc000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 0x13U)) | 
                       ((0x2000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0xdU)) | 
                        ((0x1f00000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x12U)) 
                         | (0xe00U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_145 
        = (0x33U | ((0x1f00000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                   << 0x12U)) | (0xf80U 
                                                 & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_149 
        = (0x67U | (0xf8000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                << 8U)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_154 
        = (0x33U | ((0x1f00000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                   << 0x12U)) | ((0xf8000U 
                                                  & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                     << 8U)) 
                                                 | (0xf80U 
                                                    & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_158 
        = (0xe7U | (0xf8000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                << 8U)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_27 
        = ((6U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) | (7U == (7U & 
                                              (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                               >> 0xdU))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_90 
        = (0x40840433U | ((0x700000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x12U)) 
                          | ((0x38000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                          << 8U)) | 
                             (0x380U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_95 
        = (0x844433U | ((0x700000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 0x12U)) | 
                        ((0x38000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 8U)) | (0x380U 
                                                 & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_100 
        = (0x846433U | ((0x700000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 0x12U)) | 
                        ((0x38000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 8U)) | (0x380U 
                                                 & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_105 
        = (0x847433U | ((0x700000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 0x12U)) | 
                        ((0x38000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 8U)) | (0x380U 
                                                 & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_6 
        = (2U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                        >> 0xeU)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_11 
        = ((2U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 5U))) | (3U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                  >> 5U))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_37 
        = (0U != (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                           >> 2U)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_73 
        = (0x45413U | ((0x40000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x14U)) | 
                       ((0x1f00000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x12U)) | 
                        ((0x38000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                      << 8U)) | (0x380U 
                                                 & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_16 
        = (0x63U | ((0x1000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                >> 1U)) | ((0xc00U 
                                            & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i) 
                                           | ((0x300U 
                                               & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                  << 5U)) 
                                              | (0x80U 
                                                 & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                    >> 5U))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_3 
        = (0U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                        >> 0xeU)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_4 
        = (1U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                        >> 0xeU)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_5 
        = (3U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                        >> 0xeU)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___c_jal_imm_T_2 
        = ((0x1000U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)
            ? 0xfffffU : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__c_jal_imm 
        = ((vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___c_jal_imm_T_2 
            << 0xcU) | ((0x800U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                   >> 1U)) | ((0x400U 
                                               & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                  << 2U)) 
                                              | ((0x300U 
                                                  & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                     >> 1U)) 
                                                 | ((0x80U 
                                                     & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                        << 1U)) 
                                                    | ((0x40U 
                                                        & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                           >> 1U)) 
                                                       | ((0x20U 
                                                           & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                              << 3U)) 
                                                          | ((0x10U 
                                                              & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                                 >> 7U)) 
                                                             | (0xeU 
                                                                & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                                   >> 2U))))))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_20 
        = (0x840000U | ((0x4000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x15U)) | 
                        ((0x2000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0xdU)) | 
                         ((0x700000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x12U)) 
                          | vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_2))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_44 
        = ((0x1000U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)
            ? 0x1ffU : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_5 
        = (0x6fU | ((0x1000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                   << 0xdU)) | ((0xe00000U 
                                                 & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                    << 0x12U)) 
                                                | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_44) 
                                                    << 0xcU) 
                                                   | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_46) 
                                                      << 7U)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_44 
        = ((0U == (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                            >> 7U))) ? 0x100073U : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_158);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_57 
        = ((0x1000U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)
            ? 0x7fffU : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_60 
        = (0x37U | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_57) 
                     << 0x11U) | ((0x1f000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                               << 0xaU)) 
                                  | (0xf80U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_63 
        = ((0x1000U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)
            ? 7U : 0U);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_68 
        = (0x10113U | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_63) 
                        << 0x1dU) | ((0x18000000U & 
                                      (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x18U)) | 
                                     ((0x4000000U & 
                                       (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x15U)) 
                                      | ((0x2000000U 
                                          & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                             << 0x17U)) 
                                         | (0x1000000U 
                                            & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                               << 0x12U)))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_10 
        = ((3U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 5U))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_105
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_13 
        = ((1U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 5U))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_11));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_37) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_42 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_145;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_46 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_154;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_42 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_149;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_46 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_44;
    }
    if ((0x1000U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_108 = 0xfU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_23 = 0x3fU;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_48 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_46;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_108 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_23 = 0U;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_48 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_42;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_117 
        = (0x40000U | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_108) 
                        << 0x1cU) | ((0xc000000U & 
                                      (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x15U)) | 
                                     ((0x2000000U & 
                                       (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x17U)) 
                                      | ((0x38000U 
                                          & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                             << 8U)) 
                                         | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_16))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_28 
        = (0x13U | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_23) 
                     << 0x1aU) | ((0x2000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                 << 0xdU)) 
                                  | ((0x1f00000U & 
                                      (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x12U)) | 
                                     ((0xf8000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                   << 8U)) 
                                      | (0xf80U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_54 
        = (0x13U | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_23) 
                     << 0x1aU) | ((0x2000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                 << 0xdU)) 
                                  | ((0x1f00000U & 
                                      (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0x12U)) | 
                                     (0xf80U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_86 
        = (0x47413U | (((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_23) 
                        << 0x1aU) | ((0x2000000U & 
                                      (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                       << 0xdU)) | 
                                     ((0x1f00000U & 
                                       (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                        << 0x12U)) 
                                      | ((0x38000U 
                                          & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                             << 8U)) 
                                         | (0x380U 
                                            & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))))));
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_5) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_50 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_164;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_3 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_20;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_50 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_3 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_4 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_4) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_5));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_53 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_4) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_6) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_5)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_47 
        = ((0x80000000U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                           << 0x13U)) | ((0x40000000U 
                                          & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                             << 0x16U)) 
                                         | ((0x30000000U 
                                             & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                << 0x13U)) 
                                            | ((0x8000000U 
                                                & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                   << 0x15U)) 
                                               | ((0x4000000U 
                                                   & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                      << 0x13U)) 
                                                  | ((0x2000000U 
                                                      & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                                                         << 0x17U)) 
                                                     | vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_5))))));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_8 
        = ((2U == (0x1fU & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                            >> 7U))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_68
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_60);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_12 
        = ((2U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 5U))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_100
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_10);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_15 
        = ((0U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 5U))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_13));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_26 
        = ((7U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_117
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_3) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_4));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_55 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_3) 
           | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_53));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_14 
        = ((1U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 5U))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_95
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_17 
        = (IData)(((0xc00U == (0xc00U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)) 
                   & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_15)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_28 
        = ((6U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_117
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_26);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_4)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_12
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_52 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_6)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_48
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_50);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_54 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_4)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_140
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_52);
    if (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_3) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_5;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_56 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_134;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_7 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_5;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_56 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_54;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_16 
        = ((0U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 5U))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_90
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_14);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_19 
        = ((2U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xaU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_17));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_18 
        = ((3U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xaU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_16
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_21 
        = ((1U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xaU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_19));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_20 
        = ((2U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xaU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_86
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_18);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_23 
        = ((0U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xaU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_21));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_60 
        = ((2U == (3U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_56
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_22 
        = ((1U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xaU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_73
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_24 
        = ((0U == (3U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xaU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_73
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_22);
    if ((4U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                      >> 0xdU)))) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_29 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_23;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_30 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_24;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_29 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_27;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_30 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_28;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_31 
        = ((3U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_29));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_33 
        = ((2U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_31));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_32 
        = ((3U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_8
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_30);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_35 
        = ((5U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_33));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_34 
        = ((2U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_54
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_37 
        = ((1U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_35));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_36 
        = ((5U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_47
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_34);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_39 
        = ((0U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_37));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_38 
        = ((1U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_33
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_36);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_40 
        = ((0U == (7U & (vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i 
                         >> 0xdU))) ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_28
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_38);
    if ((1U == (3U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_61 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_39;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_62 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_40;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_61 
            = ((2U == (3U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)) 
               & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_55));
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_62 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_60;
    }
    if ((0U == (3U & vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i))) {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_63 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_6;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_64 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_7;
    } else {
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_63 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_61;
        vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_64 
            = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_62;
    }
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_is_comp 
        = ((0U != vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i) 
           & (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_63));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__is_comp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_is_comp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_is_comp 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_is_comp;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_5 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_is_comp) 
           | ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri) 
              | (IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word)));
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o 
        = ((0U == vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_6 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_5)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc2
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__instruction 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_instruction_o 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_7 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcPlusOffset
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_6);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_in 
        = ((IData)(vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__amo_stall)
            ? vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg
            : vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_in 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_in;
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__npc 
        = vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_in;
}

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_stl(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vnucleusrv_soc_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___eval_triggers__stl(Vnucleusrv_soc_top___024root* vlSelf);

VL_ATTR_COLD bool Vnucleusrv_soc_top___024root___eval_phase__stl(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vnucleusrv_soc_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vnucleusrv_soc_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__ico(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__act(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge hdmi_tx_clk_p)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge nucleusrv_soc_top.clk_tmds)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnucleusrv_soc_top___024root___dump_triggers__nba(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge hdmi_tx_clk_p)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge nucleusrv_soc_top.clk_tmds)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnucleusrv_soc_top___024root___ctor_var_reset(Vnucleusrv_soc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnucleusrv_soc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnucleusrv_soc_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->btn_rst = VL_RAND_RESET_I(1);
    vlSelf->uart_rxd = VL_RAND_RESET_I(1);
    vlSelf->uart_txd = VL_RAND_RESET_I(1);
    vlSelf->hdmi_tx_clk_p = VL_RAND_RESET_I(1);
    vlSelf->hdmi_tx_clk_n = VL_RAND_RESET_I(1);
    vlSelf->hdmi_tx_p = VL_RAND_RESET_I(3);
    vlSelf->hdmi_tx_n = VL_RAND_RESET_I(3);
    vlSelf->led = VL_RAND_RESET_I(4);
    vlSelf->btn = VL_RAND_RESET_I(4);
    vlSelf->sw = VL_RAND_RESET_I(3);
    vlSelf->DDR_addr = VL_RAND_RESET_I(15);
    vlSelf->DDR_ba = VL_RAND_RESET_I(3);
    vlSelf->DDR_cas_n = VL_RAND_RESET_I(1);
    vlSelf->DDR_ck_n = VL_RAND_RESET_I(1);
    vlSelf->DDR_ck_p = VL_RAND_RESET_I(1);
    vlSelf->DDR_cke = VL_RAND_RESET_I(1);
    vlSelf->DDR_cs_n = VL_RAND_RESET_I(1);
    vlSelf->DDR_dm = VL_RAND_RESET_I(4);
    vlSelf->DDR_dq = VL_RAND_RESET_I(32);
    vlSelf->DDR_dqs_n = VL_RAND_RESET_I(4);
    vlSelf->DDR_dqs_p = VL_RAND_RESET_I(4);
    vlSelf->DDR_odt = VL_RAND_RESET_I(1);
    vlSelf->DDR_ras_n = VL_RAND_RESET_I(1);
    vlSelf->DDR_reset_n = VL_RAND_RESET_I(1);
    vlSelf->DDR_we_n = VL_RAND_RESET_I(1);
    vlSelf->FIXED_IO_ddr_vrn = VL_RAND_RESET_I(1);
    vlSelf->FIXED_IO_ddr_vrp = VL_RAND_RESET_I(1);
    vlSelf->FIXED_IO_mio = VL_RAND_RESET_Q(54);
    vlSelf->FIXED_IO_ps_clk = VL_RAND_RESET_I(1);
    vlSelf->FIXED_IO_ps_porb = VL_RAND_RESET_I(1);
    vlSelf->FIXED_IO_ps_srstb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__btn_rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__uart_rxd = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__uart_txd = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_clk_p = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_clk_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_p = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__hdmi_tx_n = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__led = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__btn = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__sw = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__DDR_addr = VL_RAND_RESET_I(15);
    vlSelf->nucleusrv_soc_top__DOT__DDR_ba = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__DDR_cas_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_ck_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_ck_p = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_cke = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_cs_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_dm = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__DDR_dq = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__DDR_dqs_n = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__DDR_dqs_p = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__DDR_odt = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_ras_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_reset_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__DDR_we_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ddr_vrn = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ddr_vrp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_mio = VL_RAND_RESET_Q(54);
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_porb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__FIXED_IO_ps_srstb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__clk25MHz = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__clk_tmds = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__pll_locked = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__rst_sync = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__sys_rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__imem_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__imem_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__imem_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__core_pin = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__boot_ram[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->nucleusrv_soc_top__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__is_boot_imem = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__boot_imem_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__boot_imem_rsp_val = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__boot_imem_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_src_boot = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__icache_cpu_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__imem_axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT____Vcellinp__u_icache__rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s0_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s0_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s0_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s0_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s0_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s0_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s0_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s0_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s0_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__s1_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s1_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s1_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s1_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s1_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s1_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s1_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s1_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s1_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__s2_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s2_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s2_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s2_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s2_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s2_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s2_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s2_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s2_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__s3_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s3_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s3_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s3_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s3_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__s3_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s3_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s3_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__s3_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_bram_rsp_val = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__bram_word_addr = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_wlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__dmem_axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__hb_cnt = VL_RAND_RESET_I(25);
    vlSelf->nucleusrv_soc_top__DOT__led2_stretcher = VL_RAND_RESET_I(21);
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_in = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_tmds = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__locked = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__div_cnt = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_pll__DOT__clk_pixel_reg = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_pin = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_addrRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_dataRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_activeByteLane = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemReq_bits_isWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_dmemRsp_bits_dataResponse = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_addrRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_dataRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_activeByteLane = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemReq_bits_isWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemRsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemRsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__io_imemRsp_bits_dataResponse = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_address = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_instruction = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_redirect = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_waiting = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_inst_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrReq_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrReq_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrReq_bits_addrRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrResp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrResp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch_io_coreInstrResp_bits_dataResponse = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_id_instruction = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_writeReg = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcAddress = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_writeEnable_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_mem_read = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_id_ex_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_wb_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_wb_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_id_ex_regWr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_mem_regWr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Ex = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Mem = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Wb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Ex_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Mem_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_Wb_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_dmem_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_immediate = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_writeRegAddress = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_readData1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_readData2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_func7 = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_func3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_memWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_jump = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ctl_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_hdu_pcWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_hdu_if_reg_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_pcPlusOffset = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ifid_flush = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_i_instr_retired = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_csr_o_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_is_csr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_ex_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_mem_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_addr_ex = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_addr_mem = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode_io_is_comp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_immediate = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_readData2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_pcAddress = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_func7 = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_func3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_mem_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_wb_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ex_mem_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_mem_wb_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_id_ex_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ex_mem_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_mem_wb_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ctl_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_ALUresult = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_memData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_src2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_op_code = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute_io_amo_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_aluResultIn = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_writeEnable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readEnable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_readData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_f3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_addrRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_dataRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_activeByteLane = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmReq_bits_isWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmRsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_dccmRsp_bits_dataResponse = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM_io_amo_alu_result_in = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_set = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_clear = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_addrIn = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile_io_matchAddr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_in = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_halt = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_out = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_pc4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc_io_pc2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_address_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_jmp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_ral_instruction_o = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_addri = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_misaligned_word = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_misaligned_word_uh = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner_io_nop_sel = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_instruction_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_addri = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_is_comp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder_io_instruction_o = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_is_comp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_rd1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_rd2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_imm = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_wra = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f7 = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_f3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_memWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ctl_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_is_csr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_csr_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wd = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_wra = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_is_csr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_csr_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_rd = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_wra = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_is_csr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_csr_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_read_done = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__amo_old_value = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_issued = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__halt = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__instruction = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__is_comp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_6 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___npc_T_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__npc = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_17 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_18 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_19 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_22 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_23 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___ex_reg_ctl_regWrite_0_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_success = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_36 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_38 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_44 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___T_45 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_readEnable_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___MEM_io_writeEnable_T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_46 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_47 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_49 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_51 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_matched = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_53 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__sc_result = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___wb_data_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___wb_data_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_67 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT___GEN_69 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_address = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_instruction = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_redirect = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_waiting = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_inst_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrReq_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrReq_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrReq_bits_addrRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrResp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrResp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_coreInstrResp_bits_dataResponse = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_9 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_10 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_11 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_13 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_14 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___next_state_T_15 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__kill = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___GEN_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__deliver = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_id_instruction = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeReg = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcAddress = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_writeEnable_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_mem_read = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_id_ex_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_mem_wb_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_mem_wb_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_id_ex_regWr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_mem_regWr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Ex = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Mem = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Wb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Ex_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Mem_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_Wb_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_dmem_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_immediate = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_writeRegAddress = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_readData2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_func7 = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_func3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_memWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_jump = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ctl_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_hdu_pcWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_hdu_if_reg_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcPlusOffset = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ifid_flush = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_i_instr_retired = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_csr_o_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_csr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_ex_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_mem_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_addr_ex = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_addr_mem = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_is_comp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_instr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder_io_out_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_imm = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_o_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_opr = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_addr = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_w_en = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr_io_i_instr_retired = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrExecute = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelExecute = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrExecute = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrMemory = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelMemory = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrMemory = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_regWrWriteback = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rdSelWriteback = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrWrWriteback = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_rs1SelDecode = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_csrInstDecode = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_mem_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_taken = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_jump = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_id_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ex_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_mem_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_id = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_ex = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_addr_mem = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_pc_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ctl_mux = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_ifid_flush = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_take_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_operandForwardEX = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu_io_operandForwardMEM = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_in = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_memToReg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_regWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_memWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_jump = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control_io_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_0 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readAddress_1 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeEnable_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeAddress = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readData_0 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers_io_readData_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate_io_instruction = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate_io_out = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_funct3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_rd2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_take_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu_io_taken = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_ctl_memToReg_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registerRs1 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__readData1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__readData2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_6 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_ex = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_ex_mem = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__fwd_mem_wb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_16 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_10 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__input1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_20 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_24 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_12 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_28 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__j_offset = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_pcPlusOffset_T_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___GEN_17 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_46 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_47 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_48 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_51 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___io_stall_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___T_52 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT___csr_io_i_data_T_9 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_instr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__io_out_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT__funct5 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_1 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_3 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_5 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_7 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_9 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_10 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_11 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_13 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_14 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_15 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_16 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_17 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_19 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_20 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_22 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_23 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__atomicDecoder__DOT___GEN_24 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_imm = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_o_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_opr = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_addr = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_w_en = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__io_i_instr_retired = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MISA_i_value = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MHARTID_i_value = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MARCHID_i_value = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_opr = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_o_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_addr = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_w_en = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_except_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_nx = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_uf = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_of = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_dz = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_nv = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_FCSR_frm = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_MINSTRET_i_instr_retired = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MISA_i_value = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MHARTID_i_value = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MARCHID_i_value = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_opr = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_o_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_addr = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_CSR_i_w_en = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_except_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nx = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_uf = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_of = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_dz = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_nv = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_FCSR_frm = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__io_MINSTRET_i_instr_retired = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MISA_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MARCHID_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MHARTID_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCAUSE_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSCRATCH_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVAL_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLE_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCYCLEH_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRET_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MINSTRETH_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TSR_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TW_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TVM_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MXR_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SUM_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPRV_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPP_REG = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SPP_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPIE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_UBE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SPIE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MIE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_SIE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MEIE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MTIE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_MSIE_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MEIP_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MTIP_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_MSIP_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_CY_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_IR_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIME_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__TIMEH_REG = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_WIRE_hi = VL_RAND_RESET_I(23);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_WIRE = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_WIRE = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIP_WIRE = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCOUNTINHIBIT_WIRE = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FFLAGS_WIRE = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FRM_WIRE = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_WIRE = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MCYCLE_REG_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MCYCLEH_REG_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_0 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIME_REG_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___TIMEH_REG_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MINSTRET_REG_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___MINSTRETH_REG_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_9 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_10 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_11 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_13 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_14 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_15 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_16 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_18 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_19 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_20 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_21 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_22 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_23 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_24 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_25 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_26 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_27 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_28 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_29 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_30 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_31 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_32 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_33 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_34 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_35 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_36 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_37 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_38 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_39 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_40 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_41 = VL_RAND_RESET_Q(33);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__r_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__set_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___clear_data_T = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__clear_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___w_data_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___w_data_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_6 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_8 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_9 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_10 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_11 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_12 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_13 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_14 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_15 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_16 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_17 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_18 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_19 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_20 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_21 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_22 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_23 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_24 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_25 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_26 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_27 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_37 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_38 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_39 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_40 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_41 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_42 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_43 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_44 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_45 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_46 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_47 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_48 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_49 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_50 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_51 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_52 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_53 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_54 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_55 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_56 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_57 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_58 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_59 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_60 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_61 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_62 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_63 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_64 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_65 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_66 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_67 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_68 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_69 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_70 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_71 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_72 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_73 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_74 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_75 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_76 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_77 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_78 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_79 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_80 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_81 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_82 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_83 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_84 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_85 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_86 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_87 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_88 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_89 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_90 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_91 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_92 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_93 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_94 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_95 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_96 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_97 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_98 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_99 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_100 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_101 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_102 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_103 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_104 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_105 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_106 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_107 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_108 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_109 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_110 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_111 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_112 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_113 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_114 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_115 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_116 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_117 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_118 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_119 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_120 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_121 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_122 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_123 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_124 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_125 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_126 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_127 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_128 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_129 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_130 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_131 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_132 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_133 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_134 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_135 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_136 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_137 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_138 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_139 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_140 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_141 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_142 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_143 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_144 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_145 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_146 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_147 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_148 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_149 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_150 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_151 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_152 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_153 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_154 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_155 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_156 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_157 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_158 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_159 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_160 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_161 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_162 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_163 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_164 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_165 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_166 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_167 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_168 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_169 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_170 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_171 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_172 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_173 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_174 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_175 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_176 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_177 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_178 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_179 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_180 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_181 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_182 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_183 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_184 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_185 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_186 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_187 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_188 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_189 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_190 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_191 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_192 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_193 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_194 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_195 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_196 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_197 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_198 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_199 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_200 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_201 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_202 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_regWrExecute = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rdSelExecute = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrWrExecute = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_regWrMemory = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rdSelMemory = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrWrMemory = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_regWrWriteback = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rdSelWriteback = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrWrWriteback = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_rs1SelDecode = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_csrInstDecode = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__io_forwardRS1 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_9 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecMem = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_10 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecWb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecEx_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecMem_T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___csrHazard_DecWb_T_9 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecWb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_3 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_5 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_7 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csrController__DOT___io_forwardRS1_T_9 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ex_mem_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_taken = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_jump = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_id_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ex_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_mem_is_amo = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_addr_id = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_addr_ex = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_addr_mem = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_if_reg_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_pc_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ctl_mux = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_ifid_flush = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_take_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardEX = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__io_operandForwardMEM = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_22 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_23 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___T_24 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_11 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_13 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_14 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_15 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__forward_EX = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__forward_MEM = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_16 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_17 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT___GEN_18 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__hdu__DOT__amo_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_in = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memToReg = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_regWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memRead = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_memWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_jump = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT__io_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_9 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_11 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_13 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_15 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_17 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_19 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_20 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_21 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_23 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_24 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_25 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_34 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_35 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_36 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_37 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_39 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_40 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_41 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_42 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_43 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_44 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_45 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_46 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_47 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_48 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_49 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_57 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_58 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_65 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_66 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_67 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_68 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_69 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_70 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_72 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_73 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_83 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_84 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_85 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_101 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_102 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_103 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_104 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_105 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_106 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_107 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_108 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_109 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_121 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_128 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_129 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_130 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_131 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_132 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__control__DOT___signals_T_133 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readAddress_0 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readAddress_1 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_writeEnable_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_writeAddress = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_0 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__io_readData_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_0 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_6 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_8 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_9 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_10 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_11 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_12 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_13 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_14 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_15 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_16 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_17 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_18 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_19 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_20 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_21 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_22 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_23 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_24 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_25 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_26 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_27 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_28 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_29 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_30 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_31 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___io_readData_0_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_65 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_66 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_67 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_68 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_69 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_70 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_71 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_72 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_73 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_74 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_75 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_76 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_77 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_78 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_79 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_80 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_81 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_82 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_83 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_84 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_85 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_86 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_87 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_88 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_89 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_90 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_91 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_92 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_93 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_94 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_95 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___io_readData_1_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_97 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_98 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_99 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_100 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_101 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_102 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_103 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_104 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_105 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_106 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_107 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_108 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_109 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_110 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_111 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_112 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_113 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_114 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_115 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_116 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_117 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_118 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_119 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_120 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_121 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_122 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_123 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_124 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_125 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_126 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT___GEN_127 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_instruction = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__io_out = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___T_11 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_i = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_i_T_2 = VL_RAND_RESET_I(20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_u = VL_RAND_RESET_I(20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_u = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___T_16 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_s = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_s_T_2 = VL_RAND_RESET_I(20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_s = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_sb = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_sb_T_2 = VL_RAND_RESET_I(19);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_sb = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__imm_uj = VL_RAND_RESET_I(20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___ext_uj_T_2 = VL_RAND_RESET_I(11);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT__ext_uj = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_0 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_funct3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_rd1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_rd2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_take_branch = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__io_taken = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___check_T_9 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT___GEN_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__bu__DOT__check = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_immediate = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_readData1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_readData2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_pcAddress = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_func7 = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_func3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_mem_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_wb_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ex_mem_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_mem_wb_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_id_ex_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ex_mem_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_mem_wb_ins = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ctl_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ctl_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ctl_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_ALUresult = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_memData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_src2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_op_code = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__io_amo_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_input2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_aluCtl = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu_io_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_f3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl_io_out = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_memData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_src2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu_io_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_ex_reg_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_reg_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs1 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_reg_rs2 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_ex_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_mem_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_forwardA = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit_io_forwardB = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_a = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_src_b = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_op = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_output_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu_io_output_bits = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux1_T_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__inputMux1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___inputMux2_T_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__inputMux2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn1_T_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluIn1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___aluIn2_T_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluIn2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__src_a_reg = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__src_b_reg = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__op_reg = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__div_en = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__f7_reg = VL_RAND_RESET_I(6);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__counter = VL_RAND_RESET_I(6);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_23 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_6 = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___T_24 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___counter_T_1 = VL_RAND_RESET_I(6);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_11 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_15 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___io_ALUresult_T_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT___GEN_19 = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_input1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_input2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_aluCtl = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT__io_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_6 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_9 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_10 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_13 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_14 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_15 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_16 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___GEN_0 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_18 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_19 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_21 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_22 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_26 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_27 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_28 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_29 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_30 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_31 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_32 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_33 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_34 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_35 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_36 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_37 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__alu__DOT___io_result_T_38 = VL_RAND_RESET_Q(63);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_aluOp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_f7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_f3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT__io_out = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_0 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_1 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_2 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_3 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_4 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_5 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_6 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_7 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_8 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_9 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__aluCtl__DOT___GEN_10 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_memData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_src2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_amoOp = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT__io_result = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_6 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_8 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_10 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___io_result_T_12 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_0 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_6 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__amoAlu__DOT___GEN_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_ex_reg_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_mem_reg_rd = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_reg_rs1 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_reg_rs2 = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_ex_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_mem_regWrite_0 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardA = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT__io_forwardB = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_9 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___GEN_0 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_10 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_13 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_14 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_15 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_18 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___T_19 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__ForwardingUnit__DOT___GEN_2 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_src_a = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_src_b = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_op = VL_RAND_RESET_I(5);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__io_output_bits = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_3 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_6 = VL_RAND_RESET_Q(33);
    VL_RAND_RESET_W(65, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_7);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_10 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_11 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_15 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_16 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___result_T_17 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__result = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_counter = VL_RAND_RESET_I(6);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_dividend = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__r_quotient = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_u_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___is_div_rem_s_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___dividend_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__dividend = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___divisor_T_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT__divisor = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_4 = VL_RAND_RESET_I(6);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_2);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___T_5);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_26);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_dividend_T_4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_quotient_T_2 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_28 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___r_quotient_T_4 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_0);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_1 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_4 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_8 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_10);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_11 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_12 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_13 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_15);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_16 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_17 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_8 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_9 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_12 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___io_output_bits_T_13 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_18 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_19 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_20 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_21 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_22 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_23 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(95, vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_29);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Execute__DOT__mdu__DOT___GEN_30 = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_aluResultIn = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_writeData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_writeEnable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_readEnable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_readData = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_f3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isAMO = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isLR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_isSC = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_addrRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_activeByteLane = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmReq_bits_isWrite = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmRsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_dccmRsp_bits_dataResponse = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__io_amo_alu_result_in = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offset = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__offsetSW = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_7 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_8 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_2 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_3 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_4 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_5 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_6 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_7 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_8 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_9 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_10 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_11 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_12 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_13 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_14 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_15 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_16 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_17 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_18 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_19 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_20 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_21 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_22 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_23 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_24 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_25 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_26 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_27 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_28 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_29 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_30 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_31 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_0 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_1 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_2 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__wdata_3 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___writeDataFinal_T_1 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT__amo_transition_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_24 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_2 = VL_RAND_RESET_I(24);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_25 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_7 = VL_RAND_RESET_I(24);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_9 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___T_26 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_12 = VL_RAND_RESET_I(24);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_14 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_17 = VL_RAND_RESET_I(24);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_19 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_39 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_40 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_41 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_22 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_25 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_28 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_31 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_43 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_44 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_45 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_34 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_37 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_40 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_47 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_48 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_43 = VL_RAND_RESET_I(16);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_45 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_48 = VL_RAND_RESET_I(16);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_50 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_53 = VL_RAND_RESET_I(16);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___io_readData_T_55 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_50 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_51 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_53 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_54 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__MEM__DOT___GEN_55 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_set = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_clear = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_addrIn = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__io_matchAddr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__reservedValid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT__reservedAddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__ReservationFile__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_in = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_halt = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_out = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc4 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__io_pc2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT___io_pc4_T_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT___io_pc2_T_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_address_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_jmp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_stall = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_ral_instruction_o = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_addri = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_misaligned_word_uh = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__io_nop_sel = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__addri = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__uh_is_comp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___uh_is_comp_reg_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__lhw_reg = VL_RAND_RESET_I(16);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__stateReg = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___nop_sel_T_2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__nop_sel = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__conc_instr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___io_ral_instruction_o_T_1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT__conc_sel = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__Realigner__DOT___io_ral_instruction_o_T_2 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_addri = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_is_comp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__instruction_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_3 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_12 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_5 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_2 = VL_RAND_RESET_I(18);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_20 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_3 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_4 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_5 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_6 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_7 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_23 = VL_RAND_RESET_I(6);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_28 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___c_jal_imm_T_2 = VL_RAND_RESET_I(20);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__c_jal_imm = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_33 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_44 = VL_RAND_RESET_I(9);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_46 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_5 = VL_RAND_RESET_I(25);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_47 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_54 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_57 = VL_RAND_RESET_I(15);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_60 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_63 = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_68 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_8 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_73 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_86 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_90 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_95 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_100 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_105 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_10 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_11 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_12 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_13 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_14 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_15 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_16 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_17 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_18 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_19 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_20 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_21 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_22 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_23 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_24 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_108 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT__io_instruction_o_lo_16 = VL_RAND_RESET_I(15);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_117 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_26 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_27 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_28 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_29 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_30 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_31 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_32 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_33 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_34 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_35 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_36 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_37 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_38 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_39 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_40 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_134 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_140 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___T_37 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_145 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_149 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_42 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_154 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_158 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_44 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_46 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_48 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___io_instruction_o_T_164 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_50 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_52 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_53 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_54 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_55 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_56 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_60 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_61 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_62 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_63 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_core__DOT__CompressedDecoder__DOT___GEN_64 = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cpu_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__m_axi_rready = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__data_ram[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__tag_ram[__Vi0] = VL_RAND_RESET_I(14);
    }
    VL_RAND_RESET_W(512, vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__valid);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__resp_word = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_line = VL_RAND_RESET_I(9);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_word = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__s_tag = VL_RAND_RESET_I(14);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__accept = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_q = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__tag_q = VL_RAND_RESET_I(14);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__cmd_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_beat_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__mst_done = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__wr_idx_unused = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__rd_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_bready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awaddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_awcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__unused_wstrb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__cmd_len = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__wr_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__wr_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__wr_strb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rd_beat_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rd_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__rd_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__done = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__m_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__beat = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_icache__DOT__u_axi__DOT__len = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__m_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s0_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s1_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s2_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__s3_rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__addr_prefix = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__sel_target = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__active_target = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__read_pending = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_bus__DOT__slave_rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rxd = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__txd = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__btn_in = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__sw_in = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__cycle_cnt = VL_RAND_RESET_Q(64);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__ms_cnt = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__ms_subcnt = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_byte = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_start = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__tx_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rx_byte = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__rx_valid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_wr_ptr = VL_RAND_RESET_I(6);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_rd_ptr = VL_RAND_RESET_I(6);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_count = VL_RAND_RESET_I(7);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_full = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_peek = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__fifo_pop = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__bus_state = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__reg_offset = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__tx_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__tx_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__txd = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__clk_cnt = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_tx__DOT__data_buf = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rxd = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rx_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rxd_sync = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__rxd_clean = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__clk_cnt = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_periph__DOT__u_uart_rx__DOT__data_buf = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__cpu_clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__cpu_rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pixclk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__clk_tmds = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pix_rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_clk_p = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_clk_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_p = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hdmi_tx_n = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_init_i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__is_fb_addr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__is_pal_addr = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_word_addr = VL_RAND_RESET_I(14);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_write_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_idx_cpu = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__p_init = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bus_state = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__h_cnt = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__v_cnt = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_visible_window = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_window = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__x_screen = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__y_screen = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__x_doom = VL_RAND_RESET_I(9);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__y_doom = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_byte_addr = VL_RAND_RESET_I(16);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_word = VL_RAND_RESET_I(14);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_byte_sel = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__byte_sel_d1 = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_doom_d2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_vis_d1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__in_vis_d2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__hsync_d2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync_d1 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__vsync_d2 = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__fb_read_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pixel_index = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb = VL_RAND_RESET_I(24);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_r = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_g = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_b = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__pal_rgb_d2 = VL_RAND_RESET_I(24);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_r_d2 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_g_d2 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__bar_b_d2 = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__red_out = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__green_out = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__blue_out = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__clk_tmds = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__red = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__green = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__blue = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hsync = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__vsync = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__video_enable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_clk_p = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_clk_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_p = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__hdmi_tx_n = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_red = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_green = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__tmds_blue = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__pixclk_sync = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__mod10 = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__synced = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_load = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_red = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_green = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__shift_blue = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__clk_pixel_forwarded = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__video_data = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__control_data = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__video_enable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__tmds_out = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__Nb1s = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__XNOR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__q_m = VL_RAND_RESET_I(9);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_sign_eq = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__invert_q_m = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc_inc = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__balance_acc_new = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__TMDS_data = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_b__DOT__TMDS_code = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__video_data = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__control_data = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__video_enable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__tmds_out = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__Nb1s = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__XNOR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__q_m = VL_RAND_RESET_I(9);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_sign_eq = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__invert_q_m = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc_inc = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__balance_acc_new = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__TMDS_data = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_g__DOT__TMDS_code = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__video_data = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__control_data = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__video_enable = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__tmds_out = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__Nb1s = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__XNOR = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__q_m = VL_RAND_RESET_I(9);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_sign_eq = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__invert_q_m = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc_inc = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__balance_acc_new = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__TMDS_data = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_video__DOT__u_hdmi_tx__DOT__enc_r__DOT__TMDS_code = VL_RAND_RESET_I(10);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_addr = VL_RAND_RESET_I(15);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ba = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_cas_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ck_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ck_p = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_cke = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_cs_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dm = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dq = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dqs_n = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_dqs_p = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_odt = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_ras_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_reset_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__DDR_we_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ddr_vrn = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ddr_vrp = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_mio = VL_RAND_RESET_Q(54);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ps_clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ps_porb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__FIXED_IO_ps_srstb = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__clk_25mhz = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__reset_n = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awaddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awlock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awqos = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_awready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wstrb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_wready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_bready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arlock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arqos = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_dmem_rready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awaddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awlock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awqos = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_awready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wstrb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_wready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_bready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arlock = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arqos = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__s_axi_imem_rready = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16777216; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__dmem_rd_cnt = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__dmem_wr_cnt = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__imem_rd_cnt = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_st = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_cnt = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_len = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__d_have_aw = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_st = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_cnt = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__i_len = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__req_is_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rsp_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__m_axi_rready = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__data_ram[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__tag_ram[__Vi0] = VL_RAND_RESET_I(14);
    }
    VL_RAND_RESET_W(512, vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__valid);
    VL_RAND_RESET_W(512, vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__dirty);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_wmask = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__resp_word = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__victim_tag = VL_RAND_RESET_I(14);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wb_cnt = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__line_buf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_line = VL_RAND_RESET_I(9);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__s_word = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__accept = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__uncached = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_addr = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_q = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__tag_q = VL_RAND_RESET_I(14);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_beat_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__mst_done = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__rd_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__cmd_len = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_data_mux = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wr_strb_mux = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__we = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wa = VL_RAND_RESET_I(12);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wd = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__wm = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__lookup_hit_load = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_ready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_write = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_addr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__cmd_len = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__wr_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__wr_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__wr_strb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rd_beat_valid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rd_idx = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__rd_data = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__done = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arcache = VL_RAND_RESET_I(4);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arprot = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__m_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__beat = VL_RAND_RESET_I(3);
    vlSelf->nucleusrv_soc_top__DOT__u_dcache__DOT__u_axi__DOT__len = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__7__Vfuncout = VL_RAND_RESET_I(9);
    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__line_of__7__a = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__8__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__word_of__8__a = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__tag_of__10__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_nucleusrv_soc_top__DOT__u_dcache__DOT__tag_of__10__a = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__hdmi_tx_clk_p__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__nucleusrv_soc_top__DOT__clk_tmds__0 = VL_RAND_RESET_I(1);
}
