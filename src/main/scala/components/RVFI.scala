package components

import chisel3._

class RVFIPORT extends Bundle{
    val valid     = Output(Bool())
    val order     = Output(UInt(64.W))
    val insn      = Output(UInt(32.W))
    val trap      = Output(Bool())
    val halt      = Output(Bool())
    val intr      = Output(Bool())
    val ixl       = Output(UInt(2.W))
    val mode      = Output(UInt(2.W))
    val rs1_addr  = Output(UInt(5.W))
    val rs1_rdata = Output(SInt(32.W))
    val rs2_addr  = Output(UInt(5.W))
    val rs2_rdata = Output(SInt(32.W))
    val rd_addr   = Output(UInt(5.W))
    val rd_wdata  = Output(SInt(32.W))
    val pc_rdata  = Output(UInt(32.W))
    val pc_wdata  = Output(UInt(32.W))
//    val mem_addr  = Output(UInt(32.W))
//    val mem_rmask = Output(UInt(4.W))
//    val mem_wmask = Output(UInt(4.W))
//    val mem_rdata = Output(UInt(32.W))
//    val mem_wdata = Output(UInt(32.W))
}
class ModuleIO extends Bundle {
  val stall = Input(Bool())
  val insn = Input(UInt(32.W))
  val rs1_rdata = Input(UInt(32.W))
  val rs2_rdata = Input(UInt(32.W))
  val rd_addr = Input(UInt(5.W))
  val rd_wdata = Input(UInt(32.W))
  val pc = Input(SInt(32.W))
  val pc_offset = Input(SInt(32.W))
  val pc_four = Input(SInt(32.W))
  val pc_src = Input(Bool())
  val rvfi = new RVFIPORT
}
class RVFI extends Module {
  val io = IO(new ModuleIO)

  val rvfi_valid = RegInit(false.B)
  val rvfi_order = RegInit(0.U(64.W))
  val rvfi_halt = RegInit(false.B)
  val rvfi_intr = RegInit(false.B)
  val rvfi_mode = RegInit(3.U(2.W))

  rvfi_valid := !reset.asBool() && !io.stall

  when(rvfi_valid){
    rvfi_order := rvfi_order + 1.U
  }

  io.rvfi.pc_rdata := io.pc.asUInt()
  io.rvfi.pc_wdata := Mux(io.pc_src, io.pc_offset.asUInt(), io.pc_four.asUInt())

  io.rvfi.rs1_addr := io.insn(19, 15)
  io.rvfi.rs1_rdata := io.rs1_rdata.asSInt()
  io.rvfi.rs2_addr := io.insn(24, 20)
  io.rvfi.rs2_rdata := io.rs2_rdata.asSInt()

  io.rvfi.rd_addr := io.rd_addr
  io.rvfi.rd_wdata := io.rd_wdata.asSInt()

  io.rvfi.mode := rvfi_mode
  io.rvfi.valid := rvfi_valid
  io.rvfi.order := rvfi_order
  io.rvfi.insn := io.insn
  io.rvfi.halt := rvfi_halt
  io.rvfi.intr := rvfi_intr
  io.rvfi.ixl  := 1.U
  io.rvfi.trap := false.B
}