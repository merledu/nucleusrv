package nucleusrv.components

import chisel3._
import chisel3.util._

class Core(implicit val config:Configs) extends Module{

  val M      = config.M
  val C      = config.C
  val XLEN   = config.XLEN
  val TRACE  = config.TRACE
  val V      = config.V

  val io = IO(new Bundle {
    val pin: UInt = Output(UInt(32.W))
    val Vpin = Output(UInt(128.W))
    val stall: Bool = Input(Bool())

    val dmemReq = Decoupled(new MemRequestIO)
    val dmemRsp = Flipped(Decoupled(new MemResponseIO))

    val imemReq = Decoupled(new MemRequestIO)
    val imemRsp = Flipped(Decoupled(new MemResponseIO))

    // RVFI Pins
    val rvfiUInt    = if (TRACE) Some(Output(Vec(4, UInt(32.W)))) else None
    val rvfiSInt    = if (TRACE) Some(Output(Vec(5, SInt(32.W)))) else None
    val rvfiBool    = if (TRACE) Some(Output(Vec(1, Bool()))) else None
    val rvfiRegAddr = if (TRACE) Some(Output(Vec(3, UInt(5.W)))) else None
    val rvfiMode    = if (TRACE) Some(Output(UInt(2.W))) else None

    val fcsr_o_data = Output(UInt(32.W))
  })

  // IF-ID Registers
  val if_reg_pc = RegInit(0.U(32.W))
  val if_reg_ins = RegInit(0.U(32.W))

  //vector IF-ID Registers
  val if_reg_lmul_v = RegInit(0.U(4.W))

  // ID-EX Registers
  val id_reg_pc = RegInit(0.U(32.W))
  val id_reg_rd1 = RegInit(0.U(32.W))
  val id_reg_rd2 = RegInit(0.U(32.W))
  val id_reg_imm = RegInit(0.U(32.W))
  val id_reg_wra = RegInit(0.U(5.W))
  val id_reg_f7 = RegInit(0.U(7.W))
  val id_reg_f6 = RegInit(0.U(6.W))
  val id_reg_f3 = RegInit(0.U(3.W))
  val id_reg_ins = RegInit(0.U(32.W))
  val id_reg_ctl_aluSrc = RegInit(false.B)
  val id_reg_ctl_aluSrc1 = RegInit(0.U(2.W))
  val id_reg_ctl_memToReg = RegInit(0.U(2.W))
  val id_reg_ctl_regWrite = RegInit(false.B)
  val id_reg_ctl_memRead = RegInit(false.B)
  val id_reg_ctl_memWrite = RegInit(false.B)
  val id_reg_ctl_branch = RegInit(false.B)
  val id_reg_ctl_aluOp = RegInit(0.U(2.W))
  val id_reg_ctl_jump = RegInit(0.U(2.W))
  val id_reg_is_csr = RegInit(false.B)
  val id_reg_csr_data = RegInit(0.U)

  // Vector ID-EX Register
  val id_reg_instruction = RegInit(0.U(32.W))
  val id_reg_vl_out = RegInit(0.S(32.W))
  val id_reg_z_imm = RegInit(0.S(11.W))
  val id_reg_vtype_out = RegInit(0.S(11.W))
  val id_reg_vstart_out = RegInit(0.S(32.W))
  val id_reg_vtype = RegInit(0.S(32.W))
  val id_reg_v_addi_imm = RegInit(0.S(32.W))
  val id_reg_v0_data = RegInit(0.S(128.W))
  val id_reg_v1_data = RegInit(0.S(128.W))
  val id_reg_v2_data = RegInit(0.S(128.W))
  val id_reg_vd_data = RegInit(0.S(128.W))
  val id_reg_vs1_addr = RegInit(0.U(5.W))
  val id_reg_vs2_addr = RegInit(0.U(5.W))
  val id_reg_vd_addr = RegInit(0.U(5.W))
  val id_reg_lmul_v = RegInit(0.U(4.W))
  dontTouch(id_reg_vd_addr)
  // val id_reg_ctl_memWrite = RegInit(false.B)
  // val id_reg_ctl_Branch = RegInit(false.B)
  // val id_reg_ctl_MemRead = RegInit(false.B)
  val id_reg_ctl_RegWrite = RegInit(false.B)
  // val id_reg_ctl_Mem2Reg = RegInit(false.B)
  // val id_reg_ctl_opAsel = RegInit(0.U(2.W))
  val id_reg_ctl_opBsel = RegInit(false.B)
  val id_reg_ctl_Ex_sel = RegInit(0.U(4.W))
  val id_reg_ctl_nextPCsel = RegInit(0.U(2.W))
  val id_reg_ctl_aluop = RegInit(0.U(5.W))
  val id_reg_ctl_vset = RegInit(false.B)
  val id_reg_ctl_v_load = RegInit(false.B)
  val id_reg_ctl_v_ins = RegInit(false.B)
  // val id_reg_RegWrite = RegInit(false.B)
  // val id_reg_vs1_addr = RegInit(0.U(5.W))
  // val id_reg_vs2_addr = RegInit(0.U(5.W))


