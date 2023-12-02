// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"

#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___sequent__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecMem;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx;
    CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem;
    IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_77;
    IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_110;
    IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_123;
    IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_2;
    CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT___T_23;
    CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT___GEN_1;
    SData/*15:0*/ Top__DOT__core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest_lo;
    SData/*15:0*/ Top__DOT__core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest_hi;
    CData/*0:0*/ __Vdly__Top__DOT__core__DOT__Execute__DOT__div_en;
    CData/*5:0*/ __Vdly__Top__DOT__core__DOT__Execute__DOT__counter;
    CData/*5:0*/ __Vdly__Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter;
    CData/*1:0*/ __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg;
    // Body
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__wmask0_reg = 0xfU;
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__din0_reg = 0U;
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg 
        = (0xfffU & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_address_o 
                     >> 2U));
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__csb0_reg 
        = (1U & (~ (IData)(vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid)));
    vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__web0_reg 
        = vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid;
    __Vdly__Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter;
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__csb0_reg 
        = vlSelf->Top__DOT__dmem__DOT__sram_csb_i;
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__web0_reg 
        = vlSelf->Top__DOT__dmem__DOT__sram_we_i;
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__din0_reg 
        = vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_bits_dataRequest;
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__wmask0_reg 
        = vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_bits_activeByteLane;
    vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg 
        = (0x7ffU & (vlSelf->Top__DOT__core__DOT__ex_reg_result 
                     >> 2U));
    __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg 
        = vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg;
    __Vdly__Top__DOT__core__DOT__Execute__DOT__counter 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__counter;
    __Vdly__Top__DOT__core__DOT__Execute__DOT__div_en 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en;
    if (VL_UNLIKELY((((IData)(vlSelf->Top__DOT__core__DOT__stallDelay_3) 
                      & (0U != vlSelf->Top__DOT__core__DOT__insDelay_3)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"ClkCycle: %10#, pc_rdata: %x, pc_wdata: %x, insn: %x, mode: 3, rs1_addr: %2#, rs1_rdata: %x, rs2_addr: %2#, rs2_rdata: %x, rd_addr: %2#, rd_wdata: %x, mem_addr: %x, mem_rdata: %x, mem_wdata: %x\n",
                   32,vlSelf->Top__DOT__tracer__DOT__clkCycle,
                   32,vlSelf->Top__DOT__core__DOT__mem_reg_pc,
                   32,vlSelf->Top__DOT__core__DOT__npcDelay_3,
                   32,vlSelf->Top__DOT__core__DOT__insDelay_3,
                   5,(IData)(vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_2),
                   32,vlSelf->Top__DOT__core__DOT__rsDataDelay_0_1,
                   5,(IData)(vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_2),
                   32,vlSelf->Top__DOT__core__DOT__rsDataDelay_1_1,
                   5,(IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra),
                   32,((1U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_memToReg))
                        ? vlSelf->Top__DOT__core__DOT__MEM_io_readData
                        : vlSelf->Top__DOT__core__DOT___GEN_6),
                   32,vlSelf->Top__DOT__core__DOT__memAddrDelay,
                   32,vlSelf->Top__DOT__core__DOT__MEM_io_readData,
                   32,vlSelf->Top__DOT__core__DOT__memWdataDelay);
    }
    if (VL_UNLIKELY((((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                      & (8U == (vlSelf->Top__DOT__core__DOT__ex_reg_result 
                                >> 0x1cU))) & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"%x\n",32,vlSelf->Top__DOT__core__DOT__ex_reg_wd);
    }
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MHARTID_REG = 0U;
    vlSelf->Top__DOT__core__DOT__Execute__DOT__f7_reg 
        = (0x3fU & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_24));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_ready 
        = ((IData)(vlSelf->reset) | (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_13));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient 
        = (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend 
        = vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28[0U];
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead 
        = ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_memRead));
    vlSelf->Top__DOT__core__DOT__mem_reg_is_csr = (
                                                   (~ (IData)(vlSelf->reset)) 
                                                   & (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_is_csr));
    vlSelf->Top__DOT__imem__DOT__validReg = ((~ (IData)(vlSelf->reset)) 
                                             & (IData)(vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid));
    vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite 
        = ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_regWrite));
    __Vdly__Top__DOT__core__DOT__Execute__DOT__div_en 
        = ((~ (IData)(vlSelf->reset)) & ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en)
                                          ? (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_14)
                                          : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_2)));
    if (vlSelf->reset) {
        __Vdly__Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter = 0x20U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter 
            = __Vdly__Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TW_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCAUSE_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPRV_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPP_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPIE_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MIE_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG = 0U;
        vlSelf->Top__DOT__core__DOT__mem_reg_csr_data = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluOp = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_27 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_29 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_31 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_28 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_30 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_26 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_21 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_19 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_20 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_14 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_22 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_23 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_24 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_25 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_15 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_16 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_17 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_18 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_9 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_7 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_11 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_2 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_10 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_1 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_5 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_6 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_8 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_0 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_3 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_12 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_4 = 0U;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_13 = 0U;
        __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg = 0U;
        vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg 
            = __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg;
        vlSelf->Top__DOT__core__DOT__Realigner__DOT__lhw_reg = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__src_a_reg = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__src_b_reg = 0U;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__op_reg = 0U;
        __Vdly__Top__DOT__core__DOT__Execute__DOT__counter = 0U;
    } else {
        if (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
             | (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u))) {
            if (vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid) {
                __Vdly__Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter = 0x20U;
            } else if ((0U != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter))) {
                __Vdly__Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter 
                    = vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_4;
            }
        }
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter 
            = __Vdly__Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter;
        if (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr_io_i_w_en) {
            if ((0x300U != (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U))) {
                if ((0x342U != (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                >> 0x14U))) {
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32;
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31;
                }
                if ((0x342U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                >> 0x14U))) {
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCAUSE_REG 
                        = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
                }
            }
            if ((0x300U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TW_REG 
                    = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                             >> 0x15U));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPRV_REG 
                    = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                             >> 0x11U));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPP_REG 
                    = (3U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                             >> 0xbU));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPIE_REG 
                    = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                             >> 7U));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MIE_REG 
                    = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                             >> 3U));
            }
        }
        vlSelf->Top__DOT__core__DOT__mem_reg_csr_data 
            = vlSelf->Top__DOT__core__DOT__ex_reg_csr_data;
        vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluOp 
            = ((0x33U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                ? 2U : ((0x13U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                         ? 2U : ((0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                  ? 2U : 0U)));
        if (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeEnable) {
            if ((0x1bU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_27 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x1dU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_29 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x1fU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_31 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x1cU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_28 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x1eU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_30 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x1aU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_26 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x15U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_21 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x13U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_19 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x14U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_20 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0xeU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_14 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x16U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_22 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x17U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_23 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x18U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_24 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x19U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_25 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0xfU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_15 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x10U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_16 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x11U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_17 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0x12U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_18 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((9U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_9 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((7U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_7 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0xbU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_11 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((2U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_2 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0xaU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_10 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((1U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_1 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((5U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_5 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((6U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_6 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((8U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_8 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_0 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((3U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_3 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0xcU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_12 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((4U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_4 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
            if ((0xdU == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_13 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
            }
        }
        if ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))) {
            __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg 
                = ((2U & vlSelf->Top__DOT__core__DOT__pc_io_in)
                    ? 1U : 0U);
        } else if ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))) {
            __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg 
                = ((2U & vlSelf->Top__DOT__core__DOT__pc_io_in)
                    ? ((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode_io_pcSrc)
                        ? 1U : 2U) : 0U);
        } else if ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))) {
            __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg 
                = ((2U & vlSelf->Top__DOT__core__DOT__pc_io_in)
                    ? 1U : 0U);
        }
        vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg 
            = __Vdly__Top__DOT__core__DOT__Realigner__DOT__stateReg;
        vlSelf->Top__DOT__core__DOT__Realigner__DOT__lhw_reg 
            = (vlSelf->Top__DOT__core__DOT__InstructionFetch_io_instruction 
               >> 0x10U);
        if ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)) 
              & (~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en))) 
             & ((((4U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)) 
                  | (5U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                 | (6U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                | (7U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))))) {
            vlSelf->Top__DOT__core__DOT__Execute__DOT__src_a_reg 
                = ((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1))
                    ? vlSelf->Top__DOT__core__DOT__id_reg_pc
                    : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1))
                        ? 0U : vlSelf->Top__DOT__core__DOT__Execute__DOT__inputMux1));
            vlSelf->Top__DOT__core__DOT__Execute__DOT__src_b_reg 
                = ((IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc)
                    ? ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB))
                        ? vlSelf->Top__DOT__core__DOT__id_reg_rd2
                        : vlSelf->Top__DOT__core__DOT__Execute__DOT___inputMux2_T_4)
                    : vlSelf->Top__DOT__core__DOT__id_reg_imm);
            vlSelf->Top__DOT__core__DOT__Execute__DOT__op_reg 
                = vlSelf->Top__DOT__core__DOT__id_reg_f3;
        }
        if (vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en) {
            __Vdly__Top__DOT__core__DOT__Execute__DOT__counter 
                = ((0x20U > (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__counter))
                    ? (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___counter_T_1)
                    : 0U);
        }
    }
    vlSelf->Top__DOT__core__DOT__Execute__DOT__counter 
        = __Vdly__Top__DOT__core__DOT__Execute__DOT__counter;
    vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en 
        = __Vdly__Top__DOT__core__DOT__Execute__DOT__div_en;
    vlSelf->Top__DOT__core__DOT__stallDelay_3 = vlSelf->Top__DOT__core__DOT__stallDelay_2;
    vlSelf->Top__DOT__core__DOT__npcDelay_3 = vlSelf->Top__DOT__core__DOT__npcDelay_2;
    vlSelf->Top__DOT__core__DOT__rsDataDelay_1_1 = vlSelf->Top__DOT__core__DOT__rsDataDelay_1_0;
    vlSelf->Top__DOT__core__DOT__rsDataDelay_0_1 = vlSelf->Top__DOT__core__DOT__rsDataDelay_0_0;
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_2 = vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_1;
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_2 = vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_1;
    vlSelf->Top__DOT__core__DOT__insDelay_3 = vlSelf->Top__DOT__core__DOT__insDelay_2;
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_4 
        = (0x3fU & ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter) 
                    - (IData)(1U)));
    vlSelf->io_fcsr = ((((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG) 
                         << 5U) | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG) 
                                    << 4U) | ((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG) 
                                              << 3U))) 
                       | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG) 
                           << 2U) | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG) 
                                      << 1U) | (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG))));
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_memRead 
        = ((~ (IData)(vlSelf->reset)) & ((0x33U != 
                                          (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                         & ((0x13U 
                                             != (0x7fU 
                                                 & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                            & ((0x73U 
                                                != 
                                                (0x7fU 
                                                 & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                               & (3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->Top__DOT__core__DOT__if_reg_ins))))));
    vlSelf->Top__DOT__core__DOT__ex_reg_is_csr = ((~ (IData)(vlSelf->reset)) 
                                                  & (IData)(vlSelf->Top__DOT__core__DOT__id_reg_is_csr));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeEnable 
        = ((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite) 
           | (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_is_csr));
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_regWrite 
        = ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_regWrite));
    vlSelf->Top__DOT__core__DOT__Execute__DOT___counter_T_1 
        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__counter)));
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc 
        = ((~ (IData)(vlSelf->reset)) & ((0x33U == 
                                          (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                         | (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control__DOT___signals_T_28)));
    if (vlSelf->reset) {
        vlSelf->Top__DOT__core__DOT__mem_reg_ins = 0U;
        vlSelf->Top__DOT__core__DOT__MEM__DOT__offset = 0U;
        vlSelf->Top__DOT__core__DOT__MEM__DOT__funct3 = 0U;
    } else {
        vlSelf->Top__DOT__core__DOT__mem_reg_ins = vlSelf->Top__DOT__core__DOT__ex_reg_ins;
        if ((1U & (~ (IData)(vlSelf->Top__DOT__dmem__DOT__validReg)))) {
            vlSelf->Top__DOT__core__DOT__MEM__DOT__offset 
                = (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result);
            vlSelf->Top__DOT__core__DOT__MEM__DOT__funct3 
                = (7U & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                         >> 0xcU));
        }
    }
    vlSelf->Top__DOT__dmem__DOT__validReg = ((~ (IData)(vlSelf->reset)) 
                                             & (IData)(vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_valid));
    vlSelf->Top__DOT__core__DOT__stallDelay_2 = vlSelf->Top__DOT__core__DOT__stallDelay_1;
    vlSelf->Top__DOT__tracer__DOT__clkCycle = ((IData)(vlSelf->reset)
                                                ? 0U
                                                : vlSelf->Top__DOT__tracer__DOT___clkCycle_T_1);
    vlSelf->Top__DOT__tracer__DOT___clkCycle_T_1 = 
        ((IData)(1U) + vlSelf->Top__DOT__tracer__DOT__clkCycle);
    vlSelf->Top__DOT__core__DOT__npcDelay_2 = vlSelf->Top__DOT__core__DOT__npcDelay_1;
    vlSelf->Top__DOT__core__DOT__rsDataDelay_1_0 = vlSelf->Top__DOT__core__DOT__id_reg_rd2;
    vlSelf->Top__DOT__core__DOT__rsDataDelay_0_0 = vlSelf->Top__DOT__core__DOT__id_reg_rd1;
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_1 = vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_0;
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_1 = vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_0;
    vlSelf->Top__DOT__core__DOT__insDelay_2 = vlSelf->Top__DOT__core__DOT__insDelay_1;
    if (vlSelf->reset) {
        vlSelf->Top__DOT__core__DOT__memWdataDelay = 0U;
        vlSelf->Top__DOT__core__DOT__mem_reg_result = 0U;
        vlSelf->Top__DOT__core__DOT__memAddrDelay = 0U;
        vlSelf->Top__DOT__core__DOT__mem_reg_pc = 0U;
        vlSelf->Top__DOT__core__DOT__mem_reg_ctl_memToReg = 0U;
    } else {
        vlSelf->Top__DOT__core__DOT__memWdataDelay 
            = vlSelf->Top__DOT__core__DOT__ex_reg_wd;
        vlSelf->Top__DOT__core__DOT__mem_reg_result 
            = vlSelf->Top__DOT__core__DOT__ex_reg_result;
        vlSelf->Top__DOT__core__DOT__memAddrDelay = vlSelf->Top__DOT__core__DOT__ex_reg_result;
        vlSelf->Top__DOT__core__DOT__mem_reg_pc = vlSelf->Top__DOT__core__DOT__ex_reg_pc;
        vlSelf->Top__DOT__core__DOT__mem_reg_ctl_memToReg 
            = vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memToReg;
    }
    vlSelf->Top__DOT__core__DOT___GEN_6 = ((2U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_memToReg))
                                            ? ((IData)(4U) 
                                               + vlSelf->Top__DOT__core__DOT__mem_reg_pc)
                                            : vlSelf->Top__DOT__core__DOT__mem_reg_result);
    vlSelf->Top__DOT__core__DOT__id_reg_is_csr = ((~ (IData)(vlSelf->reset)) 
                                                  & (0x73U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->Top__DOT__core__DOT__if_reg_ins)));
    if (vlSelf->reset) {
        vlSelf->Top__DOT__core__DOT__ex_reg_csr_data = 0U;
        vlSelf->Top__DOT__core__DOT__mem_reg_wra = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_imm = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_f7 = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_f3 = 0U;
    } else {
        vlSelf->Top__DOT__core__DOT__ex_reg_csr_data 
            = vlSelf->Top__DOT__core__DOT__id_reg_csr_data;
        vlSelf->Top__DOT__core__DOT__mem_reg_wra = vlSelf->Top__DOT__core__DOT__ex_reg_wra;
        vlSelf->Top__DOT__core__DOT__id_reg_imm = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__immediate_io_out;
        vlSelf->Top__DOT__core__DOT__id_reg_f7 = vlSelf->Top__DOT__core__DOT__InstructionDecode_io_func7;
        vlSelf->Top__DOT__core__DOT__id_reg_f3 = (7U 
                                                  & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                     >> 0xcU));
    }
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_2 
        = ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)) 
             & (~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en))) 
            & ((((4U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)) 
                 | (5U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                | (6U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
               | (7U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)))) 
           | (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out 
        = ((0U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluOp))
            ? 2U : ((0U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                     ? ((1U & ((~ (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc)) 
                               | (~ ((IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7) 
                                     >> 5U)))) ? 2U
                         : 3U) : ((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                                   ? 6U : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                                            ? 4U : 
                                           ((3U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                                             ? 5U : 
                                            ((5U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                                              ? ((0x20U 
                                                  & (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7))
                                                  ? 8U
                                                  : 7U)
                                              : ((7U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                                                  ? 0U
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                                                   ? 1U
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))
                                                    ? 9U
                                                    : 0xfU)))))))));
    Top__DOT__core__DOT__Execute__DOT___T_23 = (((1U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)) 
                                                 & (~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en))) 
                                                & ((((4U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)) 
                                                     | (5U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                                    | (6U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                                   | (7U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))));
    Top__DOT__core__DOT__Execute__DOT___GEN_1 = (((
                                                   (1U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)) 
                                                   & (~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en))) 
                                                  & ((((4U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)) 
                                                       | (5U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                                      | (6U 
                                                         == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                                     | (7U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)))) 
                                                 | ((1U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)) 
                                                    & ((((0U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)) 
                                                         | (1U 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                                        | (2U 
                                                           == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                                       | (3U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)))));
    if (vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en) {
        vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18 
            = vlSelf->Top__DOT__core__DOT__Execute__DOT__op_reg;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid 
            = ((0x20U > (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__counter)) 
               & (IData)(Top__DOT__core__DOT__Execute__DOT___GEN_1));
    } else {
        vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18 
            = vlSelf->Top__DOT__core__DOT__id_reg_f3;
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid 
            = Top__DOT__core__DOT__Execute__DOT___GEN_1;
    }
    if (vlSelf->reset) {
        vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 0U;
        vlSelf->Top__DOT__core__DOT__ex_reg_ins = 0U;
        vlSelf->Top__DOT__core__DOT__ex_reg_wd = 0U;
        vlSelf->Top__DOT__core__DOT__ex_reg_result = 0U;
        vlSelf->Top__DOT__core__DOT__ex_reg_pc = 0U;
        vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memToReg = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_csr_data = 0U;
        vlSelf->Top__DOT__core__DOT__ex_reg_wra = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_ctl_regWrite = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_ins = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_rd1 = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_rd2 = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_pc = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 0U;
        vlSelf->Top__DOT__core__DOT__id_reg_wra = 0U;
    } else {
        vlSelf->Top__DOT__core__DOT__ex_reg_ins = vlSelf->Top__DOT__core__DOT__id_reg_ins;
        vlSelf->Top__DOT__core__DOT__ex_reg_wd = ((0U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB))
                                                   ? vlSelf->Top__DOT__core__DOT__id_reg_rd2
                                                   : vlSelf->Top__DOT__core__DOT__Execute__DOT___inputMux2_T_4);
        vlSelf->Top__DOT__core__DOT__ex_reg_result 
            = vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult;
        vlSelf->Top__DOT__core__DOT__ex_reg_pc = vlSelf->Top__DOT__core__DOT__id_reg_pc;
        vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memToReg 
            = vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg;
        if ((0x33U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 0U;
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 0U;
        } else if ((0x13U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 0U;
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 0U;
        } else if ((0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 0U;
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 0U;
        } else if ((3U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 0U;
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 1U;
        } else if ((0x23U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 0U;
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 0U;
        } else if ((0x63U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 0U;
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 0U;
        } else if ((0x37U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 = 2U;
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg = 0U;
        } else {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1 
                = (0x17U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins));
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_memToReg 
                = ((0x17U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                    ? 0U : ((0x6fU == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                             ? 2U : ((0x67U == (0x7fU 
                                                & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                      ? 2U : 0U)));
        }
        vlSelf->Top__DOT__core__DOT__id_reg_csr_data 
            = ((3U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                       >> 0x14U)) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_WIRE
                : vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17);
        vlSelf->Top__DOT__core__DOT__ex_reg_wra = vlSelf->Top__DOT__core__DOT__id_reg_wra;
        if ((1U & (~ (IData)(vlSelf->Top__DOT__core__DOT__Execute_io_stall)))) {
            vlSelf->Top__DOT__core__DOT__id_reg_ctl_regWrite 
                = (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write) 
                    & (0x13U != vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                   & ((0x33U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                      | ((0x13U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                         | ((0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                            | ((3U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                               | ((0x23U != (0x7fU 
                                             & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                  & ((0x63U != (0x7fU 
                                                & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                     & ((0x37U == (0x7fU 
                                                   & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                        | ((0x17U == 
                                            (0x7fU 
                                             & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                           | ((0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                              | (0x67U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->Top__DOT__core__DOT__if_reg_ins))))))))))));
            vlSelf->Top__DOT__core__DOT__id_reg_wra 
                = (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 7U));
        }
        vlSelf->Top__DOT__core__DOT__id_reg_ins = vlSelf->Top__DOT__core__DOT__if_reg_ins;
        vlSelf->Top__DOT__core__DOT__id_reg_rd1 = vlSelf->Top__DOT__core__DOT__InstructionDecode_io_readData1;
        vlSelf->Top__DOT__core__DOT__id_reg_rd2 = vlSelf->Top__DOT__core__DOT__InstructionDecode_io_readData2;
        vlSelf->Top__DOT__core__DOT__id_reg_pc = vlSelf->Top__DOT__core__DOT__if_reg_pc;
    }
    vlSelf->Top__DOT__core__DOT__Execute_io_stall = 
        ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en)
          ? ((0x20U > (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__counter)) 
             | (IData)(Top__DOT__core__DOT__Execute__DOT___T_23))
          : (IData)(Top__DOT__core__DOT__Execute__DOT___T_23));
    vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite 
        = ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_memWrite));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_WIRE 
        = (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG) 
            << 5U) | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG) 
                       << 4U) | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG) 
                                  << 3U) | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG) 
                                             << 2U) 
                                            | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG) 
                                                << 1U) 
                                               | (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG))))));
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_14 
        = ((0x20U > (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__counter)) 
           & (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_2));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u 
        = ((5U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)) 
           | (7U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s 
        = ((4U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)) 
           | (6U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)));
    vlSelf->Top__DOT__core__DOT__stallDelay_1 = vlSelf->Top__DOT__core__DOT__stallDelay_0;
    vlSelf->Top__DOT__core__DOT__npcDelay_1 = vlSelf->Top__DOT__core__DOT__npcDelay_0;
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_0_0 = 
        (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                  >> 0xfU));
    vlSelf->Top__DOT__core__DOT__rsAddrDelay_1_0 = 
        (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                  >> 0x14U));
    vlSelf->Top__DOT__core__DOT__insDelay_1 = vlSelf->Top__DOT__core__DOT__insDelay_0;
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_13 
        = (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
            | (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u))
            ? ((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid)) 
               & ((0U != (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter))
                   ? (1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter))
                   : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_ready)))
            : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_ready));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardA 
        = (((((0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                        >> 0xfU)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                               >> 7U))) 
             & (0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                >> 7U)))) & (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_regWrite))
            ? 1U : (((((0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                 >> 0xfU)) == (0x1fU 
                                               & (vlSelf->Top__DOT__core__DOT__mem_reg_ins 
                                                  >> 7U))) 
                      & (0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__mem_reg_ins 
                                         >> 7U)))) 
                     & (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite))
                     ? 2U : 0U));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB 
        = (((((0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                        >> 0x14U)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                                >> 7U))) 
             & (0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                >> 7U)))) & (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_regWrite))
            ? 1U : (((((0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                 >> 0x14U)) == (0x1fU 
                                                & (vlSelf->Top__DOT__core__DOT__mem_reg_ins 
                                                   >> 7U))) 
                      & (0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__mem_reg_ins 
                                         >> 7U)))) 
                     & (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite))
                     ? 2U : 0U));
    vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_bits_activeByteLane 
        = (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
            & (0U == (0x7000U & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
            ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                ? 1U : ((1U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                         ? 2U : ((2U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                  ? 4U : 8U))) : (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                                                   & (0x1000U 
                                                      == 
                                                      (0x7000U 
                                                       & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                                    ? 3U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                                     ? 6U
                                                     : 0xcU))
                                                   : 0xfU));
    Top__DOT__core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest_lo 
        = ((0xff00U & ((((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                         & (0U == (0x7000U & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                         ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                             ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                >> 8U) : ((1U == (3U 
                                                  & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                           ? vlSelf->Top__DOT__core__DOT__ex_reg_wd
                                           : ((2U == 
                                               (3U 
                                                & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                               ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                  >> 0x10U)
                                               : (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                  >> 0x10U))))
                         : (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                             & (0x1000U == (0x7000U 
                                            & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                             ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                 ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                    >> 8U) : ((1U == 
                                               (3U 
                                                & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                               ? vlSelf->Top__DOT__core__DOT__ex_reg_wd
                                               : (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                  >> 0x18U)))
                             : (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                >> 8U))) << 8U)) | 
           (0xffU & (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                      & (0U == (0x7000U & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                      ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                          ? vlSelf->Top__DOT__core__DOT__ex_reg_wd
                          : ((1U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                              ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                 >> 8U) : ((2U == (3U 
                                                   & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                            ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                               >> 8U)
                                            : (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                               >> 8U))))
                      : (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                          & (0x1000U == (0x7000U & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                          ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                              ? vlSelf->Top__DOT__core__DOT__ex_reg_wd
                              : ((1U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                  ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                     >> 0x10U) : (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                  >> 0x10U)))
                          : vlSelf->Top__DOT__core__DOT__ex_reg_wd))));
    Top__DOT__core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest_hi 
        = ((0xff00U & ((((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                         & (0U == (0x7000U & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                         ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                             ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                >> 0x18U) : ((1U == 
                                              (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                              ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                 >> 0x18U)
                                              : ((2U 
                                                  == 
                                                  (3U 
                                                   & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                                  ? 
                                                 (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                  >> 0x18U)
                                                  : vlSelf->Top__DOT__core__DOT__ex_reg_wd)))
                         : (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                             & (0x1000U == (0x7000U 
                                            & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                             ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                 ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                    >> 0x18U) : ((1U 
                                                  == 
                                                  (3U 
                                                   & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                                  ? 
                                                 (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                  >> 0x18U)
                                                  : 
                                                 (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                  >> 8U)))
                             : (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                >> 0x18U))) << 8U)) 
           | (0xffU & (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                        & (0U == (0x7000U & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                        ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                            ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                               >> 0x10U) : ((1U == 
                                             (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                             ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                >> 0x10U)
                                             : ((2U 
                                                 == 
                                                 (3U 
                                                  & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                                 ? vlSelf->Top__DOT__core__DOT__ex_reg_wd
                                                 : 
                                                (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                 >> 0x18U))))
                        : (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
                            & (0x1000U == (0x7000U 
                                           & vlSelf->Top__DOT__core__DOT__ex_reg_ins)))
                            ? ((0U == (3U & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                ? (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                   >> 0x10U) : ((1U 
                                                 == 
                                                 (3U 
                                                  & vlSelf->Top__DOT__core__DOT__ex_reg_result))
                                                 ? 
                                                (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                                                 >> 8U)
                                                 : vlSelf->Top__DOT__core__DOT__ex_reg_wd))
                            : (vlSelf->Top__DOT__core__DOT__ex_reg_wd 
                               >> 0x10U)))));
    vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_valid 
        = ((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite) 
           | (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead));
    vlSelf->Top__DOT__core__DOT__id_reg_ctl_memWrite 
        = ((~ (IData)(vlSelf->reset)) & (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write) 
                                          & (0x13U 
                                             != vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                         & ((0x33U 
                                             != (0x7fU 
                                                 & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                            & ((0x13U 
                                                != 
                                                (0x7fU 
                                                 & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                               & ((0x73U 
                                                   != 
                                                   (0x7fU 
                                                    & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                                  & ((3U 
                                                      != 
                                                      (0x7fU 
                                                       & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                                                     & (0x23U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelf->Top__DOT__core__DOT__if_reg_ins))))))));
    if (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write) {
        vlSelf->Top__DOT__core__DOT__stallDelay_0 = 1U;
        vlSelf->Top__DOT__core__DOT__npcDelay_0 = vlSelf->Top__DOT__core__DOT___npc_T_2;
    } else {
        vlSelf->Top__DOT__core__DOT__stallDelay_0 = 0U;
        vlSelf->Top__DOT__core__DOT__npcDelay_0 = vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg;
    }
    if (vlSelf->reset) {
        vlSelf->Top__DOT__core__DOT__if_reg_pc = 0U;
        vlSelf->Top__DOT__core__DOT__if_reg_ins = 0U;
        vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg = 0xfffffffcU;
    } else {
        if (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write) {
            vlSelf->Top__DOT__core__DOT__if_reg_pc 
                = vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg;
        }
        if (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_taken) 
             | (0U != (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_jump)))) {
            vlSelf->Top__DOT__core__DOT__if_reg_ins = 0U;
        } else if (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write) {
            vlSelf->Top__DOT__core__DOT__if_reg_ins 
                = vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o;
        }
        vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg 
            = vlSelf->Top__DOT__core__DOT__pc_io_in;
    }
    vlSelf->Top__DOT__core__DOT__insDelay_0 = vlSelf->Top__DOT__core__DOT__InstructionFetch_io_instruction;
    vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_bits_dataRequest 
        = (((IData)(Top__DOT__core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest_hi) 
            << 0x10U) | (IData)(Top__DOT__core__DOT__MEM__DOT__io_dccmReq_bits_dataRequest_lo));
    vlSelf->Top__DOT__dmem__DOT__sram_csb_i = (1U & 
                                               ((~ 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_valid) 
                                                  & (~ (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite)))) 
                                                & (~ 
                                                   ((IData)(vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_valid) 
                                                    & (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite)))));
    vlSelf->Top__DOT__dmem__DOT__sram_we_i = ((IData)(vlSelf->Top__DOT__core__DOT__MEM_io_dccmReq_valid) 
                                              & (~ (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memWrite)));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr_io_i_w_en 
        = ((0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
           & (0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                              >> 0xfU))));
    Top__DOT__core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_2 
        = (((0x17U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
            | (0x37U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)))
            ? (0xfffff000U & vlSelf->Top__DOT__core__DOT__if_reg_ins)
            : ((0x23U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                ? ((((vlSelf->Top__DOT__core__DOT__if_reg_ins 
                      >> 0x1fU) ? 0xfffffU : 0U) << 0xcU) 
                   | ((0xfe0U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                 >> 0x14U)) | (0x1fU 
                                               & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                  >> 7U))))
                : ((0x63U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                    ? ((((vlSelf->Top__DOT__core__DOT__if_reg_ins 
                          >> 0x1fU) ? 0x7ffffU : 0U) 
                        << 0xdU) | ((0x1000U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0x13U)) 
                                    | ((0x800U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                  << 4U)) 
                                       | ((0x7e0U & 
                                           (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                            >> 0x14U)) 
                                          | (0x1eU 
                                             & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 7U))))))
                    : ((((vlSelf->Top__DOT__core__DOT__if_reg_ins 
                          >> 0x1fU) ? 0x7ffU : 0U) 
                        << 0x15U) | ((0x100000U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                   >> 0xbU)) 
                                     | ((0xff000U & vlSelf->Top__DOT__core__DOT__if_reg_ins) 
                                        | ((0x800U 
                                            & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                 >> 0x14U)))))))));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_jump 
        = ((0x33U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
            ? 0U : ((0x13U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                     ? 0U : ((0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                              ? 0U : ((3U == (0x7fU 
                                              & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                       ? 0U : ((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                                ? 0U
                                                : (
                                                   (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                                    ? 0U
                                                    : 
                                                   ((0x37U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                                     ? 0U
                                                     : 
                                                    ((0x17U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                                      ? 0U
                                                      : 
                                                     ((0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                                       ? 1U
                                                       : 
                                                      ((0x67U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelf->Top__DOT__core__DOT__if_reg_ins))
                                                        ? 2U
                                                        : 0U))))))))));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17 
        = ((2U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                   >> 0x14U)) ? (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG)
            : ((1U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                       >> 0x14U)) ? (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG) 
                                      << 4U) | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG) 
                                                 << 3U) 
                                                | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG) 
                                                    << 2U) 
                                                   | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG) 
                                                       << 1U) 
                                                      | (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG)))))
                : ((0x304U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                               >> 0x14U)) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG
                    : ((0x341U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                   >> 0x14U)) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG
                        : ((0x305U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                       >> 0x14U)) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG
                            : ((0x342U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                           >> 0x14U))
                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCAUSE_REG
                                : ((0x300U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                               >> 0x14U))
                                    ? (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TW_REG) 
                                        << 0x15U) | 
                                       (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPRV_REG) 
                                         << 0x11U) 
                                        | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPP_REG) 
                                            << 0xbU) 
                                           | (((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPIE_REG) 
                                               << 7U) 
                                              | ((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MIE_REG) 
                                                 << 3U)))))
                                    : ((0xf14U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                   >> 0x14U))
                                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MHARTID_REG
                                        : ((0x301U 
                                            == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0x14U))
                                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MHARTID_REG
                                            : 0U)))))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7 
        = ((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra) 
           == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                        >> 0xfU)));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4 
        = (((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite) 
            & (0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) 
           & (0U != (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra)));
    vlSelf->Top__DOT__core__DOT__InstructionDecode_io_func7 
        = (((0x33U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
            | (IData)((0x5013U == (0x707fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))))
            ? (vlSelf->Top__DOT__core__DOT__if_reg_ins 
               >> 0x19U) : 0U);
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control__DOT___signals_T_28 
        = ((0x13U != (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
           & ((0x73U != (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
              & ((3U != (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                 & ((0x23U != (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                    & (0x63U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7 
        = ((0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                     >> 7U)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                          >> 0xfU)));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4 
        = (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_regWrite) 
            & (0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) 
           & (0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                              >> 7U))));
    Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_77 
        = ((0xdU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                              >> 0xfU))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_13
            : ((0xcU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                  >> 0xfU))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_12
                : ((0xbU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                      >> 0xfU))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_11
                    : ((0xaU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                          >> 0xfU)))
                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_10
                        : ((9U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                            >> 0xfU)))
                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_9
                            : ((8U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0xfU)))
                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_8
                                : ((7U == (0x1fU & 
                                           (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                            >> 0xfU)))
                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_7
                                    : ((6U == (0x1fU 
                                               & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                  >> 0xfU)))
                                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_6
                                        : ((5U == (0x1fU 
                                                   & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                      >> 0xfU)))
                                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_5
                                            : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                    >> 0xfU)))
                                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_4
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                        >> 0xfU)))
                                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_3
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                         >> 0xfU)))
                                                     ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_2
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                          >> 0xfU)))
                                                      ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_1
                                                      : vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_0)))))))))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_110 
        = ((0xdU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                              >> 0x14U))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_13
            : ((0xcU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                  >> 0x14U))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_12
                : ((0xbU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                      >> 0x14U))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_11
                    : ((0xaU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                          >> 0x14U)))
                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_10
                        : ((9U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                            >> 0x14U)))
                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_9
                            : ((8U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0x14U)))
                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_8
                                : ((7U == (0x1fU & 
                                           (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                            >> 0x14U)))
                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_7
                                    : ((6U == (0x1fU 
                                               & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                  >> 0x14U)))
                                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_6
                                        : ((5U == (0x1fU 
                                                   & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                      >> 0x14U)))
                                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_5
                                            : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                    >> 0x14U)))
                                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_4
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                        >> 0x14U)))
                                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_3
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                         >> 0x14U)))
                                                     ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_2
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                          >> 0x14U)))
                                                      ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_1
                                                      : vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_0)))))))))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7 
        = ((0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                     >> 7U)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                          >> 0xfU)));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4 
        = (((IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_regWrite) 
            & (0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) 
           & (0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                              >> 7U))));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__immediate_io_out 
        = (((((((3U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
                | (0xfU == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) 
               | (0x13U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) 
              | (0x1bU == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) 
             | (0x67U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins))) 
            | (0x73U == (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)))
            ? ((((vlSelf->Top__DOT__core__DOT__if_reg_ins 
                  >> 0x1fU) ? 0xfffffU : 0U) << 0xcU) 
               | (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                  >> 0x14U)) : Top__DOT__core__DOT__InstructionDecode__DOT__immediate__DOT___GEN_2);
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__r_data 
        = ((3U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                   >> 0x14U)) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_WIRE
            : vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17);
    vlSelf->Top__DOT__core__DOT__InstructionDecode_io_stall 
        = ((1U == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode_io_func7)) 
           & ((((4U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                              >> 0xcU))) | (5U == (7U 
                                                   & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                      >> 0xcU)))) 
               | (6U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                               >> 0xcU)))) | (7U == 
                                              (7U & 
                                               (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0xcU)))));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_branch 
        = ((0x33U != (0x7fU & vlSelf->Top__DOT__core__DOT__if_reg_ins)) 
           & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control__DOT___signals_T_28));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_90 
        = ((0x1aU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                               >> 0xfU))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_26
            : ((0x19U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                   >> 0xfU))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_25
                : ((0x18U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                       >> 0xfU))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_24
                    : ((0x17U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                           >> 0xfU)))
                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_23
                        : ((0x16U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                               >> 0xfU)))
                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_22
                            : ((0x15U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                   >> 0xfU)))
                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_21
                                : ((0x14U == (0x1fU 
                                              & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                 >> 0xfU)))
                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_20
                                    : ((0x13U == (0x1fU 
                                                  & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                     >> 0xfU)))
                                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_19
                                        : ((0x12U == 
                                            (0x1fU 
                                             & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0xfU)))
                                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_18
                                            : ((0x11U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                    >> 0xfU)))
                                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_17
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                        >> 0xfU)))
                                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_16
                                                    : 
                                                   ((0xfU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                         >> 0xfU)))
                                                     ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_15
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                          >> 0xfU)))
                                                      ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_14
                                                      : Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_77)))))))))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_123 
        = ((0x1aU == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                               >> 0x14U))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_26
            : ((0x19U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                   >> 0x14U))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_25
                : ((0x18U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                       >> 0x14U))) ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_24
                    : ((0x17U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                           >> 0x14U)))
                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_23
                        : ((0x16U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                               >> 0x14U)))
                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_22
                            : ((0x15U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                   >> 0x14U)))
                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_21
                                : ((0x14U == (0x1fU 
                                              & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                 >> 0x14U)))
                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_20
                                    : ((0x13U == (0x1fU 
                                                  & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                     >> 0x14U)))
                                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_19
                                        : ((0x12U == 
                                            (0x1fU 
                                             & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0x14U)))
                                            ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_18
                                            : ((0x11U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                    >> 0x14U)))
                                                ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_17
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                        >> 0x14U)))
                                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_16
                                                    : 
                                                   ((0xfU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                         >> 0x14U)))
                                                     ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_15
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                          >> 0x14U)))
                                                      ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_14
                                                      : Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_110)))))))))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx 
        = (((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4) 
            & (~ (IData)(vlSelf->Top__DOT__core__DOT__id_reg_is_csr))) 
           & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx 
        = (((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_4) 
            & (IData)(vlSelf->Top__DOT__core__DOT__id_reg_is_csr)) 
           & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecEx_T_7));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu__DOT___T_14 
        = (((((IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_memRead) 
              | (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_branch)) 
             & (((0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                           >> 7U)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                >> 0xfU))) 
                | ((0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                             >> 7U)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                  >> 0x14U))))) 
            & (((0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                 >> 7U))) & (0U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                 >> 0xfU)))) 
               | ((0U != (0x1fU & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                   >> 7U))) & (0U != 
                                               (0x1fU 
                                                & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                   >> 0x14U)))))) 
           & (0x63U != (0x7fU & vlSelf->Top__DOT__core__DOT__id_reg_ins)));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_readData_1 
        = ((0U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U))) ? 0U : ((0x1fU 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                     >> 0x14U)))
                                                 ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_31
                                                 : 
                                                ((0x1eU 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                      >> 0x14U)))
                                                  ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_30
                                                  : 
                                                 ((0x1dU 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                       >> 0x14U)))
                                                   ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_29
                                                   : 
                                                  ((0x1cU 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                        >> 0x14U)))
                                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_28
                                                    : 
                                                   ((0x1bU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                         >> 0x14U)))
                                                     ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_27
                                                     : Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_123))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecMem 
        = ((((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4) 
             & (~ (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_is_csr))) 
            & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7)) 
           & (~ (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx)));
    Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem 
        = ((((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_4) 
             & (IData)(vlSelf->Top__DOT__core__DOT__ex_reg_is_csr)) 
            & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecMem_T_7)) 
           & (~ (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx)));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write 
        = (1U & ((~ (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead) 
                      & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_branch)) 
                     & (((0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                   >> 7U)) == (0x1fU 
                                               & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                  >> 0xfU))) 
                        | ((0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                     >> 7U)) == (0x1fU 
                                                 & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                    >> 0x14U)))))) 
                 & (~ (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu__DOT___T_14))));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1 
        = ((((((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4) 
               & (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_is_csr)) 
              & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7)) 
             & (~ (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx))) 
            & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem))
            ? 6U : ((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecMem)
                     ? 5U : ((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__csrHazard_DecEx)
                              ? 4U : ((((((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_4) 
                                          & (~ (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_is_csr))) 
                                         & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT___hazard_DecWb_T_7)) 
                                        & (~ (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx))) 
                                       & (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecMem))
                                       ? 3U : ((IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecMem)
                                                ? 2U
                                                : (IData)(Top__DOT__core__DOT__InstructionDecode__DOT__csrController__DOT__hazard_DecEx))))));
}

