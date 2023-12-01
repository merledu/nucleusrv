// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"

#include "VTop___024root.h"

extern const VlWide<32>/*1023:0*/ VTop__ConstPool__CONST_hd6b7ba52_0;
extern const VlWide<32>/*1023:0*/ VTop__ConstPool__CONST_hcda40ff1_0;

VL_ATTR_COLD void VTop___024root___settle__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___settle__TOP__1\n"); );
    // Init
    CData/*0:0*/ Top__DOT__core__DOT__pc_io_halt;
    IData/*31:0*/ Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data;
    IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT___io_ALUresult_T;
    VlWide<4>/*127:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17;
    VlWide<4>/*127:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19;
    QData/*63:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_10;
    VlWide<4>/*127:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21;
    VlWide<4>/*127:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23;
    VlWide<32>/*1023:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31;
    VlWide<32>/*1023:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16;
    VlWide<32>/*1023:0*/ Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20;
    QData/*35:0*/ Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__avl;
    QData/*63:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result;
    VlWide<4>/*127:0*/ __Vtemp_h95f9a5e4__0;
    VlWide<4>/*127:0*/ __Vtemp_h95f9a5e4__1;
    VlWide<32>/*1023:0*/ __Vtemp_h6ce151dc__0;
    VlWide<3>/*95:0*/ __Vtemp_h0e28f7bf__0;
    VlWide<3>/*95:0*/ __Vtemp_h7b3947f2__0;
    VlWide<3>/*95:0*/ __Vtemp_h78e0dfe0__0;
    VlWide<3>/*95:0*/ __Vtemp_h46a27b2a__0;
    VlWide<3>/*95:0*/ __Vtemp_h9e4b3028__0;
    VlWide<3>/*95:0*/ __Vtemp_h794917ee__0;
    VlWide<3>/*95:0*/ __Vtemp_hb4e2a88c__0;
    VlWide<4>/*127:0*/ __Vtemp_hde7f3d12__0;
    VlWide<3>/*95:0*/ __Vtemp_h3febc88c__0;
    VlWide<3>/*95:0*/ __Vtemp_h25633e76__0;
    VlWide<4>/*127:0*/ __Vtemp_h1cf192d5__0;
    VlWide<3>/*95:0*/ __Vtemp_h08bfe934__0;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__0;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__1;
    VlWide<3>/*95:0*/ __Vtemp_h7c9a1e7c__0;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__2;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__3;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__4;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__5;
    VlWide<4>/*127:0*/ __Vtemp_h9669131c__0;
    VlWide<32>/*1023:0*/ __Vtemp_h69ad7b66__0;
    VlWide<32>/*1023:0*/ __Vtemp_h570d8b70__0;
    VlWide<32>/*1023:0*/ __Vtemp_hf12b2bb9__0;
    VlWide<32>/*1023:0*/ __Vtemp_h05c677de__0;
    // Body
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_taken 
        = ((((0U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                           >> 0xcU))) ? (vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd1 
                                         == vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd2)
              : ((1U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                               >> 0xcU))) ? (vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd1 
                                             != vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd2)
                  : ((4U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                   >> 0xcU))) ? VL_LTS_III(32, vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd1, vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd2)
                      : ((5U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                       >> 0xcU))) ? 
                         VL_GTES_III(32, vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd1, vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd2)
                          : ((6U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                           >> 0xcU)))
                              ? (vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd1 
                                 < vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd2)
                              : (vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd1 
                                 >= vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd2)))))) 
            & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_branch)) 
           & ((~ (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead) 
                   & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_branch)) 
                  & (((0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                >> 7U)) == (0x1fU & 
                                            (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                             >> 0xfU))) 
                     | ((0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                  >> 7U)) == (0x1fU 
                                              & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                 >> 0x14U)))))) 
              & (~ (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__hdu__DOT___T_14))));
    Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__avl 
        = ((0U != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rs1))
            ? (((QData)((IData)((0xfU & (- (IData)(
                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rs1_readdata 
                                                    >> 0x1fU)))))) 
                << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rs1_readdata)))
            : (((0U != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rd)) 
                & (0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rs1)))
                ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__valmax
                : (((QData)((IData)((0xfU & (- (IData)(
                                                       (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___avl_T_7 
                                                        >> 0x1fU)))))) 
                    << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___avl_T_7)))));
    vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid 
        = (1U & (~ ((IData)(vlSelf->reset) | (((IData)(vlSelf->Top__DOT__core__DOT__Execute_io_stall) 
                                               | (IData)(vlSelf->Top__DOT__core__DOT__IDecode_io_stall)) 
                                              | (IData)(vlSelf->Top__DOT__core__DOT__IF_stall)))));
    VL_EXTEND_WI(128,32, __Vtemp_h95f9a5e4__0, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_B);
    VL_EXTEND_WI(128,32, __Vtemp_h95f9a5e4__1, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_B);
    if ((0xbbU == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))) {
        if ((0U == (0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                             >> 7U)))) {
            __Vtemp_h6ce151dc__0[4U] = (- (IData)((
                                                   __Vtemp_h95f9a5e4__0[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[5U] = (- (IData)((
                                                   __Vtemp_h95f9a5e4__0[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[6U] = (- (IData)((
                                                   __Vtemp_h95f9a5e4__0[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[7U] = (- (IData)((
                                                   __Vtemp_h95f9a5e4__0[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[8U] = (- (IData)((
                                                   __Vtemp_h95f9a5e4__0[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[9U] = (- (IData)((
                                                   __Vtemp_h95f9a5e4__0[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xaU] = (- (IData)(
                                                    (__Vtemp_h95f9a5e4__0[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xbU] = (- (IData)(
                                                    (__Vtemp_h95f9a5e4__0[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xcU] = (- (IData)(
                                                    (__Vtemp_h95f9a5e4__0[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xdU] = (- (IData)(
                                                    (__Vtemp_h95f9a5e4__0[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xeU] = (- (IData)(
                                                    (__Vtemp_h95f9a5e4__0[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xfU] = (- (IData)(
                                                    (__Vtemp_h95f9a5e4__0[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (__Vtemp_h95f9a5e4__0[3U] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = __Vtemp_h95f9a5e4__1[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = __Vtemp_h95f9a5e4__1[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = __Vtemp_h95f9a5e4__1[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = __Vtemp_h95f9a5e4__1[3U];
        } else if ((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h6ce151dc__0[4U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[5U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[6U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[7U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[8U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[9U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xaU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xbU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xcU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xdU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xeU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xfU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35[3U];
        } else if ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h6ce151dc__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[4U];
            __Vtemp_h6ce151dc__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[5U];
            __Vtemp_h6ce151dc__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[6U];
            __Vtemp_h6ce151dc__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U];
            __Vtemp_h6ce151dc__0[8U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[9U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xaU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xbU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xcU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xdU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xeU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xfU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[7U] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37[3U];
        } else if ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h6ce151dc__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[4U];
            __Vtemp_h6ce151dc__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[5U];
            __Vtemp_h6ce151dc__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[6U];
            __Vtemp_h6ce151dc__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[7U];
            __Vtemp_h6ce151dc__0[8U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[8U];
            __Vtemp_h6ce151dc__0[9U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[9U];
            __Vtemp_h6ce151dc__0[0xaU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0xaU];
            __Vtemp_h6ce151dc__0[0xbU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0xbU];
            __Vtemp_h6ce151dc__0[0xcU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0xcU];
            __Vtemp_h6ce151dc__0[0xdU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0xdU];
            __Vtemp_h6ce151dc__0[0xeU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0xeU];
            __Vtemp_h6ce151dc__0[0xfU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0xfU];
            __Vtemp_h6ce151dc__0[0x10U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x10U];
            __Vtemp_h6ce151dc__0[0x11U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x11U];
            __Vtemp_h6ce151dc__0[0x12U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x12U];
            __Vtemp_h6ce151dc__0[0x13U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x13U];
            __Vtemp_h6ce151dc__0[0x14U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x14U];
            __Vtemp_h6ce151dc__0[0x15U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x15U];
            __Vtemp_h6ce151dc__0[0x16U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x16U];
            __Vtemp_h6ce151dc__0[0x17U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x17U];
            __Vtemp_h6ce151dc__0[0x18U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x18U];
            __Vtemp_h6ce151dc__0[0x19U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x19U];
            __Vtemp_h6ce151dc__0[0x1aU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x1aU];
            __Vtemp_h6ce151dc__0[0x1bU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x1bU];
            __Vtemp_h6ce151dc__0[0x1cU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x1cU];
            __Vtemp_h6ce151dc__0[0x1dU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x1dU];
            __Vtemp_h6ce151dc__0[0x1eU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x1eU];
            __Vtemp_h6ce151dc__0[0x1fU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0x1fU];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39[3U];
        } else {
            __Vtemp_h6ce151dc__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[4U];
            __Vtemp_h6ce151dc__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[5U];
            __Vtemp_h6ce151dc__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[6U];
            __Vtemp_h6ce151dc__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[7U];
            __Vtemp_h6ce151dc__0[8U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[8U];
            __Vtemp_h6ce151dc__0[9U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[9U];
            __Vtemp_h6ce151dc__0[0xaU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xaU];
            __Vtemp_h6ce151dc__0[0xbU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xbU];
            __Vtemp_h6ce151dc__0[0xcU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xcU];
            __Vtemp_h6ce151dc__0[0xdU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xdU];
            __Vtemp_h6ce151dc__0[0xeU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xeU];
            __Vtemp_h6ce151dc__0[0xfU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU];
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0xfU] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5[3U];
        }
    } else if ((0xb8U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))) {
        if ((0U == (0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                             >> 7U)))) {
            __Vtemp_h6ce151dc__0[4U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[5U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[6U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[7U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[8U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[9U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xaU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xbU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xcU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xdU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xeU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xfU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1[3U];
        } else if ((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h6ce151dc__0[4U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[5U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[6U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[7U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[8U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[9U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xaU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xbU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xcU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xdU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xeU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xfU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43[3U];
        } else if ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h6ce151dc__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[4U];
            __Vtemp_h6ce151dc__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[5U];
            __Vtemp_h6ce151dc__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[6U];
            __Vtemp_h6ce151dc__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U];
            __Vtemp_h6ce151dc__0[8U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[9U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                   >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xaU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xbU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xcU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xdU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xeU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0xfU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[7U] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45[3U];
        } else if ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h6ce151dc__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[4U];
            __Vtemp_h6ce151dc__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[5U];
            __Vtemp_h6ce151dc__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[6U];
            __Vtemp_h6ce151dc__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[7U];
            __Vtemp_h6ce151dc__0[8U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[8U];
            __Vtemp_h6ce151dc__0[9U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[9U];
            __Vtemp_h6ce151dc__0[0xaU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0xaU];
            __Vtemp_h6ce151dc__0[0xbU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0xbU];
            __Vtemp_h6ce151dc__0[0xcU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0xcU];
            __Vtemp_h6ce151dc__0[0xdU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0xdU];
            __Vtemp_h6ce151dc__0[0xeU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0xeU];
            __Vtemp_h6ce151dc__0[0xfU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0xfU];
            __Vtemp_h6ce151dc__0[0x10U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x10U];
            __Vtemp_h6ce151dc__0[0x11U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x11U];
            __Vtemp_h6ce151dc__0[0x12U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x12U];
            __Vtemp_h6ce151dc__0[0x13U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x13U];
            __Vtemp_h6ce151dc__0[0x14U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x14U];
            __Vtemp_h6ce151dc__0[0x15U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x15U];
            __Vtemp_h6ce151dc__0[0x16U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x16U];
            __Vtemp_h6ce151dc__0[0x17U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x17U];
            __Vtemp_h6ce151dc__0[0x18U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x18U];
            __Vtemp_h6ce151dc__0[0x19U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x19U];
            __Vtemp_h6ce151dc__0[0x1aU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x1aU];
            __Vtemp_h6ce151dc__0[0x1bU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x1bU];
            __Vtemp_h6ce151dc__0[0x1cU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x1cU];
            __Vtemp_h6ce151dc__0[0x1dU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x1dU];
            __Vtemp_h6ce151dc__0[0x1eU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x1eU];
            __Vtemp_h6ce151dc__0[0x1fU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0x1fU];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47[3U];
        } else {
            __Vtemp_h6ce151dc__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[4U];
            __Vtemp_h6ce151dc__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[5U];
            __Vtemp_h6ce151dc__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[6U];
            __Vtemp_h6ce151dc__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[7U];
            __Vtemp_h6ce151dc__0[8U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[8U];
            __Vtemp_h6ce151dc__0[9U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[9U];
            __Vtemp_h6ce151dc__0[0xaU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xaU];
            __Vtemp_h6ce151dc__0[0xbU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xbU];
            __Vtemp_h6ce151dc__0[0xcU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xcU];
            __Vtemp_h6ce151dc__0[0xdU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xdU];
            __Vtemp_h6ce151dc__0[0xeU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xeU];
            __Vtemp_h6ce151dc__0[0xfU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU];
            __Vtemp_h6ce151dc__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h6ce151dc__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0xfU] 
                                                      >> 0x1fU)));
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[0U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[1U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[2U];
            Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
                = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10[3U];
        }
    } else {
        __Vtemp_h6ce151dc__0[4U] = VTop__ConstPool__CONST_hd6b7ba52_0[4U];
        __Vtemp_h6ce151dc__0[5U] = VTop__ConstPool__CONST_hd6b7ba52_0[5U];
        __Vtemp_h6ce151dc__0[6U] = VTop__ConstPool__CONST_hd6b7ba52_0[6U];
        __Vtemp_h6ce151dc__0[7U] = VTop__ConstPool__CONST_hd6b7ba52_0[7U];
        __Vtemp_h6ce151dc__0[8U] = VTop__ConstPool__CONST_hd6b7ba52_0[8U];
        __Vtemp_h6ce151dc__0[9U] = VTop__ConstPool__CONST_hd6b7ba52_0[9U];
        __Vtemp_h6ce151dc__0[0xaU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xaU];
        __Vtemp_h6ce151dc__0[0xbU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xbU];
        __Vtemp_h6ce151dc__0[0xcU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xcU];
        __Vtemp_h6ce151dc__0[0xdU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xdU];
        __Vtemp_h6ce151dc__0[0xeU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xeU];
        __Vtemp_h6ce151dc__0[0xfU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xfU];
        __Vtemp_h6ce151dc__0[0x10U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x10U];
        __Vtemp_h6ce151dc__0[0x11U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x11U];
        __Vtemp_h6ce151dc__0[0x12U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x12U];
        __Vtemp_h6ce151dc__0[0x13U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x13U];
        __Vtemp_h6ce151dc__0[0x14U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x14U];
        __Vtemp_h6ce151dc__0[0x15U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x15U];
        __Vtemp_h6ce151dc__0[0x16U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x16U];
        __Vtemp_h6ce151dc__0[0x17U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x17U];
        __Vtemp_h6ce151dc__0[0x18U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x18U];
        __Vtemp_h6ce151dc__0[0x19U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x19U];
        __Vtemp_h6ce151dc__0[0x1aU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1aU];
        __Vtemp_h6ce151dc__0[0x1bU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1bU];
        __Vtemp_h6ce151dc__0[0x1cU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1cU];
        __Vtemp_h6ce151dc__0[0x1dU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1dU];
        __Vtemp_h6ce151dc__0[0x1eU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1eU];
        __Vtemp_h6ce151dc__0[0x1fU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1fU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U] 
            = VTop__ConstPool__CONST_hd6b7ba52_0[0U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U] 
            = VTop__ConstPool__CONST_hd6b7ba52_0[1U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U] 
            = VTop__ConstPool__CONST_hd6b7ba52_0[2U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U] 
            = VTop__ConstPool__CONST_hd6b7ba52_0[3U];
    }
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[4U] 
        = __Vtemp_h6ce151dc__0[4U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[5U] 
        = __Vtemp_h6ce151dc__0[5U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[6U] 
        = __Vtemp_h6ce151dc__0[6U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[7U] 
        = __Vtemp_h6ce151dc__0[7U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[8U] 
        = __Vtemp_h6ce151dc__0[8U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[9U] 
        = __Vtemp_h6ce151dc__0[9U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xaU] 
        = __Vtemp_h6ce151dc__0[0xaU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xbU] 
        = __Vtemp_h6ce151dc__0[0xbU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xcU] 
        = __Vtemp_h6ce151dc__0[0xcU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xdU] 
        = __Vtemp_h6ce151dc__0[0xdU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xeU] 
        = __Vtemp_h6ce151dc__0[0xeU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xfU] 
        = __Vtemp_h6ce151dc__0[0xfU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x10U] 
        = __Vtemp_h6ce151dc__0[0x10U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x11U] 
        = __Vtemp_h6ce151dc__0[0x11U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x12U] 
        = __Vtemp_h6ce151dc__0[0x12U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x13U] 
        = __Vtemp_h6ce151dc__0[0x13U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x14U] 
        = __Vtemp_h6ce151dc__0[0x14U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x15U] 
        = __Vtemp_h6ce151dc__0[0x15U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x16U] 
        = __Vtemp_h6ce151dc__0[0x16U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x17U] 
        = __Vtemp_h6ce151dc__0[0x17U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x18U] 
        = __Vtemp_h6ce151dc__0[0x18U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x19U] 
        = __Vtemp_h6ce151dc__0[0x19U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1aU] 
        = __Vtemp_h6ce151dc__0[0x1aU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1bU] 
        = __Vtemp_h6ce151dc__0[0x1bU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1cU] 
        = __Vtemp_h6ce151dc__0[0x1cU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1dU] 
        = __Vtemp_h6ce151dc__0[0x1dU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1eU] 
        = __Vtemp_h6ce151dc__0[0x1eU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1fU] 
        = __Vtemp_h6ce151dc__0[0x1fU];
    VL_EXTEND_WI(95,32, __Vtemp_h0e28f7bf__0, (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b 
                                                   >> 0x1fU))
                                                ? (- vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b)
                                                : vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b));
    VL_SHIFTL_WWI(95,95,6, __Vtemp_h7b3947f2__0, __Vtemp_h0e28f7bf__0, 
                  (0x3fU & ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter) 
                            - (IData)(1U))));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5[0U] 
        = __Vtemp_h7b3947f2__0[0U];
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5[1U] 
        = __Vtemp_h7b3947f2__0[1U];
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5[2U] 
        = (0x7fffffffU & __Vtemp_h7b3947f2__0[2U]);
    VL_EXTENDS_WI(65,32, __Vtemp_h78e0dfe0__0, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a);
    __Vtemp_h46a27b2a__0[0U] = __Vtemp_h78e0dfe0__0[0U];
    __Vtemp_h46a27b2a__0[1U] = __Vtemp_h78e0dfe0__0[1U];
    __Vtemp_h46a27b2a__0[2U] = (1U & __Vtemp_h78e0dfe0__0[2U]);
    VL_EXTENDS_WQ(65,33, __Vtemp_h9e4b3028__0, (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b)));
    __Vtemp_h794917ee__0[0U] = __Vtemp_h9e4b3028__0[0U];
    __Vtemp_h794917ee__0[1U] = __Vtemp_h9e4b3028__0[1U];
    __Vtemp_h794917ee__0[2U] = (1U & __Vtemp_h9e4b3028__0[2U]);
    VL_MULS_WWW(65, __Vtemp_hb4e2a88c__0, __Vtemp_h46a27b2a__0, __Vtemp_h794917ee__0);
    Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result 
        = (((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38)) 
            | (3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38)))
            ? ((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a)) 
               * (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b)))
            : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))
                ? (((QData)((IData)(__Vtemp_hb4e2a88c__0[1U])) 
                    << 0x20U) | (QData)((IData)(__Vtemp_hb4e2a88c__0[0U])))
                : ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))
                    ? VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a), 
                                  VL_EXTENDS_QI(64,32, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b))
                    : 0ULL)));
    __Vtemp_hde7f3d12__0[0U] = (IData)(((0U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                         ? (((QData)((IData)(
                                                             vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U])))
                                         : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3)
                                             ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_9)
                                                 ? 
                                                (((QData)((IData)(
                                                                  vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U])))
                                                 : 
                                                ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_15)
                                                  ? 0xffffffffffffffffULL
                                                  : 
                                                 ((0x3cU 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                   ? 
                                                  (VL_GTES_IQQ(64, (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)), 
                                                               (((QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                    ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                   : 
                                                  ((0x34U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                    ? 
                                                   (((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)) 
                                                     >= 
                                                     (((QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                     ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                     : 
                                                    (((QData)((IData)(
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                    : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3178))))
                                             : 0xffffffffffffffffULL)));
    __Vtemp_hde7f3d12__0[1U] = (IData)((((0U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                          ? (((QData)((IData)(
                                                              vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U])))
                                          : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3)
                                              ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_9)
                                                  ? 
                                                 (((QData)((IData)(
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U])))
                                                  : 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_15)
                                                   ? 0xffffffffffffffffULL
                                                   : 
                                                  ((0x3cU 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                    ? 
                                                   (VL_GTES_IQQ(64, (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)), 
                                                                (((QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                                  << 0x20U) 
                                                                 | (QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                     ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                     : 
                                                    (((QData)((IData)(
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                    : 
                                                   ((0x34U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                     ? 
                                                    (((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)) 
                                                      >= 
                                                      (((QData)((IData)(
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                      ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                      : 
                                                     (((QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))))
                                                     : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3178))))
                                              : 0xffffffffffffffffULL)) 
                                        >> 0x20U));
    __Vtemp_hde7f3d12__0[2U] = (IData)(((1U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                         ? (((QData)((IData)(
                                                             vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                                         : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_60)
                                             ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_66)
                                                 ? 
                                                (((QData)((IData)(
                                                                  vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                                                 : 
                                                ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_72)
                                                  ? 0xffffffffffffffffULL
                                                  : 
                                                 ((0x3cU 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                   ? 
                                                  (VL_GTES_IQQ(64, (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)), 
                                                               (((QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                    ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                   : 
                                                  ((0x34U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                    ? 
                                                   (((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)) 
                                                     >= 
                                                     (((QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                     ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                     : 
                                                    (((QData)((IData)(
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                    : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3250))))
                                             : (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                 & (1U 
                                                    > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                 ? 
                                                (((QData)((IData)(
                                                                  vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                                                 : 0xffffffffffffffffULL))));
    __Vtemp_hde7f3d12__0[3U] = (IData)((((1U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                          ? (((QData)((IData)(
                                                              vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                                          : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_60)
                                              ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_66)
                                                  ? 
                                                 (((QData)((IData)(
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                                                  : 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_72)
                                                   ? 0xffffffffffffffffULL
                                                   : 
                                                  ((0x3cU 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                    ? 
                                                   (VL_GTES_IQQ(64, (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)), 
                                                                (((QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                                  << 0x20U) 
                                                                 | (QData)((IData)(
                                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                     ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                     : 
                                                    (((QData)((IData)(
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                    : 
                                                   ((0x34U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                     ? 
                                                    (((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)) 
                                                      >= 
                                                      (((QData)((IData)(
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                      ? (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A))
                                                      : 
                                                     (((QData)((IData)(
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))))
                                                     : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3250))))
                                              : (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                  & (1U 
                                                     > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                  ? 
                                                 (((QData)((IData)(
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                                                  : 0xffffffffffffffffULL))) 
                                        >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[0U] 
        = __Vtemp_hde7f3d12__0[0U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[1U] 
        = __Vtemp_hde7f3d12__0[1U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[2U] 
        = __Vtemp_hde7f3d12__0[2U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
        = __Vtemp_hde7f3d12__0[3U];
    __Vtemp_h3febc88c__0[1U] = (IData)((((QData)((IData)(
                                                         ((3U 
                                                           < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                           ? 
                                                          vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                           : 
                                                          ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_288)
                                                            ? 
                                                           ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_294)
                                                             ? 
                                                            vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_300)
                                                              ? 0xffffffffU
                                                              : 
                                                             ((0x3cU 
                                                               == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                               ? 
                                                              (VL_GTES_III(32, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A, 
                                                                           vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                : 
                                                               vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                               : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3540)))
                                                            : 
                                                           (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                             & (3U 
                                                                > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                             ? 
                                                            vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                             : 0xffffffffU))))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((2U 
                                                            < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                            ? 
                                                           vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                            : 
                                                           ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_231)
                                                             ? 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_237)
                                                              ? 
                                                             vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_243)
                                                               ? 0xffffffffU
                                                               : 
                                                              ((0x3cU 
                                                                == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                ? 
                                                               (VL_GTES_III(32, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A, 
                                                                            vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                 ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                 : 
                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3468)))
                                                             : 
                                                            (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                              & (2U 
                                                                 > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                              ? 
                                                             vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                              : 0xffffffffU)))))));
    __Vtemp_h3febc88c__0[2U] = (IData)(((((QData)((IData)(
                                                          ((3U 
                                                            < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                            ? 
                                                           vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                            : 
                                                           ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_288)
                                                             ? 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_294)
                                                              ? 
                                                             vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_300)
                                                               ? 0xffffffffU
                                                               : 
                                                              ((0x3cU 
                                                                == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                ? 
                                                               (VL_GTES_III(32, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A, 
                                                                            vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                 ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                 : 
                                                                vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3540)))
                                                             : 
                                                            (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                              & (3U 
                                                                 > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                              ? 
                                                             vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                              : 0xffffffffU))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           ((2U 
                                                             < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                             ? 
                                                            vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_231)
                                                              ? 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_237)
                                                               ? 
                                                              vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                               : 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_243)
                                                                ? 0xffffffffU
                                                                : 
                                                               ((0x3cU 
                                                                 == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                 ? 
                                                                (VL_GTES_III(32, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A, 
                                                                             vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                  ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                  : 
                                                                 vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                 : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3468)))
                                                              : 
                                                             (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                               & (2U 
                                                                  > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                               ? 
                                                              vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                               : 0xffffffffU)))))) 
                                        >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[0U] 
        = ((0U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
            ? vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U]
            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3)
                ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_9)
                    ? vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U]
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_15)
                        ? 0xffffffffU : ((0x3cU == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                          ? (VL_GTES_III(32, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A, 
                                                         vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                              : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                          : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3324)))
                : 0xffffffffU));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[1U] 
        = ((1U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
            ? vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_60)
                ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_66)
                    ? vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_72)
                        ? 0xffffffffU : ((0x3cU == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                          ? (VL_GTES_III(32, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A, 
                                                         vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                              : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                          : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3396)))
                : (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                    & (1U > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                    ? vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                    : 0xffffffffU)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[2U] 
        = __Vtemp_h3febc88c__0[1U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
        = __Vtemp_h3febc88c__0[2U];
    __Vtemp_h25633e76__0[0U] = ((((3U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                   ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                       << 0x10U) | 
                                      (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                       >> 0x10U)) : 
                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_288)
                                    ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_294)
                                        ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                            << 0x10U) 
                                           | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                              >> 0x10U))
                                        : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_300)
                                            ? 0xffffU
                                            : ((0x3cU 
                                                == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                ? (
                                                   VL_GTES_III(16, 
                                                               (0xffffU 
                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                               (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                >> 0x10U))
                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                    : 
                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                     << 0x10U) 
                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                       >> 0x10U)))
                                                : (
                                                   (0x34U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                    ? 
                                                   (((0xffffU 
                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                     >= 
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                      >> 0x10U))
                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                     : 
                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                      << 0x10U) 
                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                        >> 0x10U)))
                                                    : 
                                                   ((0x2cU 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                     ? 
                                                    (VL_LTES_III(16, 
                                                                 (0xffffU 
                                                                  & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                 (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                  >> 0x10U))
                                                      ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                      : 
                                                     ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                       << 0x10U) 
                                                      | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                         >> 0x10U)))
                                                     : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4976))))))
                                    : (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                        & (3U > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                        ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                            << 0x10U) 
                                           | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                              >> 0x10U))
                                        : 0xffffU))) 
                                 << 0x10U) | (0xffffU 
                                              & ((2U 
                                                  < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                  ? 
                                                 vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                                                  : 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_231)
                                                   ? 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_237)
                                                    ? 
                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                                                    : 
                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_243)
                                                     ? 0xffffU
                                                     : 
                                                    ((0x3cU 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                      ? 
                                                     (VL_GTES_III(16, 
                                                                  (0xffffU 
                                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                  (0xffffU 
                                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U]))
                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                       : 
                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                                      : 
                                                     ((0x34U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                       ? 
                                                      (((0xffffU 
                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                        >= 
                                                        (0xffffU 
                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U]))
                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                        : 
                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                                       : 
                                                      ((0x2cU 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                        ? 
                                                       (VL_LTES_III(16, 
                                                                    (0xffffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                    (0xffffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U]))
                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                         : 
                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                                        : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4904))))))
                                                   : 
                                                  (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                    & (2U 
                                                       > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                    ? 
                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                                                    : 0xffffU)))));
    __Vtemp_h25633e76__0[1U] = (IData)((((QData)((IData)(
                                                         ((((7U 
                                                             < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                             ? 
                                                            ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                              << 0x10U) 
                                                             | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                >> 0x10U))
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_744)
                                                              ? 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_750)
                                                               ? 
                                                              ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                << 0x10U) 
                                                               | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                  >> 0x10U))
                                                               : 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_756)
                                                                ? 0xffffU
                                                                : 
                                                               ((0x3cU 
                                                                 == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                 ? 
                                                                (VL_GTES_III(16, 
                                                                             (0xffffU 
                                                                              & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                             (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                              >> 0x10U))
                                                                  ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                  : 
                                                                 ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                   << 0x10U) 
                                                                  | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     >> 0x10U)))
                                                                 : 
                                                                ((0x34U 
                                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                  ? 
                                                                 (((0xffffU 
                                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                   >= 
                                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                    >> 0x10U))
                                                                   ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                   : 
                                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                    << 0x10U) 
                                                                   | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                      >> 0x10U)))
                                                                  : 
                                                                 ((0x2cU 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (VL_LTES_III(16, 
                                                                               (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                               (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x10U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     << 0x10U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                       >> 0x10U)))
                                                                   : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5264))))))
                                                              : 
                                                             (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                               & (7U 
                                                                  > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                               ? 
                                                              ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                << 0x10U) 
                                                               | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                  >> 0x10U))
                                                               : 0xffffU))) 
                                                           << 0x10U) 
                                                          | (0xffffU 
                                                             & ((6U 
                                                                 < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                 ? 
                                                                vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                 : 
                                                                ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_687)
                                                                  ? 
                                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_693)
                                                                   ? 
                                                                  vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                   : 
                                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_699)
                                                                    ? 0xffffU
                                                                    : 
                                                                   ((0x3cU 
                                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                     ? 
                                                                    (VL_GTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                      ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                      : 
                                                                     vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                     : 
                                                                    ((0x34U 
                                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                      ? 
                                                                     (((0xffffU 
                                                                        & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                       >= 
                                                                       (0xffffU 
                                                                        & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                       : 
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                      : 
                                                                     ((0x2cU 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                       ? 
                                                                      (VL_LTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                        : 
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                       : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5192))))))
                                                                  : 
                                                                 (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                   & (6U 
                                                                      > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                   ? 
                                                                  vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                   : 0xffffU))))))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((((5U 
                                                              < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                              ? 
                                                             ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                               << 0x10U) 
                                                              | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                 >> 0x10U))
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_630)
                                                               ? 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_636)
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                 << 0x10U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                   >> 0x10U))
                                                                : 
                                                               ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_642)
                                                                 ? 0xffffU
                                                                 : 
                                                                ((0x3cU 
                                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                  ? 
                                                                 (VL_GTES_III(16, 
                                                                              (0xffffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                              (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                               >> 0x10U))
                                                                   ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                   : 
                                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                    << 0x10U) 
                                                                   | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      >> 0x10U)))
                                                                  : 
                                                                 ((0x34U 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (((0xffffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                    >= 
                                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                     >> 0x10U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                     << 0x10U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                       >> 0x10U)))
                                                                   : 
                                                                  ((0x2cU 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                    ? 
                                                                   (VL_LTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x10U))
                                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                     : 
                                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      << 0x10U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                        >> 0x10U)))
                                                                    : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5120))))))
                                                               : 
                                                              (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                & (5U 
                                                                   > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                 << 0x10U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                   >> 0x10U))
                                                                : 0xffffU))) 
                                                            << 0x10U) 
                                                           | (0xffffU 
                                                              & ((4U 
                                                                  < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                  ? 
                                                                 vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                  : 
                                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_573)
                                                                   ? 
                                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_579)
                                                                    ? 
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                    : 
                                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_585)
                                                                     ? 0xffffU
                                                                     : 
                                                                    ((0x3cU 
                                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                      ? 
                                                                     (VL_GTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                       : 
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                      : 
                                                                     ((0x34U 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                       ? 
                                                                      (((0xffffU 
                                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                        >= 
                                                                        (0xffffU 
                                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                        : 
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                       : 
                                                                      ((0x2cU 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                        ? 
                                                                       (VL_LTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                         : 
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                        : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5048))))))
                                                                   : 
                                                                  (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                    & (4U 
                                                                       > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                    ? 
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                    : 0xffffU)))))))));
    __Vtemp_h25633e76__0[2U] = (IData)(((((QData)((IData)(
                                                          ((((7U 
                                                              < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                              ? 
                                                             ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                               << 0x10U) 
                                                              | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                 >> 0x10U))
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_744)
                                                               ? 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_750)
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                 << 0x10U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                   >> 0x10U))
                                                                : 
                                                               ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_756)
                                                                 ? 0xffffU
                                                                 : 
                                                                ((0x3cU 
                                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                  ? 
                                                                 (VL_GTES_III(16, 
                                                                              (0xffffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                              (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                               >> 0x10U))
                                                                   ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                   : 
                                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                    << 0x10U) 
                                                                   | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                      >> 0x10U)))
                                                                  : 
                                                                 ((0x34U 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (((0xffffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                    >= 
                                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     >> 0x10U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     << 0x10U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                       >> 0x10U)))
                                                                   : 
                                                                  ((0x2cU 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                    ? 
                                                                   (VL_LTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x10U))
                                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                     : 
                                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                      << 0x10U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                        >> 0x10U)))
                                                                    : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5264))))))
                                                               : 
                                                              (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                & (7U 
                                                                   > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                 << 0x10U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                   >> 0x10U))
                                                                : 0xffffU))) 
                                                            << 0x10U) 
                                                           | (0xffffU 
                                                              & ((6U 
                                                                  < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                  ? 
                                                                 vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                  : 
                                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_687)
                                                                   ? 
                                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_693)
                                                                    ? 
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                    : 
                                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_699)
                                                                     ? 0xffffU
                                                                     : 
                                                                    ((0x3cU 
                                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                      ? 
                                                                     (VL_GTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                       : 
                                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                      : 
                                                                     ((0x34U 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                       ? 
                                                                      (((0xffffU 
                                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                        >= 
                                                                        (0xffffU 
                                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                        : 
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                       : 
                                                                      ((0x2cU 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                        ? 
                                                                       (VL_LTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                         : 
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                        : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5192))))))
                                                                   : 
                                                                  (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                    & (6U 
                                                                       > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                    ? 
                                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                    : 0xffffU))))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           ((((5U 
                                                               < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                               ? 
                                                              ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                << 0x10U) 
                                                               | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                  >> 0x10U))
                                                               : 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_630)
                                                                ? 
                                                               ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_636)
                                                                 ? 
                                                                ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                  << 0x10U) 
                                                                 | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                    >> 0x10U))
                                                                 : 
                                                                ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_642)
                                                                  ? 0xffffU
                                                                  : 
                                                                 ((0x3cU 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (VL_GTES_III(16, 
                                                                               (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                               (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x10U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                     << 0x10U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                       >> 0x10U)))
                                                                   : 
                                                                  ((0x34U 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                    ? 
                                                                   (((0xffffU 
                                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                     >= 
                                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      >> 0x10U))
                                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                     : 
                                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      << 0x10U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                        >> 0x10U)))
                                                                    : 
                                                                   ((0x2cU 
                                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                     ? 
                                                                    (VL_LTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x10U))
                                                                      ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                      : 
                                                                     ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                       << 0x10U) 
                                                                      | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                         >> 0x10U)))
                                                                     : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5120))))))
                                                                : 
                                                               (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                 & (5U 
                                                                    > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                 ? 
                                                                ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                  << 0x10U) 
                                                                 | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                    >> 0x10U))
                                                                 : 0xffffU))) 
                                                             << 0x10U) 
                                                            | (0xffffU 
                                                               & ((4U 
                                                                   < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                   ? 
                                                                  vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                   : 
                                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_573)
                                                                    ? 
                                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_579)
                                                                     ? 
                                                                    vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                     : 
                                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_585)
                                                                      ? 0xffffU
                                                                      : 
                                                                     ((0x3cU 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                       ? 
                                                                      (VL_GTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                        : 
                                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                       : 
                                                                      ((0x34U 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                        ? 
                                                                       (((0xffffU 
                                                                          & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                         >= 
                                                                         (0xffffU 
                                                                          & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                         : 
                                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                        : 
                                                                       ((0x2cU 
                                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                         ? 
                                                                        (VL_LTES_III(16, 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                          : 
                                                                         vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                         : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5048))))))
                                                                    : 
                                                                   (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                     & (4U 
                                                                        > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                     ? 
                                                                    vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                     : 0xffffU)))))))) 
                                        >> 0x20U));
    __Vtemp_h1cf192d5__0[0U] = ((((1U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                   ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                       << 0x10U) | 
                                      (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                       >> 0x10U)) : 
                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_60)
                                    ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_66)
                                        ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                            << 0x10U) 
                                           | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                              >> 0x10U))
                                        : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_72)
                                            ? 0xffffU
                                            : ((0x3cU 
                                                == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                ? (
                                                   VL_GTES_III(16, 
                                                               (0xffffU 
                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                               (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                >> 0x10U))
                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                    : 
                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                     << 0x10U) 
                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                       >> 0x10U)))
                                                : (
                                                   (0x34U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                    ? 
                                                   (((0xffffU 
                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                     >= 
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                      >> 0x10U))
                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                     : 
                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                      << 0x10U) 
                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                        >> 0x10U)))
                                                    : 
                                                   ((0x2cU 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                     ? 
                                                    (VL_LTES_III(16, 
                                                                 (0xffffU 
                                                                  & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                 (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                  >> 0x10U))
                                                      ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                      : 
                                                     ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                       << 0x10U) 
                                                      | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                         >> 0x10U)))
                                                     : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4832))))))
                                    : (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                        & (1U > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                        ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                            << 0x10U) 
                                           | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                              >> 0x10U))
                                        : 0xffffU))) 
                                 << 0x10U) | (0xffffU 
                                              & ((0U 
                                                  < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                  ? 
                                                 vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U]
                                                  : 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3)
                                                   ? 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_9)
                                                    ? 
                                                   vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U]
                                                    : 
                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_15)
                                                     ? 0xffffU
                                                     : 
                                                    ((0x3cU 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                      ? 
                                                     (VL_GTES_III(16, 
                                                                  (0xffffU 
                                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                  (0xffffU 
                                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))
                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                       : 
                                                      vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                                      : 
                                                     ((0x34U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                       ? 
                                                      (((0xffffU 
                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                        >= 
                                                        (0xffffU 
                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))
                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                        : 
                                                       vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                                       : 
                                                      ((0x2cU 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                        ? 
                                                       (VL_LTES_III(16, 
                                                                    (0xffffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                    (0xffffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))
                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                         : 
                                                        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                                        : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4760))))))
                                                   : 0xffffU))));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[0U] 
        = __Vtemp_h1cf192d5__0[0U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[1U] 
        = __Vtemp_h25633e76__0[0U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[2U] 
        = __Vtemp_h25633e76__0[1U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
        = __Vtemp_h25633e76__0[2U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[0U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[1U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[1U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[2U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[2U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[3U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[3U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[4U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[4U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[5U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[5U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[6U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[6U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[7U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[7U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[8U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[8U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[9U] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[9U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xaU] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[0xaU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xbU] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[0xbU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xcU] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[0xcU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xdU] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[0xdU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xeU] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[0xeU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xfU] 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14[0xfU];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x10U] 
        = (IData)(((8U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((0xffU & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1257)
                        ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1263)
                            ? (QData)((IData)((0xffU 
                                               & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1269)
                                ? 0xffffffffffffffffULL
                                : (QData)((IData)((0xffU 
                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                        : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5945)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x11U] 
        = (IData)((((8U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((0xffU & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1257)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1263)
                             ? (QData)((IData)((0xffU 
                                                & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U])))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1269)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5945)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x12U] 
        = (IData)(((9U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                >> 8U))))
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1314)
                        ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1320)
                            ? (QData)((IData)((0xffU 
                                               & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                  >> 8U))))
                            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1326)
                                ? 0xffffffffffffffffULL
                                : (QData)((IData)((0xffU 
                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                        : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5974)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x13U] 
        = (IData)((((9U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                 >> 8U))))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1314)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1320)
                             ? (QData)((IData)((0xffU 
                                                & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                   >> 8U))))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1326)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5974)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x14U] 
        = (IData)(((0xaU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                >> 0x10U))))
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1371)
                        ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1377)
                            ? (QData)((IData)((0xffU 
                                               & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                  >> 0x10U))))
                            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1383)
                                ? 0xffffffffffffffffULL
                                : (QData)((IData)((0xffU 
                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                        : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6003)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x15U] 
        = (IData)((((0xaU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                 >> 0x10U))))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1371)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1377)
                             ? (QData)((IData)((0xffU 
                                                & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                   >> 0x10U))))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1383)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6003)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x16U] 
        = (IData)(((0xbU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                       >> 0x18U))) : 
                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1428)
                     ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1434)
                         ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                            >> 0x18U)))
                         : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1440)
                             ? 0xffffffffffffffffULL
                             : (QData)((IData)((0xffU 
                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                     : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6032)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x17U] 
        = (IData)((((0xbU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                        >> 0x18U)))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1428)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1434)
                             ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                >> 0x18U)))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1440)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6032)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x18U] 
        = (IData)(((0xcU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((0xffU & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])))
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1485)
                        ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1491)
                            ? (QData)((IData)((0xffU 
                                               & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])))
                            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1497)
                                ? 0xffffffffffffffffULL
                                : (QData)((IData)((0xffU 
                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                        : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6061)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x19U] 
        = (IData)((((0xcU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((0xffU & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1485)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1491)
                             ? (QData)((IData)((0xffU 
                                                & vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U])))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1497)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6061)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1aU] 
        = (IData)(((0xdU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                >> 8U))))
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1542)
                        ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1548)
                            ? (QData)((IData)((0xffU 
                                               & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                  >> 8U))))
                            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1554)
                                ? 0xffffffffffffffffULL
                                : (QData)((IData)((0xffU 
                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                        : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6090)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1bU] 
        = (IData)((((0xdU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                 >> 8U))))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1542)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1548)
                             ? (QData)((IData)((0xffU 
                                                & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                   >> 8U))))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1554)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6090)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1cU] 
        = (IData)(((0xeU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                >> 0x10U))))
                    : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1599)
                        ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1605)
                            ? (QData)((IData)((0xffU 
                                               & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                  >> 0x10U))))
                            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1611)
                                ? 0xffffffffffffffffULL
                                : (QData)((IData)((0xffU 
                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                        : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6119)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1dU] 
        = (IData)((((0xeU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((0xffU & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                 >> 0x10U))))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1599)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1605)
                             ? (QData)((IData)((0xffU 
                                                & (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                   >> 0x10U))))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1611)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6119)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1eU] 
        = (IData)(((0xfU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                    ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                       >> 0x18U))) : 
                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1656)
                     ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1662)
                         ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                            >> 0x18U)))
                         : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1668)
                             ? 0xffffffffffffffffULL
                             : (QData)((IData)((0xffU 
                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                     : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6148)));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1fU] 
        = (IData)((((0xfU < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                     ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                        >> 0x18U)))
                     : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1656)
                         ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1662)
                             ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                >> 0x18U)))
                             : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1668)
                                 ? 0xffffffffffffffffULL
                                 : (QData)((IData)(
                                                   (0xffU 
                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A)))))
                         : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6148)) 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_10 
        = (((QData)((IData)(((((7U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                    << 8U) | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                              >> 0x18U))
                                : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_744)
                                    ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_750)
                                        ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                            << 8U) 
                                           | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                              >> 0x18U))
                                        : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_756)
                                            ? 0xffU
                                            : ((0x3cU 
                                                == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                ? (
                                                   VL_GTES_III(8, 
                                                               (0xffU 
                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                               (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                >> 0x18U))
                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                    : 
                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                     << 8U) 
                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                       >> 0x18U)))
                                                : (
                                                   (0x34U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                    ? 
                                                   (((0xffU 
                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                     >= 
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                      >> 0x18U))
                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                     : 
                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                      << 8U) 
                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                        >> 0x18U)))
                                                    : 
                                                   ((0x2cU 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                     ? 
                                                    (VL_LTES_III(8, 
                                                                 (0xffU 
                                                                  & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                 (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                  >> 0x18U))
                                                      ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                      : 
                                                     ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                       << 8U) 
                                                      | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                         >> 0x18U)))
                                                     : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4112))))))
                                    : (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                        & (7U > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                        ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                            << 8U) 
                                           | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                              >> 0x18U))
                                        : 0xffU))) 
                              << 0x18U) | ((0xff0000U 
                                            & (((6U 
                                                 < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                 ? 
                                                ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                  << 0x10U) 
                                                 | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                    >> 0x10U))
                                                 : 
                                                ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_687)
                                                  ? 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_693)
                                                   ? 
                                                  ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                    << 0x10U) 
                                                   | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                      >> 0x10U))
                                                   : 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_699)
                                                    ? 0xffU
                                                    : 
                                                   ((0x3cU 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                     ? 
                                                    (VL_GTES_III(8, 
                                                                 (0xffU 
                                                                  & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                 (0xffU 
                                                                  & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                     >> 0x10U)))
                                                      ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                      : 
                                                     ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                       << 0x10U) 
                                                      | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                         >> 0x10U)))
                                                     : 
                                                    ((0x34U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                      ? 
                                                     (((0xffU 
                                                        & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                       >= 
                                                       (0xffU 
                                                        & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                           >> 0x10U)))
                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                       : 
                                                      ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                        << 0x10U) 
                                                       | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                          >> 0x10U)))
                                                      : 
                                                     ((0x2cU 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                       ? 
                                                      (VL_LTES_III(8, 
                                                                   (0xffU 
                                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                   (0xffU 
                                                                    & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                       >> 0x10U)))
                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                        : 
                                                       ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                         << 0x10U) 
                                                        | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                           >> 0x10U)))
                                                       : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4040))))))
                                                  : 
                                                 (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                   & (6U 
                                                      > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                   ? 
                                                  ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                    << 0x10U) 
                                                   | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                      >> 0x10U))
                                                   : 0xffU))) 
                                               << 0x10U)) 
                                           | ((0xff00U 
                                               & (((5U 
                                                    < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                    ? 
                                                   ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                     << 0x18U) 
                                                    | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                       >> 8U))
                                                    : 
                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_630)
                                                     ? 
                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_636)
                                                      ? 
                                                     ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                       << 0x18U) 
                                                      | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                         >> 8U))
                                                      : 
                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_642)
                                                       ? 0xffU
                                                       : 
                                                      ((0x3cU 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                        ? 
                                                       (VL_GTES_III(8, 
                                                                    (0xffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                    (0xffU 
                                                                     & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                        >> 8U)))
                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                         : 
                                                        ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                          << 0x18U) 
                                                         | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                            >> 8U)))
                                                        : 
                                                       ((0x34U 
                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                         ? 
                                                        (((0xffU 
                                                           & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                          >= 
                                                          (0xffU 
                                                           & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                              >> 8U)))
                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                          : 
                                                         ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                           << 0x18U) 
                                                          | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                             >> 8U)))
                                                         : 
                                                        ((0x2cU 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                          ? 
                                                         (VL_LTES_III(8, 
                                                                      (0xffU 
                                                                       & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                      (0xffU 
                                                                       & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                                          >> 8U)))
                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                           : 
                                                          ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                            << 0x18U) 
                                                           | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U] 
                                                              >> 8U)))
                                                          : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3968))))))
                                                     : 
                                                    (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                      & (5U 
                                                         > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                      ? 
                                                     ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                       << 0x18U) 
                                                      | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U] 
                                                         >> 8U))
                                                      : 0xffU))) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & ((4U 
                                                     < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                     ? 
                                                    vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                                                     : 
                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_573)
                                                      ? 
                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_579)
                                                       ? 
                                                      vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                                                       : 
                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_585)
                                                        ? 0xffU
                                                        : 
                                                       ((0x3cU 
                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                         ? 
                                                        (VL_GTES_III(8, 
                                                                     (0xffU 
                                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                     (0xffU 
                                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U]))
                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                          : 
                                                         vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                                         : 
                                                        ((0x34U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                          ? 
                                                         (((0xffU 
                                                            & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                           >= 
                                                           (0xffU 
                                                            & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U]))
                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                           : 
                                                          vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                                          : 
                                                         ((0x2cU 
                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                           ? 
                                                          (VL_LTES_III(8, 
                                                                       (0xffU 
                                                                        & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                       (0xffU 
                                                                        & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U]))
                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                            : 
                                                           vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[1U])
                                                           : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3896))))))
                                                      : 
                                                     (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                       & (4U 
                                                          > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                       ? 
                                                      vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[1U]
                                                       : 0xffU))))))))) 
            << 0x20U) | (QData)((IData)(((((3U < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                            ? ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                << 8U) 
                                               | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                  >> 0x18U))
                                            : ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_288)
                                                ? ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_294)
                                                    ? 
                                                   ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                     << 8U) 
                                                    | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                       >> 0x18U))
                                                    : 
                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_300)
                                                     ? 0xffU
                                                     : 
                                                    ((0x3cU 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                      ? 
                                                     (VL_GTES_III(8, 
                                                                  (0xffU 
                                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                  (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                   >> 0x18U))
                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                       : 
                                                      ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                        << 8U) 
                                                       | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                          >> 0x18U)))
                                                      : 
                                                     ((0x34U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                       ? 
                                                      (((0xffU 
                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                        >= 
                                                        (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                         >> 0x18U))
                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                        : 
                                                       ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                         << 8U) 
                                                        | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                           >> 0x18U)))
                                                       : 
                                                      ((0x2cU 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                        ? 
                                                       (VL_LTES_III(8, 
                                                                    (0xffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                     >> 0x18U))
                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                         : 
                                                        ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                          << 8U) 
                                                         | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                            >> 0x18U)))
                                                        : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3824))))))
                                                : (
                                                   ((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                    & (3U 
                                                       > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                    ? 
                                                   ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                     << 8U) 
                                                    | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                       >> 0x18U))
                                                    : 0xffU))) 
                                          << 0x18U) 
                                         | ((0xff0000U 
                                             & (((2U 
                                                  < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                  ? 
                                                 ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                   << 0x10U) 
                                                  | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                     >> 0x10U))
                                                  : 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_231)
                                                   ? 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_237)
                                                    ? 
                                                   ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                     << 0x10U) 
                                                    | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                       >> 0x10U))
                                                    : 
                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_243)
                                                     ? 0xffU
                                                     : 
                                                    ((0x3cU 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                      ? 
                                                     (VL_GTES_III(8, 
                                                                  (0xffU 
                                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                  (0xffU 
                                                                   & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                      >> 0x10U)))
                                                       ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                       : 
                                                      ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                        << 0x10U) 
                                                       | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                          >> 0x10U)))
                                                      : 
                                                     ((0x34U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                       ? 
                                                      (((0xffU 
                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                        >= 
                                                        (0xffU 
                                                         & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                            >> 0x10U)))
                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                        : 
                                                       ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                         << 0x10U) 
                                                        | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                           >> 0x10U)))
                                                       : 
                                                      ((0x2cU 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                        ? 
                                                       (VL_LTES_III(8, 
                                                                    (0xffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                    (0xffU 
                                                                     & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                        >> 0x10U)))
                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                         : 
                                                        ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                          << 0x10U) 
                                                         | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                            >> 0x10U)))
                                                        : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3752))))))
                                                   : 
                                                  (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                    & (2U 
                                                       > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                    ? 
                                                   ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                     << 0x10U) 
                                                    | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                       >> 0x10U))
                                                    : 0xffU))) 
                                                << 0x10U)) 
                                            | ((0xff00U 
                                                & (((1U 
                                                     < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                     ? 
                                                    ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                      << 0x18U) 
                                                     | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                        >> 8U))
                                                     : 
                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_60)
                                                      ? 
                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_66)
                                                       ? 
                                                      ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                        << 0x18U) 
                                                       | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                          >> 8U))
                                                       : 
                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_72)
                                                        ? 0xffU
                                                        : 
                                                       ((0x3cU 
                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                         ? 
                                                        (VL_GTES_III(8, 
                                                                     (0xffU 
                                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                     (0xffU 
                                                                      & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                         >> 8U)))
                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                          : 
                                                         ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                           << 0x18U) 
                                                          | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                             >> 8U)))
                                                         : 
                                                        ((0x34U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                          ? 
                                                         (((0xffU 
                                                            & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                           >= 
                                                           (0xffU 
                                                            & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                               >> 8U)))
                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                           : 
                                                          ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                            << 0x18U) 
                                                           | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                              >> 8U)))
                                                          : 
                                                         ((0x2cU 
                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                           ? 
                                                          (VL_LTES_III(8, 
                                                                       (0xffU 
                                                                        & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                       (0xffU 
                                                                        & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                                           >> 8U)))
                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                            : 
                                                           ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                             << 0x18U) 
                                                            | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U] 
                                                               >> 8U)))
                                                           : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3680))))))
                                                      : 
                                                     (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                       & (1U 
                                                          > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                       ? 
                                                      ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                        << 0x18U) 
                                                       | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U] 
                                                          >> 8U))
                                                       : 0xffU))) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & ((0U 
                                                      < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                      ? 
                                                     vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U]
                                                      : 
                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3)
                                                       ? 
                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_9)
                                                        ? 
                                                       vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[0U]
                                                        : 
                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_15)
                                                         ? 0xffU
                                                         : 
                                                        ((0x3cU 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                          ? 
                                                         (VL_GTES_III(8, 
                                                                      (0xffU 
                                                                       & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                      (0xffU 
                                                                       & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))
                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                           : 
                                                          vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                                          : 
                                                         ((0x34U 
                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                           ? 
                                                          (((0xffU 
                                                             & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                            >= 
                                                            (0xffU 
                                                             & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))
                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                            : 
                                                           vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                                           : 
                                                          ((0x2cU 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                            ? 
                                                           (VL_LTES_III(8, 
                                                                        (0xffU 
                                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                        (0xffU 
                                                                         & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U]))
                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                             : 
                                                            vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[0U])
                                                            : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3608))))))
                                                       : 0xffU)))))))));
    vlSelf->Top__DOT__core__DOT__IDecode_io_pcSrc = 
        ((IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_taken) 
         | (0U != (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_jump)));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___GEN_20 
        = (VL_LTES_IQQ(36, Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__avl, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__valmax)
            ? Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__avl
            : vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__valmax);
    Top__DOT__core__DOT__pc_io_halt = (1U & (((((IData)(vlSelf->Top__DOT__core__DOT__Execute_io_stall) 
                                                | (IData)(vlSelf->Top__DOT__core__DOT__IDecode_io_stall)) 
                                               | (IData)(vlSelf->Top__DOT__core__DOT__IF_stall)) 
                                              | (~ (IData)(vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid))) 
                                             | (1U 
                                                == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))));
    VL_EXTEND_WI(95,32, __Vtemp_h08bfe934__0, (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a 
                                                   >> 0x1fU))
                                                ? (- vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a)
                                                : vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a));
    VL_EXTEND_WI(95,32, __Vtemp_hf60a55f6__0, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp_hf60a55f6__1, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    VL_SUB_W(3, __Vtemp_h7c9a1e7c__0, __Vtemp_hf60a55f6__1, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5);
    VL_EXTEND_WI(95,32, __Vtemp_hf60a55f6__2, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp_hf60a55f6__3, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp_hf60a55f6__4, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp_hf60a55f6__5, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend);
    if (vlSelf->reset) {
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U] = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[1U] = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[2U] = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29 = 0ULL;
    } else if (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
                | (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u))) {
        if (vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid) {
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U] 
                = __Vtemp_h08bfe934__0[0U];
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[1U] 
                = __Vtemp_h08bfe934__0[1U];
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[2U] 
                = (0x7fffffffU & __Vtemp_h08bfe934__0[2U]);
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29 = 0ULL;
        } else if ((0U != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter))) {
            if (VL_GTE_W(3, __Vtemp_hf60a55f6__0, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5)) {
                vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U] 
                    = __Vtemp_h7c9a1e7c__0[0U];
                vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[1U] 
                    = __Vtemp_h7c9a1e7c__0[1U];
                vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[2U] 
                    = (0x7fffffffU & __Vtemp_h7c9a1e7c__0[2U]);
            } else {
                vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U] 
                    = __Vtemp_hf60a55f6__2[0U];
                vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[1U] 
                    = __Vtemp_hf60a55f6__2[1U];
                vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[2U] 
                    = (0x7fffffffU & __Vtemp_hf60a55f6__2[2U]);
            }
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29 
                = (VL_GTE_W(3, __Vtemp_hf60a55f6__5, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5)
                    ? ((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient)) 
                       + (1ULL << (0x3fU & ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter) 
                                            - (IData)(1U)))))
                    : (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient)));
        } else {
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U] 
                = __Vtemp_hf60a55f6__3[0U];
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[1U] 
                = __Vtemp_hf60a55f6__3[1U];
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[2U] 
                = (0x7fffffffU & __Vtemp_hf60a55f6__3[2U]);
            vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29 
                = (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient));
        }
    } else {
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U] 
            = __Vtemp_hf60a55f6__4[0U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[1U] 
            = __Vtemp_hf60a55f6__4[1U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[2U] 
            = (0x7fffffffU & __Vtemp_hf60a55f6__4[2U]);
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29 
            = (QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient));
    }
    Top__DOT__core__DOT__Execute__DOT___io_ALUresult_T 
        = (((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38)) 
            | ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38)) 
                 | (3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))) 
                | (2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))) 
               | (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
                   | (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u)) 
                  & ((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid)) 
                     & (0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter))))))
            ? ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))
                ? (IData)(Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result)
                : ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38)) 
                     | (3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))) 
                    | (2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38)))
                    ? (IData)((Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result 
                               >> 0x20U)) : ((4U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))
                                              ? (((
                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a 
                                                    >> 0x1fU) 
                                                   != 
                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b 
                                                    >> 0x1fU)) 
                                                  & (0U 
                                                     != vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b))
                                                  ? 
                                                 (- vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient)
                                                  : vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient)
                                              : ((5U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))
                                                  ? vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))
                                                   ? 
                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a 
                                                    >> 0x1fU)
                                                    ? 
                                                   (- vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend)
                                                    : vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38))
                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend
                                                    : 0U))))))
            : 0U);
    __Vtemp_h9669131c__0[2U] = (IData)((((QData)((IData)(
                                                         ((((0xfU 
                                                             < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                             ? 
                                                            ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                              << 8U) 
                                                             | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                >> 0x18U))
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1656)
                                                              ? 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1662)
                                                               ? 
                                                              ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                << 8U) 
                                                               | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                  >> 0x18U))
                                                               : 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1668)
                                                                ? 0xffU
                                                                : 
                                                               ((0x3cU 
                                                                 == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                 ? 
                                                                (VL_GTES_III(8, 
                                                                             (0xffU 
                                                                              & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                             (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                              >> 0x18U))
                                                                  ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                  : 
                                                                 ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                   << 8U) 
                                                                  | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     >> 0x18U)))
                                                                 : 
                                                                ((0x34U 
                                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                  ? 
                                                                 (((0xffU 
                                                                    & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                   >= 
                                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                    >> 0x18U))
                                                                   ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                   : 
                                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                    << 8U) 
                                                                   | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                      >> 0x18U)))
                                                                  : 
                                                                 ((0x2cU 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (VL_LTES_III(8, 
                                                                               (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                               (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x18U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     << 8U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                       >> 0x18U)))
                                                                   : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4688))))))
                                                              : 
                                                             (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                               & (0xfU 
                                                                  > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                               ? 
                                                              ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                << 8U) 
                                                               | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                  >> 0x18U))
                                                               : 0xffU))) 
                                                           << 0x18U) 
                                                          | ((0xff0000U 
                                                              & (((0xeU 
                                                                   < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                   ? 
                                                                  ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                    << 0x10U) 
                                                                   | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                      >> 0x10U))
                                                                   : 
                                                                  ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1599)
                                                                    ? 
                                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1605)
                                                                     ? 
                                                                    ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                      << 0x10U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                        >> 0x10U))
                                                                     : 
                                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1611)
                                                                      ? 0xffU
                                                                      : 
                                                                     ((0x3cU 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                       ? 
                                                                      (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x10U)))
                                                                        ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                        : 
                                                                       ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                         << 0x10U) 
                                                                        | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                           >> 0x10U)))
                                                                       : 
                                                                      ((0x34U 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                        ? 
                                                                       (((0xffU 
                                                                          & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                         >= 
                                                                         (0xffU 
                                                                          & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                             >> 0x10U)))
                                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                         : 
                                                                        ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                          << 0x10U) 
                                                                         | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                            >> 0x10U)))
                                                                        : 
                                                                       ((0x2cU 
                                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                         ? 
                                                                        (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x10U)))
                                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                          : 
                                                                         ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                           << 0x10U) 
                                                                          | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                             >> 0x10U)))
                                                                         : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4616))))))
                                                                    : 
                                                                   (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                     & (0xeU 
                                                                        > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                     ? 
                                                                    ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                      << 0x10U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                        >> 0x10U))
                                                                     : 0xffU))) 
                                                                 << 0x10U)) 
                                                             | ((0xff00U 
                                                                 & (((0xdU 
                                                                      < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                      ? 
                                                                     ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                       << 0x18U) 
                                                                      | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                         >> 8U))
                                                                      : 
                                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1542)
                                                                       ? 
                                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1548)
                                                                        ? 
                                                                       ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                         << 0x18U) 
                                                                        | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                           >> 8U))
                                                                        : 
                                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1554)
                                                                         ? 0xffU
                                                                         : 
                                                                        ((0x3cU 
                                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                          ? 
                                                                         (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                           : 
                                                                          ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                            << 0x18U) 
                                                                           | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                              >> 8U)))
                                                                          : 
                                                                         ((0x34U 
                                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                           ? 
                                                                          (((0xffU 
                                                                             & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                            >= 
                                                                            (0xffU 
                                                                             & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                            : 
                                                                           ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                             << 0x18U) 
                                                                            | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                               >> 8U)))
                                                                           : 
                                                                          ((0x2cU 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                            ? 
                                                                           (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                             : 
                                                                            ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                              << 0x18U) 
                                                                             | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                            : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4544))))))
                                                                       : 
                                                                      (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                        & (0xdU 
                                                                           > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                        ? 
                                                                       ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                         << 0x18U) 
                                                                        | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                           >> 8U))
                                                                        : 0xffU))) 
                                                                    << 8U)) 
                                                                | (0xffU 
                                                                   & ((0xcU 
                                                                       < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                       ? 
                                                                      vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                       : 
                                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1485)
                                                                        ? 
                                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1491)
                                                                         ? 
                                                                        vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                         : 
                                                                        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1497)
                                                                          ? 0xffU
                                                                          : 
                                                                         ((0x3cU 
                                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                           ? 
                                                                          (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                            : 
                                                                           vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                           : 
                                                                          ((0x34U 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                            ? 
                                                                           (((0xffU 
                                                                              & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                             >= 
                                                                             (0xffU 
                                                                              & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                             : 
                                                                            vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                            : 
                                                                           ((0x2cU 
                                                                             == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                             ? 
                                                                            (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                              : 
                                                                             vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                             : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4472))))))
                                                                        : 
                                                                       (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                         & (0xcU 
                                                                            > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                         ? 
                                                                        vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                         : 0xffU))))))))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((((0xbU 
                                                              < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                              ? 
                                                             ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                               << 8U) 
                                                              | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                 >> 0x18U))
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1428)
                                                               ? 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1434)
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                 << 8U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                   >> 0x18U))
                                                                : 
                                                               ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1440)
                                                                 ? 0xffU
                                                                 : 
                                                                ((0x3cU 
                                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                  ? 
                                                                 (VL_GTES_III(8, 
                                                                              (0xffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                              (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                               >> 0x18U))
                                                                   ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                   : 
                                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                    << 8U) 
                                                                   | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      >> 0x18U)))
                                                                  : 
                                                                 ((0x34U 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (((0xffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                    >= 
                                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                     >> 0x18U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                     << 8U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                       >> 0x18U)))
                                                                   : 
                                                                  ((0x2cU 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                    ? 
                                                                   (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x18U))
                                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                     : 
                                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      << 8U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                        >> 0x18U)))
                                                                    : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4400))))))
                                                               : 
                                                              (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                & (0xbU 
                                                                   > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                 << 8U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                   >> 0x18U))
                                                                : 0xffU))) 
                                                            << 0x18U) 
                                                           | ((0xff0000U 
                                                               & (((0xaU 
                                                                    < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                    ? 
                                                                   ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                     << 0x10U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                       >> 0x10U))
                                                                    : 
                                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1371)
                                                                     ? 
                                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1377)
                                                                      ? 
                                                                     ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                       << 0x10U) 
                                                                      | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                         >> 0x10U))
                                                                      : 
                                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1383)
                                                                       ? 0xffU
                                                                       : 
                                                                      ((0x3cU 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                        ? 
                                                                       (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x10U)))
                                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                         : 
                                                                        ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                          << 0x10U) 
                                                                         | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                            >> 0x10U)))
                                                                        : 
                                                                       ((0x34U 
                                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                         ? 
                                                                        (((0xffU 
                                                                           & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                          >= 
                                                                          (0xffU 
                                                                           & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                              >> 0x10U)))
                                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                          : 
                                                                         ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                           << 0x10U) 
                                                                          | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                             >> 0x10U)))
                                                                         : 
                                                                        ((0x2cU 
                                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                          ? 
                                                                         (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x10U)))
                                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                           : 
                                                                          ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                            << 0x10U) 
                                                                           | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                              >> 0x10U)))
                                                                          : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4328))))))
                                                                     : 
                                                                    (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                      & (0xaU 
                                                                         > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                      ? 
                                                                     ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                       << 0x10U) 
                                                                      | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                         >> 0x10U))
                                                                      : 0xffU))) 
                                                                  << 0x10U)) 
                                                              | ((0xff00U 
                                                                  & (((9U 
                                                                       < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                       ? 
                                                                      ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                        << 0x18U) 
                                                                       | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                          >> 8U))
                                                                       : 
                                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1314)
                                                                        ? 
                                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1320)
                                                                         ? 
                                                                        ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                          << 0x18U) 
                                                                         | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                            >> 8U))
                                                                         : 
                                                                        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1326)
                                                                          ? 0xffU
                                                                          : 
                                                                         ((0x3cU 
                                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                           ? 
                                                                          (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                            : 
                                                                           ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                             << 0x18U) 
                                                                            | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                               >> 8U)))
                                                                           : 
                                                                          ((0x34U 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                            ? 
                                                                           (((0xffU 
                                                                              & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                             >= 
                                                                             (0xffU 
                                                                              & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                             : 
                                                                            ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                              << 0x18U) 
                                                                             | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                            : 
                                                                           ((0x2cU 
                                                                             == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                             ? 
                                                                            (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                              : 
                                                                             ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                               << 0x18U) 
                                                                              | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                             : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4256))))))
                                                                        : 
                                                                       (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                         & (9U 
                                                                            > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                         ? 
                                                                        ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                          << 0x18U) 
                                                                         | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                            >> 8U))
                                                                         : 0xffU))) 
                                                                     << 8U)) 
                                                                 | (0xffU 
                                                                    & ((8U 
                                                                        < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                        ? 
                                                                       vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                        : 
                                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1257)
                                                                         ? 
                                                                        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1263)
                                                                          ? 
                                                                         vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                          : 
                                                                         ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1269)
                                                                           ? 0xffU
                                                                           : 
                                                                          ((0x3cU 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                            ? 
                                                                           (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                             : 
                                                                            vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                            : 
                                                                           ((0x34U 
                                                                             == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                             ? 
                                                                            (((0xffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                              >= 
                                                                              (0xffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                              : 
                                                                             vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                             : 
                                                                            ((0x2cU 
                                                                              == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                              ? 
                                                                             (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                               ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                               : 
                                                                              vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                              : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4184))))))
                                                                         : 
                                                                        (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                          & (8U 
                                                                             > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                          ? 
                                                                         vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                          : 0xffU)))))))))));
    __Vtemp_h9669131c__0[3U] = (IData)(((((QData)((IData)(
                                                          ((((0xfU 
                                                              < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                              ? 
                                                             ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                               << 8U) 
                                                              | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                 >> 0x18U))
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1656)
                                                               ? 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1662)
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                 << 8U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                   >> 0x18U))
                                                                : 
                                                               ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1668)
                                                                 ? 0xffU
                                                                 : 
                                                                ((0x3cU 
                                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                  ? 
                                                                 (VL_GTES_III(8, 
                                                                              (0xffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                              (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                               >> 0x18U))
                                                                   ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                   : 
                                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                    << 8U) 
                                                                   | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                      >> 0x18U)))
                                                                  : 
                                                                 ((0x34U 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (((0xffU 
                                                                     & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                    >= 
                                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     >> 0x18U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                     << 8U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                       >> 0x18U)))
                                                                   : 
                                                                  ((0x2cU 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                    ? 
                                                                   (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x18U))
                                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                     : 
                                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                      << 8U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                        >> 0x18U)))
                                                                    : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4688))))))
                                                               : 
                                                              (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                & (0xfU 
                                                                   > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                ? 
                                                               ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                 << 8U) 
                                                                | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                   >> 0x18U))
                                                                : 0xffU))) 
                                                            << 0x18U) 
                                                           | ((0xff0000U 
                                                               & (((0xeU 
                                                                    < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                    ? 
                                                                   ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                     << 0x10U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                       >> 0x10U))
                                                                    : 
                                                                   ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1599)
                                                                     ? 
                                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1605)
                                                                      ? 
                                                                     ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                       << 0x10U) 
                                                                      | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                         >> 0x10U))
                                                                      : 
                                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1611)
                                                                       ? 0xffU
                                                                       : 
                                                                      ((0x3cU 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                        ? 
                                                                       (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x10U)))
                                                                         ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                         : 
                                                                        ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                          << 0x10U) 
                                                                         | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                            >> 0x10U)))
                                                                        : 
                                                                       ((0x34U 
                                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                         ? 
                                                                        (((0xffU 
                                                                           & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                          >= 
                                                                          (0xffU 
                                                                           & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                              >> 0x10U)))
                                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                          : 
                                                                         ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                           << 0x10U) 
                                                                          | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                             >> 0x10U)))
                                                                         : 
                                                                        ((0x2cU 
                                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                          ? 
                                                                         (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 0x10U)))
                                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                           : 
                                                                          ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                            << 0x10U) 
                                                                           | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                              >> 0x10U)))
                                                                          : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4616))))))
                                                                     : 
                                                                    (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                      & (0xeU 
                                                                         > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                      ? 
                                                                     ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                       << 0x10U) 
                                                                      | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                         >> 0x10U))
                                                                      : 0xffU))) 
                                                                  << 0x10U)) 
                                                              | ((0xff00U 
                                                                  & (((0xdU 
                                                                       < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                       ? 
                                                                      ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                        << 0x18U) 
                                                                       | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                          >> 8U))
                                                                       : 
                                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1542)
                                                                        ? 
                                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1548)
                                                                         ? 
                                                                        ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                          << 0x18U) 
                                                                         | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                            >> 8U))
                                                                         : 
                                                                        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1554)
                                                                          ? 0xffU
                                                                          : 
                                                                         ((0x3cU 
                                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                           ? 
                                                                          (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                            : 
                                                                           ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                             << 0x18U) 
                                                                            | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                               >> 8U)))
                                                                           : 
                                                                          ((0x34U 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                            ? 
                                                                           (((0xffU 
                                                                              & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                             >= 
                                                                             (0xffU 
                                                                              & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                             : 
                                                                            ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                              << 0x18U) 
                                                                             | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                            : 
                                                                           ((0x2cU 
                                                                             == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                             ? 
                                                                            (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                              : 
                                                                             ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                               << 0x18U) 
                                                                              | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U] 
                                                                                >> 8U)))
                                                                             : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4544))))))
                                                                        : 
                                                                       (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                         & (0xdU 
                                                                            > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                         ? 
                                                                        ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                          << 0x18U) 
                                                                         | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U] 
                                                                            >> 8U))
                                                                         : 0xffU))) 
                                                                     << 8U)) 
                                                                 | (0xffU 
                                                                    & ((0xcU 
                                                                        < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                        ? 
                                                                       vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                        : 
                                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1485)
                                                                         ? 
                                                                        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1491)
                                                                          ? 
                                                                         vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                          : 
                                                                         ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1497)
                                                                           ? 0xffU
                                                                           : 
                                                                          ((0x3cU 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                            ? 
                                                                           (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                             : 
                                                                            vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                            : 
                                                                           ((0x34U 
                                                                             == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                             ? 
                                                                            (((0xffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                              >= 
                                                                              (0xffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                              : 
                                                                             vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                             : 
                                                                            ((0x2cU 
                                                                              == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                              ? 
                                                                             (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U]))
                                                                               ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                               : 
                                                                              vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[3U])
                                                                              : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4472))))))
                                                                         : 
                                                                        (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                          & (0xcU 
                                                                             > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                          ? 
                                                                         vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[3U]
                                                                          : 0xffU))))))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           ((((0xbU 
                                                               < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                               ? 
                                                              ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                << 8U) 
                                                               | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                  >> 0x18U))
                                                               : 
                                                              ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1428)
                                                                ? 
                                                               ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1434)
                                                                 ? 
                                                                ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                  << 8U) 
                                                                 | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                    >> 0x18U))
                                                                 : 
                                                                ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1440)
                                                                  ? 0xffU
                                                                  : 
                                                                 ((0x3cU 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                   ? 
                                                                  (VL_GTES_III(8, 
                                                                               (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                               (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x18U))
                                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                    : 
                                                                   ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                     << 8U) 
                                                                    | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                       >> 0x18U)))
                                                                   : 
                                                                  ((0x34U 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                    ? 
                                                                   (((0xffU 
                                                                      & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                     >= 
                                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      >> 0x18U))
                                                                     ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                     : 
                                                                    ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                      << 8U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                        >> 0x18U)))
                                                                    : 
                                                                   ((0x2cU 
                                                                     == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                     ? 
                                                                    (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x18U))
                                                                      ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                      : 
                                                                     ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                       << 8U) 
                                                                      | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                         >> 0x18U)))
                                                                     : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4400))))))
                                                                : 
                                                               (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                 & (0xbU 
                                                                    > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                 ? 
                                                                ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                  << 8U) 
                                                                 | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                    >> 0x18U))
                                                                 : 0xffU))) 
                                                             << 0x18U) 
                                                            | ((0xff0000U 
                                                                & (((0xaU 
                                                                     < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                     ? 
                                                                    ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                      << 0x10U) 
                                                                     | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                        >> 0x10U))
                                                                     : 
                                                                    ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1371)
                                                                      ? 
                                                                     ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1377)
                                                                       ? 
                                                                      ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                        << 0x10U) 
                                                                       | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                          >> 0x10U))
                                                                       : 
                                                                      ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1383)
                                                                        ? 0xffU
                                                                        : 
                                                                       ((0x3cU 
                                                                         == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                         ? 
                                                                        (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x10U)))
                                                                          ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                          : 
                                                                         ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                           << 0x10U) 
                                                                          | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                             >> 0x10U)))
                                                                         : 
                                                                        ((0x34U 
                                                                          == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                          ? 
                                                                         (((0xffU 
                                                                            & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                           >= 
                                                                           (0xffU 
                                                                            & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                               >> 0x10U)))
                                                                           ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                           : 
                                                                          ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                            << 0x10U) 
                                                                           | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                              >> 0x10U)))
                                                                          : 
                                                                         ((0x2cU 
                                                                           == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                           ? 
                                                                          (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 0x10U)))
                                                                            ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                            : 
                                                                           ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                             << 0x10U) 
                                                                            | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                               >> 0x10U)))
                                                                           : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4328))))))
                                                                      : 
                                                                     (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                       & (0xaU 
                                                                          > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                       ? 
                                                                      ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                        << 0x10U) 
                                                                       | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                          >> 0x10U))
                                                                       : 0xffU))) 
                                                                   << 0x10U)) 
                                                               | ((0xff00U 
                                                                   & (((9U 
                                                                        < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                        ? 
                                                                       ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                         << 0x18U) 
                                                                        | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                           >> 8U))
                                                                        : 
                                                                       ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1314)
                                                                         ? 
                                                                        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1320)
                                                                          ? 
                                                                         ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                           << 0x18U) 
                                                                          | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                             >> 8U))
                                                                          : 
                                                                         ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1326)
                                                                           ? 0xffU
                                                                           : 
                                                                          ((0x3cU 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                            ? 
                                                                           (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                             ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                             : 
                                                                            ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                              << 0x18U) 
                                                                             | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                            : 
                                                                           ((0x34U 
                                                                             == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                             ? 
                                                                            (((0xffU 
                                                                               & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                              >= 
                                                                              (0xffU 
                                                                               & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                              : 
                                                                             ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                               << 0x18U) 
                                                                              | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                             : 
                                                                            ((0x2cU 
                                                                              == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                              ? 
                                                                             (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                               ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                               : 
                                                                              ((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                << 0x18U) 
                                                                               | (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U] 
                                                                                >> 8U)))
                                                                              : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4256))))))
                                                                         : 
                                                                        (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                          & (9U 
                                                                             > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                          ? 
                                                                         ((vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                           << 0x18U) 
                                                                          | (vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U] 
                                                                             >> 8U))
                                                                          : 0xffU))) 
                                                                      << 8U)) 
                                                                  | (0xffU 
                                                                     & ((8U 
                                                                         < vlSelf->Top__DOT__core__DOT__id_reg_vstart_out)
                                                                         ? 
                                                                        vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                         : 
                                                                        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1257)
                                                                          ? 
                                                                         ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1263)
                                                                           ? 
                                                                          vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                           : 
                                                                          ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1269)
                                                                            ? 0xffU
                                                                            : 
                                                                           ((0x3cU 
                                                                             == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                             ? 
                                                                            (VL_GTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                              ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                              : 
                                                                             vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                             : 
                                                                            ((0x34U 
                                                                              == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                              ? 
                                                                             (((0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A) 
                                                                               >= 
                                                                               (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                               ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                               : 
                                                                              vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                              : 
                                                                             ((0x2cU 
                                                                               == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))
                                                                               ? 
                                                                              (VL_LTES_III(8, 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A), 
                                                                                (0xffU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U]))
                                                                                ? vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A
                                                                                : 
                                                                               vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2[2U])
                                                                               : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4184))))))
                                                                          : 
                                                                         (((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_vta)) 
                                                                           & (8U 
                                                                              > vlSelf->Top__DOT__core__DOT__Execute_io_vl))
                                                                           ? 
                                                                          vlSelf->Top__DOT__core__DOT__id_reg_vs3_data[2U]
                                                                           : 0xffU)))))))))) 
                                        >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[0U] 
        = (IData)(Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_10);
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[1U] 
        = (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_10 
                   >> 0x20U));
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[2U] 
        = __Vtemp_h9669131c__0[2U];
    Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
        = __Vtemp_h9669131c__0[3U];
    vlSelf->Top__DOT__core__DOT__pc_io_pc4 = ((IData)(Top__DOT__core__DOT__pc_io_halt)
                                               ? vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg
                                               : ((IData)(4U) 
                                                  + vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg));
    vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult 
        = ((((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en) 
             & (1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__f7_reg))) 
            & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_ready))
            ? Top__DOT__core__DOT__Execute__DOT___io_ALUresult_T
            : (((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)) 
                & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_ready))
                ? Top__DOT__core__DOT__Execute__DOT___io_ALUresult_T
                : (IData)((0x7fffffffffffffffULL & 
                           ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                             ? (QData)((IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                             : ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                 ? (QData)((IData)(
                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                    | vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                 : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                     ? (QData)((IData)(
                                                       (vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                        + vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                     : ((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                         ? (QData)((IData)(
                                                           (vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                            - vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                         : ((4U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                             ? (QData)((IData)(
                                                               VL_LTS_III(32, vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1, vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                             : ((5U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                 ? (QData)((IData)(
                                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                                    < vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                                 : 
                                                ((6U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                  ? 
                                                 ((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1)) 
                                                  << 
                                                  (0x1fU 
                                                   & vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2))
                                                  : (QData)((IData)(
                                                                    ((7U 
                                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                                      ? 
                                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2))
                                                                      : 
                                                                     ((8U 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                                       ? 
                                                                      VL_SHIFTRS_III(32,32,5, vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1, 
                                                                                (0x1fU 
                                                                                & vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2))
                                                                       : 
                                                                      ((9U 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                                        ? 
                                                                       (vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                                        ^ vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2)
                                                                        : 0U))))))))))))))));
    if ((((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
          & (4U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
         & (0xbcU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_h69ad7b66__0[4U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[5U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[6U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[7U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[8U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[9U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xaU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xbU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xcU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xdU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xeU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xfU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x10U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x11U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x12U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x13U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x14U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x15U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x16U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x17U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x18U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x19U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1aU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1bU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1cU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1dU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1eU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1fU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U] 
                                                  >> 0x1fU)));
    } else if ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                 & (4U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                & (0xbcU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_h69ad7b66__0[4U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[5U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[6U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[7U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[8U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[9U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                               >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xaU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xbU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xcU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xdU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xeU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0xfU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                 >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x10U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x11U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x12U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x13U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x14U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x15U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x16U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x17U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x18U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x19U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1aU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1bU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1cU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1dU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1eU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
        __Vtemp_h69ad7b66__0[0x1fU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U] 
                                                  >> 0x1fU)));
    } else if ((0xbcU == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))) {
        if ((0U == (0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                             >> 7U)))) {
            __Vtemp_h69ad7b66__0[4U] = VTop__ConstPool__CONST_hcda40ff1_0[4U];
            __Vtemp_h69ad7b66__0[5U] = VTop__ConstPool__CONST_hcda40ff1_0[5U];
            __Vtemp_h69ad7b66__0[6U] = VTop__ConstPool__CONST_hcda40ff1_0[6U];
            __Vtemp_h69ad7b66__0[7U] = VTop__ConstPool__CONST_hcda40ff1_0[7U];
            __Vtemp_h69ad7b66__0[8U] = VTop__ConstPool__CONST_hcda40ff1_0[8U];
            __Vtemp_h69ad7b66__0[9U] = VTop__ConstPool__CONST_hcda40ff1_0[9U];
            __Vtemp_h69ad7b66__0[0xaU] = VTop__ConstPool__CONST_hcda40ff1_0[0xaU];
            __Vtemp_h69ad7b66__0[0xbU] = VTop__ConstPool__CONST_hcda40ff1_0[0xbU];
            __Vtemp_h69ad7b66__0[0xcU] = VTop__ConstPool__CONST_hcda40ff1_0[0xcU];
            __Vtemp_h69ad7b66__0[0xdU] = VTop__ConstPool__CONST_hcda40ff1_0[0xdU];
            __Vtemp_h69ad7b66__0[0xeU] = VTop__ConstPool__CONST_hcda40ff1_0[0xeU];
            __Vtemp_h69ad7b66__0[0xfU] = VTop__ConstPool__CONST_hcda40ff1_0[0xfU];
            __Vtemp_h69ad7b66__0[0x10U] = VTop__ConstPool__CONST_hcda40ff1_0[0x10U];
            __Vtemp_h69ad7b66__0[0x11U] = VTop__ConstPool__CONST_hcda40ff1_0[0x11U];
            __Vtemp_h69ad7b66__0[0x12U] = VTop__ConstPool__CONST_hcda40ff1_0[0x12U];
            __Vtemp_h69ad7b66__0[0x13U] = VTop__ConstPool__CONST_hcda40ff1_0[0x13U];
            __Vtemp_h69ad7b66__0[0x14U] = VTop__ConstPool__CONST_hcda40ff1_0[0x14U];
            __Vtemp_h69ad7b66__0[0x15U] = VTop__ConstPool__CONST_hcda40ff1_0[0x15U];
            __Vtemp_h69ad7b66__0[0x16U] = VTop__ConstPool__CONST_hcda40ff1_0[0x16U];
            __Vtemp_h69ad7b66__0[0x17U] = VTop__ConstPool__CONST_hcda40ff1_0[0x17U];
            __Vtemp_h69ad7b66__0[0x18U] = VTop__ConstPool__CONST_hcda40ff1_0[0x18U];
            __Vtemp_h69ad7b66__0[0x19U] = VTop__ConstPool__CONST_hcda40ff1_0[0x19U];
            __Vtemp_h69ad7b66__0[0x1aU] = VTop__ConstPool__CONST_hcda40ff1_0[0x1aU];
            __Vtemp_h69ad7b66__0[0x1bU] = VTop__ConstPool__CONST_hcda40ff1_0[0x1bU];
            __Vtemp_h69ad7b66__0[0x1cU] = VTop__ConstPool__CONST_hcda40ff1_0[0x1cU];
            __Vtemp_h69ad7b66__0[0x1dU] = VTop__ConstPool__CONST_hcda40ff1_0[0x1dU];
            __Vtemp_h69ad7b66__0[0x1eU] = VTop__ConstPool__CONST_hcda40ff1_0[0x1eU];
            __Vtemp_h69ad7b66__0[0x1fU] = VTop__ConstPool__CONST_hcda40ff1_0[0x1fU];
        } else if ((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h69ad7b66__0[4U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[5U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[6U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[7U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[8U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[9U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xaU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xbU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xcU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xdU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xeU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xfU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U] 
                                                      >> 0x1fU)));
        } else if ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h69ad7b66__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[4U];
            __Vtemp_h69ad7b66__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[5U];
            __Vtemp_h69ad7b66__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[6U];
            __Vtemp_h69ad7b66__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U];
            __Vtemp_h69ad7b66__0[8U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[9U] = (- (IData)((
                                                   vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                   >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xaU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xbU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xcU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xdU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xeU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0xfU] = (- (IData)(
                                                    (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                     >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[7U] 
                                                      >> 0x1fU)));
        } else if ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h69ad7b66__0[4U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[4U];
            __Vtemp_h69ad7b66__0[5U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[5U];
            __Vtemp_h69ad7b66__0[6U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[6U];
            __Vtemp_h69ad7b66__0[7U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[7U];
            __Vtemp_h69ad7b66__0[8U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[8U];
            __Vtemp_h69ad7b66__0[9U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[9U];
            __Vtemp_h69ad7b66__0[0xaU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xaU];
            __Vtemp_h69ad7b66__0[0xbU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xbU];
            __Vtemp_h69ad7b66__0[0xcU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xcU];
            __Vtemp_h69ad7b66__0[0xdU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xdU];
            __Vtemp_h69ad7b66__0[0xeU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xeU];
            __Vtemp_h69ad7b66__0[0xfU] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU];
            __Vtemp_h69ad7b66__0[0x10U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x11U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x12U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x13U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x14U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x15U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x16U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x17U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x18U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x19U] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1aU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1bU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1cU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1dU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1eU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
            __Vtemp_h69ad7b66__0[0x1fU] = (- (IData)(
                                                     (vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0xfU] 
                                                      >> 0x1fU)));
        } else if ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
            __Vtemp_h69ad7b66__0[4U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[4U];
            __Vtemp_h69ad7b66__0[5U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[5U];
            __Vtemp_h69ad7b66__0[6U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[6U];
            __Vtemp_h69ad7b66__0[7U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[7U];
            __Vtemp_h69ad7b66__0[8U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[8U];
            __Vtemp_h69ad7b66__0[9U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[9U];
            __Vtemp_h69ad7b66__0[0xaU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xaU];
            __Vtemp_h69ad7b66__0[0xbU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xbU];
            __Vtemp_h69ad7b66__0[0xcU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xcU];
            __Vtemp_h69ad7b66__0[0xdU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xdU];
            __Vtemp_h69ad7b66__0[0xeU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xeU];
            __Vtemp_h69ad7b66__0[0xfU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0xfU];
            __Vtemp_h69ad7b66__0[0x10U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x10U];
            __Vtemp_h69ad7b66__0[0x11U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x11U];
            __Vtemp_h69ad7b66__0[0x12U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x12U];
            __Vtemp_h69ad7b66__0[0x13U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x13U];
            __Vtemp_h69ad7b66__0[0x14U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x14U];
            __Vtemp_h69ad7b66__0[0x15U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x15U];
            __Vtemp_h69ad7b66__0[0x16U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x16U];
            __Vtemp_h69ad7b66__0[0x17U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x17U];
            __Vtemp_h69ad7b66__0[0x18U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x18U];
            __Vtemp_h69ad7b66__0[0x19U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x19U];
            __Vtemp_h69ad7b66__0[0x1aU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1aU];
            __Vtemp_h69ad7b66__0[0x1bU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1bU];
            __Vtemp_h69ad7b66__0[0x1cU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1cU];
            __Vtemp_h69ad7b66__0[0x1dU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1dU];
            __Vtemp_h69ad7b66__0[0x1eU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1eU];
            __Vtemp_h69ad7b66__0[0x1fU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0x1fU];
        } else {
            __Vtemp_h69ad7b66__0[4U] = VTop__ConstPool__CONST_hd6b7ba52_0[4U];
            __Vtemp_h69ad7b66__0[5U] = VTop__ConstPool__CONST_hd6b7ba52_0[5U];
            __Vtemp_h69ad7b66__0[6U] = VTop__ConstPool__CONST_hd6b7ba52_0[6U];
            __Vtemp_h69ad7b66__0[7U] = VTop__ConstPool__CONST_hd6b7ba52_0[7U];
            __Vtemp_h69ad7b66__0[8U] = VTop__ConstPool__CONST_hd6b7ba52_0[8U];
            __Vtemp_h69ad7b66__0[9U] = VTop__ConstPool__CONST_hd6b7ba52_0[9U];
            __Vtemp_h69ad7b66__0[0xaU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xaU];
            __Vtemp_h69ad7b66__0[0xbU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xbU];
            __Vtemp_h69ad7b66__0[0xcU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xcU];
            __Vtemp_h69ad7b66__0[0xdU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xdU];
            __Vtemp_h69ad7b66__0[0xeU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xeU];
            __Vtemp_h69ad7b66__0[0xfU] = VTop__ConstPool__CONST_hd6b7ba52_0[0xfU];
            __Vtemp_h69ad7b66__0[0x10U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x10U];
            __Vtemp_h69ad7b66__0[0x11U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x11U];
            __Vtemp_h69ad7b66__0[0x12U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x12U];
            __Vtemp_h69ad7b66__0[0x13U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x13U];
            __Vtemp_h69ad7b66__0[0x14U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x14U];
            __Vtemp_h69ad7b66__0[0x15U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x15U];
            __Vtemp_h69ad7b66__0[0x16U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x16U];
            __Vtemp_h69ad7b66__0[0x17U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x17U];
            __Vtemp_h69ad7b66__0[0x18U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x18U];
            __Vtemp_h69ad7b66__0[0x19U] = VTop__ConstPool__CONST_hd6b7ba52_0[0x19U];
            __Vtemp_h69ad7b66__0[0x1aU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1aU];
            __Vtemp_h69ad7b66__0[0x1bU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1bU];
            __Vtemp_h69ad7b66__0[0x1cU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1cU];
            __Vtemp_h69ad7b66__0[0x1dU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1dU];
            __Vtemp_h69ad7b66__0[0x1eU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1eU];
            __Vtemp_h69ad7b66__0[0x1fU] = VTop__ConstPool__CONST_hd6b7ba52_0[0x1fU];
        }
    } else {
        __Vtemp_h69ad7b66__0[4U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[4U];
        __Vtemp_h69ad7b66__0[5U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[5U];
        __Vtemp_h69ad7b66__0[6U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[6U];
        __Vtemp_h69ad7b66__0[7U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[7U];
        __Vtemp_h69ad7b66__0[8U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[8U];
        __Vtemp_h69ad7b66__0[9U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[9U];
        __Vtemp_h69ad7b66__0[0xaU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xaU];
        __Vtemp_h69ad7b66__0[0xbU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xbU];
        __Vtemp_h69ad7b66__0[0xcU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xcU];
        __Vtemp_h69ad7b66__0[0xdU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xdU];
        __Vtemp_h69ad7b66__0[0xeU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xeU];
        __Vtemp_h69ad7b66__0[0xfU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0xfU];
        __Vtemp_h69ad7b66__0[0x10U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x10U];
        __Vtemp_h69ad7b66__0[0x11U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x11U];
        __Vtemp_h69ad7b66__0[0x12U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x12U];
        __Vtemp_h69ad7b66__0[0x13U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x13U];
        __Vtemp_h69ad7b66__0[0x14U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x14U];
        __Vtemp_h69ad7b66__0[0x15U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x15U];
        __Vtemp_h69ad7b66__0[0x16U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x16U];
        __Vtemp_h69ad7b66__0[0x17U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x17U];
        __Vtemp_h69ad7b66__0[0x18U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x18U];
        __Vtemp_h69ad7b66__0[0x19U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x19U];
        __Vtemp_h69ad7b66__0[0x1aU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1aU];
        __Vtemp_h69ad7b66__0[0x1bU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1bU];
        __Vtemp_h69ad7b66__0[0x1cU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1cU];
        __Vtemp_h69ad7b66__0[0x1dU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1dU];
        __Vtemp_h69ad7b66__0[0x1eU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1eU];
        __Vtemp_h69ad7b66__0[0x1fU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0x1fU];
    }
    if ((((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
          & (4U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
         & (0xbcU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_h570d8b70__0[0U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[0U];
        __Vtemp_h570d8b70__0[1U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[1U];
        __Vtemp_h570d8b70__0[2U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[2U];
        __Vtemp_h570d8b70__0[3U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0U] 
            = __Vtemp_h570d8b70__0[0U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[1U] 
            = __Vtemp_h570d8b70__0[1U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[2U] 
            = __Vtemp_h570d8b70__0[2U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[3U] 
            = __Vtemp_h570d8b70__0[3U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[4U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[5U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[6U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[7U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[8U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[9U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xaU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xbU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xcU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xdU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xeU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xfU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x10U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x11U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x12U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x13U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x14U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x15U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x16U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x17U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x18U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x19U] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1aU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1bU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1cU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1dU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1eU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1fU] 
            = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_19[3U] 
                          >> 0x1fU)));
    } else {
        if ((((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
              & (4U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
             & (0xbcU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
            __Vtemp_h570d8b70__0[0U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[0U];
            __Vtemp_h570d8b70__0[1U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[1U];
            __Vtemp_h570d8b70__0[2U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[2U];
            __Vtemp_h570d8b70__0[3U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_21[3U];
        } else if ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                     & (4U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                    & (0xbcU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
            __Vtemp_h570d8b70__0[0U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[0U];
            __Vtemp_h570d8b70__0[1U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[1U];
            __Vtemp_h570d8b70__0[2U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[2U];
            __Vtemp_h570d8b70__0[3U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_23[3U];
        } else if ((0xbcU == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc))) {
            if ((0U == (0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                 >> 7U)))) {
                __Vtemp_h570d8b70__0[0U] = VTop__ConstPool__CONST_hcda40ff1_0[0U];
                __Vtemp_h570d8b70__0[1U] = VTop__ConstPool__CONST_hcda40ff1_0[1U];
                __Vtemp_h570d8b70__0[2U] = VTop__ConstPool__CONST_hcda40ff1_0[2U];
                __Vtemp_h570d8b70__0[3U] = VTop__ConstPool__CONST_hcda40ff1_0[3U];
            } else if ((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
                __Vtemp_h570d8b70__0[0U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[0U];
                __Vtemp_h570d8b70__0[1U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[1U];
                __Vtemp_h570d8b70__0[2U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[2U];
                __Vtemp_h570d8b70__0[3U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25[3U];
            } else if ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
                __Vtemp_h570d8b70__0[0U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[0U];
                __Vtemp_h570d8b70__0[1U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[1U];
                __Vtemp_h570d8b70__0[2U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[2U];
                __Vtemp_h570d8b70__0[3U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27[3U];
            } else if ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
                __Vtemp_h570d8b70__0[0U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[0U];
                __Vtemp_h570d8b70__0[1U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[1U];
                __Vtemp_h570d8b70__0[2U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[2U];
                __Vtemp_h570d8b70__0[3U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29[3U];
            } else if ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew))) {
                __Vtemp_h570d8b70__0[0U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[0U];
                __Vtemp_h570d8b70__0[1U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[1U];
                __Vtemp_h570d8b70__0[2U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[2U];
                __Vtemp_h570d8b70__0[3U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_31[3U];
            } else {
                __Vtemp_h570d8b70__0[0U] = VTop__ConstPool__CONST_hd6b7ba52_0[0U];
                __Vtemp_h570d8b70__0[1U] = VTop__ConstPool__CONST_hd6b7ba52_0[1U];
                __Vtemp_h570d8b70__0[2U] = VTop__ConstPool__CONST_hd6b7ba52_0[2U];
                __Vtemp_h570d8b70__0[3U] = VTop__ConstPool__CONST_hd6b7ba52_0[3U];
            }
        } else {
            __Vtemp_h570d8b70__0[0U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[0U];
            __Vtemp_h570d8b70__0[1U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[1U];
            __Vtemp_h570d8b70__0[2U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[2U];
            __Vtemp_h570d8b70__0[3U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_16[3U];
        }
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0U] 
            = __Vtemp_h570d8b70__0[0U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[1U] 
            = __Vtemp_h570d8b70__0[1U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[2U] 
            = __Vtemp_h570d8b70__0[2U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[3U] 
            = __Vtemp_h570d8b70__0[3U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[4U] 
            = __Vtemp_h69ad7b66__0[4U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[5U] 
            = __Vtemp_h69ad7b66__0[5U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[6U] 
            = __Vtemp_h69ad7b66__0[6U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[7U] 
            = __Vtemp_h69ad7b66__0[7U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[8U] 
            = __Vtemp_h69ad7b66__0[8U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[9U] 
            = __Vtemp_h69ad7b66__0[9U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xaU] 
            = __Vtemp_h69ad7b66__0[0xaU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xbU] 
            = __Vtemp_h69ad7b66__0[0xbU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xcU] 
            = __Vtemp_h69ad7b66__0[0xcU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xdU] 
            = __Vtemp_h69ad7b66__0[0xdU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xeU] 
            = __Vtemp_h69ad7b66__0[0xeU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xfU] 
            = __Vtemp_h69ad7b66__0[0xfU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x10U] 
            = __Vtemp_h69ad7b66__0[0x10U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x11U] 
            = __Vtemp_h69ad7b66__0[0x11U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x12U] 
            = __Vtemp_h69ad7b66__0[0x12U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x13U] 
            = __Vtemp_h69ad7b66__0[0x13U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x14U] 
            = __Vtemp_h69ad7b66__0[0x14U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x15U] 
            = __Vtemp_h69ad7b66__0[0x15U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x16U] 
            = __Vtemp_h69ad7b66__0[0x16U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x17U] 
            = __Vtemp_h69ad7b66__0[0x17U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x18U] 
            = __Vtemp_h69ad7b66__0[0x18U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x19U] 
            = __Vtemp_h69ad7b66__0[0x19U];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1aU] 
            = __Vtemp_h69ad7b66__0[0x1aU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1bU] 
            = __Vtemp_h69ad7b66__0[0x1bU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1cU] 
            = __Vtemp_h69ad7b66__0[0x1cU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1dU] 
            = __Vtemp_h69ad7b66__0[0x1dU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1eU] 
            = __Vtemp_h69ad7b66__0[0x1eU];
        Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1fU] 
            = __Vtemp_h69ad7b66__0[0x1fU];
    }
    Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data 
        = ((0x4000U & vlSelf->Top__DOT__core__DOT__if_reg_ins)
            ? (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                        >> 0xfU)) : ((6U == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController_io_forwardRS1))
                                      ? vlSelf->Top__DOT__core__DOT__mem_reg_csr_data
                                      : ((5U == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController_io_forwardRS1))
                                          ? vlSelf->Top__DOT__core__DOT__ex_reg_csr_data
                                          : ((4U == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController_io_forwardRS1))
                                              ? vlSelf->Top__DOT__core__DOT__id_reg_csr_data
                                              : ((3U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController_io_forwardRS1))
                                                  ? vlSelf->Top__DOT__core__DOT__IDecode_io_writeData
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController_io_forwardRS1))
                                                   ? 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead)
                                                    ? vlSelf->Top__DOT__dmem__DOT__sram_rdata_o
                                                    : vlSelf->Top__DOT__core__DOT__ex_reg_result)
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController_io_forwardRS1))
                                                    ? vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult
                                                    : vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers_io_readData_1)))))));
    vlSelf->Top__DOT__core__DOT___npc_T_6 = ((1U & 
                                              ((~ (
                                                   ((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead) 
                                                    & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_branch)) 
                                                   & (((0x1fU 
                                                        & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                                           >> 7U)) 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                           >> 0xfU))) 
                                                      | ((0x1fU 
                                                          & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                                             >> 7U)) 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                             >> 0x14U)))))) 
                                               & (~ (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__hdu__DOT___T_14))))
                                              ? ((IData)(vlSelf->Top__DOT__core__DOT__IDecode_io_pcSrc)
                                                  ? 
                                                 ((1U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_jump))
                                                   ? 
                                                  (vlSelf->Top__DOT__core__DOT__if_reg_pc 
                                                   + vlSelf->Top__DOT__core__DOT__IDecode__DOT__immediate_io_out)
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_jump))
                                                    ? 
                                                   ((((0x1fU 
                                                       & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                          >> 0xfU)) 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                                          >> 7U)))
                                                      ? vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult
                                                      : 
                                                     (((0x1fU 
                                                        & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                           >> 0xfU)) 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                                           >> 7U)))
                                                       ? vlSelf->Top__DOT__core__DOT__ex_reg_result
                                                       : 
                                                      (((0x1fU 
                                                         & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                            >> 0xfU)) 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->Top__DOT__core__DOT__mem_reg_ins 
                                                            >> 7U)))
                                                        ? vlSelf->Top__DOT__core__DOT__IDecode_io_writeData
                                                        : 
                                                       (((0x1fU 
                                                          & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                             >> 0xfU)) 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                                             >> 7U)))
                                                         ? vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult
                                                         : vlSelf->Top__DOT__core__DOT__IDecode_io_readData1)))) 
                                                    + vlSelf->Top__DOT__core__DOT__IDecode__DOT__immediate_io_out)
                                                    : 
                                                   (vlSelf->Top__DOT__core__DOT__if_reg_pc 
                                                    + vlSelf->Top__DOT__core__DOT__IDecode__DOT__immediate_io_out)))
                                                  : 
                                                 (((0U 
                                                    != vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o) 
                                                   & ((0U 
                                                       == 
                                                       (3U 
                                                        & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                            >> 0xeU))) 
                                                       | ((1U 
                                                           == 
                                                           (3U 
                                                            & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                               >> 0xeU))) 
                                                          | (3U 
                                                             == 
                                                             (3U 
                                                              & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                 >> 0xeU)))))
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (3U 
                                                         & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                             >> 0xdU))) 
                                                        | (IData)(vlSelf->Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_37))
                                                        : 
                                                       ((2U 
                                                         == 
                                                         (3U 
                                                          & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)) 
                                                        & ((0U 
                                                            == 
                                                            (3U 
                                                             & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                >> 0xeU))) 
                                                           | ((1U 
                                                               == 
                                                               (3U 
                                                                & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                   >> 0xeU))) 
                                                              | ((2U 
                                                                  == 
                                                                  (3U 
                                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                      >> 0xeU))) 
                                                                 | (3U 
                                                                    == 
                                                                    (3U 
                                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                        >> 0xeU))))))))))
                                                   ? 
                                                  ((IData)(Top__DOT__core__DOT__pc_io_halt)
                                                    ? vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg
                                                    : 
                                                   ((IData)(2U) 
                                                    + vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg))
                                                   : vlSelf->Top__DOT__core__DOT__pc_io_pc4))
                                              : vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg);
    if ((((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
          & (3U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
         & (0xbbU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_hf12b2bb9__0[4U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[5U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[6U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[7U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[8U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[9U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xaU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xbU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xcU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xdU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xeU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xfU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x10U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x11U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x12U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x13U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x14U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x15U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x16U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x17U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x18U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x19U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1aU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1bU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1cU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1dU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1eU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1fU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U] 
                                                  >> 0x1fU)));
    } else if ((((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                 & (3U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                & (0xbbU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_hf12b2bb9__0[4U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[5U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[6U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[7U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[8U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[9U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xaU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xbU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xcU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xdU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xeU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xfU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x10U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x11U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x12U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x13U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x14U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x15U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x16U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x17U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x18U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x19U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1aU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1bU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1cU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1dU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1eU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1fU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U] 
                                                  >> 0x1fU)));
    } else if ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                 & (3U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                & (0xbbU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_hf12b2bb9__0[4U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[5U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[6U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[7U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[8U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[9U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xaU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xbU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xcU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xdU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xeU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xfU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x10U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x11U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x12U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x13U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x14U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x15U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x16U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x17U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x18U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x19U] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1aU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1bU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1cU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1dU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1eU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1fU] = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U] 
                                                  >> 0x1fU)));
    } else if ((((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                 & (4U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                & (0xbcU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_hf12b2bb9__0[4U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[5U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[6U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[7U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[8U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[9U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                               >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xaU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xbU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xcU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xdU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xeU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0xfU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                 >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x10U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x11U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x12U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x13U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x14U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x15U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x16U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x17U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x18U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x19U] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1aU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1bU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1cU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1dU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1eU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
        __Vtemp_hf12b2bb9__0[0x1fU] = (- (IData)((Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U] 
                                                  >> 0x1fU)));
    } else {
        __Vtemp_hf12b2bb9__0[4U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[4U];
        __Vtemp_hf12b2bb9__0[5U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[5U];
        __Vtemp_hf12b2bb9__0[6U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[6U];
        __Vtemp_hf12b2bb9__0[7U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[7U];
        __Vtemp_hf12b2bb9__0[8U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[8U];
        __Vtemp_hf12b2bb9__0[9U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[9U];
        __Vtemp_hf12b2bb9__0[0xaU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xaU];
        __Vtemp_hf12b2bb9__0[0xbU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xbU];
        __Vtemp_hf12b2bb9__0[0xcU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xcU];
        __Vtemp_hf12b2bb9__0[0xdU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xdU];
        __Vtemp_hf12b2bb9__0[0xeU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xeU];
        __Vtemp_hf12b2bb9__0[0xfU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0xfU];
        __Vtemp_hf12b2bb9__0[0x10U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x10U];
        __Vtemp_hf12b2bb9__0[0x11U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x11U];
        __Vtemp_hf12b2bb9__0[0x12U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x12U];
        __Vtemp_hf12b2bb9__0[0x13U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x13U];
        __Vtemp_hf12b2bb9__0[0x14U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x14U];
        __Vtemp_hf12b2bb9__0[0x15U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x15U];
        __Vtemp_hf12b2bb9__0[0x16U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x16U];
        __Vtemp_hf12b2bb9__0[0x17U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x17U];
        __Vtemp_hf12b2bb9__0[0x18U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x18U];
        __Vtemp_hf12b2bb9__0[0x19U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x19U];
        __Vtemp_hf12b2bb9__0[0x1aU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1aU];
        __Vtemp_hf12b2bb9__0[0x1bU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1bU];
        __Vtemp_hf12b2bb9__0[0x1cU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1cU];
        __Vtemp_hf12b2bb9__0[0x1dU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1dU];
        __Vtemp_hf12b2bb9__0[0x1eU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1eU];
        __Vtemp_hf12b2bb9__0[0x1fU] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0x1fU];
    }
    if ((((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
          & (3U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
         & (0xbbU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
        __Vtemp_h05c677de__0[0U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[0U];
        __Vtemp_h05c677de__0[1U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[1U];
        __Vtemp_h05c677de__0[2U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[2U];
        __Vtemp_h05c677de__0[3U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0U] 
            = __Vtemp_h05c677de__0[0U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[1U] 
            = __Vtemp_h05c677de__0[1U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[2U] 
            = __Vtemp_h05c677de__0[2U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[3U] 
            = __Vtemp_h05c677de__0[3U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[4U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[5U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[6U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[7U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[8U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[9U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xaU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xbU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xcU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xdU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xeU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xfU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x10U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x11U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x12U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x13U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x14U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x15U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x16U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x17U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x18U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x19U] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1aU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1bU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1cU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1dU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1eU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1fU] 
            = (- (IData)((vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9[3U] 
                          >> 0x1fU)));
    } else {
        if ((((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
              & (3U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
             & (0xbbU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
            __Vtemp_h05c677de__0[0U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[0U];
            __Vtemp_h05c677de__0[1U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[1U];
            __Vtemp_h05c677de__0[2U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[2U];
            __Vtemp_h05c677de__0[3U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11[3U];
        } else if ((((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                     & (3U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                    & (0xbbU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
            __Vtemp_h05c677de__0[0U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[0U];
            __Vtemp_h05c677de__0[1U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[1U];
            __Vtemp_h05c677de__0[2U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[2U];
            __Vtemp_h05c677de__0[3U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13[3U];
        } else if ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                     & (3U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                    & (0xbbU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
            __Vtemp_h05c677de__0[0U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[0U];
            __Vtemp_h05c677de__0[1U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[1U];
            __Vtemp_h05c677de__0[2U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[2U];
            __Vtemp_h05c677de__0[3U] = vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15[3U];
        } else if ((((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_v_sew)) 
                     & (4U == (7U & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) 
                    & (0xbcU != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc)))) {
            __Vtemp_h05c677de__0[0U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[0U];
            __Vtemp_h05c677de__0[1U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[1U];
            __Vtemp_h05c677de__0[2U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[2U];
            __Vtemp_h05c677de__0[3U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_17[3U];
        } else {
            __Vtemp_h05c677de__0[0U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[0U];
            __Vtemp_h05c677de__0[1U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[1U];
            __Vtemp_h05c677de__0[2U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[2U];
            __Vtemp_h05c677de__0[3U] = Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_20[3U];
        }
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0U] 
            = __Vtemp_h05c677de__0[0U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[1U] 
            = __Vtemp_h05c677de__0[1U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[2U] 
            = __Vtemp_h05c677de__0[2U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[3U] 
            = __Vtemp_h05c677de__0[3U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[4U] 
            = __Vtemp_hf12b2bb9__0[4U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[5U] 
            = __Vtemp_hf12b2bb9__0[5U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[6U] 
            = __Vtemp_hf12b2bb9__0[6U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[7U] 
            = __Vtemp_hf12b2bb9__0[7U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[8U] 
            = __Vtemp_hf12b2bb9__0[8U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[9U] 
            = __Vtemp_hf12b2bb9__0[9U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xaU] 
            = __Vtemp_hf12b2bb9__0[0xaU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xbU] 
            = __Vtemp_hf12b2bb9__0[0xbU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xcU] 
            = __Vtemp_hf12b2bb9__0[0xcU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xdU] 
            = __Vtemp_hf12b2bb9__0[0xdU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xeU] 
            = __Vtemp_hf12b2bb9__0[0xeU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0xfU] 
            = __Vtemp_hf12b2bb9__0[0xfU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x10U] 
            = __Vtemp_hf12b2bb9__0[0x10U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x11U] 
            = __Vtemp_hf12b2bb9__0[0x11U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x12U] 
            = __Vtemp_hf12b2bb9__0[0x12U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x13U] 
            = __Vtemp_hf12b2bb9__0[0x13U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x14U] 
            = __Vtemp_hf12b2bb9__0[0x14U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x15U] 
            = __Vtemp_hf12b2bb9__0[0x15U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x16U] 
            = __Vtemp_hf12b2bb9__0[0x16U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x17U] 
            = __Vtemp_hf12b2bb9__0[0x17U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x18U] 
            = __Vtemp_hf12b2bb9__0[0x18U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x19U] 
            = __Vtemp_hf12b2bb9__0[0x19U];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1aU] 
            = __Vtemp_hf12b2bb9__0[0x1aU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1bU] 
            = __Vtemp_hf12b2bb9__0[0x1bU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1cU] 
            = __Vtemp_hf12b2bb9__0[0x1cU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1dU] 
            = __Vtemp_hf12b2bb9__0[0x1dU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1eU] 
            = __Vtemp_hf12b2bb9__0[0x1eU];
        vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25[0x1fU] 
            = __Vtemp_hf12b2bb9__0[0x1fU];
    }
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
        = ((3U == (3U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                         >> 0xcU))) ? (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__r_data 
                                       & (~ Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data))
            : ((2U == (3U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                             >> 0xcU))) ? (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__r_data 
                                           | Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data)
                : ((1U == (3U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                 >> 0xcU))) ? Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data
                    : 0U)));
    vlSelf->Top__DOT__core__DOT__pc_io_in = ((IData)(vlSelf->Top__DOT__core__DOT___GEN_17)
                                              ? vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg
                                              : vlSelf->Top__DOT__core__DOT___npc_T_6);
    if ((0x305U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                    >> 0x14U))) {
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 
            = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
            = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
            = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG;
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
            = (7U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
    } else {
        vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 
            = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG;
        if ((0x341U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                        >> 0x14U))) {
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
                = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
                = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG;
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                = (7U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
        } else {
            vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
                = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
            if ((0x304U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U))) {
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
                    = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                    = (7U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
            } else {
                vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
                    = vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG;
                if ((3U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U))) {
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                        = (1U & vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 1U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 2U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 3U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 4U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                        = (7U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 5U));
                } else if ((1U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                   >> 0x14U))) {
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                        = (1U & vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 1U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 2U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 3U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                        = (1U & (vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 4U));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                        = (7U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
                } else {
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
                    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                        = (7U & ((2U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                         >> 0x14U))
                                  ? vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data
                                  : (IData)(vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG)));
                }
            }
        }
    }
    vlSelf->Top__DOT__core__DOT__Realigner_io_ral_address_o 
        = ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg)) 
             & (vlSelf->Top__DOT__core__DOT__pc_io_in 
                >> 1U)) & (~ (IData)(vlSelf->Top__DOT__core__DOT__IDecode_io_pcSrc)))
            ? ((IData)(4U) + vlSelf->Top__DOT__core__DOT__pc_io_in)
            : vlSelf->Top__DOT__core__DOT__pc_io_in);
}

VL_ATTR_COLD void VTop___024root___initial__TOP__0(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
    VTop___024root___initial__TOP__0(vlSelf);
}

VL_ATTR_COLD void VTop___024root___settle__TOP__0(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Body
    VTop___024root___settle__TOP__0(vlSelf);
    VTop___024root___settle__TOP__1(vlSelf);
}

VL_ATTR_COLD void VTop___024root___final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___final\n"); );
}

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_pin = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->io_v_pin);
    vlSelf->io_fcsr = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__InstructionFetch_io_instruction = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode_io_readData1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode_io_readData2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode_io_func7 = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__core__DOT__IDecode_io_pcSrc = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode_io_stall = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute_io_vl = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute_io_vta = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute_io_v_sew = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute_io_stall = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__MEM_io_writeEnable = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__MEM_io_readData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_valid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_bits_dataRequest = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_bits_activeByteLane = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__pc_io_in = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__pc_io_pc4 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Realigner_io_ral_address_o = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__if_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__if_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__if_reg_lmul_v = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__if_pc4_out = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__if_reg_eew = VL_RAND_RESET_I(10);
    vlSelf->Top__DOT__core__DOT__if_reg_lsuType = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__id_pc4_out = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_rd1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_rd2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_imm = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_wra = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__id_reg_f7 = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__core__DOT__id_reg_f3 = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__id_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_regWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_memRead = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_memWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluOp = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__id_reg_is_csr = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_csr_data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_z_imm = VL_RAND_RESET_I(11);
    vlSelf->Top__DOT__core__DOT__id_reg_vstart_out = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_vtype = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__id_reg_v_addi_imm = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__id_reg_v0_data);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__id_reg_v1_data);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__id_reg_v2_data);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__id_reg_vs3_data);
    vlSelf->Top__DOT__core__DOT__id_reg_vs1_addr = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__id_reg_vs2_addr = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__id_reg_vd_addr = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__id_reg_lmul_v = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__id_reg_eew = VL_RAND_RESET_I(10);
    vlSelf->Top__DOT__core__DOT__id_reg_lsuType = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_RegWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_opBsel = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_Ex_sel = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluop = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_vset = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_v_ins = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_v_memRead = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_v_MemWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_pc4_out = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__ex_reg_result = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__ex_reg_wd = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__ex_reg_wra = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__ex_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_regWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__ex_reg_is_csr = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_csr_data = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__ex_reg_vec_alu_res);
    vlSelf->Top__DOT__core__DOT__ex_reg_vl = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__ex_reg_vd_addr = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__ex_reg_lmul_v = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__ex_reg_vset = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_v_memRead = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_v_MemWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_reg_write = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__ex_reg_vtype = VL_RAND_RESET_I(11);
    vlSelf->Top__DOT__core__DOT__ex_reg_eew = VL_RAND_RESET_I(10);
    vlSelf->Top__DOT__core__DOT__ex_reg_lsuType = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__ex_reg_read_data1 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__ex_reg_vs3);
    vlSelf->Top__DOT__core__DOT__ex_reg_v_ins = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__mem_reg_ins = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__mem_reg_result = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__mem_reg_wra = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__mem_reg_ctl_memToReg = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__mem_reg_pc = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__mem_reg_is_csr = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__mem_reg_csr_data = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__mem_reg_vec_alu_out);
    vlSelf->Top__DOT__core__DOT__mem_reg_vec_vl = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__mem_reg_vtype = VL_RAND_RESET_I(11);
    vlSelf->Top__DOT__core__DOT__mem_reg_vec_vd_addr = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__mem_reg_lmul_v = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__mem_reg_vset = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__mem_reg_vec_reg_write = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__lmul = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__lmul_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__delays = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__vlmul_count = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___lmul_reg_T_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___delays_T_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___GEN_17 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__count = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__addrcount = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__vlcount = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___T_83 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT___GEN_32 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___GEN_33 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___GEN_34 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___GEN_35 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___count_T_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IF_stall = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT___npc_T_6 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___GEN_61 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__npcDelay_0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__npcDelay_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__npcDelay_2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__npcDelay_3 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_0 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_1 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_0 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_1 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__rsDataDelay_0_0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__rsDataDelay_0_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__rsDataDelay_1_0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__rsDataDelay_1_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__memAddrDelay = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__memWdataDelay = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__stallDelay_0 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__stallDelay_1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__stallDelay_2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__stallDelay_3 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT___GEN_2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr_io_i_w_en = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController_io_forwardRS1 = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__hdu_io_if_reg_write = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_branch = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__control_io_jump = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__Vcontrol_io_RegWrite = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__Vcontrol_io_RegRead = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers_io_writeEnable = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers_io_writeAddress = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers_io_readData_1 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers_io_vs3_data);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__immediate_io_out = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_rd2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__bu_io_taken = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MHARTID_REG = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MCAUSE_REG = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TW_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPRV_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPP_REG = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPIE_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MIE_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_WIRE = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__r_data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT__w_data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController__DOT___hazard_DecEx_T_4 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController__DOT___hazard_DecEx_T_7 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController__DOT___hazard_DecMem_T_4 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController__DOT___hazard_DecMem_T_7 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController__DOT___hazard_DecWb_T_4 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__csrController__DOT___hazard_DecWb_T_7 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__hdu__DOT___T_14 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__control__DOT___signals_T_28 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__Vcontrol__DOT___GEN_7 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__Vcontrol__DOT___GEN_14 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__Vcontrol__DOT___GEN_33 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__Vcontrol__DOT___GEN_36 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_3 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_4 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_5 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_6 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_7 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_8 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_9 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_10 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_11 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_12 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_13 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_14 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_15 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_16 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_17 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_18 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_19 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_20 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_21 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_22 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_23 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_24 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_25 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_26 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_27 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_28 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_29 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_30 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT__reg_31 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT___GEN_77 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT___GEN_90 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__registers__DOT___GEN_110 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_0);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_1);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_2);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_3);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_4);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_5);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_6);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_7);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_8);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_9);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_10);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_11);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_12);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_13);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_14);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_15);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_16);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_17);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_18);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_19);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_20);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_21);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_22);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_23);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_24);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_25);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_26);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_27);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_28);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_29);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_30);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__register_31);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__vs1_in = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__vs2_in = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT__vs3_in = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_31);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_63);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_96);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_97);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_98);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_99);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_100);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_101);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_102);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_103);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_104);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_105);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_106);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_107);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_108);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_109);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_110);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_111);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_112);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_113);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_114);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_115);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_116);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_117);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_118);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_119);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_120);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_121);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_122);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_123);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_124);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_125);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_126);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_127);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__IDecode__DOT__v_registers__DOT___GEN_281);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__immediate__DOT___GEN_2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__vec_csr__DOT__vtypeReg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__IDecode__DOT__vec_csr__DOT__vlReg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__alu_io_input2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardA = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardC = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__Vec_aluCtl_io_aluc = VL_RAND_RESET_I(9);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_A = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_in_B = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs1);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu_io_vs2);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rs1 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rd = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config_io_rs1_readdata = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__inputMux1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT___inputMux2_T_4 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vlReg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_14 = VL_RAND_RESET_I(11);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__src_a_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__src_b_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__op_reg = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__f7_reg = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__counter = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_22 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT___counter_T_1 = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_34 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_38 = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_44 = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_9 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_15 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_55 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_60 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_66 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_72 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_112 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_169 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_226 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_231 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_237 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_243 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_283 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_288 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_294 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_300 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_340 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_3);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_397 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_454 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_511 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_568 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_573 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_579 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_585 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_625 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_630 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_636 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_642 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_682 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_687 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_693 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_699 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_739 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_744 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_750 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_756 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_796 = VL_RAND_RESET_I(16);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_5);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_853 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_910 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_967 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1024 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1081 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1138 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1195 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1252 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1257 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1263 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1269 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1309 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1314 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1320 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1326 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1366 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1371 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1377 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1383 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1423 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1428 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1434 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1440 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1480 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1485 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1491 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1497 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1537 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1542 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1548 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1554 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1594 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1599 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1605 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1611 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1651 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1656 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1662 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1668 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_1708 = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_7);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_9);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_11);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_13);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_15);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3178 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3250 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3324 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3396 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3468 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3540 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3608 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3680 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3752 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3824 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3896 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_3968 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4040 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4112 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4184 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4256 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4328 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4400 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4472 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4544 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4616 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4688 = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4760 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4832 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4904 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_4976 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5048 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5120 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5192 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5264 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5336 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_25);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5394 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5423 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5452 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(256, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_27);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5510 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5539 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5568 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5597 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5626 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5655 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5684 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(512, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_29);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5742 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5771 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5800 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5829 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5858 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5887 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5916 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5945 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_5974 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6003 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6032 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6061 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6090 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6119 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_out_T_6148 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(512, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT__io_v_output_lo_14);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_35);
    VL_RAND_RESET_W(256, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_37);
    VL_RAND_RESET_W(1024, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_39);
    VL_RAND_RESET_W(512, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_5);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_43);
    VL_RAND_RESET_W(256, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_45);
    VL_RAND_RESET_W(1024, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___io_v_output_T_47);
    VL_RAND_RESET_W(512, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_10);
    VL_RAND_RESET_W(1024, vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_alu__DOT___GEN_25);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___GEN_2 = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___GEN_5 = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___GEN_8 = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___GEN_10 = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT__valmax = VL_RAND_RESET_Q(36);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___GEN_19 = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___avl_T_7 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__vec_config__DOT___GEN_20 = VL_RAND_RESET_Q(36);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_ready = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_4 = VL_RAND_RESET_I(6);
    VL_RAND_RESET_W(95, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_13 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(95, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__core__DOT__MEM__DOT__offset = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__MEM__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__core__DOT__MEM__DOT__addr = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__MEM__DOT__data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__vlsu__DOT__eew = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__core__DOT__Realigner__DOT__lhw_reg = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_37 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dmem__DOT__sram_csb_i = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dmem__DOT__sram_we_i = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dmem__DOT__sram_rdata_o = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__dmem__DOT__validReg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__csb0_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__web0_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__wmask0_reg = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg = VL_RAND_RESET_I(13);
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__din0_reg = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__imem__DOT__sram_rdata_o = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__imem__DOT__validReg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__csb0_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__web0_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__wmask0_reg = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg = VL_RAND_RESET_I(13);
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__din0_reg = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__tracer__DOT__clkCycle = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__tracer__DOT___clkCycle_T_1 = VL_RAND_RESET_I(32);
}
