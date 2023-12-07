/* verilator lint_off ASSIGNDLY */
/* verilator lint_off UNUSED */
/* verilator lint_off BLKSEQ */
/* verilator lint_off DECLFILENAME */
module InstructionFetch(
  input         reset,
  input  [31:0] io_address,
  output [31:0] io_instruction,
  input         io_stall,
  output        io_coreInstrReq_valid,
  output [31:0] io_coreInstrReq_bits_addrRequest,
  input         io_coreInstrResp_valid,
  input  [31:0] io_coreInstrResp_bits_dataResponse
);
  assign io_instruction = io_coreInstrResp_valid ? io_coreInstrResp_bits_dataResponse : 32'h0; // @[InstructionFetch.scala 29:24]
  assign io_coreInstrReq_valid = reset | io_stall ? 1'h0 : 1'h1; // @[InstructionFetch.scala 27:31]
  assign io_coreInstrReq_bits_addrRequest = {{2'd0}, io_address[31:2]}; // @[InstructionFetch.scala 26:36]
endmodule
module CSRRegFile(
  input         clock,
  input         reset,
  input  [31:0] io_MISA_i_value,
  input  [31:0] io_MHARTID_i_value,
  input  [1:0]  io_CSR_i_opr,
  output [31:0] io_CSR_o_data,
  input  [31:0] io_CSR_i_data,
  input  [11:0] io_CSR_i_addr,
  input         io_CSR_i_w_en,
  output        io_FCSR_nx,
  output        io_FCSR_uf,
  output        io_FCSR_of,
  output        io_FCSR_dz,
  output        io_FCSR_nv,
  output [2:0]  io_FCSR_frm
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
`endif // RANDOMIZE_REG_INIT
  reg [31:0] MISA_REG; // @[CSRRegFile.scala 18:38]
  reg [31:0] MHARTID_REG; // @[CSRRegFile.scala 19:38]
  reg [31:0] MCAUSE_REG; // @[CSRRegFile.scala 20:38]
  reg [31:0] MTVEC_REG; // @[CSRRegFile.scala 21:38]
  reg [31:0] MEPC_REG; // @[CSRRegFile.scala 22:38]
  reg [31:0] MIE_REG; // @[CSRRegFile.scala 23:38]
  reg  MSTATUS_TW_REG; // @[CSRRegFile.scala 26:38]
  reg  MSTATUS_MPRV_REG; // @[CSRRegFile.scala 27:38]
  reg [1:0] MSTATUS_MPP_REG; // @[CSRRegFile.scala 28:38]
  reg  MSTATUS_MPIE_REG; // @[CSRRegFile.scala 29:38]
  reg  MSTATUS_MIE_REG; // @[CSRRegFile.scala 30:38]
  reg  FCSR_NX_REG; // @[CSRRegFile.scala 33:38]
  reg  FCSR_UF_REG; // @[CSRRegFile.scala 34:38]
  reg  FCSR_OF_REG; // @[CSRRegFile.scala 35:38]
  reg  FCSR_DZ_REG; // @[CSRRegFile.scala 36:38]
  reg  FCSR_NV_REG; // @[CSRRegFile.scala 37:38]
  reg [2:0] FCSR_FRM_REG; // @[CSRRegFile.scala 38:38]
  wire [10:0] MSTATUS_WIRE_lo = {3'h0,MSTATUS_MPIE_REG,3'h0,MSTATUS_MIE_REG,3'h0}; // @[Cat.scala 33:92]
  wire [31:0] MSTATUS_WIRE = {10'h0,MSTATUS_TW_REG,3'h0,MSTATUS_MPRV_REG,4'h0,MSTATUS_MPP_REG,MSTATUS_WIRE_lo}; // @[Cat.scala 33:92]
  wire [31:0] FFLAGS_WIRE = {27'h0,FCSR_NV_REG,FCSR_DZ_REG,FCSR_OF_REG,FCSR_UF_REG,FCSR_NX_REG}; // @[Cat.scala 33:92]
  wire [31:0] FRM_WIRE = {29'h0,FCSR_FRM_REG}; // @[Cat.scala 33:92]
  wire [31:0] FCSR_WIRE = {24'h0,FCSR_FRM_REG,FCSR_NV_REG,FCSR_DZ_REG,FCSR_OF_REG,FCSR_UF_REG,FCSR_NX_REG}; // @[Cat.scala 33:92]
  wire [31:0] _r_data_T_1 = 12'h301 == io_CSR_i_addr ? MISA_REG : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _r_data_T_3 = 12'hf14 == io_CSR_i_addr ? MHARTID_REG : _r_data_T_1; // @[Mux.scala 81:58]
  wire  _r_data_T_4 = 12'h300 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_5 = 12'h300 == io_CSR_i_addr ? MSTATUS_WIRE : _r_data_T_3; // @[Mux.scala 81:58]
  wire  _r_data_T_6 = 12'h342 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_7 = 12'h342 == io_CSR_i_addr ? MCAUSE_REG : _r_data_T_5; // @[Mux.scala 81:58]
  wire  _r_data_T_8 = 12'h305 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_9 = 12'h305 == io_CSR_i_addr ? MTVEC_REG : _r_data_T_7; // @[Mux.scala 81:58]
  wire  _r_data_T_10 = 12'h341 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_11 = 12'h341 == io_CSR_i_addr ? MEPC_REG : _r_data_T_9; // @[Mux.scala 81:58]
  wire  _r_data_T_12 = 12'h304 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_13 = 12'h304 == io_CSR_i_addr ? MIE_REG : _r_data_T_11; // @[Mux.scala 81:58]
  wire  _r_data_T_14 = 12'h1 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_15 = 12'h1 == io_CSR_i_addr ? FFLAGS_WIRE : _r_data_T_13; // @[Mux.scala 81:58]
  wire  _r_data_T_16 = 12'h2 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] _r_data_T_17 = 12'h2 == io_CSR_i_addr ? FRM_WIRE : _r_data_T_15; // @[Mux.scala 81:58]
  wire  _r_data_T_18 = 12'h3 == io_CSR_i_addr; // @[Mux.scala 81:61]
  wire [31:0] r_data = 12'h3 == io_CSR_i_addr ? FCSR_WIRE : _r_data_T_17; // @[Mux.scala 81:58]
  wire [31:0] set_data = r_data | io_CSR_i_data; // @[CSRRegFile.scala 90:29]
  wire [31:0] _clear_data_T = ~io_CSR_i_data; // @[CSRRegFile.scala 91:31]
  wire [31:0] clear_data = r_data & _clear_data_T; // @[CSRRegFile.scala 91:29]
  wire [31:0] _w_data_T_1 = 2'h1 == io_CSR_i_opr ? io_CSR_i_data : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _w_data_T_3 = 2'h2 == io_CSR_i_opr ? set_data : _w_data_T_1; // @[Mux.scala 81:58]
  wire [31:0] w_data = 2'h3 == io_CSR_i_opr ? clear_data : _w_data_T_3; // @[Mux.scala 81:58]
  wire [2:0] _GEN_0 = _r_data_T_16 ? w_data[2:0] : FCSR_FRM_REG; // @[CSRRegFile.scala 102:30 138:34 38:38]
  wire  _GEN_1 = _r_data_T_14 ? w_data[0] : FCSR_NX_REG; // @[CSRRegFile.scala 102:30 131:34 33:38]
  wire  _GEN_2 = _r_data_T_14 ? w_data[1] : FCSR_UF_REG; // @[CSRRegFile.scala 102:30 132:34 34:38]
  wire  _GEN_3 = _r_data_T_14 ? w_data[2] : FCSR_OF_REG; // @[CSRRegFile.scala 102:30 133:34 35:38]
  wire  _GEN_4 = _r_data_T_14 ? w_data[3] : FCSR_DZ_REG; // @[CSRRegFile.scala 102:30 134:34 36:38]
  wire  _GEN_5 = _r_data_T_14 ? w_data[4] : FCSR_NV_REG; // @[CSRRegFile.scala 102:30 135:34 37:38]
  wire [2:0] _GEN_6 = _r_data_T_14 ? FCSR_FRM_REG : _GEN_0; // @[CSRRegFile.scala 102:30 38:38]
  wire  _GEN_7 = _r_data_T_18 ? w_data[0] : _GEN_1; // @[CSRRegFile.scala 102:30 123:34]
  wire  _GEN_8 = _r_data_T_18 ? w_data[1] : _GEN_2; // @[CSRRegFile.scala 102:30 124:34]
  wire  _GEN_9 = _r_data_T_18 ? w_data[2] : _GEN_3; // @[CSRRegFile.scala 102:30 125:34]
  wire  _GEN_10 = _r_data_T_18 ? w_data[3] : _GEN_4; // @[CSRRegFile.scala 102:30 126:34]
  wire  _GEN_11 = _r_data_T_18 ? w_data[4] : _GEN_5; // @[CSRRegFile.scala 102:30 127:34]
  wire [2:0] _GEN_12 = _r_data_T_18 ? w_data[7:5] : _GEN_6; // @[CSRRegFile.scala 102:30 128:34]
  wire [31:0] _GEN_13 = _r_data_T_12 ? w_data : MIE_REG; // @[CSRRegFile.scala 102:30 120:34 23:38]
  wire  _GEN_14 = _r_data_T_12 ? FCSR_NX_REG : _GEN_7; // @[CSRRegFile.scala 102:30 33:38]
  wire  _GEN_15 = _r_data_T_12 ? FCSR_UF_REG : _GEN_8; // @[CSRRegFile.scala 102:30 34:38]
  wire  _GEN_16 = _r_data_T_12 ? FCSR_OF_REG : _GEN_9; // @[CSRRegFile.scala 102:30 35:38]
  wire  _GEN_17 = _r_data_T_12 ? FCSR_DZ_REG : _GEN_10; // @[CSRRegFile.scala 102:30 36:38]
  wire  _GEN_18 = _r_data_T_12 ? FCSR_NV_REG : _GEN_11; // @[CSRRegFile.scala 102:30 37:38]
  wire [2:0] _GEN_19 = _r_data_T_12 ? FCSR_FRM_REG : _GEN_12; // @[CSRRegFile.scala 102:30 38:38]
  wire [31:0] _GEN_20 = _r_data_T_10 ? w_data : MEPC_REG; // @[CSRRegFile.scala 102:30 117:34 22:38]
  wire [31:0] _GEN_21 = _r_data_T_10 ? MIE_REG : _GEN_13; // @[CSRRegFile.scala 102:30 23:38]
  wire  _GEN_22 = _r_data_T_10 ? FCSR_NX_REG : _GEN_14; // @[CSRRegFile.scala 102:30 33:38]
  wire  _GEN_23 = _r_data_T_10 ? FCSR_UF_REG : _GEN_15; // @[CSRRegFile.scala 102:30 34:38]
  wire  _GEN_24 = _r_data_T_10 ? FCSR_OF_REG : _GEN_16; // @[CSRRegFile.scala 102:30 35:38]
  wire  _GEN_25 = _r_data_T_10 ? FCSR_DZ_REG : _GEN_17; // @[CSRRegFile.scala 102:30 36:38]
  wire  _GEN_26 = _r_data_T_10 ? FCSR_NV_REG : _GEN_18; // @[CSRRegFile.scala 102:30 37:38]
  wire [2:0] _GEN_27 = _r_data_T_10 ? FCSR_FRM_REG : _GEN_19; // @[CSRRegFile.scala 102:30 38:38]
  wire [31:0] _GEN_28 = _r_data_T_8 ? w_data : MTVEC_REG; // @[CSRRegFile.scala 102:30 114:34 21:38]
  wire [31:0] _GEN_29 = _r_data_T_8 ? MEPC_REG : _GEN_20; // @[CSRRegFile.scala 102:30 22:38]
  wire [31:0] _GEN_30 = _r_data_T_8 ? MIE_REG : _GEN_21; // @[CSRRegFile.scala 102:30 23:38]
  wire  _GEN_31 = _r_data_T_8 ? FCSR_NX_REG : _GEN_22; // @[CSRRegFile.scala 102:30 33:38]
  wire  _GEN_32 = _r_data_T_8 ? FCSR_UF_REG : _GEN_23; // @[CSRRegFile.scala 102:30 34:38]
  wire  _GEN_33 = _r_data_T_8 ? FCSR_OF_REG : _GEN_24; // @[CSRRegFile.scala 102:30 35:38]
  wire  _GEN_34 = _r_data_T_8 ? FCSR_DZ_REG : _GEN_25; // @[CSRRegFile.scala 102:30 36:38]
  wire  _GEN_35 = _r_data_T_8 ? FCSR_NV_REG : _GEN_26; // @[CSRRegFile.scala 102:30 37:38]
  wire [2:0] _GEN_36 = _r_data_T_8 ? FCSR_FRM_REG : _GEN_27; // @[CSRRegFile.scala 102:30 38:38]
  assign io_CSR_o_data = 12'h3 == io_CSR_i_addr ? FCSR_WIRE : _r_data_T_17; // @[Mux.scala 81:58]
  assign io_FCSR_nx = FCSR_NX_REG; // @[CSRRegFile.scala 45:29]
  assign io_FCSR_uf = FCSR_UF_REG; // @[CSRRegFile.scala 46:29]
  assign io_FCSR_of = FCSR_OF_REG; // @[CSRRegFile.scala 47:29]
  assign io_FCSR_dz = FCSR_DZ_REG; // @[CSRRegFile.scala 48:29]
  assign io_FCSR_nv = FCSR_NV_REG; // @[CSRRegFile.scala 49:29]
  assign io_FCSR_frm = FCSR_FRM_REG; // @[CSRRegFile.scala 50:29]
  always @(posedge clock) begin
    if (reset) begin // @[CSRRegFile.scala 18:38]
      MISA_REG <= 32'h0; // @[CSRRegFile.scala 18:38]
    end else begin
      MISA_REG <= io_MISA_i_value; // @[CSRRegFile.scala 41:29]
    end
    if (reset) begin // @[CSRRegFile.scala 19:38]
      MHARTID_REG <= 32'h0; // @[CSRRegFile.scala 19:38]
    end else begin
      MHARTID_REG <= io_MHARTID_i_value; // @[CSRRegFile.scala 42:29]
    end
    if (reset) begin // @[CSRRegFile.scala 20:38]
      MCAUSE_REG <= 32'h0; // @[CSRRegFile.scala 20:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (_r_data_T_6) begin // @[CSRRegFile.scala 102:30]
          MCAUSE_REG <= w_data; // @[CSRRegFile.scala 111:34]
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 21:38]
      MTVEC_REG <= 32'h0; // @[CSRRegFile.scala 21:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          MTVEC_REG <= _GEN_28;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 22:38]
      MEPC_REG <= 32'h0; // @[CSRRegFile.scala 22:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          MEPC_REG <= _GEN_29;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 23:38]
      MIE_REG <= 32'h0; // @[CSRRegFile.scala 23:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          MIE_REG <= _GEN_30;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 26:38]
      MSTATUS_TW_REG <= 1'h0; // @[CSRRegFile.scala 26:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (_r_data_T_4) begin // @[CSRRegFile.scala 102:30]
        MSTATUS_TW_REG <= w_data[21]; // @[CSRRegFile.scala 104:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 27:38]
      MSTATUS_MPRV_REG <= 1'h0; // @[CSRRegFile.scala 27:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (_r_data_T_4) begin // @[CSRRegFile.scala 102:30]
        MSTATUS_MPRV_REG <= w_data[17]; // @[CSRRegFile.scala 105:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 28:38]
      MSTATUS_MPP_REG <= 2'h0; // @[CSRRegFile.scala 28:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (_r_data_T_4) begin // @[CSRRegFile.scala 102:30]
        MSTATUS_MPP_REG <= w_data[12:11]; // @[CSRRegFile.scala 106:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 29:38]
      MSTATUS_MPIE_REG <= 1'h0; // @[CSRRegFile.scala 29:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (_r_data_T_4) begin // @[CSRRegFile.scala 102:30]
        MSTATUS_MPIE_REG <= w_data[7]; // @[CSRRegFile.scala 107:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 30:38]
      MSTATUS_MIE_REG <= 1'h0; // @[CSRRegFile.scala 30:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (_r_data_T_4) begin // @[CSRRegFile.scala 102:30]
        MSTATUS_MIE_REG <= w_data[3]; // @[CSRRegFile.scala 108:34]
      end
    end
    if (reset) begin // @[CSRRegFile.scala 33:38]
      FCSR_NX_REG <= 1'h0; // @[CSRRegFile.scala 33:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          FCSR_NX_REG <= _GEN_31;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 34:38]
      FCSR_UF_REG <= 1'h0; // @[CSRRegFile.scala 34:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          FCSR_UF_REG <= _GEN_32;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 35:38]
      FCSR_OF_REG <= 1'h0; // @[CSRRegFile.scala 35:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          FCSR_OF_REG <= _GEN_33;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 36:38]
      FCSR_DZ_REG <= 1'h0; // @[CSRRegFile.scala 36:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          FCSR_DZ_REG <= _GEN_34;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 37:38]
      FCSR_NV_REG <= 1'h0; // @[CSRRegFile.scala 37:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          FCSR_NV_REG <= _GEN_35;
        end
      end
    end
    if (reset) begin // @[CSRRegFile.scala 38:38]
      FCSR_FRM_REG <= 3'h0; // @[CSRRegFile.scala 38:38]
    end else if (io_CSR_i_w_en) begin // @[CSRRegFile.scala 101:24]
      if (!(_r_data_T_4)) begin // @[CSRRegFile.scala 102:30]
        if (!(_r_data_T_6)) begin // @[CSRRegFile.scala 102:30]
          FCSR_FRM_REG <= _GEN_36;
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
  MHARTID_REG = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  MCAUSE_REG = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  MTVEC_REG = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  MEPC_REG = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  MIE_REG = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  MSTATUS_TW_REG = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  MSTATUS_MPRV_REG = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  MSTATUS_MPP_REG = _RAND_8[1:0];
  _RAND_9 = {1{`RANDOM}};
  MSTATUS_MPIE_REG = _RAND_9[0:0];
  _RAND_10 = {1{`RANDOM}};
  MSTATUS_MIE_REG = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  FCSR_NX_REG = _RAND_11[0:0];
  _RAND_12 = {1{`RANDOM}};
  FCSR_UF_REG = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  FCSR_OF_REG = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  FCSR_DZ_REG = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  FCSR_NV_REG = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  FCSR_FRM_REG = _RAND_16[2:0];
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
  output [31:0] io_fcsr_o_data
);
  wire  csrRegFile_clock; // @[CSR.scala 20:28]
  wire  csrRegFile_reset; // @[CSR.scala 20:28]
  wire [31:0] csrRegFile_io_MISA_i_value; // @[CSR.scala 20:28]
  wire [31:0] csrRegFile_io_MHARTID_i_value; // @[CSR.scala 20:28]
  wire [1:0] csrRegFile_io_CSR_i_opr; // @[CSR.scala 20:28]
  wire [31:0] csrRegFile_io_CSR_o_data; // @[CSR.scala 20:28]
  wire [31:0] csrRegFile_io_CSR_i_data; // @[CSR.scala 20:28]
  wire [11:0] csrRegFile_io_CSR_i_addr; // @[CSR.scala 20:28]
  wire  csrRegFile_io_CSR_i_w_en; // @[CSR.scala 20:28]
  wire  csrRegFile_io_FCSR_nx; // @[CSR.scala 20:28]
  wire  csrRegFile_io_FCSR_uf; // @[CSR.scala 20:28]
  wire  csrRegFile_io_FCSR_of; // @[CSR.scala 20:28]
  wire  csrRegFile_io_FCSR_dz; // @[CSR.scala 20:28]
  wire  csrRegFile_io_FCSR_nv; // @[CSR.scala 20:28]
  wire [2:0] csrRegFile_io_FCSR_frm; // @[CSR.scala 20:28]
  wire [2:0] io_fcsr_o_data_lo = {csrRegFile_io_FCSR_of,csrRegFile_io_FCSR_uf,csrRegFile_io_FCSR_nx}; // @[Cat.scala 33:92]
  wire [28:0] io_fcsr_o_data_hi = {24'h0,csrRegFile_io_FCSR_frm,csrRegFile_io_FCSR_nv,csrRegFile_io_FCSR_dz}; // @[Cat.scala 33:92]
  CSRRegFile csrRegFile ( // @[CSR.scala 20:28]
    .clock(csrRegFile_clock),
    .reset(csrRegFile_reset),
    .io_MISA_i_value(csrRegFile_io_MISA_i_value),
    .io_MHARTID_i_value(csrRegFile_io_MHARTID_i_value),
    .io_CSR_i_opr(csrRegFile_io_CSR_i_opr),
    .io_CSR_o_data(csrRegFile_io_CSR_o_data),
    .io_CSR_i_data(csrRegFile_io_CSR_i_data),
    .io_CSR_i_addr(csrRegFile_io_CSR_i_addr),
    .io_CSR_i_w_en(csrRegFile_io_CSR_i_w_en),
    .io_FCSR_nx(csrRegFile_io_FCSR_nx),
    .io_FCSR_uf(csrRegFile_io_FCSR_uf),
    .io_FCSR_of(csrRegFile_io_FCSR_of),
    .io_FCSR_dz(csrRegFile_io_FCSR_dz),
    .io_FCSR_nv(csrRegFile_io_FCSR_nv),
    .io_FCSR_frm(csrRegFile_io_FCSR_frm)
  );
  assign io_o_data = csrRegFile_io_CSR_o_data; // @[CSR.scala 30:37]
  assign io_fcsr_o_data = {io_fcsr_o_data_hi,io_fcsr_o_data_lo}; // @[Cat.scala 33:92]
  assign csrRegFile_clock = clock;
  assign csrRegFile_reset = reset;
  assign csrRegFile_io_MISA_i_value = 32'h0; // @[CSR.scala 25:37]
  assign csrRegFile_io_MHARTID_i_value = 32'h0; // @[CSR.scala 26:37]
  assign csrRegFile_io_CSR_i_opr = io_i_opr[1:0]; // @[CSR.scala 24:37]
  assign csrRegFile_io_CSR_i_data = io_i_opr[2] ? {{27'd0}, io_i_imm} : io_i_data; // @[CSR.scala 23:43]
  assign csrRegFile_io_CSR_i_addr = io_i_addr; // @[CSR.scala 27:37]
  assign csrRegFile_io_CSR_i_w_en = io_i_w_en; // @[CSR.scala 28:37]
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
  wire  _hazard_DecEx_T = io_regWrExecute & io_csrInstDecode; // @[CSRController.scala 33:44]
  wire  _hazard_DecEx_T_3 = |io_rdSelExecute; // @[CSRController.scala 36:44]
  wire  _hazard_DecEx_T_4 = _hazard_DecEx_T & _hazard_DecEx_T_3; // @[CSRController.scala 35:46]
  wire  _hazard_DecEx_T_5 = ~io_csrWrExecute; // @[CSRController.scala 37:28]
  wire  _hazard_DecEx_T_6 = _hazard_DecEx_T_4 & _hazard_DecEx_T_5; // @[CSRController.scala 36:48]
  wire  _hazard_DecEx_T_7 = io_rdSelExecute == io_rs1SelDecode; // @[CSRController.scala 38:44]
  wire  hazard_DecEx = _hazard_DecEx_T_6 & _hazard_DecEx_T_7; // @[CSRController.scala 37:45]
  wire  _hazard_DecMem_T = io_regWrMemory & io_csrInstDecode; // @[CSRController.scala 42:44]
  wire  _hazard_DecMem_T_3 = |io_rdSelMemory; // @[CSRController.scala 45:43]
  wire  _hazard_DecMem_T_4 = _hazard_DecMem_T & _hazard_DecMem_T_3; // @[CSRController.scala 44:46]
  wire  _hazard_DecMem_T_5 = ~io_csrWrMemory; // @[CSRController.scala 46:28]
  wire  _hazard_DecMem_T_6 = _hazard_DecMem_T_4 & _hazard_DecMem_T_5; // @[CSRController.scala 45:47]
  wire  _hazard_DecMem_T_7 = io_rdSelMemory == io_rs1SelDecode; // @[CSRController.scala 47:43]
  wire  _hazard_DecMem_T_8 = _hazard_DecMem_T_6 & _hazard_DecMem_T_7; // @[CSRController.scala 46:44]
  wire  _hazard_DecMem_T_9 = ~hazard_DecEx; // @[CSRController.scala 48:28]
  wire  hazard_DecMem = _hazard_DecMem_T_8 & _hazard_DecMem_T_9; // @[CSRController.scala 47:63]
  wire  _hazard_DecWb_T = io_regWrWriteback & io_csrInstDecode; // @[CSRController.scala 52:46]
  wire  _hazard_DecWb_T_3 = |io_rdSelWriteback; // @[CSRController.scala 55:46]
  wire  _hazard_DecWb_T_4 = _hazard_DecWb_T & _hazard_DecWb_T_3; // @[CSRController.scala 54:46]
  wire  _hazard_DecWb_T_5 = ~io_csrWrWriteback; // @[CSRController.scala 56:28]
  wire  _hazard_DecWb_T_6 = _hazard_DecWb_T_4 & _hazard_DecWb_T_5; // @[CSRController.scala 55:50]
  wire  _hazard_DecWb_T_7 = io_rdSelWriteback == io_rs1SelDecode; // @[CSRController.scala 57:46]
  wire  _hazard_DecWb_T_8 = _hazard_DecWb_T_6 & _hazard_DecWb_T_7; // @[CSRController.scala 56:47]
  wire  _hazard_DecWb_T_10 = _hazard_DecWb_T_8 & _hazard_DecMem_T_9; // @[CSRController.scala 57:66]
  wire  hazard_DecWb = _hazard_DecWb_T_10 & hazard_DecMem; // @[CSRController.scala 58:42]
  wire  _csrHazard_DecEx_T_5 = _hazard_DecEx_T_4 & io_csrWrExecute; // @[CSRController.scala 66:48]
  wire  csrHazard_DecEx = _csrHazard_DecEx_T_5 & _hazard_DecEx_T_7; // @[CSRController.scala 67:44]
  wire  _csrHazard_DecMem_T_5 = _hazard_DecMem_T_4 & io_csrWrMemory; // @[CSRController.scala 75:47]
  wire  _csrHazard_DecMem_T_7 = _csrHazard_DecMem_T_5 & _hazard_DecMem_T_7; // @[CSRController.scala 76:43]
  wire  _csrHazard_DecMem_T_8 = ~csrHazard_DecEx; // @[CSRController.scala 78:28]
  wire  csrHazard_DecMem = _csrHazard_DecMem_T_7 & _csrHazard_DecMem_T_8; // @[CSRController.scala 77:63]
  wire  _csrHazard_DecWb_T_5 = _hazard_DecWb_T_4 & io_csrWrWriteback; // @[CSRController.scala 85:50]
  wire  _csrHazard_DecWb_T_7 = _csrHazard_DecWb_T_5 & _hazard_DecWb_T_7; // @[CSRController.scala 86:46]
  wire  _csrHazard_DecWb_T_9 = _csrHazard_DecWb_T_7 & _csrHazard_DecMem_T_8; // @[CSRController.scala 87:66]
  wire  csrHazard_DecWb = _csrHazard_DecWb_T_9 & csrHazard_DecMem; // @[CSRController.scala 88:45]
  wire [1:0] _io_forwardRS1_T_3 = hazard_DecMem ? 2'h2 : {{1'd0}, hazard_DecEx}; // @[Mux.scala 81:58]
  wire [1:0] _io_forwardRS1_T_5 = hazard_DecWb ? 2'h3 : _io_forwardRS1_T_3; // @[Mux.scala 81:58]
  wire [2:0] _io_forwardRS1_T_7 = csrHazard_DecEx ? 3'h4 : {{1'd0}, _io_forwardRS1_T_5}; // @[Mux.scala 81:58]
  wire [2:0] _io_forwardRS1_T_9 = csrHazard_DecMem ? 3'h5 : _io_forwardRS1_T_7; // @[Mux.scala 81:58]
  assign io_forwardRS1 = csrHazard_DecWb ? 3'h6 : _io_forwardRS1_T_9; // @[Mux.scala 81:58]
