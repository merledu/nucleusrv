package nucleusrv.components
import chisel3._
import chisel3.util._

class AMOALU extends Module {
  val io = IO(new Bundle {
    val memData = Input(UInt(32.W))   // Data loaded from memory (old value at rs1 address)
    val src2    = Input(UInt(32.W))   // Value from rs2 register
    val amoOp   = Input(UInt(4.W))    // Operation code from decoder
    val result  = Output(UInt(32.W))  // Computed result to write back
  })
  io.result := 0.U

  // AMOoperation encodin
  val AMO_ADD   = 1.U
  val AMO_SWAP  = 2.U
  val AMO_XOR   = 3.U
  val AMO_AND   = 4.U
  val AMO_OR    = 5.U
  val AMO_MIN   = 6.U
  val AMO_MAX   = 7.U
  val AMO_MINU  = 8.U
  val AMO_MAXU  = 9.U

  // Signed for comparisons
  val s_memData = io.memData.asSInt
  val s_src2    = io.src2.asSInt

  switch(io.amoOp) {
    is(AMO_ADD)  { 
        io.result := io.memData + io.src2 }
    is(AMO_SWAP) { 
        io.result := io.src2 }                // Swap old with new
    is(AMO_XOR)  { 
        io.result := io.memData ^ io.src2 }
    is(AMO_AND)  { 
        io.result := io.memData & io.src2 }
    is(AMO_OR)   { 
        io.result := io.memData | io.src2 }
    is(AMO_MIN)  { 
        io.result := Mux(s_memData < s_src2, io.memData, io.src2) }
    is(AMO_MAX)  { 
        io.result := Mux(s_memData > s_src2, io.memData, io.src2) }
    is(AMO_MINU) { 
        io.result := Mux(io.memData < io.src2, io.memData, io.src2) }
    is(AMO_MAXU) { 
        io.result := Mux(io.memData > io.src2, io.memData, io.src2) }
  }
}
