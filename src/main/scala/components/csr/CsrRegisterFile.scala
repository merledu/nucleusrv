package nucleusrv.components.csr
import chisel3._

class CsrRegisterFile extends Module {
  val io = IO(new Bundle {
    val csr_addr = Input(UInt(12.W))
    val rs1_addr = Input(UInt(5.W))
    val csr_cmd = Input(UInt(3.W))
    val csr_in = Input(UInt(1.W))
  })

  val W = 1.U
  val S = 2.U
  val C = 3.U

  val mstatus = RegInit(UInt(32.W))
  val mtvec = RegInit(UInt(32.W))
  val mie = RegInit(UInt(32.W))
  val mip = RegInit(UInt(32.W))
  val mepc = RegInit(UInt(32.W))


}
