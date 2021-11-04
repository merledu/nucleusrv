package nucleusrv.components.csr
import chisel3._
import chisel3.util._

class CsrRegisterFile extends Module {
  val io = IO(new Bundle {
    val csr_addr = Input(UInt(12.W))
    val rs1_addr = Input(UInt(5.W))
    val csr_cmd = Input(UInt(3.W))
    val csr_in = Input(UInt(32.W))

    val out = Output(UInt(32.W))
  })

  val W = 1.U
  val S = 2.U
  val C = 3.U

  // mstatus
  val TW = RegInit(0.U)
  val MPRV = RegInit(0.U)
  val MPP = RegInit(UInt(2.W))
  val MPIE = RegInit(0.U)
  val MIE = RegInit(0.U)
  val mstatus = Cat("b0".U(10.W), TW, "b0".U(3.W), MPRV, "b0".U(4.W),
    MPP, "b0".U(3.W), MPIE, "b0".U(3.W), MIE, "b0".U(3.W))

//  val mtvec = RegInit(UInt(32.W))
//  val mie = RegInit(UInt(32.W))
//  val mip = RegInit(UInt(32.W))
//  val mepc = RegInit(UInt(32.W))

  val csrRegFile = Seq(
    BitPat(CsrAddressMap.mstatus) -> mstatus
  )

  io.out := Lookup(io.csr_addr, 0.U, csrRegFile).asUInt()

  val w_data = MuxLookup(io.csr_cmd, 0.U, Seq(
    W -> io.csr_in,
    S -> (io.out | io.csr_in),
    C -> (io.out | io.csr_in)
  ))

  when(io.csr_addr === CsrAddressMap.mstatus){
    
  }

}