  // EX-MEM Registers
  val ex_reg_branch = RegInit(0.U(32.W))
  val ex_reg_zero = RegInit(0.U(32.W))
  val ex_reg_result = RegInit(0.U(32.W))
  val ex_reg_wd = RegInit(0.U(32.W))
  val ex_reg_wra = RegInit(0.U(5.W))
  val ex_reg_ins = RegInit(0.U(32.W))
  val ex_reg_ctl_memToReg = RegInit(0.U(2.W))
  val ex_reg_ctl_regWrite = RegInit(false.B)
  val ex_reg_ctl_memRead = RegInit(false.B)
  val ex_reg_ctl_memWrite = RegInit(false.B)
  val ex_reg_ctl_branch_taken = RegInit(false.B)
  val ex_reg_pc = RegInit(0.U(32.W))
  val ex_reg_is_csr = RegInit(false.B)
  val ex_reg_csr_data = RegInit(0.U)

  //vector EX-MEM Registers
  val ex_reg_vec_alu_res = RegInit(0.S(128.W))
  // val ex_reg_lmul = RegInit(0.S(32.W))
  val ex_reg_vl = RegInit(0.S(32.W))
  dontTouch(ex_reg_vl)
  val ex_reg_rd_out = RegInit(0.U(5.W))
  val ex_reg_avl_o = RegInit(0.S(32.W))
  val ex_reg_valmax_o = RegInit(0.S(32.W))
  val ex_reg_vs1_addr = RegInit(0.U(5.W))
  val ex_reg_vs2_addr = RegInit(0.U(5.W))
  val ex_reg_vd_addr = RegInit(0.U(5.W))
  val ex_reg_lmul_v = RegInit(0.U(4.W))
  dontTouch(ex_reg_vd_addr)
  val ex_reg_vset = RegInit(false.B)
  val ex_reg_reg_write = RegInit(false.B)
  val ex_reg_vtype = RegInit(0.S(11.W))

  // MEM-WB Registers
  val mem_reg_rd = RegInit(0.U(32.W))
  val mem_reg_ins = RegInit(0.U(32.W))
  val mem_reg_result = RegInit(0.U(32.W))
  val mem_reg_branch = RegInit(0.U(32.W))
  val mem_reg_wra = RegInit(0.U(5.W))
  val mem_reg_ctl_memToReg = RegInit(0.U(2.W))
  val mem_reg_ctl_regWrite = RegInit(false.B)
  val mem_reg_pc = RegInit(0.U(32.W))
  val mem_reg_is_csr = RegInit(false.B)
  val mem_reg_csr_data = RegInit(0.U)

  //vector MEM-WB Registers
  val mem_reg_vec_alu_out = RegInit(0.S(128.W))
  val mem_reg_vec_vl = RegInit(0.S(32.W))
  val mem_reg_vtype = RegInit(0.S(11.W))
  val mem_reg_vec_rd_out = RegInit(0.U(5.W))
  val mem_reg_vec_avl_o = RegInit(0.S(32.W))
  val mem_reg_vec_valmax_o = RegInit(0.S(32.W))
  val mem_reg_vec_vd_addr = RegInit(0.U(5.W))
  dontTouch(mem_reg_vec_vd_addr)
  val mem_reg_lmul_v = RegInit(0.U(4.W))
  val mem_reg_vset = RegInit(false.B)
  val mem_reg_vec_reg_write = RegInit(false.B)