VL_INLINE_OPT void VTop___024root___sequent__TOP__2(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___sequent__TOP__2\n"); );
    // Body
    if ((1U & ((~ (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__csb0_reg)) 
               & (~ (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__web0_reg))))) {
        if ((1U & (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xffffff00U & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xffU & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
        if ((2U & (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xffff00ffU & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xff00U & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
        if ((4U & (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xff00ffffU & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xff0000U & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
        if ((8U & (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xffffffU & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xff000000U & vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
    }
    if ((1U & ((~ (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__csb0_reg)) 
               & (~ (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__web0_reg))))) {
        if ((1U & (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xffffff00U & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xffU & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
        if ((2U & (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xffff00ffU & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xff00U & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
        if ((4U & (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xff00ffffU & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xff0000U & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
        if ((8U & (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__wmask0_reg))) {
            vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem[vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg] 
                = ((0xffffffU & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem
                    [vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg]) 
                   | (0xff000000U & vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__din0_reg));
        }
    }
    if (((~ (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__csb0_reg)) 
         & (IData)(vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__web0_reg))) {
        vlSelf->Top__DOT__imem__DOT__sram_rdata_o = 
            vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem
            [vlSelf->Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg];
    }
    if (((~ (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__csb0_reg)) 
         & (IData)(vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__web0_reg))) {
        vlSelf->Top__DOT__dmem__DOT__sram_rdata_o = 
            vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem
            [vlSelf->Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg];
    }
}

VL_INLINE_OPT void VTop___024root___combo__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_24 
        = ((IData)(vlSelf->reset) ? 0U : ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)) 
                                            & (~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en))) 
                                           & ((((4U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3)) 
                                                | (5U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                               | (6U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))) 
                                              | (7U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f3))))
                                           ? (IData)(vlSelf->Top__DOT__core__DOT__id_reg_f7)
                                           : (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__f7_reg)));
}

VL_INLINE_OPT void VTop___024root___multiclk__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___multiclk__TOP__0\n"); );
    // Init
    IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1;
    IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2;
    IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data;
    IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__alu_io_input1;
    IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__alu_io_input2;
    IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b;
    IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__inputMux2;
    IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT___aluIn1_T_2;
    IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT___io_ALUresult_T;
    QData/*63:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result;
    IData/*31:0*/ Top__DOT__core__DOT__MEM__DOT__rdata;
    IData/*31:0*/ Top__DOT__core__DOT__MEM__DOT___GEN_53;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_7;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_42;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_82;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_16;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_126;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_32;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_52;
    IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_62;
    VlWide<3>/*95:0*/ __Vtemp_hf7a1a000__0;
    VlWide<3>/*95:0*/ __Vtemp_h3a6cd15e__0;
    VlWide<3>/*95:0*/ __Vtemp_h78e0dfe0__0;
    VlWide<3>/*95:0*/ __Vtemp_h46a27b2a__0;
    VlWide<3>/*95:0*/ __Vtemp_h121fdeb2__0;
    VlWide<3>/*95:0*/ __Vtemp_h3059a97b__0;
    VlWide<3>/*95:0*/ __Vtemp_h981e149c__0;
    // Body
    vlSelf->Top__DOT__core__DOT__InstructionFetch_io_instruction 
        = ((IData)(vlSelf->Top__DOT__imem__DOT__validReg)
            ? vlSelf->Top__DOT__imem__DOT__sram_rdata_o
            : 0U);
    Top__DOT__core__DOT__MEM__DOT__rdata = ((IData)(vlSelf->Top__DOT__dmem__DOT__validReg)
                                             ? vlSelf->Top__DOT__dmem__DOT__sram_rdata_o
                                             : 0U);
    vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
        = ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))
            ? 0x13U : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))
                        ? ((vlSelf->Top__DOT__core__DOT__InstructionFetch_io_instruction 
                            << 0x10U) | (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__lhw_reg))
                        : vlSelf->Top__DOT__core__DOT__InstructionFetch_io_instruction));
    Top__DOT__core__DOT__MEM__DOT___GEN_53 = ((4U == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__funct3))
                                               ? ((0U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                                   ? 
                                                  (0xffU 
                                                   & Top__DOT__core__DOT__MEM__DOT__rdata)
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                                    ? 
                                                   (0xffU 
                                                    & (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                       >> 8U))
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                                     ? 
                                                    (0xffU 
                                                     & (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                        >> 0x10U))
                                                     : 
                                                    (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                     >> 0x18U))))
                                               : ((5U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__funct3))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                                    ? 
                                                   (0xffffU 
                                                    & Top__DOT__core__DOT__MEM__DOT__rdata)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                                     ? 
                                                    (0xffffU 
                                                     & (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                        >> 8U))
                                                     : 
                                                    (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                     >> 0x10U)))
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                                    ? 
                                                   ((((0x8000U 
                                                       & Top__DOT__core__DOT__MEM__DOT__rdata)
                                                       ? 0xffffU
                                                       : 0U) 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & Top__DOT__core__DOT__MEM__DOT__rdata))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                                     ? 
                                                    ((((0x800000U 
                                                        & Top__DOT__core__DOT__MEM__DOT__rdata)
                                                        ? 0xffffU
                                                        : 0U) 
                                                      << 0x10U) 
                                                     | (0xffffU 
                                                        & (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                           >> 8U)))
                                                     : 
                                                    ((((Top__DOT__core__DOT__MEM__DOT__rdata 
                                                        >> 0x1fU)
                                                        ? 0xffffU
                                                        : 0U) 
                                                      << 0x10U) 
                                                     | (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                        >> 0x10U))))));
    vlSelf->Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_37 
        = ((1U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                         >> 0xdU))) | ((5U == (7U & 
                                               (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                >> 0xdU))) 
                                       | ((2U == (7U 
                                                  & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                     >> 0xdU))) 
                                          | ((3U == 
                                              (7U & 
                                               (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                >> 0xdU))) 
                                             | ((4U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                     >> 0xdU)))
                                                 ? 
                                                ((0U 
                                                  == 
                                                  (3U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      >> 0xaU))) 
                                                 | ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         >> 0xaU))) 
                                                    | ((2U 
                                                        == 
                                                        (3U 
                                                         & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                            >> 0xaU))) 
                                                       | (IData)(
                                                                 ((0xc00U 
                                                                   == 
                                                                   (0xc00U 
                                                                    & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)) 
                                                                  & ((0U 
                                                                      == 
                                                                      (3U 
                                                                       & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                          >> 5U))) 
                                                                     | ((1U 
                                                                         == 
                                                                         (3U 
                                                                          & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                             >> 5U))) 
                                                                        | ((2U 
                                                                            == 
                                                                            (3U 
                                                                             & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                                >> 5U))) 
                                                                           | (3U 
                                                                              == 
                                                                              (3U 
                                                                               & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                                >> 5U)))))))))))
                                                 : 
                                                ((6U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      >> 0xdU))) 
                                                 | (7U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                        >> 0xdU)))))))));
    Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_7 
        = ((0U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                         >> 0xeU))) ? (0x10413U | (
                                                   (0x3c000000U 
                                                    & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                       << 0x13U)) 
                                                   | ((0x3000000U 
                                                       & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                          << 0xdU)) 
                                                      | ((0x800000U 
                                                          & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                             << 0x12U)) 
                                                         | ((0x400000U 
                                                             & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                << 0x10U)) 
                                                            | (0x380U 
                                                               & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                  << 5U)))))))
            : ((1U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                             >> 0xeU))) ? (0x42403U 
                                           | ((0x4000000U 
                                               & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                  << 0x15U)) 
                                              | ((0x3800000U 
                                                  & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                     << 0xdU)) 
                                                 | ((0x400000U 
                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                        << 0x10U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                           << 8U)) 
                                                       | (0x380U 
                                                          & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                             << 5U)))))))
                : ((3U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                 >> 0xeU))) ? (0x842023U 
                                               | ((0x4000000U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      << 0x15U)) 
                                                  | ((0x2000000U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         << 0xdU)) 
                                                     | ((0x700000U 
                                                         & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                            << 0x12U)) 
                                                        | ((0x38000U 
                                                            & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                               << 8U)) 
                                                           | ((0xc00U 
                                                               & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o) 
                                                              | (0x200U 
                                                                 & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                    << 3U))))))))
                    : vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)));
    Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_42 
        = (0x6fU | ((0x80000000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                    << 0x13U)) | ((0x40000000U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      << 0x16U)) 
                                                  | ((0x30000000U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         << 0x13U)) 
                                                     | ((0x8000000U 
                                                         & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                            << 0x15U)) 
                                                        | ((0x4000000U 
                                                            & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                               << 0x13U)) 
                                                           | ((0x2000000U 
                                                               & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                  << 0x17U)) 
                                                              | ((0x1000000U 
                                                                  & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                     << 0xdU)) 
                                                                 | ((0xe00000U 
                                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                        << 0x12U)) 
                                                                    | ((((0x1000U 
                                                                          & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                                                                          ? 0x1ffU
                                                                          : 0U) 
                                                                        << 0xcU) 
                                                                       | (0x80U 
                                                                          & ((~ 
                                                                              (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                               >> 0xfU)) 
                                                                             << 7U))))))))))));
    Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_52 
        = ((2U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                         >> 0xeU))) ? ((0x1000U & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                                        ? ((0U != (0x1fU 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      >> 2U)))
                                            ? (0x33U 
                                               | ((0x1f00000U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      << 0x12U)) 
                                                  | ((0xf8000U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         << 8U)) 
                                                     | (0xf80U 
                                                        & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))
                                            : ((0U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                    >> 7U)))
                                                ? 0x100073U
                                                : (0xe7U 
                                                   | (0xf8000U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         << 8U)))))
                                        : ((0U != (0x1fU 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      >> 2U)))
                                            ? (0x33U 
                                               | ((0x1f00000U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      << 0x12U)) 
                                                  | (0xf80U 
                                                     & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)))
                                            : (0x67U 
                                               | (0xf8000U 
                                                  & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                     << 8U)))))
            : ((3U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                             >> 0xeU))) ? (0x12023U 
                                           | ((0xc000000U 
                                               & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                  << 0x13U)) 
                                              | ((0x2000000U 
                                                  & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                     << 0xdU)) 
                                                 | ((0x1f00000U 
                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                        << 0x12U)) 
                                                    | (0xe00U 
                                                       & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)))))
                : vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o));
    Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_82 
        = (0x45413U | ((0x40000000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                       << 0x14U)) | 
                       ((0x1f00000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                       << 0x12U)) | 
                        ((0x38000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                      << 8U)) | (0x380U 
                                                 & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)))));
    Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_16 
        = ((0U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                         >> 5U))) ? (0x40840433U | 
                                     ((0x700000U & 
                                       (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                        << 0x12U)) 
                                      | ((0x38000U 
                                          & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                             << 8U)) 
                                         | (0x380U 
                                            & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))
            : ((1U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                             >> 5U))) ? (0x844433U 
                                         | ((0x700000U 
                                             & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                << 0x12U)) 
                                            | ((0x38000U 
                                                & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                   << 8U)) 
                                               | (0x380U 
                                                  & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))
                : ((2U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                 >> 5U))) ? (0x846433U 
                                             | ((0x700000U 
                                                 & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                    << 0x12U)) 
                                                | ((0x38000U 
                                                    & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                       << 8U)) 
                                                   | (0x380U 
                                                      & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))
                    : ((3U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                     >> 5U))) ? (0x847433U 
                                                 | ((0x700000U 
                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                        << 0x12U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                           << 8U)) 
                                                       | (0x380U 
                                                          & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))
                        : vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))));
    Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_126 
        = (0x40063U | ((((0x1000U & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                          ? 0xfU : 0U) << 0x1cU) | 
                       ((0xc000000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                       << 0x15U)) | 
                        ((0x2000000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                        << 0x17U)) 
                         | ((0x38000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                         << 8U)) | 
                            ((0x1000U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                         >> 1U)) | 
                             ((0xc00U & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o) 
                              | ((0x300U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                            << 5U)) 
                                 | (0x80U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                             >> 5U))))))))));
    vlSelf->Top__DOT__core__DOT__MEM_io_readData = 
        ((2U == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__funct3))
          ? Top__DOT__core__DOT__MEM__DOT__rdata : 
         ((0U == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__funct3))
           ? ((0U == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
               ? ((((0x80U & Top__DOT__core__DOT__MEM__DOT__rdata)
                     ? 0xffffffU : 0U) << 8U) | (0xffU 
                                                 & Top__DOT__core__DOT__MEM__DOT__rdata))
               : ((1U == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                   ? ((((0x8000U & Top__DOT__core__DOT__MEM__DOT__rdata)
                         ? 0xffffffU : 0U) << 8U) | 
                      (0xffU & (Top__DOT__core__DOT__MEM__DOT__rdata 
                                >> 8U))) : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__MEM__DOT__offset))
                                             ? ((((0x800000U 
                                                   & Top__DOT__core__DOT__MEM__DOT__rdata)
                                                   ? 0xffffffU
                                                   : 0U) 
                                                 << 8U) 
                                                | (0xffU 
                                                   & (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                      >> 0x10U)))
                                             : ((((Top__DOT__core__DOT__MEM__DOT__rdata 
                                                   >> 0x1fU)
                                                   ? 0xffffffU
                                                   : 0U) 
                                                 << 8U) 
                                                | (Top__DOT__core__DOT__MEM__DOT__rdata 
                                                   >> 0x18U)))))
           : Top__DOT__core__DOT__MEM__DOT___GEN_53));
    Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_32 
        = ((3U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                         >> 0xdU))) ? ((2U == (0x1fU 
                                               & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                  >> 7U)))
                                        ? (0x10113U 
                                           | ((((0x1000U 
                                                 & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                                                 ? 7U
                                                 : 0U) 
                                               << 0x1dU) 
                                              | ((0x18000000U 
                                                  & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                     << 0x18U)) 
                                                 | ((0x4000000U 
                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                        << 0x15U)) 
                                                    | ((0x2000000U 
                                                        & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                           << 0x17U)) 
                                                       | (0x1000000U 
                                                          & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                             << 0x12U)))))))
                                        : (0x37U | 
                                           ((((0x1000U 
                                               & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                                               ? 0x7fffU
                                               : 0U) 
                                             << 0x11U) 
                                            | ((0x1f000U 
                                                & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                   << 0xaU)) 
                                               | (0xf80U 
                                                  & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)))))
            : ((4U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                             >> 0xdU))) ? ((0U == (3U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      >> 0xaU)))
                                            ? Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_82
                                            : ((1U 
                                                == 
                                                (3U 
                                                 & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                    >> 0xaU)))
                                                ? Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_82
                                                : (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                        >> 0xaU)))
                                                    ? 
                                                   (0x47413U 
                                                    | ((((0x1000U 
                                                          & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                                                          ? 0x3fU
                                                          : 0U) 
                                                        << 0x1aU) 
                                                       | ((0x2000000U 
                                                           & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                              << 0xdU)) 
                                                          | ((0x1f00000U 
                                                              & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                 << 0x12U)) 
                                                             | ((0x38000U 
                                                                 & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                    << 8U)) 
                                                                | (0x380U 
                                                                   & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))))
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (3U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         >> 0xaU)))
                                                     ? Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_16
                                                     : vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))
                : ((6U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                 >> 0xdU))) ? Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_126
                    : ((7U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                     >> 0xdU))) ? Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_126
                        : vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))));
    if ((1U == (IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_memToReg))) {
        vlSelf->io_pin = vlSelf->Top__DOT__core__DOT__MEM_io_readData;
        vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData 
            = vlSelf->Top__DOT__core__DOT__MEM_io_readData;
    } else {
        vlSelf->io_pin = vlSelf->Top__DOT__core__DOT___GEN_6;
        vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData 
            = vlSelf->Top__DOT__core__DOT___GEN_6;
    }
    Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_62 
        = ((1U == (3U & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))
            ? ((0U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                             >> 0xdU))) ? (0x13U | 
                                           ((((0x1000U 
                                               & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                                               ? 0x3fU
                                               : 0U) 
                                             << 0x1aU) 
                                            | ((0x2000000U 
                                                & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                   << 0xdU)) 
                                               | ((0x1f00000U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      << 0x12U)) 
                                                  | ((0xf8000U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         << 8U)) 
                                                     | (0xf80U 
                                                        & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))))
                : ((1U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                 >> 0xdU))) ? Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_42
                    : ((5U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                     >> 0xdU))) ? Top__DOT__core__DOT__CompressedDecoder__DOT___io_instruction_o_T_42
                        : ((2U == (7U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                         >> 0xdU)))
                            ? (0x13U | ((((0x1000U 
                                           & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
                                           ? 0x3fU : 0U) 
                                         << 0x1aU) 
                                        | ((0x2000000U 
                                            & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                               << 0xdU)) 
                                           | ((0x1f00000U 
                                               & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                  << 0x12U)) 
                                              | (0xf80U 
                                                 & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)))))
                            : Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_32))))
            : ((2U == (3U & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))
                ? ((0U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                 >> 0xeU))) ? (0x1013U 
                                               | ((0x1f00000U 
                                                   & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                      << 0x12U)) 
                                                  | ((0xf8000U 
                                                      & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                         << 8U)) 
                                                     | (0xf80U 
                                                        & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))))
                    : ((1U == (3U & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                     >> 0xeU))) ? (0x12003U 
                                                   | ((0xc000000U 
                                                       & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                          << 0x18U)) 
                                                      | ((0x2000000U 
                                                          & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                             << 0xdU)) 
                                                         | ((0x1c00000U 
                                                             & (vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o 
                                                                << 0x12U)) 
                                                            | (0xf80U 
                                                               & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)))))
                        : Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_52))
                : vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData 
        = ((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_is_csr)
            ? vlSelf->Top__DOT__core__DOT__mem_reg_csr_data
            : vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData);
    vlSelf->Top__DOT__core__DOT__Execute__DOT__inputMux1 
        = ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardA))
            ? vlSelf->Top__DOT__core__DOT__id_reg_rd1
            : ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardA))
                ? vlSelf->Top__DOT__core__DOT__ex_reg_result
                : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardA))
                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData
                    : 0U)));
    vlSelf->Top__DOT__core__DOT__Execute__DOT___inputMux2_T_4 
        = ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB))
            ? vlSelf->Top__DOT__core__DOT__ex_reg_result
            : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB))
                ? vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData
                : 0U));
    vlSelf->Top__DOT__core__DOT__InstructionDecode_io_readData1 
        = (((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite) 
            & ((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra) 
               == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0xfU)))) ? ((0U == (0x1fU 
                                                   & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                      >> 0xfU)))
                                            ? 0U : vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData)
            : ((0U == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                >> 0xfU))) ? 0U : (
                                                   (0x1fU 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                        >> 0xfU)))
                                                    ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_31
                                                    : 
                                                   ((0x1eU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                         >> 0xfU)))
                                                     ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_30
                                                     : 
                                                    ((0x1dU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                          >> 0xfU)))
                                                      ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_29
                                                      : 
                                                     ((0x1cU 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                           >> 0xfU)))
                                                       ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_28
                                                       : 
                                                      ((0x1bU 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                            >> 0xfU)))
                                                        ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_27
                                                        : vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_90)))))));
    vlSelf->Top__DOT__core__DOT__InstructionDecode_io_readData2 
        = (((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_ctl_regWrite) 
            & ((IData)(vlSelf->Top__DOT__core__DOT__mem_reg_wra) 
               == (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U)))) ? ((0U == 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                 >> 0x14U)))
                                             ? 0U : vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData)
            : vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_readData_1);
    vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o 
        = ((0U == vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o)
            ? vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o
            : ((0U == (3U & vlSelf->Top__DOT__core__DOT__Realigner_io_ral_instruction_o))
                ? Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_7
                : Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_62));
    Top__DOT__core__DOT__Execute__DOT___aluIn1_T_2 
        = ((2U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1))
            ? 0U : vlSelf->Top__DOT__core__DOT__Execute__DOT__inputMux1);
    Top__DOT__core__DOT__Execute__DOT__inputMux2 = 
        ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB))
          ? vlSelf->Top__DOT__core__DOT__id_reg_rd2
          : vlSelf->Top__DOT__core__DOT__Execute__DOT___inputMux2_T_4);
    Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1 
        = (((0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                      >> 0xfU)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                             >> 7U)))
            ? vlSelf->Top__DOT__core__DOT__ex_reg_result
            : (((0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                          >> 0xfU)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__mem_reg_ins 
                                                 >> 7U)))
                ? vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData
                : vlSelf->Top__DOT__core__DOT__InstructionDecode_io_readData1));
    Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2 
        = (((0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                      >> 0x14U)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                              >> 7U)))
            ? vlSelf->Top__DOT__core__DOT__ex_reg_result
            : (((0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                          >> 0x14U)) == (0x1fU & (vlSelf->Top__DOT__core__DOT__mem_reg_ins 
                                                  >> 7U)))
                ? vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData
                : vlSelf->Top__DOT__core__DOT__InstructionDecode_io_readData2));
    vlSelf->Top__DOT__core__DOT__IF_stall = ((1U == 
                                              ((0x33U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o))
                                                ? (0x3fU 
                                                   & (vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o 
                                                      >> 0x19U))
                                                : 0U)) 
                                             & ((((4U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o 
                                                       >> 0xcU))) 
                                                  | (5U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o 
                                                         >> 0xcU)))) 
                                                 | (6U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o 
                                                        >> 0xcU)))) 
                                                | (7U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->Top__DOT__core__DOT__CompressedDecoder_io_instruction_o 
                                                       >> 0xcU)))));
    Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
        = ((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1))
            ? vlSelf->Top__DOT__core__DOT__id_reg_pc
            : Top__DOT__core__DOT__Execute__DOT___aluIn1_T_2);
    if (vlSelf->Top__DOT__core__DOT__Execute__DOT__div_en) {
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a 
            = vlSelf->Top__DOT__core__DOT__Execute__DOT__src_a_reg;
        Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b 
            = vlSelf->Top__DOT__core__DOT__Execute__DOT__src_b_reg;
    } else {
        vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a 
            = ((1U == (IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc1))
                ? vlSelf->Top__DOT__core__DOT__id_reg_pc
                : Top__DOT__core__DOT__Execute__DOT___aluIn1_T_2);
        Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b 
            = ((IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc)
                ? Top__DOT__core__DOT__Execute__DOT__inputMux2
                : vlSelf->Top__DOT__core__DOT__id_reg_imm);
    }
    Top__DOT__core__DOT__Execute__DOT__alu_io_input2 
        = ((IData)(vlSelf->Top__DOT__core__DOT__id_reg_ctl_aluSrc)
            ? Top__DOT__core__DOT__Execute__DOT__inputMux2
            : vlSelf->Top__DOT__core__DOT__id_reg_imm);
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_taken 
        = ((((0U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                           >> 0xcU))) ? (Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1 
                                         == Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2)
              : ((1U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                               >> 0xcU))) ? (Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1 
                                             != Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2)
                  : ((4U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                   >> 0xcU))) ? VL_LTS_III(32, Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1, Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2)
                      : ((5U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                       >> 0xcU))) ? 
                         VL_GTES_III(32, Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1, Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2)
                          : ((6U == (7U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                           >> 0xcU)))
                              ? (Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1 
                                 < Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2)
                              : (Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd1 
                                 >= Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_rd2)))))) 
            & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_branch)) 
           & ((~ (((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead) 
                   & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_branch)) 
                  & (((0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                >> 7U)) == (0x1fU & 
                                            (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                             >> 0xfU))) 
                     | ((0x1fU & (vlSelf->Top__DOT__core__DOT__ex_reg_ins 
                                  >> 7U)) == (0x1fU 
                                              & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                 >> 0x14U)))))) 
              & (~ (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu__DOT___T_14))));
    VL_EXTEND_WI(95,32, __Vtemp_hf7a1a000__0, (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
                                                & (Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b 
                                                   >> 0x1fU))
                                                ? (- Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b)
                                                : Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b));
    VL_SHIFTL_WWI(95,95,6, __Vtemp_h3a6cd15e__0, __Vtemp_hf7a1a000__0, 
                  (0x3fU & ((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter) 
                            - (IData)(1U))));
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5[0U] 
        = __Vtemp_h3a6cd15e__0[0U];
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5[1U] 
        = __Vtemp_h3a6cd15e__0[1U];
    vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5[2U] 
        = (0x7fffffffU & __Vtemp_h3a6cd15e__0[2U]);
    VL_EXTENDS_WI(65,32, __Vtemp_h78e0dfe0__0, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a);
    __Vtemp_h46a27b2a__0[0U] = __Vtemp_h78e0dfe0__0[0U];
    __Vtemp_h46a27b2a__0[1U] = __Vtemp_h78e0dfe0__0[1U];
    __Vtemp_h46a27b2a__0[2U] = (1U & __Vtemp_h78e0dfe0__0[2U]);
    VL_EXTENDS_WQ(65,33, __Vtemp_h121fdeb2__0, (QData)((IData)(Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b)));
    __Vtemp_h3059a97b__0[0U] = __Vtemp_h121fdeb2__0[0U];
    __Vtemp_h3059a97b__0[1U] = __Vtemp_h121fdeb2__0[1U];
    __Vtemp_h3059a97b__0[2U] = (1U & __Vtemp_h121fdeb2__0[2U]);
    VL_MULS_WWW(65, __Vtemp_h981e149c__0, __Vtemp_h46a27b2a__0, __Vtemp_h3059a97b__0);
    Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result 
        = (((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)) 
            | (3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)))
            ? ((QData)((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a)) 
               * (QData)((IData)(Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b)))
            : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))
                ? (((QData)((IData)(__Vtemp_h981e149c__0[1U])) 
                    << 0x20U) | (QData)((IData)(__Vtemp_h981e149c__0[0U])))
                : ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))
                    ? VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a), 
                                  VL_EXTENDS_QI(64,32, Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b))
                    : 0ULL)));
    vlSelf->Top__DOT__core__DOT__InstructionDecode_io_pcSrc 
        = ((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_taken) 
           | (0U != (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_jump)));
    Top__DOT__core__DOT__Execute__DOT___io_ALUresult_T 
        = (((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)) 
            | ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)) 
                 | (3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))) 
                | (2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))) 
               | (((IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s) 
                   | (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u)) 
                  & ((~ (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_valid)) 
                     & (0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter))))))
            ? ((0U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))
                ? (IData)(Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result)
                : ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)) 
                     | (3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))) 
                    | (2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18)))
                    ? (IData)((Top__DOT__core__DOT__Execute__DOT__mdu__DOT__result 
                               >> 0x20U)) : ((4U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))
                                              ? (((
                                                   (vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a 
                                                    >> 0x1fU) 
                                                   != 
                                                   (Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b 
                                                    >> 0x1fU)) 
                                                  & (0U 
                                                     != Top__DOT__core__DOT__Execute__DOT__mdu_io_src_b))
                                                  ? 
                                                 (- vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient)
                                                  : vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient)
                                              : ((5U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))
                                                  ? vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))
                                                   ? 
                                                  ((vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a 
                                                    >> 0x1fU)
                                                    ? 
                                                   (- vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend)
                                                    : vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT___GEN_18))
                                                    ? vlSelf->Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend
                                                    : 0U))))))
            : 0U);
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
                             ? (QData)((IData)((Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                & Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                             : ((1U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                 ? (QData)((IData)(
                                                   (Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                    | Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                 : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                     ? (QData)((IData)(
                                                       (Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                        + Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                     : ((3U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                         ? (QData)((IData)(
                                                           (Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                            - Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                         : ((4U == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                             ? (QData)((IData)(
                                                               VL_LTS_III(32, Top__DOT__core__DOT__Execute__DOT__alu_io_input1, Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                             : ((5U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                 ? (QData)((IData)(
                                                                   (Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                                    < Top__DOT__core__DOT__Execute__DOT__alu_io_input2)))
                                                 : 
                                                ((6U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                  ? 
                                                 ((QData)((IData)(Top__DOT__core__DOT__Execute__DOT__alu_io_input1)) 
                                                  << 
                                                  (0x1fU 
                                                   & Top__DOT__core__DOT__Execute__DOT__alu_io_input2))
                                                  : (QData)((IData)(
                                                                    ((7U 
                                                                      == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                                      ? 
                                                                     (Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & Top__DOT__core__DOT__Execute__DOT__alu_io_input2))
                                                                      : 
                                                                     ((8U 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                                       ? 
                                                                      VL_SHIFTRS_III(32,32,5, Top__DOT__core__DOT__Execute__DOT__alu_io_input1, 
                                                                                (0x1fU 
                                                                                & Top__DOT__core__DOT__Execute__DOT__alu_io_input2))
                                                                       : 
                                                                      ((9U 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out))
                                                                        ? 
                                                                       (Top__DOT__core__DOT__Execute__DOT__alu_io_input1 
                                                                        ^ Top__DOT__core__DOT__Execute__DOT__alu_io_input2)
                                                                        : 0U))))))))))))))));
    Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data 
        = ((0x4000U & vlSelf->Top__DOT__core__DOT__if_reg_ins)
            ? (0x1fU & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                        >> 0xfU)) : ((6U == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1))
                                      ? vlSelf->Top__DOT__core__DOT__mem_reg_csr_data
                                      : ((5U == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1))
                                          ? vlSelf->Top__DOT__core__DOT__ex_reg_csr_data
                                          : ((4U == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1))
                                              ? vlSelf->Top__DOT__core__DOT__id_reg_csr_data
                                              : ((3U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1))
                                                  ? vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1))
                                                   ? 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT__ex_reg_ctl_memRead)
                                                    ? vlSelf->Top__DOT__dmem__DOT__sram_rdata_o
                                                    : vlSelf->Top__DOT__core__DOT__ex_reg_result)
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1))
                                                    ? vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult
                                                    : vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_readData_1)))))));
    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
        = ((3U == (3U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                         >> 0xcU))) ? (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__r_data 
                                       & (~ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data))
            : ((2U == (3U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                             >> 0xcU))) ? (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__r_data 
                                           | Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data)
                : ((1U == (3U & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                 >> 0xcU))) ? Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile_io_CSR_i_data
                    : 0U)));
    if ((0x305U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                    >> 0x14U))) {
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 
            = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
            = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
            = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG;
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
            = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
            = (7U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
    } else {
        vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28 
            = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG;
        if ((0x341U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                        >> 0x14U))) {
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
                = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
                = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG;
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                = (7U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
        } else {
            vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29 
                = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
            if ((0x304U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U))) {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                    = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                    = (7U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
            } else {
                vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30 
                    = vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG;
                if ((3U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                            >> 0x14U))) {
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                        = (1U & vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 1U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 2U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 3U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 4U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                        = (7U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 5U));
                } else if ((1U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                   >> 0x14U))) {
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                        = (1U & vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data);
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 1U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 2U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 3U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                        = (1U & (vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data 
                                 >> 4U));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                        = (7U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG));
                } else {
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35 
                        = (1U & (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG));
                    vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36 
                        = (7U & ((2U == (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                         >> 0x14U))
                                  ? vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data
                                  : (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG)));
                }
            }
        }
    }
}

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
                                               | (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode_io_stall)) 
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
    Top__DOT__core__DOT__pc_io_halt = (1U & (((((IData)(vlSelf->Top__DOT__core__DOT__Execute_io_stall) 
                                                | (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode_io_stall)) 
                                               | (IData)(vlSelf->Top__DOT__core__DOT__IF_stall)) 
                                              | (~ (IData)(vlSelf->Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid))) 
                                             | (1U 
                                                == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg))));
    vlSelf->Top__DOT__core__DOT___npc_T_2 = ((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode_io_pcSrc)
                                              ? ((1U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_jump))
                                                  ? 
                                                 (vlSelf->Top__DOT__core__DOT__if_reg_pc 
                                                  + vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__immediate_io_out)
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__control_io_jump))
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
                                                       ? vlSelf->Top__DOT__core__DOT__InstructionDecode_io_writeData
                                                       : 
                                                      (((0x1fU 
                                                         & (vlSelf->Top__DOT__core__DOT__if_reg_ins 
                                                            >> 0xfU)) 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->Top__DOT__core__DOT__id_reg_ins 
                                                            >> 7U)))
                                                        ? vlSelf->Top__DOT__core__DOT__Execute_io_ALUresult
                                                        : vlSelf->Top__DOT__core__DOT__InstructionDecode_io_readData1)))) 
                                                   + vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__immediate_io_out)
                                                   : 
                                                  (vlSelf->Top__DOT__core__DOT__if_reg_pc 
                                                   + vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__immediate_io_out)))
                                              : (((0U 
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
                                                  : 
                                                 ((IData)(Top__DOT__core__DOT__pc_io_halt)
                                                   ? vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg))));
    vlSelf->Top__DOT__core__DOT__pc_io_in = ((IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write)
                                              ? vlSelf->Top__DOT__core__DOT___npc_T_2
                                              : vlSelf->Top__DOT__core__DOT__pc__DOT__pc_reg);
    vlSelf->Top__DOT__core__DOT__Realigner_io_ral_address_o 
        = ((((1U == (IData)(vlSelf->Top__DOT__core__DOT__Realigner__DOT__stateReg)) 
             & (vlSelf->Top__DOT__core__DOT__pc_io_in 
                >> 1U)) & (~ (IData)(vlSelf->Top__DOT__core__DOT__InstructionDecode_io_pcSrc)))
            ? ((IData)(4U) + vlSelf->Top__DOT__core__DOT__pc_io_in)
            : vlSelf->Top__DOT__core__DOT__pc_io_in);
}

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VTop___024root___sequent__TOP__1(vlSelf);
    }
    if (((~ (IData)(vlSelf->clock)) & (IData)(vlSelf->__Vclklast__TOP__clock))) {
        VTop___024root___sequent__TOP__2(vlSelf);
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
