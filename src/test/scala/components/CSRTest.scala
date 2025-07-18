package nucleusrv.components
import chisel3._
import chisel3.testers._
import nucleusrv.components._

class CSRTest extends Module {
  val io = IO(new Bundle {
    val test_pass = Output(Bool())
  })
  
  // Simple test to verify CSR module compiles
  val csr = Module(new CSR)
  
  // Connect default values
  csr.io.read_addr := CSRs.MSTATUS
  csr.io.write_addr := 0.U
  csr.io.write_data := 0.U
  csr.io.write_enable := false.B
  csr.io.exception := false.B
  csr.io.exception_pc := 0.U
  csr.io.exception_cause := 0.U
  csr.io.exception_tval := 0.U
  csr.io.mret := false.B
  csr.io.inst_retired := false.B
  
  // Test passes if CSR module instantiates successfully
  io.test_pass := true.B
}