  //Pipeline Units
  val IF = Module(new InstructionFetch).io
  dontTouch(IF)
  val IDecode = Module(new InstructionDecode(TRACE))
  val ID = IDecode.io
  dontTouch(ID)
  val EX = Module(new Execute(M = M)).io
  dontTouch(EX)
  val MEM = Module(new MemoryFetch)

  io.fcsr_o_data := ID.fscr_o_data
  
  /*****************
   * Fetch Stage *
   ******************/

  val pc = Module(new PC)

  io.imemReq <> IF.coreInstrReq
  IF.coreInstrResp <> io.imemRsp

  val instruction = Wire(UInt(32.W))
  val ral_halt_o  = WireInit(false.B)
  val is_comp     = WireInit(false.B)


     /************************
   * Vector Fetch Stage *
   ************************/

      // **************************grouping**********************//
      //vsetvl not implement (rs2 value)
var lmul = RegInit(0.U(3.W)) // by default lmul==1
when(instruction(6,0)==="b1010111".U && instruction(14,12)==="b111".U && (instruction(31)==="b0".U || instruction(31,30)==="b11".U)){
  lmul := instruction(22,20)
}
.otherwise{
  lmul := lmul
}

var vlmul_count = WireInit(0.U(32.W))
// val vtype = WireInit("b010".U(32.W))
dontTouch(vlmul_count)
// dontTouch(vtype)
// working on  only one vector 
    when (lmul==="b000".U){
        vlmul_count := 0.U
    }
    // working on  only two vector continously
    .elsewhen (lmul==="b001".U){
        vlmul_count := 1.U
    }
    // working on  only four vector continously
    .elsewhen (lmul==="b010".U){
        vlmul_count := 3.U
    }
    // working on  only eight vector continously
    .elsewhen (lmul==="b011".U){
        vlmul_count := 7.U
    }
    // val aaai = WireInit(0.U(32.W))
    // aaai := instruction(6,0)
    // dontTouch(aaai)
    // val aaaf = WireInit(0.U(32.W))
    // aaaf := instruction(14,12)
    // dontTouch(lmul)
    // dontTouch(aaaf)
  var next_pc_selector = WireInit(0.U(32.W))
  val lmul_reg = RegInit(0.U(32.W))
    when(lmul_reg =/= vlmul_count && instruction(6,0)==="b1010111".U && instruction(14,12)=/="b111".U){
        next_pc_selector := 1.U
        lmul_reg := lmul_reg +1.U
        if_reg_lmul_v := lmul_reg  //paasing fetch stage
    }
    .otherwise{
        lmul_reg := 0.U
        next_pc_selector := 0.U
        if_reg_lmul_v := lmul_reg //paasing fetch stage
    }
dontTouch(lmul_reg)
dontTouch(next_pc_selector)

  val c_ins_trace = if (C) Some(dontTouch(WireInit(0.U(32.W)))) else None

  // if (V){




  /************************
   * Vector Decode Stage *
   ************************/

    id_reg_vl_out := ID.vl_out
    id_reg_z_imm := ID.v_z_imm
    id_reg_vstart_out := ID.vstart_out
    id_reg_vtype := ID.vtypei_out
    id_reg_v_addi_imm := ID.v_addi_imm
    id_reg_v0_data := ID.vs0_data
    id_reg_v1_data := ID.vs1_data
    id_reg_v2_data := ID.vs2_data
    id_reg_vd_data := ID.vd_data
    id_reg_ctl_RegWrite :=ID.ctl_v_RegWrite
    id_reg_ctl_opBsel :=ID.ctl_v_opBsel
    id_reg_ctl_Ex_sel :=ID.ctl_v_Ex_sel
    id_reg_ctl_aluop := ID.ctl_v_aluop
    id_reg_ctl_vset := ID.ctl_v_vset
    id_reg_ctl_v_load := ID.ctl_v_load
    id_reg_ctl_v_ins := ID.ctl_v_ins
    id_reg_instruction := ID.id_instruction
    id_reg_vd_addr := ID.vd_addr
    id_reg_vs1_addr := ID.vs1_addr
    id_reg_vs2_addr := ID.vs2_addr
    id_reg_lmul_v  := if_reg_lmul_v
    ID.id_lmul_vs1in_vs2in := if_reg_lmul_v
    
    


