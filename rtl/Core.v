module InstructionFetch(
  input         clock,
  input         reset,
  input  [31:0] io_address,
  output [31:0] io_instruction,
  input         io_stall,
  input         io_redirect,
  output        io_waiting,
  output        io_inst_valid,
  input         io_coreInstrReq_ready,
  output        io_coreInstrReq_valid,
  output [31:0] io_coreInstrReq_bits_addrRequest,
  output        io_coreInstrResp_ready,
  input         io_coreInstrResp_valid,
  input  [31:0] io_coreInstrResp_bits_dataResponse
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [1:0] state_reg; // @[InstructionFetch.scala 26:36]
  wire  _next_state_T_1 = ~io_stall; // @[InstructionFetch.scala 30:31]
  wire  _next_state_T_4 = state_reg == 2'h0 & (~io_stall | ~reset); // @[InstructionFetch.scala 30:27]
  wire  _next_state_T_5 = state_reg == 2'h1; // @[InstructionFetch.scala 31:17]
  wire  _next_state_T_8 = io_coreInstrReq_ready & io_coreInstrReq_valid; // @[Decoupled.scala 51:35]
  wire  _next_state_T_9 = state_reg == 2'h1 & _next_state_T_1 & _next_state_T_8; // @[InstructionFetch.scala 31:41]
  wire  _next_state_T_10 = state_reg == 2'h2; // @[InstructionFetch.scala 32:17]
  wire  _next_state_T_11 = io_coreInstrResp_ready & io_coreInstrResp_valid; // @[Decoupled.scala 51:35]
  wire  _next_state_T_12 = state_reg == 2'h2 & _next_state_T_11; // @[InstructionFetch.scala 32:28]
  wire [1:0] _next_state_T_13 = reset ? 2'h0 : state_reg; // @[Mux.scala 101:16]
  wire [1:0] _next_state_T_14 = _next_state_T_12 ? 2'h1 : _next_state_T_13; // @[Mux.scala 101:16]
  wire [1:0] _next_state_T_15 = _next_state_T_9 ? 2'h2 : _next_state_T_14; // @[Mux.scala 101:16]
  wire [1:0] next_state = _next_state_T_4 ? 2'h1 : _next_state_T_15; // @[Mux.scala 101:16]
  reg  kill; // @[InstructionFetch.scala 39:21]
  wire  _GEN_0 = _next_state_T_11 ? 1'h0 : kill; // @[InstructionFetch.scala 40:31 41:10 39:21]
  wire  _GEN_1 = _next_state_T_10 & io_redirect & ~_next_state_T_11 | _GEN_0; // @[InstructionFetch.scala 43:72 44:10]
  wire  deliver = _next_state_T_11 & ~kill & ~io_redirect; // @[InstructionFetch.scala 49:48]
  assign io_instruction = deliver ? io_coreInstrResp_bits_dataResponse : 32'h0; // @[InstructionFetch.scala 65:24]
  assign io_waiting = _next_state_T_10 & ~deliver; // @[InstructionFetch.scala 52:39]
  assign io_inst_valid = _next_state_T_11 & ~kill & ~io_redirect; // @[InstructionFetch.scala 49:48]
  assign io_coreInstrReq_valid = _next_state_T_5 & _next_state_T_1; // @[InstructionFetch.scala 62:50]
  assign io_coreInstrReq_bits_addrRequest = io_address; // @[InstructionFetch.scala 61:36]
  assign io_coreInstrResp_ready = _next_state_T_10 & (kill | io_redirect | _next_state_T_1); // @[InstructionFetch.scala 48:51]
  always @(posedge clock) begin
    if (reset) begin // @[InstructionFetch.scala 26:36]
      state_reg <= 2'h0; // @[InstructionFetch.scala 26:36]
    end else if (_next_state_T_4) begin // @[Mux.scala 101:16]
      state_reg <= 2'h1;
    end else if (_next_state_T_9) begin // @[Mux.scala 101:16]
      state_reg <= 2'h2;
    end else if (_next_state_T_12) begin // @[Mux.scala 101:16]
      state_reg <= 2'h1;
    end else begin
      state_reg <= _next_state_T_13;
    end
    if (reset) begin // @[InstructionFetch.scala 39:21]
      kill <= 1'h0; // @[InstructionFetch.scala 39:21]
    end else begin
      kill <= _GEN_1;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state_reg = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  kill = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AtomicDecoder(
  input  [31:0] io_instr,
  output        io_out_isLR,
  output        io_out_isSC,
  output        io_out_isAMO,
  output [4:0]  io_out_amoOp
);
  wire [6:0] opcode = io_instr[6:0]; // @[AtomicDecoder.scala 37:24]
  wire [2:0] funct3 = io_instr[14:12]; // @[AtomicDecoder.scala 39:24]
  wire [4:0] funct5 = io_instr[31:27]; // @[AtomicDecoder.scala 42:24]
  wire  _T_3 = 5'h2 == funct5; // @[AtomicDecoder.scala 66:20]
  wire [4:0] _GEN_1 = 5'h1c == funct5 ? funct5 : 5'h0; // @[AtomicDecoder.scala 29:16 66:20 78:55]
  wire  _GEN_2 = 5'h18 == funct5 | 5'h1c == funct5; // @[AtomicDecoder.scala 66:20 77:31]
  wire [4:0] _GEN_3 = 5'h18 == funct5 ? funct5 : _GEN_1; // @[AtomicDecoder.scala 66:20 77:55]
  wire  _GEN_4 = 5'h14 == funct5 | _GEN_2; // @[AtomicDecoder.scala 66:20 76:31]
  wire [4:0] _GEN_5 = 5'h14 == funct5 ? funct5 : _GEN_3; // @[AtomicDecoder.scala 66:20 76:55]
  wire  _GEN_6 = 5'h10 == funct5 | _GEN_4; // @[AtomicDecoder.scala 66:20 75:31]
  wire [4:0] _GEN_7 = 5'h10 == funct5 ? funct5 : _GEN_5; // @[AtomicDecoder.scala 66:20 75:55]
  wire  _GEN_8 = 5'h8 == funct5 | _GEN_6; // @[AtomicDecoder.scala 66:20 74:31]
  wire [4:0] _GEN_9 = 5'h8 == funct5 ? funct5 : _GEN_7; // @[AtomicDecoder.scala 66:20 74:55]
  wire  _GEN_10 = 5'hc == funct5 | _GEN_8; // @[AtomicDecoder.scala 66:20 73:31]
  wire [4:0] _GEN_11 = 5'hc == funct5 ? funct5 : _GEN_9; // @[AtomicDecoder.scala 66:20 73:55]
  wire  _GEN_12 = 5'h4 == funct5 | _GEN_10; // @[AtomicDecoder.scala 66:20 72:31]
  wire [4:0] _GEN_13 = 5'h4 == funct5 ? funct5 : _GEN_11; // @[AtomicDecoder.scala 66:20 72:55]
  wire  _GEN_14 = 5'h1 == funct5 | _GEN_12; // @[AtomicDecoder.scala 66:20 71:31]
  wire [4:0] _GEN_15 = 5'h1 == funct5 ? 5'h1 : _GEN_13; // @[AtomicDecoder.scala 66:20 71:55]
  wire  _GEN_16 = 5'h0 == funct5 | _GEN_14; // @[AtomicDecoder.scala 66:20 70:31]
  wire [4:0] _GEN_17 = 5'h0 == funct5 ? 5'h0 : _GEN_15; // @[AtomicDecoder.scala 66:20 70:55]
  wire [4:0] _GEN_19 = 5'h3 == funct5 ? 5'h3 : _GEN_17; // @[AtomicDecoder.scala 66:20 68:61]
  wire  _GEN_20 = 5'h3 == funct5 ? 1'h0 : _GEN_16; // @[AtomicDecoder.scala 28:16 66:20]
  wire [4:0] _GEN_22 = 5'h2 == funct5 ? 5'h2 : _GEN_19; // @[AtomicDecoder.scala 66:20 67:61]
  wire  _GEN_23 = 5'h2 == funct5 ? 1'h0 : 5'h3 == funct5; // @[AtomicDecoder.scala 27:16 66:20]
  wire  _GEN_24 = 5'h2 == funct5 ? 1'h0 : _GEN_20; // @[AtomicDecoder.scala 28:16 66:20]
  assign io_out_isLR = opcode == 7'h2f & funct3 == 3'h2 & _T_3; // @[AtomicDecoder.scala 26:16 65:57]
  assign io_out_isSC = opcode == 7'h2f & funct3 == 3'h2 & _GEN_23; // @[AtomicDecoder.scala 27:16 65:57]
  assign io_out_isAMO = opcode == 7'h2f & funct3 == 3'h2 & _GEN_24; // @[AtomicDecoder.scala 28:16 65:57]
  assign io_out_amoOp = opcode == 7'h2f & funct3 == 3'h2 ? _GEN_22 : 5'h0; // @[AtomicDecoder.scala 29:16 65:57]
endmodule
module CSRRegFile(
  input         clock,
  input         reset,
  input  [31:0] io_MISA_i_value,
  input  [31:0] io_MHARTID_i_value,
  input  [31:0] io_MARCHID_i_value,
  input  [1:0]  io_CSR_i_opr,
  output [31:0] io_CSR_o_data,
  input  [31:0] io_CSR_i_data,
  input  [11:0] io_CSR_i_addr,
  input         io_CSR_i_w_en,
  input         io_FCSR_except_0,
  input         io_FCSR_except_1,
  input         io_FCSR_except_2,
  input         io_FCSR_except_3,
  input         io_FCSR_except_4,
  output        io_FCSR_nx,
  output        io_FCSR_uf,
  output        io_FCSR_of,
  output        io_FCSR_dz,
  output        io_FCSR_nv,
  output [2:0]  io_FCSR_frm,
  input         io_MINSTRET_i_instr_retired
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
  reg [31:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [31:0] _RAND_34;
  reg [31:0] _RAND_35;
  reg [31:0] _RAND_36;
  reg [31:0] _RAND_37;
  reg [31:0] _RAND_38;
  reg [31:0] _RAND_39;
  reg [31:0] _RAND_40;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] MISA_REG; // @[CSRRegFile.scala 20:38]
  reg [31:0] MARCHID_REG; // @[CSRRegFile.scala 21:38]
  reg [31:0] MHARTID_REG; // @[CSRRegFile.scala 22:38]
  reg [31:0] MCAUSE_REG; // @[CSRRegFile.scala 23:38]
  reg [31:0] MTVEC_REG; // @[CSRRegFile.scala 24:38]
  reg [31:0] MEPC_REG; // @[CSRRegFile.scala 25:38]
  reg [31:0] MSCRATCH_REG; // @[CSRRegFile.scala 26:38]
  reg [31:0] MTVAL_REG; // @[CSRRegFile.scala 27:38]
  reg [31:0] MCYCLE_REG; // @[CSRRegFile.scala 28:38]
  reg [31:0] MCYCLEH_REG; // @[CSRRegFile.scala 29:38]
  reg [31:0] MINSTRET_REG; // @[CSRRegFile.scala 30:38]
  reg [31:0] MINSTRETH_REG; // @[CSRRegFile.scala 31:38]
  reg  MSTATUS_TSR_REG; // @[CSRRegFile.scala 34:38]
  reg  MSTATUS_TW_REG; // @[CSRRegFile.scala 35:38]
  reg  MSTATUS_TVM_REG; // @[CSRRegFile.scala 36:38]
  reg  MSTATUS_MXR_REG; // @[CSRRegFile.scala 37:38]
  reg  MSTATUS_SUM_REG; // @[CSRRegFile.scala 38:38]
  reg  MSTATUS_MPRV_REG; // @[CSRRegFile.scala 39:38]
  reg [1:0] MSTATUS_MPP_REG; // @[CSRRegFile.scala 40:38]
  reg  MSTATUS_SPP_REG; // @[CSRRegFile.scala 41:38]
  reg  MSTATUS_MPIE_REG; // @[CSRRegFile.scala 42:38]
  reg  MSTATUS_UBE_REG; // @[CSRRegFile.scala 43:38]
  reg  MSTATUS_SPIE_REG; // @[CSRRegFile.scala 44:38]
  reg  MSTATUS_MIE_REG; // @[CSRRegFile.scala 45:38]
  reg  MSTATUS_SIE_REG; // @[CSRRegFile.scala 46:38]
  reg  MIE_MEIE_REG; // @[CSRRegFile.scala 49:38]
  reg  MIE_MTIE_REG; // @[CSRRegFile.scala 50:38]
  reg  MIE_MSIE_REG; // @[CSRRegFile.scala 51:38]
  reg  MIP_MEIP_REG; // @[CSRRegFile.scala 54:38]
  reg  MIP_MTIP_REG; // @[CSRRegFile.scala 55:38]
  reg  MIP_MSIP_REG; // @[CSRRegFile.scala 56:38]
  reg  MCOUNTINHIBIT_CY_REG; // @[CSRRegFile.scala 59:39]
  reg  MCOUNTINHIBIT_IR_REG; // @[CSRRegFile.scala 60:39]
  reg [31:0] TIME_REG; // @[CSRRegFile.scala 63:38]
  reg [31:0] TIMEH_REG; // @[CSRRegFile.scala 64:38]
  reg  FCSR_NX_REG; // @[CSRRegFile.scala 67:38]
  reg  FCSR_UF_REG; // @[CSRRegFile.scala 68:38]
  reg  FCSR_OF_REG; // @[CSRRegFile.scala 69:38]
  reg  FCSR_DZ_REG; // @[CSRRegFile.scala 70:38]
  reg  FCSR_NV_REG; // @[CSRRegFile.scala 71:38]
  reg [2:0] FCSR_FRM_REG; // @[CSRRegFile.scala 72:38]
  wire [22:0] MSTATUS_WIRE_hi = {9'h0,MSTATUS_TSR_REG,MSTATUS_TW_REG,MSTATUS_TVM_REG,MSTATUS_MXR_REG,MSTATUS_SUM_REG,
    MSTATUS_MPRV_REG,4'h0,MSTATUS_MPP_REG,2'h0}; // @[Cat.scala 33:92]
  wire [31:0] MSTATUS_WIRE = {MSTATUS_WIRE_hi,MSTATUS_SPP_REG,MSTATUS_MPIE_REG,MSTATUS_UBE_REG,MSTATUS_SPIE_REG,1'h0,
    MSTATUS_MIE_REG,1'h0,MSTATUS_SIE_REG,1'h0}; // @[Cat.scala 33:92]
  wire [32:0] MIE_WIRE = {21'h0,MIE_MEIE_REG,3'h0,MIE_MTIE_REG,3'h0,MIE_MSIE_REG,3'h0}; // @[Cat.scala 33:92]
  wire [32:0] MIP_WIRE = {21'h0,MIP_MEIP_REG,3'h0,MIP_MTIP_REG,3'h0,MIP_MSIP_REG,3'h0}; // @[Cat.scala 33:92]
  wire [31:0] MCOUNTINHIBIT_WIRE = {29'h0,MCOUNTINHIBIT_IR_REG,1'h0,MCOUNTINHIBIT_CY_REG}; // @[Cat.scala 33:92]
  wire [31:0] FFLAGS_WIRE = {27'h0,FCSR_NV_REG,FCSR_DZ_REG,FCSR_OF_REG,FCSR_UF_REG,FCSR_NX_REG}; // @[Cat.scala 33:92]
  wire [31:0] FRM_WIRE = {29'h0,FCSR_FRM_REG}; // @[Cat.scala 33:92]
  wire [31:0] FCSR_WIRE = {24'h0,FCSR_FRM_REG,FCSR_NV_REG,FCSR_DZ_REG,FCSR_OF_REG,FCSR_UF_REG,FCSR_NX_REG}; // @[Cat.scala 33:92]
  wire [31:0] _MCYCLE_REG_T_1 = MCYCLE_REG + 32'h1; // @[CSRRegFile.scala 132:34]
  wire [31:0] _MCYCLEH_REG_T_1 = MCYCLEH_REG + 32'h1; // @[CSRRegFile.scala 134:40]
  wire [31:0] _GEN_0 = MCYCLE_REG == 32'h0 ? _MCYCLEH_REG_T_1 : MCYCLEH_REG; // @[CSRRegFile.scala 133:33 134:25 29:38]
  wire [31:0] _GEN_1 = ~MCOUNTINHIBIT_CY_REG ? _MCYCLE_REG_T_1 : MCYCLE_REG; // @[CSRRegFile.scala 131:32 132:20 28:38]
  wire [31:0] _GEN_2 = ~MCOUNTINHIBIT_CY_REG ? _GEN_0 : MCYCLEH_REG; // @[CSRRegFile.scala 131:32 29:38]
  wire [31:0] _TIME_REG_T_1 = TIME_REG + 32'h1; // @[CSRRegFile.scala 141:26]
  wire [31:0] _TIMEH_REG_T_1 = TIMEH_REG + 32'h1; // @[CSRRegFile.scala 143:32]
  wire [31:0] _GEN_3 = TIME_REG == 32'h0 ? _TIMEH_REG_T_1 : TIMEH_REG; // @[CSRRegFile.scala 142:27 143:19 64:38]
  wire  _T_3 = ~MCOUNTINHIBIT_IR_REG; // @[CSRRegFile.scala 148:41]
  wire [31:0] _MINSTRET_REG_T_1 = MINSTRET_REG + 32'h1; // @[CSRRegFile.scala 149:38]
  wire [31:0] _GEN_4 = io_MINSTRET_i_instr_retired & ~MCOUNTINHIBIT_IR_REG ? _MINSTRET_REG_T_1 : MINSTRET_REG; // @[CSRRegFile.scala 148:63 149:22 30:38]
  wire [31:0] _MINSTRETH_REG_T_1 = MINSTRETH_REG + 32'h1; // @[CSRRegFile.scala 152:40]
  wire [31:0] _GEN_5 = io_MINSTRET_i_instr_retired & MINSTRET_REG == 32'h0 & _T_3 ? _MINSTRETH_REG_T_1 : MINSTRETH_REG; // @[CSRRegFile.scala 151:87 152:23 31:38]
  wire [31:0] _r_data_T_1 = 12'h301 == io_CSR_i_addr ? MISA_REG : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _r_data_T_3 = 12'hf14 == io_CSR_i_addr ? MHARTID_REG : _r_data_T_1; // @[Mux.scala 81:58]
  wire [31:0] _r_data_T_5 = 12'hf12 == io_CSR_i_addr ? MARCHID_REG : _r_data_T_3; // @[Mux.scala 81:58]
  wire  _r_data_T_6 = 12'h300 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_7 = 12'h300 == io_CSR_i_addr ? MSTATUS_WIRE : _r_data_T_5; // @[Mux.scala 81:58]
  wire  _r_data_T_8 = 12'h342 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_9 = 12'h342 == io_CSR_i_addr ? MCAUSE_REG : _r_data_T_7; // @[Mux.scala 81:58]
  wire  _r_data_T_10 = 12'h305 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_11 = 12'h305 == io_CSR_i_addr ? MTVEC_REG : _r_data_T_9; // @[Mux.scala 81:58]
  wire  _r_data_T_12 = 12'h341 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_13 = 12'h341 == io_CSR_i_addr ? MEPC_REG : _r_data_T_11; // @[Mux.scala 81:58]
  wire  _r_data_T_14 = 12'h340 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_15 = 12'h340 == io_CSR_i_addr ? MSCRATCH_REG : _r_data_T_13; // @[Mux.scala 81:58]
  wire  _r_data_T_16 = 12'h343 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_17 = 12'h343 == io_CSR_i_addr ? MTVAL_REG : _r_data_T_15; // @[Mux.scala 81:58]
  wire  _r_data_T_18 = 12'h304 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_19 = 12'h304 == io_CSR_i_addr ? MIE_WIRE : {{1'd0}, _r_data_T_17}; // @[Mux.scala 81:58]
  wire  _r_data_T_20 = 12'h344 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_21 = 12'h344 == io_CSR_i_addr ? MIP_WIRE : _r_data_T_19; // @[Mux.scala 81:58]
  wire  _r_data_T_22 = 12'h1 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_23 = 12'h1 == io_CSR_i_addr ? {{1'd0}, FFLAGS_WIRE} : _r_data_T_21; // @[Mux.scala 81:58]
  wire  _r_data_T_24 = 12'h2 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_25 = 12'h2 == io_CSR_i_addr ? {{1'd0}, FRM_WIRE} : _r_data_T_23; // @[Mux.scala 81:58]
  wire  _r_data_T_26 = 12'h3 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_27 = 12'h3 == io_CSR_i_addr ? {{1'd0}, FCSR_WIRE} : _r_data_T_25; // @[Mux.scala 81:58]
  wire  _r_data_T_28 = 12'hb00 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_29 = 12'hb00 == io_CSR_i_addr ? {{1'd0}, MCYCLE_REG} : _r_data_T_27; // @[Mux.scala 81:58]
  wire  _r_data_T_30 = 12'hb80 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_31 = 12'hb80 == io_CSR_i_addr ? {{1'd0}, MCYCLEH_REG} : _r_data_T_29; // @[Mux.scala 81:58]
  wire  _r_data_T_32 = 12'hb02 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_33 = 12'hb02 == io_CSR_i_addr ? {{1'd0}, MINSTRET_REG} : _r_data_T_31; // @[Mux.scala 81:58]
  wire  _r_data_T_34 = 12'hb82 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_35 = 12'hb82 == io_CSR_i_addr ? {{1'd0}, MINSTRETH_REG} : _r_data_T_33; // @[Mux.scala 81:58]
  wire  _r_data_T_36 = 12'h320 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_37 = 12'h320 == io_CSR_i_addr ? {{1'd0}, MCOUNTINHIBIT_WIRE} : _r_data_T_35; // @[Mux.scala 81:58]
  wire  _r_data_T_38 = 12'hc01 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_39 = 12'hc01 == io_CSR_i_addr ? {{1'd0}, TIME_REG} : _r_data_T_37; // @[Mux.scala 81:58]
  wire  _r_data_T_40 = 12'hc81 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [32:0] _r_data_T_41 = 12'hc81 == io_CSR_i_addr ? {{1'd0}, TIMEH_REG} : _r_data_T_39; // @[Mux.scala 81:58]
  wire [31:0] r_data = _r_data_T_41[31:0]; // @[CSRRegFile.scala 184:12 99:39]
  wire [31:0] set_data = r_data | io_CSR_i_data; // @[CSRRegFile.scala 190:29]
  wire [31:0] _clear_data_T = ~io_CSR_i_data; // @[CSRRegFile.scala 191:31]
  wire [31:0] clear_data = r_data & _clear_data_T; // @[CSRRegFile.scala 191:29]
  wire [31:0] _w_data_T_1 = 2'h1 == io_CSR_i_opr ? io_CSR_i_data : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _w_data_T_3 = 2'h2 == io_CSR_i_opr ? set_data : _w_data_T_1; // @[Mux.scala 81:58]
  wire [31:0] w_data = 2'h3 == io_CSR_i_opr ? clear_data : _w_data_T_3; // @[Mux.scala 81:58]
  wire [31:0] _GEN_6 = _r_data_T_40 ? w_data : _GEN_3; // @[CSRRegFile.scala 202:30 281:34]
  wire [31:0] _GEN_7 = _r_data_T_38 ? w_data : _TIME_REG_T_1; // @[CSRRegFile.scala 141:14 202:30 278:34]
  wire [31:0] _GEN_8 = _r_data_T_38 ? _GEN_3 : _GEN_6; // @[CSRRegFile.scala 202:30]
  wire  _GEN_9 = _r_data_T_36 ? w_data[0] : MCOUNTINHIBIT_CY_REG; // @[CSRRegFile.scala 202:30 274:38 59:39]
  wire  _GEN_10 = _r_data_T_36 ? w_data[2] : MCOUNTINHIBIT_IR_REG; // @[CSRRegFile.scala 202:30 275:38 60:39]
  wire [31:0] _GEN_11 = _r_data_T_36 ? _TIME_REG_T_1 : _GEN_7; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_12 = _r_data_T_36 ? _GEN_3 : _GEN_8; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_13 = _r_data_T_34 ? w_data : _GEN_5; // @[CSRRegFile.scala 202:30 271:35]
  wire  _GEN_14 = _r_data_T_34 ? MCOUNTINHIBIT_CY_REG : _GEN_9; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_15 = _r_data_T_34 ? MCOUNTINHIBIT_IR_REG : _GEN_10; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_16 = _r_data_T_34 ? _TIME_REG_T_1 : _GEN_11; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_17 = _r_data_T_34 ? _GEN_3 : _GEN_12; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_18 = _r_data_T_32 ? w_data : _GEN_4; // @[CSRRegFile.scala 202:30 268:35]
  wire [31:0] _GEN_19 = _r_data_T_32 ? _GEN_5 : _GEN_13; // @[CSRRegFile.scala 202:30]
  wire  _GEN_20 = _r_data_T_32 ? MCOUNTINHIBIT_CY_REG : _GEN_14; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_21 = _r_data_T_32 ? MCOUNTINHIBIT_IR_REG : _GEN_15; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_22 = _r_data_T_32 ? _TIME_REG_T_1 : _GEN_16; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_23 = _r_data_T_32 ? _GEN_3 : _GEN_17; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_24 = _r_data_T_30 ? w_data : _GEN_2; // @[CSRRegFile.scala 202:30 265:35]
  wire [31:0] _GEN_25 = _r_data_T_30 ? _GEN_4 : _GEN_18; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_26 = _r_data_T_30 ? _GEN_5 : _GEN_19; // @[CSRRegFile.scala 202:30]
  wire  _GEN_27 = _r_data_T_30 ? MCOUNTINHIBIT_CY_REG : _GEN_20; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_28 = _r_data_T_30 ? MCOUNTINHIBIT_IR_REG : _GEN_21; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_29 = _r_data_T_30 ? _TIME_REG_T_1 : _GEN_22; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_30 = _r_data_T_30 ? _GEN_3 : _GEN_23; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_31 = _r_data_T_28 ? w_data : _GEN_1; // @[CSRRegFile.scala 202:30 262:35]
  wire [31:0] _GEN_32 = _r_data_T_28 ? _GEN_2 : _GEN_24; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_33 = _r_data_T_28 ? _GEN_4 : _GEN_25; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_34 = _r_data_T_28 ? _GEN_5 : _GEN_26; // @[CSRRegFile.scala 202:30]
  wire  _GEN_35 = _r_data_T_28 ? MCOUNTINHIBIT_CY_REG : _GEN_27; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_36 = _r_data_T_28 ? MCOUNTINHIBIT_IR_REG : _GEN_28; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_37 = _r_data_T_28 ? _TIME_REG_T_1 : _GEN_29; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_38 = _r_data_T_28 ? _GEN_3 : _GEN_30; // @[CSRRegFile.scala 202:30]
  wire [2:0] _GEN_39 = _r_data_T_24 ? w_data[2:0] : FCSR_FRM_REG; // @[CSRRegFile.scala 202:30 259:34 72:38]
  wire [31:0] _GEN_40 = _r_data_T_24 ? _GEN_1 : _GEN_31; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_41 = _r_data_T_24 ? _GEN_2 : _GEN_32; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_42 = _r_data_T_24 ? _GEN_4 : _GEN_33; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_43 = _r_data_T_24 ? _GEN_5 : _GEN_34; // @[CSRRegFile.scala 202:30]
  wire  _GEN_44 = _r_data_T_24 ? MCOUNTINHIBIT_CY_REG : _GEN_35; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_45 = _r_data_T_24 ? MCOUNTINHIBIT_IR_REG : _GEN_36; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_46 = _r_data_T_24 ? _TIME_REG_T_1 : _GEN_37; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_47 = _r_data_T_24 ? _GEN_3 : _GEN_38; // @[CSRRegFile.scala 202:30]
  wire  _GEN_48 = _r_data_T_22 ? w_data[0] : FCSR_NX_REG | io_FCSR_except_0; // @[CSRRegFile.scala 202:30 252:34 88:17]
  wire  _GEN_49 = _r_data_T_22 ? w_data[1] : FCSR_UF_REG | io_FCSR_except_1; // @[CSRRegFile.scala 202:30 253:34 88:17]
  wire  _GEN_50 = _r_data_T_22 ? w_data[2] : FCSR_OF_REG | io_FCSR_except_2; // @[CSRRegFile.scala 202:30 254:34 88:17]
  wire  _GEN_51 = _r_data_T_22 ? w_data[3] : FCSR_DZ_REG | io_FCSR_except_3; // @[CSRRegFile.scala 202:30 255:34 88:17]
  wire  _GEN_52 = _r_data_T_22 ? w_data[4] : FCSR_NV_REG | io_FCSR_except_4; // @[CSRRegFile.scala 202:30 256:34 88:17]
  wire [2:0] _GEN_53 = _r_data_T_22 ? FCSR_FRM_REG : _GEN_39; // @[CSRRegFile.scala 202:30 72:38]
  wire [31:0] _GEN_54 = _r_data_T_22 ? _GEN_1 : _GEN_40; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_55 = _r_data_T_22 ? _GEN_2 : _GEN_41; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_56 = _r_data_T_22 ? _GEN_4 : _GEN_42; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_57 = _r_data_T_22 ? _GEN_5 : _GEN_43; // @[CSRRegFile.scala 202:30]
  wire  _GEN_58 = _r_data_T_22 ? MCOUNTINHIBIT_CY_REG : _GEN_44; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_59 = _r_data_T_22 ? MCOUNTINHIBIT_IR_REG : _GEN_45; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_60 = _r_data_T_22 ? _TIME_REG_T_1 : _GEN_46; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_61 = _r_data_T_22 ? _GEN_3 : _GEN_47; // @[CSRRegFile.scala 202:30]
  wire  _GEN_62 = _r_data_T_26 ? w_data[0] : _GEN_48; // @[CSRRegFile.scala 202:30 244:34]
  wire  _GEN_63 = _r_data_T_26 ? w_data[1] : _GEN_49; // @[CSRRegFile.scala 202:30 245:34]
  wire  _GEN_64 = _r_data_T_26 ? w_data[2] : _GEN_50; // @[CSRRegFile.scala 202:30 246:34]
  wire  _GEN_65 = _r_data_T_26 ? w_data[3] : _GEN_51; // @[CSRRegFile.scala 202:30 247:34]
  wire  _GEN_66 = _r_data_T_26 ? w_data[4] : _GEN_52; // @[CSRRegFile.scala 202:30 248:34]
  wire [2:0] _GEN_67 = _r_data_T_26 ? w_data[7:5] : _GEN_53; // @[CSRRegFile.scala 202:30 249:34]
  wire [31:0] _GEN_68 = _r_data_T_26 ? _GEN_1 : _GEN_54; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_69 = _r_data_T_26 ? _GEN_2 : _GEN_55; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_70 = _r_data_T_26 ? _GEN_4 : _GEN_56; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_71 = _r_data_T_26 ? _GEN_5 : _GEN_57; // @[CSRRegFile.scala 202:30]
  wire  _GEN_72 = _r_data_T_26 ? MCOUNTINHIBIT_CY_REG : _GEN_58; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_73 = _r_data_T_26 ? MCOUNTINHIBIT_IR_REG : _GEN_59; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_74 = _r_data_T_26 ? _TIME_REG_T_1 : _GEN_60; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_75 = _r_data_T_26 ? _GEN_3 : _GEN_61; // @[CSRRegFile.scala 202:30]
  wire  _GEN_76 = _r_data_T_20 ? w_data[11] : MIP_MEIP_REG; // @[CSRRegFile.scala 202:30 239:34 54:38]
  wire  _GEN_77 = _r_data_T_20 ? w_data[7] : MIP_MTIP_REG; // @[CSRRegFile.scala 202:30 240:34 55:38]
  wire  _GEN_78 = _r_data_T_20 ? w_data[3] : MIP_MSIP_REG; // @[CSRRegFile.scala 202:30 241:34 56:38]
  wire  _GEN_79 = _r_data_T_20 ? FCSR_NX_REG | io_FCSR_except_0 : _GEN_62; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_80 = _r_data_T_20 ? FCSR_UF_REG | io_FCSR_except_1 : _GEN_63; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_81 = _r_data_T_20 ? FCSR_OF_REG | io_FCSR_except_2 : _GEN_64; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_82 = _r_data_T_20 ? FCSR_DZ_REG | io_FCSR_except_3 : _GEN_65; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_83 = _r_data_T_20 ? FCSR_NV_REG | io_FCSR_except_4 : _GEN_66; // @[CSRRegFile.scala 202:30 88:17]
  wire [2:0] _GEN_84 = _r_data_T_20 ? FCSR_FRM_REG : _GEN_67; // @[CSRRegFile.scala 202:30 72:38]
  wire [31:0] _GEN_85 = _r_data_T_20 ? _GEN_1 : _GEN_68; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_86 = _r_data_T_20 ? _GEN_2 : _GEN_69; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_87 = _r_data_T_20 ? _GEN_4 : _GEN_70; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_88 = _r_data_T_20 ? _GEN_5 : _GEN_71; // @[CSRRegFile.scala 202:30]
  wire  _GEN_89 = _r_data_T_20 ? MCOUNTINHIBIT_CY_REG : _GEN_72; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_90 = _r_data_T_20 ? MCOUNTINHIBIT_IR_REG : _GEN_73; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_91 = _r_data_T_20 ? _TIME_REG_T_1 : _GEN_74; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_92 = _r_data_T_20 ? _GEN_3 : _GEN_75; // @[CSRRegFile.scala 202:30]
  wire  _GEN_93 = _r_data_T_18 ? w_data[11] : MIE_MEIE_REG; // @[CSRRegFile.scala 202:30 234:34 49:38]
  wire  _GEN_94 = _r_data_T_18 ? w_data[7] : MIE_MTIE_REG; // @[CSRRegFile.scala 202:30 235:34 50:38]
  wire  _GEN_95 = _r_data_T_18 ? w_data[3] : MIE_MSIE_REG; // @[CSRRegFile.scala 202:30 236:34 51:38]
  wire  _GEN_96 = _r_data_T_18 ? MIP_MEIP_REG : _GEN_76; // @[CSRRegFile.scala 202:30 54:38]
  wire  _GEN_97 = _r_data_T_18 ? MIP_MTIP_REG : _GEN_77; // @[CSRRegFile.scala 202:30 55:38]
  wire  _GEN_98 = _r_data_T_18 ? MIP_MSIP_REG : _GEN_78; // @[CSRRegFile.scala 202:30 56:38]
  wire  _GEN_99 = _r_data_T_18 ? FCSR_NX_REG | io_FCSR_except_0 : _GEN_79; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_100 = _r_data_T_18 ? FCSR_UF_REG | io_FCSR_except_1 : _GEN_80; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_101 = _r_data_T_18 ? FCSR_OF_REG | io_FCSR_except_2 : _GEN_81; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_102 = _r_data_T_18 ? FCSR_DZ_REG | io_FCSR_except_3 : _GEN_82; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_103 = _r_data_T_18 ? FCSR_NV_REG | io_FCSR_except_4 : _GEN_83; // @[CSRRegFile.scala 202:30 88:17]
  wire [2:0] _GEN_104 = _r_data_T_18 ? FCSR_FRM_REG : _GEN_84; // @[CSRRegFile.scala 202:30 72:38]
  wire [31:0] _GEN_105 = _r_data_T_18 ? _GEN_1 : _GEN_85; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_106 = _r_data_T_18 ? _GEN_2 : _GEN_86; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_107 = _r_data_T_18 ? _GEN_4 : _GEN_87; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_108 = _r_data_T_18 ? _GEN_5 : _GEN_88; // @[CSRRegFile.scala 202:30]
  wire  _GEN_109 = _r_data_T_18 ? MCOUNTINHIBIT_CY_REG : _GEN_89; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_110 = _r_data_T_18 ? MCOUNTINHIBIT_IR_REG : _GEN_90; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_111 = _r_data_T_18 ? _TIME_REG_T_1 : _GEN_91; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_112 = _r_data_T_18 ? _GEN_3 : _GEN_92; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_113 = _r_data_T_16 ? w_data : MTVAL_REG; // @[CSRRegFile.scala 202:30 231:34 27:38]
  wire  _GEN_114 = _r_data_T_16 ? MIE_MEIE_REG : _GEN_93; // @[CSRRegFile.scala 202:30 49:38]
  wire  _GEN_115 = _r_data_T_16 ? MIE_MTIE_REG : _GEN_94; // @[CSRRegFile.scala 202:30 50:38]
  wire  _GEN_116 = _r_data_T_16 ? MIE_MSIE_REG : _GEN_95; // @[CSRRegFile.scala 202:30 51:38]
  wire  _GEN_117 = _r_data_T_16 ? MIP_MEIP_REG : _GEN_96; // @[CSRRegFile.scala 202:30 54:38]
  wire  _GEN_118 = _r_data_T_16 ? MIP_MTIP_REG : _GEN_97; // @[CSRRegFile.scala 202:30 55:38]
  wire  _GEN_119 = _r_data_T_16 ? MIP_MSIP_REG : _GEN_98; // @[CSRRegFile.scala 202:30 56:38]
  wire  _GEN_120 = _r_data_T_16 ? FCSR_NX_REG | io_FCSR_except_0 : _GEN_99; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_121 = _r_data_T_16 ? FCSR_UF_REG | io_FCSR_except_1 : _GEN_100; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_122 = _r_data_T_16 ? FCSR_OF_REG | io_FCSR_except_2 : _GEN_101; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_123 = _r_data_T_16 ? FCSR_DZ_REG | io_FCSR_except_3 : _GEN_102; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_124 = _r_data_T_16 ? FCSR_NV_REG | io_FCSR_except_4 : _GEN_103; // @[CSRRegFile.scala 202:30 88:17]
  wire [2:0] _GEN_125 = _r_data_T_16 ? FCSR_FRM_REG : _GEN_104; // @[CSRRegFile.scala 202:30 72:38]
  wire [31:0] _GEN_126 = _r_data_T_16 ? _GEN_1 : _GEN_105; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_127 = _r_data_T_16 ? _GEN_2 : _GEN_106; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_128 = _r_data_T_16 ? _GEN_4 : _GEN_107; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_129 = _r_data_T_16 ? _GEN_5 : _GEN_108; // @[CSRRegFile.scala 202:30]
  wire  _GEN_130 = _r_data_T_16 ? MCOUNTINHIBIT_CY_REG : _GEN_109; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_131 = _r_data_T_16 ? MCOUNTINHIBIT_IR_REG : _GEN_110; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_132 = _r_data_T_16 ? _TIME_REG_T_1 : _GEN_111; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_133 = _r_data_T_16 ? _GEN_3 : _GEN_112; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_134 = _r_data_T_14 ? w_data : MSCRATCH_REG; // @[CSRRegFile.scala 202:30 228:34 26:38]
  wire [31:0] _GEN_135 = _r_data_T_14 ? MTVAL_REG : _GEN_113; // @[CSRRegFile.scala 202:30 27:38]
  wire  _GEN_136 = _r_data_T_14 ? MIE_MEIE_REG : _GEN_114; // @[CSRRegFile.scala 202:30 49:38]
  wire  _GEN_137 = _r_data_T_14 ? MIE_MTIE_REG : _GEN_115; // @[CSRRegFile.scala 202:30 50:38]
  wire  _GEN_138 = _r_data_T_14 ? MIE_MSIE_REG : _GEN_116; // @[CSRRegFile.scala 202:30 51:38]
  wire  _GEN_139 = _r_data_T_14 ? MIP_MEIP_REG : _GEN_117; // @[CSRRegFile.scala 202:30 54:38]
  wire  _GEN_140 = _r_data_T_14 ? MIP_MTIP_REG : _GEN_118; // @[CSRRegFile.scala 202:30 55:38]
  wire  _GEN_141 = _r_data_T_14 ? MIP_MSIP_REG : _GEN_119; // @[CSRRegFile.scala 202:30 56:38]
  wire  _GEN_142 = _r_data_T_14 ? FCSR_NX_REG | io_FCSR_except_0 : _GEN_120; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_143 = _r_data_T_14 ? FCSR_UF_REG | io_FCSR_except_1 : _GEN_121; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_144 = _r_data_T_14 ? FCSR_OF_REG | io_FCSR_except_2 : _GEN_122; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_145 = _r_data_T_14 ? FCSR_DZ_REG | io_FCSR_except_3 : _GEN_123; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_146 = _r_data_T_14 ? FCSR_NV_REG | io_FCSR_except_4 : _GEN_124; // @[CSRRegFile.scala 202:30 88:17]
  wire [2:0] _GEN_147 = _r_data_T_14 ? FCSR_FRM_REG : _GEN_125; // @[CSRRegFile.scala 202:30 72:38]
  wire [31:0] _GEN_148 = _r_data_T_14 ? _GEN_1 : _GEN_126; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_149 = _r_data_T_14 ? _GEN_2 : _GEN_127; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_150 = _r_data_T_14 ? _GEN_4 : _GEN_128; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_151 = _r_data_T_14 ? _GEN_5 : _GEN_129; // @[CSRRegFile.scala 202:30]
  wire  _GEN_152 = _r_data_T_14 ? MCOUNTINHIBIT_CY_REG : _GEN_130; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_153 = _r_data_T_14 ? MCOUNTINHIBIT_IR_REG : _GEN_131; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_154 = _r_data_T_14 ? _TIME_REG_T_1 : _GEN_132; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_155 = _r_data_T_14 ? _GEN_3 : _GEN_133; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_156 = _r_data_T_12 ? w_data : MEPC_REG; // @[CSRRegFile.scala 202:30 225:34 25:38]
  wire [31:0] _GEN_157 = _r_data_T_12 ? MSCRATCH_REG : _GEN_134; // @[CSRRegFile.scala 202:30 26:38]
  wire [31:0] _GEN_158 = _r_data_T_12 ? MTVAL_REG : _GEN_135; // @[CSRRegFile.scala 202:30 27:38]
  wire  _GEN_159 = _r_data_T_12 ? MIE_MEIE_REG : _GEN_136; // @[CSRRegFile.scala 202:30 49:38]
  wire  _GEN_160 = _r_data_T_12 ? MIE_MTIE_REG : _GEN_137; // @[CSRRegFile.scala 202:30 50:38]
  wire  _GEN_161 = _r_data_T_12 ? MIE_MSIE_REG : _GEN_138; // @[CSRRegFile.scala 202:30 51:38]
  wire  _GEN_162 = _r_data_T_12 ? MIP_MEIP_REG : _GEN_139; // @[CSRRegFile.scala 202:30 54:38]
  wire  _GEN_163 = _r_data_T_12 ? MIP_MTIP_REG : _GEN_140; // @[CSRRegFile.scala 202:30 55:38]
  wire  _GEN_164 = _r_data_T_12 ? MIP_MSIP_REG : _GEN_141; // @[CSRRegFile.scala 202:30 56:38]
  wire  _GEN_165 = _r_data_T_12 ? FCSR_NX_REG | io_FCSR_except_0 : _GEN_142; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_166 = _r_data_T_12 ? FCSR_UF_REG | io_FCSR_except_1 : _GEN_143; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_167 = _r_data_T_12 ? FCSR_OF_REG | io_FCSR_except_2 : _GEN_144; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_168 = _r_data_T_12 ? FCSR_DZ_REG | io_FCSR_except_3 : _GEN_145; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_169 = _r_data_T_12 ? FCSR_NV_REG | io_FCSR_except_4 : _GEN_146; // @[CSRRegFile.scala 202:30 88:17]
  wire [2:0] _GEN_170 = _r_data_T_12 ? FCSR_FRM_REG : _GEN_147; // @[CSRRegFile.scala 202:30 72:38]
  wire [31:0] _GEN_171 = _r_data_T_12 ? _GEN_1 : _GEN_148; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_172 = _r_data_T_12 ? _GEN_2 : _GEN_149; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_173 = _r_data_T_12 ? _GEN_4 : _GEN_150; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_174 = _r_data_T_12 ? _GEN_5 : _GEN_151; // @[CSRRegFile.scala 202:30]
  wire  _GEN_175 = _r_data_T_12 ? MCOUNTINHIBIT_CY_REG : _GEN_152; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_176 = _r_data_T_12 ? MCOUNTINHIBIT_IR_REG : _GEN_153; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_177 = _r_data_T_12 ? _TIME_REG_T_1 : _GEN_154; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_178 = _r_data_T_12 ? _GEN_3 : _GEN_155; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_179 = _r_data_T_10 ? w_data : MTVEC_REG; // @[CSRRegFile.scala 202:30 222:34 24:38]
  wire [31:0] _GEN_180 = _r_data_T_10 ? MEPC_REG : _GEN_156; // @[CSRRegFile.scala 202:30 25:38]
  wire [31:0] _GEN_181 = _r_data_T_10 ? MSCRATCH_REG : _GEN_157; // @[CSRRegFile.scala 202:30 26:38]
  wire [31:0] _GEN_182 = _r_data_T_10 ? MTVAL_REG : _GEN_158; // @[CSRRegFile.scala 202:30 27:38]
  wire  _GEN_183 = _r_data_T_10 ? MIE_MEIE_REG : _GEN_159; // @[CSRRegFile.scala 202:30 49:38]
  wire  _GEN_184 = _r_data_T_10 ? MIE_MTIE_REG : _GEN_160; // @[CSRRegFile.scala 202:30 50:38]
  wire  _GEN_185 = _r_data_T_10 ? MIE_MSIE_REG : _GEN_161; // @[CSRRegFile.scala 202:30 51:38]
  wire  _GEN_186 = _r_data_T_10 ? MIP_MEIP_REG : _GEN_162; // @[CSRRegFile.scala 202:30 54:38]
  wire  _GEN_187 = _r_data_T_10 ? MIP_MTIP_REG : _GEN_163; // @[CSRRegFile.scala 202:30 55:38]
  wire  _GEN_188 = _r_data_T_10 ? MIP_MSIP_REG : _GEN_164; // @[CSRRegFile.scala 202:30 56:38]
  wire  _GEN_189 = _r_data_T_10 ? FCSR_NX_REG | io_FCSR_except_0 : _GEN_165; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_190 = _r_data_T_10 ? FCSR_UF_REG | io_FCSR_except_1 : _GEN_166; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_191 = _r_data_T_10 ? FCSR_OF_REG | io_FCSR_except_2 : _GEN_167; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_192 = _r_data_T_10 ? FCSR_DZ_REG | io_FCSR_except_3 : _GEN_168; // @[CSRRegFile.scala 202:30 88:17]
  wire  _GEN_193 = _r_data_T_10 ? FCSR_NV_REG | io_FCSR_except_4 : _GEN_169; // @[CSRRegFile.scala 202:30 88:17]
  wire [2:0] _GEN_194 = _r_data_T_10 ? FCSR_FRM_REG : _GEN_170; // @[CSRRegFile.scala 202:30 72:38]
  wire [31:0] _GEN_195 = _r_data_T_10 ? _GEN_1 : _GEN_171; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_196 = _r_data_T_10 ? _GEN_2 : _GEN_172; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_197 = _r_data_T_10 ? _GEN_4 : _GEN_173; // @[CSRRegFile.scala 202:30]
  wire [31:0] _GEN_198 = _r_data_T_10 ? _GEN_5 : _GEN_174; // @[CSRRegFile.scala 202:30]
  wire  _GEN_199 = _r_data_T_10 ? MCOUNTINHIBIT_CY_REG : _GEN_175; // @[CSRRegFile.scala 202:30 59:39]
  wire  _GEN_200 = _r_data_T_10 ? MCOUNTINHIBIT_IR_REG : _GEN_176; // @[CSRRegFile.scala 202:30 60:39]
  wire [31:0] _GEN_201 = _r_data_T_10 ? _TIME_REG_T_1 : _GEN_177; // @[CSRRegFile.scala 141:14 202:30]
  wire [31:0] _GEN_202 = _r_data_T_10 ? _GEN_3 : _GEN_178; // @[CSRRegFile.scala 202:30]
  assign io_CSR_o_data = _r_data_T_41[31:0]; // @[CSRRegFile.scala 184:12 99:39]
  assign io_FCSR_nx = FCSR_NX_REG; // @[CSRRegFile.scala 90:29]
  assign io_FCSR_uf = FCSR_UF_REG; // @[CSRRegFile.scala 91:29]
  assign io_FCSR_of = FCSR_OF_REG; // @[CSRRegFile.scala 92:29]
  assign io_FCSR_dz = FCSR_DZ_REG; // @[CSRRegFile.scala 93:29]
  assign io_FCSR_nv = FCSR_NV_REG; // @[CSRRegFile.scala 94:29]
  assign io_FCSR_frm = FCSR_FRM_REG; // @[CSRRegFile.scala 95:29]
  always @(posedge clock) begin
    if (reset) begin // @[CSRRegFile.scala 20:38]
      MISA_REG <= 32'h0; // @[CSRRegFile.scala 20:38]
    end else begin
      MISA_REG <= io_MISA_i_value; // @[CSRRegFile.scala 77:29]
    end
    if (reset) begin // @[CSRRegFile.scala 21:38]
      MARCHID_REG <= 32'h0; // @[CSRRegFile.scala 21:38]
    end else begin
      MARCHID_REG <= io_MARCHID_i_value; // @[CSRRegFile.scala 79:29]
    end
    if (reset) begin // @[CSRRegFile.scala 22:38]
      MHARTID_REG <= 32'h0; // @[CSRRegFile.scala 22:38]
    end else begin
      MHARTID_REG <= io_MHARTID_i_value; // @[CSRRegFile.scala 78:29]
    end
    if (reset) begin // @[CSRRegFile.scala 23:38]
      MCAUSE_REG <= 32'h0; // @[CSRRegFile.scala 23:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
          MCAUSE_REG <= w_data; // @[CSRRegFile.scala 219:34]
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 24:38]
      MTVEC_REG <= 32'h0; // @[CSRRegFile.scala 24:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MTVEC_REG <= _GEN_179;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 25:38]
      MEPC_REG <= 32'h0; // @[CSRRegFile.scala 25:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MEPC_REG <= _GEN_180;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 26:38]
      MSCRATCH_REG <= 32'h0; // @[CSRRegFile.scala 26:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MSCRATCH_REG <= _GEN_181;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 27:38]
      MTVAL_REG <= 32'h0; // @[CSRRegFile.scala 27:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MTVAL_REG <= _GEN_182;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 28:38]
      MCYCLE_REG <= 32'h0; // @[CSRRegFile.scala 28:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MCYCLE_REG <= _GEN_1;
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        MCYCLE_REG <= _GEN_1;
      end else begin
        MCYCLE_REG <= _GEN_195;
      end
    end else begin
      MCYCLE_REG <= _GEN_1;
    end
    if (reset) begin // @[CSRRegFile.scala 29:38]
      MCYCLEH_REG <= 32'h0; // @[CSRRegFile.scala 29:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MCYCLEH_REG <= _GEN_2;
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        MCYCLEH_REG <= _GEN_2;
      end else begin
        MCYCLEH_REG <= _GEN_196;
      end
    end else begin
      MCYCLEH_REG <= _GEN_2;
    end
    if (reset) begin // @[CSRRegFile.scala 30:38]
      MINSTRET_REG <= 32'h0; // @[CSRRegFile.scala 30:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MINSTRET_REG <= _GEN_4;
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        MINSTRET_REG <= _GEN_4;
      end else begin
        MINSTRET_REG <= _GEN_197;
      end
    end else begin
      MINSTRET_REG <= _GEN_4;
    end
    if (reset) begin // @[CSRRegFile.scala 31:38]
      MINSTRETH_REG <= 32'h0; // @[CSRRegFile.scala 31:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MINSTRETH_REG <= _GEN_5;
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        MINSTRETH_REG <= _GEN_5;
      end else begin
        MINSTRETH_REG <= _GEN_198;
      end
    end else begin
      MINSTRETH_REG <= _GEN_5;
    end
    if (reset) begin // @[CSRRegFile.scala 34:38]
      MSTATUS_TSR_REG <= 1'h0; // @[CSRRegFile.scala 34:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_TSR_REG <= w_data[22]; // @[CSRRegFile.scala 204:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 35:38]
      MSTATUS_TW_REG <= 1'h0; // @[CSRRegFile.scala 35:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_TW_REG <= w_data[21]; // @[CSRRegFile.scala 205:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 36:38]
      MSTATUS_TVM_REG <= 1'h0; // @[CSRRegFile.scala 36:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_TVM_REG <= w_data[20]; // @[CSRRegFile.scala 206:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 37:38]
      MSTATUS_MXR_REG <= 1'h0; // @[CSRRegFile.scala 37:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_MXR_REG <= w_data[19]; // @[CSRRegFile.scala 207:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 38:38]
      MSTATUS_SUM_REG <= 1'h0; // @[CSRRegFile.scala 38:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_SUM_REG <= w_data[18]; // @[CSRRegFile.scala 208:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 39:38]
      MSTATUS_MPRV_REG <= 1'h0; // @[CSRRegFile.scala 39:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_MPRV_REG <= w_data[17]; // @[CSRRegFile.scala 209:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 40:38]
      MSTATUS_MPP_REG <= 2'h0; // @[CSRRegFile.scala 40:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_MPP_REG <= w_data[12:11]; // @[CSRRegFile.scala 210:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 41:38]
      MSTATUS_SPP_REG <= 1'h0; // @[CSRRegFile.scala 41:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_SPP_REG <= w_data[8]; // @[CSRRegFile.scala 211:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 42:38]
      MSTATUS_MPIE_REG <= 1'h0; // @[CSRRegFile.scala 42:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_MPIE_REG <= w_data[7]; // @[CSRRegFile.scala 212:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 43:38]
      MSTATUS_UBE_REG <= 1'h0; // @[CSRRegFile.scala 43:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_UBE_REG <= w_data[6]; // @[CSRRegFile.scala 213:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 44:38]
      MSTATUS_SPIE_REG <= 1'h0; // @[CSRRegFile.scala 44:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_SPIE_REG <= w_data[5]; // @[CSRRegFile.scala 214:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 45:38]
      MSTATUS_MIE_REG <= 1'h0; // @[CSRRegFile.scala 45:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_MIE_REG <= w_data[3]; // @[CSRRegFile.scala 215:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 46:38]
      MSTATUS_SIE_REG <= 1'h0; // @[CSRRegFile.scala 46:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        MSTATUS_SIE_REG <= w_data[1]; // @[CSRRegFile.scala 216:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 49:38]
      MIE_MEIE_REG <= 1'h0; // @[CSRRegFile.scala 49:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MIE_MEIE_REG <= _GEN_183;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 50:38]
      MIE_MTIE_REG <= 1'h0; // @[CSRRegFile.scala 50:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MIE_MTIE_REG <= _GEN_184;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 51:38]
      MIE_MSIE_REG <= 1'h0; // @[CSRRegFile.scala 51:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MIE_MSIE_REG <= _GEN_185;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 54:38]
      MIP_MEIP_REG <= 1'h0; // @[CSRRegFile.scala 54:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MIP_MEIP_REG <= _GEN_186;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 55:38]
      MIP_MTIP_REG <= 1'h0; // @[CSRRegFile.scala 55:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MIP_MTIP_REG <= _GEN_187;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 56:38]
      MIP_MSIP_REG <= 1'h0; // @[CSRRegFile.scala 56:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MIP_MSIP_REG <= _GEN_188;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 59:39]
      MCOUNTINHIBIT_CY_REG <= 1'h0; // @[CSRRegFile.scala 59:39]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MCOUNTINHIBIT_CY_REG <= _GEN_199;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 60:39]
      MCOUNTINHIBIT_IR_REG <= 1'h0; // @[CSRRegFile.scala 60:39]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          MCOUNTINHIBIT_IR_REG <= _GEN_200;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 63:38]
      TIME_REG <= 32'h0; // @[CSRRegFile.scala 63:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        TIME_REG <= _TIME_REG_T_1; // @[CSRRegFile.scala 141:14]
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        TIME_REG <= _TIME_REG_T_1; // @[CSRRegFile.scala 141:14]
      end else begin
        TIME_REG <= _GEN_201;
      end
    end else begin
      TIME_REG <= _TIME_REG_T_1; // @[CSRRegFile.scala 141:14]
    end
    if (reset) begin // @[CSRRegFile.scala 64:38]
      TIMEH_REG <= 32'h0; // @[CSRRegFile.scala 64:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        TIMEH_REG <= _GEN_3;
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        TIMEH_REG <= _GEN_3;
      end else begin
        TIMEH_REG <= _GEN_202;
      end
    end else begin
      TIMEH_REG <= _GEN_3;
    end
    if (reset) begin // @[CSRRegFile.scala 67:38]
      FCSR_NX_REG <= 1'h0; // @[CSRRegFile.scala 67:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        FCSR_NX_REG <= FCSR_NX_REG | io_FCSR_except_0; // @[CSRRegFile.scala 88:17]
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        FCSR_NX_REG <= FCSR_NX_REG | io_FCSR_except_0; // @[CSRRegFile.scala 88:17]
      end else begin
        FCSR_NX_REG <= _GEN_189;
      end
    end else begin
      FCSR_NX_REG <= FCSR_NX_REG | io_FCSR_except_0; // @[CSRRegFile.scala 88:17]
    end
    if (reset) begin // @[CSRRegFile.scala 68:38]
      FCSR_UF_REG <= 1'h0; // @[CSRRegFile.scala 68:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        FCSR_UF_REG <= FCSR_UF_REG | io_FCSR_except_1; // @[CSRRegFile.scala 88:17]
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        FCSR_UF_REG <= FCSR_UF_REG | io_FCSR_except_1; // @[CSRRegFile.scala 88:17]
      end else begin
        FCSR_UF_REG <= _GEN_190;
      end
    end else begin
      FCSR_UF_REG <= FCSR_UF_REG | io_FCSR_except_1; // @[CSRRegFile.scala 88:17]
    end
    if (reset) begin // @[CSRRegFile.scala 69:38]
      FCSR_OF_REG <= 1'h0; // @[CSRRegFile.scala 69:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        FCSR_OF_REG <= FCSR_OF_REG | io_FCSR_except_2; // @[CSRRegFile.scala 88:17]
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        FCSR_OF_REG <= FCSR_OF_REG | io_FCSR_except_2; // @[CSRRegFile.scala 88:17]
      end else begin
        FCSR_OF_REG <= _GEN_191;
      end
    end else begin
      FCSR_OF_REG <= FCSR_OF_REG | io_FCSR_except_2; // @[CSRRegFile.scala 88:17]
    end
    if (reset) begin // @[CSRRegFile.scala 70:38]
      FCSR_DZ_REG <= 1'h0; // @[CSRRegFile.scala 70:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        FCSR_DZ_REG <= FCSR_DZ_REG | io_FCSR_except_3; // @[CSRRegFile.scala 88:17]
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        FCSR_DZ_REG <= FCSR_DZ_REG | io_FCSR_except_3; // @[CSRRegFile.scala 88:17]
      end else begin
        FCSR_DZ_REG <= _GEN_192;
      end
    end else begin
      FCSR_DZ_REG <= FCSR_DZ_REG | io_FCSR_except_3; // @[CSRRegFile.scala 88:17]
    end
    if (reset) begin // @[CSRRegFile.scala 71:38]
      FCSR_NV_REG <= 1'h0; // @[CSRRegFile.scala 71:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (_r_data_T_6) begin // @[CSRRegFile.scala 202:30]
        FCSR_NV_REG <= FCSR_NV_REG | io_FCSR_except_4; // @[CSRRegFile.scala 88:17]
      end else if (_r_data_T_8) begin // @[CSRRegFile.scala 202:30]
        FCSR_NV_REG <= FCSR_NV_REG | io_FCSR_except_4; // @[CSRRegFile.scala 88:17]
      end else begin
        FCSR_NV_REG <= _GEN_193;
      end
    end else begin
      FCSR_NV_REG <= FCSR_NV_REG | io_FCSR_except_4; // @[CSRRegFile.scala 88:17]
    end
    if (reset) begin // @[CSRRegFile.scala 72:38]
      FCSR_FRM_REG <= 3'h0; // @[CSRRegFile.scala 72:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 201:24]
      if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 202:30]
        if (!(_r_data_T_8)) begin // @[CSRRegFile.scala 202:30]
          FCSR_FRM_REG <= _GEN_194;
        end
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  MISA_REG = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  MARCHID_REG = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  MHARTID_REG = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  MCAUSE_REG = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  MTVEC_REG = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  MEPC_REG = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  MSCRATCH_REG = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  MTVAL_REG = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  MCYCLE_REG = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  MCYCLEH_REG = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  MINSTRET_REG = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  MINSTRETH_REG = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  MSTATUS_TSR_REG = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  MSTATUS_TW_REG = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  MSTATUS_TVM_REG = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  MSTATUS_MXR_REG = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  MSTATUS_SUM_REG = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  MSTATUS_MPRV_REG = _RAND_17[0:0];
  _RAND_18 = {1{`RANDOM}};
  MSTATUS_MPP_REG = _RAND_18[1:0];
  _RAND_19 = {1{`RANDOM}};
  MSTATUS_SPP_REG = _RAND_19[0:0];
  _RAND_20 = {1{`RANDOM}};
  MSTATUS_MPIE_REG = _RAND_20[0:0];
  _RAND_21 = {1{`RANDOM}};
  MSTATUS_UBE_REG = _RAND_21[0:0];
  _RAND_22 = {1{`RANDOM}};
  MSTATUS_SPIE_REG = _RAND_22[0:0];
  _RAND_23 = {1{`RANDOM}};
  MSTATUS_MIE_REG = _RAND_23[0:0];
  _RAND_24 = {1{`RANDOM}};
  MSTATUS_SIE_REG = _RAND_24[0:0];
  _RAND_25 = {1{`RANDOM}};
  MIE_MEIE_REG = _RAND_25[0:0];
  _RAND_26 = {1{`RANDOM}};
  MIE_MTIE_REG = _RAND_26[0:0];
  _RAND_27 = {1{`RANDOM}};
  MIE_MSIE_REG = _RAND_27[0:0];
  _RAND_28 = {1{`RANDOM}};
  MIP_MEIP_REG = _RAND_28[0:0];
  _RAND_29 = {1{`RANDOM}};
  MIP_MTIP_REG = _RAND_29[0:0];
  _RAND_30 = {1{`RANDOM}};
  MIP_MSIP_REG = _RAND_30[0:0];
  _RAND_31 = {1{`RANDOM}};
  MCOUNTINHIBIT_CY_REG = _RAND_31[0:0];
  _RAND_32 = {1{`RANDOM}};
  MCOUNTINHIBIT_IR_REG = _RAND_32[0:0];
  _RAND_33 = {1{`RANDOM}};
  TIME_REG = _RAND_33[31:0];
  _RAND_34 = {1{`RANDOM}};
  TIMEH_REG = _RAND_34[31:0];
  _RAND_35 = {1{`RANDOM}};
  FCSR_NX_REG = _RAND_35[0:0];
  _RAND_36 = {1{`RANDOM}};
  FCSR_UF_REG = _RAND_36[0:0];
  _RAND_37 = {1{`RANDOM}};
  FCSR_OF_REG = _RAND_37[0:0];
  _RAND_38 = {1{`RANDOM}};
  FCSR_DZ_REG = _RAND_38[0:0];
  _RAND_39 = {1{`RANDOM}};
  FCSR_NV_REG = _RAND_39[0:0];
  _RAND_40 = {1{`RANDOM}};
  FCSR_FRM_REG = _RAND_40[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module CSR(
  input         clock,
  input         reset,
  input  [31:0] io_i_data,
  input  [4:0]  io_i_imm,
  output [31:0] io_o_data,
  input  [2:0]  io_i_opr,
  input  [11:0] io_i_addr,
  input         io_i_w_en,
  input         io_i_instr_retired
);
  wire  csrRegFile_clock; // @[CSR.scala 25:28]
  wire  csrRegFile_reset; // @[CSR.scala 25:28]
  wire [31:0] csrRegFile_io_MISA_i_value; // @[CSR.scala 25:28]
  wire [31:0] csrRegFile_io_MHARTID_i_value; // @[CSR.scala 25:28]
  wire [31:0] csrRegFile_io_MARCHID_i_value; // @[CSR.scala 25:28]
  wire [1:0] csrRegFile_io_CSR_i_opr; // @[CSR.scala 25:28]
  wire [31:0] csrRegFile_io_CSR_o_data; // @[CSR.scala 25:28]
  wire [31:0] csrRegFile_io_CSR_i_data; // @[CSR.scala 25:28]
  wire [11:0] csrRegFile_io_CSR_i_addr; // @[CSR.scala 25:28]
  wire  csrRegFile_io_CSR_i_w_en; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_except_0; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_except_1; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_except_2; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_except_3; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_except_4; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_nx; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_uf; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_of; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_dz; // @[CSR.scala 25:28]
  wire  csrRegFile_io_FCSR_nv; // @[CSR.scala 25:28]
  wire [2:0] csrRegFile_io_FCSR_frm; // @[CSR.scala 25:28]
  wire  csrRegFile_io_MINSTRET_i_instr_retired; // @[CSR.scala 25:28]
  CSRRegFile csrRegFile ( // @[CSR.scala 25:28]
    .clock(csrRegFile_clock),
    .reset(csrRegFile_reset),
    .io_MISA_i_value(csrRegFile_io_MISA_i_value),
    .io_MHARTID_i_value(csrRegFile_io_MHARTID_i_value),
    .io_MARCHID_i_value(csrRegFile_io_MARCHID_i_value),
    .io_CSR_i_opr(csrRegFile_io_CSR_i_opr),
    .io_CSR_o_data(csrRegFile_io_CSR_o_data),
    .io_CSR_i_data(csrRegFile_io_CSR_i_data),
    .io_CSR_i_addr(csrRegFile_io_CSR_i_addr),
    .io_CSR_i_w_en(csrRegFile_io_CSR_i_w_en),
    .io_FCSR_except_0(csrRegFile_io_FCSR_except_0),
    .io_FCSR_except_1(csrRegFile_io_FCSR_except_1),
    .io_FCSR_except_2(csrRegFile_io_FCSR_except_2),
    .io_FCSR_except_3(csrRegFile_io_FCSR_except_3),
    .io_FCSR_except_4(csrRegFile_io_FCSR_except_4),
    .io_FCSR_nx(csrRegFile_io_FCSR_nx),
    .io_FCSR_uf(csrRegFile_io_FCSR_uf),
    .io_FCSR_of(csrRegFile_io_FCSR_of),
    .io_FCSR_dz(csrRegFile_io_FCSR_dz),
    .io_FCSR_nv(csrRegFile_io_FCSR_nv),
    .io_FCSR_frm(csrRegFile_io_FCSR_frm),
    .io_MINSTRET_i_instr_retired(csrRegFile_io_MINSTRET_i_instr_retired)
  );
  assign io_o_data = csrRegFile_io_CSR_o_data; // @[CSR.scala 38:37]
  assign csrRegFile_clock = clock;
  assign csrRegFile_reset = reset;
  assign csrRegFile_io_MISA_i_value = 32'h40001104; // @[CSR.scala 30:44]
  assign csrRegFile_io_MHARTID_i_value = 32'h1; // @[CSR.scala 31:44]
  assign csrRegFile_io_MARCHID_i_value = 32'h1; // @[CSR.scala 32:44]
  assign csrRegFile_io_CSR_i_opr = io_i_opr[1:0]; // @[CSR.scala 29:44]
  assign csrRegFile_io_CSR_i_data = io_i_opr[2] ? {{27'd0}, io_i_imm} : io_i_data; // @[CSR.scala 28:50]
  assign csrRegFile_io_CSR_i_addr = io_i_addr; // @[CSR.scala 33:44]
  assign csrRegFile_io_CSR_i_w_en = io_i_w_en; // @[CSR.scala 34:44]
  assign csrRegFile_io_FCSR_except_0 = 1'h0; // @[CSR.scala 36:44]
  assign csrRegFile_io_FCSR_except_1 = 1'h0; // @[CSR.scala 36:44]
  assign csrRegFile_io_FCSR_except_2 = 1'h0; // @[CSR.scala 36:44]
  assign csrRegFile_io_FCSR_except_3 = 1'h0; // @[CSR.scala 36:44]
  assign csrRegFile_io_FCSR_except_4 = 1'h0; // @[CSR.scala 36:44]
  assign csrRegFile_io_MINSTRET_i_instr_retired = io_i_instr_retired; // @[CSR.scala 35:44]
endmodule
module CSRController(
  input        io_regWrExecute,
  input  [4:0] io_rdSelExecute,
  input        io_csrWrExecute,
  input        io_regWrMemory,
  input  [4:0] io_rdSelMemory,
  input        io_csrWrMemory,
  input        io_regWrWriteback,
  input  [4:0] io_rdSelWriteback,
  input        io_csrWrWriteback,
  input  [4:0] io_rs1SelDecode,
  input        io_csrInstDecode,
  output [2:0] io_forwardRS1
);
  wire  _hazard_DecEx_T = io_regWrExecute & io_csrInstDecode; // @[CSRController.scala 35:44]
  wire  _hazard_DecEx_T_3 = |io_rdSelExecute; // @[CSRController.scala 38:44]
  wire  _hazard_DecEx_T_4 = _hazard_DecEx_T & _hazard_DecEx_T_3; // @[CSRController.scala 37:46]
  wire  _hazard_DecEx_T_5 = ~io_csrWrExecute; // @[CSRController.scala 39:28]
  wire  _hazard_DecEx_T_6 = _hazard_DecEx_T_4 & _hazard_DecEx_T_5; // @[CSRController.scala 38:48]
  wire  _hazard_DecEx_T_7 = io_rdSelExecute == io_rs1SelDecode; // @[CSRController.scala 40:44]
  wire  hazard_DecEx = _hazard_DecEx_T_6 & _hazard_DecEx_T_7; // @[CSRController.scala 39:45]
  wire  _hazard_DecMem_T = io_regWrMemory & io_csrInstDecode; // @[CSRController.scala 44:44]
  wire  _hazard_DecMem_T_3 = |io_rdSelMemory; // @[CSRController.scala 47:43]
  wire  _hazard_DecMem_T_4 = _hazard_DecMem_T & _hazard_DecMem_T_3; // @[CSRController.scala 46:46]
  wire  _hazard_DecMem_T_5 = ~io_csrWrMemory; // @[CSRController.scala 48:28]
  wire  _hazard_DecMem_T_6 = _hazard_DecMem_T_4 & _hazard_DecMem_T_5; // @[CSRController.scala 47:47]
  wire  _hazard_DecMem_T_7 = io_rdSelMemory == io_rs1SelDecode; // @[CSRController.scala 49:43]
  wire  _hazard_DecMem_T_8 = _hazard_DecMem_T_6 & _hazard_DecMem_T_7; // @[CSRController.scala 48:44]
  wire  _hazard_DecMem_T_9 = ~hazard_DecEx; // @[CSRController.scala 50:28]
  wire  hazard_DecMem = _hazard_DecMem_T_8 & _hazard_DecMem_T_9; // @[CSRController.scala 49:63]
  wire  _hazard_DecWb_T = io_regWrWriteback & io_csrInstDecode; // @[CSRController.scala 54:46]
  wire  _hazard_DecWb_T_3 = |io_rdSelWriteback; // @[CSRController.scala 57:46]
  wire  _hazard_DecWb_T_4 = _hazard_DecWb_T & _hazard_DecWb_T_3; // @[CSRController.scala 56:46]
  wire  _hazard_DecWb_T_5 = ~io_csrWrWriteback; // @[CSRController.scala 58:28]
  wire  _hazard_DecWb_T_6 = _hazard_DecWb_T_4 & _hazard_DecWb_T_5; // @[CSRController.scala 57:50]
  wire  _hazard_DecWb_T_7 = io_rdSelWriteback == io_rs1SelDecode; // @[CSRController.scala 59:46]
  wire  _hazard_DecWb_T_8 = _hazard_DecWb_T_6 & _hazard_DecWb_T_7; // @[CSRController.scala 58:47]
  wire  _hazard_DecWb_T_10 = _hazard_DecWb_T_8 & _hazard_DecMem_T_9; // @[CSRController.scala 59:66]
  wire  hazard_DecWb = _hazard_DecWb_T_10 & hazard_DecMem; // @[CSRController.scala 60:42]
  wire  _csrHazard_DecEx_T_5 = _hazard_DecEx_T_4 & io_csrWrExecute; // @[CSRController.scala 68:48]
  wire  csrHazard_DecEx = _csrHazard_DecEx_T_5 & _hazard_DecEx_T_7; // @[CSRController.scala 69:44]
  wire  _csrHazard_DecMem_T_5 = _hazard_DecMem_T_4 & io_csrWrMemory; // @[CSRController.scala 77:47]
  wire  _csrHazard_DecMem_T_7 = _csrHazard_DecMem_T_5 & _hazard_DecMem_T_7; // @[CSRController.scala 78:43]
  wire  _csrHazard_DecMem_T_8 = ~csrHazard_DecEx; // @[CSRController.scala 80:28]
  wire  csrHazard_DecMem = _csrHazard_DecMem_T_7 & _csrHazard_DecMem_T_8; // @[CSRController.scala 79:63]
  wire  _csrHazard_DecWb_T_5 = _hazard_DecWb_T_4 & io_csrWrWriteback; // @[CSRController.scala 87:50]
  wire  _csrHazard_DecWb_T_7 = _csrHazard_DecWb_T_5 & _hazard_DecWb_T_7; // @[CSRController.scala 88:46]
  wire  _csrHazard_DecWb_T_9 = _csrHazard_DecWb_T_7 & _csrHazard_DecMem_T_8; // @[CSRController.scala 89:66]
  wire  csrHazard_DecWb = _csrHazard_DecWb_T_9 & csrHazard_DecMem; // @[CSRController.scala 90:45]
  wire [1:0] _io_forwardRS1_T_3 = hazard_DecMem ? 2'h2 : {{1'd0}, hazard_DecEx}; // @[Mux.scala 81:58]
  wire [1:0] _io_forwardRS1_T_5 = hazard_DecWb ? 2'h3 : _io_forwardRS1_T_3; // @[Mux.scala 81:58]
  wire [2:0] _io_forwardRS1_T_7 = csrHazard_DecEx ? 3'h4 : {{1'd0}, _io_forwardRS1_T_5}; // @[Mux.scala 81:58]
  wire [2:0] _io_forwardRS1_T_9 = csrHazard_DecMem ? 3'h5 : _io_forwardRS1_T_7; // @[Mux.scala 81:58]
  assign io_forwardRS1 = csrHazard_DecWb ? 3'h6 : _io_forwardRS1_T_9; // @[Mux.scala 81:58]
endmodule
module HazardUnit(
  input         io_ex_mem_memRead,
  input         io_taken,
  input  [1:0]  io_jump,
  input         io_id_is_amo,
  input         io_ex_is_amo,
  input         io_mem_is_amo,
  input  [31:0] io_addr_id,
  input  [31:0] io_addr_ex,
  input  [31:0] io_addr_mem,
  output        io_if_reg_write,
  output        io_pc_write,
  output        io_ctl_mux,
  output        io_ifid_flush,
  output        io_take_branch,
  output        io_operandForwardEX,
  output        io_operandForwardMEM
);
  wire  _T_22 = io_mem_is_amo | io_ex_mem_memRead; // @[HazardUnit.scala 91:20]
  wire  _T_23 = io_addr_id == io_addr_mem; // @[HazardUnit.scala 92:20]
  wire  _GEN_2 = io_addr_id == io_addr_mem ? 1'h0 : 1'h1; // @[HazardUnit.scala 80:32 92:34 95:19]
  wire  _GEN_3 = (io_mem_is_amo | io_ex_mem_memRead) & _T_23; // @[HazardUnit.scala 82:32 91:35]
  wire  _GEN_4 = (io_mem_is_amo | io_ex_mem_memRead) & _GEN_2; // @[HazardUnit.scala 80:32 91:35]
  wire  _T_24 = io_addr_id == io_addr_ex; // @[HazardUnit.scala 101:20]
  wire  _GEN_6 = io_ex_is_amo & _T_24; // @[HazardUnit.scala 100:20 81:32]
  wire  _GEN_11 = _T_24 ? 1'h0 : _T_23; // @[HazardUnit.scala 108:33 110:21]
  wire  _GEN_12 = _T_24 ? 1'h0 : _GEN_2; // @[HazardUnit.scala 108:33 111:19]
  wire  _GEN_13 = io_ex_is_amo & _T_22 ? _T_24 : _GEN_6; // @[HazardUnit.scala 107:49]
  wire  _GEN_14 = io_ex_is_amo & _T_22 ? _GEN_11 : _GEN_3; // @[HazardUnit.scala 107:49]
  wire  _GEN_15 = io_ex_is_amo & _T_22 ? _GEN_12 : _GEN_4; // @[HazardUnit.scala 107:49]
  wire  forward_EX = io_id_is_amo & _GEN_13; // @[HazardUnit.scala 88:22 81:32]
  wire  forward_MEM = io_id_is_amo & _GEN_14; // @[HazardUnit.scala 88:22 82:32]
  wire  _GEN_16 = ~forward_EX & ~forward_MEM & (io_ex_mem_memRead | io_mem_is_amo | io_ex_is_amo) | _GEN_15; // @[HazardUnit.scala 124:80 125:17]
  wire  _GEN_17 = io_addr_ex != io_addr_mem ? 1'h0 : _GEN_16; // @[HazardUnit.scala 130:34 131:19]
  wire  _GEN_18 = io_ex_is_amo & io_mem_is_amo ? _GEN_17 : _GEN_16; // @[HazardUnit.scala 129:33]
  wire  amo_stall = io_id_is_amo & _GEN_18; // @[HazardUnit.scala 88:22 80:32]
  assign io_if_reg_write = amo_stall ? 1'h0 : 1'h1; // @[HazardUnit.scala 137:37 138:16 37:14]
  assign io_pc_write = amo_stall ? 1'h0 : 1'h1; // @[HazardUnit.scala 137:37 138:16 37:14]
  assign io_ctl_mux = amo_stall ? 1'h0 : 1'h1; // @[HazardUnit.scala 137:37 138:16 37:14]
  assign io_ifid_flush = io_taken | io_jump != 2'h0; // @[HazardUnit.scala 62:17]
  assign io_take_branch = amo_stall ? 1'h0 : 1'h1; // @[HazardUnit.scala 137:37 138:16 37:14]
  assign io_operandForwardEX = io_id_is_amo & _GEN_13; // @[HazardUnit.scala 88:22 81:32]
  assign io_operandForwardMEM = io_id_is_amo & _GEN_14; // @[HazardUnit.scala 88:22 82:32]
endmodule
module Control(
  input  [31:0] io_in,
  output        io_aluSrc,
  output [1:0]  io_memToReg,
  output        io_regWrite,
  output        io_memRead,
  output        io_memWrite,
  output        io_branch,
  output [1:0]  io_aluOp,
  output [1:0]  io_jump,
  output [1:0]  io_aluSrc1
);
  wire [31:0] _signals_T = io_in & 32'h7f; // @[Lookup.scala 31:38]
  wire  _signals_T_1 = 32'h33 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_3 = 32'h13 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_5 = 32'h73 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_7 = 32'h3 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_9 = 32'h23 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_11 = 32'h63 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_13 = 32'h37 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_15 = 32'h17 == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_17 = 32'h6f == _signals_T; // @[Lookup.scala 31:38]
  wire  _signals_T_19 = 32'h67 == _signals_T; // @[Lookup.scala 31:38]
  wire [31:0] _signals_T_20 = io_in & 32'hf800007f; // @[Lookup.scala 31:38]
  wire  _signals_T_21 = 32'h1000002f == _signals_T_20; // @[Lookup.scala 31:38]
  wire  _signals_T_23 = 32'h1800002f == _signals_T_20; // @[Lookup.scala 31:38]
  wire [31:0] _signals_T_24 = io_in & 32'h200007f; // @[Lookup.scala 31:38]
  wire  _signals_T_25 = 32'h2f == _signals_T_24; // @[Lookup.scala 31:38]
  wire  _signals_T_34 = _signals_T_9 ? 1'h0 : _signals_T_11; // @[Lookup.scala 34:39]
  wire  _signals_T_35 = _signals_T_7 ? 1'h0 : _signals_T_34; // @[Lookup.scala 34:39]
  wire  _signals_T_36 = _signals_T_5 ? 1'h0 : _signals_T_35; // @[Lookup.scala 34:39]
  wire  _signals_T_37 = _signals_T_3 ? 1'h0 : _signals_T_36; // @[Lookup.scala 34:39]
  wire  _signals_T_39 = _signals_T_23 ? 1'h0 : _signals_T_25; // @[Lookup.scala 34:39]
  wire  _signals_T_40 = _signals_T_21 | _signals_T_39; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_41 = _signals_T_19 ? 2'h2 : {{1'd0}, _signals_T_40}; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_42 = _signals_T_17 ? 2'h2 : _signals_T_41; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_43 = _signals_T_15 ? 2'h0 : _signals_T_42; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_44 = _signals_T_13 ? 2'h0 : _signals_T_43; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_45 = _signals_T_11 ? 2'h0 : _signals_T_44; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_46 = _signals_T_9 ? 2'h0 : _signals_T_45; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_47 = _signals_T_7 ? 2'h1 : _signals_T_46; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_48 = _signals_T_5 ? 2'h0 : _signals_T_47; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_49 = _signals_T_3 ? 2'h0 : _signals_T_48; // @[Lookup.scala 34:39]
  wire  _signals_T_57 = _signals_T_11 ? 1'h0 : _signals_T_13 | (_signals_T_15 | (_signals_T_17 | (_signals_T_19 | (
    _signals_T_21 | (_signals_T_23 | _signals_T_25))))); // @[Lookup.scala 34:39]
  wire  _signals_T_58 = _signals_T_9 ? 1'h0 : _signals_T_57; // @[Lookup.scala 34:39]
  wire  _signals_T_65 = _signals_T_19 ? 1'h0 : _signals_T_21; // @[Lookup.scala 34:39]
  wire  _signals_T_66 = _signals_T_17 ? 1'h0 : _signals_T_65; // @[Lookup.scala 34:39]
  wire  _signals_T_67 = _signals_T_15 ? 1'h0 : _signals_T_66; // @[Lookup.scala 34:39]
  wire  _signals_T_68 = _signals_T_13 ? 1'h0 : _signals_T_67; // @[Lookup.scala 34:39]
  wire  _signals_T_69 = _signals_T_11 ? 1'h0 : _signals_T_68; // @[Lookup.scala 34:39]
  wire  _signals_T_70 = _signals_T_9 ? 1'h0 : _signals_T_69; // @[Lookup.scala 34:39]
  wire  _signals_T_72 = _signals_T_5 ? 1'h0 : _signals_T_7 | _signals_T_70; // @[Lookup.scala 34:39]
  wire  _signals_T_73 = _signals_T_3 ? 1'h0 : _signals_T_72; // @[Lookup.scala 34:39]
  wire  _signals_T_83 = _signals_T_7 ? 1'h0 : _signals_T_9; // @[Lookup.scala 34:39]
  wire  _signals_T_84 = _signals_T_5 ? 1'h0 : _signals_T_83; // @[Lookup.scala 34:39]
  wire  _signals_T_85 = _signals_T_3 ? 1'h0 : _signals_T_84; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_101 = _signals_T_19 ? 2'h2 : 2'h0; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_102 = _signals_T_17 ? 2'h1 : _signals_T_101; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_103 = _signals_T_15 ? 2'h0 : _signals_T_102; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_104 = _signals_T_13 ? 2'h0 : _signals_T_103; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_105 = _signals_T_11 ? 2'h0 : _signals_T_104; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_106 = _signals_T_9 ? 2'h0 : _signals_T_105; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_107 = _signals_T_7 ? 2'h0 : _signals_T_106; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_108 = _signals_T_5 ? 2'h0 : _signals_T_107; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_109 = _signals_T_3 ? 2'h0 : _signals_T_108; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_121 = _signals_T_3 ? 2'h2 : {{1'd0}, _signals_T_5}; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_128 = _signals_T_13 ? 2'h2 : {{1'd0}, _signals_T_15}; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_129 = _signals_T_11 ? 2'h0 : _signals_T_128; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_130 = _signals_T_9 ? 2'h0 : _signals_T_129; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_131 = _signals_T_7 ? 2'h0 : _signals_T_130; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_132 = _signals_T_5 ? 2'h0 : _signals_T_131; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_133 = _signals_T_3 ? 2'h0 : _signals_T_132; // @[Lookup.scala 34:39]
  assign io_aluSrc = _signals_T_1 | _signals_T_37; // @[Lookup.scala 34:39]
  assign io_memToReg = _signals_T_1 ? 2'h0 : _signals_T_49; // @[Lookup.scala 34:39]
  assign io_regWrite = _signals_T_1 | (_signals_T_3 | (_signals_T_5 | (_signals_T_7 | _signals_T_58))); // @[Lookup.scala 34:39]
  assign io_memRead = _signals_T_1 ? 1'h0 : _signals_T_73; // @[Lookup.scala 34:39]
  assign io_memWrite = _signals_T_1 ? 1'h0 : _signals_T_85; // @[Lookup.scala 34:39]
  assign io_branch = _signals_T_1 ? 1'h0 : _signals_T_37; // @[Lookup.scala 34:39]
  assign io_aluOp = _signals_T_1 ? 2'h2 : _signals_T_121; // @[Lookup.scala 34:39]
  assign io_jump = _signals_T_1 ? 2'h0 : _signals_T_109; // @[Lookup.scala 34:39]
  assign io_aluSrc1 = _signals_T_1 ? 2'h0 : _signals_T_133; // @[Lookup.scala 34:39]
endmodule
module Registers(
  input         clock,
  input         reset,
  input  [4:0]  io_readAddress_0,
  input  [4:0]  io_readAddress_1,
  input         io_writeEnable_0,
  input  [4:0]  io_writeAddress,
  input  [31:0] io_writeData,
  output [31:0] io_readData_0,
  output [31:0] io_readData_1
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] i_reg_0; // @[Registers.scala 17:22]
  reg [31:0] i_reg_1; // @[Registers.scala 17:22]
  reg [31:0] i_reg_2; // @[Registers.scala 17:22]
  reg [31:0] i_reg_3; // @[Registers.scala 17:22]
  reg [31:0] i_reg_4; // @[Registers.scala 17:22]
  reg [31:0] i_reg_5; // @[Registers.scala 17:22]
  reg [31:0] i_reg_6; // @[Registers.scala 17:22]
  reg [31:0] i_reg_7; // @[Registers.scala 17:22]
  reg [31:0] i_reg_8; // @[Registers.scala 17:22]
  reg [31:0] i_reg_9; // @[Registers.scala 17:22]
  reg [31:0] i_reg_10; // @[Registers.scala 17:22]
  reg [31:0] i_reg_11; // @[Registers.scala 17:22]
  reg [31:0] i_reg_12; // @[Registers.scala 17:22]
  reg [31:0] i_reg_13; // @[Registers.scala 17:22]
  reg [31:0] i_reg_14; // @[Registers.scala 17:22]
  reg [31:0] i_reg_15; // @[Registers.scala 17:22]
  reg [31:0] i_reg_16; // @[Registers.scala 17:22]
  reg [31:0] i_reg_17; // @[Registers.scala 17:22]
  reg [31:0] i_reg_18; // @[Registers.scala 17:22]
  reg [31:0] i_reg_19; // @[Registers.scala 17:22]
  reg [31:0] i_reg_20; // @[Registers.scala 17:22]
  reg [31:0] i_reg_21; // @[Registers.scala 17:22]
  reg [31:0] i_reg_22; // @[Registers.scala 17:22]
  reg [31:0] i_reg_23; // @[Registers.scala 17:22]
  reg [31:0] i_reg_24; // @[Registers.scala 17:22]
  reg [31:0] i_reg_25; // @[Registers.scala 17:22]
  reg [31:0] i_reg_26; // @[Registers.scala 17:22]
  reg [31:0] i_reg_27; // @[Registers.scala 17:22]
  reg [31:0] i_reg_28; // @[Registers.scala 17:22]
  reg [31:0] i_reg_29; // @[Registers.scala 17:22]
  reg [31:0] i_reg_30; // @[Registers.scala 17:22]
  reg [31:0] i_reg_31; // @[Registers.scala 17:22]
  wire  _io_readData_0_T = io_readAddress_0 != 5'h0; // @[Registers.scala 35:26]
  wire [31:0] _GEN_65 = 5'h1 == io_readAddress_0 ? i_reg_1 : i_reg_0; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_66 = 5'h2 == io_readAddress_0 ? i_reg_2 : _GEN_65; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_67 = 5'h3 == io_readAddress_0 ? i_reg_3 : _GEN_66; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_68 = 5'h4 == io_readAddress_0 ? i_reg_4 : _GEN_67; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_69 = 5'h5 == io_readAddress_0 ? i_reg_5 : _GEN_68; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_70 = 5'h6 == io_readAddress_0 ? i_reg_6 : _GEN_69; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_71 = 5'h7 == io_readAddress_0 ? i_reg_7 : _GEN_70; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_72 = 5'h8 == io_readAddress_0 ? i_reg_8 : _GEN_71; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_73 = 5'h9 == io_readAddress_0 ? i_reg_9 : _GEN_72; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_74 = 5'ha == io_readAddress_0 ? i_reg_10 : _GEN_73; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_75 = 5'hb == io_readAddress_0 ? i_reg_11 : _GEN_74; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_76 = 5'hc == io_readAddress_0 ? i_reg_12 : _GEN_75; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_77 = 5'hd == io_readAddress_0 ? i_reg_13 : _GEN_76; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_78 = 5'he == io_readAddress_0 ? i_reg_14 : _GEN_77; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_79 = 5'hf == io_readAddress_0 ? i_reg_15 : _GEN_78; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_80 = 5'h10 == io_readAddress_0 ? i_reg_16 : _GEN_79; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_81 = 5'h11 == io_readAddress_0 ? i_reg_17 : _GEN_80; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_82 = 5'h12 == io_readAddress_0 ? i_reg_18 : _GEN_81; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_83 = 5'h13 == io_readAddress_0 ? i_reg_19 : _GEN_82; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_84 = 5'h14 == io_readAddress_0 ? i_reg_20 : _GEN_83; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_85 = 5'h15 == io_readAddress_0 ? i_reg_21 : _GEN_84; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_86 = 5'h16 == io_readAddress_0 ? i_reg_22 : _GEN_85; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_87 = 5'h17 == io_readAddress_0 ? i_reg_23 : _GEN_86; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_88 = 5'h18 == io_readAddress_0 ? i_reg_24 : _GEN_87; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_89 = 5'h19 == io_readAddress_0 ? i_reg_25 : _GEN_88; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_90 = 5'h1a == io_readAddress_0 ? i_reg_26 : _GEN_89; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_91 = 5'h1b == io_readAddress_0 ? i_reg_27 : _GEN_90; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_92 = 5'h1c == io_readAddress_0 ? i_reg_28 : _GEN_91; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_93 = 5'h1d == io_readAddress_0 ? i_reg_29 : _GEN_92; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_94 = 5'h1e == io_readAddress_0 ? i_reg_30 : _GEN_93; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_95 = 5'h1f == io_readAddress_0 ? i_reg_31 : _GEN_94; // @[Mux.scala 101:{16,16}]
  wire  _io_readData_1_T = io_readAddress_1 != 5'h0; // @[Registers.scala 35:26]
  wire [31:0] _GEN_97 = 5'h1 == io_readAddress_1 ? i_reg_1 : i_reg_0; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_98 = 5'h2 == io_readAddress_1 ? i_reg_2 : _GEN_97; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_99 = 5'h3 == io_readAddress_1 ? i_reg_3 : _GEN_98; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_100 = 5'h4 == io_readAddress_1 ? i_reg_4 : _GEN_99; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_101 = 5'h5 == io_readAddress_1 ? i_reg_5 : _GEN_100; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_102 = 5'h6 == io_readAddress_1 ? i_reg_6 : _GEN_101; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_103 = 5'h7 == io_readAddress_1 ? i_reg_7 : _GEN_102; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_104 = 5'h8 == io_readAddress_1 ? i_reg_8 : _GEN_103; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_105 = 5'h9 == io_readAddress_1 ? i_reg_9 : _GEN_104; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_106 = 5'ha == io_readAddress_1 ? i_reg_10 : _GEN_105; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_107 = 5'hb == io_readAddress_1 ? i_reg_11 : _GEN_106; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_108 = 5'hc == io_readAddress_1 ? i_reg_12 : _GEN_107; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_109 = 5'hd == io_readAddress_1 ? i_reg_13 : _GEN_108; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_110 = 5'he == io_readAddress_1 ? i_reg_14 : _GEN_109; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_111 = 5'hf == io_readAddress_1 ? i_reg_15 : _GEN_110; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_112 = 5'h10 == io_readAddress_1 ? i_reg_16 : _GEN_111; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_113 = 5'h11 == io_readAddress_1 ? i_reg_17 : _GEN_112; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_114 = 5'h12 == io_readAddress_1 ? i_reg_18 : _GEN_113; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_115 = 5'h13 == io_readAddress_1 ? i_reg_19 : _GEN_114; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_116 = 5'h14 == io_readAddress_1 ? i_reg_20 : _GEN_115; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_117 = 5'h15 == io_readAddress_1 ? i_reg_21 : _GEN_116; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_118 = 5'h16 == io_readAddress_1 ? i_reg_22 : _GEN_117; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_119 = 5'h17 == io_readAddress_1 ? i_reg_23 : _GEN_118; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_120 = 5'h18 == io_readAddress_1 ? i_reg_24 : _GEN_119; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_121 = 5'h19 == io_readAddress_1 ? i_reg_25 : _GEN_120; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_122 = 5'h1a == io_readAddress_1 ? i_reg_26 : _GEN_121; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_123 = 5'h1b == io_readAddress_1 ? i_reg_27 : _GEN_122; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_124 = 5'h1c == io_readAddress_1 ? i_reg_28 : _GEN_123; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_125 = 5'h1d == io_readAddress_1 ? i_reg_29 : _GEN_124; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_126 = 5'h1e == io_readAddress_1 ? i_reg_30 : _GEN_125; // @[Mux.scala 101:{16,16}]
  wire [31:0] _GEN_127 = 5'h1f == io_readAddress_1 ? i_reg_31 : _GEN_126; // @[Mux.scala 101:{16,16}]
  assign io_readData_0 = _io_readData_0_T ? _GEN_95 : 32'h0; // @[Mux.scala 101:16]
  assign io_readData_1 = _io_readData_1_T ? _GEN_127 : 32'h0; // @[Mux.scala 101:16]
  always @(posedge clock) begin
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_0 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h0 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_0 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_1 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h1 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_1 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_2 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h2 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_2 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_3 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h3 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_3 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_4 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h4 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_4 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_5 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h5 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_5 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_6 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h6 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_6 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_7 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h7 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_7 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_8 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h8 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_8 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_9 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h9 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_9 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_10 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'ha == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_10 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_11 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'hb == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_11 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_12 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'hc == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_12 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_13 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'hd == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_13 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_14 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'he == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_14 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_15 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'hf == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_15 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_16 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h10 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_16 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_17 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h11 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_17 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_18 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h12 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_18 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_19 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h13 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_19 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_20 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h14 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_20 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_21 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h15 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_21 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_22 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h16 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_22 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_23 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h17 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_23 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_24 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h18 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_24 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_25 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h19 == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_25 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_26 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h1a == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_26 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_27 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h1b == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_27 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_28 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h1c == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_28 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_29 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h1d == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_29 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_30 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h1e == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_30 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
    if (reset) begin // @[Registers.scala 17:22]
      i_reg_31 <= 32'h0; // @[Registers.scala 17:22]
    end else if (io_writeEnable_0 & io_writeAddress != 5'h0) begin // @[Registers.scala 20:68]
      if (5'h1f == io_writeAddress) begin // @[Registers.scala 21:28]
        i_reg_31 <= io_writeData; // @[Registers.scala 21:28]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  i_reg_0 = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  i_reg_1 = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  i_reg_2 = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  i_reg_3 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  i_reg_4 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  i_reg_5 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  i_reg_6 = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  i_reg_7 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  i_reg_8 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  i_reg_9 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  i_reg_10 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  i_reg_11 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  i_reg_12 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  i_reg_13 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  i_reg_14 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  i_reg_15 = _RAND_15[31:0];
  _RAND_16 = {1{`RANDOM}};
  i_reg_16 = _RAND_16[31:0];
  _RAND_17 = {1{`RANDOM}};
  i_reg_17 = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  i_reg_18 = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  i_reg_19 = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  i_reg_20 = _RAND_20[31:0];
  _RAND_21 = {1{`RANDOM}};
  i_reg_21 = _RAND_21[31:0];
  _RAND_22 = {1{`RANDOM}};
  i_reg_22 = _RAND_22[31:0];
  _RAND_23 = {1{`RANDOM}};
  i_reg_23 = _RAND_23[31:0];
  _RAND_24 = {1{`RANDOM}};
  i_reg_24 = _RAND_24[31:0];
  _RAND_25 = {1{`RANDOM}};
  i_reg_25 = _RAND_25[31:0];
  _RAND_26 = {1{`RANDOM}};
  i_reg_26 = _RAND_26[31:0];
  _RAND_27 = {1{`RANDOM}};
  i_reg_27 = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  i_reg_28 = _RAND_28[31:0];
  _RAND_29 = {1{`RANDOM}};
  i_reg_29 = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  i_reg_30 = _RAND_30[31:0];
  _RAND_31 = {1{`RANDOM}};
  i_reg_31 = _RAND_31[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module ImmediateGen(
  input  [31:0] io_instruction,
  output [31:0] io_out
);
  wire [6:0] opcode = io_instruction[6:0]; // @[ImmediateGen.scala 11:30]
  wire  _T_11 = opcode == 7'h3 | opcode == 7'hf | opcode == 7'h13 | opcode == 7'h1b | opcode == 7'h67 | opcode == 7'h73; // @[ImmediateGen.scala 21:97]
  wire [11:0] imm_i = io_instruction[31:20]; // @[ImmediateGen.scala 24:31]
  wire [19:0] _ext_i_T_2 = imm_i[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 77:12]
  wire [31:0] ext_i = {_ext_i_T_2,imm_i}; // @[Cat.scala 33:92]
  wire [19:0] imm_u = io_instruction[31:12]; // @[ImmediateGen.scala 31:31]
  wire [31:0] ext_u = {imm_u,12'h0}; // @[Cat.scala 33:92]
  wire  _T_16 = opcode == 7'h23; // @[ImmediateGen.scala 37:13]
  wire [11:0] imm_s = {io_instruction[31:25],io_instruction[11:7]}; // @[Cat.scala 33:92]
  wire [19:0] _ext_s_T_2 = imm_s[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 77:12]
  wire [31:0] ext_s = {_ext_s_T_2,io_instruction[31:25],io_instruction[11:7]}; // @[Cat.scala 33:92]
  wire [11:0] imm_sb = {io_instruction[31],io_instruction[7],io_instruction[30:25],io_instruction[11:8]}; // @[Cat.scala 33:92]
  wire [18:0] _ext_sb_T_2 = imm_sb[11] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 77:12]
  wire [31:0] ext_sb = {_ext_sb_T_2,io_instruction[31],io_instruction[7],io_instruction[30:25],io_instruction[11:8],1'h0
    }; // @[Cat.scala 33:92]
  wire [19:0] imm_uj = {io_instruction[31],io_instruction[19:12],io_instruction[20],io_instruction[30:21]}; // @[Cat.scala 33:92]
  wire [10:0] _ext_uj_T_2 = imm_uj[19] ? 11'h7ff : 11'h0; // @[Bitwise.scala 77:12]
  wire [31:0] ext_uj = {_ext_uj_T_2,io_instruction[31],io_instruction[19:12],io_instruction[20],io_instruction[30:21],1'h0
    }; // @[Cat.scala 33:92]
  wire [31:0] _GEN_0 = opcode == 7'h63 ? ext_sb : ext_uj; // @[ImmediateGen.scala 45:30 53:12 65:12]
  wire [31:0] _GEN_1 = _T_16 ? ext_s : _GEN_0; // @[ImmediateGen.scala 39:5 42:12]
  wire [31:0] _GEN_2 = opcode == 7'h17 | opcode == 7'h37 ? ext_u : _GEN_1; // @[ImmediateGen.scala 30:49 33:12]
  wire [31:0] _GEN_3 = _T_11 ? ext_i : _GEN_2; // @[ImmediateGen.scala 23:5 26:12]
  assign io_out = opcode == 7'h2f ? 32'h0 : _GEN_3; // @[ImmediateGen.scala 16:33 17:12]
endmodule
module BranchUnit(
  input         io_branch,
  input  [2:0]  io_funct3,
  input  [31:0] io_rd1,
  input  [31:0] io_rd2,
  input         io_take_branch,
  output        io_taken
);
  wire  _check_T_9 = io_rd1 >= io_rd2; // @[BranchUnit.scala 28:32]
  wire  _GEN_1 = 3'h6 == io_funct3 ? io_rd1 < io_rd2 : _check_T_9; // @[BranchUnit.scala 22:21 27:21]
  wire  _GEN_2 = 3'h5 == io_funct3 ? $signed(io_rd1) >= $signed(io_rd2) : _GEN_1; // @[BranchUnit.scala 22:21 26:21]
  wire  _GEN_3 = 3'h4 == io_funct3 ? $signed(io_rd1) < $signed(io_rd2) : _GEN_2; // @[BranchUnit.scala 22:21 25:21]
  wire  _GEN_4 = 3'h1 == io_funct3 ? io_rd1 != io_rd2 : _GEN_3; // @[BranchUnit.scala 22:21 24:21]
  wire  check = 3'h0 == io_funct3 ? io_rd1 == io_rd2 : _GEN_4; // @[BranchUnit.scala 22:21 23:21]
  assign io_taken = check & io_branch & io_take_branch; // @[BranchUnit.scala 31:33]
endmodule
module InstructionDecode(
  input         clock,
  input         reset,
  input  [31:0] io_id_instruction,
  input  [31:0] io_writeData,
  input  [4:0]  io_writeReg,
  input  [31:0] io_pcAddress,
  input         io_ctl_writeEnable_0,
  input         io_ex_mem_mem_read,
  input  [4:0]  io_id_ex_rd,
  input  [4:0]  io_ex_mem_rd,
  input  [31:0] io_ex_mem_ins,
  input  [31:0] io_mem_wb_ins,
  input  [31:0] io_ex_ins,
  input  [31:0] io_ex_result,
  input  [31:0] io_ex_mem_result,
  input  [31:0] io_mem_wb_result,
  input         io_id_ex_regWr,
  input         io_ex_mem_regWr,
  input         io_csr_Ex,
  input         io_csr_Mem,
  input         io_csr_Wb,
  input  [31:0] io_csr_Ex_data,
  input  [31:0] io_csr_Mem_data,
  input  [31:0] io_csr_Wb_data,
  input  [31:0] io_dmem_data,
  input         io_ex_stall,
  output [31:0] io_immediate,
  output [4:0]  io_writeRegAddress,
  output [31:0] io_readData1,
  output [31:0] io_readData2,
  output [6:0]  io_func7,
  output [2:0]  io_func3,
  output        io_ctl_aluSrc,
  output [1:0]  io_ctl_memToReg,
  output        io_ctl_regWrite_0,
  output        io_ctl_memRead,
  output        io_ctl_memWrite,
  output        io_ctl_branch,
  output [1:0]  io_ctl_aluOp,
  output [1:0]  io_ctl_jump,
  output [1:0]  io_ctl_aluSrc1,
  output        io_hdu_pcWrite,
  output        io_hdu_if_reg_write,
  output        io_pcSrc,
  output [31:0] io_pcPlusOffset,
  output        io_ifid_flush,
  output        io_stall,
  input         io_csr_i_instr_retired,
  output [31:0] io_csr_o_data,
  output        io_is_csr,
  output        io_isAMO,
  output        io_isLR,
  output        io_isSC,
  output [4:0]  io_amoOp,
  input         io_ex_is_amo,
  input         io_mem_is_amo,
  input  [31:0] io_addr_ex,
  input  [31:0] io_addr_mem,
  input         io_is_comp
);
  wire [31:0] atomicDecoder_io_instr; // @[InstructionDecode.scala 110:29]
  wire  atomicDecoder_io_out_isLR; // @[InstructionDecode.scala 110:29]
  wire  atomicDecoder_io_out_isSC; // @[InstructionDecode.scala 110:29]
  wire  atomicDecoder_io_out_isAMO; // @[InstructionDecode.scala 110:29]
  wire [4:0] atomicDecoder_io_out_amoOp; // @[InstructionDecode.scala 110:29]
  wire  csr_clock; // @[InstructionDecode.scala 135:35]
  wire  csr_reset; // @[InstructionDecode.scala 135:35]
  wire [31:0] csr_io_i_data; // @[InstructionDecode.scala 135:35]
  wire [4:0] csr_io_i_imm; // @[InstructionDecode.scala 135:35]
  wire [31:0] csr_io_o_data; // @[InstructionDecode.scala 135:35]
  wire [2:0] csr_io_i_opr; // @[InstructionDecode.scala 135:35]
  wire [11:0] csr_io_i_addr; // @[InstructionDecode.scala 135:35]
  wire  csr_io_i_w_en; // @[InstructionDecode.scala 135:35]
  wire  csr_io_i_instr_retired; // @[InstructionDecode.scala 135:35]
  wire  csrController_io_regWrExecute; // @[InstructionDecode.scala 162:45]
  wire [4:0] csrController_io_rdSelExecute; // @[InstructionDecode.scala 162:45]
  wire  csrController_io_csrWrExecute; // @[InstructionDecode.scala 162:45]
  wire  csrController_io_regWrMemory; // @[InstructionDecode.scala 162:45]
  wire [4:0] csrController_io_rdSelMemory; // @[InstructionDecode.scala 162:45]
  wire  csrController_io_csrWrMemory; // @[InstructionDecode.scala 162:45]
  wire  csrController_io_regWrWriteback; // @[InstructionDecode.scala 162:45]
  wire [4:0] csrController_io_rdSelWriteback; // @[InstructionDecode.scala 162:45]
  wire  csrController_io_csrWrWriteback; // @[InstructionDecode.scala 162:45]
  wire [4:0] csrController_io_rs1SelDecode; // @[InstructionDecode.scala 162:45]
  wire  csrController_io_csrInstDecode; // @[InstructionDecode.scala 162:45]
  wire [2:0] csrController_io_forwardRS1; // @[InstructionDecode.scala 162:45]
  wire  hdu_io_ex_mem_memRead; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_taken; // @[InstructionDecode.scala 179:19]
  wire [1:0] hdu_io_jump; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_id_is_amo; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_ex_is_amo; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_mem_is_amo; // @[InstructionDecode.scala 179:19]
  wire [31:0] hdu_io_addr_id; // @[InstructionDecode.scala 179:19]
  wire [31:0] hdu_io_addr_ex; // @[InstructionDecode.scala 179:19]
  wire [31:0] hdu_io_addr_mem; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_if_reg_write; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_pc_write; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_ctl_mux; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_ifid_flush; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_take_branch; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_operandForwardEX; // @[InstructionDecode.scala 179:19]
  wire  hdu_io_operandForwardMEM; // @[InstructionDecode.scala 179:19]
  wire [31:0] control_io_in; // @[InstructionDecode.scala 194:23]
  wire  control_io_aluSrc; // @[InstructionDecode.scala 194:23]
  wire [1:0] control_io_memToReg; // @[InstructionDecode.scala 194:23]
  wire  control_io_regWrite; // @[InstructionDecode.scala 194:23]
  wire  control_io_memRead; // @[InstructionDecode.scala 194:23]
  wire  control_io_memWrite; // @[InstructionDecode.scala 194:23]
  wire  control_io_branch; // @[InstructionDecode.scala 194:23]
  wire [1:0] control_io_aluOp; // @[InstructionDecode.scala 194:23]
  wire [1:0] control_io_jump; // @[InstructionDecode.scala 194:23]
  wire [1:0] control_io_aluSrc1; // @[InstructionDecode.scala 194:23]
  wire  registers_clock; // @[InstructionDecode.scala 227:25]
  wire  registers_reset; // @[InstructionDecode.scala 227:25]
  wire [4:0] registers_io_readAddress_0; // @[InstructionDecode.scala 227:25]
  wire [4:0] registers_io_readAddress_1; // @[InstructionDecode.scala 227:25]
  wire  registers_io_writeEnable_0; // @[InstructionDecode.scala 227:25]
  wire [4:0] registers_io_writeAddress; // @[InstructionDecode.scala 227:25]
  wire [31:0] registers_io_writeData; // @[InstructionDecode.scala 227:25]
  wire [31:0] registers_io_readData_0; // @[InstructionDecode.scala 227:25]
  wire [31:0] registers_io_readData_1; // @[InstructionDecode.scala 227:25]
  wire [31:0] immediate_io_instruction; // @[InstructionDecode.scala 310:25]
  wire [31:0] immediate_io_out; // @[InstructionDecode.scala 310:25]
  wire  bu_io_branch; // @[InstructionDecode.scala 352:18]
  wire [2:0] bu_io_funct3; // @[InstructionDecode.scala 352:18]
  wire [31:0] bu_io_rd1; // @[InstructionDecode.scala 352:18]
  wire [31:0] bu_io_rd2; // @[InstructionDecode.scala 352:18]
  wire  bu_io_take_branch; // @[InstructionDecode.scala 352:18]
  wire  bu_io_taken; // @[InstructionDecode.scala 352:18]
  wire  _io_ctl_memToReg_T_1 = control_io_memToReg == 2'h2 & io_is_comp; // @[InstructionDecode.scala 203:35]
  wire [4:0] registerRs1 = io_id_instruction[19:15]; // @[InstructionDecode.scala 229:48]
  wire [31:0] writeData = io_csr_Wb ? io_csr_Wb_data : io_writeData; // @[InstructionDecode.scala 234:43]
  wire  _T_2 = io_writeReg == io_id_instruction[19:15]; // @[InstructionDecode.scala 255:18]
  wire  _T_3 = _T_2 & io_ctl_writeEnable_0; // @[InstructionDecode.scala 256:5]
  wire  _T_4 = io_id_instruction[19:15] == 5'h0; // @[InstructionDecode.scala 262:20]
  wire [31:0] _GEN_2 = _T_4 ? 32'h0 : io_writeData; // @[InstructionDecode.scala 264:7 265:17 267:17]
  wire [31:0] readData1 = _T_3 ? _GEN_2 : registers_io_readData_0; // @[InstructionDecode.scala 260:5 270:15]
  wire  _T_6 = io_writeReg == io_id_instruction[24:20]; // @[InstructionDecode.scala 274:18]
  wire  _T_7 = _T_6 & io_ctl_writeEnable_0; // @[InstructionDecode.scala 275:5]
  wire  _T_8 = io_id_instruction[24:20] == 5'h0; // @[InstructionDecode.scala 281:20]
  wire [31:0] _GEN_4 = _T_8 ? 32'h0 : io_writeData; // @[InstructionDecode.scala 283:7 284:17 286:17]
  wire [31:0] readData2 = _T_7 ? _GEN_4 : registers_io_readData_1; // @[InstructionDecode.scala 279:5 289:15]
  wire [31:0] _GEN_6 = hdu_io_operandForwardMEM ? io_ex_mem_result : readData1; // @[InstructionDecode.scala 272:16 304:40 305:18]
  wire [31:0] _GEN_7 = hdu_io_operandForwardMEM ? io_ex_mem_result : readData2; // @[InstructionDecode.scala 291:16 304:40 306:18]
  wire  fwd_ex = io_id_ex_regWr & io_ex_ins[11:7] != 5'h0; // @[InstructionDecode.scala 317:35]
  wire  fwd_ex_mem = io_ex_mem_regWr & io_ex_mem_ins[11:7] != 5'h0; // @[InstructionDecode.scala 318:36]
  wire  fwd_mem_wb = io_ctl_writeEnable_0 & io_mem_wb_ins[11:7] != 5'h0; // @[InstructionDecode.scala 319:42]
  wire  _T_12 = fwd_ex_mem & io_id_instruction[19:15] == io_ex_mem_ins[11:7]; // @[InstructionDecode.scala 325:16]
  wire  _T_16 = fwd_mem_wb & io_id_instruction[19:15] == io_mem_wb_ins[11:7]; // @[InstructionDecode.scala 330:16]
  wire [31:0] _GEN_10 = _T_16 ? io_mem_wb_result : readData1; // @[InstructionDecode.scala 332:5 333:12 335:12]
  wire [31:0] input1 = _T_12 ? io_ex_mem_result : _GEN_10; // @[InstructionDecode.scala 327:5 328:12]
  wire  _T_20 = fwd_ex_mem & io_id_instruction[24:20] == io_ex_mem_ins[11:7]; // @[InstructionDecode.scala 338:16]
  wire  _T_24 = fwd_mem_wb & io_id_instruction[24:20] == io_mem_wb_ins[11:7]; // @[InstructionDecode.scala 343:16]
  wire [31:0] _GEN_12 = _T_24 ? io_mem_wb_result : readData2; // @[InstructionDecode.scala 345:5 346:12 348:12]
  wire  _T_28 = fwd_ex & io_id_instruction[19:15] == io_ex_ins[11:7]; // @[InstructionDecode.scala 363:12]
  wire [31:0] j_offset = _T_28 ? io_ex_result : input1; // @[InstructionDecode.scala 365:5 366:14]
  wire [31:0] _io_pcPlusOffset_T_1 = io_pcAddress + io_immediate; // @[InstructionDecode.scala 383:37]
  wire [31:0] _io_pcPlusOffset_T_3 = j_offset + io_immediate; // @[InstructionDecode.scala 385:35]
  wire [31:0] _io_pcPlusOffset_T_5 = io_pcAddress + immediate_io_out; // @[InstructionDecode.scala 388:39]
  wire [31:0] _GEN_17 = io_ctl_jump == 2'h2 ? _io_pcPlusOffset_T_3 : _io_pcPlusOffset_T_5; // @[InstructionDecode.scala 384:35 385:23 388:23]
  wire  _T_46 = io_func3 == 3'h5; // @[InstructionDecode.scala 404:61]
  wire  _T_47 = io_id_instruction[6:0] == 7'h13 & io_func3 == 3'h5; // @[InstructionDecode.scala 404:49]
  wire  _T_48 = io_id_instruction[6:0] == 7'h33 | _T_47; // @[InstructionDecode.scala 403:47]
  wire  _T_51 = _T_48 | io_id_instruction[6:0] == 7'h53; // @[InstructionDecode.scala 405:7]
  wire  _io_stall_T_7 = io_func3 == 3'h4 | _T_46 | io_func3 == 3'h6 | io_func3 == 3'h7; // @[InstructionDecode.scala 413:62]
  wire [31:0] _T_52 = io_ex_mem_mem_read ? io_dmem_data : io_ex_mem_result; // @[InstructionDecode.scala 418:15]
  wire [31:0] _csr_io_i_data_T_1 = 3'h1 == csrController_io_forwardRS1 ? io_ex_result : registers_io_readData_0; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_3 = 3'h2 == csrController_io_forwardRS1 ? _T_52 : _csr_io_i_data_T_1; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_5 = 3'h3 == csrController_io_forwardRS1 ? io_writeData : _csr_io_i_data_T_3; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_7 = 3'h4 == csrController_io_forwardRS1 ? io_csr_Ex_data : _csr_io_i_data_T_5; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_9 = 3'h5 == csrController_io_forwardRS1 ? io_csr_Mem_data : _csr_io_i_data_T_7; // @[Mux.scala 81:58]
  AtomicDecoder atomicDecoder ( // @[InstructionDecode.scala 110:29]
    .io_instr(atomicDecoder_io_instr),
    .io_out_isLR(atomicDecoder_io_out_isLR),
    .io_out_isSC(atomicDecoder_io_out_isSC),
    .io_out_isAMO(atomicDecoder_io_out_isAMO),
    .io_out_amoOp(atomicDecoder_io_out_amoOp)
  );
  CSR csr ( // @[InstructionDecode.scala 135:35]
    .clock(csr_clock),
    .reset(csr_reset),
    .io_i_data(csr_io_i_data),
    .io_i_imm(csr_io_i_imm),
    .io_o_data(csr_io_o_data),
    .io_i_opr(csr_io_i_opr),
    .io_i_addr(csr_io_i_addr),
    .io_i_w_en(csr_io_i_w_en),
    .io_i_instr_retired(csr_io_i_instr_retired)
  );
  CSRController csrController ( // @[InstructionDecode.scala 162:45]
    .io_regWrExecute(csrController_io_regWrExecute),
    .io_rdSelExecute(csrController_io_rdSelExecute),
    .io_csrWrExecute(csrController_io_csrWrExecute),
    .io_regWrMemory(csrController_io_regWrMemory),
    .io_rdSelMemory(csrController_io_rdSelMemory),
    .io_csrWrMemory(csrController_io_csrWrMemory),
    .io_regWrWriteback(csrController_io_regWrWriteback),
    .io_rdSelWriteback(csrController_io_rdSelWriteback),
    .io_csrWrWriteback(csrController_io_csrWrWriteback),
    .io_rs1SelDecode(csrController_io_rs1SelDecode),
    .io_csrInstDecode(csrController_io_csrInstDecode),
    .io_forwardRS1(csrController_io_forwardRS1)
  );
  HazardUnit hdu ( // @[InstructionDecode.scala 179:19]
    .io_ex_mem_memRead(hdu_io_ex_mem_memRead),
    .io_taken(hdu_io_taken),
    .io_jump(hdu_io_jump),
    .io_id_is_amo(hdu_io_id_is_amo),
    .io_ex_is_amo(hdu_io_ex_is_amo),
    .io_mem_is_amo(hdu_io_mem_is_amo),
    .io_addr_id(hdu_io_addr_id),
    .io_addr_ex(hdu_io_addr_ex),
    .io_addr_mem(hdu_io_addr_mem),
    .io_if_reg_write(hdu_io_if_reg_write),
    .io_pc_write(hdu_io_pc_write),
    .io_ctl_mux(hdu_io_ctl_mux),
    .io_ifid_flush(hdu_io_ifid_flush),
    .io_take_branch(hdu_io_take_branch),
    .io_operandForwardEX(hdu_io_operandForwardEX),
    .io_operandForwardMEM(hdu_io_operandForwardMEM)
  );
  Control control ( // @[InstructionDecode.scala 194:23]
    .io_in(control_io_in),
    .io_aluSrc(control_io_aluSrc),
    .io_memToReg(control_io_memToReg),
    .io_regWrite(control_io_regWrite),
    .io_memRead(control_io_memRead),
    .io_memWrite(control_io_memWrite),
    .io_branch(control_io_branch),
    .io_aluOp(control_io_aluOp),
    .io_jump(control_io_jump),
    .io_aluSrc1(control_io_aluSrc1)
  );
  Registers registers ( // @[InstructionDecode.scala 227:25]
    .clock(registers_clock),
    .reset(registers_reset),
    .io_readAddress_0(registers_io_readAddress_0),
    .io_readAddress_1(registers_io_readAddress_1),
    .io_writeEnable_0(registers_io_writeEnable_0),
    .io_writeAddress(registers_io_writeAddress),
    .io_writeData(registers_io_writeData),
    .io_readData_0(registers_io_readData_0),
    .io_readData_1(registers_io_readData_1)
  );
  ImmediateGen immediate ( // @[InstructionDecode.scala 310:25]
    .io_instruction(immediate_io_instruction),
    .io_out(immediate_io_out)
  );
  BranchUnit bu ( // @[InstructionDecode.scala 352:18]
    .io_branch(bu_io_branch),
    .io_funct3(bu_io_funct3),
    .io_rd1(bu_io_rd1),
    .io_rd2(bu_io_rd2),
    .io_take_branch(bu_io_take_branch),
    .io_taken(bu_io_taken)
  );
  assign io_immediate = immediate_io_out; // @[InstructionDecode.scala 312:16]
  assign io_writeRegAddress = io_id_instruction[11:7]; // @[InstructionDecode.scala 400:42]
  assign io_readData1 = hdu_io_operandForwardEX ? io_ex_result : _GEN_6; // @[InstructionDecode.scala 301:33 302:18]
  assign io_readData2 = hdu_io_operandForwardEX ? io_ex_result : _GEN_7; // @[InstructionDecode.scala 301:33 303:18]
  assign io_func7 = _T_51 ? io_id_instruction[31:25] : 7'h0; // @[InstructionDecode.scala 406:4 407:14 409:14]
  assign io_func3 = io_id_instruction[14:12]; // @[InstructionDecode.scala 401:32]
  assign io_ctl_aluSrc = control_io_aluSrc; // @[InstructionDecode.scala 197:17]
  assign io_ctl_memToReg = _io_ctl_memToReg_T_1 ? 2'h3 : control_io_memToReg; // @[InstructionDecode.scala 202:15]
  assign io_ctl_regWrite_0 = hdu_io_ctl_mux & io_id_instruction != 32'h13 & control_io_regWrite; // @[InstructionDecode.scala 210:57 212:24 215:24]
  assign io_ctl_memRead = control_io_memRead; // @[InstructionDecode.scala 200:18]
  assign io_ctl_memWrite = hdu_io_ctl_mux & io_id_instruction != 32'h13 & control_io_memWrite; // @[InstructionDecode.scala 210:57 211:21 214:21]
  assign io_ctl_branch = control_io_branch; // @[InstructionDecode.scala 199:17]
  assign io_ctl_aluOp = control_io_aluOp; // @[InstructionDecode.scala 196:16]
  assign io_ctl_jump = control_io_jump; // @[InstructionDecode.scala 209:15]
  assign io_ctl_aluSrc1 = control_io_aluSrc1; // @[InstructionDecode.scala 198:18]
  assign io_hdu_pcWrite = hdu_io_pc_write; // @[InstructionDecode.scala 190:18]
  assign io_hdu_if_reg_write = hdu_io_if_reg_write; // @[InstructionDecode.scala 191:23]
  assign io_pcSrc = bu_io_taken | io_ctl_jump != 2'h0; // @[InstructionDecode.scala 391:20]
  assign io_pcPlusOffset = io_ctl_jump == 2'h1 ? _io_pcPlusOffset_T_1 : _GEN_17; // @[InstructionDecode.scala 382:29 383:21]
  assign io_ifid_flush = hdu_io_ifid_flush; // @[InstructionDecode.scala 398:17]
  assign io_stall = io_func7 == 7'h1 & _io_stall_T_7; // @[InstructionDecode.scala 412:32]
  assign io_csr_o_data = csr_io_o_data; // @[InstructionDecode.scala 157:39]
  assign io_is_csr = io_id_instruction[6:0] == 7'h73; // @[InstructionDecode.scala 146:64]
  assign io_isAMO = atomicDecoder_io_out_isAMO; // @[InstructionDecode.scala 113:12]
  assign io_isLR = atomicDecoder_io_out_isLR; // @[InstructionDecode.scala 114:12]
  assign io_isSC = atomicDecoder_io_out_isSC; // @[InstructionDecode.scala 115:12]
  assign io_amoOp = atomicDecoder_io_out_amoOp; // @[InstructionDecode.scala 116:12]
  assign atomicDecoder_io_instr = io_id_instruction; // @[InstructionDecode.scala 111:26]
  assign csr_clock = clock;
  assign csr_reset = reset;
  assign csr_io_i_data = 3'h6 == csrController_io_forwardRS1 ? io_csr_Wb_data : _csr_io_i_data_T_9; // @[Mux.scala 81:58]
  assign csr_io_i_imm = io_id_instruction[19:15]; // @[InstructionDecode.scala 140:57]
  assign csr_io_i_opr = io_id_instruction[14:12]; // @[InstructionDecode.scala 141:57]
  assign csr_io_i_addr = io_id_instruction[31:20]; // @[InstructionDecode.scala 142:57]
  assign csr_io_i_w_en = io_is_csr & io_id_instruction[19:15] != 5'h0; // @[InstructionDecode.scala 143:54]
  assign csr_io_i_instr_retired = io_csr_i_instr_retired; // @[InstructionDecode.scala 144:37]
  assign csrController_io_regWrExecute = io_id_ex_regWr; // @[InstructionDecode.scala 164:42]
  assign csrController_io_rdSelExecute = io_id_ex_rd; // @[InstructionDecode.scala 165:42]
  assign csrController_io_csrWrExecute = io_csr_Ex; // @[InstructionDecode.scala 166:42]
  assign csrController_io_regWrMemory = io_ex_mem_regWr; // @[InstructionDecode.scala 167:42]
  assign csrController_io_rdSelMemory = io_ex_mem_rd; // @[InstructionDecode.scala 168:42]
  assign csrController_io_csrWrMemory = io_csr_Mem; // @[InstructionDecode.scala 169:42]
  assign csrController_io_regWrWriteback = io_ctl_writeEnable_0; // @[InstructionDecode.scala 170:42]
  assign csrController_io_rdSelWriteback = io_writeReg; // @[InstructionDecode.scala 171:42]
  assign csrController_io_csrWrWriteback = io_csr_Wb; // @[InstructionDecode.scala 172:42]
  assign csrController_io_rs1SelDecode = io_id_instruction[19:15]; // @[InstructionDecode.scala 173:62]
  assign csrController_io_csrInstDecode = io_id_instruction[6:0] == 7'h73; // @[InstructionDecode.scala 174:69]
  assign hdu_io_ex_mem_memRead = io_ex_mem_mem_read; // @[InstructionDecode.scala 182:25]
  assign hdu_io_taken = bu_io_taken; // @[InstructionDecode.scala 358:16]
  assign hdu_io_jump = io_ctl_jump; // @[InstructionDecode.scala 188:15]
  assign hdu_io_id_is_amo = io_isAMO; // @[InstructionDecode.scala 432:21]
  assign hdu_io_ex_is_amo = io_ex_is_amo; // @[InstructionDecode.scala 433:21]
  assign hdu_io_mem_is_amo = io_mem_is_amo; // @[InstructionDecode.scala 434:21]
  assign hdu_io_addr_id = _T_3 ? _GEN_2 : registers_io_readData_0; // @[InstructionDecode.scala 260:5 270:15]
  assign hdu_io_addr_ex = io_addr_ex; // @[InstructionDecode.scala 437:19]
  assign hdu_io_addr_mem = io_addr_mem; // @[InstructionDecode.scala 438:19]
  assign control_io_in = io_id_instruction; // @[InstructionDecode.scala 195:17]
  assign registers_clock = clock;
  assign registers_reset = reset;
  assign registers_io_readAddress_0 = io_id_instruction[19:15]; // @[InstructionDecode.scala 236:31]
  assign registers_io_readAddress_1 = io_id_instruction[24:20]; // @[InstructionDecode.scala 230:38]
  assign registers_io_writeEnable_0 = io_ctl_writeEnable_0 | io_csr_Wb; // @[InstructionDecode.scala 241:57]
  assign registers_io_writeAddress = io_writeReg; // @[InstructionDecode.scala 245:29]
  assign registers_io_writeData = writeData; // @[InstructionDecode.scala 246:26]
  assign immediate_io_instruction = io_id_instruction; // @[InstructionDecode.scala 311:28]
  assign bu_io_branch = io_ctl_branch; // @[InstructionDecode.scala 353:16]
  assign bu_io_funct3 = io_id_instruction[14:12]; // @[InstructionDecode.scala 354:36]
  assign bu_io_rd1 = _T_12 ? io_ex_mem_result : _GEN_10; // @[InstructionDecode.scala 327:5 328:12]
  assign bu_io_rd2 = _T_20 ? io_ex_mem_result : _GEN_12; // @[InstructionDecode.scala 340:5 341:12]
  assign bu_io_take_branch = hdu_io_take_branch; // @[InstructionDecode.scala 357:21]
endmodule
module ALU(
  input  [31:0] io_input1,
  input  [31:0] io_input2,
  input  [3:0]  io_aluCtl,
  output [31:0] io_result
);
  wire  _io_result_T = io_aluCtl == 4'h0; // @[ALU.scala 19:18]
  wire [31:0] _io_result_T_1 = io_input1 & io_input2; // @[ALU.scala 19:41]
  wire  _io_result_T_2 = io_aluCtl == 4'h1; // @[ALU.scala 20:18]
  wire [31:0] _io_result_T_3 = io_input1 | io_input2; // @[ALU.scala 20:40]
  wire  _io_result_T_4 = io_aluCtl == 4'h2; // @[ALU.scala 21:18]
  wire [31:0] _io_result_T_6 = io_input1 + io_input2; // @[ALU.scala 21:41]
  wire  _io_result_T_7 = io_aluCtl == 4'h3; // @[ALU.scala 22:18]
  wire [31:0] _io_result_T_9 = io_input1 - io_input2; // @[ALU.scala 22:41]
  wire  _io_result_T_10 = io_aluCtl == 4'h4; // @[ALU.scala 23:18]
  wire  _io_result_T_13 = $signed(io_input1) < $signed(io_input2); // @[ALU.scala 23:48]
  wire  _io_result_T_14 = io_aluCtl == 4'h5; // @[ALU.scala 24:18]
  wire  _io_result_T_15 = io_input1 < io_input2; // @[ALU.scala 24:42]
  wire  _io_result_T_16 = io_aluCtl == 4'h6; // @[ALU.scala 25:18]
  wire [62:0] _GEN_0 = {{31'd0}, io_input1}; // @[ALU.scala 25:41]
  wire [62:0] _io_result_T_18 = _GEN_0 << io_input2[4:0]; // @[ALU.scala 25:41]
  wire  _io_result_T_19 = io_aluCtl == 4'h7; // @[ALU.scala 26:18]
  wire [31:0] _io_result_T_21 = io_input1 >> io_input2[4:0]; // @[ALU.scala 26:41]
  wire  _io_result_T_22 = io_aluCtl == 4'h8; // @[ALU.scala 27:18]
  wire [31:0] _io_result_T_26 = $signed(io_input1) >>> io_input2[4:0]; // @[ALU.scala 27:68]
  wire  _io_result_T_27 = io_aluCtl == 4'h9; // @[ALU.scala 28:18]
  wire [31:0] _io_result_T_28 = io_input1 ^ io_input2; // @[ALU.scala 28:41]
  wire [31:0] _io_result_T_29 = _io_result_T_27 ? _io_result_T_28 : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _io_result_T_30 = _io_result_T_22 ? _io_result_T_26 : _io_result_T_29; // @[Mux.scala 101:16]
  wire [31:0] _io_result_T_31 = _io_result_T_19 ? _io_result_T_21 : _io_result_T_30; // @[Mux.scala 101:16]
  wire [62:0] _io_result_T_32 = _io_result_T_16 ? _io_result_T_18 : {{31'd0}, _io_result_T_31}; // @[Mux.scala 101:16]
  wire [62:0] _io_result_T_33 = _io_result_T_14 ? {{62'd0}, _io_result_T_15} : _io_result_T_32; // @[Mux.scala 101:16]
  wire [62:0] _io_result_T_34 = _io_result_T_10 ? {{62'd0}, _io_result_T_13} : _io_result_T_33; // @[Mux.scala 101:16]
  wire [62:0] _io_result_T_35 = _io_result_T_7 ? {{31'd0}, _io_result_T_9} : _io_result_T_34; // @[Mux.scala 101:16]
  wire [62:0] _io_result_T_36 = _io_result_T_4 ? {{31'd0}, _io_result_T_6} : _io_result_T_35; // @[Mux.scala 101:16]
  wire [62:0] _io_result_T_37 = _io_result_T_2 ? {{31'd0}, _io_result_T_3} : _io_result_T_36; // @[Mux.scala 101:16]
  wire [62:0] _io_result_T_38 = _io_result_T ? {{31'd0}, _io_result_T_1} : _io_result_T_37; // @[Mux.scala 101:16]
  assign io_result = _io_result_T_38[31:0]; // @[ALU.scala 16:13]
endmodule
module AluControl(
  input  [1:0] io_aluOp,
  input        io_f7,
  input  [2:0] io_f3,
  input        io_aluSrc,
  output [3:0] io_out
);
  wire  _T_4 = ~io_f7; // @[AluControl.scala 40:34]
  wire [1:0] _GEN_0 = ~io_aluSrc | ~io_f7 ? 2'h2 : 2'h3; // @[AluControl.scala 40:43 41:18 44:20]
  wire [3:0] _GEN_1 = _T_4 ? 4'h7 : 4'h8; // @[AluControl.scala 57:29 58:18 60:18]
  wire [3:0] _GEN_2 = 3'h4 == io_f3 ? 4'h9 : 4'hf; // @[AluControl.scala 31:10 38:19 70:16]
  wire [3:0] _GEN_3 = 3'h6 == io_f3 ? 4'h1 : _GEN_2; // @[AluControl.scala 38:19 67:16]
  wire [3:0] _GEN_4 = 3'h7 == io_f3 ? 4'h0 : _GEN_3; // @[AluControl.scala 38:19 64:16]
  wire [3:0] _GEN_5 = 3'h5 == io_f3 ? _GEN_1 : _GEN_4; // @[AluControl.scala 38:19]
  wire [3:0] _GEN_6 = 3'h3 == io_f3 ? 4'h5 : _GEN_5; // @[AluControl.scala 38:19 54:16]
  wire [3:0] _GEN_7 = 3'h2 == io_f3 ? 4'h4 : _GEN_6; // @[AluControl.scala 38:19 51:16]
  wire [3:0] _GEN_8 = 3'h1 == io_f3 ? 4'h6 : _GEN_7; // @[AluControl.scala 38:19 48:16]
  wire [3:0] _GEN_9 = 3'h0 == io_f3 ? {{2'd0}, _GEN_0} : _GEN_8; // @[AluControl.scala 38:19]
  wire [3:0] _GEN_10 = io_aluOp == 2'h1 ? 4'hf : _GEN_9; // @[AluControl.scala 35:32 36:12]
  assign io_out = io_aluOp == 2'h0 ? 4'h2 : _GEN_10; // @[AluControl.scala 33:26 34:12]
endmodule
module AMOALU(
  input  [31:0] io_memData,
  input  [31:0] io_src2,
  input  [4:0]  io_amoOp,
  output [31:0] io_result
);
  wire [31:0] _io_result_T_1 = io_memData + io_src2; // @[AtomicAlu.scala 31:33]
  wire [31:0] _io_result_T_2 = io_memData ^ io_src2; // @[AtomicAlu.scala 35:33]
  wire [31:0] _io_result_T_3 = io_memData & io_src2; // @[AtomicAlu.scala 37:33]
  wire [31:0] _io_result_T_4 = io_memData | io_src2; // @[AtomicAlu.scala 39:33]
  wire [31:0] _io_result_T_6 = $signed(io_memData) < $signed(io_src2) ? io_memData : io_src2; // @[AtomicAlu.scala 41:25]
  wire [31:0] _io_result_T_8 = $signed(io_memData) > $signed(io_src2) ? io_memData : io_src2; // @[AtomicAlu.scala 43:25]
  wire [31:0] _io_result_T_10 = io_memData < io_src2 ? io_memData : io_src2; // @[AtomicAlu.scala 45:25]
  wire [31:0] _io_result_T_12 = io_memData > io_src2 ? io_memData : io_src2; // @[AtomicAlu.scala 47:25]
  wire [31:0] _GEN_0 = 5'h1c == io_amoOp ? _io_result_T_12 : 32'h0; // @[AtomicAlu.scala 12:13 29:20 47:19]
  wire [31:0] _GEN_1 = 5'h18 == io_amoOp ? _io_result_T_10 : _GEN_0; // @[AtomicAlu.scala 29:20 45:19]
  wire [31:0] _GEN_2 = 5'h14 == io_amoOp ? _io_result_T_8 : _GEN_1; // @[AtomicAlu.scala 29:20 43:19]
  wire [31:0] _GEN_3 = 5'h10 == io_amoOp ? _io_result_T_6 : _GEN_2; // @[AtomicAlu.scala 29:20 41:19]
  wire [31:0] _GEN_4 = 5'h8 == io_amoOp ? _io_result_T_4 : _GEN_3; // @[AtomicAlu.scala 29:20 39:19]
  wire [31:0] _GEN_5 = 5'hc == io_amoOp ? _io_result_T_3 : _GEN_4; // @[AtomicAlu.scala 29:20 37:19]
  wire [31:0] _GEN_6 = 5'h4 == io_amoOp ? _io_result_T_2 : _GEN_5; // @[AtomicAlu.scala 29:20 35:19]
  wire [31:0] _GEN_7 = 5'h1 == io_amoOp ? io_src2 : _GEN_6; // @[AtomicAlu.scala 29:20 33:19]
  assign io_result = 5'h0 == io_amoOp ? _io_result_T_1 : _GEN_7; // @[AtomicAlu.scala 29:20 31:19]
endmodule
module ForwardingUnit(
  input  [4:0] io_ex_reg_rd,
  input  [4:0] io_mem_reg_rd,
  input  [4:0] io_reg_rs1,
  input  [4:0] io_reg_rs2,
  input        io_ex_regWrite_0,
  input        io_mem_regWrite_0,
  output [1:0] io_forwardA,
  output [1:0] io_forwardB
);
  wire  _T = io_reg_rs1 == io_ex_reg_rd; // @[ForwardingUnit.scala 27:17]
  wire  _T_2 = io_ex_regWrite_0 ? io_ex_reg_rd != 5'h0 : 1'h1; // @[ForwardingUnit.scala 28:11]
  wire  _T_3 = _T & _T_2; // @[ForwardingUnit.scala 28:5]
  wire  _T_4 = _T_3 & io_ex_regWrite_0; // @[ForwardingUnit.scala 29:5]
  wire  _T_5 = io_reg_rs1 == io_mem_reg_rd; // @[ForwardingUnit.scala 36:17]
  wire  _T_7 = io_mem_regWrite_0 ? io_mem_reg_rd != 5'h0 : 1'h1; // @[ForwardingUnit.scala 37:11]
  wire  _T_8 = _T_5 & _T_7; // @[ForwardingUnit.scala 37:5]
  wire  _T_9 = _T_8 & io_mem_regWrite_0; // @[ForwardingUnit.scala 38:5]
  wire [1:0] _GEN_0 = _T_9 ? 2'h2 : 2'h0; // @[ForwardingUnit.scala 42:5 43:17 45:17]
  wire  _T_10 = io_reg_rs2 == io_ex_reg_rd; // @[ForwardingUnit.scala 49:17]
  wire  _T_13 = _T_10 & _T_2; // @[ForwardingUnit.scala 50:5]
  wire  _T_14 = _T_13 & io_ex_regWrite_0; // @[ForwardingUnit.scala 51:5]
  wire  _T_15 = io_reg_rs2 == io_mem_reg_rd; // @[ForwardingUnit.scala 58:17]
  wire  _T_18 = _T_15 & _T_7; // @[ForwardingUnit.scala 59:5]
  wire  _T_19 = _T_18 & io_mem_regWrite_0; // @[ForwardingUnit.scala 60:5]
  wire [1:0] _GEN_2 = _T_19 ? 2'h2 : 2'h0; // @[ForwardingUnit.scala 64:5 65:17 67:17]
  assign io_forwardA = _T_4 ? 2'h1 : _GEN_0; // @[ForwardingUnit.scala 33:5 34:17]
  assign io_forwardB = _T_14 ? 2'h1 : _GEN_2; // @[ForwardingUnit.scala 55:5 56:17]
endmodule
module MDU(
  input         clock,
  input         reset,
  input  [31:0] io_src_a,
  input  [31:0] io_src_b,
  input  [4:0]  io_op,
  input         io_valid,
  output        io_ready,
  output        io_output_valid,
  output [31:0] io_output_bits
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  wire  _result_T = io_op == 5'h0; // @[MDU.scala 36:16]
  wire  _result_T_1 = io_op == 5'h3; // @[MDU.scala 36:33]
  wire  _result_T_2 = io_op == 5'h0 | io_op == 5'h3; // @[MDU.scala 36:24]
  wire [63:0] _result_T_3 = io_src_a * io_src_b; // @[MDU.scala 36:58]
  wire  _result_T_4 = io_op == 5'h2; // @[MDU.scala 37:16]
  wire [32:0] _result_T_6 = {1'b0,$signed(io_src_b)}; // @[MDU.scala 37:66]
  wire [64:0] _result_T_7 = $signed(io_src_a) * $signed(_result_T_6); // @[MDU.scala 37:66]
  wire [63:0] _result_T_10 = _result_T_7[63:0]; // @[MDU.scala 37:78]
  wire  _result_T_11 = io_op == 5'h1; // @[MDU.scala 38:16]
  wire [63:0] _result_T_15 = $signed(io_src_a) * $signed(io_src_b); // @[MDU.scala 38:85]
  wire [63:0] _result_T_16 = _result_T_11 ? _result_T_15 : 64'h0; // @[Mux.scala 101:16]
  wire [63:0] _result_T_17 = _result_T_4 ? _result_T_10 : _result_T_16; // @[Mux.scala 101:16]
  wire [63:0] result = _result_T_2 ? _result_T_3 : _result_T_17; // @[Mux.scala 101:16]
  reg  r_ready; // @[MDU.scala 43:29]
  reg [5:0] r_counter; // @[MDU.scala 44:29]
  reg [31:0] r_dividend; // @[MDU.scala 45:29]
  reg [31:0] r_quotient; // @[MDU.scala 46:29]
  wire  _is_div_rem_u_T = io_op == 5'h5; // @[MDU.scala 50:39]
  wire  _is_div_rem_u_T_1 = io_op == 5'h7; // @[MDU.scala 50:57]
  wire  is_div_rem_u = io_op == 5'h5 | io_op == 5'h7; // @[MDU.scala 50:48]
  wire  _is_div_rem_s_T = io_op == 5'h4; // @[MDU.scala 51:39]
  wire  _is_div_rem_s_T_1 = io_op == 5'h6; // @[MDU.scala 51:56]
  wire  is_div_rem_s = io_op == 5'h4 | io_op == 5'h6; // @[MDU.scala 51:47]
  wire [31:0] _dividend_T_3 = 32'h0 - io_src_a; // @[MDU.scala 53:59]
  wire [31:0] dividend = is_div_rem_s & io_src_a[31] ? _dividend_T_3 : io_src_a; // @[MDU.scala 53:28]
  wire [31:0] _divisor_T_3 = 32'h0 - io_src_b; // @[MDU.scala 54:59]
  wire [31:0] divisor = is_div_rem_s & io_src_b[31] ? _divisor_T_3 : io_src_b; // @[MDU.scala 54:28]
  wire [5:0] _T_4 = r_counter - 6'h1; // @[MDU.scala 61:52]
  wire [94:0] _GEN_2 = {{63'd0}, divisor}; // @[MDU.scala 61:40]
  wire [94:0] _T_5 = _GEN_2 << _T_4; // @[MDU.scala 61:40]
  wire [94:0] _GEN_26 = {{63'd0}, r_dividend}; // @[MDU.scala 61:29]
  wire [94:0] _r_dividend_T_4 = _GEN_26 - _T_5; // @[MDU.scala 62:45]
  wire [63:0] _r_quotient_T_2 = 64'h1 << _T_4; // @[MDU.scala 63:51]
  wire [63:0] _GEN_28 = {{32'd0}, r_quotient}; // @[MDU.scala 63:45]
  wire [63:0] _r_quotient_T_4 = _GEN_28 + _r_quotient_T_2; // @[MDU.scala 63:45]
  wire [94:0] _GEN_0 = _GEN_26 >= _T_5 ? _r_dividend_T_4 : {{63'd0}, r_dividend}; // @[MDU.scala 45:29 61:59 62:31]
  wire [63:0] _GEN_1 = _GEN_26 >= _T_5 ? _r_quotient_T_4 : {{32'd0}, r_quotient}; // @[MDU.scala 46:29 61:59 63:31]
  wire [94:0] _GEN_3 = r_counter != 6'h0 ? _GEN_0 : {{63'd0}, r_dividend}; // @[MDU.scala 45:29 60:38]
  wire [63:0] _GEN_4 = r_counter != 6'h0 ? _GEN_1 : {{32'd0}, r_quotient}; // @[MDU.scala 46:29 60:38]
  wire  _GEN_5 = r_counter != 6'h0 ? r_counter == 6'h1 : r_ready; // @[MDU.scala 60:38 68:24 43:29]
  wire  _GEN_7 = r_counter != 6'h0 ? 1'h0 : 1'h1; // @[MDU.scala 48:21 60:38 70:29]
  wire  _GEN_8 = io_valid ? 1'h0 : _GEN_5; // @[MDU.scala 55:32 56:24]
  wire [94:0] _GEN_10 = io_valid ? {{63'd0}, dividend} : _GEN_3; // @[MDU.scala 55:32 58:24]
  wire [63:0] _GEN_11 = io_valid ? 64'h0 : _GEN_4; // @[MDU.scala 55:32 59:24]
  wire  _GEN_12 = io_valid ? 1'h0 : _GEN_7; // @[MDU.scala 48:21 55:32]
  wire  _GEN_13 = is_div_rem_s | is_div_rem_u ? _GEN_8 : r_ready; // @[MDU.scala 43:29 52:39]
  wire [94:0] _GEN_15 = is_div_rem_s | is_div_rem_u ? _GEN_10 : {{63'd0}, r_dividend}; // @[MDU.scala 45:29 52:39]
  wire [63:0] _GEN_16 = is_div_rem_s | is_div_rem_u ? _GEN_11 : {{32'd0}, r_quotient}; // @[MDU.scala 46:29 52:39]
  wire  _GEN_17 = (is_div_rem_s | is_div_rem_u) & _GEN_12; // @[MDU.scala 48:21 52:39]
  wire [31:0] _io_output_bits_T_8 = 32'h0 - r_quotient; // @[MDU.scala 82:76]
  wire [31:0] _io_output_bits_T_9 = io_src_a[31] != io_src_b[31] & |io_src_b ? _io_output_bits_T_8 : r_quotient; // @[MDU.scala 82:30]
  wire [31:0] _io_output_bits_T_12 = 32'h0 - r_dividend; // @[MDU.scala 86:44]
  wire [31:0] _io_output_bits_T_13 = io_src_a[31] ? _io_output_bits_T_12 : r_dividend; // @[MDU.scala 86:30]
  wire [31:0] _GEN_18 = _is_div_rem_u_T_1 ? r_dividend : 32'h0; // @[MDU.scala 87:31 88:24 90:24]
  wire [31:0] _GEN_19 = _is_div_rem_s_T_1 ? _io_output_bits_T_13 : _GEN_18; // @[MDU.scala 85:30 86:24]
  wire [31:0] _GEN_20 = _is_div_rem_u_T ? r_quotient : _GEN_19; // @[MDU.scala 83:31 84:24]
  wire [31:0] _GEN_21 = _is_div_rem_s_T ? _io_output_bits_T_9 : _GEN_20; // @[MDU.scala 81:30 82:24]
  wire [31:0] _GEN_22 = _result_T_11 | _result_T_1 | _result_T_4 ? result[63:32] : _GEN_21; // @[MDU.scala 78:70 79:24]
  wire  _GEN_23 = _result_T_11 | _result_T_1 | _result_T_4 | _GEN_17; // @[MDU.scala 78:70 80:25]
  wire [94:0] _GEN_29 = reset ? 95'h0 : _GEN_15; // @[MDU.scala 45:{29,29}]
  wire [63:0] _GEN_30 = reset ? 64'h0 : _GEN_16; // @[MDU.scala 46:{29,29}]
  assign io_ready = r_ready; // @[MDU.scala 74:18]
  assign io_output_valid = _result_T | _GEN_23; // @[MDU.scala 75:24 77:25]
  assign io_output_bits = _result_T ? result[31:0] : _GEN_22; // @[MDU.scala 75:24 76:24]
  always @(posedge clock) begin
    r_ready <= reset | _GEN_13; // @[MDU.scala 43:{29,29}]
    if (reset) begin // @[MDU.scala 44:29]
      r_counter <= 6'h20; // @[MDU.scala 44:29]
    end else if (is_div_rem_s | is_div_rem_u) begin // @[MDU.scala 52:39]
      if (io_valid) begin // @[MDU.scala 55:32]
        r_counter <= 6'h20; // @[MDU.scala 57:24]
      end else if (r_counter != 6'h0) begin // @[MDU.scala 60:38]
        r_counter <= _T_4; // @[MDU.scala 67:24]
      end
    end
    r_dividend <= _GEN_29[31:0]; // @[MDU.scala 45:{29,29}]
    r_quotient <= _GEN_30[31:0]; // @[MDU.scala 46:{29,29}]
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  r_ready = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  r_counter = _RAND_1[5:0];
  _RAND_2 = {1{`RANDOM}};
  r_dividend = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  r_quotient = _RAND_3[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Execute(
  input         clock,
  input         reset,
  input  [31:0] io_immediate,
  input  [31:0] io_readData1,
  input  [31:0] io_readData2,
  input  [31:0] io_pcAddress,
  input  [6:0]  io_func7,
  input  [2:0]  io_func3,
  input  [31:0] io_mem_result,
  input  [31:0] io_wb_result,
  input         io_ex_mem_regWrite_0,
  input         io_mem_wb_regWrite_0,
  input  [31:0] io_id_ex_ins,
  input  [31:0] io_ex_mem_ins,
  input  [31:0] io_mem_wb_ins,
  input         io_ctl_aluSrc,
  input  [1:0]  io_ctl_aluOp,
  input  [1:0]  io_ctl_aluSrc1,
  input         io_isAMO,
  input         io_isLR,
  input         io_isSC,
  output [31:0] io_writeData,
  output [31:0] io_ALUresult,
  output        io_stall,
  input  [31:0] io_amo_memData,
  input  [31:0] io_amo_src2,
  input  [4:0]  io_amo_op_code,
  output [31:0] io_amo_result
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] alu_io_input1; // @[Execute.scala 57:19]
  wire [31:0] alu_io_input2; // @[Execute.scala 57:19]
  wire [3:0] alu_io_aluCtl; // @[Execute.scala 57:19]
  wire [31:0] alu_io_result; // @[Execute.scala 57:19]
  wire [1:0] aluCtl_io_aluOp; // @[Execute.scala 58:22]
  wire  aluCtl_io_f7; // @[Execute.scala 58:22]
  wire [2:0] aluCtl_io_f3; // @[Execute.scala 58:22]
  wire  aluCtl_io_aluSrc; // @[Execute.scala 58:22]
  wire [3:0] aluCtl_io_out; // @[Execute.scala 58:22]
  wire [31:0] amoAlu_io_memData; // @[Execute.scala 60:22]
  wire [31:0] amoAlu_io_src2; // @[Execute.scala 60:22]
  wire [4:0] amoAlu_io_amoOp; // @[Execute.scala 60:22]
  wire [31:0] amoAlu_io_result; // @[Execute.scala 60:22]
  wire [4:0] ForwardingUnit_io_ex_reg_rd; // @[Execute.scala 66:18]
  wire [4:0] ForwardingUnit_io_mem_reg_rd; // @[Execute.scala 66:18]
  wire [4:0] ForwardingUnit_io_reg_rs1; // @[Execute.scala 66:18]
  wire [4:0] ForwardingUnit_io_reg_rs2; // @[Execute.scala 66:18]
  wire  ForwardingUnit_io_ex_regWrite_0; // @[Execute.scala 66:18]
  wire  ForwardingUnit_io_mem_regWrite_0; // @[Execute.scala 66:18]
  wire [1:0] ForwardingUnit_io_forwardA; // @[Execute.scala 66:18]
  wire [1:0] ForwardingUnit_io_forwardB; // @[Execute.scala 66:18]
  wire  mdu_clock; // @[Execute.scala 132:32]
  wire  mdu_reset; // @[Execute.scala 132:32]
  wire [31:0] mdu_io_src_a; // @[Execute.scala 132:32]
  wire [31:0] mdu_io_src_b; // @[Execute.scala 132:32]
  wire [4:0] mdu_io_op; // @[Execute.scala 132:32]
  wire  mdu_io_valid; // @[Execute.scala 132:32]
  wire  mdu_io_ready; // @[Execute.scala 132:32]
  wire  mdu_io_output_valid; // @[Execute.scala 132:32]
  wire [31:0] mdu_io_output_bits; // @[Execute.scala 132:32]
  wire  _inputMux1_T = ForwardingUnit_io_forwardA == 2'h0; // @[Execute.scala 84:20]
  wire  _inputMux1_T_1 = ForwardingUnit_io_forwardA == 2'h1; // @[Execute.scala 85:20]
  wire  _inputMux1_T_2 = ForwardingUnit_io_forwardA == 2'h2; // @[Execute.scala 86:20]
  wire [31:0] _inputMux1_T_3 = _inputMux1_T_2 ? io_wb_result : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _inputMux1_T_4 = _inputMux1_T_1 ? io_mem_result : _inputMux1_T_3; // @[Mux.scala 101:16]
  wire [31:0] inputMux1 = _inputMux1_T ? io_readData1 : _inputMux1_T_4; // @[Mux.scala 101:16]
  wire  _inputMux2_T = ForwardingUnit_io_forwardB == 2'h0; // @[Execute.scala 92:20]
  wire  _inputMux2_T_1 = ForwardingUnit_io_forwardB == 2'h1; // @[Execute.scala 93:20]
  wire  _inputMux2_T_2 = ForwardingUnit_io_forwardB == 2'h2; // @[Execute.scala 94:20]
  wire [31:0] _inputMux2_T_3 = _inputMux2_T_2 ? io_wb_result : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _inputMux2_T_4 = _inputMux2_T_1 ? io_mem_result : _inputMux2_T_3; // @[Mux.scala 101:16]
  wire [31:0] inputMux2 = _inputMux2_T ? io_readData2 : _inputMux2_T_4; // @[Mux.scala 101:16]
  wire  _aluIn1_T_1 = io_isAMO | io_isLR | io_isSC; // @[Execute.scala 109:28]
  wire  _aluIn1_T_2 = io_ctl_aluSrc1 == 2'h1; // @[Execute.scala 110:23]
  wire  _aluIn1_T_3 = io_ctl_aluSrc1 == 2'h2; // @[Execute.scala 111:23]
  wire [31:0] _aluIn1_T_4 = _aluIn1_T_3 ? 32'h0 : inputMux1; // @[Mux.scala 101:16]
  wire [31:0] _aluIn1_T_5 = _aluIn1_T_2 ? io_pcAddress : _aluIn1_T_4; // @[Mux.scala 101:16]
  wire [31:0] aluIn1 = _aluIn1_T_1 ? inputMux1 : _aluIn1_T_5; // @[Mux.scala 101:16]
  wire [31:0] _aluIn2_T_2 = io_ctl_aluSrc ? inputMux2 : io_immediate; // @[Execute.scala 120:8]
  wire [31:0] aluIn2 = _aluIn1_T_1 ? 32'h0 : _aluIn2_T_2; // @[Execute.scala 117:19]
  reg [31:0] src_a_reg; // @[Execute.scala 133:38]
  reg [31:0] src_b_reg; // @[Execute.scala 134:38]
  reg [2:0] op_reg; // @[Execute.scala 135:38]
  reg  div_en; // @[Execute.scala 136:38]
  reg [5:0] f7_reg; // @[Execute.scala 137:38]
  reg [5:0] counter; // @[Execute.scala 138:38]
  wire  _T_4 = io_func7 == 7'h1; // @[Execute.scala 144:19]
  wire  _T_12 = io_func7 == 7'h1 & (io_func3 == 3'h0 | io_func3 == 3'h1 | io_func3 == 3'h2 | io_func3 == 3'h3); // @[Execute.scala 144:27]
  wire  _T_23 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7); // @[Execute.scala 150:42]
  wire  _GEN_1 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7) | _T_12; // @[Execute.scala 150:124 151:24]
  wire  _GEN_2 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7) | div_en; // @[Execute.scala 150:124 152:18 136:38]
  wire [6:0] _GEN_6 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7) ?
    io_func7 : {{1'd0}, f7_reg}; // @[Execute.scala 150:124 156:18 137:38]
  wire  _T_24 = counter < 6'h20; // @[Execute.scala 161:25]
  wire [5:0] _counter_T_1 = counter + 6'h1; // @[Execute.scala 165:36]
  wire  _GEN_11 = counter < 6'h20 & _GEN_1; // @[Execute.scala 161:32 167:26]
  wire  _GEN_12 = counter < 6'h20 & _GEN_2; // @[Execute.scala 161:32 168:26]
  wire [2:0] _GEN_15 = div_en ? op_reg : io_func3; // @[Execute.scala 160:21 142:22]
  wire  _io_ALUresult_T_2 = div_en & f7_reg == 6'h1 & mdu_io_ready; // @[Execute.scala 254:41]
  wire [31:0] _io_ALUresult_T_3 = mdu_io_output_valid ? mdu_io_output_bits : 32'h0; // @[Execute.scala 254:68]
  wire  _io_ALUresult_T_5 = _T_4 & mdu_io_ready; // @[Execute.scala 255:25]
  wire [31:0] _io_ALUresult_T_7 = _io_ALUresult_T_5 ? _io_ALUresult_T_3 : alu_io_result; // @[Mux.scala 101:16]
  wire [6:0] _GEN_19 = reset ? 7'h0 : _GEN_6; // @[Execute.scala 137:{38,38}]
  ALU alu ( // @[Execute.scala 57:19]
    .io_input1(alu_io_input1),
    .io_input2(alu_io_input2),
    .io_aluCtl(alu_io_aluCtl),
    .io_result(alu_io_result)
  );
  AluControl aluCtl ( // @[Execute.scala 58:22]
    .io_aluOp(aluCtl_io_aluOp),
    .io_f7(aluCtl_io_f7),
    .io_f3(aluCtl_io_f3),
    .io_aluSrc(aluCtl_io_aluSrc),
    .io_out(aluCtl_io_out)
  );
  AMOALU amoAlu ( // @[Execute.scala 60:22]
    .io_memData(amoAlu_io_memData),
    .io_src2(amoAlu_io_src2),
    .io_amoOp(amoAlu_io_amoOp),
    .io_result(amoAlu_io_result)
  );
  ForwardingUnit ForwardingUnit ( // @[Execute.scala 66:18]
    .io_ex_reg_rd(ForwardingUnit_io_ex_reg_rd),
    .io_mem_reg_rd(ForwardingUnit_io_mem_reg_rd),
    .io_reg_rs1(ForwardingUnit_io_reg_rs1),
    .io_reg_rs2(ForwardingUnit_io_reg_rs2),
    .io_ex_regWrite_0(ForwardingUnit_io_ex_regWrite_0),
    .io_mem_regWrite_0(ForwardingUnit_io_mem_regWrite_0),
    .io_forwardA(ForwardingUnit_io_forwardA),
    .io_forwardB(ForwardingUnit_io_forwardB)
  );
  MDU mdu ( // @[Execute.scala 132:32]
    .clock(mdu_clock),
    .reset(mdu_reset),
    .io_src_a(mdu_io_src_a),
    .io_src_b(mdu_io_src_b),
    .io_op(mdu_io_op),
    .io_valid(mdu_io_valid),
    .io_ready(mdu_io_ready),
    .io_output_valid(mdu_io_output_valid),
    .io_output_bits(mdu_io_output_bits)
  );
  assign io_writeData = _inputMux2_T ? io_readData2 : _inputMux2_T_4; // @[Mux.scala 101:16]
  assign io_ALUresult = _io_ALUresult_T_2 ? _io_ALUresult_T_3 : _io_ALUresult_T_7; // @[Mux.scala 101:16]
  assign io_stall = _T_23 | div_en & _T_24; // @[Execute.scala 267:7]
  assign io_amo_result = amoAlu_io_result; // @[Execute.scala 64:17]
  assign alu_io_input1 = _aluIn1_T_1 ? inputMux1 : _aluIn1_T_5; // @[Mux.scala 101:16]
  assign alu_io_input2 = _aluIn1_T_1 ? 32'h0 : _aluIn2_T_2; // @[Execute.scala 117:19]
  assign alu_io_aluCtl = aluCtl_io_out; // @[Execute.scala 130:17]
  assign aluCtl_io_aluOp = io_ctl_aluOp; // @[Execute.scala 125:19]
  assign aluCtl_io_f7 = io_func7[5]; // @[Execute.scala 124:27]
  assign aluCtl_io_f3 = io_func3; // @[Execute.scala 123:16]
  assign aluCtl_io_aluSrc = io_ctl_aluSrc; // @[Execute.scala 126:20]
  assign amoAlu_io_memData = io_amo_memData; // @[Execute.scala 61:21]
  assign amoAlu_io_src2 = io_amo_src2; // @[Execute.scala 62:18]
  assign amoAlu_io_amoOp = io_amo_op_code; // @[Execute.scala 63:19]
  assign ForwardingUnit_io_ex_reg_rd = io_ex_mem_ins[11:7]; // @[Execute.scala 72:32]
  assign ForwardingUnit_io_mem_reg_rd = io_mem_wb_ins[11:7]; // @[Execute.scala 73:33]
  assign ForwardingUnit_io_reg_rs1 = io_id_ex_ins[19:15]; // @[Execute.scala 74:29]
  assign ForwardingUnit_io_reg_rs2 = io_id_ex_ins[24:20]; // @[Execute.scala 75:29]
  assign ForwardingUnit_io_ex_regWrite_0 = io_ex_mem_regWrite_0; // @[Execute.scala 70:18]
  assign ForwardingUnit_io_mem_regWrite_0 = io_mem_wb_regWrite_0; // @[Execute.scala 71:19]
  assign mdu_clock = clock;
  assign mdu_reset = reset;
  assign mdu_io_src_a = div_en ? src_a_reg : aluIn1; // @[Execute.scala 160:21 140:22]
  assign mdu_io_src_b = div_en ? src_b_reg : aluIn2; // @[Execute.scala 160:21 141:22]
  assign mdu_io_op = {{2'd0}, _GEN_15};
  assign mdu_io_valid = div_en ? _GEN_11 : _GEN_1; // @[Execute.scala 160:21]
  always @(posedge clock) begin
    if (reset) begin // @[Execute.scala 133:38]
      src_a_reg <= 32'h0; // @[Execute.scala 133:38]
    end else if (_T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7)) begin // @[Execute.scala 150:124]
      if (_aluIn1_T_1) begin // @[Mux.scala 101:16]
        if (_inputMux1_T) begin // @[Mux.scala 101:16]
          src_a_reg <= io_readData1;
        end else begin
          src_a_reg <= _inputMux1_T_4;
        end
      end else if (_aluIn1_T_2) begin // @[Mux.scala 101:16]
        src_a_reg <= io_pcAddress;
      end else begin
        src_a_reg <= _aluIn1_T_4;
      end
    end
    if (reset) begin // @[Execute.scala 134:38]
      src_b_reg <= 32'h0; // @[Execute.scala 134:38]
    end else if (_T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7)) begin // @[Execute.scala 150:124]
      if (_aluIn1_T_1) begin // @[Execute.scala 117:19]
        src_b_reg <= 32'h0;
      end else if (io_ctl_aluSrc) begin // @[Execute.scala 120:8]
        src_b_reg <= inputMux2;
      end else begin
        src_b_reg <= io_immediate;
      end
    end
    if (reset) begin // @[Execute.scala 135:38]
      op_reg <= 3'h0; // @[Execute.scala 135:38]
    end else if (_T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7)) begin // @[Execute.scala 150:124]
      op_reg <= io_func3; // @[Execute.scala 155:18]
    end
    if (reset) begin // @[Execute.scala 136:38]
      div_en <= 1'h0; // @[Execute.scala 136:38]
    end else if (div_en) begin // @[Execute.scala 160:21]
      div_en <= _GEN_12;
    end else begin
      div_en <= _GEN_2;
    end
    f7_reg <= _GEN_19[5:0]; // @[Execute.scala 137:{38,38}]
    if (reset) begin // @[Execute.scala 138:38]
      counter <= 6'h0; // @[Execute.scala 138:38]
    end else if (div_en) begin // @[Execute.scala 160:21]
      if (counter < 6'h20) begin // @[Execute.scala 161:32]
        counter <= _counter_T_1; // @[Execute.scala 165:21]
      end else begin
        counter <= 6'h0; // @[Execute.scala 172:21]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  src_a_reg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  src_b_reg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  op_reg = _RAND_2[2:0];
  _RAND_3 = {1{`RANDOM}};
  div_en = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  f7_reg = _RAND_4[5:0];
  _RAND_5 = {1{`RANDOM}};
  counter = _RAND_5[5:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module MemoryFetch(
  input         clock,
  input         reset,
  input  [31:0] io_aluResultIn,
  input  [31:0] io_writeData,
  input         io_writeEnable,
  input         io_readEnable,
  output [31:0] io_readData,
  output        io_stall,
  input  [2:0]  io_f3,
  input         io_isAMO,
  input         io_isLR,
  input         io_isSC,
  input         io_dccmReq_ready,
  output        io_dccmReq_valid,
  output [31:0] io_dccmReq_bits_addrRequest,
  output [31:0] io_dccmReq_bits_dataRequest,
  output [3:0]  io_dccmReq_bits_activeByteLane,
  output        io_dccmReq_bits_isWrite,
  input         io_dccmRsp_valid,
  input  [31:0] io_dccmRsp_bits_dataResponse,
  input  [31:0] io_amo_alu_result_in
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [1:0] offset; // @[MemoryFetch.scala 37:23]
  reg [2:0] funct3; // @[MemoryFetch.scala 38:23]
  wire [1:0] offsetSW = io_aluResultIn[1:0]; // @[MemoryFetch.scala 39:32]
  wire  _T = ~io_dccmRsp_valid; // @[MemoryFetch.scala 41:8]
  wire  _T_3 = ~io_isAMO; // @[MemoryFetch.scala 55:48]
  wire  _T_5 = ~io_isSC; // @[MemoryFetch.scala 55:61]
  wire  _T_7 = offsetSW == 2'h0; // @[MemoryFetch.scala 56:19]
  wire  _T_8 = offsetSW == 2'h1; // @[MemoryFetch.scala 59:25]
  wire [7:0] _GEN_2 = offsetSW == 2'h2 ? io_writeData[15:8] : io_writeData[15:8]; // @[MemoryFetch.scala 66:33 67:16 74:16]
  wire [7:0] _GEN_3 = offsetSW == 2'h2 ? io_writeData[23:16] : io_writeData[23:16]; // @[MemoryFetch.scala 66:33 68:16 75:16]
  wire [7:0] _GEN_4 = offsetSW == 2'h2 ? io_writeData[7:0] : io_writeData[31:24]; // @[MemoryFetch.scala 66:33 69:16 76:16]
  wire [7:0] _GEN_5 = offsetSW == 2'h2 ? io_writeData[31:24] : io_writeData[7:0]; // @[MemoryFetch.scala 66:33 70:16 77:16]
  wire [3:0] _GEN_6 = offsetSW == 2'h2 ? 4'h4 : 4'h8; // @[MemoryFetch.scala 66:33 71:38 78:38]
  wire [7:0] _GEN_7 = offsetSW == 2'h1 ? io_writeData[15:8] : _GEN_2; // @[MemoryFetch.scala 59:33 60:16]
  wire [7:0] _GEN_8 = offsetSW == 2'h1 ? io_writeData[7:0] : _GEN_3; // @[MemoryFetch.scala 59:33 61:16]
  wire [7:0] _GEN_9 = offsetSW == 2'h1 ? io_writeData[23:16] : _GEN_4; // @[MemoryFetch.scala 59:33 62:16]
  wire [7:0] _GEN_10 = offsetSW == 2'h1 ? io_writeData[31:24] : _GEN_5; // @[MemoryFetch.scala 59:33 63:16]
  wire [3:0] _GEN_11 = offsetSW == 2'h1 ? 4'h2 : _GEN_6; // @[MemoryFetch.scala 59:33 64:38]
  wire [3:0] _GEN_12 = offsetSW == 2'h0 ? 4'h1 : _GEN_11; // @[MemoryFetch.scala 56:27 57:38]
  wire [7:0] _GEN_13 = offsetSW == 2'h0 ? io_writeData[7:0] : _GEN_7; // @[MemoryFetch.scala 49:12 56:27]
  wire [7:0] _GEN_14 = offsetSW == 2'h0 ? io_writeData[15:8] : _GEN_8; // @[MemoryFetch.scala 50:12 56:27]
  wire [7:0] _GEN_15 = offsetSW == 2'h0 ? io_writeData[23:16] : _GEN_9; // @[MemoryFetch.scala 51:12 56:27]
  wire [7:0] _GEN_16 = offsetSW == 2'h0 ? io_writeData[31:24] : _GEN_10; // @[MemoryFetch.scala 52:12 56:27]
  wire [3:0] _GEN_17 = _T_8 ? 4'h6 : 4'hc; // @[MemoryFetch.scala 87:33 88:38 95:38]
  wire [7:0] _GEN_18 = _T_8 ? io_writeData[23:16] : io_writeData[23:16]; // @[MemoryFetch.scala 87:33 90:16 99:16]
  wire [7:0] _GEN_19 = _T_8 ? io_writeData[7:0] : io_writeData[31:24]; // @[MemoryFetch.scala 100:16 87:33 91:16]
  wire [7:0] _GEN_20 = _T_8 ? io_writeData[15:8] : io_writeData[7:0]; // @[MemoryFetch.scala 87:33 92:16 97:16]
  wire [7:0] _GEN_21 = _T_8 ? io_writeData[31:24] : io_writeData[15:8]; // @[MemoryFetch.scala 87:33 93:16 98:16]
  wire [3:0] _GEN_22 = _T_7 ? 4'h3 : _GEN_17; // @[MemoryFetch.scala 84:27 85:38]
  wire [7:0] _GEN_23 = _T_7 ? io_writeData[7:0] : _GEN_18; // @[MemoryFetch.scala 49:12 84:27]
  wire [7:0] _GEN_24 = _T_7 ? io_writeData[15:8] : _GEN_19; // @[MemoryFetch.scala 50:12 84:27]
  wire [7:0] _GEN_25 = _T_7 ? io_writeData[23:16] : _GEN_20; // @[MemoryFetch.scala 51:12 84:27]
  wire [7:0] _GEN_26 = _T_7 ? io_writeData[31:24] : _GEN_21; // @[MemoryFetch.scala 52:12 84:27]
  wire [3:0] _GEN_27 = io_writeEnable & io_f3 == 3'h1 & _T_3 & _T_5 ? _GEN_22 : 4'hf; // @[MemoryFetch.scala 105:36 83:75]
  wire [7:0] _GEN_28 = io_writeEnable & io_f3 == 3'h1 & _T_3 & _T_5 ? _GEN_23 : io_writeData[7:0]; // @[MemoryFetch.scala 49:12 83:75]
  wire [7:0] _GEN_29 = io_writeEnable & io_f3 == 3'h1 & _T_3 & _T_5 ? _GEN_24 : io_writeData[15:8]; // @[MemoryFetch.scala 50:12 83:75]
  wire [7:0] _GEN_30 = io_writeEnable & io_f3 == 3'h1 & _T_3 & _T_5 ? _GEN_25 : io_writeData[23:16]; // @[MemoryFetch.scala 51:12 83:75]
  wire [7:0] _GEN_31 = io_writeEnable & io_f3 == 3'h1 & _T_3 & _T_5 ? _GEN_26 : io_writeData[31:24]; // @[MemoryFetch.scala 52:12 83:75]
  wire [7:0] wdata_0 = io_writeEnable & io_f3 == 3'h0 & ~io_isAMO & ~io_isSC ? _GEN_13 : _GEN_28; // @[MemoryFetch.scala 55:70]
  wire [7:0] wdata_1 = io_writeEnable & io_f3 == 3'h0 & ~io_isAMO & ~io_isSC ? _GEN_14 : _GEN_29; // @[MemoryFetch.scala 55:70]
  wire [7:0] wdata_2 = io_writeEnable & io_f3 == 3'h0 & ~io_isAMO & ~io_isSC ? _GEN_15 : _GEN_30; // @[MemoryFetch.scala 55:70]
  wire [7:0] wdata_3 = io_writeEnable & io_f3 == 3'h0 & ~io_isAMO & ~io_isSC ? _GEN_16 : _GEN_31; // @[MemoryFetch.scala 55:70]
  wire [31:0] rdata = io_dccmRsp_valid ? io_dccmRsp_bits_dataResponse : 32'h0; // @[MemoryFetch.scala 135:15]
  wire [31:0] _writeDataFinal_T_1 = {wdata_3,wdata_2,wdata_1,wdata_0}; // @[MemoryFetch.scala 118:84]
  wire  amo_transition_stall = io_isAMO & io_readEnable & io_dccmRsp_valid; // @[MemoryFetch.scala 131:56]
  wire  _T_24 = offset == 2'h0; // @[MemoryFetch.scala 144:19]
  wire [23:0] _io_readData_T_2 = rdata[7] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_4 = {_io_readData_T_2,rdata[7:0]}; // @[Cat.scala 33:92]
  wire  _T_25 = offset == 2'h1; // @[MemoryFetch.scala 146:26]
  wire [23:0] _io_readData_T_7 = rdata[15] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_9 = {_io_readData_T_7,rdata[15:8]}; // @[Cat.scala 33:92]
  wire  _T_26 = offset == 2'h2; // @[MemoryFetch.scala 148:26]
  wire [23:0] _io_readData_T_12 = rdata[23] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_14 = {_io_readData_T_12,rdata[23:16]}; // @[Cat.scala 33:92]
  wire [23:0] _io_readData_T_17 = rdata[31] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_19 = {_io_readData_T_17,rdata[31:24]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_39 = offset == 2'h2 ? _io_readData_T_14 : _io_readData_T_19; // @[MemoryFetch.scala 148:39 149:21]
  wire [31:0] _GEN_40 = offset == 2'h1 ? _io_readData_T_9 : _GEN_39; // @[MemoryFetch.scala 146:39 147:21]
  wire [31:0] _GEN_41 = offset == 2'h0 ? _io_readData_T_4 : _GEN_40; // @[MemoryFetch.scala 144:32 145:21]
  wire [31:0] _io_readData_T_22 = {24'h0,rdata[7:0]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_25 = {24'h0,rdata[15:8]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_28 = {24'h0,rdata[23:16]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_31 = {24'h0,rdata[31:24]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_43 = _T_26 ? _io_readData_T_28 : _io_readData_T_31; // @[MemoryFetch.scala 162:38 163:21]
  wire [31:0] _GEN_44 = _T_25 ? _io_readData_T_25 : _GEN_43; // @[MemoryFetch.scala 160:38 161:21]
  wire [31:0] _GEN_45 = _T_24 ? _io_readData_T_22 : _GEN_44; // @[MemoryFetch.scala 158:32 159:21]
  wire [31:0] _io_readData_T_34 = {16'h0,rdata[15:0]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_37 = {16'h0,rdata[23:8]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_40 = {16'h0,rdata[31:16]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_47 = _T_25 ? _io_readData_T_37 : _io_readData_T_40; // @[MemoryFetch.scala 174:39 175:21]
  wire [31:0] _GEN_48 = _T_24 ? _io_readData_T_34 : _GEN_47; // @[MemoryFetch.scala 172:32 173:21]
  wire [15:0] _io_readData_T_43 = rdata[15] ? 16'hffff : 16'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_45 = {_io_readData_T_43,rdata[15:0]}; // @[Cat.scala 33:92]
  wire [15:0] _io_readData_T_48 = rdata[23] ? 16'hffff : 16'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_50 = {_io_readData_T_48,rdata[23:8]}; // @[Cat.scala 33:92]
  wire [15:0] _io_readData_T_53 = rdata[31] ? 16'hffff : 16'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_55 = {_io_readData_T_53,rdata[31:16]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_50 = _T_25 ? _io_readData_T_50 : _io_readData_T_55; // @[MemoryFetch.scala 186:39 187:21]
  wire [31:0] _GEN_51 = _T_24 ? _io_readData_T_45 : _GEN_50; // @[MemoryFetch.scala 184:32 185:21]
  wire [31:0] _GEN_53 = funct3 == 3'h5 ? _GEN_48 : _GEN_51; // @[MemoryFetch.scala 170:36]
  wire [31:0] _GEN_54 = funct3 == 3'h4 ? _GEN_45 : _GEN_53; // @[MemoryFetch.scala 156:36]
  wire [31:0] _GEN_55 = funct3 == 3'h0 ? _GEN_41 : _GEN_54; // @[MemoryFetch.scala 142:36]
  assign io_readData = funct3 == 3'h2 | io_isAMO | io_isLR ? rdata : _GEN_55; // @[MemoryFetch.scala 138:54 140:19]
  assign io_stall = io_writeEnable & ~io_dccmReq_ready | io_readEnable & _T | amo_transition_stall; // @[MemoryFetch.scala 133:95]
  assign io_dccmReq_valid = io_writeEnable | io_readEnable; // @[MemoryFetch.scala 123:42]
  assign io_dccmReq_bits_addrRequest = io_aluResultIn; // @[MemoryFetch.scala 121:31]
  assign io_dccmReq_bits_dataRequest = io_isAMO & io_writeEnable ? io_amo_alu_result_in : _writeDataFinal_T_1; // @[MemoryFetch.scala 118:27]
  assign io_dccmReq_bits_activeByteLane = io_writeEnable & io_f3 == 3'h0 & ~io_isAMO & ~io_isSC ? _GEN_12 : _GEN_27; // @[MemoryFetch.scala 55:70]
  assign io_dccmReq_bits_isWrite = io_writeEnable; // @[MemoryFetch.scala 122:27]
  always @(posedge clock) begin
    if (reset) begin // @[MemoryFetch.scala 37:23]
      offset <= 2'h0; // @[MemoryFetch.scala 37:23]
    end else if (~io_dccmRsp_valid) begin // @[MemoryFetch.scala 41:26]
      offset <= offsetSW; // @[MemoryFetch.scala 43:12]
    end
    if (reset) begin // @[MemoryFetch.scala 38:23]
      funct3 <= 3'h0; // @[MemoryFetch.scala 38:23]
    end else if (~io_dccmRsp_valid) begin // @[MemoryFetch.scala 41:26]
      funct3 <= io_f3; // @[MemoryFetch.scala 42:12]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  offset = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  funct3 = _RAND_1[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module ReservationFile(
  input         clock,
  input         reset,
  input         io_set,
  input         io_clear,
  input  [31:0] io_addrIn,
  output        io_matchAddr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg  reservedValid; // @[reservationFile.scala 20:30]
  reg [31:0] reservedAddr; // @[reservationFile.scala 21:26]
  wire  _GEN_1 = io_set | reservedValid; // @[reservationFile.scala 26:16 28:19 20:30]
  assign io_matchAddr = reservedValid & reservedAddr == io_addrIn; // @[reservationFile.scala 36:22]
  always @(posedge clock) begin
    if (reset) begin // @[reservationFile.scala 20:30]
      reservedValid <= 1'h0; // @[reservationFile.scala 20:30]
    end else if (io_clear) begin // @[reservationFile.scala 31:18]
      reservedValid <= 1'h0; // @[reservationFile.scala 32:19]
    end else begin
      reservedValid <= _GEN_1;
    end
    if (io_set) begin // @[reservationFile.scala 26:16]
      reservedAddr <= io_addrIn; // @[reservationFile.scala 27:19]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  reservedValid = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  reservedAddr = _RAND_1[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module PC(
  input         clock,
  input         reset,
  input  [31:0] io_in,
  input         io_halt,
  output [31:0] io_out,
  output [31:0] io_pc4,
  output [31:0] io_pc2
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] pc_reg; // @[PC.scala 13:23]
  wire [31:0] _io_pc4_T_2 = $signed(pc_reg) + 32'sh4; // @[PC.scala 16:41]
  wire [31:0] _io_pc2_T_2 = $signed(pc_reg) + 32'sh2; // @[PC.scala 17:41]
  assign io_out = pc_reg; // @[PC.scala 15:10]
  assign io_pc4 = io_halt ? $signed(pc_reg) : $signed(_io_pc4_T_2); // @[PC.scala 16:16]
  assign io_pc2 = io_halt ? $signed(pc_reg) : $signed(_io_pc2_T_2); // @[PC.scala 17:16]
  always @(posedge clock) begin
    if (reset) begin // @[PC.scala 13:23]
      pc_reg <= -32'sh4; // @[PC.scala 13:23]
    end else begin
      pc_reg <= io_in; // @[PC.scala 14:10]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  pc_reg = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Realigner(
  input         clock,
  input         reset,
  input  [31:0] io_ral_address_i,
  input  [31:0] io_ral_instruction_i,
  input         io_ral_jmp,
  input         io_stall,
  output [31:0] io_ral_instruction_o,
  output        io_addri,
  output        io_misaligned_word,
  output        io_misaligned_word_uh,
  output        io_nop_sel
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire  addri = io_ral_address_i[1]; // @[Realigner.scala 40:31]
  wire  _uh_is_comp_T_1 = 2'h0 == io_ral_instruction_i[17:16]; // @[Realigner.scala 52:9]
  wire  _uh_is_comp_T_3 = 2'h1 == io_ral_instruction_i[17:16]; // @[Realigner.scala 52:9]
  wire  _uh_is_comp_T_5 = 2'h2 == io_ral_instruction_i[17:16]; // @[Realigner.scala 52:9]
  wire  uh_is_comp = _uh_is_comp_T_1 | _uh_is_comp_T_3 | _uh_is_comp_T_5; // @[Realigner.scala 53:15]
  wire  _uh_is_comp_reg_T = io_ral_instruction_i != 32'h0; // @[Realigner.scala 55:26]
  reg [15:0] lhw_reg; // @[Realigner.scala 61:24]
  reg  stateReg; // @[Realigner.scala 81:25]
  wire  _nop_sel_T = ~stateReg; // @[Realigner.scala 106:38]
  wire  _nop_sel_T_2 = ~uh_is_comp; // @[Realigner.scala 106:62]
  wire  nop_sel = ~stateReg & addri & ~uh_is_comp & _uh_is_comp_reg_T; // @[Realigner.scala 106:88]
  wire [31:0] conc_instr = {io_ral_instruction_i[15:0],lhw_reg}; // @[Cat.scala 33:92]
  wire  _io_ral_instruction_o_T_1 = addri & _nop_sel_T_2; // @[Realigner.scala 69:12]
  wire  conc_sel = stateReg & _uh_is_comp_reg_T; // @[Realigner.scala 107:50]
  wire [31:0] _io_ral_instruction_o_T_2 = conc_sel ? conc_instr : io_ral_instruction_i; // @[Mux.scala 101:16]
  assign io_ral_instruction_o = _io_ral_instruction_o_T_1 ? 32'h13 : _io_ral_instruction_o_T_2; // @[Mux.scala 101:16]
  assign io_addri = io_ral_address_i[1]; // @[Realigner.scala 40:31]
  assign io_misaligned_word = stateReg & _uh_is_comp_reg_T; // @[Realigner.scala 107:50]
  assign io_misaligned_word_uh = stateReg; // @[Realigner.scala 108:38]
  assign io_nop_sel = ~stateReg & addri & ~uh_is_comp & _uh_is_comp_reg_T; // @[Realigner.scala 106:88]
  always @(posedge clock) begin
    if (reset) begin // @[Realigner.scala 61:24]
      lhw_reg <= 16'h0; // @[Realigner.scala 61:24]
    end else if (nop_sel) begin // @[Realigner.scala 63:17]
      lhw_reg <= io_ral_instruction_i[31:16];
    end
    if (reset) begin // @[Realigner.scala 81:25]
      stateReg <= 1'h0; // @[Realigner.scala 81:25]
    end else if (_nop_sel_T) begin // @[Realigner.scala 84:19]
      if (io_stall) begin // @[Realigner.scala 86:23]
        stateReg <= 1'h0; // @[Realigner.scala 87:18]
      end else if (io_ral_jmp) begin // @[Realigner.scala 88:31]
        stateReg <= 1'h0; // @[Realigner.scala 89:18]
      end else begin
        stateReg <= _io_ral_instruction_o_T_1;
      end
    end else if (stateReg) begin // @[Realigner.scala 84:19]
      stateReg <= io_stall;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  lhw_reg = _RAND_0[15:0];
  _RAND_1 = {1{`RANDOM}};
  stateReg = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module CompressedDecoder(
  input  [31:0] io_instruction_i,
  input         io_addri,
  output        io_is_comp,
  output [31:0] io_instruction_o
);
  wire [31:0] instruction_i = io_addri ? {{16'd0}, io_instruction_i[31:16]} : io_instruction_i; // @[CompressedDecoder.scala 35:23]
  wire  _T_3 = 2'h0 == instruction_i[15:14]; // @[CompressedDecoder.scala 47:38]
  wire [31:0] _io_instruction_o_T_5 = {2'h0,instruction_i[10:7],instruction_i[12:11],instruction_i[5],instruction_i[6],2'h0
    ,10'h41,instruction_i[4:2],7'h13}; // @[Cat.scala 33:92]
  wire  _T_4 = 2'h1 == instruction_i[15:14]; // @[CompressedDecoder.scala 47:38]
  wire [31:0] _io_instruction_o_T_12 = {5'h0,instruction_i[5],instruction_i[12:10],instruction_i[6],4'h1,instruction_i[9
    :7],3'h2,2'h1,instruction_i[4:2],7'h3}; // @[Cat.scala 33:92]
  wire  _T_5 = 2'h3 == instruction_i[15:14]; // @[CompressedDecoder.scala 47:38]
  wire [17:0] io_instruction_o_lo_2 = {instruction_i[9:7],3'h2,instruction_i[11:10],instruction_i[6],2'h0,7'h23}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_20 = {5'h0,instruction_i[5],instruction_i[12],2'h1,instruction_i[4:2],2'h1,
    io_instruction_o_lo_2}; // @[Cat.scala 33:92]
  wire  _T_6 = 2'h2 == instruction_i[15:14]; // @[CompressedDecoder.scala 47:38]
  wire [31:0] _GEN_3 = 2'h3 == instruction_i[15:14] ? _io_instruction_o_T_20 : instruction_i; // @[CompressedDecoder.scala 47:38 66:28]
  wire  _GEN_4 = 2'h1 == instruction_i[15:14] | 2'h3 == instruction_i[15:14]; // @[CompressedDecoder.scala 47:38 58:22]
  wire [31:0] _GEN_5 = 2'h1 == instruction_i[15:14] ? _io_instruction_o_T_12 : _GEN_3; // @[CompressedDecoder.scala 47:38 59:28]
  wire  _GEN_6 = 2'h0 == instruction_i[15:14] | _GEN_4; // @[CompressedDecoder.scala 47:38 51:22]
  wire [31:0] _GEN_7 = 2'h0 == instruction_i[15:14] ? _io_instruction_o_T_5 : _GEN_5; // @[CompressedDecoder.scala 47:38 52:28]
  wire [5:0] _io_instruction_o_T_23 = instruction_i[12] ? 6'h3f : 6'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_instruction_o_T_28 = {_io_instruction_o_T_23,instruction_i[12],instruction_i[6:2],instruction_i[11:7],3'h0
    ,instruction_i[11:7],7'h13}; // @[Cat.scala 33:92]
  wire [19:0] _c_jal_imm_T_2 = instruction_i[12] ? 20'hfffff : 20'h0; // @[Bitwise.scala 77:12]
  wire [31:0] c_jal_imm = {_c_jal_imm_T_2,instruction_i[12],instruction_i[8],instruction_i[10:9],instruction_i[6],
    instruction_i[7],instruction_i[2],instruction_i[11],instruction_i[5:3],1'h0}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_33 = {c_jal_imm[20],c_jal_imm[10:1],c_jal_imm[11],c_jal_imm[19:12],5'h1,7'h6f}; // @[Cat.scala 33:92]
  wire [8:0] _io_instruction_o_T_44 = instruction_i[12] ? 9'h1ff : 9'h0; // @[Bitwise.scala 77:12]
  wire  _io_instruction_o_T_46 = ~instruction_i[15]; // @[CompressedDecoder.scala 128:79]
  wire [24:0] io_instruction_o_lo_5 = {instruction_i[11],instruction_i[5:3],_io_instruction_o_T_44,4'h0,
    _io_instruction_o_T_46,7'h6f}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_47 = {instruction_i[12],instruction_i[8],instruction_i[10:9],instruction_i[6],
    instruction_i[7],instruction_i[2],io_instruction_o_lo_5}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_54 = {_io_instruction_o_T_23,instruction_i[12],instruction_i[6:2],5'h0,3'h0,
    instruction_i[11:7],7'h13}; // @[Cat.scala 33:92]
  wire [14:0] _io_instruction_o_T_57 = instruction_i[12] ? 15'h7fff : 15'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_instruction_o_T_60 = {_io_instruction_o_T_57,instruction_i[6:2],instruction_i[11:7],7'h37}; // @[Cat.scala 33:92]
  wire [2:0] _io_instruction_o_T_63 = instruction_i[12] ? 3'h7 : 3'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_instruction_o_T_68 = {_io_instruction_o_T_63,instruction_i[4:3],instruction_i[5],instruction_i[2],
    instruction_i[6],24'h10113}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_8 = instruction_i[11:7] == 5'h2 ? _io_instruction_o_T_68 : _io_instruction_o_T_60; // @[CompressedDecoder.scala 143:28 145:59 147:31]
  wire [31:0] _io_instruction_o_T_73 = {1'h0,instruction_i[10],5'h0,instruction_i[6:2],2'h1,instruction_i[9:7],3'h5,2'h1
    ,instruction_i[9:7],7'h13}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_86 = {_io_instruction_o_T_23,instruction_i[12],instruction_i[6:2],2'h1,instruction_i[9
    :7],5'h1d,instruction_i[9:7],7'h13}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_90 = {9'h81,instruction_i[4:2],2'h1,instruction_i[9:7],3'h0,2'h1,instruction_i[9:7],7'h33
    }; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_95 = {9'h1,instruction_i[4:2],2'h1,instruction_i[9:7],5'h11,instruction_i[9:7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_100 = {9'h1,instruction_i[4:2],2'h1,instruction_i[9:7],5'h19,instruction_i[9:7],7'h33}
    ; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_105 = {9'h1,instruction_i[4:2],2'h1,instruction_i[9:7],5'h1d,instruction_i[9:7],7'h33}
    ; // @[Cat.scala 33:92]
  wire [31:0] _GEN_10 = 2'h3 == instruction_i[6:5] ? _io_instruction_o_T_105 : instruction_i; // @[CompressedDecoder.scala 179:43 205:36 39:20]
  wire  _GEN_11 = 2'h2 == instruction_i[6:5] | 2'h3 == instruction_i[6:5]; // @[CompressedDecoder.scala 179:43 197:30]
  wire [31:0] _GEN_12 = 2'h2 == instruction_i[6:5] ? _io_instruction_o_T_100 : _GEN_10; // @[CompressedDecoder.scala 179:43 198:36]
  wire  _GEN_13 = 2'h1 == instruction_i[6:5] | _GEN_11; // @[CompressedDecoder.scala 179:43 190:30]
  wire [31:0] _GEN_14 = 2'h1 == instruction_i[6:5] ? _io_instruction_o_T_95 : _GEN_12; // @[CompressedDecoder.scala 179:43 191:36]
  wire  _GEN_15 = 2'h0 == instruction_i[6:5] | _GEN_13; // @[CompressedDecoder.scala 179:43 183:30]
  wire [31:0] _GEN_16 = 2'h0 == instruction_i[6:5] ? _io_instruction_o_T_90 : _GEN_14; // @[CompressedDecoder.scala 179:43 184:36]
  wire  _GEN_17 = 2'h3 == instruction_i[11:10] & _GEN_15; // @[CompressedDecoder.scala 154:41 38:14]
  wire [31:0] _GEN_18 = 2'h3 == instruction_i[11:10] ? _GEN_16 : instruction_i; // @[CompressedDecoder.scala 154:41 39:20]
  wire  _GEN_19 = 2'h2 == instruction_i[11:10] | _GEN_17; // @[CompressedDecoder.scala 154:41 172:26]
  wire [31:0] _GEN_20 = 2'h2 == instruction_i[11:10] ? _io_instruction_o_T_86 : _GEN_18; // @[CompressedDecoder.scala 154:41 173:32]
  wire  _GEN_21 = 2'h1 == instruction_i[11:10] | _GEN_19; // @[CompressedDecoder.scala 154:41 165:26]
  wire [31:0] _GEN_22 = 2'h1 == instruction_i[11:10] ? _io_instruction_o_T_73 : _GEN_20; // @[CompressedDecoder.scala 154:41 166:32]
  wire  _GEN_23 = 2'h0 == instruction_i[11:10] | _GEN_21; // @[CompressedDecoder.scala 154:41 158:26]
  wire [31:0] _GEN_24 = 2'h0 == instruction_i[11:10] ? _io_instruction_o_T_73 : _GEN_22; // @[CompressedDecoder.scala 154:41 159:32]
  wire [3:0] _io_instruction_o_T_108 = instruction_i[12] ? 4'hf : 4'h0; // @[Bitwise.scala 77:12]
  wire [14:0] io_instruction_o_lo_16 = {2'h0,instruction_i[13],instruction_i[11:10],instruction_i[4:3],instruction_i[12]
    ,7'h63}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_117 = {_io_instruction_o_T_108,instruction_i[6:5],instruction_i[2],7'h1,instruction_i[
    9:7],io_instruction_o_lo_16}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_26 = 3'h7 == instruction_i[15:13] ? _io_instruction_o_T_117 : instruction_i; // @[CompressedDecoder.scala 224:28 39:20 85:38]
  wire  _GEN_27 = 3'h6 == instruction_i[15:13] | 3'h7 == instruction_i[15:13]; // @[CompressedDecoder.scala 215:22 85:38]
  wire [31:0] _GEN_28 = 3'h6 == instruction_i[15:13] ? _io_instruction_o_T_117 : _GEN_26; // @[CompressedDecoder.scala 216:28 85:38]
  wire  _GEN_29 = 3'h4 == instruction_i[15:13] ? _GEN_23 : _GEN_27; // @[CompressedDecoder.scala 85:38]
  wire [31:0] _GEN_30 = 3'h4 == instruction_i[15:13] ? _GEN_24 : _GEN_28; // @[CompressedDecoder.scala 85:38]
  wire  _GEN_31 = 3'h3 == instruction_i[15:13] | _GEN_29; // @[CompressedDecoder.scala 142:22 85:38]
  wire [31:0] _GEN_32 = 3'h3 == instruction_i[15:13] ? _GEN_8 : _GEN_30; // @[CompressedDecoder.scala 85:38]
  wire  _GEN_33 = 3'h2 == instruction_i[15:13] | _GEN_31; // @[CompressedDecoder.scala 134:22 85:38]
  wire [31:0] _GEN_34 = 3'h2 == instruction_i[15:13] ? _io_instruction_o_T_54 : _GEN_32; // @[CompressedDecoder.scala 135:28 85:38]
  wire  _GEN_35 = 3'h5 == instruction_i[15:13] | _GEN_33; // @[CompressedDecoder.scala 125:22 85:38]
  wire [31:0] _GEN_36 = 3'h5 == instruction_i[15:13] ? _io_instruction_o_T_47 : _GEN_34; // @[CompressedDecoder.scala 126:28 85:38]
  wire  _GEN_37 = 3'h1 == instruction_i[15:13] | _GEN_35; // @[CompressedDecoder.scala 85:38 97:22]
  wire [31:0] _GEN_38 = 3'h1 == instruction_i[15:13] ? _io_instruction_o_T_33 : _GEN_36; // @[CompressedDecoder.scala 113:28 85:38]
  wire  _GEN_39 = 3'h0 == instruction_i[15:13] | _GEN_37; // @[CompressedDecoder.scala 85:38 90:22]
  wire [31:0] _GEN_40 = 3'h0 == instruction_i[15:13] ? _io_instruction_o_T_28 : _GEN_38; // @[CompressedDecoder.scala 85:38 91:28]
  wire [31:0] _io_instruction_o_T_134 = {7'h0,instruction_i[6:2],instruction_i[11:7],3'h1,instruction_i[11:7],7'h13}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_140 = {4'h0,instruction_i[3:2],instruction_i[12],instruction_i[6:4],2'h0,8'h12,
    instruction_i[11:7],7'h3}; // @[Cat.scala 33:92]
  wire  _T_37 = instruction_i[6:2] != 5'h0; // @[CompressedDecoder.scala 260:37]
  wire [31:0] _io_instruction_o_T_145 = {7'h0,instruction_i[6:2],8'h0,instruction_i[11:7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_149 = {12'h0,instruction_i[11:7],15'h67}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_42 = instruction_i[6:2] != 5'h0 ? _io_instruction_o_T_145 : _io_instruction_o_T_149; // @[CompressedDecoder.scala 260:59 265:32 270:32]
  wire [31:0] _io_instruction_o_T_154 = {7'h0,instruction_i[6:2],instruction_i[11:7],3'h0,instruction_i[11:7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_158 = {12'h0,instruction_i[11:7],7'h0,8'he7}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_44 = instruction_i[11:7] == 5'h0 ? 32'h100073 : _io_instruction_o_T_158; // @[CompressedDecoder.scala 281:62 284:34 288:34]
  wire [31:0] _GEN_46 = _T_37 ? _io_instruction_o_T_154 : _GEN_44; // @[CompressedDecoder.scala 274:59 278:32]
  wire [31:0] _GEN_48 = ~instruction_i[12] ? _GEN_42 : _GEN_46; // @[CompressedDecoder.scala 258:47]
  wire [31:0] _io_instruction_o_T_164 = {4'h0,instruction_i[8:7],instruction_i[12],instruction_i[6:2],5'h2,3'h2,
    instruction_i[11:9],9'h23}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_50 = _T_5 ? _io_instruction_o_T_164 : instruction_i; // @[CompressedDecoder.scala 239:37 297:28 39:20]
  wire [31:0] _GEN_52 = _T_6 ? _GEN_48 : _GEN_50; // @[CompressedDecoder.scala 239:37]
  wire  _GEN_53 = _T_4 | (_T_6 | _T_5); // @[CompressedDecoder.scala 239:37 251:22]
  wire [31:0] _GEN_54 = _T_4 ? _io_instruction_o_T_140 : _GEN_52; // @[CompressedDecoder.scala 239:37 252:28]
  wire  _GEN_55 = _T_3 | _GEN_53; // @[CompressedDecoder.scala 239:37 244:22]
  wire [31:0] _GEN_56 = _T_3 ? _io_instruction_o_T_134 : _GEN_54; // @[CompressedDecoder.scala 239:37 245:28]
  wire [31:0] _GEN_60 = 2'h2 == instruction_i[1:0] ? _GEN_56 : instruction_i; // @[CompressedDecoder.scala 42:31]
  wire  _GEN_61 = 2'h1 == instruction_i[1:0] ? _GEN_39 : 2'h2 == instruction_i[1:0] & _GEN_55; // @[CompressedDecoder.scala 42:31]
  wire [31:0] _GEN_62 = 2'h1 == instruction_i[1:0] ? _GEN_40 : _GEN_60; // @[CompressedDecoder.scala 42:31]
  wire  _GEN_63 = 2'h0 == instruction_i[1:0] ? _GEN_6 : _GEN_61; // @[CompressedDecoder.scala 42:31]
  wire [31:0] _GEN_64 = 2'h0 == instruction_i[1:0] ? _GEN_7 : _GEN_62; // @[CompressedDecoder.scala 42:31]
  assign io_is_comp = instruction_i == 32'h0 ? 1'h0 : _GEN_63; // @[CompressedDecoder.scala 310:44 312:18]
  assign io_instruction_o = instruction_i == 32'h0 ? instruction_i : _GEN_64; // @[CompressedDecoder.scala 310:44 313:24]
endmodule
module Core(
  input         clock,
  input         reset,
  output [31:0] io_pin,
  input         io_stall,
  input         io_dmemReq_ready,
  output        io_dmemReq_valid,
  output [31:0] io_dmemReq_bits_addrRequest,
  output [31:0] io_dmemReq_bits_dataRequest,
  output [3:0]  io_dmemReq_bits_activeByteLane,
  output        io_dmemReq_bits_isWrite,
  output        io_dmemRsp_ready,
  input         io_dmemRsp_valid,
  input  [31:0] io_dmemRsp_bits_dataResponse,
  input         io_imemReq_ready,
  output        io_imemReq_valid,
  output [31:0] io_imemReq_bits_addrRequest,
  output [31:0] io_imemReq_bits_dataRequest,
  output [3:0]  io_imemReq_bits_activeByteLane,
  output        io_imemReq_bits_isWrite,
  output        io_imemRsp_ready,
  input         io_imemRsp_valid,
  input  [31:0] io_imemRsp_bits_dataResponse
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
  reg [31:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [31:0] _RAND_34;
  reg [31:0] _RAND_35;
  reg [31:0] _RAND_36;
  reg [31:0] _RAND_37;
  reg [31:0] _RAND_38;
  reg [31:0] _RAND_39;
  reg [31:0] _RAND_40;
  reg [31:0] _RAND_41;
  reg [31:0] _RAND_42;
  reg [31:0] _RAND_43;
  reg [31:0] _RAND_44;
  reg [31:0] _RAND_45;
  reg [31:0] _RAND_46;
  reg [31:0] _RAND_47;
  reg [31:0] _RAND_48;
  reg [31:0] _RAND_49;
  reg [31:0] _RAND_50;
  reg [31:0] _RAND_51;
`endif // RANDOMIZE_REG_INIT
  wire  InstructionFetch_clock; // @[Core.scala 124:18]
  wire  InstructionFetch_reset; // @[Core.scala 124:18]
  wire [31:0] InstructionFetch_io_address; // @[Core.scala 124:18]
  wire [31:0] InstructionFetch_io_instruction; // @[Core.scala 124:18]
  wire  InstructionFetch_io_stall; // @[Core.scala 124:18]
  wire  InstructionFetch_io_redirect; // @[Core.scala 124:18]
  wire  InstructionFetch_io_waiting; // @[Core.scala 124:18]
  wire  InstructionFetch_io_inst_valid; // @[Core.scala 124:18]
  wire  InstructionFetch_io_coreInstrReq_ready; // @[Core.scala 124:18]
  wire  InstructionFetch_io_coreInstrReq_valid; // @[Core.scala 124:18]
  wire [31:0] InstructionFetch_io_coreInstrReq_bits_addrRequest; // @[Core.scala 124:18]
  wire  InstructionFetch_io_coreInstrResp_ready; // @[Core.scala 124:18]
  wire  InstructionFetch_io_coreInstrResp_valid; // @[Core.scala 124:18]
  wire [31:0] InstructionFetch_io_coreInstrResp_bits_dataResponse; // @[Core.scala 124:18]
  wire  InstructionDecode_clock; // @[Core.scala 125:18]
  wire  InstructionDecode_reset; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_id_instruction; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_writeData; // @[Core.scala 125:18]
  wire [4:0] InstructionDecode_io_writeReg; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_pcAddress; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ctl_writeEnable_0; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ex_mem_mem_read; // @[Core.scala 125:18]
  wire [4:0] InstructionDecode_io_id_ex_rd; // @[Core.scala 125:18]
  wire [4:0] InstructionDecode_io_ex_mem_rd; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_ex_mem_ins; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_mem_wb_ins; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_ex_ins; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_ex_result; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_ex_mem_result; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_mem_wb_result; // @[Core.scala 125:18]
  wire  InstructionDecode_io_id_ex_regWr; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ex_mem_regWr; // @[Core.scala 125:18]
  wire  InstructionDecode_io_csr_Ex; // @[Core.scala 125:18]
  wire  InstructionDecode_io_csr_Mem; // @[Core.scala 125:18]
  wire  InstructionDecode_io_csr_Wb; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_csr_Ex_data; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_csr_Mem_data; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_csr_Wb_data; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_dmem_data; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ex_stall; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_immediate; // @[Core.scala 125:18]
  wire [4:0] InstructionDecode_io_writeRegAddress; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_readData1; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_readData2; // @[Core.scala 125:18]
  wire [6:0] InstructionDecode_io_func7; // @[Core.scala 125:18]
  wire [2:0] InstructionDecode_io_func3; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ctl_aluSrc; // @[Core.scala 125:18]
  wire [1:0] InstructionDecode_io_ctl_memToReg; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ctl_regWrite_0; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ctl_memRead; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ctl_memWrite; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ctl_branch; // @[Core.scala 125:18]
  wire [1:0] InstructionDecode_io_ctl_aluOp; // @[Core.scala 125:18]
  wire [1:0] InstructionDecode_io_ctl_jump; // @[Core.scala 125:18]
  wire [1:0] InstructionDecode_io_ctl_aluSrc1; // @[Core.scala 125:18]
  wire  InstructionDecode_io_hdu_pcWrite; // @[Core.scala 125:18]
  wire  InstructionDecode_io_hdu_if_reg_write; // @[Core.scala 125:18]
  wire  InstructionDecode_io_pcSrc; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_pcPlusOffset; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ifid_flush; // @[Core.scala 125:18]
  wire  InstructionDecode_io_stall; // @[Core.scala 125:18]
  wire  InstructionDecode_io_csr_i_instr_retired; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_csr_o_data; // @[Core.scala 125:18]
  wire  InstructionDecode_io_is_csr; // @[Core.scala 125:18]
  wire  InstructionDecode_io_isAMO; // @[Core.scala 125:18]
  wire  InstructionDecode_io_isLR; // @[Core.scala 125:18]
  wire  InstructionDecode_io_isSC; // @[Core.scala 125:18]
  wire [4:0] InstructionDecode_io_amoOp; // @[Core.scala 125:18]
  wire  InstructionDecode_io_ex_is_amo; // @[Core.scala 125:18]
  wire  InstructionDecode_io_mem_is_amo; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_addr_ex; // @[Core.scala 125:18]
  wire [31:0] InstructionDecode_io_addr_mem; // @[Core.scala 125:18]
  wire  InstructionDecode_io_is_comp; // @[Core.scala 125:18]
  wire  Execute_clock; // @[Core.scala 126:18]
  wire  Execute_reset; // @[Core.scala 126:18]
  wire [31:0] Execute_io_immediate; // @[Core.scala 126:18]
  wire [31:0] Execute_io_readData1; // @[Core.scala 126:18]
  wire [31:0] Execute_io_readData2; // @[Core.scala 126:18]
  wire [31:0] Execute_io_pcAddress; // @[Core.scala 126:18]
  wire [6:0] Execute_io_func7; // @[Core.scala 126:18]
  wire [2:0] Execute_io_func3; // @[Core.scala 126:18]
  wire [31:0] Execute_io_mem_result; // @[Core.scala 126:18]
  wire [31:0] Execute_io_wb_result; // @[Core.scala 126:18]
  wire  Execute_io_ex_mem_regWrite_0; // @[Core.scala 126:18]
  wire  Execute_io_mem_wb_regWrite_0; // @[Core.scala 126:18]
  wire [31:0] Execute_io_id_ex_ins; // @[Core.scala 126:18]
  wire [31:0] Execute_io_ex_mem_ins; // @[Core.scala 126:18]
  wire [31:0] Execute_io_mem_wb_ins; // @[Core.scala 126:18]
  wire  Execute_io_ctl_aluSrc; // @[Core.scala 126:18]
  wire [1:0] Execute_io_ctl_aluOp; // @[Core.scala 126:18]
  wire [1:0] Execute_io_ctl_aluSrc1; // @[Core.scala 126:18]
  wire  Execute_io_isAMO; // @[Core.scala 126:18]
  wire  Execute_io_isLR; // @[Core.scala 126:18]
  wire  Execute_io_isSC; // @[Core.scala 126:18]
  wire [31:0] Execute_io_writeData; // @[Core.scala 126:18]
  wire [31:0] Execute_io_ALUresult; // @[Core.scala 126:18]
  wire  Execute_io_stall; // @[Core.scala 126:18]
  wire [31:0] Execute_io_amo_memData; // @[Core.scala 126:18]
  wire [31:0] Execute_io_amo_src2; // @[Core.scala 126:18]
  wire [4:0] Execute_io_amo_op_code; // @[Core.scala 126:18]
  wire [31:0] Execute_io_amo_result; // @[Core.scala 126:18]
  wire  MEM_clock; // @[Core.scala 127:19]
  wire  MEM_reset; // @[Core.scala 127:19]
  wire [31:0] MEM_io_aluResultIn; // @[Core.scala 127:19]
  wire [31:0] MEM_io_writeData; // @[Core.scala 127:19]
  wire  MEM_io_writeEnable; // @[Core.scala 127:19]
  wire  MEM_io_readEnable; // @[Core.scala 127:19]
  wire [31:0] MEM_io_readData; // @[Core.scala 127:19]
  wire  MEM_io_stall; // @[Core.scala 127:19]
  wire [2:0] MEM_io_f3; // @[Core.scala 127:19]
  wire  MEM_io_isAMO; // @[Core.scala 127:19]
  wire  MEM_io_isLR; // @[Core.scala 127:19]
  wire  MEM_io_isSC; // @[Core.scala 127:19]
  wire  MEM_io_dccmReq_ready; // @[Core.scala 127:19]
  wire  MEM_io_dccmReq_valid; // @[Core.scala 127:19]
  wire [31:0] MEM_io_dccmReq_bits_addrRequest; // @[Core.scala 127:19]
  wire [31:0] MEM_io_dccmReq_bits_dataRequest; // @[Core.scala 127:19]
  wire [3:0] MEM_io_dccmReq_bits_activeByteLane; // @[Core.scala 127:19]
  wire  MEM_io_dccmReq_bits_isWrite; // @[Core.scala 127:19]
  wire  MEM_io_dccmRsp_valid; // @[Core.scala 127:19]
  wire [31:0] MEM_io_dccmRsp_bits_dataResponse; // @[Core.scala 127:19]
  wire [31:0] MEM_io_amo_alu_result_in; // @[Core.scala 127:19]
  wire  ReservationFile_clock; // @[Core.scala 129:31]
  wire  ReservationFile_reset; // @[Core.scala 129:31]
  wire  ReservationFile_io_set; // @[Core.scala 129:31]
  wire  ReservationFile_io_clear; // @[Core.scala 129:31]
  wire [31:0] ReservationFile_io_addrIn; // @[Core.scala 129:31]
  wire  ReservationFile_io_matchAddr; // @[Core.scala 129:31]
  wire  pc_clock; // @[Core.scala 135:18]
  wire  pc_reset; // @[Core.scala 135:18]
  wire [31:0] pc_io_in; // @[Core.scala 135:18]
  wire  pc_io_halt; // @[Core.scala 135:18]
  wire [31:0] pc_io_out; // @[Core.scala 135:18]
  wire [31:0] pc_io_pc4; // @[Core.scala 135:18]
  wire [31:0] pc_io_pc2; // @[Core.scala 135:18]
  wire  Realigner_clock; // @[Core.scala 144:30]
  wire  Realigner_reset; // @[Core.scala 144:30]
  wire [31:0] Realigner_io_ral_address_i; // @[Core.scala 144:30]
  wire [31:0] Realigner_io_ral_instruction_i; // @[Core.scala 144:30]
  wire  Realigner_io_ral_jmp; // @[Core.scala 144:30]
  wire  Realigner_io_stall; // @[Core.scala 144:30]
  wire [31:0] Realigner_io_ral_instruction_o; // @[Core.scala 144:30]
  wire  Realigner_io_addri; // @[Core.scala 144:30]
  wire  Realigner_io_misaligned_word; // @[Core.scala 144:30]
  wire  Realigner_io_misaligned_word_uh; // @[Core.scala 144:30]
  wire  Realigner_io_nop_sel; // @[Core.scala 144:30]
  wire [31:0] CompressedDecoder_io_instruction_i; // @[Core.scala 153:20]
  wire  CompressedDecoder_io_addri; // @[Core.scala 153:20]
  wire  CompressedDecoder_io_is_comp; // @[Core.scala 153:20]
  wire [31:0] CompressedDecoder_io_instruction_o; // @[Core.scala 153:20]
  reg [31:0] if_reg_pc; // @[Core.scala 35:26]
  reg [31:0] if_reg_ins; // @[Core.scala 36:27]
  reg  if_reg_is_comp; // @[Core.scala 37:43]
  reg [31:0] id_reg_pc; // @[Core.scala 40:26]
  reg [31:0] id_reg_rd1; // @[Core.scala 41:27]
  reg [31:0] id_reg_rd2; // @[Core.scala 42:27]
  reg [31:0] id_reg_imm; // @[Core.scala 43:27]
  reg [4:0] id_reg_wra; // @[Core.scala 44:27]
  reg [6:0] id_reg_f7; // @[Core.scala 45:26]
  reg [2:0] id_reg_f3; // @[Core.scala 46:26]
  reg [31:0] id_reg_ins; // @[Core.scala 47:27]
  reg  id_reg_ctl_aluSrc; // @[Core.scala 48:34]
  reg [1:0] id_reg_ctl_aluSrc1; // @[Core.scala 49:35]
  reg [1:0] id_reg_ctl_memToReg; // @[Core.scala 50:36]
  reg  id_reg_ctl_regWrite_0; // @[Core.scala 51:36]
  reg  id_reg_ctl_memRead; // @[Core.scala 52:35]
  reg  id_reg_ctl_memWrite; // @[Core.scala 53:36]
  reg [1:0] id_reg_ctl_aluOp; // @[Core.scala 55:33]
  reg  id_reg_is_csr; // @[Core.scala 57:46]
  reg [31:0] id_reg_csr_data; // @[Core.scala 58:48]
  reg  id_reg_isAMO; // @[Core.scala 66:29]
  reg  id_reg_isLR; // @[Core.scala 67:29]
  reg  id_reg_isSC; // @[Core.scala 68:29]
  reg [4:0] id_reg_amoOp; // @[Core.scala 69:29]
  reg [31:0] ex_reg_result; // @[Core.scala 74:30]
  reg [31:0] ex_reg_wd; // @[Core.scala 75:26]
  reg [4:0] ex_reg_wra; // @[Core.scala 76:27]
  reg [31:0] ex_reg_ins; // @[Core.scala 77:27]
  reg [1:0] ex_reg_ctl_memToReg; // @[Core.scala 78:36]
  reg  ex_reg_ctl_regWrite_0; // @[Core.scala 79:36]
  reg  ex_reg_ctl_memRead; // @[Core.scala 80:35]
  reg  ex_reg_ctl_memWrite; // @[Core.scala 81:36]
  reg [31:0] ex_reg_pc; // @[Core.scala 83:26]
  reg  ex_reg_is_csr; // @[Core.scala 84:46]
  reg [31:0] ex_reg_csr_data; // @[Core.scala 85:48]
  reg  ex_reg_isAMO; // @[Core.scala 92:30]
  reg  ex_reg_isLR; // @[Core.scala 93:30]
  reg  ex_reg_isSC; // @[Core.scala 94:30]
  reg [4:0] ex_reg_amoOp; // @[Core.scala 95:30]
  reg [31:0] mem_reg_rd; // @[Core.scala 98:27]
  reg [31:0] mem_reg_ins; // @[Core.scala 99:28]
  reg [31:0] mem_reg_result; // @[Core.scala 100:31]
  reg [4:0] mem_reg_wra; // @[Core.scala 102:28]
  reg [1:0] mem_reg_ctl_memToReg; // @[Core.scala 103:37]
  reg  mem_reg_ctl_regWrite_0; // @[Core.scala 104:37]
  reg [31:0] mem_reg_pc; // @[Core.scala 105:27]
  reg  mem_reg_is_csr; // @[Core.scala 106:47]
  reg [31:0] mem_reg_csr_data; // @[Core.scala 107:49]
  reg  amo_read_done; // @[Core.scala 119:30]
  reg [31:0] amo_old_value; // @[Core.scala 120:30]
  reg  sc_issued; // @[Core.scala 121:26]
  wire  halt = Execute_io_stall | InstructionDecode_io_stall | io_imemReq_valid | MEM_io_stall |
    InstructionFetch_io_waiting; // @[Core.scala 142:71]
  wire  _T_2 = ~MEM_io_stall; // @[Core.scala 148:45]
  wire  _T_3 = InstructionDecode_io_pcSrc & ~MEM_io_stall; // @[Core.scala 148:42]
  wire [31:0] instruction = CompressedDecoder_io_instruction_o; // @[Core.scala 140:25 156:18]
  wire  is_comp = CompressedDecoder_io_is_comp; // @[Core.scala 141:39 157:13]
  wire  _npc_T_5 = is_comp | pc_io_out[1] | Realigner_io_misaligned_word; // @[Core.scala 188:33]
  wire [31:0] _npc_T_6 = _npc_T_5 ? $signed(pc_io_pc2) : $signed(pc_io_pc4); // @[Core.scala 187:10]
  wire [31:0] _npc_T_7 = _T_3 ? $signed(InstructionDecode_io_pcPlusOffset) : $signed(_npc_T_6); // @[Core.scala 184:8]
  wire [31:0] npc = InstructionDecode_io_hdu_pcWrite ? $signed(_npc_T_7) : $signed(pc_io_out); // @[Core.scala 182:16]
  wire  _T_17 = InstructionDecode_io_hdu_if_reg_write & _T_2; // @[Core.scala 197:28]
  wire  _T_18 = ~Realigner_io_misaligned_word_uh; // @[Core.scala 198:12]
  wire  _T_19 = InstructionDecode_io_hdu_if_reg_write & _T_2 & _T_18; // @[Core.scala 197:45]
  wire  _T_22 = ~Realigner_io_nop_sel; // @[Core.scala 203:12]
  wire  _T_23 = _T_17 & _T_22; // @[Core.scala 202:45]
  wire  _ex_reg_ctl_regWrite_0_T = ~Execute_io_stall; // @[Core.scala 315:85]
  wire  sc_success = ex_reg_isSC & ReservationFile_io_matchAddr; // @[Core.scala 379:32]
  wire  _T_36 = io_dmemReq_ready & io_dmemReq_valid; // @[Decoupled.scala 51:35]
  wire  _T_38 = ~sc_issued; // @[Core.scala 380:80]
  wire  _T_44 = ~ex_reg_isAMO; // @[Core.scala 381:68]
  wire  _T_45 = ex_reg_ctl_memWrite & ~ex_reg_isSC & ~ex_reg_isAMO; // @[Core.scala 381:65]
  wire  _MEM_io_readEnable_T_1 = ex_reg_isAMO & ~amo_read_done; // @[Core.scala 386:60]
  wire  _MEM_io_writeEnable_T_4 = ex_reg_isAMO & amo_read_done; // @[Core.scala 389:97]
  wire  _GEN_46 = _T_44 ? 1'h0 : amo_read_done; // @[Core.scala 424:29 425:19 119:30]
  wire  _GEN_47 = _MEM_io_writeEnable_T_4 & io_dmemRsp_valid ? 1'h0 : _GEN_46; // @[Core.scala 420:65 422:19]
  wire  _GEN_49 = _MEM_io_readEnable_T_1 & io_dmemRsp_valid | _GEN_47; // @[Core.scala 416:60 418:19]
  wire  _GEN_51 = ex_reg_isSC & _T_2 | sc_issued; // @[Core.scala 431:38 432:16 121:26]
  reg  sc_matched; // @[Core.scala 443:27]
  wire  _GEN_53 = sc_success | sc_matched; // @[Core.scala 444:50 445:16 443:27]
  wire  sc_result = _GEN_53 ? 1'h0 : 1'h1; // @[Core.scala 454:22]
  wire [31:0] _wb_data_T_1 = mem_reg_pc + 32'h4; // @[Core.scala 493:27]
  wire [31:0] _wb_data_T_3 = mem_reg_pc + 32'h2; // @[Core.scala 496:27]
  wire [31:0] _GEN_67 = mem_reg_ctl_memToReg == 2'h3 ? _wb_data_T_3 : mem_reg_result; // @[Core.scala 495:44 496:13 499:13]
  wire [31:0] _GEN_69 = mem_reg_ctl_memToReg == 2'h2 ? _wb_data_T_1 : _GEN_67; // @[Core.scala 492:44 493:13]
  wire [31:0] wb_data = mem_reg_ctl_memToReg == 2'h1 ? mem_reg_rd : _GEN_69; // @[Core.scala 489:38 490:13]
  InstructionFetch InstructionFetch ( // @[Core.scala 124:18]
    .clock(InstructionFetch_clock),
    .reset(InstructionFetch_reset),
    .io_address(InstructionFetch_io_address),
    .io_instruction(InstructionFetch_io_instruction),
    .io_stall(InstructionFetch_io_stall),
    .io_redirect(InstructionFetch_io_redirect),
    .io_waiting(InstructionFetch_io_waiting),
    .io_inst_valid(InstructionFetch_io_inst_valid),
    .io_coreInstrReq_ready(InstructionFetch_io_coreInstrReq_ready),
    .io_coreInstrReq_valid(InstructionFetch_io_coreInstrReq_valid),
    .io_coreInstrReq_bits_addrRequest(InstructionFetch_io_coreInstrReq_bits_addrRequest),
    .io_coreInstrResp_ready(InstructionFetch_io_coreInstrResp_ready),
    .io_coreInstrResp_valid(InstructionFetch_io_coreInstrResp_valid),
    .io_coreInstrResp_bits_dataResponse(InstructionFetch_io_coreInstrResp_bits_dataResponse)
  );
  InstructionDecode InstructionDecode ( // @[Core.scala 125:18]
    .clock(InstructionDecode_clock),
    .reset(InstructionDecode_reset),
    .io_id_instruction(InstructionDecode_io_id_instruction),
    .io_writeData(InstructionDecode_io_writeData),
    .io_writeReg(InstructionDecode_io_writeReg),
    .io_pcAddress(InstructionDecode_io_pcAddress),
    .io_ctl_writeEnable_0(InstructionDecode_io_ctl_writeEnable_0),
    .io_ex_mem_mem_read(InstructionDecode_io_ex_mem_mem_read),
    .io_id_ex_rd(InstructionDecode_io_id_ex_rd),
    .io_ex_mem_rd(InstructionDecode_io_ex_mem_rd),
    .io_ex_mem_ins(InstructionDecode_io_ex_mem_ins),
    .io_mem_wb_ins(InstructionDecode_io_mem_wb_ins),
    .io_ex_ins(InstructionDecode_io_ex_ins),
    .io_ex_result(InstructionDecode_io_ex_result),
    .io_ex_mem_result(InstructionDecode_io_ex_mem_result),
    .io_mem_wb_result(InstructionDecode_io_mem_wb_result),
    .io_id_ex_regWr(InstructionDecode_io_id_ex_regWr),
    .io_ex_mem_regWr(InstructionDecode_io_ex_mem_regWr),
    .io_csr_Ex(InstructionDecode_io_csr_Ex),
    .io_csr_Mem(InstructionDecode_io_csr_Mem),
    .io_csr_Wb(InstructionDecode_io_csr_Wb),
    .io_csr_Ex_data(InstructionDecode_io_csr_Ex_data),
    .io_csr_Mem_data(InstructionDecode_io_csr_Mem_data),
    .io_csr_Wb_data(InstructionDecode_io_csr_Wb_data),
    .io_dmem_data(InstructionDecode_io_dmem_data),
    .io_ex_stall(InstructionDecode_io_ex_stall),
    .io_immediate(InstructionDecode_io_immediate),
    .io_writeRegAddress(InstructionDecode_io_writeRegAddress),
    .io_readData1(InstructionDecode_io_readData1),
    .io_readData2(InstructionDecode_io_readData2),
    .io_func7(InstructionDecode_io_func7),
    .io_func3(InstructionDecode_io_func3),
    .io_ctl_aluSrc(InstructionDecode_io_ctl_aluSrc),
    .io_ctl_memToReg(InstructionDecode_io_ctl_memToReg),
    .io_ctl_regWrite_0(InstructionDecode_io_ctl_regWrite_0),
    .io_ctl_memRead(InstructionDecode_io_ctl_memRead),
    .io_ctl_memWrite(InstructionDecode_io_ctl_memWrite),
    .io_ctl_branch(InstructionDecode_io_ctl_branch),
    .io_ctl_aluOp(InstructionDecode_io_ctl_aluOp),
    .io_ctl_jump(InstructionDecode_io_ctl_jump),
    .io_ctl_aluSrc1(InstructionDecode_io_ctl_aluSrc1),
    .io_hdu_pcWrite(InstructionDecode_io_hdu_pcWrite),
    .io_hdu_if_reg_write(InstructionDecode_io_hdu_if_reg_write),
    .io_pcSrc(InstructionDecode_io_pcSrc),
    .io_pcPlusOffset(InstructionDecode_io_pcPlusOffset),
    .io_ifid_flush(InstructionDecode_io_ifid_flush),
    .io_stall(InstructionDecode_io_stall),
    .io_csr_i_instr_retired(InstructionDecode_io_csr_i_instr_retired),
    .io_csr_o_data(InstructionDecode_io_csr_o_data),
    .io_is_csr(InstructionDecode_io_is_csr),
    .io_isAMO(InstructionDecode_io_isAMO),
    .io_isLR(InstructionDecode_io_isLR),
    .io_isSC(InstructionDecode_io_isSC),
    .io_amoOp(InstructionDecode_io_amoOp),
    .io_ex_is_amo(InstructionDecode_io_ex_is_amo),
    .io_mem_is_amo(InstructionDecode_io_mem_is_amo),
    .io_addr_ex(InstructionDecode_io_addr_ex),
    .io_addr_mem(InstructionDecode_io_addr_mem),
    .io_is_comp(InstructionDecode_io_is_comp)
  );
  Execute Execute ( // @[Core.scala 126:18]
    .clock(Execute_clock),
    .reset(Execute_reset),
    .io_immediate(Execute_io_immediate),
    .io_readData1(Execute_io_readData1),
    .io_readData2(Execute_io_readData2),
    .io_pcAddress(Execute_io_pcAddress),
    .io_func7(Execute_io_func7),
    .io_func3(Execute_io_func3),
    .io_mem_result(Execute_io_mem_result),
    .io_wb_result(Execute_io_wb_result),
    .io_ex_mem_regWrite_0(Execute_io_ex_mem_regWrite_0),
    .io_mem_wb_regWrite_0(Execute_io_mem_wb_regWrite_0),
    .io_id_ex_ins(Execute_io_id_ex_ins),
    .io_ex_mem_ins(Execute_io_ex_mem_ins),
    .io_mem_wb_ins(Execute_io_mem_wb_ins),
    .io_ctl_aluSrc(Execute_io_ctl_aluSrc),
    .io_ctl_aluOp(Execute_io_ctl_aluOp),
    .io_ctl_aluSrc1(Execute_io_ctl_aluSrc1),
    .io_isAMO(Execute_io_isAMO),
    .io_isLR(Execute_io_isLR),
    .io_isSC(Execute_io_isSC),
    .io_writeData(Execute_io_writeData),
    .io_ALUresult(Execute_io_ALUresult),
    .io_stall(Execute_io_stall),
    .io_amo_memData(Execute_io_amo_memData),
    .io_amo_src2(Execute_io_amo_src2),
    .io_amo_op_code(Execute_io_amo_op_code),
    .io_amo_result(Execute_io_amo_result)
  );
  MemoryFetch MEM ( // @[Core.scala 127:19]
    .clock(MEM_clock),
    .reset(MEM_reset),
    .io_aluResultIn(MEM_io_aluResultIn),
    .io_writeData(MEM_io_writeData),
    .io_writeEnable(MEM_io_writeEnable),
    .io_readEnable(MEM_io_readEnable),
    .io_readData(MEM_io_readData),
    .io_stall(MEM_io_stall),
    .io_f3(MEM_io_f3),
    .io_isAMO(MEM_io_isAMO),
    .io_isLR(MEM_io_isLR),
    .io_isSC(MEM_io_isSC),
    .io_dccmReq_ready(MEM_io_dccmReq_ready),
    .io_dccmReq_valid(MEM_io_dccmReq_valid),
    .io_dccmReq_bits_addrRequest(MEM_io_dccmReq_bits_addrRequest),
    .io_dccmReq_bits_dataRequest(MEM_io_dccmReq_bits_dataRequest),
    .io_dccmReq_bits_activeByteLane(MEM_io_dccmReq_bits_activeByteLane),
    .io_dccmReq_bits_isWrite(MEM_io_dccmReq_bits_isWrite),
    .io_dccmRsp_valid(MEM_io_dccmRsp_valid),
    .io_dccmRsp_bits_dataResponse(MEM_io_dccmRsp_bits_dataResponse),
    .io_amo_alu_result_in(MEM_io_amo_alu_result_in)
  );
  ReservationFile ReservationFile ( // @[Core.scala 129:31]
    .clock(ReservationFile_clock),
    .reset(ReservationFile_reset),
    .io_set(ReservationFile_io_set),
    .io_clear(ReservationFile_io_clear),
    .io_addrIn(ReservationFile_io_addrIn),
    .io_matchAddr(ReservationFile_io_matchAddr)
  );
  PC pc ( // @[Core.scala 135:18]
    .clock(pc_clock),
    .reset(pc_reset),
    .io_in(pc_io_in),
    .io_halt(pc_io_halt),
    .io_out(pc_io_out),
    .io_pc4(pc_io_pc4),
    .io_pc2(pc_io_pc2)
  );
  Realigner Realigner ( // @[Core.scala 144:30]
    .clock(Realigner_clock),
    .reset(Realigner_reset),
    .io_ral_address_i(Realigner_io_ral_address_i),
    .io_ral_instruction_i(Realigner_io_ral_instruction_i),
    .io_ral_jmp(Realigner_io_ral_jmp),
    .io_stall(Realigner_io_stall),
    .io_ral_instruction_o(Realigner_io_ral_instruction_o),
    .io_addri(Realigner_io_addri),
    .io_misaligned_word(Realigner_io_misaligned_word),
    .io_misaligned_word_uh(Realigner_io_misaligned_word_uh),
    .io_nop_sel(Realigner_io_nop_sel)
  );
  CompressedDecoder CompressedDecoder ( // @[Core.scala 153:20]
    .io_instruction_i(CompressedDecoder_io_instruction_i),
    .io_addri(CompressedDecoder_io_addri),
    .io_is_comp(CompressedDecoder_io_is_comp),
    .io_instruction_o(CompressedDecoder_io_instruction_o)
  );
  assign io_pin = wb_data; // @[Core.scala 515:10]
  assign io_dmemReq_valid = MEM_io_dccmReq_valid; // @[Core.scala 374:14]
  assign io_dmemReq_bits_addrRequest = MEM_io_dccmReq_bits_addrRequest; // @[Core.scala 374:14]
  assign io_dmemReq_bits_dataRequest = MEM_io_dccmReq_bits_dataRequest; // @[Core.scala 374:14]
  assign io_dmemReq_bits_activeByteLane = MEM_io_dccmReq_bits_activeByteLane; // @[Core.scala 374:14]
  assign io_dmemReq_bits_isWrite = MEM_io_dccmReq_bits_isWrite; // @[Core.scala 374:14]
  assign io_dmemRsp_ready = 1'h1; // @[Core.scala 375:18]
  assign io_imemReq_valid = InstructionFetch_io_coreInstrReq_valid; // @[Core.scala 137:14]
  assign io_imemReq_bits_addrRequest = InstructionFetch_io_coreInstrReq_bits_addrRequest; // @[Core.scala 137:14]
  assign io_imemReq_bits_dataRequest = 32'h0; // @[Core.scala 137:14]
  assign io_imemReq_bits_activeByteLane = 4'hf; // @[Core.scala 137:14]
  assign io_imemReq_bits_isWrite = 1'h0; // @[Core.scala 137:14]
  assign io_imemRsp_ready = InstructionFetch_io_coreInstrResp_ready; // @[Core.scala 138:20]
  assign InstructionFetch_clock = clock;
  assign InstructionFetch_reset = reset;
  assign InstructionFetch_io_address = pc_io_out; // @[Core.scala 162:27]
  assign InstructionFetch_io_stall = io_stall | Execute_io_stall | InstructionDecode_io_stall |
    InstructionDecode_io_pcSrc | MEM_io_stall; // @[Core.scala 178:76]
  assign InstructionFetch_io_redirect = InstructionDecode_io_pcSrc & _T_2; // @[Core.scala 179:27]
  assign InstructionFetch_io_coreInstrReq_ready = io_imemReq_ready; // @[Core.scala 137:14]
  assign InstructionFetch_io_coreInstrResp_valid = io_imemRsp_valid; // @[Core.scala 138:20]
  assign InstructionFetch_io_coreInstrResp_bits_dataResponse = io_imemRsp_bits_dataResponse; // @[Core.scala 138:20]
  assign InstructionDecode_clock = clock;
  assign InstructionDecode_reset = reset;
  assign InstructionDecode_io_id_instruction = if_reg_ins; // @[Core.scala 250:21]
  assign InstructionDecode_io_writeData = wb_data; // @[Core.scala 505:16]
  assign InstructionDecode_io_writeReg = mem_reg_wra; // @[Core.scala 489:38 491:13]
  assign InstructionDecode_io_pcAddress = if_reg_pc; // @[Core.scala 251:16]
  assign InstructionDecode_io_ctl_writeEnable_0 = mem_reg_ctl_regWrite_0; // @[Core.scala 509:22]
  assign InstructionDecode_io_ex_mem_mem_read = ex_reg_ctl_memRead; // @[Core.scala 331:22]
  assign InstructionDecode_io_id_ex_rd = id_reg_ins[11:7]; // @[Core.scala 335:28]
  assign InstructionDecode_io_ex_mem_rd = ex_reg_ins[11:7]; // @[Core.scala 337:29]
  assign InstructionDecode_io_ex_mem_ins = ex_reg_ins; // @[Core.scala 254:17]
  assign InstructionDecode_io_mem_wb_ins = mem_reg_ins; // @[Core.scala 255:17]
  assign InstructionDecode_io_ex_ins = id_reg_ins; // @[Core.scala 253:13]
  assign InstructionDecode_io_ex_result = Execute_io_ALUresult; // @[Core.scala 347:16]
  assign InstructionDecode_io_ex_mem_result = ex_reg_ctl_memRead ? MEM_io_readData : ex_reg_result; // @[Core.scala 342:26]
  assign InstructionDecode_io_mem_wb_result = wb_data; // @[Core.scala 503:20]
  assign InstructionDecode_io_id_ex_regWr = id_reg_ctl_regWrite_0; // @[Core.scala 266:18]
  assign InstructionDecode_io_ex_mem_regWr = ex_reg_ctl_regWrite_0; // @[Core.scala 267:19]
  assign InstructionDecode_io_csr_Ex = id_reg_is_csr; // @[Core.scala 349:19]
  assign InstructionDecode_io_csr_Mem = ex_reg_is_csr; // @[Core.scala 406:20]
  assign InstructionDecode_io_csr_Wb = mem_reg_is_csr; // @[Core.scala 511:19]
  assign InstructionDecode_io_csr_Ex_data = id_reg_csr_data; // @[Core.scala 350:24]
  assign InstructionDecode_io_csr_Mem_data = ex_reg_csr_data; // @[Core.scala 407:25]
  assign InstructionDecode_io_csr_Wb_data = mem_reg_csr_data; // @[Core.scala 512:24]
  assign InstructionDecode_io_dmem_data = io_dmemRsp_bits_dataResponse; // @[Core.scala 514:16]
  assign InstructionDecode_io_ex_stall = Execute_io_stall; // @[Core.scala 352:15]
  assign InstructionDecode_io_csr_i_instr_retired = mem_reg_ins != 32'h0 & ~InstructionDecode_io_ifid_flush & ~(
    MEM_io_stall | io_stall) & (mem_reg_ctl_memToReg == 2'h0 | io_dmemRsp_valid); // @[Core.scala 533:99]
  assign InstructionDecode_io_ex_is_amo = id_reg_isAMO; // @[Core.scala 409:17]
  assign InstructionDecode_io_mem_is_amo = ex_reg_isAMO; // @[Core.scala 410:17]
  assign InstructionDecode_io_addr_ex = Execute_io_ALUresult; // @[Core.scala 412:15]
  assign InstructionDecode_io_addr_mem = ex_reg_result; // @[Core.scala 413:15]
  assign InstructionDecode_io_is_comp = if_reg_is_comp; // @[Core.scala 282:20]
  assign Execute_clock = clock;
  assign Execute_reset = reset;
  assign Execute_io_immediate = id_reg_imm; // @[Core.scala 293:16]
  assign Execute_io_readData1 = id_reg_rd1; // @[Core.scala 294:16]
  assign Execute_io_readData2 = id_reg_rd2; // @[Core.scala 295:16]
  assign Execute_io_pcAddress = id_reg_pc; // @[Core.scala 296:16]
  assign Execute_io_func7 = id_reg_f7; // @[Core.scala 298:12]
  assign Execute_io_func3 = id_reg_f3; // @[Core.scala 297:12]
  assign Execute_io_mem_result = ex_reg_result; // @[Core.scala 404:17]
  assign Execute_io_wb_result = wb_data; // @[Core.scala 506:16]
  assign Execute_io_ex_mem_regWrite_0 = ex_reg_ctl_regWrite_0; // @[Core.scala 480:22]
  assign Execute_io_mem_wb_regWrite_0 = mem_reg_ctl_regWrite_0; // @[Core.scala 507:22]
  assign Execute_io_id_ex_ins = id_reg_ins; // @[Core.scala 332:16]
  assign Execute_io_ex_mem_ins = ex_reg_ins; // @[Core.scala 333:17]
  assign Execute_io_mem_wb_ins = mem_reg_ins; // @[Core.scala 334:17]
  assign Execute_io_ctl_aluSrc = id_reg_ctl_aluSrc; // @[Core.scala 299:17]
  assign Execute_io_ctl_aluOp = id_reg_ctl_aluOp; // @[Core.scala 300:16]
  assign Execute_io_ctl_aluSrc1 = id_reg_ctl_aluSrc1; // @[Core.scala 301:18]
  assign Execute_io_isAMO = id_reg_isAMO; // @[Core.scala 289:12]
  assign Execute_io_isLR = id_reg_isLR; // @[Core.scala 290:11]
  assign Execute_io_isSC = id_reg_isSC; // @[Core.scala 291:11]
  assign Execute_io_amo_memData = amo_old_value; // @[Core.scala 304:18]
  assign Execute_io_amo_src2 = ex_reg_wd; // @[Core.scala 305:18]
  assign Execute_io_amo_op_code = ex_reg_amoOp; // @[Core.scala 306:18]
  assign MEM_clock = clock;
  assign MEM_reset = reset;
  assign MEM_io_aluResultIn = ex_reg_result; // @[Core.scala 401:22]
  assign MEM_io_writeData = ex_reg_wd; // @[Core.scala 391:20]
  assign MEM_io_writeEnable = _T_45 | ex_reg_isAMO & amo_read_done | ex_reg_isSC & sc_success & _T_38; // @[Core.scala 389:115]
  assign MEM_io_readEnable = ex_reg_ctl_memRead | ex_reg_isAMO & ~amo_read_done | ex_reg_isLR; // @[Core.scala 386:79]
  assign MEM_io_f3 = ex_reg_ins[14:12]; // @[Core.scala 402:26]
  assign MEM_io_isAMO = ex_reg_isAMO; // @[Core.scala 394:16]
  assign MEM_io_isLR = ex_reg_isLR; // @[Core.scala 395:15]
  assign MEM_io_isSC = ex_reg_isSC; // @[Core.scala 396:15]
  assign MEM_io_dccmReq_ready = io_dmemReq_ready; // @[Core.scala 374:14]
  assign MEM_io_dccmRsp_valid = io_dmemRsp_valid; // @[Core.scala 375:18]
  assign MEM_io_dccmRsp_bits_dataResponse = io_dmemRsp_bits_dataResponse; // @[Core.scala 375:18]
  assign MEM_io_amo_alu_result_in = Execute_io_amo_result; // @[Core.scala 398:28]
  assign ReservationFile_clock = clock;
  assign ReservationFile_reset = reset;
  assign ReservationFile_io_set = ex_reg_isLR & io_dmemRsp_valid; // @[Core.scala 378:38]
  assign ReservationFile_io_clear = ex_reg_isSC & (_T_36 | ~sc_success & ~sc_issued) | _T_45; // @[Core.scala 380:94]
  assign ReservationFile_io_addrIn = ex_reg_result; // @[Core.scala 382:26]
  assign pc_clock = clock;
  assign pc_reset = reset;
  assign pc_io_in = npc; // @[Core.scala 195:12]
  assign pc_io_halt = halt; // @[Core.scala 181:14]
  assign Realigner_clock = clock;
  assign Realigner_reset = reset;
  assign Realigner_io_ral_address_i = pc_io_out; // @[Core.scala 146:43]
  assign Realigner_io_ral_instruction_i = InstructionFetch_io_inst_valid ? InstructionFetch_io_instruction : 32'h0; // @[Core.scala 147:36]
  assign Realigner_io_ral_jmp = InstructionDecode_io_pcSrc & ~MEM_io_stall; // @[Core.scala 148:42]
  assign Realigner_io_stall = halt; // @[Core.scala 149:30]
  assign CompressedDecoder_io_instruction_i = Realigner_io_ral_instruction_o; // @[Core.scala 154:22]
  assign CompressedDecoder_io_addri = Realigner_io_addri; // @[Core.scala 155:14]
  always @(posedge clock) begin
    if (reset) begin // @[Core.scala 35:26]
      if_reg_pc <= 32'h0; // @[Core.scala 35:26]
    end else if (_T_19) begin // @[Core.scala 199:6]
      if_reg_pc <= pc_io_out; // @[Core.scala 200:15]
    end
    if (reset) begin // @[Core.scala 36:27]
      if_reg_ins <= 32'h0; // @[Core.scala 36:27]
    end else if (InstructionDecode_io_ifid_flush & _T_2) begin // @[Core.scala 210:40]
      if_reg_ins <= 32'h0; // @[Core.scala 211:16]
    end else if (_T_23) begin // @[Core.scala 204:6]
      if_reg_ins <= instruction; // @[Core.scala 205:16]
    end
    if (reset) begin // @[Core.scala 37:43]
      if_reg_is_comp <= 1'h0; // @[Core.scala 37:43]
    end else if (InstructionDecode_io_ifid_flush & _T_2) begin // @[Core.scala 210:40]
      if_reg_is_comp <= 1'h0; // @[Core.scala 213:26]
    end else if (_T_23) begin // @[Core.scala 204:6]
      if_reg_is_comp <= is_comp; // @[Core.scala 207:26]
    end
    if (reset) begin // @[Core.scala 40:26]
      id_reg_pc <= 32'h0; // @[Core.scala 40:26]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_pc <= if_reg_pc; // @[Core.scala 229:15]
    end
    if (reset) begin // @[Core.scala 41:27]
      id_reg_rd1 <= 32'h0; // @[Core.scala 41:27]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_rd1 <= InstructionDecode_io_readData1; // @[Core.scala 222:16]
    end
    if (reset) begin // @[Core.scala 42:27]
      id_reg_rd2 <= 32'h0; // @[Core.scala 42:27]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_rd2 <= InstructionDecode_io_readData2; // @[Core.scala 223:16]
    end
    if (reset) begin // @[Core.scala 43:27]
      id_reg_imm <= 32'h0; // @[Core.scala 43:27]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_imm <= InstructionDecode_io_immediate; // @[Core.scala 224:16]
    end
    if (reset) begin // @[Core.scala 44:27]
      id_reg_wra <= 5'h0; // @[Core.scala 44:27]
    end else if (!(Execute_io_stall | MEM_io_stall)) begin // @[Core.scala 354:33]
      if (_T_2) begin // @[Core.scala 221:23]
        id_reg_wra <= InstructionDecode_io_writeRegAddress; // @[Core.scala 225:16]
      end
    end
    if (reset) begin // @[Core.scala 45:26]
      id_reg_f7 <= 7'h0; // @[Core.scala 45:26]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_f7 <= InstructionDecode_io_func7; // @[Core.scala 227:15]
    end
    if (reset) begin // @[Core.scala 46:26]
      id_reg_f3 <= 3'h0; // @[Core.scala 46:26]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_f3 <= InstructionDecode_io_func3; // @[Core.scala 226:15]
    end
    if (reset) begin // @[Core.scala 47:27]
      id_reg_ins <= 32'h0; // @[Core.scala 47:27]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_ins <= if_reg_ins; // @[Core.scala 228:16]
    end
    if (reset) begin // @[Core.scala 48:34]
      id_reg_ctl_aluSrc <= 1'h0; // @[Core.scala 48:34]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_ctl_aluSrc <= InstructionDecode_io_ctl_aluSrc; // @[Core.scala 230:23]
    end
    if (reset) begin // @[Core.scala 49:35]
      id_reg_ctl_aluSrc1 <= 2'h0; // @[Core.scala 49:35]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_ctl_aluSrc1 <= InstructionDecode_io_ctl_aluSrc1; // @[Core.scala 238:24]
    end
    if (reset) begin // @[Core.scala 50:36]
      id_reg_ctl_memToReg <= 2'h0; // @[Core.scala 50:36]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_ctl_memToReg <= InstructionDecode_io_ctl_memToReg; // @[Core.scala 231:25]
    end
    if (reset) begin // @[Core.scala 51:36]
      id_reg_ctl_regWrite_0 <= 1'h0; // @[Core.scala 51:36]
    end else if (!(Execute_io_stall | MEM_io_stall)) begin // @[Core.scala 354:33]
      if (_T_2) begin // @[Core.scala 221:23]
        id_reg_ctl_regWrite_0 <= InstructionDecode_io_ctl_regWrite_0; // @[Core.scala 232:25]
      end
    end
    if (reset) begin // @[Core.scala 52:35]
      id_reg_ctl_memRead <= 1'h0; // @[Core.scala 52:35]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_ctl_memRead <= InstructionDecode_io_ctl_memRead; // @[Core.scala 233:24]
    end
    if (reset) begin // @[Core.scala 53:36]
      id_reg_ctl_memWrite <= 1'h0; // @[Core.scala 53:36]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_ctl_memWrite <= InstructionDecode_io_ctl_memWrite; // @[Core.scala 234:25]
    end
    if (reset) begin // @[Core.scala 55:33]
      id_reg_ctl_aluOp <= 2'h0; // @[Core.scala 55:33]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_ctl_aluOp <= InstructionDecode_io_ctl_aluOp; // @[Core.scala 236:22]
    end
    if (reset) begin // @[Core.scala 57:46]
      id_reg_is_csr <= 1'h0; // @[Core.scala 57:46]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_is_csr <= InstructionDecode_io_is_csr; // @[Core.scala 240:25]
    end
    if (reset) begin // @[Core.scala 58:48]
      id_reg_csr_data <= 32'h0; // @[Core.scala 58:48]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_csr_data <= InstructionDecode_io_csr_o_data; // @[Core.scala 241:27]
    end
    if (reset) begin // @[Core.scala 66:29]
      id_reg_isAMO <= 1'h0; // @[Core.scala 66:29]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_isAMO <= InstructionDecode_io_isAMO; // @[Core.scala 244:18]
    end
    if (reset) begin // @[Core.scala 67:29]
      id_reg_isLR <= 1'h0; // @[Core.scala 67:29]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_isLR <= InstructionDecode_io_isLR; // @[Core.scala 245:18]
    end
    if (reset) begin // @[Core.scala 68:29]
      id_reg_isSC <= 1'h0; // @[Core.scala 68:29]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_isSC <= InstructionDecode_io_isSC; // @[Core.scala 246:18]
    end
    if (reset) begin // @[Core.scala 69:29]
      id_reg_amoOp <= 5'h0; // @[Core.scala 69:29]
    end else if (_T_2) begin // @[Core.scala 221:23]
      id_reg_amoOp <= InstructionDecode_io_amoOp; // @[Core.scala 247:18]
    end
    if (reset) begin // @[Core.scala 74:30]
      ex_reg_result <= 32'h0; // @[Core.scala 74:30]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_result <= Execute_io_ALUresult; // @[Core.scala 323:19]
    end
    if (reset) begin // @[Core.scala 75:26]
      ex_reg_wd <= 32'h0; // @[Core.scala 75:26]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_wd <= Execute_io_writeData; // @[Core.scala 322:15]
    end
    if (reset) begin // @[Core.scala 76:27]
      ex_reg_wra <= 5'h0; // @[Core.scala 76:27]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_wra <= id_reg_wra; // @[Core.scala 310:16]
    end
    if (reset) begin // @[Core.scala 77:27]
      ex_reg_ins <= 32'h0; // @[Core.scala 77:27]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_ins <= id_reg_ins; // @[Core.scala 311:16]
    end
    if (reset) begin // @[Core.scala 78:36]
      ex_reg_ctl_memToReg <= 2'h0; // @[Core.scala 78:36]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_ctl_memToReg <= id_reg_ctl_memToReg; // @[Core.scala 312:25]
    end
    if (reset) begin // @[Core.scala 79:36]
      ex_reg_ctl_regWrite_0 <= 1'h0; // @[Core.scala 79:36]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_ctl_regWrite_0 <= id_reg_ctl_regWrite_0 & ~Execute_io_stall; // @[Core.scala 315:77]
    end
    if (reset) begin // @[Core.scala 80:35]
      ex_reg_ctl_memRead <= 1'h0; // @[Core.scala 80:35]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_ctl_memRead <= id_reg_ctl_memRead; // @[Core.scala 320:24]
    end
    if (reset) begin // @[Core.scala 81:36]
      ex_reg_ctl_memWrite <= 1'h0; // @[Core.scala 81:36]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_ctl_memWrite <= id_reg_ctl_memWrite; // @[Core.scala 321:25]
    end
    if (reset) begin // @[Core.scala 83:26]
      ex_reg_pc <= 32'h0; // @[Core.scala 83:26]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_pc <= id_reg_pc; // @[Core.scala 309:15]
    end
    if (reset) begin // @[Core.scala 84:46]
      ex_reg_is_csr <= 1'h0; // @[Core.scala 84:46]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_is_csr <= id_reg_is_csr; // @[Core.scala 317:25]
    end
    if (reset) begin // @[Core.scala 85:48]
      ex_reg_csr_data <= 32'h0; // @[Core.scala 85:48]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_csr_data <= id_reg_csr_data; // @[Core.scala 318:27]
    end
    if (reset) begin // @[Core.scala 92:30]
      ex_reg_isAMO <= 1'h0; // @[Core.scala 92:30]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_isAMO <= id_reg_isAMO; // @[Core.scala 324:18]
    end
    if (reset) begin // @[Core.scala 93:30]
      ex_reg_isLR <= 1'h0; // @[Core.scala 93:30]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_isLR <= id_reg_isLR; // @[Core.scala 325:18]
    end
    if (reset) begin // @[Core.scala 94:30]
      ex_reg_isSC <= 1'h0; // @[Core.scala 94:30]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_isSC <= id_reg_isSC; // @[Core.scala 326:18]
    end
    if (reset) begin // @[Core.scala 95:30]
      ex_reg_amoOp <= 5'h0; // @[Core.scala 95:30]
    end else if (_T_2) begin // @[Core.scala 308:23]
      ex_reg_amoOp <= id_reg_amoOp; // @[Core.scala 327:18]
    end
    if (reset) begin // @[Core.scala 98:27]
      mem_reg_rd <= 32'h0; // @[Core.scala 98:27]
    end else if (_T_2) begin // @[Core.scala 456:23]
      if (ex_reg_isAMO) begin // @[Core.scala 457:22]
        mem_reg_rd <= amo_old_value;
      end else begin
        mem_reg_rd <= MEM_io_readData;
      end
    end
    if (reset) begin // @[Core.scala 99:28]
      mem_reg_ins <= 32'h0; // @[Core.scala 99:28]
    end else if (_T_2) begin // @[Core.scala 456:23]
      mem_reg_ins <= ex_reg_ins; // @[Core.scala 460:17]
    end
    if (reset) begin // @[Core.scala 100:31]
      mem_reg_result <= 32'h0; // @[Core.scala 100:31]
    end else if (_T_2) begin // @[Core.scala 456:23]
      if (ex_reg_isSC) begin // @[Core.scala 458:26]
        mem_reg_result <= {{31'd0}, sc_result};
      end else begin
        mem_reg_result <= ex_reg_result;
      end
    end
    if (reset) begin // @[Core.scala 102:28]
      mem_reg_wra <= 5'h0; // @[Core.scala 102:28]
    end else if (_T_2) begin // @[Core.scala 456:23]
      mem_reg_wra <= ex_reg_wra; // @[Core.scala 462:17]
    end
    if (reset) begin // @[Core.scala 103:37]
      mem_reg_ctl_memToReg <= 2'h0; // @[Core.scala 103:37]
    end else if (_T_2) begin // @[Core.scala 456:23]
      mem_reg_ctl_memToReg <= ex_reg_ctl_memToReg; // @[Core.scala 463:26]
    end
    if (reset) begin // @[Core.scala 104:37]
      mem_reg_ctl_regWrite_0 <= 1'h0; // @[Core.scala 104:37]
    end else if (_T_2) begin // @[Core.scala 456:23]
      mem_reg_ctl_regWrite_0 <= ex_reg_ctl_regWrite_0; // @[Core.scala 459:26]
    end
    if (reset) begin // @[Core.scala 105:27]
      mem_reg_pc <= 32'h0; // @[Core.scala 105:27]
    end else if (_T_2) begin // @[Core.scala 456:23]
      mem_reg_pc <= ex_reg_pc; // @[Core.scala 461:16]
    end
    if (reset) begin // @[Core.scala 106:47]
      mem_reg_is_csr <= 1'h0; // @[Core.scala 106:47]
    end else if (_T_2) begin // @[Core.scala 456:23]
      mem_reg_is_csr <= ex_reg_is_csr; // @[Core.scala 465:26]
    end
    if (reset) begin // @[Core.scala 107:49]
      mem_reg_csr_data <= 32'h0; // @[Core.scala 107:49]
    end else if (_T_2) begin // @[Core.scala 456:23]
      mem_reg_csr_data <= ex_reg_csr_data; // @[Core.scala 466:28]
    end
    if (reset) begin // @[Core.scala 119:30]
      amo_read_done <= 1'h0; // @[Core.scala 119:30]
    end else begin
      amo_read_done <= _GEN_49;
    end
    if (reset) begin // @[Core.scala 120:30]
      amo_old_value <= 32'h0; // @[Core.scala 120:30]
    end else if (_MEM_io_readEnable_T_1 & io_dmemRsp_valid) begin // @[Core.scala 416:60]
      amo_old_value <= io_dmemRsp_bits_dataResponse; // @[Core.scala 419:19]
    end
    if (reset) begin // @[Core.scala 121:26]
      sc_issued <= 1'h0; // @[Core.scala 121:26]
    end else if (_T_2 & _ex_reg_ctl_regWrite_0_T) begin // @[Core.scala 437:36]
      sc_issued <= 1'h0; // @[Core.scala 438:17]
    end else begin
      sc_issued <= _GEN_51;
    end
    if (reset) begin // @[Core.scala 443:27]
      sc_matched <= 1'h0; // @[Core.scala 443:27]
    end else if (_T_2) begin // @[Core.scala 447:23]
      sc_matched <= 1'h0; // @[Core.scala 448:16]
    end else begin
      sc_matched <= _GEN_53;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  if_reg_pc = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  if_reg_ins = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  if_reg_is_comp = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  id_reg_pc = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  id_reg_rd1 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  id_reg_rd2 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  id_reg_imm = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  id_reg_wra = _RAND_7[4:0];
  _RAND_8 = {1{`RANDOM}};
  id_reg_f7 = _RAND_8[6:0];
  _RAND_9 = {1{`RANDOM}};
  id_reg_f3 = _RAND_9[2:0];
  _RAND_10 = {1{`RANDOM}};
  id_reg_ins = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  id_reg_ctl_aluSrc = _RAND_11[0:0];
  _RAND_12 = {1{`RANDOM}};
  id_reg_ctl_aluSrc1 = _RAND_12[1:0];
  _RAND_13 = {1{`RANDOM}};
  id_reg_ctl_memToReg = _RAND_13[1:0];
  _RAND_14 = {1{`RANDOM}};
  id_reg_ctl_regWrite_0 = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  id_reg_ctl_memRead = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  id_reg_ctl_memWrite = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  id_reg_ctl_aluOp = _RAND_17[1:0];
  _RAND_18 = {1{`RANDOM}};
  id_reg_is_csr = _RAND_18[0:0];
  _RAND_19 = {1{`RANDOM}};
  id_reg_csr_data = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  id_reg_isAMO = _RAND_20[0:0];
  _RAND_21 = {1{`RANDOM}};
  id_reg_isLR = _RAND_21[0:0];
  _RAND_22 = {1{`RANDOM}};
  id_reg_isSC = _RAND_22[0:0];
  _RAND_23 = {1{`RANDOM}};
  id_reg_amoOp = _RAND_23[4:0];
  _RAND_24 = {1{`RANDOM}};
  ex_reg_result = _RAND_24[31:0];
  _RAND_25 = {1{`RANDOM}};
  ex_reg_wd = _RAND_25[31:0];
  _RAND_26 = {1{`RANDOM}};
  ex_reg_wra = _RAND_26[4:0];
  _RAND_27 = {1{`RANDOM}};
  ex_reg_ins = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  ex_reg_ctl_memToReg = _RAND_28[1:0];
  _RAND_29 = {1{`RANDOM}};
  ex_reg_ctl_regWrite_0 = _RAND_29[0:0];
  _RAND_30 = {1{`RANDOM}};
  ex_reg_ctl_memRead = _RAND_30[0:0];
  _RAND_31 = {1{`RANDOM}};
  ex_reg_ctl_memWrite = _RAND_31[0:0];
  _RAND_32 = {1{`RANDOM}};
  ex_reg_pc = _RAND_32[31:0];
  _RAND_33 = {1{`RANDOM}};
  ex_reg_is_csr = _RAND_33[0:0];
  _RAND_34 = {1{`RANDOM}};
  ex_reg_csr_data = _RAND_34[31:0];
  _RAND_35 = {1{`RANDOM}};
  ex_reg_isAMO = _RAND_35[0:0];
  _RAND_36 = {1{`RANDOM}};
  ex_reg_isLR = _RAND_36[0:0];
  _RAND_37 = {1{`RANDOM}};
  ex_reg_isSC = _RAND_37[0:0];
  _RAND_38 = {1{`RANDOM}};
  ex_reg_amoOp = _RAND_38[4:0];
  _RAND_39 = {1{`RANDOM}};
  mem_reg_rd = _RAND_39[31:0];
  _RAND_40 = {1{`RANDOM}};
  mem_reg_ins = _RAND_40[31:0];
  _RAND_41 = {1{`RANDOM}};
  mem_reg_result = _RAND_41[31:0];
  _RAND_42 = {1{`RANDOM}};
  mem_reg_wra = _RAND_42[4:0];
  _RAND_43 = {1{`RANDOM}};
  mem_reg_ctl_memToReg = _RAND_43[1:0];
  _RAND_44 = {1{`RANDOM}};
  mem_reg_ctl_regWrite_0 = _RAND_44[0:0];
  _RAND_45 = {1{`RANDOM}};
  mem_reg_pc = _RAND_45[31:0];
  _RAND_46 = {1{`RANDOM}};
  mem_reg_is_csr = _RAND_46[0:0];
  _RAND_47 = {1{`RANDOM}};
  mem_reg_csr_data = _RAND_47[31:0];
  _RAND_48 = {1{`RANDOM}};
  amo_read_done = _RAND_48[0:0];
  _RAND_49 = {1{`RANDOM}};
  amo_old_value = _RAND_49[31:0];
  _RAND_50 = {1{`RANDOM}};
  sc_issued = _RAND_50[0:0];
  _RAND_51 = {1{`RANDOM}};
  sc_matched = _RAND_51[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