endmodule
module HazardUnit(
  input        io_id_ex_memRead,
  input        io_ex_mem_memRead,
  input        io_id_ex_branch,
  input  [4:0] io_id_ex_rd,
  input  [4:0] io_ex_mem_rd,
  input  [4:0] io_id_rs1,
  input  [4:0] io_id_rs2,
  input        io_taken,
  input  [1:0] io_jump,
  input        io_branch,
  output       io_if_reg_write,
  output       io_pc_write,
  output       io_ctl_mux,
  output       io_ifid_flush,
  output       io_take_branch
);
  wire  _T_3 = io_id_ex_rd == io_id_rs1 | io_id_ex_rd == io_id_rs2; // @[HazardUnit.scala 35:34]
  wire  _T_4 = (io_id_ex_memRead | io_branch) & _T_3; // @[HazardUnit.scala 34:37]
  wire  _T_5 = io_id_ex_rd != 5'h0; // @[HazardUnit.scala 36:21]
  wire  _T_10 = _T_5 & io_id_rs2 != 5'h0; // @[HazardUnit.scala 37:28]
  wire  _T_11 = io_id_ex_rd != 5'h0 & io_id_rs1 != 5'h0 | _T_10; // @[HazardUnit.scala 36:51]
  wire  _T_12 = _T_4 & _T_11; // @[HazardUnit.scala 35:65]
  wire  _T_13 = ~io_id_ex_branch; // @[HazardUnit.scala 38:7]
  wire  _T_14 = _T_12 & _T_13; // @[HazardUnit.scala 37:51]
  wire  _GEN_0 = _T_14 ? 1'h0 : 1'h1; // @[HazardUnit.scala 26:14 40:3 41:16]
  assign io_if_reg_write = io_ex_mem_memRead & io_branch & (io_ex_mem_rd == io_id_rs1 | io_ex_mem_rd == io_id_rs2) ? 1'h0
     : _GEN_0; // @[HazardUnit.scala 47:101 48:16]
  assign io_pc_write = io_ex_mem_memRead & io_branch & (io_ex_mem_rd == io_id_rs1 | io_ex_mem_rd == io_id_rs2) ? 1'h0 :
    _GEN_0; // @[HazardUnit.scala 47:101 48:16]
  assign io_ctl_mux = io_ex_mem_memRead & io_branch & (io_ex_mem_rd == io_id_rs1 | io_ex_mem_rd == io_id_rs2) ? 1'h0 :
    _GEN_0; // @[HazardUnit.scala 47:101 48:16]
  assign io_ifid_flush = io_taken | io_jump != 2'h0; // @[HazardUnit.scala 55:17]
  assign io_take_branch = io_ex_mem_memRead & io_branch & (io_ex_mem_rd == io_id_rs1 | io_ex_mem_rd == io_id_rs2) ? 1'h0
     : _GEN_0; // @[HazardUnit.scala 47:101 48:16]
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
  wire  _signals_T_25 = _signals_T_9 ? 1'h0 : _signals_T_11; // @[Lookup.scala 34:39]
  wire  _signals_T_26 = _signals_T_7 ? 1'h0 : _signals_T_25; // @[Lookup.scala 34:39]
  wire  _signals_T_27 = _signals_T_5 ? 1'h0 : _signals_T_26; // @[Lookup.scala 34:39]
  wire  _signals_T_28 = _signals_T_3 ? 1'h0 : _signals_T_27; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_29 = _signals_T_19 ? 2'h2 : 2'h0; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_30 = _signals_T_17 ? 2'h2 : _signals_T_29; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_31 = _signals_T_15 ? 2'h0 : _signals_T_30; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_32 = _signals_T_13 ? 2'h0 : _signals_T_31; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_33 = _signals_T_11 ? 2'h0 : _signals_T_32; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_34 = _signals_T_9 ? 2'h0 : _signals_T_33; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_35 = _signals_T_7 ? 2'h1 : _signals_T_34; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_36 = _signals_T_5 ? 2'h0 : _signals_T_35; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_37 = _signals_T_3 ? 2'h0 : _signals_T_36; // @[Lookup.scala 34:39]
  wire  _signals_T_42 = _signals_T_11 ? 1'h0 : _signals_T_13 | (_signals_T_15 | (_signals_T_17 | _signals_T_19)); // @[Lookup.scala 34:39]
  wire  _signals_T_43 = _signals_T_9 ? 1'h0 : _signals_T_42; // @[Lookup.scala 34:39]
  wire  _signals_T_54 = _signals_T_5 ? 1'h0 : _signals_T_7; // @[Lookup.scala 34:39]
  wire  _signals_T_55 = _signals_T_3 ? 1'h0 : _signals_T_54; // @[Lookup.scala 34:39]
  wire  _signals_T_62 = _signals_T_7 ? 1'h0 : _signals_T_9; // @[Lookup.scala 34:39]
  wire  _signals_T_63 = _signals_T_5 ? 1'h0 : _signals_T_62; // @[Lookup.scala 34:39]
  wire  _signals_T_64 = _signals_T_3 ? 1'h0 : _signals_T_63; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_75 = _signals_T_17 ? 2'h1 : _signals_T_29; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_76 = _signals_T_15 ? 2'h0 : _signals_T_75; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_77 = _signals_T_13 ? 2'h0 : _signals_T_76; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_78 = _signals_T_11 ? 2'h0 : _signals_T_77; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_79 = _signals_T_9 ? 2'h0 : _signals_T_78; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_80 = _signals_T_7 ? 2'h0 : _signals_T_79; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_81 = _signals_T_5 ? 2'h0 : _signals_T_80; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_82 = _signals_T_3 ? 2'h0 : _signals_T_81; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_90 = _signals_T_5 ? 2'h2 : 2'h0; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_91 = _signals_T_3 ? 2'h2 : _signals_T_90; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_95 = _signals_T_13 ? 2'h2 : {{1'd0}, _signals_T_15}; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_96 = _signals_T_11 ? 2'h0 : _signals_T_95; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_97 = _signals_T_9 ? 2'h0 : _signals_T_96; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_98 = _signals_T_7 ? 2'h0 : _signals_T_97; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_99 = _signals_T_5 ? 2'h0 : _signals_T_98; // @[Lookup.scala 34:39]
  wire [1:0] _signals_T_100 = _signals_T_3 ? 2'h0 : _signals_T_99; // @[Lookup.scala 34:39]
  assign io_aluSrc = _signals_T_1 | _signals_T_28; // @[Lookup.scala 34:39]
  assign io_memToReg = _signals_T_1 ? 2'h0 : _signals_T_37; // @[Lookup.scala 34:39]
  assign io_regWrite = _signals_T_1 | (_signals_T_3 | (_signals_T_5 | (_signals_T_7 | _signals_T_43))); // @[Lookup.scala 34:39]
  assign io_memRead = _signals_T_1 ? 1'h0 : _signals_T_55; // @[Lookup.scala 34:39]
  assign io_memWrite = _signals_T_1 ? 1'h0 : _signals_T_64; // @[Lookup.scala 34:39]
  assign io_branch = _signals_T_1 ? 1'h0 : _signals_T_28; // @[Lookup.scala 34:39]
  assign io_aluOp = _signals_T_1 ? 2'h2 : _signals_T_91; // @[Lookup.scala 34:39]
  assign io_jump = _signals_T_1 ? 2'h0 : _signals_T_82; // @[Lookup.scala 34:39]
  assign io_aluSrc1 = _signals_T_1 ? 2'h0 : _signals_T_100; // @[Lookup.scala 34:39]