  /*************************
   * Vector Execute Stage *
  **************************/

  EX.func6 := id_reg_ins(31, 26)
  EX.v_ctl_aluop := id_reg_ctl_aluop
  EX.v_ctl_exsel := id_reg_ctl_Ex_sel
  EX.v_ctl_regwrite := id_reg_ctl_RegWrite
  EX.v_ctl_opBsel := id_reg_ctl_opBsel
  EX.v_ctl_v_load := id_reg_ctl_v_load
  EX.v_ctl_v_ins := id_reg_ctl_v_ins
  EX.v_ctl_vset := id_reg_ctl_vset
  ex_reg_vset := id_reg_ctl_vset
  EX.vs1_data := id_reg_v1_data
  EX.vs2_data := id_reg_v2_data
  EX.vl := Mux(ex_reg_vset, ex_reg_vl, Mux(mem_reg_vset, mem_reg_vec_vl, ID.vl_out))
  EX.vstart := id_reg_vstart_out
  EX.vd_data := id_reg_vd_data
  EX.vma := Mux(ex_reg_vset, ex_reg_vtype(7), Mux(mem_reg_vset, mem_reg_vtype(7), ID.vtypei_out(7)))
  EX.vta := Mux(ex_reg_vset, ex_reg_vtype(6), Mux(mem_reg_vset, mem_reg_vtype(6), ID.vtypei_out(6)))
  EX.vm := id_reg_ins(25)
  EX.vs0 := id_reg_v0_data
  EX.vd_addr := id_reg_ins(11, 7)
  EX.v_sew := Mux(ex_reg_vset, ex_reg_vtype(5, 3), Mux(mem_reg_vset, mem_reg_vtype(5, 3), ID.vtypei_out(5, 3)))
  EX.zimm := id_reg_vtype
  EX.v_addi_imm := id_reg_v_addi_imm

  EX.fu_reg_vs1 := id_reg_vs1_addr
  EX.fu_reg_vs2 := id_reg_vs2_addr
  EX.fu_ex_reg_vd := ex_reg_vd_addr
  EX.fu_mem_reg_vd := mem_reg_vec_vd_addr
  EX.fu_ex_reg_write := ex_reg_reg_write
  EX.fu_mem_reg_write := mem_reg_vec_reg_write

  ex_reg_vtype := id_reg_z_imm
  ex_reg_vec_alu_res := EX.vec_alu_res
  ex_reg_vl := EX.vec_vl
  ex_reg_rd_out := EX.vec_rd_out
  ex_reg_avl_o := EX.vec_avl_o
  ex_reg_valmax_o := EX.vec_valmax_o

  ex_reg_reg_write := id_reg_ctl_RegWrite
  EX.fu_ex_reg_write := ex_reg_reg_write
  ex_reg_vd_addr := id_reg_vd_addr
  ex_reg_lmul_v := id_reg_lmul_v

  /****************
   * Memory Stage *
   ****************/

  EX.vec_mem_res := ex_reg_vec_alu_res
  mem_reg_vec_alu_out := ex_reg_vec_alu_res
  mem_reg_vset := ex_reg_vset
  mem_reg_vec_vl := ex_reg_vl
  mem_reg_vtype := ex_reg_vtype
  mem_reg_vec_rd_out := ex_reg_rd_out
  mem_reg_vec_avl_o := ex_reg_avl_o
  mem_reg_vec_valmax_o := ex_reg_valmax_o
  mem_reg_vec_reg_write := ex_reg_reg_write
  mem_reg_vec_vd_addr := ex_reg_vd_addr
  mem_reg_lmul_v := ex_reg_lmul_v


  /****************
   * Write Back *
   ****************/

  EX.vec_wb_res := mem_reg_vec_alu_out
  ID.wb_RegWrite := mem_reg_vec_reg_write
  ID.wb_addr := mem_reg_vec_vd_addr
  ID.id_lmul_count := mem_reg_lmul_v

