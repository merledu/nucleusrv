package nucleusrv.components.csr
import chisel3._
import chisel3.util._

class CsrRegisterFile extends Module {
  val io = IO(new Bundle {
    val csr_addr = Input(UInt(12.W))
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
  val MPP = RegInit(0.U(2.W))
  val MPIE = RegInit(0.U)
  val MIE = RegInit(0.U)
  val mstatus = Cat("b0".U(10.W), TW, "b0".U(3.W), MPRV, "b0".U(4.W),
    MPP, "b0".U(3.W), MPIE, "b0".U(3.W), MIE, "b0".U(3.W))
    
  //mtvec
   val BASE = RegInit(0.U(30.W))
   val MODE = RegInit(0.U(2.W))
   val mtvec = Cat(BASE,MODE)
   
  //mip 
  val MEIP = RegInit(0.U)
  val MTIP = RegInit(0.U)
  val MSIP = RegInit(0.U)
  val mip = Cat("b0".U(20.W), MEIP, "b0".U(3.W), MTIP, "b0".U(3.W),MSIP,"b0".U(3.W))
  
  //mie
  val MEIE = RegInit(0.U)
  val MTIE = RegInit(0.U)
  val MSIE = RegInit(0.U)
  val mie = Cat("b0".U(20.W), MEIE, "b0".U(3.W), MTIE, "b0".U(3.W),MSIE,"b0".U(3.W))

  //mepc
  val A = RegInit(0.U(30.W))
  val mepc = Cat(A,"b0".U(2.W))

//  val mtvec = RegInit(UInt(32.W))
//  val mie = RegInit(UInt(32.W))
//  val mip = RegInit(UInt(32.W))
//  val mepc = RegInit(UInt(32.W))

  val csrRegFile = Seq(
    BitPat(CsrAddressMap.mstatus) -> mstatus,
    BitPat(CsrAddressMap.mtvec) -> mtvec,
    BitPat(CsrAddressMap.mip) -> mip,
    BitPat(CsrAddressMap.mie) -> mie,
    BitPat(CsrAddressMap.mie) -> mepc
  )

  io.out := Lookup(io.csr_addr, 0.U, csrRegFile).asUInt()

  val w_data = MuxLookup(io.csr_cmd, 0.U, Seq(
    W -> io.csr_in,
    S -> (io.out | io.csr_in),
    C -> (io.out & !io.csr_in)
  ))

  when(io.csr_addr === CsrAddressMap.mstatus){
    	TW := w_data(21)
    	MPRV := w_data(17)
    	MPP := w_data(12,11)
    	MPIE := w_data(7)
    	MIE := w_data(3)
  }.elsewhen(io.csr_addr === CsrAddressMap.mtvec){
    	BASE := w_data(31,2)
    	MODE := w_data(1,0)
  }.elsewhen(io.csr_addr === CsrAddressMap.mip){
    	MEIP := w_data(11)
    	MTIP := w_data(7)
    	MSIP := w_data(3)
  }.elsewhen(io.csr_addr === CsrAddressMap.mie){
    	MEIE := w_data(11)
    	MTIE := w_data(7)
    	MSIE := w_data(3)
  }.elsewhen(io.csr_addr === CsrAddressMap.mepc){
    	A := w_data(31,2)
  }

}