endmodule
module Registers(
  input         clock,
  input         reset,
  input  [4:0]  io_readAddress_0,
  input  [4:0]  io_readAddress_1,
  input         io_writeEnable,
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
  reg [31:0] reg_0; // @[Registers.scala 14:20]
  reg [31:0] reg_1; // @[Registers.scala 14:20]
  reg [31:0] reg_2; // @[Registers.scala 14:20]
  reg [31:0] reg_3; // @[Registers.scala 14:20]
  reg [31:0] reg_4; // @[Registers.scala 14:20]
  reg [31:0] reg_5; // @[Registers.scala 14:20]
  reg [31:0] reg_6; // @[Registers.scala 14:20]
  reg [31:0] reg_7; // @[Registers.scala 14:20]
  reg [31:0] reg_8; // @[Registers.scala 14:20]
  reg [31:0] reg_9; // @[Registers.scala 14:20]
  reg [31:0] reg_10; // @[Registers.scala 14:20]
  reg [31:0] reg_11; // @[Registers.scala 14:20]
  reg [31:0] reg_12; // @[Registers.scala 14:20]
  reg [31:0] reg_13; // @[Registers.scala 14:20]
  reg [31:0] reg_14; // @[Registers.scala 14:20]
  reg [31:0] reg_15; // @[Registers.scala 14:20]
  reg [31:0] reg_16; // @[Registers.scala 14:20]
  reg [31:0] reg_17; // @[Registers.scala 14:20]
  reg [31:0] reg_18; // @[Registers.scala 14:20]
  reg [31:0] reg_19; // @[Registers.scala 14:20]
  reg [31:0] reg_20; // @[Registers.scala 14:20]
  reg [31:0] reg_21; // @[Registers.scala 14:20]
  reg [31:0] reg_22; // @[Registers.scala 14:20]
  reg [31:0] reg_23; // @[Registers.scala 14:20]
  reg [31:0] reg_24; // @[Registers.scala 14:20]
  reg [31:0] reg_25; // @[Registers.scala 14:20]
  reg [31:0] reg_26; // @[Registers.scala 14:20]
  reg [31:0] reg_27; // @[Registers.scala 14:20]
  reg [31:0] reg_28; // @[Registers.scala 14:20]
  reg [31:0] reg_29; // @[Registers.scala 14:20]
  reg [31:0] reg_30; // @[Registers.scala 14:20]
  reg [31:0] reg_31; // @[Registers.scala 14:20]
  wire [31:0] _GEN_65 = 5'h1 == io_readAddress_0 ? reg_1 : reg_0; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_66 = 5'h2 == io_readAddress_0 ? reg_2 : _GEN_65; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_67 = 5'h3 == io_readAddress_0 ? reg_3 : _GEN_66; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_68 = 5'h4 == io_readAddress_0 ? reg_4 : _GEN_67; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_69 = 5'h5 == io_readAddress_0 ? reg_5 : _GEN_68; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_70 = 5'h6 == io_readAddress_0 ? reg_6 : _GEN_69; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_71 = 5'h7 == io_readAddress_0 ? reg_7 : _GEN_70; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_72 = 5'h8 == io_readAddress_0 ? reg_8 : _GEN_71; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_73 = 5'h9 == io_readAddress_0 ? reg_9 : _GEN_72; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_74 = 5'ha == io_readAddress_0 ? reg_10 : _GEN_73; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_75 = 5'hb == io_readAddress_0 ? reg_11 : _GEN_74; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_76 = 5'hc == io_readAddress_0 ? reg_12 : _GEN_75; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_77 = 5'hd == io_readAddress_0 ? reg_13 : _GEN_76; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_78 = 5'he == io_readAddress_0 ? reg_14 : _GEN_77; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_79 = 5'hf == io_readAddress_0 ? reg_15 : _GEN_78; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_80 = 5'h10 == io_readAddress_0 ? reg_16 : _GEN_79; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_81 = 5'h11 == io_readAddress_0 ? reg_17 : _GEN_80; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_82 = 5'h12 == io_readAddress_0 ? reg_18 : _GEN_81; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_83 = 5'h13 == io_readAddress_0 ? reg_19 : _GEN_82; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_84 = 5'h14 == io_readAddress_0 ? reg_20 : _GEN_83; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_85 = 5'h15 == io_readAddress_0 ? reg_21 : _GEN_84; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_86 = 5'h16 == io_readAddress_0 ? reg_22 : _GEN_85; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_87 = 5'h17 == io_readAddress_0 ? reg_23 : _GEN_86; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_88 = 5'h18 == io_readAddress_0 ? reg_24 : _GEN_87; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_89 = 5'h19 == io_readAddress_0 ? reg_25 : _GEN_88; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_90 = 5'h1a == io_readAddress_0 ? reg_26 : _GEN_89; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_91 = 5'h1b == io_readAddress_0 ? reg_27 : _GEN_90; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_92 = 5'h1c == io_readAddress_0 ? reg_28 : _GEN_91; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_93 = 5'h1d == io_readAddress_0 ? reg_29 : _GEN_92; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_94 = 5'h1e == io_readAddress_0 ? reg_30 : _GEN_93; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_95 = 5'h1f == io_readAddress_0 ? reg_31 : _GEN_94; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_98 = 5'h1 == io_readAddress_1 ? reg_1 : reg_0; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_99 = 5'h2 == io_readAddress_1 ? reg_2 : _GEN_98; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_100 = 5'h3 == io_readAddress_1 ? reg_3 : _GEN_99; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_101 = 5'h4 == io_readAddress_1 ? reg_4 : _GEN_100; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_102 = 5'h5 == io_readAddress_1 ? reg_5 : _GEN_101; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_103 = 5'h6 == io_readAddress_1 ? reg_6 : _GEN_102; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_104 = 5'h7 == io_readAddress_1 ? reg_7 : _GEN_103; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_105 = 5'h8 == io_readAddress_1 ? reg_8 : _GEN_104; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_106 = 5'h9 == io_readAddress_1 ? reg_9 : _GEN_105; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_107 = 5'ha == io_readAddress_1 ? reg_10 : _GEN_106; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_108 = 5'hb == io_readAddress_1 ? reg_11 : _GEN_107; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_109 = 5'hc == io_readAddress_1 ? reg_12 : _GEN_108; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_110 = 5'hd == io_readAddress_1 ? reg_13 : _GEN_109; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_111 = 5'he == io_readAddress_1 ? reg_14 : _GEN_110; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_112 = 5'hf == io_readAddress_1 ? reg_15 : _GEN_111; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_113 = 5'h10 == io_readAddress_1 ? reg_16 : _GEN_112; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_114 = 5'h11 == io_readAddress_1 ? reg_17 : _GEN_113; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_115 = 5'h12 == io_readAddress_1 ? reg_18 : _GEN_114; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_116 = 5'h13 == io_readAddress_1 ? reg_19 : _GEN_115; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_117 = 5'h14 == io_readAddress_1 ? reg_20 : _GEN_116; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_118 = 5'h15 == io_readAddress_1 ? reg_21 : _GEN_117; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_119 = 5'h16 == io_readAddress_1 ? reg_22 : _GEN_118; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_120 = 5'h17 == io_readAddress_1 ? reg_23 : _GEN_119; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_121 = 5'h18 == io_readAddress_1 ? reg_24 : _GEN_120; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_122 = 5'h19 == io_readAddress_1 ? reg_25 : _GEN_121; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_123 = 5'h1a == io_readAddress_1 ? reg_26 : _GEN_122; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_124 = 5'h1b == io_readAddress_1 ? reg_27 : _GEN_123; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_125 = 5'h1c == io_readAddress_1 ? reg_28 : _GEN_124; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_126 = 5'h1d == io_readAddress_1 ? reg_29 : _GEN_125; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_127 = 5'h1e == io_readAddress_1 ? reg_30 : _GEN_126; // @[Registers.scala 23:{22,22}]
  wire [31:0] _GEN_128 = 5'h1f == io_readAddress_1 ? reg_31 : _GEN_127; // @[Registers.scala 23:{22,22}]
  assign io_readData_0 = io_readAddress_0 == 5'h0 ? 32'h0 : _GEN_95; // @[Registers.scala 20:37 21:22 23:22]
  assign io_readData_1 = io_readAddress_1 == 5'h0 ? 32'h0 : _GEN_128; // @[Registers.scala 20:37 21:22 23:22]
  always @(posedge clock) begin
    if (reset) begin // @[Registers.scala 14:20]
      reg_0 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h0 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_0 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_1 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h1 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_1 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_2 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h2 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_2 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_3 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h3 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_3 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_4 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h4 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_4 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_5 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h5 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_5 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_6 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h6 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_6 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_7 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h7 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_7 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_8 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h8 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_8 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_9 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h9 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_9 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_10 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'ha == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_10 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_11 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'hb == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_11 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_12 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'hc == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_12 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_13 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'hd == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_13 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_14 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'he == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_14 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_15 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'hf == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_15 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_16 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h10 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_16 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_17 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h11 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_17 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_18 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h12 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_18 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_19 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h13 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_19 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_20 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h14 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_20 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_21 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h15 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_21 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_22 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h16 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_22 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_23 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h17 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_23 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_24 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h18 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_24 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_25 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h19 == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_25 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_26 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h1a == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_26 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_27 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h1b == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_27 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_28 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h1c == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_28 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_29 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h1d == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_29 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_30 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h1e == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_30 <= io_writeData; // @[Registers.scala 17:26]
      end
    end
    if (reset) begin // @[Registers.scala 14:20]
      reg_31 <= 32'h0; // @[Registers.scala 14:20]
    end else if (io_writeEnable) begin // @[Registers.scala 16:24]
      if (5'h1f == io_writeAddress) begin // @[Registers.scala 17:26]
        reg_31 <= io_writeData; // @[Registers.scala 17:26]
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
  reg_0 = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  reg_1 = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  reg_2 = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  reg_3 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  reg_4 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  reg_5 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  reg_6 = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  reg_7 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  reg_8 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  reg_9 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  reg_10 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  reg_11 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  reg_12 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  reg_13 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  reg_14 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  reg_15 = _RAND_15[31:0];
  _RAND_16 = {1{`RANDOM}};
  reg_16 = _RAND_16[31:0];
  _RAND_17 = {1{`RANDOM}};
  reg_17 = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  reg_18 = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  reg_19 = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  reg_20 = _RAND_20[31:0];
  _RAND_21 = {1{`RANDOM}};
  reg_21 = _RAND_21[31:0];
  _RAND_22 = {1{`RANDOM}};
  reg_22 = _RAND_22[31:0];
  _RAND_23 = {1{`RANDOM}};
  reg_23 = _RAND_23[31:0];
  _RAND_24 = {1{`RANDOM}};
  reg_24 = _RAND_24[31:0];
  _RAND_25 = {1{`RANDOM}};
  reg_25 = _RAND_25[31:0];
  _RAND_26 = {1{`RANDOM}};
  reg_26 = _RAND_26[31:0];
  _RAND_27 = {1{`RANDOM}};
  reg_27 = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  reg_28 = _RAND_28[31:0];
  _RAND_29 = {1{`RANDOM}};
  reg_29 = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  reg_30 = _RAND_30[31:0];
  _RAND_31 = {1{`RANDOM}};
  reg_31 = _RAND_31[31:0];
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
  wire  _T_10 = opcode == 7'h3 | opcode == 7'hf | opcode == 7'h13 | opcode == 7'h1b | opcode == 7'h67 | opcode == 7'h73; // @[ImmediateGen.scala 15:97]
  wire [11:0] imm_i = io_instruction[31:20]; // @[ImmediateGen.scala 17:31]
  wire [19:0] _ext_i_T_2 = imm_i[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 77:12]
  wire [31:0] ext_i = {_ext_i_T_2,imm_i}; // @[Cat.scala 33:92]
  wire [19:0] imm_u = io_instruction[31:12]; // @[ImmediateGen.scala 24:33]
  wire [31:0] ext_u = {imm_u,12'h0}; // @[Cat.scala 33:92]
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
  wire [31:0] _GEN_0 = opcode == 7'h63 ? ext_sb : ext_uj; // @[ImmediateGen.scala 35:32 43:14 55:12]
  wire [31:0] _GEN_1 = opcode == 7'h23 ? ext_s : _GEN_0; // @[ImmediateGen.scala 29:32 32:14]
  wire [31:0] _GEN_2 = opcode == 7'h17 | opcode == 7'h37 ? ext_u : _GEN_1; // @[ImmediateGen.scala 23:51 26:14]
  assign io_out = _T_10 ? ext_i : _GEN_2; // @[ImmediateGen.scala 16:5 19:12]
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
  input         io_ctl_writeEnable,
  input         io_id_ex_mem_read,
  input         io_ex_mem_mem_read,
  input  [4:0]  io_id_ex_rd,
  input  [4:0]  io_ex_mem_rd,
  input         io_id_ex_branch,
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
  output [31:0] io_immediate,
  output [4:0]  io_writeRegAddress,
  output [31:0] io_readData1,
  output [31:0] io_readData2,
  output [6:0]  io_func7,
  output [2:0]  io_func3,
  output        io_ctl_aluSrc,
  output [1:0]  io_ctl_memToReg,
  output        io_ctl_regWrite,
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
  output [31:0] io_csr_o_data,
  output        io_is_csr,
  output [31:0] io_fscr_o_data,
  output [4:0]  io_rs_addr_0,
  output [4:0]  io_rs_addr_1
);
  wire  csr_clock; // @[InstructionDecode.scala 74:19]
  wire  csr_reset; // @[InstructionDecode.scala 74:19]
  wire [31:0] csr_io_i_data; // @[InstructionDecode.scala 74:19]
  wire [4:0] csr_io_i_imm; // @[InstructionDecode.scala 74:19]
  wire [31:0] csr_io_o_data; // @[InstructionDecode.scala 74:19]
  wire [2:0] csr_io_i_opr; // @[InstructionDecode.scala 74:19]
  wire [11:0] csr_io_i_addr; // @[InstructionDecode.scala 74:19]
  wire  csr_io_i_w_en; // @[InstructionDecode.scala 74:19]
  wire [31:0] csr_io_fcsr_o_data; // @[InstructionDecode.scala 74:19]
  wire  csrController_io_regWrExecute; // @[InstructionDecode.scala 86:29]
  wire [4:0] csrController_io_rdSelExecute; // @[InstructionDecode.scala 86:29]
  wire  csrController_io_csrWrExecute; // @[InstructionDecode.scala 86:29]
  wire  csrController_io_regWrMemory; // @[InstructionDecode.scala 86:29]
  wire [4:0] csrController_io_rdSelMemory; // @[InstructionDecode.scala 86:29]
  wire  csrController_io_csrWrMemory; // @[InstructionDecode.scala 86:29]
  wire  csrController_io_regWrWriteback; // @[InstructionDecode.scala 86:29]
  wire [4:0] csrController_io_rdSelWriteback; // @[InstructionDecode.scala 86:29]
  wire  csrController_io_csrWrWriteback; // @[InstructionDecode.scala 86:29]
  wire [4:0] csrController_io_rs1SelDecode; // @[InstructionDecode.scala 86:29]
  wire  csrController_io_csrInstDecode; // @[InstructionDecode.scala 86:29]
  wire [2:0] csrController_io_forwardRS1; // @[InstructionDecode.scala 86:29]
  wire  hdu_io_id_ex_memRead; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_ex_mem_memRead; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_id_ex_branch; // @[InstructionDecode.scala 101:19]
  wire [4:0] hdu_io_id_ex_rd; // @[InstructionDecode.scala 101:19]
  wire [4:0] hdu_io_ex_mem_rd; // @[InstructionDecode.scala 101:19]
  wire [4:0] hdu_io_id_rs1; // @[InstructionDecode.scala 101:19]
  wire [4:0] hdu_io_id_rs2; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_taken; // @[InstructionDecode.scala 101:19]
  wire [1:0] hdu_io_jump; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_branch; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_if_reg_write; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_pc_write; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_ctl_mux; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_ifid_flush; // @[InstructionDecode.scala 101:19]
  wire  hdu_io_take_branch; // @[InstructionDecode.scala 101:19]
  wire [31:0] control_io_in; // @[InstructionDecode.scala 117:23]
  wire  control_io_aluSrc; // @[InstructionDecode.scala 117:23]
  wire [1:0] control_io_memToReg; // @[InstructionDecode.scala 117:23]
  wire  control_io_regWrite; // @[InstructionDecode.scala 117:23]
  wire  control_io_memRead; // @[InstructionDecode.scala 117:23]
  wire  control_io_memWrite; // @[InstructionDecode.scala 117:23]
  wire  control_io_branch; // @[InstructionDecode.scala 117:23]
  wire [1:0] control_io_aluOp; // @[InstructionDecode.scala 117:23]
  wire [1:0] control_io_jump; // @[InstructionDecode.scala 117:23]
  wire [1:0] control_io_aluSrc1; // @[InstructionDecode.scala 117:23]
  wire  registers_clock; // @[InstructionDecode.scala 136:25]
  wire  registers_reset; // @[InstructionDecode.scala 136:25]
  wire [4:0] registers_io_readAddress_0; // @[InstructionDecode.scala 136:25]
  wire [4:0] registers_io_readAddress_1; // @[InstructionDecode.scala 136:25]
  wire  registers_io_writeEnable; // @[InstructionDecode.scala 136:25]
  wire [4:0] registers_io_writeAddress; // @[InstructionDecode.scala 136:25]
  wire [31:0] registers_io_writeData; // @[InstructionDecode.scala 136:25]
  wire [31:0] registers_io_readData_0; // @[InstructionDecode.scala 136:25]
  wire [31:0] registers_io_readData_1; // @[InstructionDecode.scala 136:25]
  wire [31:0] immediate_io_instruction; // @[InstructionDecode.scala 167:25]
  wire [31:0] immediate_io_out; // @[InstructionDecode.scala 167:25]
  wire  bu_io_branch; // @[InstructionDecode.scala 193:18]
  wire [2:0] bu_io_funct3; // @[InstructionDecode.scala 193:18]
  wire [31:0] bu_io_rd1; // @[InstructionDecode.scala 193:18]
  wire [31:0] bu_io_rd2; // @[InstructionDecode.scala 193:18]
  wire  bu_io_take_branch; // @[InstructionDecode.scala 193:18]
  wire  bu_io_taken; // @[InstructionDecode.scala 193:18]
  wire [31:0] _GEN_2 = io_id_instruction[19:15] == 5'h0 ? 32'h0 : io_writeData; // @[InstructionDecode.scala 148:30 149:20 151:20]
  wire [31:0] _GEN_4 = io_id_instruction[24:20] == 5'h0 ? 32'h0 : io_writeData; // @[InstructionDecode.scala 157:30 158:20 160:20]
  wire  _T_9 = io_id_instruction[19:15] == io_ex_mem_ins[11:7]; // @[InstructionDecode.scala 175:20]
  wire  _T_11 = io_id_instruction[19:15] == io_mem_wb_ins[11:7]; // @[InstructionDecode.scala 177:26]
  wire [31:0] _GEN_6 = io_id_instruction[19:15] == io_mem_wb_ins[11:7] ? io_mem_wb_result : io_readData1; // @[InstructionDecode.scala 177:52 178:14 181:14]
  wire [31:0] _GEN_8 = io_id_instruction[24:20] == io_mem_wb_ins[11:7] ? io_mem_wb_result : io_readData2; // @[InstructionDecode.scala 185:52 186:14 189:14]
  wire  _T_17 = io_id_instruction[19:15] == io_ex_ins[11:7]; // @[InstructionDecode.scala 203:22]
  wire [31:0] _GEN_10 = _T_17 ? io_ex_result : io_readData1; // @[InstructionDecode.scala 209:47 210:14 212:16]
  wire [31:0] _GEN_11 = _T_11 ? io_mem_wb_result : _GEN_10; // @[InstructionDecode.scala 207:52 208:14]
  wire [31:0] _GEN_12 = _T_9 ? io_ex_mem_result : _GEN_11; // @[InstructionDecode.scala 205:54 206:14]
  wire [31:0] j_offset = io_id_instruction[19:15] == io_ex_ins[11:7] ? io_ex_result : _GEN_12; // @[InstructionDecode.scala 203:43 204:16]
  wire [31:0] _io_pcPlusOffset_T_1 = io_pcAddress + io_immediate; // @[InstructionDecode.scala 217:37]
  wire [31:0] _io_pcPlusOffset_T_3 = j_offset + io_immediate; // @[InstructionDecode.scala 219:35]
  wire [31:0] _io_pcPlusOffset_T_5 = io_pcAddress + immediate_io_out; // @[InstructionDecode.scala 222:39]
  wire [31:0] _GEN_14 = io_ctl_jump == 2'h2 ? _io_pcPlusOffset_T_3 : _io_pcPlusOffset_T_5; // @[InstructionDecode.scala 218:35 219:23 222:23]
  wire  _T_32 = io_func3 == 3'h5; // @[InstructionDecode.scala 236:107]
  wire [31:0] _T_35 = io_ex_mem_mem_read ? io_dmem_data : io_ex_mem_result; // @[InstructionDecode.scala 246:15]
  wire [31:0] _csr_io_i_data_T_1 = 3'h1 == csrController_io_forwardRS1 ? io_ex_result : registers_io_readData_1; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_3 = 3'h2 == csrController_io_forwardRS1 ? _T_35 : _csr_io_i_data_T_1; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_5 = 3'h3 == csrController_io_forwardRS1 ? io_writeData : _csr_io_i_data_T_3; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_7 = 3'h4 == csrController_io_forwardRS1 ? io_csr_Ex_data : _csr_io_i_data_T_5; // @[Mux.scala 81:58]
  wire [31:0] _csr_io_i_data_T_9 = 3'h5 == csrController_io_forwardRS1 ? io_csr_Mem_data : _csr_io_i_data_T_7; // @[Mux.scala 81:58]
  CSR csr ( // @[InstructionDecode.scala 74:19]
    .clock(csr_clock),
    .reset(csr_reset),
    .io_i_data(csr_io_i_data),
    .io_i_imm(csr_io_i_imm),
    .io_o_data(csr_io_o_data),
    .io_i_opr(csr_io_i_opr),
    .io_i_addr(csr_io_i_addr),
    .io_i_w_en(csr_io_i_w_en),
    .io_fcsr_o_data(csr_io_fcsr_o_data)
  );
  CSRController csrController ( // @[InstructionDecode.scala 86:29]
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
  HazardUnit hdu ( // @[InstructionDecode.scala 101:19]
    .io_id_ex_memRead(hdu_io_id_ex_memRead),
    .io_ex_mem_memRead(hdu_io_ex_mem_memRead),
    .io_id_ex_branch(hdu_io_id_ex_branch),
    .io_id_ex_rd(hdu_io_id_ex_rd),
    .io_ex_mem_rd(hdu_io_ex_mem_rd),
    .io_id_rs1(hdu_io_id_rs1),
    .io_id_rs2(hdu_io_id_rs2),
    .io_taken(hdu_io_taken),
    .io_jump(hdu_io_jump),
    .io_branch(hdu_io_branch),
    .io_if_reg_write(hdu_io_if_reg_write),
    .io_pc_write(hdu_io_pc_write),
    .io_ctl_mux(hdu_io_ctl_mux),
    .io_ifid_flush(hdu_io_ifid_flush),
    .io_take_branch(hdu_io_take_branch)
  );
  Control control ( // @[InstructionDecode.scala 117:23]
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
  Registers registers ( // @[InstructionDecode.scala 136:25]
    .clock(registers_clock),
    .reset(registers_reset),
    .io_readAddress_0(registers_io_readAddress_0),
    .io_readAddress_1(registers_io_readAddress_1),
    .io_writeEnable(registers_io_writeEnable),
    .io_writeAddress(registers_io_writeAddress),
    .io_writeData(registers_io_writeData),
    .io_readData_0(registers_io_readData_0),
    .io_readData_1(registers_io_readData_1)
  );
  ImmediateGen immediate ( // @[InstructionDecode.scala 167:25]
    .io_instruction(immediate_io_instruction),
    .io_out(immediate_io_out)
  );
  BranchUnit bu ( // @[InstructionDecode.scala 193:18]
    .io_branch(bu_io_branch),
    .io_funct3(bu_io_funct3),
    .io_rd1(bu_io_rd1),
    .io_rd2(bu_io_rd2),
    .io_take_branch(bu_io_take_branch),
    .io_taken(bu_io_taken)
  );
  assign io_immediate = immediate_io_out; // @[InstructionDecode.scala 169:16]
  assign io_writeRegAddress = io_id_instruction[11:7]; // @[InstructionDecode.scala 234:42]
  assign io_readData1 = io_ctl_writeEnable & io_writeReg == io_id_instruction[19:15] ? _GEN_2 : registers_io_readData_0; // @[InstructionDecode.scala 147:60 154:18]
  assign io_readData2 = io_ctl_writeEnable & io_writeReg == io_id_instruction[24:20] ? _GEN_4 : registers_io_readData_1; // @[InstructionDecode.scala 156:60 163:18]
  assign io_func7 = io_id_instruction[6:0] == 7'h33 | io_id_instruction[6:0] == 7'h13 & io_func3 == 3'h5 ?
    io_id_instruction[31:25] : 7'h0; // @[InstructionDecode.scala 236:117 237:14 239:14]
  assign io_func3 = io_id_instruction[14:12]; // @[InstructionDecode.scala 235:32]
  assign io_ctl_aluSrc = control_io_aluSrc; // @[InstructionDecode.scala 120:17]
  assign io_ctl_memToReg = control_io_memToReg; // @[InstructionDecode.scala 124:19]
  assign io_ctl_regWrite = hdu_io_ctl_mux & io_id_instruction != 32'h13 & control_io_regWrite; // @[InstructionDecode.scala 126:57 128:21 132:21]
  assign io_ctl_memRead = control_io_memRead; // @[InstructionDecode.scala 123:18]
  assign io_ctl_memWrite = hdu_io_ctl_mux & io_id_instruction != 32'h13 & control_io_memWrite; // @[InstructionDecode.scala 126:57 127:21 131:21]
  assign io_ctl_branch = control_io_branch; // @[InstructionDecode.scala 122:17]
  assign io_ctl_aluOp = control_io_aluOp; // @[InstructionDecode.scala 119:16]
  assign io_ctl_jump = control_io_jump; // @[InstructionDecode.scala 125:15]
  assign io_ctl_aluSrc1 = control_io_aluSrc1; // @[InstructionDecode.scala 121:18]
  assign io_hdu_pcWrite = hdu_io_pc_write; // @[InstructionDecode.scala 113:18]
  assign io_hdu_if_reg_write = hdu_io_if_reg_write; // @[InstructionDecode.scala 114:23]
  assign io_pcSrc = bu_io_taken | io_ctl_jump != 2'h0; // @[InstructionDecode.scala 225:20]
  assign io_pcPlusOffset = io_ctl_jump == 2'h1 ? _io_pcPlusOffset_T_1 : _GEN_14; // @[InstructionDecode.scala 216:29 217:21]
  assign io_ifid_flush = hdu_io_ifid_flush; // @[InstructionDecode.scala 232:17]
  assign io_stall = io_func7 == 7'h1 & (io_func3 == 3'h4 | _T_32 | io_func3 == 3'h6 | io_func3 == 3'h7); // @[InstructionDecode.scala 242:32]
  assign io_csr_o_data = csr_io_o_data; // @[InstructionDecode.scala 83:31]
  assign io_is_csr = io_id_instruction[6:0] == 7'h73; // @[InstructionDecode.scala 82:58]
  assign io_fscr_o_data = csr_io_fcsr_o_data; // @[InstructionDecode.scala 84:31]
  assign io_rs_addr_0 = io_id_instruction[19:15]; // @[InstructionDecode.scala 138:38]
  assign io_rs_addr_1 = io_id_instruction[24:20]; // @[InstructionDecode.scala 139:38]
  assign csr_clock = clock;
  assign csr_reset = reset;
  assign csr_io_i_data = 3'h6 == csrController_io_forwardRS1 ? io_csr_Wb_data : _csr_io_i_data_T_9; // @[Mux.scala 81:58]
  assign csr_io_i_imm = io_id_instruction[19:15]; // @[InstructionDecode.scala 77:51]
  assign csr_io_i_opr = io_id_instruction[14:12]; // @[InstructionDecode.scala 78:51]
  assign csr_io_i_addr = io_id_instruction[31:20]; // @[InstructionDecode.scala 79:51]
  assign csr_io_i_w_en = io_is_csr & io_id_instruction[19:15] != 5'h0; // @[InstructionDecode.scala 80:44]
  assign csrController_io_regWrExecute = io_id_ex_regWr; // @[InstructionDecode.scala 87:36]
  assign csrController_io_rdSelExecute = io_id_ex_rd; // @[InstructionDecode.scala 88:36]
  assign csrController_io_csrWrExecute = io_csr_Ex; // @[InstructionDecode.scala 89:36]
  assign csrController_io_regWrMemory = io_ex_mem_regWr; // @[InstructionDecode.scala 90:36]
  assign csrController_io_rdSelMemory = io_ex_mem_rd; // @[InstructionDecode.scala 91:36]
  assign csrController_io_csrWrMemory = io_csr_Mem; // @[InstructionDecode.scala 92:36]
  assign csrController_io_regWrWriteback = io_ctl_writeEnable; // @[InstructionDecode.scala 93:36]
  assign csrController_io_rdSelWriteback = io_writeReg; // @[InstructionDecode.scala 94:36]
  assign csrController_io_csrWrWriteback = io_csr_Wb; // @[InstructionDecode.scala 95:36]
  assign csrController_io_rs1SelDecode = io_id_instruction[19:15]; // @[InstructionDecode.scala 96:56]
  assign csrController_io_csrInstDecode = io_id_instruction[6:0] == 7'h73; // @[InstructionDecode.scala 97:63]
  assign hdu_io_id_ex_memRead = io_id_ex_mem_read; // @[InstructionDecode.scala 103:24]
  assign hdu_io_ex_mem_memRead = io_ex_mem_mem_read; // @[InstructionDecode.scala 105:25]
  assign hdu_io_id_ex_branch = io_id_ex_branch; // @[InstructionDecode.scala 107:23]
  assign hdu_io_id_ex_rd = io_id_ex_rd; // @[InstructionDecode.scala 106:19]
  assign hdu_io_ex_mem_rd = io_ex_mem_rd; // @[InstructionDecode.scala 108:20]
  assign hdu_io_id_rs1 = io_id_instruction[19:15]; // @[InstructionDecode.scala 109:37]
  assign hdu_io_id_rs2 = io_id_instruction[24:20]; // @[InstructionDecode.scala 110:37]
  assign hdu_io_taken = bu_io_taken; // @[InstructionDecode.scala 199:16]
  assign hdu_io_jump = io_ctl_jump; // @[InstructionDecode.scala 111:15]
  assign hdu_io_branch = io_ctl_branch; // @[InstructionDecode.scala 112:17]
  assign control_io_in = io_id_instruction; // @[InstructionDecode.scala 118:17]
  assign registers_clock = clock;
  assign registers_reset = reset;
  assign registers_io_readAddress_0 = io_id_instruction[19:15]; // @[InstructionDecode.scala 138:38]
  assign registers_io_readAddress_1 = io_id_instruction[24:20]; // @[InstructionDecode.scala 139:38]
  assign registers_io_writeEnable = io_ctl_writeEnable | io_csr_Wb; // @[InstructionDecode.scala 142:50]
  assign registers_io_writeAddress = io_writeReg; // @[InstructionDecode.scala 143:29]
  assign registers_io_writeData = io_csr_Wb ? io_csr_Wb_data : io_writeData; // @[InstructionDecode.scala 144:32]
  assign immediate_io_instruction = io_id_instruction; // @[InstructionDecode.scala 168:28]
  assign bu_io_branch = io_ctl_branch; // @[InstructionDecode.scala 194:16]
  assign bu_io_funct3 = io_id_instruction[14:12]; // @[InstructionDecode.scala 195:36]
  assign bu_io_rd1 = io_id_instruction[19:15] == io_ex_mem_ins[11:7] ? io_ex_mem_result : _GEN_6; // @[InstructionDecode.scala 175:46 176:12]
  assign bu_io_rd2 = io_id_instruction[24:20] == io_ex_mem_ins[11:7] ? io_ex_mem_result : _GEN_8; // @[InstructionDecode.scala 183:46 184:12]
  assign bu_io_take_branch = hdu_io_take_branch; // @[InstructionDecode.scala 198:21]
endmodule
module ALU(
  input  [31:0] io_input1,
  input  [31:0] io_input2,
  input  [3:0]  io_aluCtl,
  output [31:0] io_result
);
  wire  _io_result_T = io_aluCtl == 4'h0; // @[ALU.scala 17:18]
  wire [31:0] _io_result_T_1 = io_input1 & io_input2; // @[ALU.scala 17:41]
  wire  _io_result_T_2 = io_aluCtl == 4'h1; // @[ALU.scala 18:18]
  wire [31:0] _io_result_T_3 = io_input1 | io_input2; // @[ALU.scala 18:41]
  wire  _io_result_T_4 = io_aluCtl == 4'h2; // @[ALU.scala 19:18]
  wire [31:0] _io_result_T_6 = io_input1 + io_input2; // @[ALU.scala 19:41]
  wire  _io_result_T_7 = io_aluCtl == 4'h3; // @[ALU.scala 20:18]
  wire [31:0] _io_result_T_9 = io_input1 - io_input2; // @[ALU.scala 20:41]
  wire  _io_result_T_10 = io_aluCtl == 4'h4; // @[ALU.scala 21:18]
  wire  _io_result_T_13 = $signed(io_input1) < $signed(io_input2); // @[ALU.scala 21:48]
  wire  _io_result_T_14 = io_aluCtl == 4'h5; // @[ALU.scala 22:18]
  wire  _io_result_T_15 = io_input1 < io_input2; // @[ALU.scala 22:41]
  wire  _io_result_T_16 = io_aluCtl == 4'h6; // @[ALU.scala 23:18]
  wire [62:0] _GEN_0 = {{31'd0}, io_input1}; // @[ALU.scala 23:41]
  wire [62:0] _io_result_T_18 = _GEN_0 << io_input2[4:0]; // @[ALU.scala 23:41]
  wire  _io_result_T_19 = io_aluCtl == 4'h7; // @[ALU.scala 24:18]
  wire [31:0] _io_result_T_21 = io_input1 >> io_input2[4:0]; // @[ALU.scala 24:41]
  wire  _io_result_T_22 = io_aluCtl == 4'h8; // @[ALU.scala 25:18]
  wire [31:0] _io_result_T_26 = $signed(io_input1) >>> io_input2[4:0]; // @[ALU.scala 25:68]
  wire  _io_result_T_27 = io_aluCtl == 4'h9; // @[ALU.scala 26:18]
  wire [31:0] _io_result_T_28 = io_input1 ^ io_input2; // @[ALU.scala 26:41]
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
  assign io_result = _io_result_T_38[31:0]; // @[ALU.scala 14:13]
endmodule
module AluControl(
  input  [1:0] io_aluOp,
  input        io_f7,
  input  [2:0] io_f3,
  input        io_aluSrc,
  output [3:0] io_out
);
  wire  _T_3 = ~io_f7; // @[AluControl.scala 38:34]
  wire [1:0] _GEN_0 = ~io_aluSrc | ~io_f7 ? 2'h2 : 2'h3; // @[AluControl.scala 38:43 39:18 42:20]
  wire [3:0] _GEN_1 = _T_3 ? 4'h7 : 4'h8; // @[AluControl.scala 55:29 56:18 58:18]
  wire [3:0] _GEN_2 = 3'h4 == io_f3 ? 4'h9 : 4'hf; // @[AluControl.scala 31:10 36:19 68:16]
  wire [3:0] _GEN_3 = 3'h6 == io_f3 ? 4'h1 : _GEN_2; // @[AluControl.scala 36:19 65:16]
  wire [3:0] _GEN_4 = 3'h7 == io_f3 ? 4'h0 : _GEN_3; // @[AluControl.scala 36:19 62:16]
  wire [3:0] _GEN_5 = 3'h5 == io_f3 ? _GEN_1 : _GEN_4; // @[AluControl.scala 36:19]
  wire [3:0] _GEN_6 = 3'h3 == io_f3 ? 4'h5 : _GEN_5; // @[AluControl.scala 36:19 52:16]
  wire [3:0] _GEN_7 = 3'h2 == io_f3 ? 4'h4 : _GEN_6; // @[AluControl.scala 36:19 49:16]
  wire [3:0] _GEN_8 = 3'h1 == io_f3 ? 4'h6 : _GEN_7; // @[AluControl.scala 36:19 46:16]
  wire [3:0] _GEN_9 = 3'h0 == io_f3 ? {{2'd0}, _GEN_0} : _GEN_8; // @[AluControl.scala 36:19]
  assign io_out = io_aluOp == 2'h0 ? 4'h2 : _GEN_9; // @[AluControl.scala 33:26 34:12]
endmodule
module ForwardingUnit(
  input  [4:0] io_ex_reg_rd,
  input  [4:0] io_mem_reg_rd,
  input  [4:0] io_reg_rs1,
  input  [4:0] io_reg_rs2,
  input        io_ex_regWrite,
  input        io_mem_regWrite,
  output [1:0] io_forwardA,
  output [1:0] io_forwardB
);
  wire  _T_1 = io_ex_reg_rd != 5'h0; // @[ForwardingUnit.scala 21:52]
  wire  _T_5 = io_mem_reg_rd != 5'h0; // @[ForwardingUnit.scala 24:53]
  wire  _T_7 = io_reg_rs1 == io_mem_reg_rd & io_mem_reg_rd != 5'h0 & io_mem_regWrite; // @[ForwardingUnit.scala 24:61]
  wire [1:0] _GEN_0 = _T_7 ? 2'h2 : 2'h0; // @[ForwardingUnit.scala 25:7 26:19 29:19]
  wire  _T_15 = io_reg_rs2 == io_mem_reg_rd & _T_5 & io_mem_regWrite; // @[ForwardingUnit.scala 35:61]
  wire [1:0] _GEN_2 = _T_15 ? 2'h2 : 2'h0; // @[ForwardingUnit.scala 36:7 37:19 40:19]
  assign io_forwardA = io_reg_rs1 == io_ex_reg_rd & io_ex_reg_rd != 5'h0 & io_ex_regWrite ? 2'h1 : _GEN_0; // @[ForwardingUnit.scala 21:79 22:17]
  assign io_forwardB = io_reg_rs2 == io_ex_reg_rd & _T_1 & io_ex_regWrite ? 2'h1 : _GEN_2; // @[ForwardingUnit.scala 32:79 33:17]
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
  wire  _result_T = io_op == 5'h0; // @[MDU.scala 34:16]
  wire  _result_T_1 = io_op == 5'h3; // @[MDU.scala 34:33]
  wire  _result_T_2 = io_op == 5'h0 | io_op == 5'h3; // @[MDU.scala 34:24]
  wire [63:0] _result_T_3 = io_src_a * io_src_b; // @[MDU.scala 34:58]
  wire  _result_T_4 = io_op == 5'h2; // @[MDU.scala 35:16]
  wire [32:0] _result_T_6 = {1'b0,$signed(io_src_b)}; // @[MDU.scala 35:66]
  wire [64:0] _result_T_7 = $signed(io_src_a) * $signed(_result_T_6); // @[MDU.scala 35:66]
  wire [63:0] _result_T_10 = _result_T_7[63:0]; // @[MDU.scala 35:78]
  wire  _result_T_11 = io_op == 5'h1; // @[MDU.scala 36:16]
  wire [63:0] _result_T_15 = $signed(io_src_a) * $signed(io_src_b); // @[MDU.scala 36:85]
  wire [63:0] _result_T_16 = _result_T_11 ? _result_T_15 : 64'h0; // @[Mux.scala 101:16]
  wire [63:0] _result_T_17 = _result_T_4 ? _result_T_10 : _result_T_16; // @[Mux.scala 101:16]
  wire [63:0] result = _result_T_2 ? _result_T_3 : _result_T_17; // @[Mux.scala 101:16]
  reg  r_ready; // @[MDU.scala 41:29]
  reg [5:0] r_counter; // @[MDU.scala 42:29]
  reg [31:0] r_dividend; // @[MDU.scala 43:29]
  reg [31:0] r_quotient; // @[MDU.scala 44:29]
  wire  _is_div_rem_u_T = io_op == 5'h5; // @[MDU.scala 48:39]
  wire  _is_div_rem_u_T_1 = io_op == 5'h7; // @[MDU.scala 48:57]
  wire  is_div_rem_u = io_op == 5'h5 | io_op == 5'h7; // @[MDU.scala 48:48]
  wire  _is_div_rem_s_T = io_op == 5'h4; // @[MDU.scala 49:39]
  wire  _is_div_rem_s_T_1 = io_op == 5'h6; // @[MDU.scala 49:56]
  wire  is_div_rem_s = io_op == 5'h4 | io_op == 5'h6; // @[MDU.scala 49:47]
  wire [31:0] _dividend_T_3 = 32'h0 - io_src_a; // @[MDU.scala 51:59]
  wire [31:0] dividend = is_div_rem_s & io_src_a[31] ? _dividend_T_3 : io_src_a; // @[MDU.scala 51:28]
  wire [31:0] _divisor_T_3 = 32'h0 - io_src_b; // @[MDU.scala 52:59]
  wire [31:0] divisor = is_div_rem_s & io_src_b[31] ? _divisor_T_3 : io_src_b; // @[MDU.scala 52:28]
  wire [5:0] _T_4 = r_counter - 6'h1; // @[MDU.scala 59:52]
  wire [94:0] _GEN_30 = {{63'd0}, divisor}; // @[MDU.scala 59:40]
  wire [94:0] _T_5 = _GEN_30 << _T_4; // @[MDU.scala 59:40]
  wire [94:0] _GEN_2 = {{63'd0}, r_dividend}; // @[MDU.scala 59:29]
  wire [94:0] _r_dividend_T_4 = _GEN_2 - _T_5; // @[MDU.scala 60:45]
  wire [63:0] _r_quotient_T_2 = 64'h1 << _T_4; // @[MDU.scala 61:51]
  wire [63:0] _GEN_27 = {{32'd0}, r_quotient}; // @[MDU.scala 61:45]
  wire [63:0] _r_quotient_T_4 = _GEN_27 + _r_quotient_T_2; // @[MDU.scala 61:45]
  wire [94:0] _GEN_0 = _GEN_2 >= _T_5 ? _r_dividend_T_4 : {{63'd0}, r_dividend}; // @[MDU.scala 43:29 59:59 60:31]
  wire [63:0] _GEN_1 = _GEN_2 >= _T_5 ? _r_quotient_T_4 : {{32'd0}, r_quotient}; // @[MDU.scala 44:29 59:59 61:31]
  wire [94:0] _GEN_3 = r_counter != 6'h0 ? _GEN_0 : {{63'd0}, r_dividend}; // @[MDU.scala 43:29 58:38]
  wire [63:0] _GEN_4 = r_counter != 6'h0 ? _GEN_1 : {{32'd0}, r_quotient}; // @[MDU.scala 44:29 58:38]
  wire  _GEN_5 = r_counter != 6'h0 ? r_counter == 6'h1 : r_ready; // @[MDU.scala 58:38 66:24 41:29]
  wire  _GEN_7 = r_counter != 6'h0 ? 1'h0 : 1'h1; // @[MDU.scala 46:21 58:38 68:29]
  wire  _GEN_8 = io_valid ? 1'h0 : _GEN_5; // @[MDU.scala 53:32 54:24]
  wire [94:0] _GEN_10 = io_valid ? {{63'd0}, dividend} : _GEN_3; // @[MDU.scala 53:32 56:24]
  wire [63:0] _GEN_11 = io_valid ? 64'h0 : _GEN_4; // @[MDU.scala 53:32 57:24]
  wire  _GEN_12 = io_valid ? 1'h0 : _GEN_7; // @[MDU.scala 46:21 53:32]
  wire  _GEN_13 = is_div_rem_s | is_div_rem_u ? _GEN_8 : r_ready; // @[MDU.scala 41:29 50:39]
  wire [94:0] _GEN_15 = is_div_rem_s | is_div_rem_u ? _GEN_10 : {{63'd0}, r_dividend}; // @[MDU.scala 43:29 50:39]
  wire [63:0] _GEN_16 = is_div_rem_s | is_div_rem_u ? _GEN_11 : {{32'd0}, r_quotient}; // @[MDU.scala 44:29 50:39]
  wire  _GEN_17 = (is_div_rem_s | is_div_rem_u) & _GEN_12; // @[MDU.scala 46:21 50:39]
  wire [31:0] _io_output_bits_T_8 = 32'h0 - r_quotient; // @[MDU.scala 80:76]
  wire [31:0] _io_output_bits_T_9 = io_src_a[31] != io_src_b[31] & |io_src_b ? _io_output_bits_T_8 : r_quotient; // @[MDU.scala 80:30]
  wire [31:0] _io_output_bits_T_12 = 32'h0 - r_dividend; // @[MDU.scala 84:44]
  wire [31:0] _io_output_bits_T_13 = io_src_a[31] ? _io_output_bits_T_12 : r_dividend; // @[MDU.scala 84:30]
  wire [31:0] _GEN_18 = _is_div_rem_u_T_1 ? r_dividend : 32'h0; // @[MDU.scala 85:31 86:24 88:24]
  wire [31:0] _GEN_19 = _is_div_rem_s_T_1 ? _io_output_bits_T_13 : _GEN_18; // @[MDU.scala 83:30 84:24]
  wire [31:0] _GEN_20 = _is_div_rem_u_T ? r_quotient : _GEN_19; // @[MDU.scala 81:31 82:24]
  wire [31:0] _GEN_21 = _is_div_rem_s_T ? _io_output_bits_T_9 : _GEN_20; // @[MDU.scala 79:30 80:24]
  wire [31:0] _GEN_22 = _result_T_11 | _result_T_1 | _result_T_4 ? result[63:32] : _GEN_21; // @[MDU.scala 76:70 77:24]
  wire  _GEN_23 = _result_T_11 | _result_T_1 | _result_T_4 | _GEN_17; // @[MDU.scala 76:70 78:25]
  wire [94:0] _GEN_28 = reset ? 95'h0 : _GEN_15; // @[MDU.scala 43:{29,29}]
  wire [63:0] _GEN_29 = reset ? 64'h0 : _GEN_16; // @[MDU.scala 44:{29,29}]
  assign io_ready = r_ready; // @[MDU.scala 72:18]
  assign io_output_valid = _result_T | _GEN_23; // @[MDU.scala 73:24 75:25]
  assign io_output_bits = _result_T ? result[31:0] : _GEN_22; // @[MDU.scala 73:24 74:24]
  always @(posedge clock) begin
    r_ready <= reset | _GEN_13; // @[MDU.scala 41:{29,29}]
    if (reset) begin // @[MDU.scala 42:29]
      r_counter <= 6'h20; // @[MDU.scala 42:29]
    end else if (is_div_rem_s | is_div_rem_u) begin // @[MDU.scala 50:39]
      if (io_valid) begin // @[MDU.scala 53:32]
        r_counter <= 6'h20; // @[MDU.scala 55:24]
      end else if (r_counter != 6'h0) begin // @[MDU.scala 58:38]
        r_counter <= _T_4; // @[MDU.scala 65:24]
      end
    end
    r_dividend <= _GEN_28[31:0]; // @[MDU.scala 43:{29,29}]
    r_quotient <= _GEN_29[31:0]; // @[MDU.scala 44:{29,29}]
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
  input         io_ex_mem_regWrite,
  input         io_mem_wb_regWrite,
  input  [31:0] io_id_ex_ins,
  input  [31:0] io_ex_mem_ins,
  input  [31:0] io_mem_wb_ins,
  input         io_ctl_aluSrc,
  input  [1:0]  io_ctl_aluOp,
  input  [1:0]  io_ctl_aluSrc1,
  output [31:0] io_writeData,
  output [31:0] io_ALUresult,
  output        io_stall
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] alu_io_input1; // @[Execute.scala 33:19]
  wire [31:0] alu_io_input2; // @[Execute.scala 33:19]
  wire [3:0] alu_io_aluCtl; // @[Execute.scala 33:19]
  wire [31:0] alu_io_result; // @[Execute.scala 33:19]
  wire [1:0] aluCtl_io_aluOp; // @[Execute.scala 34:22]
  wire  aluCtl_io_f7; // @[Execute.scala 34:22]
  wire [2:0] aluCtl_io_f3; // @[Execute.scala 34:22]
  wire  aluCtl_io_aluSrc; // @[Execute.scala 34:22]
  wire [3:0] aluCtl_io_out; // @[Execute.scala 34:22]
  wire [4:0] ForwardingUnit_io_ex_reg_rd; // @[Execute.scala 35:18]
  wire [4:0] ForwardingUnit_io_mem_reg_rd; // @[Execute.scala 35:18]
  wire [4:0] ForwardingUnit_io_reg_rs1; // @[Execute.scala 35:18]
  wire [4:0] ForwardingUnit_io_reg_rs2; // @[Execute.scala 35:18]
  wire  ForwardingUnit_io_ex_regWrite; // @[Execute.scala 35:18]
  wire  ForwardingUnit_io_mem_regWrite; // @[Execute.scala 35:18]
  wire [1:0] ForwardingUnit_io_forwardA; // @[Execute.scala 35:18]
  wire [1:0] ForwardingUnit_io_forwardB; // @[Execute.scala 35:18]
  wire  mdu_clock; // @[Execute.scala 83:22]
  wire  mdu_reset; // @[Execute.scala 83:22]
  wire [31:0] mdu_io_src_a; // @[Execute.scala 83:22]
  wire [31:0] mdu_io_src_b; // @[Execute.scala 83:22]
  wire [4:0] mdu_io_op; // @[Execute.scala 83:22]
  wire  mdu_io_valid; // @[Execute.scala 83:22]
  wire  mdu_io_ready; // @[Execute.scala 83:22]
  wire  mdu_io_output_valid; // @[Execute.scala 83:22]
  wire [31:0] mdu_io_output_bits; // @[Execute.scala 83:22]
  wire  _inputMux1_T = ForwardingUnit_io_forwardA == 2'h0; // @[Execute.scala 49:20]
  wire  _inputMux1_T_1 = ForwardingUnit_io_forwardA == 2'h1; // @[Execute.scala 50:20]
  wire  _inputMux1_T_2 = ForwardingUnit_io_forwardA == 2'h2; // @[Execute.scala 51:20]
  wire [31:0] _inputMux1_T_3 = _inputMux1_T_2 ? io_wb_result : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _inputMux1_T_4 = _inputMux1_T_1 ? io_mem_result : _inputMux1_T_3; // @[Mux.scala 101:16]
  wire [31:0] inputMux1 = _inputMux1_T ? io_readData1 : _inputMux1_T_4; // @[Mux.scala 101:16]
  wire  _inputMux2_T = ForwardingUnit_io_forwardB == 2'h0; // @[Execute.scala 57:20]
  wire  _inputMux2_T_1 = ForwardingUnit_io_forwardB == 2'h1; // @[Execute.scala 58:20]
  wire  _inputMux2_T_2 = ForwardingUnit_io_forwardB == 2'h2; // @[Execute.scala 59:20]
  wire [31:0] _inputMux2_T_3 = _inputMux2_T_2 ? io_wb_result : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _inputMux2_T_4 = _inputMux2_T_1 ? io_mem_result : _inputMux2_T_3; // @[Mux.scala 101:16]
  wire [31:0] inputMux2 = _inputMux2_T ? io_readData2 : _inputMux2_T_4; // @[Mux.scala 101:16]
  wire  _aluIn1_T = io_ctl_aluSrc1 == 2'h1; // @[Execute.scala 66:23]
  wire  _aluIn1_T_1 = io_ctl_aluSrc1 == 2'h2; // @[Execute.scala 67:23]
  wire [31:0] _aluIn1_T_2 = _aluIn1_T_1 ? 32'h0 : inputMux1; // @[Mux.scala 101:16]
  wire [31:0] aluIn1 = _aluIn1_T ? io_pcAddress : _aluIn1_T_2; // @[Mux.scala 101:16]
  wire [31:0] aluIn2 = io_ctl_aluSrc ? inputMux2 : io_immediate; // @[Execute.scala 70:19]
  reg [31:0] src_a_reg; // @[Execute.scala 90:28]
  reg [31:0] src_b_reg; // @[Execute.scala 91:28]
  reg [2:0] op_reg; // @[Execute.scala 92:28]
  reg  div_en; // @[Execute.scala 93:28]
  reg [5:0] f7_reg; // @[Execute.scala 94:28]
  reg [5:0] counter; // @[Execute.scala 95:28]
  wire  _T_4 = io_func7 == 7'h1; // @[Execute.scala 97:19]
  wire  _T_12 = io_func7 == 7'h1 & (io_func3 == 3'h0 | io_func3 == 3'h1 | io_func3 == 3'h2 | io_func3 == 3'h3); // @[Execute.scala 97:27]
  wire  _T_23 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7); // @[Execute.scala 103:38]
  wire  _GEN_1 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7) | _T_12; // @[Execute.scala 103:120 104:20]
  wire  _GEN_2 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7) | div_en; // @[Execute.scala 103:120 105:14 93:28]
  wire [6:0] _GEN_6 = _T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7) ?
    io_func7 : {{1'd0}, f7_reg}; // @[Execute.scala 103:120 109:14 94:28]
  wire [5:0] _counter_T_1 = counter + 6'h1; // @[Execute.scala 122:28]
  wire  _GEN_8 = counter < 6'h20 | _T_23; // @[Execute.scala 116:28 117:18]
  wire  _GEN_13 = counter < 6'h20 & _GEN_1; // @[Execute.scala 116:28 124:22]
  wire  _GEN_14 = counter < 6'h20 & _GEN_2; // @[Execute.scala 116:28 125:22]
  wire [2:0] _GEN_18 = div_en ? op_reg : io_func3; // @[Execute.scala 114:17 86:18]
  wire [31:0] _io_ALUresult_T = mdu_io_output_valid ? mdu_io_output_bits : 32'h0; // @[Execute.scala 134:26]
  wire [31:0] _GEN_22 = _T_4 & mdu_io_ready ? _io_ALUresult_T : alu_io_result; // @[Execute.scala 136:49 137:20 139:29]
  wire [6:0] _GEN_24 = reset ? 7'h0 : _GEN_6; // @[Execute.scala 94:{28,28}]
  ALU alu ( // @[Execute.scala 33:19]
    .io_input1(alu_io_input1),
    .io_input2(alu_io_input2),
    .io_aluCtl(alu_io_aluCtl),
    .io_result(alu_io_result)
  );
  AluControl aluCtl ( // @[Execute.scala 34:22]
    .io_aluOp(aluCtl_io_aluOp),
    .io_f7(aluCtl_io_f7),
    .io_f3(aluCtl_io_f3),
    .io_aluSrc(aluCtl_io_aluSrc),
    .io_out(aluCtl_io_out)
  );
  ForwardingUnit ForwardingUnit ( // @[Execute.scala 35:18]
    .io_ex_reg_rd(ForwardingUnit_io_ex_reg_rd),
    .io_mem_reg_rd(ForwardingUnit_io_mem_reg_rd),
    .io_reg_rs1(ForwardingUnit_io_reg_rs1),
    .io_reg_rs2(ForwardingUnit_io_reg_rs2),
    .io_ex_regWrite(ForwardingUnit_io_ex_regWrite),
    .io_mem_regWrite(ForwardingUnit_io_mem_regWrite),
    .io_forwardA(ForwardingUnit_io_forwardA),
    .io_forwardB(ForwardingUnit_io_forwardB)
  );
  MDU mdu ( // @[Execute.scala 83:22]
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
  assign io_ALUresult = div_en & f7_reg == 6'h1 & mdu_io_ready ? _io_ALUresult_T : _GEN_22; // @[Execute.scala 133:51 134:20]
  assign io_stall = div_en ? _GEN_8 : _T_23; // @[Execute.scala 114:17]
  assign alu_io_input1 = _aluIn1_T ? io_pcAddress : _aluIn1_T_2; // @[Mux.scala 101:16]
  assign alu_io_input2 = io_ctl_aluSrc ? inputMux2 : io_immediate; // @[Execute.scala 70:19]
  assign alu_io_aluCtl = aluCtl_io_out; // @[Execute.scala 79:17]
  assign aluCtl_io_aluOp = io_ctl_aluOp; // @[Execute.scala 74:19]
  assign aluCtl_io_f7 = io_func7[5]; // @[Execute.scala 73:27]
  assign aluCtl_io_f3 = io_func3; // @[Execute.scala 72:16]
  assign aluCtl_io_aluSrc = io_ctl_aluSrc; // @[Execute.scala 75:20]
  assign ForwardingUnit_io_ex_reg_rd = io_ex_mem_ins[11:7]; // @[Execute.scala 41:32]
  assign ForwardingUnit_io_mem_reg_rd = io_mem_wb_ins[11:7]; // @[Execute.scala 42:33]
  assign ForwardingUnit_io_reg_rs1 = io_id_ex_ins[19:15]; // @[Execute.scala 43:29]
  assign ForwardingUnit_io_reg_rs2 = io_id_ex_ins[24:20]; // @[Execute.scala 44:29]
  assign ForwardingUnit_io_ex_regWrite = io_ex_mem_regWrite; // @[Execute.scala 39:18]
  assign ForwardingUnit_io_mem_regWrite = io_mem_wb_regWrite; // @[Execute.scala 40:19]
  assign mdu_clock = clock;
  assign mdu_reset = reset;
  assign mdu_io_src_a = div_en ? src_a_reg : aluIn1; // @[Execute.scala 114:17 84:18]
  assign mdu_io_src_b = div_en ? src_b_reg : aluIn2; // @[Execute.scala 114:17 85:18]
  assign mdu_io_op = {{2'd0}, _GEN_18};
  assign mdu_io_valid = div_en ? _GEN_13 : _GEN_1; // @[Execute.scala 114:17]
  always @(posedge clock) begin
    if (reset) begin // @[Execute.scala 90:28]
      src_a_reg <= 32'h0; // @[Execute.scala 90:28]
    end else if (_T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7)) begin // @[Execute.scala 103:120]
      if (_aluIn1_T) begin // @[Mux.scala 101:16]
        src_a_reg <= io_pcAddress;
      end else if (_aluIn1_T_1) begin // @[Mux.scala 101:16]
        src_a_reg <= 32'h0;
      end else begin
        src_a_reg <= inputMux1;
      end
    end
    if (reset) begin // @[Execute.scala 91:28]
      src_b_reg <= 32'h0; // @[Execute.scala 91:28]
    end else if (_T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7)) begin // @[Execute.scala 103:120]
      if (io_ctl_aluSrc) begin // @[Execute.scala 70:19]
        if (_inputMux2_T) begin // @[Mux.scala 101:16]
          src_b_reg <= io_readData2;
        end else begin
          src_b_reg <= _inputMux2_T_4;
        end
      end else begin
        src_b_reg <= io_immediate;
      end
    end
    if (reset) begin // @[Execute.scala 92:28]
      op_reg <= 3'h0; // @[Execute.scala 92:28]
    end else if (_T_4 & ~div_en & (io_func3 == 3'h4 | io_func3 == 3'h5 | io_func3 == 3'h6 | io_func3 == 3'h7)) begin // @[Execute.scala 103:120]
      op_reg <= io_func3; // @[Execute.scala 108:14]
    end
    if (reset) begin // @[Execute.scala 93:28]
      div_en <= 1'h0; // @[Execute.scala 93:28]
    end else if (div_en) begin // @[Execute.scala 114:17]
      div_en <= _GEN_14;
    end else begin
      div_en <= _GEN_2;
    end
    f7_reg <= _GEN_24[5:0]; // @[Execute.scala 94:{28,28}]
    if (reset) begin // @[Execute.scala 95:28]
      counter <= 6'h0; // @[Execute.scala 95:28]
    end else if (div_en) begin // @[Execute.scala 114:17]
      if (counter < 6'h20) begin // @[Execute.scala 116:28]
        counter <= _counter_T_1; // @[Execute.scala 122:17]
      end else begin
        counter <= 6'h0; // @[Execute.scala 129:17]
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
  input  [2:0]  io_f3,
  output        io_dccmReq_valid,
  output [31:0] io_dccmReq_bits_addrRequest,
  output [31:0] io_dccmReq_bits_dataRequest,
  output [3:0]  io_dccmReq_bits_activeByteLane,
  output        io_dccmReq_bits_isWrite,
  input         io_dccmRsp_valid,
  input  [31:0] io_dccmRsp_bits_dataResponse
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [1:0] offset; // @[MemoryFetch.scala 26:23]
  reg [2:0] funct3; // @[MemoryFetch.scala 27:23]
  wire [1:0] offsetSW = io_aluResultIn[1:0]; // @[MemoryFetch.scala 28:32]
  wire  _T_3 = offsetSW == 2'h0; // @[MemoryFetch.scala 45:19]
  wire  _T_4 = offsetSW == 2'h1; // @[MemoryFetch.scala 47:25]
  wire [7:0] _GEN_2 = offsetSW == 2'h2 ? io_writeData[15:8] : io_writeData[15:8]; // @[MemoryFetch.scala 53:33 54:16 60:16]
  wire [7:0] _GEN_3 = offsetSW == 2'h2 ? io_writeData[23:16] : io_writeData[23:16]; // @[MemoryFetch.scala 53:33 55:16 61:16]
  wire [7:0] _GEN_4 = offsetSW == 2'h2 ? io_writeData[7:0] : io_writeData[31:24]; // @[MemoryFetch.scala 53:33 56:16 62:16]
  wire [7:0] _GEN_5 = offsetSW == 2'h2 ? io_writeData[31:24] : io_writeData[7:0]; // @[MemoryFetch.scala 53:33 57:16 63:16]
  wire [3:0] _GEN_6 = offsetSW == 2'h2 ? 4'h4 : 4'h8; // @[MemoryFetch.scala 53:33 58:38 64:38]
  wire [7:0] _GEN_7 = offsetSW == 2'h1 ? io_writeData[15:8] : _GEN_2; // @[MemoryFetch.scala 47:33 48:16]
  wire [7:0] _GEN_8 = offsetSW == 2'h1 ? io_writeData[7:0] : _GEN_3; // @[MemoryFetch.scala 47:33 49:16]
  wire [7:0] _GEN_9 = offsetSW == 2'h1 ? io_writeData[23:16] : _GEN_4; // @[MemoryFetch.scala 47:33 50:16]
  wire [7:0] _GEN_10 = offsetSW == 2'h1 ? io_writeData[31:24] : _GEN_5; // @[MemoryFetch.scala 47:33 51:16]
  wire [3:0] _GEN_11 = offsetSW == 2'h1 ? 4'h2 : _GEN_6; // @[MemoryFetch.scala 47:33 52:38]
  wire [3:0] _GEN_12 = offsetSW == 2'h0 ? 4'h1 : _GEN_11; // @[MemoryFetch.scala 45:27 46:38]
  wire [7:0] _GEN_13 = offsetSW == 2'h0 ? io_writeData[7:0] : _GEN_7; // @[MemoryFetch.scala 38:12 45:27]
  wire [7:0] _GEN_14 = offsetSW == 2'h0 ? io_writeData[15:8] : _GEN_8; // @[MemoryFetch.scala 39:12 45:27]
  wire [7:0] _GEN_15 = offsetSW == 2'h0 ? io_writeData[23:16] : _GEN_9; // @[MemoryFetch.scala 40:12 45:27]
  wire [7:0] _GEN_16 = offsetSW == 2'h0 ? io_writeData[31:24] : _GEN_10; // @[MemoryFetch.scala 41:12 45:27]
  wire [3:0] _GEN_17 = _T_4 ? 4'h6 : 4'hc; // @[MemoryFetch.scala 73:33 75:38 82:38]
  wire [7:0] _GEN_18 = _T_4 ? io_writeData[23:16] : io_writeData[23:16]; // @[MemoryFetch.scala 73:33 76:16 85:16]
  wire [7:0] _GEN_19 = _T_4 ? io_writeData[7:0] : io_writeData[31:24]; // @[MemoryFetch.scala 73:33 77:16 86:16]
  wire [7:0] _GEN_20 = _T_4 ? io_writeData[15:8] : io_writeData[7:0]; // @[MemoryFetch.scala 73:33 78:16 83:16]
  wire [7:0] _GEN_21 = _T_4 ? io_writeData[31:24] : io_writeData[15:8]; // @[MemoryFetch.scala 73:33 79:16 84:16]
  wire [3:0] _GEN_22 = _T_3 ? 4'h3 : _GEN_17; // @[MemoryFetch.scala 70:27 72:38]
  wire [7:0] _GEN_23 = _T_3 ? io_writeData[7:0] : _GEN_18; // @[MemoryFetch.scala 38:12 70:27]
  wire [7:0] _GEN_24 = _T_3 ? io_writeData[15:8] : _GEN_19; // @[MemoryFetch.scala 39:12 70:27]
  wire [7:0] _GEN_25 = _T_3 ? io_writeData[23:16] : _GEN_20; // @[MemoryFetch.scala 40:12 70:27]
  wire [7:0] _GEN_26 = _T_3 ? io_writeData[31:24] : _GEN_21; // @[MemoryFetch.scala 41:12 70:27]
  wire [3:0] _GEN_27 = io_writeEnable & io_f3 == 3'h1 ? _GEN_22 : 4'hf; // @[MemoryFetch.scala 68:52 91:36]
  wire [7:0] _GEN_28 = io_writeEnable & io_f3 == 3'h1 ? _GEN_23 : io_writeData[7:0]; // @[MemoryFetch.scala 38:12 68:52]
  wire [7:0] _GEN_29 = io_writeEnable & io_f3 == 3'h1 ? _GEN_24 : io_writeData[15:8]; // @[MemoryFetch.scala 39:12 68:52]
  wire [7:0] _GEN_30 = io_writeEnable & io_f3 == 3'h1 ? _GEN_25 : io_writeData[23:16]; // @[MemoryFetch.scala 40:12 68:52]
  wire [7:0] _GEN_31 = io_writeEnable & io_f3 == 3'h1 ? _GEN_26 : io_writeData[31:24]; // @[MemoryFetch.scala 41:12 68:52]
  wire [7:0] wdata_0 = io_writeEnable & io_f3 == 3'h0 ? _GEN_13 : _GEN_28; // @[MemoryFetch.scala 44:45]
  wire [7:0] wdata_1 = io_writeEnable & io_f3 == 3'h0 ? _GEN_14 : _GEN_29; // @[MemoryFetch.scala 44:45]
  wire [7:0] wdata_2 = io_writeEnable & io_f3 == 3'h0 ? _GEN_15 : _GEN_30; // @[MemoryFetch.scala 44:45]
  wire [7:0] wdata_3 = io_writeEnable & io_f3 == 3'h0 ? _GEN_16 : _GEN_31; // @[MemoryFetch.scala 44:45]
  wire [15:0] io_dccmReq_bits_dataRequest_lo = {wdata_1,wdata_0}; // @[MemoryFetch.scala 94:46]
  wire [15:0] io_dccmReq_bits_dataRequest_hi = {wdata_3,wdata_2}; // @[MemoryFetch.scala 94:46]
  wire [31:0] _io_dccmReq_bits_addrRequest_T = io_aluResultIn & 32'h1fff; // @[MemoryFetch.scala 95:50]
  wire [31:0] rdata = io_dccmRsp_valid ? io_dccmRsp_bits_dataResponse : 32'h0; // @[MemoryFetch.scala 101:15]
  wire  _T_12 = offset == 2'h0; // @[MemoryFetch.scala 111:21]
  wire [23:0] _io_readData_T_2 = rdata[7] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_4 = {_io_readData_T_2,rdata[7:0]}; // @[Cat.scala 33:92]
  wire  _T_13 = offset == 2'h1; // @[MemoryFetch.scala 114:28]
  wire [23:0] _io_readData_T_7 = rdata[15] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_9 = {_io_readData_T_7,rdata[15:8]}; // @[Cat.scala 33:92]
  wire  _T_14 = offset == 2'h2; // @[MemoryFetch.scala 117:28]
  wire [23:0] _io_readData_T_12 = rdata[23] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_14 = {_io_readData_T_12,rdata[23:16]}; // @[Cat.scala 33:92]
  wire [23:0] _io_readData_T_17 = rdata[31] ? 24'hffffff : 24'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_19 = {_io_readData_T_17,rdata[31:24]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_38 = offset == 2'h2 ? _io_readData_T_14 : _io_readData_T_19; // @[MemoryFetch.scala 117:41 119:23]
  wire [31:0] _GEN_39 = offset == 2'h1 ? _io_readData_T_9 : _GEN_38; // @[MemoryFetch.scala 114:41 116:23]
  wire [31:0] _GEN_40 = offset == 2'h0 ? _io_readData_T_4 : _GEN_39; // @[MemoryFetch.scala 111:34 113:23]
  wire [31:0] _io_readData_T_22 = {24'h0,rdata[7:0]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_25 = {24'h0,rdata[15:8]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_28 = {24'h0,rdata[23:16]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_31 = {24'h0,rdata[31:24]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_42 = _T_14 ? _io_readData_T_28 : _io_readData_T_31; // @[MemoryFetch.scala 136:40 138:23]
  wire [31:0] _GEN_43 = _T_13 ? _io_readData_T_25 : _GEN_42; // @[MemoryFetch.scala 133:40 135:23]
  wire [31:0] _GEN_44 = _T_12 ? _io_readData_T_22 : _GEN_43; // @[MemoryFetch.scala 130:34 132:23]
  wire [31:0] _io_readData_T_34 = {16'h0,rdata[15:0]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_37 = {16'h0,rdata[23:8]}; // @[Cat.scala 33:92]
  wire [31:0] _io_readData_T_40 = {16'h0,rdata[31:16]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_46 = _T_13 ? _io_readData_T_37 : _io_readData_T_40; // @[MemoryFetch.scala 152:41 154:23]
  wire [31:0] _GEN_47 = _T_12 ? _io_readData_T_34 : _GEN_46; // @[MemoryFetch.scala 149:34 151:23]
  wire [15:0] _io_readData_T_43 = rdata[15] ? 16'hffff : 16'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_45 = {_io_readData_T_43,rdata[15:0]}; // @[Cat.scala 33:92]
  wire [15:0] _io_readData_T_48 = rdata[23] ? 16'hffff : 16'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_50 = {_io_readData_T_48,rdata[23:8]}; // @[Cat.scala 33:92]
  wire [15:0] _io_readData_T_53 = rdata[31] ? 16'hffff : 16'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_readData_T_55 = {_io_readData_T_53,rdata[31:16]}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_49 = _T_13 ? _io_readData_T_50 : _io_readData_T_55; // @[MemoryFetch.scala 168:41 170:23]
  wire [31:0] _GEN_50 = _T_12 ? _io_readData_T_45 : _GEN_49; // @[MemoryFetch.scala 165:34 167:23]
  wire [31:0] _GEN_52 = funct3 == 3'h5 ? _GEN_47 : _GEN_50; // @[MemoryFetch.scala 147:38]
  wire [31:0] _GEN_53 = funct3 == 3'h4 ? _GEN_44 : _GEN_52; // @[MemoryFetch.scala 128:38]
  wire [31:0] _GEN_54 = funct3 == 3'h0 ? _GEN_40 : _GEN_53; // @[MemoryFetch.scala 109:38]
  wire  _T_31 = io_writeEnable & io_aluResultIn[31:28] == 4'h8; // @[MemoryFetch.scala 188:23]
  assign io_readData = funct3 == 3'h2 ? rdata : _GEN_54; // @[MemoryFetch.scala 105:31 107:19]
  assign io_dccmReq_valid = io_writeEnable | io_readEnable; // @[MemoryFetch.scala 97:42]
  assign io_dccmReq_bits_addrRequest = {{2'd0}, _io_dccmReq_bits_addrRequest_T[31:2]}; // @[MemoryFetch.scala 95:31]
  assign io_dccmReq_bits_dataRequest = {io_dccmReq_bits_dataRequest_hi,io_dccmReq_bits_dataRequest_lo}; // @[MemoryFetch.scala 94:46]
  assign io_dccmReq_bits_activeByteLane = io_writeEnable & io_f3 == 3'h0 ? _GEN_12 : _GEN_27; // @[MemoryFetch.scala 44:45]
  assign io_dccmReq_bits_isWrite = io_writeEnable; // @[MemoryFetch.scala 96:27]
  always @(posedge clock) begin
    if (reset) begin // @[MemoryFetch.scala 26:23]
      offset <= 2'h0; // @[MemoryFetch.scala 26:23]
    end else if (~io_dccmRsp_valid) begin // @[MemoryFetch.scala 30:26]
      offset <= offsetSW; // @[MemoryFetch.scala 32:12]
    end
    if (reset) begin // @[MemoryFetch.scala 27:23]
      funct3 <= 3'h0; // @[MemoryFetch.scala 27:23]
    end else if (~io_dccmRsp_valid) begin // @[MemoryFetch.scala 30:26]
      funct3 <= io_f3; // @[MemoryFetch.scala 31:12]
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_31 & ~reset) begin
          $fwrite(32'h80000002,"%x\n",io_writeData); // @[MemoryFetch.scala 189:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
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
  output [31:0] io_ral_address_o,
  output [31:0] io_ral_instruction_o,
  output        io_ral_halt_o
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire  addri = io_ral_address_i[1]; // @[Realigner.scala 36:31]
  reg [15:0] lhw_reg; // @[Realigner.scala 49:24]
  wire [31:0] conc_instr = {io_ral_instruction_i[15:0],lhw_reg}; // @[Cat.scala 33:92]
  wire [31:0] _io_ral_address_o_T_1 = io_ral_address_i + 32'h4; // @[Realigner.scala 56:53]
  reg [1:0] stateReg; // @[Realigner.scala 68:25]
  wire  _pc4_sel_T = stateReg == 2'h1; // @[Realigner.scala 101:30]
  wire  pc4_sel = stateReg == 2'h1 & addri & ~io_ral_jmp; // @[Realigner.scala 101:50]
  wire  conc_sel = stateReg == 2'h2; // @[Realigner.scala 103:30]
  wire [31:0] _io_ral_instruction_o_T = conc_sel ? conc_instr : io_ral_instruction_i; // @[Realigner.scala 59:69]
  wire [1:0] _GEN_0 = addri ? 2'h1 : 2'h0; // @[Realigner.scala 73:20 74:18 76:18]
  wire [1:0] _GEN_1 = io_ral_jmp ? 2'h1 : 2'h2; // @[Realigner.scala 81:27 82:20 84:20]
  assign io_ral_address_o = pc4_sel ? _io_ral_address_o_T_1 : io_ral_address_i; // @[Realigner.scala 56:26]
  assign io_ral_instruction_o = _pc4_sel_T ? 32'h13 : _io_ral_instruction_o_T; // @[Realigner.scala 59:30]
  assign io_ral_halt_o = stateReg == 2'h1; // @[Realigner.scala 100:30]
  always @(posedge clock) begin
    if (reset) begin // @[Realigner.scala 49:24]
      lhw_reg <= 16'h0; // @[Realigner.scala 49:24]
    end else begin
      lhw_reg <= io_ral_instruction_i[31:16]; // @[Realigner.scala 51:11]
    end
    if (reset) begin // @[Realigner.scala 68:25]
      stateReg <= 2'h0; // @[Realigner.scala 68:25]
    end else if (2'h0 == stateReg) begin // @[Realigner.scala 71:19]
      stateReg <= _GEN_0;
    end else if (2'h1 == stateReg) begin // @[Realigner.scala 71:19]
      if (addri) begin // @[Realigner.scala 80:18]
        stateReg <= _GEN_1;
      end else begin
        stateReg <= 2'h0; // @[Realigner.scala 87:18]
      end
    end else if (2'h2 == stateReg) begin // @[Realigner.scala 71:19]
      stateReg <= _GEN_0;
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
  stateReg = _RAND_1[1:0];
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
  output        io_is_comp,
  output [31:0] io_instruction_o
);
  wire  _T_3 = 2'h0 == io_instruction_i[15:14]; // @[CompressedDecoder.scala 42:41]
  wire [31:0] _io_instruction_o_T_5 = {2'h0,io_instruction_i[10:7],io_instruction_i[12:11],io_instruction_i[5],
    io_instruction_i[6],2'h0,10'h41,io_instruction_i[4:2],7'h13}; // @[Cat.scala 33:92]
  wire  _T_4 = 2'h1 == io_instruction_i[15:14]; // @[CompressedDecoder.scala 42:41]
  wire [31:0] _io_instruction_o_T_12 = {5'h0,io_instruction_i[5],io_instruction_i[12:10],io_instruction_i[6],4'h1,
    io_instruction_i[9:7],3'h2,2'h1,io_instruction_i[4:2],7'h3}; // @[Cat.scala 33:92]
  wire  _T_5 = 2'h3 == io_instruction_i[15:14]; // @[CompressedDecoder.scala 42:41]
  wire [17:0] io_instruction_o_lo_2 = {io_instruction_i[9:7],3'h2,io_instruction_i[11:10],io_instruction_i[6],2'h0,7'h23
    }; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_20 = {5'h0,io_instruction_i[5],io_instruction_i[12],2'h1,io_instruction_i[4:2],2'h1,
    io_instruction_o_lo_2}; // @[Cat.scala 33:92]
  wire  _T_6 = 2'h2 == io_instruction_i[15:14]; // @[CompressedDecoder.scala 42:41]
  wire [31:0] _GEN_3 = 2'h3 == io_instruction_i[15:14] ? _io_instruction_o_T_20 : io_instruction_i; // @[CompressedDecoder.scala 42:41 61:28]
  wire  _GEN_4 = 2'h1 == io_instruction_i[15:14] | 2'h3 == io_instruction_i[15:14]; // @[CompressedDecoder.scala 42:41 53:22]
  wire [31:0] _GEN_5 = 2'h1 == io_instruction_i[15:14] ? _io_instruction_o_T_12 : _GEN_3; // @[CompressedDecoder.scala 42:41 54:28]
  wire  _GEN_6 = 2'h0 == io_instruction_i[15:14] | _GEN_4; // @[CompressedDecoder.scala 42:41 46:22]
  wire [31:0] _GEN_7 = 2'h0 == io_instruction_i[15:14] ? _io_instruction_o_T_5 : _GEN_5; // @[CompressedDecoder.scala 42:41 47:28]
  wire [5:0] _io_instruction_o_T_23 = io_instruction_i[12] ? 6'h3f : 6'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_instruction_o_T_28 = {_io_instruction_o_T_23,io_instruction_i[12],io_instruction_i[6:2],
    io_instruction_i[11:7],3'h0,io_instruction_i[11:7],7'h13}; // @[Cat.scala 33:92]
  wire [8:0] _io_instruction_o_T_39 = io_instruction_i[12] ? 9'h1ff : 9'h0; // @[Bitwise.scala 77:12]
  wire  _io_instruction_o_T_41 = ~io_instruction_i[15]; // @[CompressedDecoder.scala 95:82]
  wire [24:0] io_instruction_o_lo_4 = {io_instruction_i[11],io_instruction_i[5:3],_io_instruction_o_T_39,4'h0,
    _io_instruction_o_T_41,7'h6f}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_42 = {io_instruction_i[12],io_instruction_i[8],io_instruction_i[10:9],io_instruction_i
    [6],io_instruction_i[7],io_instruction_i[2],io_instruction_o_lo_4}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_63 = {_io_instruction_o_T_23,io_instruction_i[12],io_instruction_i[6:2],5'h0,3'h0,
    io_instruction_i[11:7],7'h13}; // @[Cat.scala 33:92]
  wire [14:0] _io_instruction_o_T_66 = io_instruction_i[12] ? 15'h7fff : 15'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_instruction_o_T_69 = {_io_instruction_o_T_66,io_instruction_i[6:2],io_instruction_i[11:7],7'h37}; // @[Cat.scala 33:92]
  wire [2:0] _io_instruction_o_T_72 = io_instruction_i[12] ? 3'h7 : 3'h0; // @[Bitwise.scala 77:12]
  wire [31:0] _io_instruction_o_T_77 = {_io_instruction_o_T_72,io_instruction_i[4:3],io_instruction_i[5],
    io_instruction_i[2],io_instruction_i[6],24'h10113}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_8 = io_instruction_i[11:7] == 5'h2 ? _io_instruction_o_T_77 : _io_instruction_o_T_69; // @[CompressedDecoder.scala 118:28 120:62 122:31]
  wire [31:0] _io_instruction_o_T_82 = {1'h0,io_instruction_i[10],5'h0,io_instruction_i[6:2],2'h1,io_instruction_i[9:7],3'h5
    ,2'h1,io_instruction_i[9:7],7'h13}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_95 = {_io_instruction_o_T_23,io_instruction_i[12],io_instruction_i[6:2],2'h1,
    io_instruction_i[9:7],5'h1d,io_instruction_i[9:7],7'h13}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_99 = {9'h81,io_instruction_i[4:2],2'h1,io_instruction_i[9:7],3'h0,2'h1,
    io_instruction_i[9:7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_104 = {9'h1,io_instruction_i[4:2],2'h1,io_instruction_i[9:7],5'h11,io_instruction_i[9:
    7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_109 = {9'h1,io_instruction_i[4:2],2'h1,io_instruction_i[9:7],5'h19,io_instruction_i[9:
    7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_114 = {9'h1,io_instruction_i[4:2],2'h1,io_instruction_i[9:7],5'h1d,io_instruction_i[9:
    7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_10 = 2'h3 == io_instruction_i[6:5] ? _io_instruction_o_T_114 : io_instruction_i; // @[CompressedDecoder.scala 154:46 180:36 35:20]
  wire  _GEN_11 = 2'h2 == io_instruction_i[6:5] | 2'h3 == io_instruction_i[6:5]; // @[CompressedDecoder.scala 154:46 172:30]
  wire [31:0] _GEN_12 = 2'h2 == io_instruction_i[6:5] ? _io_instruction_o_T_109 : _GEN_10; // @[CompressedDecoder.scala 154:46 173:36]
  wire  _GEN_13 = 2'h1 == io_instruction_i[6:5] | _GEN_11; // @[CompressedDecoder.scala 154:46 165:30]
  wire [31:0] _GEN_14 = 2'h1 == io_instruction_i[6:5] ? _io_instruction_o_T_104 : _GEN_12; // @[CompressedDecoder.scala 154:46 166:36]
  wire  _GEN_15 = 2'h0 == io_instruction_i[6:5] | _GEN_13; // @[CompressedDecoder.scala 154:46 158:30]
  wire [31:0] _GEN_16 = 2'h0 == io_instruction_i[6:5] ? _io_instruction_o_T_99 : _GEN_14; // @[CompressedDecoder.scala 154:46 159:36]
  wire  _GEN_17 = 2'h3 == io_instruction_i[11:10] & _GEN_15; // @[CompressedDecoder.scala 129:44 34:14]
  wire [31:0] _GEN_18 = 2'h3 == io_instruction_i[11:10] ? _GEN_16 : io_instruction_i; // @[CompressedDecoder.scala 129:44 35:20]
  wire  _GEN_19 = 2'h2 == io_instruction_i[11:10] | _GEN_17; // @[CompressedDecoder.scala 129:44 147:26]
  wire [31:0] _GEN_20 = 2'h2 == io_instruction_i[11:10] ? _io_instruction_o_T_95 : _GEN_18; // @[CompressedDecoder.scala 129:44 148:32]
  wire  _GEN_21 = 2'h1 == io_instruction_i[11:10] | _GEN_19; // @[CompressedDecoder.scala 129:44 140:26]
  wire [31:0] _GEN_22 = 2'h1 == io_instruction_i[11:10] ? _io_instruction_o_T_82 : _GEN_20; // @[CompressedDecoder.scala 129:44 141:32]
  wire  _GEN_23 = 2'h0 == io_instruction_i[11:10] | _GEN_21; // @[CompressedDecoder.scala 129:44 133:26]
  wire [31:0] _GEN_24 = 2'h0 == io_instruction_i[11:10] ? _io_instruction_o_T_82 : _GEN_22; // @[CompressedDecoder.scala 129:44 134:32]
  wire [3:0] _io_instruction_o_T_117 = io_instruction_i[12] ? 4'hf : 4'h0; // @[Bitwise.scala 77:12]
  wire [14:0] io_instruction_o_lo_16 = {2'h0,io_instruction_i[13],io_instruction_i[11:10],io_instruction_i[4:3],
    io_instruction_i[12],7'h63}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_126 = {_io_instruction_o_T_117,io_instruction_i[6:5],io_instruction_i[2],7'h1,
    io_instruction_i[9:7],io_instruction_o_lo_16}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_26 = 3'h7 == io_instruction_i[15:13] ? _io_instruction_o_T_126 : io_instruction_i; // @[CompressedDecoder.scala 199:28 35:20 80:41]
  wire  _GEN_27 = 3'h6 == io_instruction_i[15:13] | 3'h7 == io_instruction_i[15:13]; // @[CompressedDecoder.scala 190:22 80:41]
  wire [31:0] _GEN_28 = 3'h6 == io_instruction_i[15:13] ? _io_instruction_o_T_126 : _GEN_26; // @[CompressedDecoder.scala 191:28 80:41]
  wire  _GEN_29 = 3'h4 == io_instruction_i[15:13] ? _GEN_23 : _GEN_27; // @[CompressedDecoder.scala 80:41]
  wire [31:0] _GEN_30 = 3'h4 == io_instruction_i[15:13] ? _GEN_24 : _GEN_28; // @[CompressedDecoder.scala 80:41]
  wire  _GEN_31 = 3'h3 == io_instruction_i[15:13] | _GEN_29; // @[CompressedDecoder.scala 117:22 80:41]
  wire [31:0] _GEN_32 = 3'h3 == io_instruction_i[15:13] ? _GEN_8 : _GEN_30; // @[CompressedDecoder.scala 80:41]
  wire  _GEN_33 = 3'h2 == io_instruction_i[15:13] | _GEN_31; // @[CompressedDecoder.scala 109:22 80:41]
  wire [31:0] _GEN_34 = 3'h2 == io_instruction_i[15:13] ? _io_instruction_o_T_63 : _GEN_32; // @[CompressedDecoder.scala 110:28 80:41]
  wire  _GEN_35 = 3'h5 == io_instruction_i[15:13] | _GEN_33; // @[CompressedDecoder.scala 100:22 80:41]
  wire [31:0] _GEN_36 = 3'h5 == io_instruction_i[15:13] ? _io_instruction_o_T_42 : _GEN_34; // @[CompressedDecoder.scala 101:28 80:41]
  wire  _GEN_37 = 3'h1 == io_instruction_i[15:13] | _GEN_35; // @[CompressedDecoder.scala 80:41 92:22]
  wire [31:0] _GEN_38 = 3'h1 == io_instruction_i[15:13] ? _io_instruction_o_T_42 : _GEN_36; // @[CompressedDecoder.scala 80:41 93:28]
  wire  _GEN_39 = 3'h0 == io_instruction_i[15:13] | _GEN_37; // @[CompressedDecoder.scala 80:41 85:22]
  wire [31:0] _GEN_40 = 3'h0 == io_instruction_i[15:13] ? _io_instruction_o_T_28 : _GEN_38; // @[CompressedDecoder.scala 80:41 86:28]
  wire [31:0] _io_instruction_o_T_143 = {7'h0,io_instruction_i[6:2],io_instruction_i[11:7],3'h1,io_instruction_i[11:7],7'h13
    }; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_149 = {4'h0,io_instruction_i[3:2],io_instruction_i[12],io_instruction_i[6:4],2'h0,8'h12
    ,io_instruction_i[11:7],7'h3}; // @[Cat.scala 33:92]
  wire  _T_37 = io_instruction_i[6:2] != 5'h0; // @[CompressedDecoder.scala 235:40]
  wire [31:0] _io_instruction_o_T_154 = {7'h0,io_instruction_i[6:2],8'h0,io_instruction_i[11:7],7'h33}; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_158 = {12'h0,io_instruction_i[11:7],15'h67}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_42 = io_instruction_i[6:2] != 5'h0 ? _io_instruction_o_T_154 : _io_instruction_o_T_158; // @[CompressedDecoder.scala 235:62 240:32 245:32]
  wire [31:0] _io_instruction_o_T_163 = {7'h0,io_instruction_i[6:2],io_instruction_i[11:7],3'h0,io_instruction_i[11:7],7'h33
    }; // @[Cat.scala 33:92]
  wire [31:0] _io_instruction_o_T_167 = {12'h0,io_instruction_i[11:7],7'h0,8'he7}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_44 = io_instruction_i[11:7] == 5'h0 ? 32'h100073 : _io_instruction_o_T_167; // @[CompressedDecoder.scala 256:65 259:34 263:34]
  wire [31:0] _GEN_46 = _T_37 ? _io_instruction_o_T_163 : _GEN_44; // @[CompressedDecoder.scala 249:62 253:32]
  wire [31:0] _GEN_48 = ~io_instruction_i[12] ? _GEN_42 : _GEN_46; // @[CompressedDecoder.scala 233:50]
  wire [31:0] _io_instruction_o_T_173 = {4'h0,io_instruction_i[8:7],io_instruction_i[12],io_instruction_i[6:2],5'h2,3'h2
    ,io_instruction_i[11:9],9'h23}; // @[Cat.scala 33:92]
  wire [31:0] _GEN_50 = _T_5 ? _io_instruction_o_T_173 : io_instruction_i; // @[CompressedDecoder.scala 214:40 272:28 35:20]
  wire [31:0] _GEN_52 = _T_6 ? _GEN_48 : _GEN_50; // @[CompressedDecoder.scala 214:40]
  wire  _GEN_53 = _T_4 | (_T_6 | _T_5); // @[CompressedDecoder.scala 214:40 226:22]
  wire [31:0] _GEN_54 = _T_4 ? _io_instruction_o_T_149 : _GEN_52; // @[CompressedDecoder.scala 214:40 227:28]
  wire  _GEN_55 = _T_3 | _GEN_53; // @[CompressedDecoder.scala 214:40 219:22]
  wire [31:0] _GEN_56 = _T_3 ? _io_instruction_o_T_143 : _GEN_54; // @[CompressedDecoder.scala 214:40 220:28]
  wire [31:0] _GEN_60 = 2'h2 == io_instruction_i[1:0] ? _GEN_56 : io_instruction_i; // @[CompressedDecoder.scala 37:34]
  wire  _GEN_61 = 2'h1 == io_instruction_i[1:0] ? _GEN_39 : 2'h2 == io_instruction_i[1:0] & _GEN_55; // @[CompressedDecoder.scala 37:34]
  wire [31:0] _GEN_62 = 2'h1 == io_instruction_i[1:0] ? _GEN_40 : _GEN_60; // @[CompressedDecoder.scala 37:34]
  wire  _GEN_63 = 2'h0 == io_instruction_i[1:0] ? _GEN_6 : _GEN_61; // @[CompressedDecoder.scala 37:34]
  wire [31:0] _GEN_64 = 2'h0 == io_instruction_i[1:0] ? _GEN_7 : _GEN_62; // @[CompressedDecoder.scala 37:34]
  assign io_is_comp = io_instruction_i == 32'h0 ? 1'h0 : _GEN_63; // @[CompressedDecoder.scala 285:47 287:18]
  assign io_instruction_o = io_instruction_i == 32'h0 ? io_instruction_i : _GEN_64; // @[CompressedDecoder.scala 285:47 288:24]
endmodule
module Core(
  input         clock,
  input         reset,
  output [31:0] io_pin,
  output        io_dmemReq_valid,
  output [31:0] io_dmemReq_bits_addrRequest,
  output [31:0] io_dmemReq_bits_dataRequest,
  output [3:0]  io_dmemReq_bits_activeByteLane,
  output        io_dmemReq_bits_isWrite,
  input         io_dmemRsp_valid,
  input  [31:0] io_dmemRsp_bits_dataResponse,
  output        io_imemReq_valid,
  output [31:0] io_imemReq_bits_addrRequest,
  input         io_imemRsp_valid,
  input  [31:0] io_imemRsp_bits_dataResponse,
  output [31:0] io_rvfiUInt_0,
  output [31:0] io_rvfiUInt_1,
  output [31:0] io_rvfiUInt_2,
  output [31:0] io_rvfiUInt_3,
  output [31:0] io_rvfiSInt_0,
  output [31:0] io_rvfiSInt_1,
  output [31:0] io_rvfiSInt_2,
  output [31:0] io_rvfiSInt_3,
  output [31:0] io_rvfiSInt_4,
  output        io_rvfiBool_0,
  output [4:0]  io_rvfiRegAddr_0,
  output [4:0]  io_rvfiRegAddr_1,
  output [4:0]  io_rvfiRegAddr_2,
  output [31:0] io_fcsr_o_data
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
  reg [31:0] _RAND_52;
  reg [31:0] _RAND_53;
  reg [31:0] _RAND_54;
  reg [31:0] _RAND_55;
  reg [31:0] _RAND_56;
  reg [31:0] _RAND_57;
  reg [31:0] _RAND_58;
  reg [31:0] _RAND_59;
  reg [31:0] _RAND_60;
  reg [31:0] _RAND_61;
`endif // RANDOMIZE_REG_INIT
  wire  InstructionFetch_reset; // @[Core.scala 87:18]
  wire [31:0] InstructionFetch_io_address; // @[Core.scala 87:18]
  wire [31:0] InstructionFetch_io_instruction; // @[Core.scala 87:18]
  wire  InstructionFetch_io_stall; // @[Core.scala 87:18]
  wire  InstructionFetch_io_coreInstrReq_valid; // @[Core.scala 87:18]
  wire [31:0] InstructionFetch_io_coreInstrReq_bits_addrRequest; // @[Core.scala 87:18]
  wire  InstructionFetch_io_coreInstrResp_valid; // @[Core.scala 87:18]
  wire [31:0] InstructionFetch_io_coreInstrResp_bits_dataResponse; // @[Core.scala 87:18]
  wire  InstructionDecode_clock; // @[Core.scala 88:18]
  wire  InstructionDecode_reset; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_id_instruction; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_writeData; // @[Core.scala 88:18]
  wire [4:0] InstructionDecode_io_writeReg; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_pcAddress; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ctl_writeEnable; // @[Core.scala 88:18]
  wire  InstructionDecode_io_id_ex_mem_read; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ex_mem_mem_read; // @[Core.scala 88:18]
  wire [4:0] InstructionDecode_io_id_ex_rd; // @[Core.scala 88:18]
  wire [4:0] InstructionDecode_io_ex_mem_rd; // @[Core.scala 88:18]
  wire  InstructionDecode_io_id_ex_branch; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_ex_mem_ins; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_mem_wb_ins; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_ex_ins; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_ex_result; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_ex_mem_result; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_mem_wb_result; // @[Core.scala 88:18]
  wire  InstructionDecode_io_id_ex_regWr; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ex_mem_regWr; // @[Core.scala 88:18]
  wire  InstructionDecode_io_csr_Ex; // @[Core.scala 88:18]
  wire  InstructionDecode_io_csr_Mem; // @[Core.scala 88:18]
  wire  InstructionDecode_io_csr_Wb; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_csr_Ex_data; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_csr_Mem_data; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_csr_Wb_data; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_dmem_data; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_immediate; // @[Core.scala 88:18]
  wire [4:0] InstructionDecode_io_writeRegAddress; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_readData1; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_readData2; // @[Core.scala 88:18]
  wire [6:0] InstructionDecode_io_func7; // @[Core.scala 88:18]
  wire [2:0] InstructionDecode_io_func3; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ctl_aluSrc; // @[Core.scala 88:18]
  wire [1:0] InstructionDecode_io_ctl_memToReg; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ctl_regWrite; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ctl_memRead; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ctl_memWrite; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ctl_branch; // @[Core.scala 88:18]
  wire [1:0] InstructionDecode_io_ctl_aluOp; // @[Core.scala 88:18]
  wire [1:0] InstructionDecode_io_ctl_jump; // @[Core.scala 88:18]
  wire [1:0] InstructionDecode_io_ctl_aluSrc1; // @[Core.scala 88:18]
  wire  InstructionDecode_io_hdu_pcWrite; // @[Core.scala 88:18]
  wire  InstructionDecode_io_hdu_if_reg_write; // @[Core.scala 88:18]
  wire  InstructionDecode_io_pcSrc; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_pcPlusOffset; // @[Core.scala 88:18]
  wire  InstructionDecode_io_ifid_flush; // @[Core.scala 88:18]
  wire  InstructionDecode_io_stall; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_csr_o_data; // @[Core.scala 88:18]
  wire  InstructionDecode_io_is_csr; // @[Core.scala 88:18]
  wire [31:0] InstructionDecode_io_fscr_o_data; // @[Core.scala 88:18]
  wire [4:0] InstructionDecode_io_rs_addr_0; // @[Core.scala 88:18]
  wire [4:0] InstructionDecode_io_rs_addr_1; // @[Core.scala 88:18]
  wire  Execute_clock; // @[Core.scala 89:18]
  wire  Execute_reset; // @[Core.scala 89:18]
  wire [31:0] Execute_io_immediate; // @[Core.scala 89:18]
  wire [31:0] Execute_io_readData1; // @[Core.scala 89:18]
  wire [31:0] Execute_io_readData2; // @[Core.scala 89:18]
  wire [31:0] Execute_io_pcAddress; // @[Core.scala 89:18]
  wire [6:0] Execute_io_func7; // @[Core.scala 89:18]
  wire [2:0] Execute_io_func3; // @[Core.scala 89:18]
  wire [31:0] Execute_io_mem_result; // @[Core.scala 89:18]
  wire [31:0] Execute_io_wb_result; // @[Core.scala 89:18]
  wire  Execute_io_ex_mem_regWrite; // @[Core.scala 89:18]
  wire  Execute_io_mem_wb_regWrite; // @[Core.scala 89:18]
  wire [31:0] Execute_io_id_ex_ins; // @[Core.scala 89:18]
  wire [31:0] Execute_io_ex_mem_ins; // @[Core.scala 89:18]
  wire [31:0] Execute_io_mem_wb_ins; // @[Core.scala 89:18]
  wire  Execute_io_ctl_aluSrc; // @[Core.scala 89:18]
  wire [1:0] Execute_io_ctl_aluOp; // @[Core.scala 89:18]
  wire [1:0] Execute_io_ctl_aluSrc1; // @[Core.scala 89:18]
  wire [31:0] Execute_io_writeData; // @[Core.scala 89:18]
  wire [31:0] Execute_io_ALUresult; // @[Core.scala 89:18]
  wire  Execute_io_stall; // @[Core.scala 89:18]
  wire  MEM_clock; // @[Core.scala 90:19]
  wire  MEM_reset; // @[Core.scala 90:19]
  wire [31:0] MEM_io_aluResultIn; // @[Core.scala 90:19]
  wire [31:0] MEM_io_writeData; // @[Core.scala 90:19]
  wire  MEM_io_writeEnable; // @[Core.scala 90:19]
  wire  MEM_io_readEnable; // @[Core.scala 90:19]
  wire [31:0] MEM_io_readData; // @[Core.scala 90:19]
  wire [2:0] MEM_io_f3; // @[Core.scala 90:19]
  wire  MEM_io_dccmReq_valid; // @[Core.scala 90:19]
  wire [31:0] MEM_io_dccmReq_bits_addrRequest; // @[Core.scala 90:19]
  wire [31:0] MEM_io_dccmReq_bits_dataRequest; // @[Core.scala 90:19]
  wire [3:0] MEM_io_dccmReq_bits_activeByteLane; // @[Core.scala 90:19]
  wire  MEM_io_dccmReq_bits_isWrite; // @[Core.scala 90:19]
  wire  MEM_io_dccmRsp_valid; // @[Core.scala 90:19]
  wire [31:0] MEM_io_dccmRsp_bits_dataResponse; // @[Core.scala 90:19]
  wire  pc_clock; // @[Core.scala 98:18]
  wire  pc_reset; // @[Core.scala 98:18]
  wire [31:0] pc_io_in; // @[Core.scala 98:18]
  wire  pc_io_halt; // @[Core.scala 98:18]
  wire [31:0] pc_io_out; // @[Core.scala 98:18]
  wire [31:0] pc_io_pc4; // @[Core.scala 98:18]
  wire [31:0] pc_io_pc2; // @[Core.scala 98:18]
  wire  Realigner_clock; // @[Core.scala 115:20]
  wire  Realigner_reset; // @[Core.scala 115:20]
  wire [31:0] Realigner_io_ral_address_i; // @[Core.scala 115:20]
  wire [31:0] Realigner_io_ral_instruction_i; // @[Core.scala 115:20]
  wire  Realigner_io_ral_jmp; // @[Core.scala 115:20]
  wire [31:0] Realigner_io_ral_address_o; // @[Core.scala 115:20]
  wire [31:0] Realigner_io_ral_instruction_o; // @[Core.scala 115:20]
  wire  Realigner_io_ral_halt_o; // @[Core.scala 115:20]
  wire [31:0] CompressedDecoder_io_instruction_i; // @[Core.scala 129:20]
  wire  CompressedDecoder_io_is_comp; // @[Core.scala 129:20]
  wire [31:0] CompressedDecoder_io_instruction_o; // @[Core.scala 129:20]
  reg [31:0] if_reg_pc; // @[Core.scala 34:26]
  reg [31:0] if_reg_ins; // @[Core.scala 35:27]
  reg [31:0] id_reg_pc; // @[Core.scala 38:26]
  reg [31:0] id_reg_rd1; // @[Core.scala 39:27]
  reg [31:0] id_reg_rd2; // @[Core.scala 40:27]
  reg [31:0] id_reg_imm; // @[Core.scala 41:27]
  reg [4:0] id_reg_wra; // @[Core.scala 42:27]
  reg [6:0] id_reg_f7; // @[Core.scala 43:26]
  reg [2:0] id_reg_f3; // @[Core.scala 44:26]
  reg [31:0] id_reg_ins; // @[Core.scala 45:27]
  reg  id_reg_ctl_aluSrc; // @[Core.scala 46:34]
  reg [1:0] id_reg_ctl_aluSrc1; // @[Core.scala 47:35]
  reg [1:0] id_reg_ctl_memToReg; // @[Core.scala 48:36]
  reg  id_reg_ctl_regWrite; // @[Core.scala 49:36]
  reg  id_reg_ctl_memRead; // @[Core.scala 50:35]
  reg  id_reg_ctl_memWrite; // @[Core.scala 51:36]
  reg [1:0] id_reg_ctl_aluOp; // @[Core.scala 53:33]
  reg  id_reg_is_csr; // @[Core.scala 55:30]
  reg [31:0] id_reg_csr_data; // @[Core.scala 56:32]
  reg [31:0] ex_reg_result; // @[Core.scala 61:30]
  reg [31:0] ex_reg_wd; // @[Core.scala 62:26]
  reg [4:0] ex_reg_wra; // @[Core.scala 63:27]
  reg [31:0] ex_reg_ins; // @[Core.scala 64:27]
  reg [1:0] ex_reg_ctl_memToReg; // @[Core.scala 65:36]
  reg  ex_reg_ctl_regWrite; // @[Core.scala 66:36]
  reg  ex_reg_ctl_memRead; // @[Core.scala 67:35]
  reg  ex_reg_ctl_memWrite; // @[Core.scala 68:36]
  reg [31:0] ex_reg_pc; // @[Core.scala 70:26]
  reg  ex_reg_is_csr; // @[Core.scala 71:30]
  reg [31:0] ex_reg_csr_data; // @[Core.scala 72:32]
  reg [31:0] mem_reg_ins; // @[Core.scala 76:28]
  reg [31:0] mem_reg_result; // @[Core.scala 77:31]
  reg [4:0] mem_reg_wra; // @[Core.scala 79:28]
  reg [1:0] mem_reg_ctl_memToReg; // @[Core.scala 80:37]
  reg  mem_reg_ctl_regWrite; // @[Core.scala 81:37]
  reg [31:0] mem_reg_pc; // @[Core.scala 82:27]
  reg  mem_reg_is_csr; // @[Core.scala 83:31]
  reg [31:0] mem_reg_csr_data; // @[Core.scala 84:33]
  wire [31:0] instruction = CompressedDecoder_io_instruction_o; // @[Core.scala 103:25 132:18]
  wire [2:0] func3 = instruction[14:12]; // @[Core.scala 146:26]
  wire [6:0] _GEN_0 = instruction[6:0] == 7'h33 ? instruction[31:25] : 7'h0; // @[Core.scala 148:42 149:11 151:11]
  wire [5:0] func7 = _GEN_0[5:0]; // @[Core.scala 147:19]
  wire  IF_stall = func7 == 6'h1 & (func3 == 3'h4 | func3 == 3'h5 | func3 == 3'h6 | func3 == 3'h7); // @[Core.scala 154:32]
  wire  ral_halt_o = Realigner_io_ral_halt_o; // @[Core.scala 104:29 124:26]
  wire  is_comp = CompressedDecoder_io_is_comp; // @[Core.scala 105:29 134:13]
  wire [31:0] _npc_T_1 = is_comp ? $signed(pc_io_pc2) : $signed(pc_io_pc4); // @[Core.scala 160:76]
  wire [31:0] _npc_T_2 = InstructionDecode_io_pcSrc ? $signed(InstructionDecode_io_pcPlusOffset) : $signed(_npc_T_1); // @[Core.scala 160:36]
  wire [31:0] _wb_data_T_1 = mem_reg_pc + 32'h4; // @[Core.scala 322:28]
  wire [31:0] _GEN_6 = mem_reg_ctl_memToReg == 2'h2 ? _wb_data_T_1 : mem_reg_result; // @[Core.scala 321:44 322:15 326:15]
  reg [31:0] npcDelay_0; // @[Core.scala 345:23]
  reg [31:0] npcDelay_1; // @[Core.scala 345:23]
  reg [31:0] npcDelay_2; // @[Core.scala 345:23]
  reg [31:0] npcDelay_3; // @[Core.scala 345:23]
  reg [4:0] rsAddrDelay_0_0; // @[Core.scala 346:53]
  reg [4:0] rsAddrDelay_0_1; // @[Core.scala 346:53]
  reg [4:0] rsAddrDelay_0_2; // @[Core.scala 346:53]
  reg [4:0] rsAddrDelay_1_0; // @[Core.scala 346:53]
  reg [4:0] rsAddrDelay_1_1; // @[Core.scala 346:53]
  reg [4:0] rsAddrDelay_1_2; // @[Core.scala 346:53]
  reg [31:0] rsDataDelay_0_0; // @[Core.scala 347:53]
  reg [31:0] rsDataDelay_0_1; // @[Core.scala 347:53]
  reg [31:0] rsDataDelay_1_0; // @[Core.scala 347:53]
  reg [31:0] rsDataDelay_1_1; // @[Core.scala 347:53]
  reg [31:0] memAddrDelay; // @[Core.scala 348:31]
  reg [31:0] memWdataDelay; // @[Core.scala 349:32]
  reg  stallDelay_0; // @[Core.scala 350:25]
  reg  stallDelay_1; // @[Core.scala 350:25]
  reg  stallDelay_2; // @[Core.scala 350:25]
  reg  stallDelay_3; // @[Core.scala 350:25]
  reg [31:0] insDelay_0; // @[Core.scala 351:45]
  reg [31:0] insDelay_1; // @[Core.scala 351:45]
  reg [31:0] insDelay_2; // @[Core.scala 351:45]
  reg [31:0] insDelay_3; // @[Core.scala 351:45]
  wire [31:0] c_ins_trace = InstructionFetch_io_instruction; // @[Core.scala 107:51 136:21]
  InstructionFetch InstructionFetch ( // @[Core.scala 87:18]
    .reset(InstructionFetch_reset),
    .io_address(InstructionFetch_io_address),
    .io_instruction(InstructionFetch_io_instruction),
    .io_stall(InstructionFetch_io_stall),
    .io_coreInstrReq_valid(InstructionFetch_io_coreInstrReq_valid),
    .io_coreInstrReq_bits_addrRequest(InstructionFetch_io_coreInstrReq_bits_addrRequest),
    .io_coreInstrResp_valid(InstructionFetch_io_coreInstrResp_valid),
    .io_coreInstrResp_bits_dataResponse(InstructionFetch_io_coreInstrResp_bits_dataResponse)
  );
  InstructionDecode InstructionDecode ( // @[Core.scala 88:18]
    .clock(InstructionDecode_clock),
    .reset(InstructionDecode_reset),
    .io_id_instruction(InstructionDecode_io_id_instruction),
    .io_writeData(InstructionDecode_io_writeData),
    .io_writeReg(InstructionDecode_io_writeReg),
    .io_pcAddress(InstructionDecode_io_pcAddress),
    .io_ctl_writeEnable(InstructionDecode_io_ctl_writeEnable),
    .io_id_ex_mem_read(InstructionDecode_io_id_ex_mem_read),
    .io_ex_mem_mem_read(InstructionDecode_io_ex_mem_mem_read),
    .io_id_ex_rd(InstructionDecode_io_id_ex_rd),
    .io_ex_mem_rd(InstructionDecode_io_ex_mem_rd),
    .io_id_ex_branch(InstructionDecode_io_id_ex_branch),
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
    .io_immediate(InstructionDecode_io_immediate),
    .io_writeRegAddress(InstructionDecode_io_writeRegAddress),
    .io_readData1(InstructionDecode_io_readData1),
    .io_readData2(InstructionDecode_io_readData2),
    .io_func7(InstructionDecode_io_func7),
    .io_func3(InstructionDecode_io_func3),
    .io_ctl_aluSrc(InstructionDecode_io_ctl_aluSrc),
    .io_ctl_memToReg(InstructionDecode_io_ctl_memToReg),
    .io_ctl_regWrite(InstructionDecode_io_ctl_regWrite),
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
    .io_csr_o_data(InstructionDecode_io_csr_o_data),
    .io_is_csr(InstructionDecode_io_is_csr),
    .io_fscr_o_data(InstructionDecode_io_fscr_o_data),
    .io_rs_addr_0(InstructionDecode_io_rs_addr_0),
    .io_rs_addr_1(InstructionDecode_io_rs_addr_1)
  );
  Execute Execute ( // @[Core.scala 89:18]
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
    .io_ex_mem_regWrite(Execute_io_ex_mem_regWrite),
    .io_mem_wb_regWrite(Execute_io_mem_wb_regWrite),
    .io_id_ex_ins(Execute_io_id_ex_ins),
    .io_ex_mem_ins(Execute_io_ex_mem_ins),
    .io_mem_wb_ins(Execute_io_mem_wb_ins),
    .io_ctl_aluSrc(Execute_io_ctl_aluSrc),
    .io_ctl_aluOp(Execute_io_ctl_aluOp),
    .io_ctl_aluSrc1(Execute_io_ctl_aluSrc1),
    .io_writeData(Execute_io_writeData),
    .io_ALUresult(Execute_io_ALUresult),
    .io_stall(Execute_io_stall)
  );
  MemoryFetch MEM ( // @[Core.scala 90:19]
    .clock(MEM_clock),
    .reset(MEM_reset),
    .io_aluResultIn(MEM_io_aluResultIn),
    .io_writeData(MEM_io_writeData),
    .io_writeEnable(MEM_io_writeEnable),
    .io_readEnable(MEM_io_readEnable),
    .io_readData(MEM_io_readData),
    .io_f3(MEM_io_f3),
    .io_dccmReq_valid(MEM_io_dccmReq_valid),
    .io_dccmReq_bits_addrRequest(MEM_io_dccmReq_bits_addrRequest),
    .io_dccmReq_bits_dataRequest(MEM_io_dccmReq_bits_dataRequest),
    .io_dccmReq_bits_activeByteLane(MEM_io_dccmReq_bits_activeByteLane),
    .io_dccmReq_bits_isWrite(MEM_io_dccmReq_bits_isWrite),
    .io_dccmRsp_valid(MEM_io_dccmRsp_valid),
    .io_dccmRsp_bits_dataResponse(MEM_io_dccmRsp_bits_dataResponse)
  );
  PC pc ( // @[Core.scala 98:18]
    .clock(pc_clock),
    .reset(pc_reset),
    .io_in(pc_io_in),
    .io_halt(pc_io_halt),
    .io_out(pc_io_out),
    .io_pc4(pc_io_pc4),
    .io_pc2(pc_io_pc2)
  );
  Realigner Realigner ( // @[Core.scala 115:20]
    .clock(Realigner_clock),
    .reset(Realigner_reset),
    .io_ral_address_i(Realigner_io_ral_address_i),
    .io_ral_instruction_i(Realigner_io_ral_instruction_i),
    .io_ral_jmp(Realigner_io_ral_jmp),
    .io_ral_address_o(Realigner_io_ral_address_o),
    .io_ral_instruction_o(Realigner_io_ral_instruction_o),
    .io_ral_halt_o(Realigner_io_ral_halt_o)
  );
  CompressedDecoder CompressedDecoder ( // @[Core.scala 129:20]
    .io_instruction_i(CompressedDecoder_io_instruction_i),
    .io_is_comp(CompressedDecoder_io_is_comp),
    .io_instruction_o(CompressedDecoder_io_instruction_o)
  );
  assign io_pin = mem_reg_ctl_memToReg == 2'h1 ? MEM_io_readData : _GEN_6; // @[Core.scala 318:38 319:13]
  assign io_dmemReq_valid = MEM_io_dccmReq_valid; // @[Core.scala 263:14]
  assign io_dmemReq_bits_addrRequest = MEM_io_dccmReq_bits_addrRequest; // @[Core.scala 263:14]
  assign io_dmemReq_bits_dataRequest = MEM_io_dccmReq_bits_dataRequest; // @[Core.scala 263:14]
  assign io_dmemReq_bits_activeByteLane = MEM_io_dccmReq_bits_activeByteLane; // @[Core.scala 263:14]
  assign io_dmemReq_bits_isWrite = MEM_io_dccmReq_bits_isWrite; // @[Core.scala 263:14]
  assign io_imemReq_valid = InstructionFetch_io_coreInstrReq_valid; // @[Core.scala 100:14]
  assign io_imemReq_bits_addrRequest = InstructionFetch_io_coreInstrReq_bits_addrRequest; // @[Core.scala 100:14]
  assign io_rvfiUInt_0 = mem_reg_pc; // @[Core.scala 398:19]
  assign io_rvfiUInt_1 = npcDelay_3; // @[Core.scala 398:19]
  assign io_rvfiUInt_2 = insDelay_3; // @[Core.scala 398:19]
  assign io_rvfiUInt_3 = memAddrDelay; // @[Core.scala 398:19]
  assign io_rvfiSInt_0 = mem_reg_ctl_memToReg == 2'h1 ? MEM_io_readData : _GEN_6; // @[Core.scala 392:36]
  assign io_rvfiSInt_1 = rsDataDelay_0_1; // @[Core.scala 361:30]
  assign io_rvfiSInt_2 = rsDataDelay_1_1; // @[Core.scala 361:30]
  assign io_rvfiSInt_3 = MEM_io_readData; // @[Core.scala 393:44]
  assign io_rvfiSInt_4 = memWdataDelay; // @[Core.scala 398:19]
  assign io_rvfiBool_0 = stallDelay_3; // @[Core.scala 398:19]
  assign io_rvfiRegAddr_0 = mem_reg_wra; // @[Core.scala 318:38 320:13]
  assign io_rvfiRegAddr_1 = rsAddrDelay_0_2; // @[Core.scala 358:33]
  assign io_rvfiRegAddr_2 = rsAddrDelay_1_2; // @[Core.scala 358:33]
  assign io_fcsr_o_data = InstructionDecode_io_fscr_o_data; // @[Core.scala 92:18]
  assign InstructionFetch_reset = reset;
  assign InstructionFetch_io_address = Realigner_io_ral_address_o; // @[Core.scala 121:26]
  assign InstructionFetch_io_stall = Execute_io_stall | InstructionDecode_io_stall | IF_stall; // @[Core.scala 156:48]
  assign InstructionFetch_io_coreInstrResp_valid = io_imemRsp_valid; // @[Core.scala 101:20]
  assign InstructionFetch_io_coreInstrResp_bits_dataResponse = io_imemRsp_bits_dataResponse; // @[Core.scala 101:20]
  assign InstructionDecode_clock = clock;
  assign InstructionDecode_reset = reset;
  assign InstructionDecode_io_id_instruction = if_reg_ins; // @[Core.scala 196:21]
  assign InstructionDecode_io_writeData = mem_reg_ctl_memToReg == 2'h1 ? MEM_io_readData : _GEN_6; // @[Core.scala 318:38 319:13]
  assign InstructionDecode_io_writeReg = mem_reg_wra; // @[Core.scala 318:38 320:13]
  assign InstructionDecode_io_pcAddress = if_reg_pc; // @[Core.scala 197:16]
  assign InstructionDecode_io_ctl_writeEnable = mem_reg_ctl_regWrite; // @[Core.scala 335:22]
  assign InstructionDecode_io_id_ex_mem_read = id_reg_ctl_memRead; // @[Core.scala 239:21]
  assign InstructionDecode_io_ex_mem_mem_read = ex_reg_ctl_memRead; // @[Core.scala 240:22]
  assign InstructionDecode_io_id_ex_rd = id_reg_ins[11:7]; // @[Core.scala 247:28]
  assign InstructionDecode_io_ex_mem_rd = ex_reg_ins[11:7]; // @[Core.scala 249:29]
  assign InstructionDecode_io_id_ex_branch = id_reg_ins[6:0] == 7'h63; // @[Core.scala 248:42]
  assign InstructionDecode_io_ex_mem_ins = ex_reg_ins; // @[Core.scala 202:17]
  assign InstructionDecode_io_mem_wb_ins = mem_reg_ins; // @[Core.scala 203:17]
  assign InstructionDecode_io_ex_ins = id_reg_ins; // @[Core.scala 201:13]
  assign InstructionDecode_io_ex_result = Execute_io_ALUresult; // @[Core.scala 250:16]
  assign InstructionDecode_io_ex_mem_result = ex_reg_result; // @[Core.scala 204:20]
  assign InstructionDecode_io_mem_wb_result = mem_reg_ctl_memToReg == 2'h1 ? MEM_io_readData : _GEN_6; // @[Core.scala 318:38 319:13]
  assign InstructionDecode_io_id_ex_regWr = id_reg_ctl_regWrite; // @[Core.scala 208:18]
  assign InstructionDecode_io_ex_mem_regWr = ex_reg_ctl_regWrite; // @[Core.scala 209:19]
  assign InstructionDecode_io_csr_Ex = id_reg_is_csr; // @[Core.scala 251:13]
  assign InstructionDecode_io_csr_Mem = ex_reg_is_csr; // @[Core.scala 308:14]
  assign InstructionDecode_io_csr_Wb = mem_reg_is_csr; // @[Core.scala 336:13]
  assign InstructionDecode_io_csr_Ex_data = id_reg_csr_data; // @[Core.scala 252:18]
  assign InstructionDecode_io_csr_Mem_data = ex_reg_csr_data; // @[Core.scala 309:19]
  assign InstructionDecode_io_csr_Wb_data = mem_reg_csr_data; // @[Core.scala 337:18]
  assign InstructionDecode_io_dmem_data = io_dmemRsp_bits_dataResponse; // @[Core.scala 338:16]
  assign Execute_clock = clock;
  assign Execute_reset = reset;
  assign Execute_io_immediate = id_reg_imm; // @[Core.scala 219:16]
  assign Execute_io_readData1 = id_reg_rd1; // @[Core.scala 220:16]
  assign Execute_io_readData2 = id_reg_rd2; // @[Core.scala 221:16]
  assign Execute_io_pcAddress = id_reg_pc; // @[Core.scala 222:16]
  assign Execute_io_func7 = id_reg_f7; // @[Core.scala 224:12]
  assign Execute_io_func3 = id_reg_f3; // @[Core.scala 223:12]
  assign Execute_io_mem_result = ex_reg_result; // @[Core.scala 307:17]
  assign Execute_io_wb_result = mem_reg_ctl_memToReg == 2'h1 ? MEM_io_readData : _GEN_6; // @[Core.scala 318:38 319:13]
  assign Execute_io_ex_mem_regWrite = ex_reg_ctl_regWrite; // @[Core.scala 301:22]
  assign Execute_io_mem_wb_regWrite = mem_reg_ctl_regWrite; // @[Core.scala 333:22]
  assign Execute_io_id_ex_ins = id_reg_ins; // @[Core.scala 244:16]
  assign Execute_io_ex_mem_ins = ex_reg_ins; // @[Core.scala 245:17]
  assign Execute_io_mem_wb_ins = mem_reg_ins; // @[Core.scala 246:17]
  assign Execute_io_ctl_aluSrc = id_reg_ctl_aluSrc; // @[Core.scala 225:17]
  assign Execute_io_ctl_aluOp = id_reg_ctl_aluOp; // @[Core.scala 226:16]
  assign Execute_io_ctl_aluSrc1 = id_reg_ctl_aluSrc1; // @[Core.scala 227:18]
  assign MEM_clock = clock;
  assign MEM_reset = reset;
  assign MEM_io_aluResultIn = ex_reg_result; // @[Core.scala 302:22]
  assign MEM_io_writeData = ex_reg_wd; // @[Core.scala 303:20]
  assign MEM_io_writeEnable = ex_reg_ctl_memWrite; // @[Core.scala 305:22]
  assign MEM_io_readEnable = ex_reg_ctl_memRead; // @[Core.scala 304:21]
  assign MEM_io_f3 = ex_reg_ins[14:12]; // @[Core.scala 306:26]
  assign MEM_io_dccmRsp_valid = io_dmemRsp_valid; // @[Core.scala 264:18]
  assign MEM_io_dccmRsp_bits_dataResponse = io_dmemRsp_bits_dataResponse; // @[Core.scala 264:18]
  assign pc_clock = clock;
  assign pc_reset = reset;
  assign pc_io_in = InstructionDecode_io_hdu_pcWrite ? $signed(_npc_T_2) : $signed(pc_io_out); // @[Core.scala 160:16]
  assign pc_io_halt = Execute_io_stall | InstructionDecode_io_stall | IF_stall | ~io_imemReq_valid | ral_halt_o; // @[Core.scala 159:78]
  assign Realigner_clock = clock;
  assign Realigner_reset = reset;
  assign Realigner_io_ral_address_i = pc_io_in; // @[Core.scala 117:44]
  assign Realigner_io_ral_instruction_i = InstructionFetch_io_instruction; // @[Core.scala 118:26]
  assign Realigner_io_ral_jmp = InstructionDecode_io_pcSrc; // @[Core.scala 119:26]
  assign CompressedDecoder_io_instruction_i = Realigner_io_ral_instruction_o; // @[Core.scala 131:22]
  always @(posedge clock) begin
    if (reset) begin // @[Core.scala 34:26]
      if_reg_pc <= 32'h0; // @[Core.scala 34:26]
    end else if (InstructionDecode_io_hdu_if_reg_write) begin // @[Core.scala 163:29]
      if_reg_pc <= pc_io_out; // @[Core.scala 164:15]
    end
    if (reset) begin // @[Core.scala 35:27]
      if_reg_ins <= 32'h0; // @[Core.scala 35:27]
    end else if (InstructionDecode_io_ifid_flush) begin // @[Core.scala 167:23]
      if_reg_ins <= 32'h0; // @[Core.scala 168:16]
    end else if (InstructionDecode_io_hdu_if_reg_write) begin // @[Core.scala 163:29]
      if_reg_ins <= instruction; // @[Core.scala 165:16]
    end
    if (reset) begin // @[Core.scala 38:26]
      id_reg_pc <= 32'h0; // @[Core.scala 38:26]
    end else begin
      id_reg_pc <= if_reg_pc; // @[Core.scala 183:13]
    end
    if (reset) begin // @[Core.scala 39:27]
      id_reg_rd1 <= 32'h0; // @[Core.scala 39:27]
    end else begin
      id_reg_rd1 <= InstructionDecode_io_readData1; // @[Core.scala 176:14]
    end
    if (reset) begin // @[Core.scala 40:27]
      id_reg_rd2 <= 32'h0; // @[Core.scala 40:27]
    end else begin
      id_reg_rd2 <= InstructionDecode_io_readData2; // @[Core.scala 177:14]
    end
    if (reset) begin // @[Core.scala 41:27]
      id_reg_imm <= 32'h0; // @[Core.scala 41:27]
    end else begin
      id_reg_imm <= InstructionDecode_io_immediate; // @[Core.scala 178:14]
    end
    if (reset) begin // @[Core.scala 42:27]
      id_reg_wra <= 5'h0; // @[Core.scala 42:27]
    end else if (!(Execute_io_stall)) begin // @[Core.scala 254:17]
      id_reg_wra <= InstructionDecode_io_writeRegAddress; // @[Core.scala 179:14]
    end
    if (reset) begin // @[Core.scala 43:26]
      id_reg_f7 <= 7'h0; // @[Core.scala 43:26]
    end else begin
      id_reg_f7 <= InstructionDecode_io_func7; // @[Core.scala 181:13]
    end
    if (reset) begin // @[Core.scala 44:26]
      id_reg_f3 <= 3'h0; // @[Core.scala 44:26]
    end else begin
      id_reg_f3 <= InstructionDecode_io_func3; // @[Core.scala 180:13]
    end
    if (reset) begin // @[Core.scala 45:27]
      id_reg_ins <= 32'h0; // @[Core.scala 45:27]
    end else begin
      id_reg_ins <= if_reg_ins; // @[Core.scala 182:14]
    end
    if (reset) begin // @[Core.scala 46:34]
      id_reg_ctl_aluSrc <= 1'h0; // @[Core.scala 46:34]
    end else begin
      id_reg_ctl_aluSrc <= InstructionDecode_io_ctl_aluSrc; // @[Core.scala 184:21]
    end
    if (reset) begin // @[Core.scala 47:35]
      id_reg_ctl_aluSrc1 <= 2'h0; // @[Core.scala 47:35]
    end else begin
      id_reg_ctl_aluSrc1 <= InstructionDecode_io_ctl_aluSrc1; // @[Core.scala 192:22]
    end
    if (reset) begin // @[Core.scala 48:36]
      id_reg_ctl_memToReg <= 2'h0; // @[Core.scala 48:36]
    end else begin
      id_reg_ctl_memToReg <= InstructionDecode_io_ctl_memToReg; // @[Core.scala 185:23]
    end
    if (reset) begin // @[Core.scala 49:36]
      id_reg_ctl_regWrite <= 1'h0; // @[Core.scala 49:36]
    end else if (!(Execute_io_stall)) begin // @[Core.scala 254:17]
      id_reg_ctl_regWrite <= InstructionDecode_io_ctl_regWrite; // @[Core.scala 186:23]
    end
    if (reset) begin // @[Core.scala 50:35]
      id_reg_ctl_memRead <= 1'h0; // @[Core.scala 50:35]
    end else begin
      id_reg_ctl_memRead <= InstructionDecode_io_ctl_memRead; // @[Core.scala 187:22]
    end
    if (reset) begin // @[Core.scala 51:36]
      id_reg_ctl_memWrite <= 1'h0; // @[Core.scala 51:36]
    end else begin
      id_reg_ctl_memWrite <= InstructionDecode_io_ctl_memWrite; // @[Core.scala 188:23]
    end
    if (reset) begin // @[Core.scala 53:33]
      id_reg_ctl_aluOp <= 2'h0; // @[Core.scala 53:33]
    end else begin
      id_reg_ctl_aluOp <= InstructionDecode_io_ctl_aluOp; // @[Core.scala 190:20]
    end
    if (reset) begin // @[Core.scala 55:30]
      id_reg_is_csr <= 1'h0; // @[Core.scala 55:30]
    end else begin
      id_reg_is_csr <= InstructionDecode_io_is_csr; // @[Core.scala 193:17]
    end
    if (reset) begin // @[Core.scala 56:32]
      id_reg_csr_data <= 32'h0; // @[Core.scala 56:32]
    end else begin
      id_reg_csr_data <= InstructionDecode_io_csr_o_data; // @[Core.scala 194:19]
    end
    if (reset) begin // @[Core.scala 61:30]
      ex_reg_result <= 32'h0; // @[Core.scala 61:30]
    end else begin
      ex_reg_result <= Execute_io_ALUresult; // @[Core.scala 295:19]
    end
    if (reset) begin // @[Core.scala 62:26]
      ex_reg_wd <= 32'h0; // @[Core.scala 62:26]
    end else begin
      ex_reg_wd <= Execute_io_writeData; // @[Core.scala 294:15]
    end
    if (reset) begin // @[Core.scala 63:27]
      ex_reg_wra <= 5'h0; // @[Core.scala 63:27]
    end else begin
      ex_reg_wra <= id_reg_wra; // @[Core.scala 231:14]
    end
    if (reset) begin // @[Core.scala 64:27]
      ex_reg_ins <= 32'h0; // @[Core.scala 64:27]
    end else begin
      ex_reg_ins <= id_reg_ins; // @[Core.scala 232:14]
    end
    if (reset) begin // @[Core.scala 65:36]
      ex_reg_ctl_memToReg <= 2'h0; // @[Core.scala 65:36]
    end else begin
      ex_reg_ctl_memToReg <= id_reg_ctl_memToReg; // @[Core.scala 233:23]
    end
    if (reset) begin // @[Core.scala 66:36]
      ex_reg_ctl_regWrite <= 1'h0; // @[Core.scala 66:36]
    end else begin
      ex_reg_ctl_regWrite <= id_reg_ctl_regWrite; // @[Core.scala 234:23]
    end
    if (reset) begin // @[Core.scala 67:35]
      ex_reg_ctl_memRead <= 1'h0; // @[Core.scala 67:35]
    end else begin
      ex_reg_ctl_memRead <= id_reg_ctl_memRead; // @[Core.scala 292:24]
    end
    if (reset) begin // @[Core.scala 68:36]
      ex_reg_ctl_memWrite <= 1'h0; // @[Core.scala 68:36]
    end else begin
      ex_reg_ctl_memWrite <= id_reg_ctl_memWrite; // @[Core.scala 293:25]
    end
    if (reset) begin // @[Core.scala 70:26]
      ex_reg_pc <= 32'h0; // @[Core.scala 70:26]
    end else begin
      ex_reg_pc <= id_reg_pc; // @[Core.scala 230:13]
    end
    if (reset) begin // @[Core.scala 71:30]
      ex_reg_is_csr <= 1'h0; // @[Core.scala 71:30]
    end else begin
      ex_reg_is_csr <= id_reg_is_csr; // @[Core.scala 235:17]
    end
    if (reset) begin // @[Core.scala 72:32]
      ex_reg_csr_data <= 32'h0; // @[Core.scala 72:32]
    end else begin
      ex_reg_csr_data <= id_reg_csr_data; // @[Core.scala 236:19]
    end
    if (reset) begin // @[Core.scala 76:28]
      mem_reg_ins <= 32'h0; // @[Core.scala 76:28]
    end else begin
      mem_reg_ins <= ex_reg_ins; // @[Core.scala 289:17]
    end
    if (reset) begin // @[Core.scala 77:31]
      mem_reg_result <= 32'h0; // @[Core.scala 77:31]
    end else begin
      mem_reg_result <= ex_reg_result; // @[Core.scala 286:20]
    end
    if (reset) begin // @[Core.scala 79:28]
      mem_reg_wra <= 5'h0; // @[Core.scala 79:28]
    end else begin
      mem_reg_wra <= ex_reg_wra; // @[Core.scala 297:15]
    end
    if (reset) begin // @[Core.scala 80:37]
      mem_reg_ctl_memToReg <= 2'h0; // @[Core.scala 80:37]
    end else begin
      mem_reg_ctl_memToReg <= ex_reg_ctl_memToReg; // @[Core.scala 298:24]
    end
    if (reset) begin // @[Core.scala 81:37]
      mem_reg_ctl_regWrite <= 1'h0; // @[Core.scala 81:37]
    end else begin
      mem_reg_ctl_regWrite <= ex_reg_ctl_regWrite; // @[Core.scala 288:26]
    end
    if (reset) begin // @[Core.scala 82:27]
      mem_reg_pc <= 32'h0; // @[Core.scala 82:27]
    end else begin
      mem_reg_pc <= ex_reg_pc; // @[Core.scala 290:16]
    end
    if (reset) begin // @[Core.scala 83:31]
      mem_reg_is_csr <= 1'h0; // @[Core.scala 83:31]
    end else begin
      mem_reg_is_csr <= ex_reg_is_csr; // @[Core.scala 299:18]
    end
    if (reset) begin // @[Core.scala 84:33]
      mem_reg_csr_data <= 32'h0; // @[Core.scala 84:33]
    end else begin
      mem_reg_csr_data <= ex_reg_csr_data; // @[Core.scala 300:20]
    end
    npcDelay_0 <= InstructionDecode_io_hdu_pcWrite ? $signed(_npc_T_2) : $signed(pc_io_out); // @[Core.scala 376:25]
    npcDelay_1 <= npcDelay_0; // @[Core.scala 364:23]
    npcDelay_2 <= npcDelay_1; // @[Core.scala 364:23]
    npcDelay_3 <= npcDelay_2; // @[Core.scala 364:23]
    rsAddrDelay_0_0 <= InstructionDecode_io_rs_addr_0; // @[Core.scala 357:25]
    rsAddrDelay_0_1 <= rsAddrDelay_0_0; // @[Core.scala 355:31]
    rsAddrDelay_0_2 <= rsAddrDelay_0_1; // @[Core.scala 355:31]
    rsAddrDelay_1_0 <= InstructionDecode_io_rs_addr_1; // @[Core.scala 357:25]
    rsAddrDelay_1_1 <= rsAddrDelay_1_0; // @[Core.scala 355:31]
    rsAddrDelay_1_2 <= rsAddrDelay_1_1; // @[Core.scala 355:31]
    rsDataDelay_0_0 <= id_reg_rd1; // @[Core.scala 378:38]
    rsDataDelay_0_1 <= rsDataDelay_0_0; // @[Core.scala 360:25]
    rsDataDelay_1_0 <= id_reg_rd2; // @[Core.scala 379:38]
    rsDataDelay_1_1 <= rsDataDelay_1_0; // @[Core.scala 360:25]
    if (reset) begin // @[Core.scala 348:31]
      memAddrDelay <= 32'h0; // @[Core.scala 348:31]
    end else begin
      memAddrDelay <= ex_reg_result; // @[Core.scala 398:19]
    end
    if (reset) begin // @[Core.scala 349:32]
      memWdataDelay <= 32'sh0; // @[Core.scala 349:32]
    end else begin
      memWdataDelay <= ex_reg_wd; // @[Core.scala 398:19]
    end
    stallDelay_0 <= InstructionDecode_io_hdu_if_reg_write; // @[Core.scala 398:19]
    stallDelay_1 <= stallDelay_0; // @[Core.scala 365:25]
    stallDelay_2 <= stallDelay_1; // @[Core.scala 365:25]
    stallDelay_3 <= stallDelay_2; // @[Core.scala 365:25]
    insDelay_0 <= c_ins_trace; // @[Core.scala 371:23]
    insDelay_1 <= insDelay_0; // @[Core.scala 369:29]
    insDelay_2 <= insDelay_1; // @[Core.scala 369:29]
    insDelay_3 <= insDelay_2; // @[Core.scala 369:29]
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
  id_reg_pc = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  id_reg_rd1 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  id_reg_rd2 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  id_reg_imm = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  id_reg_wra = _RAND_6[4:0];
  _RAND_7 = {1{`RANDOM}};
  id_reg_f7 = _RAND_7[6:0];
  _RAND_8 = {1{`RANDOM}};
  id_reg_f3 = _RAND_8[2:0];
  _RAND_9 = {1{`RANDOM}};
  id_reg_ins = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  id_reg_ctl_aluSrc = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  id_reg_ctl_aluSrc1 = _RAND_11[1:0];
  _RAND_12 = {1{`RANDOM}};
  id_reg_ctl_memToReg = _RAND_12[1:0];
  _RAND_13 = {1{`RANDOM}};
  id_reg_ctl_regWrite = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  id_reg_ctl_memRead = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  id_reg_ctl_memWrite = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  id_reg_ctl_aluOp = _RAND_16[1:0];
  _RAND_17 = {1{`RANDOM}};
  id_reg_is_csr = _RAND_17[0:0];
  _RAND_18 = {1{`RANDOM}};
  id_reg_csr_data = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  ex_reg_result = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  ex_reg_wd = _RAND_20[31:0];
  _RAND_21 = {1{`RANDOM}};
  ex_reg_wra = _RAND_21[4:0];
  _RAND_22 = {1{`RANDOM}};
  ex_reg_ins = _RAND_22[31:0];
  _RAND_23 = {1{`RANDOM}};
  ex_reg_ctl_memToReg = _RAND_23[1:0];
  _RAND_24 = {1{`RANDOM}};
  ex_reg_ctl_regWrite = _RAND_24[0:0];
  _RAND_25 = {1{`RANDOM}};
  ex_reg_ctl_memRead = _RAND_25[0:0];
  _RAND_26 = {1{`RANDOM}};
  ex_reg_ctl_memWrite = _RAND_26[0:0];
  _RAND_27 = {1{`RANDOM}};
  ex_reg_pc = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  ex_reg_is_csr = _RAND_28[0:0];
  _RAND_29 = {1{`RANDOM}};
  ex_reg_csr_data = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  mem_reg_ins = _RAND_30[31:0];
  _RAND_31 = {1{`RANDOM}};
  mem_reg_result = _RAND_31[31:0];
  _RAND_32 = {1{`RANDOM}};
  mem_reg_wra = _RAND_32[4:0];
  _RAND_33 = {1{`RANDOM}};
  mem_reg_ctl_memToReg = _RAND_33[1:0];
  _RAND_34 = {1{`RANDOM}};
  mem_reg_ctl_regWrite = _RAND_34[0:0];
  _RAND_35 = {1{`RANDOM}};
  mem_reg_pc = _RAND_35[31:0];
  _RAND_36 = {1{`RANDOM}};
  mem_reg_is_csr = _RAND_36[0:0];
  _RAND_37 = {1{`RANDOM}};
  mem_reg_csr_data = _RAND_37[31:0];
  _RAND_38 = {1{`RANDOM}};
  npcDelay_0 = _RAND_38[31:0];
  _RAND_39 = {1{`RANDOM}};
  npcDelay_1 = _RAND_39[31:0];
  _RAND_40 = {1{`RANDOM}};
  npcDelay_2 = _RAND_40[31:0];
  _RAND_41 = {1{`RANDOM}};
  npcDelay_3 = _RAND_41[31:0];
  _RAND_42 = {1{`RANDOM}};
  rsAddrDelay_0_0 = _RAND_42[4:0];
  _RAND_43 = {1{`RANDOM}};
  rsAddrDelay_0_1 = _RAND_43[4:0];
  _RAND_44 = {1{`RANDOM}};
  rsAddrDelay_0_2 = _RAND_44[4:0];
  _RAND_45 = {1{`RANDOM}};
  rsAddrDelay_1_0 = _RAND_45[4:0];
  _RAND_46 = {1{`RANDOM}};
  rsAddrDelay_1_1 = _RAND_46[4:0];
  _RAND_47 = {1{`RANDOM}};
  rsAddrDelay_1_2 = _RAND_47[4:0];
  _RAND_48 = {1{`RANDOM}};
  rsDataDelay_0_0 = _RAND_48[31:0];
  _RAND_49 = {1{`RANDOM}};
  rsDataDelay_0_1 = _RAND_49[31:0];
  _RAND_50 = {1{`RANDOM}};
  rsDataDelay_1_0 = _RAND_50[31:0];
  _RAND_51 = {1{`RANDOM}};
  rsDataDelay_1_1 = _RAND_51[31:0];
  _RAND_52 = {1{`RANDOM}};
  memAddrDelay = _RAND_52[31:0];
  _RAND_53 = {1{`RANDOM}};
  memWdataDelay = _RAND_53[31:0];
  _RAND_54 = {1{`RANDOM}};
  stallDelay_0 = _RAND_54[0:0];
  _RAND_55 = {1{`RANDOM}};
  stallDelay_1 = _RAND_55[0:0];
  _RAND_56 = {1{`RANDOM}};
  stallDelay_2 = _RAND_56[0:0];
  _RAND_57 = {1{`RANDOM}};
  stallDelay_3 = _RAND_57[0:0];
  _RAND_58 = {1{`RANDOM}};
  insDelay_0 = _RAND_58[31:0];
  _RAND_59 = {1{`RANDOM}};
  insDelay_1 = _RAND_59[31:0];
  _RAND_60 = {1{`RANDOM}};
  insDelay_2 = _RAND_60[31:0];
  _RAND_61 = {1{`RANDOM}};
  insDelay_3 = _RAND_61[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module SRamTop(
  input         clock,
  input         reset,
  input         io_req_valid,
  input  [31:0] io_req_bits_addrRequest,
  input  [31:0] io_req_bits_dataRequest,
  input  [3:0]  io_req_bits_activeByteLane,
  input         io_req_bits_isWrite,
  output        io_rsp_valid,
  output [31:0] io_rsp_bits_dataResponse
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire  sram_clk_i; // @[SRamTop.scala 21:22]
  wire  sram_rst_i; // @[SRamTop.scala 21:22]
  wire  sram_csb_i; // @[SRamTop.scala 21:22]
  wire  sram_we_i; // @[SRamTop.scala 21:22]
  wire [3:0] sram_wmask_i; // @[SRamTop.scala 21:22]
  wire [12:0] sram_addr_i; // @[SRamTop.scala 21:22]
  wire [31:0] sram_wdata_i; // @[SRamTop.scala 21:22]
  wire [31:0] sram_rdata_o; // @[SRamTop.scala 21:22]
  reg  validReg; // @[SRamTop.scala 14:27]
  wire  _T_2 = io_req_valid & io_req_bits_isWrite; // @[SRamTop.scala 49:34]
  wire  _GEN_0 = io_req_valid & io_req_bits_isWrite ? 1'h0 : 1'h1; // @[SRamTop.scala 29:19 49:58 54:27]
  wire  _GEN_6 = io_req_valid & ~io_req_bits_isWrite | _T_2; // @[SRamTop.scala 40:52 43:22]
  sram_top #(.IFILE_IN("/home/hassan/Documents/nucleusrv/riscv-arch-test/work/rv32i/I-ADD-01.elf.data.hex")) sram ( // @[SRamTop.scala 21:22]
    .clk_i(sram_clk_i),
    .rst_i(sram_rst_i),
    .csb_i(sram_csb_i),
    .we_i(sram_we_i),
    .wmask_i(sram_wmask_i),
    .addr_i(sram_addr_i),
    .wdata_i(sram_wdata_i),
    .rdata_o(sram_rdata_o)
  );
  assign io_rsp_valid = validReg; // @[SRamTop.scala 15:18]
  assign io_rsp_bits_dataResponse = sram_rdata_o; // @[SRamTop.scala 67:30]
  assign sram_clk_i = clock; // @[SRamTop.scala 23:36]
  assign sram_rst_i = reset; // @[SRamTop.scala 25:24]
  assign sram_csb_i = io_req_valid & ~io_req_bits_isWrite ? 1'h0 : _GEN_0; // @[SRamTop.scala 40:52 44:27]
  assign sram_we_i = io_req_valid & ~io_req_bits_isWrite; // @[SRamTop.scala 40:27]
  assign sram_wmask_i = io_req_bits_activeByteLane; // @[SRamTop.scala 49:58 56:29]
  assign sram_addr_i = io_req_bits_addrRequest[12:0];
  assign sram_wdata_i = io_req_bits_dataRequest; // @[SRamTop.scala 49:58 58:29]
  always @(posedge clock) begin
    if (reset) begin // @[SRamTop.scala 14:27]
      validReg <= 1'h0; // @[SRamTop.scala 14:27]
    end else begin
      validReg <= _GEN_6;
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
  validReg = _RAND_0[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module SRamTop_1(
  input         clock,
  input         reset,
  input         io_req_valid,
  input  [31:0] io_req_bits_addrRequest,
  output        io_rsp_valid,
  output [31:0] io_rsp_bits_dataResponse
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire  sram_clk_i; // @[SRamTop.scala 21:22]
  wire  sram_rst_i; // @[SRamTop.scala 21:22]
  wire  sram_csb_i; // @[SRamTop.scala 21:22]
  wire  sram_we_i; // @[SRamTop.scala 21:22]
  wire [3:0] sram_wmask_i; // @[SRamTop.scala 21:22]
  wire [12:0] sram_addr_i; // @[SRamTop.scala 21:22]
  wire [31:0] sram_wdata_i; // @[SRamTop.scala 21:22]
  wire [31:0] sram_rdata_o; // @[SRamTop.scala 21:22]
  reg  validReg; // @[SRamTop.scala 14:27]
  sram_top #(.IFILE_IN("/home/hassan/nucleusrv/imperas_test/ADD-01.hex")) sram ( // @[SRamTop.scala 21:22]
    .clk_i(sram_clk_i),
    .rst_i(sram_rst_i),
    .csb_i(sram_csb_i),
    .we_i(sram_we_i),
    .wmask_i(sram_wmask_i),
    .addr_i(sram_addr_i),
    .wdata_i(sram_wdata_i),
    .rdata_o(sram_rdata_o)
  );
  assign io_rsp_valid = validReg; // @[SRamTop.scala 15:18]
  assign io_rsp_bits_dataResponse = sram_rdata_o; // @[SRamTop.scala 67:30]
  assign sram_clk_i = clock; // @[SRamTop.scala 23:36]
  assign sram_rst_i = reset; // @[SRamTop.scala 25:24]
  assign sram_csb_i = io_req_valid ? 1'h0 : 1'h1; // @[SRamTop.scala 40:52 44:27]
  assign sram_we_i = io_req_valid; // @[SRamTop.scala 40:27]
  assign sram_wmask_i = 4'hf; // @[SRamTop.scala 49:58 56:29]
  assign sram_addr_i = io_req_bits_addrRequest[12:0];
  assign sram_wdata_i = 32'h0; // @[SRamTop.scala 49:58 58:29]
  always @(posedge clock) begin
    if (reset) begin // @[SRamTop.scala 14:27]
      validReg <= 1'h0; // @[SRamTop.scala 14:27]
    end else begin
      validReg <= io_req_valid;
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
  validReg = _RAND_0[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Tracer(
  input         clock,
  input         reset,
  input  [31:0] io_rvfiUInt_0,
  input  [31:0] io_rvfiUInt_1,
  input  [31:0] io_rvfiUInt_2,
  input  [31:0] io_rvfiUInt_3,
  input  [31:0] io_rvfiSInt_0,
  input  [31:0] io_rvfiSInt_1,
  input  [31:0] io_rvfiSInt_2,
  input  [31:0] io_rvfiSInt_3,
  input  [31:0] io_rvfiSInt_4,
  input         io_rvfiBool_0,
  input  [4:0]  io_rvfiRegAddr_0,
  input  [4:0]  io_rvfiRegAddr_1,
  input  [4:0]  io_rvfiRegAddr_2
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] clkCycle; // @[Tracer.scala 18:31]
  wire [31:0] _clkCycle_T_1 = clkCycle + 32'h1; // @[Tracer.scala 19:24]
  wire  _T_1 = io_rvfiBool_0 & io_rvfiUInt_2 != 32'h0; // @[Tracer.scala 44:28]
  always @(posedge clock) begin
    if (reset) begin // @[Tracer.scala 18:31]
      clkCycle <= 32'h0; // @[Tracer.scala 18:31]
    end else begin
      clkCycle <= _clkCycle_T_1; // @[Tracer.scala 19:12]
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1 & ~reset) begin
          $fwrite(32'h80000002,
            "ClkCycle: %d, pc_rdata: %x, pc_wdata: %x, insn: %x, mode: %d, rs1_addr: %d, rs1_rdata: %x, rs2_addr: %d, rs2_rdata: %x, rd_addr: %d, rd_wdata: %x, mem_addr: %x, mem_rdata: %x, mem_wdata: %x\n"
            ,clkCycle,io_rvfiUInt_0,io_rvfiUInt_1,io_rvfiUInt_2,2'h3,io_rvfiRegAddr_1,io_rvfiSInt_1,io_rvfiRegAddr_2,
            io_rvfiSInt_2,io_rvfiRegAddr_0,io_rvfiSInt_0,io_rvfiUInt_3,io_rvfiSInt_3,io_rvfiSInt_4); // @[Tracer.scala 45:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
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
  clkCycle = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Top(
  input         clock,
  input         reset,
  output [31:0] io_pin,
  output [31:0] io_fcsr
);
  wire  core_clock; // @[Top.scala 16:26]
  wire  core_reset; // @[Top.scala 16:26]
  wire [31:0] core_io_pin; // @[Top.scala 16:26]
  wire  core_io_dmemReq_valid; // @[Top.scala 16:26]
  wire [31:0] core_io_dmemReq_bits_addrRequest; // @[Top.scala 16:26]
  wire [31:0] core_io_dmemReq_bits_dataRequest; // @[Top.scala 16:26]
  wire [3:0] core_io_dmemReq_bits_activeByteLane; // @[Top.scala 16:26]
  wire  core_io_dmemReq_bits_isWrite; // @[Top.scala 16:26]
  wire  core_io_dmemRsp_valid; // @[Top.scala 16:26]
  wire [31:0] core_io_dmemRsp_bits_dataResponse; // @[Top.scala 16:26]
  wire  core_io_imemReq_valid; // @[Top.scala 16:26]
  wire [31:0] core_io_imemReq_bits_addrRequest; // @[Top.scala 16:26]
  wire  core_io_imemRsp_valid; // @[Top.scala 16:26]
  wire [31:0] core_io_imemRsp_bits_dataResponse; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiUInt_0; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiUInt_1; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiUInt_2; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiUInt_3; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiSInt_0; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiSInt_1; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiSInt_2; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiSInt_3; // @[Top.scala 16:26]
  wire [31:0] core_io_rvfiSInt_4; // @[Top.scala 16:26]
  wire  core_io_rvfiBool_0; // @[Top.scala 16:26]
  wire [4:0] core_io_rvfiRegAddr_0; // @[Top.scala 16:26]
  wire [4:0] core_io_rvfiRegAddr_1; // @[Top.scala 16:26]
  wire [4:0] core_io_rvfiRegAddr_2; // @[Top.scala 16:26]
  wire [31:0] core_io_fcsr_o_data; // @[Top.scala 16:26]
  wire  dmem_clock; // @[Top.scala 19:20]
  wire  dmem_reset; // @[Top.scala 19:20]
  wire  dmem_io_req_valid; // @[Top.scala 19:20]
  wire [31:0] dmem_io_req_bits_addrRequest; // @[Top.scala 19:20]
  wire [31:0] dmem_io_req_bits_dataRequest; // @[Top.scala 19:20]
  wire [3:0] dmem_io_req_bits_activeByteLane; // @[Top.scala 19:20]
  wire  dmem_io_req_bits_isWrite; // @[Top.scala 19:20]
  wire  dmem_io_rsp_valid; // @[Top.scala 19:20]
  wire [31:0] dmem_io_rsp_bits_dataResponse; // @[Top.scala 19:20]
  wire  imem_clock; // @[Top.scala 20:20]
  wire  imem_reset; // @[Top.scala 20:20]
  wire  imem_io_req_valid; // @[Top.scala 20:20]
  wire [31:0] imem_io_req_bits_addrRequest; // @[Top.scala 20:20]
  wire  imem_io_rsp_valid; // @[Top.scala 20:20]
  wire [31:0] imem_io_rsp_bits_dataResponse; // @[Top.scala 20:20]
  wire  tracer_clock; // @[Top.scala 35:24]
  wire  tracer_reset; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiUInt_0; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiUInt_1; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiUInt_2; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiUInt_3; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiSInt_0; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiSInt_1; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiSInt_2; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiSInt_3; // @[Top.scala 35:24]
  wire [31:0] tracer_io_rvfiSInt_4; // @[Top.scala 35:24]
  wire  tracer_io_rvfiBool_0; // @[Top.scala 35:24]
  wire [4:0] tracer_io_rvfiRegAddr_0; // @[Top.scala 35:24]
  wire [4:0] tracer_io_rvfiRegAddr_1; // @[Top.scala 35:24]
  wire [4:0] tracer_io_rvfiRegAddr_2; // @[Top.scala 35:24]
  Core core ( // @[Top.scala 16:26]
    .clock(core_clock),
    .reset(core_reset),
    .io_pin(core_io_pin),
    .io_dmemReq_valid(core_io_dmemReq_valid),
    .io_dmemReq_bits_addrRequest(core_io_dmemReq_bits_addrRequest),
    .io_dmemReq_bits_dataRequest(core_io_dmemReq_bits_dataRequest),
    .io_dmemReq_bits_activeByteLane(core_io_dmemReq_bits_activeByteLane),
    .io_dmemReq_bits_isWrite(core_io_dmemReq_bits_isWrite),
    .io_dmemRsp_valid(core_io_dmemRsp_valid),
    .io_dmemRsp_bits_dataResponse(core_io_dmemRsp_bits_dataResponse),
    .io_imemReq_valid(core_io_imemReq_valid),
    .io_imemReq_bits_addrRequest(core_io_imemReq_bits_addrRequest),
    .io_imemRsp_valid(core_io_imemRsp_valid),
    .io_imemRsp_bits_dataResponse(core_io_imemRsp_bits_dataResponse),
    .io_rvfiUInt_0(core_io_rvfiUInt_0),
    .io_rvfiUInt_1(core_io_rvfiUInt_1),
    .io_rvfiUInt_2(core_io_rvfiUInt_2),
    .io_rvfiUInt_3(core_io_rvfiUInt_3),
    .io_rvfiSInt_0(core_io_rvfiSInt_0),
    .io_rvfiSInt_1(core_io_rvfiSInt_1),
    .io_rvfiSInt_2(core_io_rvfiSInt_2),
    .io_rvfiSInt_3(core_io_rvfiSInt_3),
    .io_rvfiSInt_4(core_io_rvfiSInt_4),
    .io_rvfiBool_0(core_io_rvfiBool_0),
    .io_rvfiRegAddr_0(core_io_rvfiRegAddr_0),
    .io_rvfiRegAddr_1(core_io_rvfiRegAddr_1),
    .io_rvfiRegAddr_2(core_io_rvfiRegAddr_2),
    .io_fcsr_o_data(core_io_fcsr_o_data)
  );
  SRamTop dmem ( // @[Top.scala 19:20]
    .clock(dmem_clock),
    .reset(dmem_reset),
    .io_req_valid(dmem_io_req_valid),
    .io_req_bits_addrRequest(dmem_io_req_bits_addrRequest),
    .io_req_bits_dataRequest(dmem_io_req_bits_dataRequest),
    .io_req_bits_activeByteLane(dmem_io_req_bits_activeByteLane),
    .io_req_bits_isWrite(dmem_io_req_bits_isWrite),
    .io_rsp_valid(dmem_io_rsp_valid),
    .io_rsp_bits_dataResponse(dmem_io_rsp_bits_dataResponse)
  );
  SRamTop_1 imem ( // @[Top.scala 20:20]
    .clock(imem_clock),
    .reset(imem_reset),
    .io_req_valid(imem_io_req_valid),
    .io_req_bits_addrRequest(imem_io_req_bits_addrRequest),
    .io_rsp_valid(imem_io_rsp_valid),
    .io_rsp_bits_dataResponse(imem_io_rsp_bits_dataResponse)
  );
  Tracer tracer ( // @[Top.scala 35:24]
    .clock(tracer_clock),
    .reset(tracer_reset),
    .io_rvfiUInt_0(tracer_io_rvfiUInt_0),
    .io_rvfiUInt_1(tracer_io_rvfiUInt_1),
    .io_rvfiUInt_2(tracer_io_rvfiUInt_2),
    .io_rvfiUInt_3(tracer_io_rvfiUInt_3),
    .io_rvfiSInt_0(tracer_io_rvfiSInt_0),
    .io_rvfiSInt_1(tracer_io_rvfiSInt_1),
    .io_rvfiSInt_2(tracer_io_rvfiSInt_2),
    .io_rvfiSInt_3(tracer_io_rvfiSInt_3),
    .io_rvfiSInt_4(tracer_io_rvfiSInt_4),
    .io_rvfiBool_0(tracer_io_rvfiBool_0),
    .io_rvfiRegAddr_0(tracer_io_rvfiRegAddr_0),
    .io_rvfiRegAddr_1(tracer_io_rvfiRegAddr_1),
    .io_rvfiRegAddr_2(tracer_io_rvfiRegAddr_2)
  );
  assign io_pin = core_io_pin; // @[Top.scala 31:10]
  assign io_fcsr = core_io_fcsr_o_data; // @[Top.scala 32:11]
  assign core_clock = clock;
  assign core_reset = reset;
  assign core_io_dmemRsp_valid = dmem_io_rsp_valid; // @[Top.scala 28:19]
  assign core_io_dmemRsp_bits_dataResponse = dmem_io_rsp_bits_dataResponse; // @[Top.scala 28:19]
  assign core_io_imemRsp_valid = imem_io_rsp_valid; // @[Top.scala 23:19]
  assign core_io_imemRsp_bits_dataResponse = imem_io_rsp_bits_dataResponse; // @[Top.scala 23:19]
  assign dmem_clock = clock;
  assign dmem_reset = reset;
  assign dmem_io_req_valid = core_io_dmemReq_valid; // @[Top.scala 29:15]
  assign dmem_io_req_bits_addrRequest = core_io_dmemReq_bits_addrRequest; // @[Top.scala 29:15]
  assign dmem_io_req_bits_dataRequest = core_io_dmemReq_bits_dataRequest; // @[Top.scala 29:15]
  assign dmem_io_req_bits_activeByteLane = core_io_dmemReq_bits_activeByteLane; // @[Top.scala 29:15]
  assign dmem_io_req_bits_isWrite = core_io_dmemReq_bits_isWrite; // @[Top.scala 29:15]
  assign imem_clock = clock;
  assign imem_reset = reset;
  assign imem_io_req_valid = core_io_imemReq_valid; // @[Top.scala 24:15]
  assign imem_io_req_bits_addrRequest = core_io_imemReq_bits_addrRequest; // @[Top.scala 24:15]
  assign tracer_clock = clock;
  assign tracer_reset = reset;
  assign tracer_io_rvfiUInt_0 = core_io_rvfiUInt_0; // @[Top.scala 43:19]
  assign tracer_io_rvfiUInt_1 = core_io_rvfiUInt_1; // @[Top.scala 43:19]
  assign tracer_io_rvfiUInt_2 = core_io_rvfiUInt_2; // @[Top.scala 43:19]
  assign tracer_io_rvfiUInt_3 = core_io_rvfiUInt_3; // @[Top.scala 43:19]
  assign tracer_io_rvfiSInt_0 = core_io_rvfiSInt_0; // @[Top.scala 43:19]
  assign tracer_io_rvfiSInt_1 = core_io_rvfiSInt_1; // @[Top.scala 43:19]
  assign tracer_io_rvfiSInt_2 = core_io_rvfiSInt_2; // @[Top.scala 43:19]
  assign tracer_io_rvfiSInt_3 = core_io_rvfiSInt_3; // @[Top.scala 43:19]
  assign tracer_io_rvfiSInt_4 = core_io_rvfiSInt_4; // @[Top.scala 43:19]
  assign tracer_io_rvfiBool_0 = core_io_rvfiBool_0; // @[Top.scala 43:19]
  assign tracer_io_rvfiRegAddr_0 = core_io_rvfiRegAddr_0; // @[Top.scala 43:19]
  assign tracer_io_rvfiRegAddr_1 = core_io_rvfiRegAddr_1; // @[Top.scala 43:19]
  assign tracer_io_rvfiRegAddr_2 = core_io_rvfiRegAddr_2; // @[Top.scala 43:19]
endmodule