  ID.write_data := mem_reg_vec_alu_out
  ID.ctl_vset := mem_reg_vset
  ID.vl := mem_reg_vec_vl
  ID.vtypei := mem_reg_vtype

  // }
  if (C) {

    /*****************
    * Realingner *
    ******************/
    val RA = Module(new Realigner).io

    RA.ral_address_i     := pc.io.in.asUInt()
    RA.ral_instruction_i := IF.instruction
    RA.ral_jmp           := ID.pcSrc

    IF.address           := RA.ral_address_o
    val instruction_cd    = RA.ral_instruction_o

    ral_halt_o           := RA.ral_halt_o

    /*************************************************
    * Compressed Decoder (Fully Combinational) *
    *************************************************/
    val CD = Module(new CompressedDecoder).io

    CD.instruction_i := instruction_cd
    instruction  := CD.instruction_o

    is_comp := CD.is_comp

    c_ins_trace.get := IF.instruction

  }
  else {

    IF.address := pc.io.in.asUInt()
    instruction := IF.instruction

  }

  val func3 = instruction(14, 12)
  val func7 = Wire(UInt(6.W))
  when(instruction(6,0) === "b0110011".U){
    func7 := instruction(31,25)
  }.otherwise{
    func7 := 0.U
  }

  val IF_stall = func7 === 1.U && (func3 === 4.U || func3 === 5.U || func3 === 6.U || func3 === 7.U)

  IF.stall := io.stall || EX.stall || ID.stall || IF_stall //stall signal from outside
  
  // pc.io.halt := Mux(io.imemReq.valid || ~EX.stall || ~ID.stall, 0.B, 1.B)
  pc.io.halt := Mux(((EX.stall || ID.stall || IF_stall || ~io.imemReq.valid) | ral_halt_o), 1.B, 0.B)
  // vector changes
  val npc = Mux(next_pc_selector===1.U,pc.io.out,Mux(ID.hdu_pcWrite, Mux(ID.pcSrc, ID.pcPlusOffset.asSInt(), Mux(is_comp, pc.io.pc2, pc.io.pc4)), pc.io.out))
  pc.io.in := npc

  when(ID.hdu_if_reg_write) {
    if_reg_pc := pc.io.out.asUInt()
    if_reg_ins := instruction 
  }
  when(ID.ifid_flush) {
    if_reg_ins := 0.U
  }
  // val ins_trace = if (C && TRACE){
  //   Some(WireInit(instruction_cd))
  // }else if(!C && TRACE){
  //   Some(WireInit(if_reg_ins))
  // }else{
  //   None
  // }

  /****************
   * Decode Stage *
   ****************/

  id_reg_rd1 := ID.readData1
  id_reg_rd2 := ID.readData2
  id_reg_imm := ID.immediate
  id_reg_wra := ID.writeRegAddress
  id_reg_f3 := ID.func3
  id_reg_f6 := ID.func6
  id_reg_f7 := ID.func7
  id_reg_ins := if_reg_ins
  id_reg_pc := if_reg_pc
  id_reg_ctl_aluSrc := ID.ctl_aluSrc
  id_reg_ctl_memToReg := ID.ctl_memToReg
  id_reg_ctl_regWrite := ID.ctl_regWrite || ID.ctl_v_RegWrite
  id_reg_ctl_memRead := ID.ctl_memRead
  id_reg_ctl_memWrite := ID.ctl_memWrite
  id_reg_ctl_branch := ID.ctl_branch
  id_reg_ctl_aluOp := ID.ctl_aluOp
  id_reg_ctl_jump := ID.ctl_jump
  id_reg_ctl_aluSrc1 := ID.ctl_aluSrc1
  id_reg_is_csr := ID.is_csr
  id_reg_csr_data := ID.csr_o_data

