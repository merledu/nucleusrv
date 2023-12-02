// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class VTop__Syms;

class VTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        CData/*0:0*/ Top__DOT__core__DOT__InstructionFetch_io_coreInstrReq_valid;
        CData/*6:0*/ Top__DOT__core__DOT__InstructionDecode_io_func7;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode_io_pcSrc;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode_io_stall;
        CData/*0:0*/ Top__DOT__core__DOT__Execute_io_stall;
        CData/*0:0*/ Top__DOT__core__DOT__MEM_io_dccmReq_valid;
        CData/*3:0*/ Top__DOT__core__DOT__MEM_io_dccmReq_bits_activeByteLane;
        CData/*4:0*/ Top__DOT__core__DOT__id_reg_wra;
        CData/*6:0*/ Top__DOT__core__DOT__id_reg_f7;
        CData/*2:0*/ Top__DOT__core__DOT__id_reg_f3;
        CData/*0:0*/ Top__DOT__core__DOT__id_reg_ctl_aluSrc;
        CData/*1:0*/ Top__DOT__core__DOT__id_reg_ctl_aluSrc1;
        CData/*1:0*/ Top__DOT__core__DOT__id_reg_ctl_memToReg;
        CData/*0:0*/ Top__DOT__core__DOT__id_reg_ctl_regWrite;
        CData/*0:0*/ Top__DOT__core__DOT__id_reg_ctl_memRead;
        CData/*0:0*/ Top__DOT__core__DOT__id_reg_ctl_memWrite;
        CData/*1:0*/ Top__DOT__core__DOT__id_reg_ctl_aluOp;
        CData/*0:0*/ Top__DOT__core__DOT__id_reg_is_csr;
        CData/*4:0*/ Top__DOT__core__DOT__ex_reg_wra;
        CData/*1:0*/ Top__DOT__core__DOT__ex_reg_ctl_memToReg;
        CData/*0:0*/ Top__DOT__core__DOT__ex_reg_ctl_regWrite;
        CData/*0:0*/ Top__DOT__core__DOT__ex_reg_ctl_memRead;
        CData/*0:0*/ Top__DOT__core__DOT__ex_reg_ctl_memWrite;
        CData/*0:0*/ Top__DOT__core__DOT__ex_reg_is_csr;
        CData/*4:0*/ Top__DOT__core__DOT__mem_reg_wra;
        CData/*1:0*/ Top__DOT__core__DOT__mem_reg_ctl_memToReg;
        CData/*0:0*/ Top__DOT__core__DOT__mem_reg_ctl_regWrite;
        CData/*0:0*/ Top__DOT__core__DOT__mem_reg_is_csr;
        CData/*0:0*/ Top__DOT__core__DOT__IF_stall;
        CData/*4:0*/ Top__DOT__core__DOT__rsAddrDelay_0_0;
        CData/*4:0*/ Top__DOT__core__DOT__rsAddrDelay_0_1;
        CData/*4:0*/ Top__DOT__core__DOT__rsAddrDelay_0_2;
        CData/*4:0*/ Top__DOT__core__DOT__rsAddrDelay_1_0;
        CData/*4:0*/ Top__DOT__core__DOT__rsAddrDelay_1_1;
        CData/*4:0*/ Top__DOT__core__DOT__rsAddrDelay_1_2;
        CData/*0:0*/ Top__DOT__core__DOT__stallDelay_0;
        CData/*0:0*/ Top__DOT__core__DOT__stallDelay_1;
        CData/*0:0*/ Top__DOT__core__DOT__stallDelay_2;
        CData/*0:0*/ Top__DOT__core__DOT__stallDelay_3;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr_io_i_w_en;
        CData/*2:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csrController_io_forwardRS1;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__hdu_io_if_reg_write;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__control_io_branch;
        CData/*1:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__control_io_jump;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeEnable;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__bu_io_taken;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_TW_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPRV_REG;
        CData/*1:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPP_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MPIE_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MSTATUS_MIE_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NX_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_UF_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_OF_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_DZ_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_NV_REG;
        CData/*2:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_FRM_REG;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_31;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_32;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_33;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_34;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_35;
    };
    struct {
        CData/*2:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_36;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__hdu__DOT___T_14;
        CData/*0:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__control__DOT___signals_T_28;
        CData/*3:0*/ Top__DOT__core__DOT__Execute__DOT__aluCtl_io_out;
        CData/*1:0*/ Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardA;
        CData/*1:0*/ Top__DOT__core__DOT__Execute__DOT__ForwardingUnit_io_forwardB;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT__mdu_io_valid;
        CData/*2:0*/ Top__DOT__core__DOT__Execute__DOT__op_reg;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT__div_en;
        CData/*5:0*/ Top__DOT__core__DOT__Execute__DOT__f7_reg;
        CData/*5:0*/ Top__DOT__core__DOT__Execute__DOT__counter;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT___GEN_2;
        CData/*5:0*/ Top__DOT__core__DOT__Execute__DOT___counter_T_1;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT___GEN_14;
        CData/*2:0*/ Top__DOT__core__DOT__Execute__DOT___GEN_18;
        CData/*6:0*/ Top__DOT__core__DOT__Execute__DOT___GEN_24;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_ready;
        CData/*5:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_counter;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_u;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__is_div_rem_s;
        CData/*5:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_4;
        CData/*0:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_13;
        CData/*1:0*/ Top__DOT__core__DOT__MEM__DOT__offset;
        CData/*2:0*/ Top__DOT__core__DOT__MEM__DOT__funct3;
        CData/*1:0*/ Top__DOT__core__DOT__Realigner__DOT__stateReg;
        CData/*0:0*/ Top__DOT__core__DOT__CompressedDecoder__DOT___GEN_37;
        CData/*0:0*/ Top__DOT__dmem__DOT__sram_csb_i;
        CData/*0:0*/ Top__DOT__dmem__DOT__sram_we_i;
        CData/*0:0*/ Top__DOT__dmem__DOT__validReg;
        CData/*0:0*/ Top__DOT__dmem__DOT__sram__DOT__memory__DOT__csb0_reg;
        CData/*0:0*/ Top__DOT__dmem__DOT__sram__DOT__memory__DOT__web0_reg;
        CData/*3:0*/ Top__DOT__dmem__DOT__sram__DOT__memory__DOT__wmask0_reg;
        CData/*0:0*/ Top__DOT__imem__DOT__validReg;
        CData/*0:0*/ Top__DOT__imem__DOT__sram__DOT__memory__DOT__csb0_reg;
        CData/*0:0*/ Top__DOT__imem__DOT__sram__DOT__memory__DOT__web0_reg;
        CData/*3:0*/ Top__DOT__imem__DOT__sram__DOT__memory__DOT__wmask0_reg;
        CData/*0:0*/ __Vclklast__TOP__clock;
        CData/*0:0*/ __Vclklast__TOP__reset;
        SData/*15:0*/ Top__DOT__core__DOT__Realigner__DOT__lhw_reg;
        SData/*12:0*/ Top__DOT__dmem__DOT__sram__DOT__memory__DOT__addr0_reg;
        SData/*12:0*/ Top__DOT__imem__DOT__sram__DOT__memory__DOT__addr0_reg;
        VL_OUT(io_pin,31,0);
        VL_OUT(io_fcsr,31,0);
        IData/*31:0*/ Top__DOT__core__DOT__InstructionFetch_io_instruction;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode_io_writeData;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode_io_readData1;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode_io_readData2;
        IData/*31:0*/ Top__DOT__core__DOT__Execute_io_ALUresult;
        IData/*31:0*/ Top__DOT__core__DOT__MEM_io_readData;
        IData/*31:0*/ Top__DOT__core__DOT__MEM_io_dccmReq_bits_dataRequest;
        IData/*31:0*/ Top__DOT__core__DOT__pc_io_in;
        IData/*31:0*/ Top__DOT__core__DOT__Realigner_io_ral_address_o;
        IData/*31:0*/ Top__DOT__core__DOT__Realigner_io_ral_instruction_o;
        IData/*31:0*/ Top__DOT__core__DOT__CompressedDecoder_io_instruction_o;
        IData/*31:0*/ Top__DOT__core__DOT__if_reg_pc;
        IData/*31:0*/ Top__DOT__core__DOT__if_reg_ins;
        IData/*31:0*/ Top__DOT__core__DOT__id_reg_pc;
        IData/*31:0*/ Top__DOT__core__DOT__id_reg_rd1;
        IData/*31:0*/ Top__DOT__core__DOT__id_reg_rd2;
        IData/*31:0*/ Top__DOT__core__DOT__id_reg_imm;
        IData/*31:0*/ Top__DOT__core__DOT__id_reg_ins;
        IData/*31:0*/ Top__DOT__core__DOT__id_reg_csr_data;
        IData/*31:0*/ Top__DOT__core__DOT__ex_reg_result;
        IData/*31:0*/ Top__DOT__core__DOT__ex_reg_wd;
    };
    struct {
        IData/*31:0*/ Top__DOT__core__DOT__ex_reg_ins;
        IData/*31:0*/ Top__DOT__core__DOT__ex_reg_pc;
        IData/*31:0*/ Top__DOT__core__DOT__ex_reg_csr_data;
        IData/*31:0*/ Top__DOT__core__DOT__mem_reg_ins;
        IData/*31:0*/ Top__DOT__core__DOT__mem_reg_result;
        IData/*31:0*/ Top__DOT__core__DOT__mem_reg_pc;
        IData/*31:0*/ Top__DOT__core__DOT__mem_reg_csr_data;
        IData/*31:0*/ Top__DOT__core__DOT___npc_T_2;
        IData/*31:0*/ Top__DOT__core__DOT___GEN_6;
        IData/*31:0*/ Top__DOT__core__DOT__npcDelay_0;
        IData/*31:0*/ Top__DOT__core__DOT__npcDelay_1;
        IData/*31:0*/ Top__DOT__core__DOT__npcDelay_2;
        IData/*31:0*/ Top__DOT__core__DOT__npcDelay_3;
        IData/*31:0*/ Top__DOT__core__DOT__rsDataDelay_0_0;
        IData/*31:0*/ Top__DOT__core__DOT__rsDataDelay_0_1;
        IData/*31:0*/ Top__DOT__core__DOT__rsDataDelay_1_0;
        IData/*31:0*/ Top__DOT__core__DOT__rsDataDelay_1_1;
        IData/*31:0*/ Top__DOT__core__DOT__memAddrDelay;
        IData/*31:0*/ Top__DOT__core__DOT__memWdataDelay;
        IData/*31:0*/ Top__DOT__core__DOT__insDelay_0;
        IData/*31:0*/ Top__DOT__core__DOT__insDelay_1;
        IData/*31:0*/ Top__DOT__core__DOT__insDelay_2;
        IData/*31:0*/ Top__DOT__core__DOT__insDelay_3;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_writeData;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers_io_readData_1;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__immediate_io_out;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MHARTID_REG;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MCAUSE_REG;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MTVEC_REG;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MIE_REG;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__FCSR_WIRE;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___r_data_T_17;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__r_data;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__w_data;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_28;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_29;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT___GEN_30;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_0;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_1;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_2;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_3;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_4;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_5;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_6;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_7;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_8;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_9;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_10;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_11;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_12;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_13;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_14;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_15;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_16;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_17;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_18;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_19;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_20;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_21;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_22;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_23;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_24;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_25;
    };
    struct {
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_26;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_27;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_28;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_29;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_30;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT__reg_31;
        IData/*31:0*/ Top__DOT__core__DOT__InstructionDecode__DOT__registers__DOT___GEN_90;
        IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__mdu_io_src_a;
        IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__inputMux1;
        IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT___inputMux2_T_4;
        IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__src_a_reg;
        IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__src_b_reg;
        IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_dividend;
        IData/*31:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT__r_quotient;
        VlWide<3>/*94:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT___T_5;
        VlWide<3>/*94:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_28;
        IData/*31:0*/ Top__DOT__core__DOT__pc__DOT__pc_reg;
        IData/*31:0*/ Top__DOT__dmem__DOT__sram_rdata_o;
        IData/*31:0*/ Top__DOT__dmem__DOT__sram__DOT__memory__DOT__din0_reg;
        IData/*31:0*/ Top__DOT__imem__DOT__sram_rdata_o;
        IData/*31:0*/ Top__DOT__imem__DOT__sram__DOT__memory__DOT__din0_reg;
        IData/*31:0*/ Top__DOT__tracer__DOT__clkCycle;
        IData/*31:0*/ Top__DOT__tracer__DOT___clkCycle_T_1;
        QData/*63:0*/ Top__DOT__core__DOT__Execute__DOT__mdu__DOT___GEN_29;
        VlUnpacked<IData/*31:0*/, 8192> Top__DOT__dmem__DOT__sram__DOT__memory__DOT__mem;
        VlUnpacked<IData/*31:0*/, 8192> Top__DOT__imem__DOT__sram__DOT__memory__DOT__mem;
    };

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
