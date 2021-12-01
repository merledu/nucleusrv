package components

import chisel3._

class RVFIPORT  extends Bundle{
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
    val mem_addr  = Output(UInt(32.W))
    val mem_rmask = Output(UInt(4.W))
    val mem_wmask = Output(UInt(4.W))
    val mem_rdata = Output(UInt(32.W))
    val mem_wdata = Output(UInt(32.W))
}

class RVFI extends Module {
  val rvfi = IO(new RVFIPORT)
  val io = IO(new Bundle {
    val stall = Input(Bool())
    val insn = Input(UInt(32.W))
    val rs1_addr = Input(UInt(5.W))
    val rs1_rdata = Input(UInt(32.W))
    val rs2_addr = Input(UInt(5.W))
    val rs2_rdata = Input(UInt(32.W))
    val rd_addr = Input(UInt(5.W))
    val rd_wdata = Input(UInt(32.W))
  })

  val rvfi_valid = RegInit(false.B)
  val rvfi_order = RegInit(UInt(64.W))

  rvfi_valid := !reset.asBool() && !io.stall

  when(rvfi_valid){
    rvfi_order := rvfi_order + 1.U
  }

  rvfi.rs1_addr := io.rs1_addr
  rvfi.rs1_rdata := io.rs1_rdata
  rvfi.rs2_addr := io.rs2_addr
  rvfi.rs2_rdata := io.rs2_rdata
  rvfi.rd_addr := io.rd_addr
  rvfi.rd_wdata := io.rd_wdata
  rvfi.valid := rvfi_valid
  rvfi.order := rvfi_order
  rvfi.insn := io.insn
}