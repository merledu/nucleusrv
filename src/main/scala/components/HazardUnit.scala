package nucleusrv.components
import chisel3._

class HazardUnit extends Module {
  val io = IO(new Bundle {
    val id_ex_memRead = Input(Bool())
    val ex_mem_memRead = Input(Bool())
    val id_ex_branch = Input(Bool())
    val id_ex_rd = Input(UInt(5.W))
    val ex_mem_rd = Input(UInt(5.W))
    val id_rs1 = Input(UInt(5.W))
    val id_rs2 = Input(UInt(5.W))
    val dmem_resp_valid = Input(Bool())
    val taken = Input(Bool())
    val jump = Input(UInt(2.W))
    val branch = Input(Bool())

    val id_is_amo = Input(Bool())      // instruction in ID is AMO
    val ex_is_amo = Input(Bool())      // instruction in EX is AMO
    val mem_is_amo = Input(Bool())     // instruction in MEM is AMO
    
    val addr_id  = Input(UInt(32.W))
    val addr_ex  = Input(UInt(32.W))
    val addr_mem = Input(UInt(32.W))

    val if_reg_write = Output(Bool())
    val pc_write = Output(Bool())
    val ctl_mux = Output(Bool())
    val ifid_flush = Output(Bool())
    val take_branch = Output(Bool())
    
    // Forwarding signals for ID stage
    val operandForwardEX = Output(Bool())
    val operandForwardMEM = Output(Bool())
  })

  io.ctl_mux := true.B
  dontTouch(io.pc_write) := true.B
  io.if_reg_write := true.B
  io.take_branch := true.B
  io.ifid_flush := false.B

  // Standard Load-Use Hazard Detection
  val standard_stall = WireDefault(false.B)
  when (
    (io.id_ex_memRead || io.branch)
    && ((io.id_ex_rd === io.id_rs1) || (io.id_ex_rd === io.id_rs2))
    && (
      ((io.id_ex_rd =/= 0.U) && (io.id_rs1 =/= 0.U))
      || ((io.id_ex_rd =/= 0.U) && (io.id_rs2 =/= 0.U))
    ) && !io.id_ex_branch
  ) {
  }

  when (
    (io.ex_mem_memRead || io.branch)
    && ((io.ex_mem_rd === io.id_rs1) || (io.ex_mem_rd === io.id_rs2))
  ) {
  }

  // Branch flush hazard
  when(io.taken || (io.jump =/= 0.U)) {
    io.ifid_flush := true.B
  }.otherwise {
    io.ifid_flush := false.B
  }

  //AMO Hazard Detection and Forwarding
  val rs1_ID      = io.id_rs1
  val rs2_ID      = io.id_rs2
  val rd_EX       = io.id_ex_rd
  val rd_MEM      = io.ex_mem_rd
  val isAMO_EX    = io.ex_is_amo
  val isAMO_MEM   = io.mem_is_amo
  val isLoad_MEM  = io.ex_mem_memRead
  val addr_EX     = io.addr_ex
  val addr_MEM    = io.addr_mem
  val addr_ID     = io.addr_id

  val amo_stall   = WireDefault(false.B)
  val forward_EX  = WireDefault(false.B)
  val forward_MEM = WireDefault(false.B)

  io.operandForwardEX := forward_EX
  io.operandForwardMEM := forward_MEM

  // Hazard detection
  when(io.id_is_amo) {
    
    // MEM has load or AMO, check address match
    when(isAMO_MEM || isLoad_MEM) {
      when(addr_ID === addr_MEM) {
        forward_MEM := true.B  // Forward from MEM
      } .otherwise {
        amo_stall := true.B    // Stall if not match
      }
    }

    // EX has AMO, check address match
    when(isAMO_EX) {
      when(addr_ID === addr_EX) {
        forward_EX := true.B   // Forward from EX
      }
    }

    // Both EX and MEM have hazards
    when(isAMO_EX && (isAMO_MEM || isLoad_MEM)) {
      when(addr_ID === addr_EX) {
        forward_EX := true.B
        forward_MEM := false.B // Priority to EX
        amo_stall := false.B   // Clear any previous stall
      } .elsewhen(addr_ID === addr_MEM) {
        forward_MEM := true.B
        forward_EX := false.B
        amo_stall := false.B   // Clear any previous stall
      } .otherwise {
        amo_stall := true.B    // Stall 1 cycle if neither match
        forward_EX := false.B
        forward_MEM := false.B
      }
    }

    // Load and AMO addresses differ
    when(!forward_EX && !forward_MEM && (isLoad_MEM || isAMO_MEM || isAMO_EX)) {
      amo_stall := true.B    
    }

    // Consecutive AMOs optimization
    when(isAMO_EX && isAMO_MEM) {
      when(addr_EX =/= addr_MEM) {
        amo_stall := false.B   // Allow different AMO addresses
      }
    }
  }

  // Combined Stall
  when(standard_stall || amo_stall) {
    io.ctl_mux := false.B
    io.pc_write := false.B
    io.if_reg_write := false.B
    io.take_branch := false.B
  }

}