  // id_reg_vl_out := ID.vl_out
  // id_reg_vtype_out := ID.vtype_out
  // id_reg_vstart_out := ID.vstart_out
  // id_reg_vtype := ID.v_z_imm
  // id_reg_v_addi_imm := ID.v_addi_imm
  // id_reg_v0_data := ID.vs0_data
  // id_reg_v1_data := ID.vs1_data
  // id_reg_v2_data := ID.vs2_data
  // id_reg_vd_data := ID.vd_data
  // id_reg_regWrite := ID.reg_write
  // id_reg_ctl_memWrite :=ID.ctl_MemWrite
  // id_reg_ctl_Branch :=ID.ctl_Branch
  // id_reg_ctl_MemRead :=ID.ctl_MemRead
  // id_reg_ctl_RegWrite :=ID.ctl_RegWrite
  // id_reg_ctl_Mem2Reg :=ID.ctl_Mem2Reg
  // id_reg_ctl_opAsel :=ID.ctl_opAsel
  // id_reg_ctl_opBsel :=ID.ctl_opBsel
  // id_reg_ctl_Ex_sel :=ID.ctl_Ex_sel
  // id_reg_ctl_nextPCsel := ID.ctl_nextPCsel
  // id_reg_ctl_aluop := ID.ctl_aluop
  // id_reg_ctl_vset := ID.ctl_vset
  // id_reg_ctl_v_load := ID.ctl_v_load
  // id_reg_ctl_v_ins := ID.ctl_v_ins
  // id_reg_instruction := ID.id_instruction

//  IF.PcWrite := ID.hdu_pcWrite
  ID.id_instruction := if_reg_ins
  ID.pcAddress := if_reg_pc
  ID.dmem_resp_valid := io.dmemRsp.valid
//  IF.PcSrc := ID.pcSrc
//  IF.PCPlusOffset := ID.pcPlusOffset
  ID.ex_ins := id_reg_ins
  ID.ex_mem_ins := ex_reg_ins
  ID.mem_wb_ins := mem_reg_ins
  ID.ex_mem_result := ex_reg_result

  ID.csr_i_misa    := DontCare
  ID.csr_i_mhartid := DontCare
  ID.id_ex_regWr := id_reg_ctl_regWrite
  ID.ex_mem_regWr := ex_reg_ctl_regWrite

  /*****************
   * Execute Stage *
  ******************/

  //ex_reg_branch := EX.branchAddress
//  ex_reg_wd := EX.writeData
//  ex_reg_result := EX.ALUresult
  //ex_reg_ctl_branch_taken := EX.branch_taken
  EX.immediate := id_reg_imm
  EX.readData1 := id_reg_rd1
  EX.readData2 := id_reg_rd2
  EX.pcAddress := id_reg_pc
  EX.func3 := id_reg_f3
  EX.func7 := id_reg_f7
  EX.ctl_aluSrc := id_reg_ctl_aluSrc
  EX.ctl_aluOp := id_reg_ctl_aluOp
  EX.ctl_aluSrc1 := id_reg_ctl_aluSrc1
  //EX.ctl_branch := id_reg_ctl_branch
  //EX.ctl_jump := id_reg_ctl_jump
  
  
  // EX.id_ex_ins
  // EX.func6 := id_reg_ins(31, 26)
  // EX.v_ctl_aluop := id_reg_ctl_aluop
  // EX.v_ctl_exsel := id_reg_ctl_Ex_sel
  // EX.v_ctl_mem2reg := id_reg_ctl_memToReg
  // EX.v_ctl_regwrite := id_reg_ctl_RegWrite
  // EX.v_ctl_memwrite := id_reg_ctl_memWrite
  // EX.v_ctl_branch := id_reg_ctl_Branch
  // EX.v_ctl_memread := id_reg_ctl_memRead
  // EX.v_ctl_opAsel := id_reg_ctl_opAsel
  // EX.v_ctl_opBsel := id_reg_ctl_opBsel
  // EX.v_ctl_nextpcsel := id_reg_ctl_nextPCsel
  // EX.v_ctl_v_load := id_reg_ctl_v_load
  // EX.v_ctl_v_ins := id_reg_ctl_v_ins
  // EX.v_ctl_vset := id_reg_ctl_vset
  // EX.vs1_data := id_reg_v1_data
  // EX.vs2_data := id_reg_v2_data
  // EX.vl := id_reg_vl_out
  // EX.vstart := id_reg_vstart_out
  // EX.vd_data := id_reg_vd_data
  // EX.vma := id_reg_vtype_out(7)
  // EX.vta := id_reg_vtype_out(6)
  // EX.vm := id_reg_ins(25)
  // EX.vs0 := id_reg_v0_data
  // EX.vd_addr := id_reg_ins(11, 7)
  // // EX.v_aluc :=
  // EX.v_sew := id_reg_vtype_out(5, 3)
  // EX.zimm := id_reg_vtype
  
