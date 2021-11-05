package components
import chisel3._
import chisel3.util._

class Multiplier() extends Module {
  val io = IO(new Bundle {
    val i_clk = Input(Bool())
    val i_rst = Input(Bool())
    val i_mdu_rs1 = Input(UInt(32.W))
    val i_mdu_rs2 = Input(UInt(32.W))
    val i_mdu_op = Input(UInt(3.W))
    val i_mdu_valid = Input(Bool())
    // val opcode: UInt = Input(UInt(2.W))
    val func7: UInt = Input(UInt(1.W))
    // val func3: UInt = Input(UInt(3.W))

    val o_mdu_ready = Output(Bool())
    val o_mdu_rd = Output(UInt(32.W))
  })