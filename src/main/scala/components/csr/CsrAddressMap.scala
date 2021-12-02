package nucleusrv.components.csr
import chisel3._

object CsrAddressMap {
  // Supports machine & user modes
  val PRV_U = 0x0.U(2.W)
  val PRV_M = 0x3.U(2.W)

  // User-level CSR addrs
  val cycle    = 0xc00.U(12.W)
  val time     = 0xc01.U(12.W)
  val instret  = 0xc02.U(12.W)
  val cycleh   = 0xc80.U(12.W)
  val timeh    = 0xc81.U(12.W)
  val instreth = 0xc82.U(12.W)

  // Supervisor-level CSR addrs
  val cyclew    = 0x900.U(12.W)
  val timew     = 0x901.U(12.W)
  val instretw  = 0x902.U(12.W)
  val cyclehw   = 0x980.U(12.W)
  val timehw    = 0x981.U(12.W)
  val instrethw = 0x982.U(12.W)

  // Machine-level CSR addrs
  // Machine Information Registers
  val mcpuid   = 0xf00.U(12.W)
  val mimpid   = 0xf01.U(12.W)
  val mhartid  = 0xf10.U(12.W)
  // Machine Trap Setup
  val mstatus  = 0x300.U(12.W)
  val mtvec    = 0x305.U(12.W)
  val mtdeleg  = 0x302.U(12.W)
  val mie      = 0x304.U(12.W)
  val mtimecmp = 0x321.U(12.W)
  // Machine Timers and Counters
  val mtime    = 0x701.U(12.W)
  val mtimeh   = 0x741.U(12.W)
  // Machine Trap Handling
  val mscratch = 0x340.U(12.W)
  val mepc     = 0x341.U(12.W)
  val mcause   = 0x342.U(12.W)
  val mbadaddr = 0x343.U(12.W)
  val mip      = 0x344.U(12.W)
  // Machine HITF
  val mtohost   = 0x780.U(12.W)
  val mfromhost = 0x781.U(12.W)
}