  ex_reg_pc := id_reg_pc
  ex_reg_wra := id_reg_wra
  ex_reg_ins := id_reg_ins
  ex_reg_ctl_memToReg := id_reg_ctl_memToReg
  ex_reg_ctl_regWrite := id_reg_ctl_regWrite
  ex_reg_is_csr := id_reg_is_csr
  ex_reg_csr_data := id_reg_csr_data
//  ex_reg_ctl_memRead := id_reg_ctl_memRead
//  ex_reg_ctl_memWrite := id_reg_ctl_memWrite
  ID.id_ex_mem_read := id_reg_ctl_memRead
  ID.ex_mem_mem_read := ex_reg_ctl_memRead
//  ID.ex_mem_mem_write := ex_reg_ctl_memWrite
  //EX.ex_mem_regWrite := ex_reg_ctl_regWrite
  //EX.mem_wb_regWrite := mem_reg_ctl_regWrite
  EX.id_ex_ins := id_reg_ins
  EX.ex_mem_ins := ex_reg_ins
  EX.mem_wb_ins := mem_reg_ins
  ID.id_ex_rd := id_reg_ins(11, 7)
  ID.id_ex_branch := Mux(id_reg_ins(6,0) === "b1100011".asUInt(), true.B, false.B )
  ID.ex_mem_rd := ex_reg_ins(11, 7)
  ID.ex_result := EX.ALUresult
  ID.csr_Ex := id_reg_is_csr
  ID.csr_Ex_data := id_reg_csr_data

  


  when(EX.stall){
    id_reg_wra := id_reg_wra
    id_reg_ctl_regWrite := id_reg_ctl_regWrite
  }

  /****************
   * Memory Stage *
   ****************/

  io.dmemReq <> MEM.io.dccmReq
  MEM.io.dccmRsp <> io.dmemRsp
//  val stall = Wire(Bool())
//  stall := (ex_reg_ctl_memWrite || ex_reg_ctl_memRead) && !io.dmemRsp.valid
//  when(MEM.io.stall){
//    mem_reg_rd := mem_reg_rd
//    mem_reg_result := mem_reg_result
////    mem_reg_wra := mem_reg_wra
//    ex_reg_wra := ex_reg_wra
//    ex_reg_ctl_memToReg := ex_reg_ctl_memToReg
////    mem_reg_ctl_memToReg := mem_reg_ctl_memToReg
//    ex_reg_ctl_regWrite := ex_reg_ctl_regWrite
//    mem_reg_ctl_regWrite := ex_reg_ctl_regWrite
//    mem_reg_ins := mem_reg_ins
//    mem_reg_pc := mem_reg_pc
//
//    ex_reg_ctl_memRead := ex_reg_ctl_memRead
//    ex_reg_ctl_memWrite := ex_reg_ctl_memWrite
////    ex_reg_wd := ex_reg_wd
////    ex_reg_result := 0.U
//
//  } otherwise{
    mem_reg_rd := MEM.io.readData
    mem_reg_result := ex_reg_result
//    mem_reg_ctl_memToReg := ex_reg_ctl_memToReg
    mem_reg_ctl_regWrite := ex_reg_ctl_regWrite
    mem_reg_ins := ex_reg_ins
    mem_reg_pc := ex_reg_pc
    mem_reg_wra := ex_reg_wra
    ex_reg_ctl_memRead := id_reg_ctl_memRead
    ex_reg_ctl_memWrite := id_reg_ctl_memWrite
    ex_reg_wd := EX.writeData
    ex_reg_result := EX.ALUresult
//  }
  mem_reg_wra := ex_reg_wra
  mem_reg_ctl_memToReg := ex_reg_ctl_memToReg
  mem_reg_is_csr := ex_reg_is_csr
  mem_reg_csr_data := ex_reg_csr_data
  EX.ex_mem_regWrite := ex_reg_ctl_regWrite
  MEM.io.aluResultIn := ex_reg_result
  MEM.io.writeData := ex_reg_wd
  MEM.io.readEnable := ex_reg_ctl_memRead
  MEM.io.writeEnable := ex_reg_ctl_memWrite
  MEM.io.f3 := ex_reg_ins(14,12)
  EX.mem_result := ex_reg_result
  ID.csr_Mem := ex_reg_is_csr
  ID.csr_Mem_data := ex_reg_csr_data

