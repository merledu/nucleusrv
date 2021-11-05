package nucleusrv.components.csr
import chisel3._
import chisel3.util._


class CsrDecode extends Module {
  val io = IO(new Bundle{
    val func3 = Input(UInt(3.W))

    val csr_cmd = Output(UInt(2.W))
    val csr_in = Output(UInt(2.W))
  })

  val W = BitPat("b?01") //CSSRW
  val S = BitPat("b?10") //CSSRS
  val C = BitPat("b?11") //CSSRC

  io.csr_in := 0.U
  io.csr_cmd := 0.U
  //when msb of funct3 = 1, instructions are of immediate type
  when(io.func3 === BitPat("b1??")){
    io.csr_in := 1.U // immediate value
  }.elsewhen(io.func3 === BitPat("b0??")){
    io.csr_in := 2.U // register value
  }

  when(io.func3 === W){
    io.csr_cmd := 1.U
  }.elsewhen(io.func3 === S){
    io.csr_cmd := 2.U
  }.elsewhen(io.func3 === C){
    io.csr_cmd := 3.U
  }
}
