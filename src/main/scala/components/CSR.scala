package nucleusrv.components
import chisel3._
import nucleusrv.components.csr.{CsrDecode, CsrRegisterFile}

class CSR extends Module {
  val io = IO(new Bundle {
    val func3 = Input(UInt(4.W))
    val imm = Input(UInt(32.W))
    val rs1_data = Input(UInt(32.W))
    val csr_addr = Input(UInt(32.W))

    val out = Output(UInt(32.W))
  })

  val csrDecode = Module(new CsrDecode)
  val csrRegisterFile = Module(new CsrRegisterFile)

  csrDecode.io.func3 := io.func3

  val in = Mux(csrDecode.io.csr_in === 1.U, io.imm, io.rs1_data)

  csrRegisterFile.io.csr_in := in
  csrRegisterFile.io.csr_cmd := csrDecode.io.csr_cmd
  csrRegisterFile.io.csr_addr := io.csr_addr

  io.out := csrRegisterFile.io.out

}