  /********************
   * Write Back Stage *
   ********************/

  val wb_data = Wire(UInt(32.W))
  val wb_addr = Wire(UInt(5.W))

  when(mem_reg_ctl_memToReg === 1.U) {
    wb_data := MEM.io.readData
    wb_addr := mem_reg_wra
  }.elsewhen(mem_reg_ctl_memToReg === 2.U) {
      wb_data := mem_reg_pc+4.U
      wb_addr := mem_reg_wra
    }
    .otherwise {
      wb_data := mem_reg_result
      wb_addr := mem_reg_wra
    }

  ID.mem_wb_result := wb_data
  ID.writeData := wb_data
  EX.wb_result := wb_data
  EX.mem_wb_regWrite := mem_reg_ctl_regWrite
  ID.writeReg := wb_addr
  ID.ctl_writeEnable := mem_reg_ctl_regWrite
  ID.csr_Wb := mem_reg_is_csr
  ID.csr_Wb_data := mem_reg_csr_data
  ID.dmem_data := io.dmemRsp.bits.dataResponse
  io.pin := wb_data
  io.Vpin := ID.vd_data.asUInt

  /**************
  ** RVFI PINS **
  **************/
  if (TRACE) {
    val npcDelay = Reg(Vec(4, UInt(32.W)))
    val rsAddrDelay = for (i <- 0 until 2) yield Reg(Vec(3, UInt(5.W)))
    val rsDataDelay = for (i <- 0 until 2) yield Reg(Vec(2, SInt(32.W)))
    val memAddrDelay = RegInit(0.U(32.W))
    val memWdataDelay = RegInit(0.S(32.W))
    val stallDelay = Reg(Vec(4, Bool()))
    val insDelay = if (C) Some(dontTouch(Reg(Vec(4, UInt(32.W))))) else None

    for (i <- 0 until 2) {
      for (j <- 0 until 2) {
        rsAddrDelay(i)(j + 1) := rsAddrDelay(i)(j)
      }
      rsAddrDelay(i)(0) := ID.rs_addr.get(i)
      io.rvfiRegAddr.get(i + 1) := rsAddrDelay(i)(2)

      rsDataDelay(i)(1) := rsDataDelay(i)(0)
      io.rvfiSInt.get(i + 1) := rsDataDelay(i)(1)
    }
    for (i <- 0 until 3) {
      npcDelay(i + 1) := npcDelay(i)
      stallDelay(i + 1) := stallDelay(i)
    }

    if (C) {
      for (i <- 0 until 3) {
        insDelay.get(i + 1) := insDelay.get(i)
      }
      insDelay.get(0) := c_ins_trace.get
    }


    Seq(
      (npcDelay(0), npc.asUInt),
      (memAddrDelay, ex_reg_result),
      (rsDataDelay(0)(0), id_reg_rd1.asSInt),
      (rsDataDelay(1)(0), id_reg_rd2.asSInt),
      (memWdataDelay, ex_reg_wd.asSInt),
      (stallDelay(0), ID.hdu_if_reg_write),

      (io.rvfiUInt.get(0), mem_reg_pc),
      (io.rvfiUInt.get(1), npcDelay(3)),

      (io.rvfiUInt.get(2), if (C) insDelay.get(3) else mem_reg_ins),

      (io.rvfiUInt.get(3), memAddrDelay),

      (io.rvfiMode.get, 3.U),

      (io.rvfiRegAddr.get(0), wb_addr),

      (io.rvfiSInt.get(0), wb_data.asSInt),
      (io.rvfiSInt.get(3), MEM.io.readData.asSInt),
      (io.rvfiSInt.get(4), memWdataDelay),

      (io.rvfiBool.get(0), stallDelay(3))
    ).map(
      tr => tr._1 := tr._2
    )
  }
}