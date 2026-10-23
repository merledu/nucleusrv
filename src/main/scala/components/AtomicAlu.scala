package nucleusrv.components
import chisel3._
import chisel3.util._

class AMOALU(XLEN: Int) extends Module {
  val io = IO(new Bundle {
    val memData = Input(UInt(XLEN.W))   // Data loaded from memory (old value at rs1 address)
    val src2    = Input(UInt(XLEN.W))   // Value from rs2 register
    val amoOp   = Input(UInt(5.W))    // Operation code from decoder(fun5)
    val result  = Output(UInt(XLEN.W))  // Computed result to write back
    val isD     = Input(Bool())
  })
  io.result := 0.U

  // AMOoperation encodin
  val AMO_ADD   = "b00000".U
  val AMO_SWAP  = "b00001".U
  val AMO_XOR   = "b00100".U
  val AMO_AND   = "b01100".U
  val AMO_OR    = "b01000".U
  val AMO_MIN   = "b10000".U
  val AMO_MAX   = "b10100".U
  val AMO_MINU  = "b11000".U
  val AMO_MAXU  = "b11100".U

  // Signed for comparisons
  val s_memData = io.memData.asSInt
  val s_src2    = io.src2.asSInt

  val s_memData_w = io.memData(31,0).asSInt
  val s_src2_w    = io.src2(31,0).asSInt 

  val u_memData_w = io.memData(31,0)
  val u_src2_w    = io.src2(31,0)

  val amomax_w  = if (XLEN == 64) Some(Mux(s_memData_w > s_src2_w, io.memData(31,0), io.src2(31,0))) else None
  val amomaxu_w = if (XLEN == 64) Some(Mux(u_memData_w > u_src2_w, io.memData(31,0), io.src2(31,0))) else None
  val amomin_w  = if (XLEN == 64) Some(Mux(s_memData_w < s_src2_w, io.memData(31,0), io.src2(31,0))) else None
  val amominu_w = if (XLEN == 64) Some(Mux(u_memData_w < u_src2_w, io.memData(31,0), io.src2(31,0))) else None

  switch(io.amoOp) {
    is(AMO_ADD)  { 
        io.result := io.memData + io.src2 }
    is(AMO_SWAP) { 
        io.result := io.src2 }
    is(AMO_XOR)  { 
        io.result := io.memData ^ io.src2 }
    is(AMO_AND)  { 
        io.result := io.memData & io.src2 }
    is(AMO_OR)   { 
        io.result := io.memData | io.src2 }
    is(AMO_MIN)  { 
        io.result := Mux(io.isD, Mux(s_memData < s_src2, io.memData, io.src2), Cat(Fill(32, amomin_w.get(31)), amomin_w.get)) }
    is(AMO_MAX)  { 
        io.result := Mux(io.isD, Mux(s_memData > s_src2, io.memData, io.src2), Cat(Fill(32, amomax_w.get(31)), amomax_w.get)) }
    is(AMO_MINU) { 
        io.result := Mux(io.isD, Mux(io.memData < io.src2, io.memData, io.src2), Cat(Fill(32, amominu_w.get(31)), amominu_w.get)) }
    is(AMO_MAXU) { 
        io.result := Mux(io.isD, Mux(io.memData > io.src2, io.memData, io.src2), Cat(Fill(32, amomaxu_w.get(31)), amomaxu_w.get)) }
  }
}