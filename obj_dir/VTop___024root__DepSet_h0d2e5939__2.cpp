// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"

#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___combo__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___combo__TOP__1\n"); );
    // Init
    CData/*0:0*/ Top__DOT__core__DOT__pc_io_halt;
    VlWide<3>/*95:0*/ __Vtemp_h08bfe934__0;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__0;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__1;
    VlWide<3>/*95:0*/ __Vtemp_h7c9a1e7c__0;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__2;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__3;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__4;
    VlWide<3>/*95:0*/ __Vtemp_hf60a55f6__5;
    // Body
    vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid 
        = (1U & (~ ((IData)(vlSelf->reset) | (((IData)(vlSelf->Top__DOT__core__DOT__Execute_io_stall) 
                                               | (IData)(vlSelf->Top__DOT__core__DOT__IDecode_io_stall)) 
                                              | (IData)(vlSelf->Top__DOT__core__DOT__IF_stall)))));
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
        vlSelf->Top__DOT__core__DOT___GEN_2 = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U] = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[1U] = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[2U] = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29 = 0ULL;
    } else {
        vlSelf->Top__DOT__core__DOT___GEN_2 = ((((vlSelf->Top__DOT__core__DOT__lmul_reg 
                                                  != vlSelf->Top__DOT__core__DOT__vlmul_count) 
                                                 & (0x57U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o))) 
                                                & (7U 
                                                   != 
                                                   (7U 
                                                    & (vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o 
                                                       >> 0xcU))))
                                                ? vlSelf->Top__DOT__core__DOT__lmul_reg
                                                : (
                                                   ((vlSelf->Top__DOT__core__DOT__delays 
                                                     != 
                                                     ((0x27U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o))
                                                       ? 4U
                                                       : 0U)) 
                                                    & (0x27U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o)))
                                                    ? (IData)(vlSelf->Top__DOT__core__DOT__if_reg_lmul_v)
                                                    : vlSelf->Top__DOT__core__DOT__lmul_reg));
        if (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
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
    }
    Top__DOT__core__DOT__pc_io_halt = (1U & (((((IData)(vlSelf->Top__DOT__core__DOT__Execute_io_stall) 
                                                | (IData)(vlSelf->Top__DOT__core__DOT__IDecode_io_stall)) 
                                               | (IData)(vlSelf->Top__DOT__core__DOT__IF_stall)) 
                                              | (~ (IData)(vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid))) 
                                             | (1U 
                                                == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))));
    vlSelf->Top__DOT__core__DOT__pc_io_pc4 = ((IData)(Top__DOT__core__DOT__pc_io_halt)
                                               ? vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg
                                               : ((IData)(4U) 
                                                  + vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg));
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
    vlSelf->Top__DOT__core__DOT__pc_io_in = ((IData)(vlSelf->Top__DOT__core__DOT___GEN_17)
                                              ? vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg
                                              : vlSelf->Top__DOT__core__DOT___npc_T_6);
    vlSelf->Top__DOT__core__DOT__Realigner_io_ral_address_o 
        = ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg)) 
             & (vlSelf->Top__DOT__core__DOT__pc_io_in 
                >> 1U)) & (~ (IData)(vlSelf->Top__DOT__core__DOT__IDecode_io_pcSrc)))
            ? ((IData)(4U) + vlSelf->Top__DOT__core__DOT__pc_io_in)
            : vlSelf->Top__DOT__core__DOT__pc_io_in);
}

void VTop___024root___sequent__TOP__0(VTop___024root* vlSelf);
void VTop___024root___sequent__TOP__1(VTop___024root* vlSelf);
void VTop___024root___sequent__TOP__3(VTop___024root* vlSelf);
void VTop___024root___combo__TOP__0(VTop___024root* vlSelf);
void VTop___024root___multiclk__TOP__0(VTop___024root* vlSelf);

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VTop___024root___sequent__TOP__0(vlSelf);
        VTop___024root___sequent__TOP__1(vlSelf);
    }
    if (((~ (IData)(vlSelf->clock)) & (IData)(vlSelf->__Vclklast__TOP__clock))) {
        VTop___024root___sequent__TOP__3(vlSelf);
    }
    VTop___024root___combo__TOP__0(vlSelf);
    if (((IData)(vlSelf->clock) ^ (IData)(vlSelf->__Vclklast__TOP__clock))) {
        VTop___024root___multiclk__TOP__0(vlSelf);
    }
    VTop___024root___combo__TOP__1(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
