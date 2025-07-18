
package nucleusrv.components
import chisel3._

object ALUOps {
  val ALU_ADD = 2.asUInt(4.W)
  val ALU_SUB = 6.asUInt(4.W)
  val ALU_AND = 0.asUInt(4.W)
  val ALU_OR = 1.asUInt(4.W)
  val ALU_XOR = 9.asUInt(4.W)
  // val ALU_SLL = 3.asUInt(4.W)
  // val ALU_SRL = 4.asUInt(4.W)
  // val ALU_SRA = 5.asUInt(4.W)
  // val ALU_SLT = 9.asUInt(4.W)
  // val ALU_SLTU = 10.asUInt(4.W)
  // val ALU_COPY1 = 11.asUInt(4.W)
  // val ALU_X = 0.asUInt(4.W)
}

object Instructions {
  // System instruction opcodes
  val SYSTEM_OPCODE = "b1110011".U(7.W)
  
  // System instruction function codes
  val ECALL_FUNCT12  = "h000".U(12.W)
  val EBREAK_FUNCT12 = "h001".U(12.W)
  val MRET_FUNCT12   = "h302".U(12.W)
  
  // CSR instruction function3 codes
  val CSRRW  = "b001".U(3.W)
  val CSRRS  = "b010".U(3.W)
  val CSRRC  = "b011".U(3.W)
  val CSRRWI = "b101".U(3.W)
  val CSRRSI = "b110".U(3.W)
  val CSRRCI = "b111".U(3.W)
}

object CSRs {
  // Machine-level CSRs
  val MSTATUS   = "h300".U(12.W)
  val MISA      = "h301".U(12.W)
  val MIE       = "h304".U(12.W)
  val MTVEC     = "h305".U(12.W)
  val MSCRATCH  = "h340".U(12.W)
  val MEPC      = "h341".U(12.W)
  val MCAUSE    = "h342".U(12.W)
  val MTVAL     = "h343".U(12.W)
  val MIP       = "h344".U(12.W)
  
  // Machine Performance Counters
  val MCYCLE    = "hB00".U(12.W)
  val MINSTRET  = "hB02".U(12.W)
  val MCYCLEH   = "hB80".U(12.W)
  val MINSTRETH = "hB82".U(12.W)
  
  // Machine Information Registers
  val MVENDORID = "hF11".U(12.W)
  val MARCHID   = "hF12".U(12.W)
  val MIMPID    = "hF13".U(12.W)
  val MHARTID   = "hF14".U(12.W)
}

object Exceptions {
  // Exception causes
  val INST_ADDR_MISALIGNED = 0.U(32.W)
  val INST_ACCESS_FAULT    = 1.U(32.W)
  val ILLEGAL_INST         = 2.U(32.W)
  val BREAKPOINT           = 3.U(32.W)
  val LOAD_ADDR_MISALIGNED = 4.U(32.W)
  val LOAD_ACCESS_FAULT    = 5.U(32.W)
  val STORE_ADDR_MISALIGNED = 6.U(32.W)
  val STORE_ACCESS_FAULT   = 7.U(32.W)
  val ECALL_FROM_U         = 8.U(32.W)
  val ECALL_FROM_S         = 9.U(32.W)
  val ECALL_FROM_M         = 11.U(32.W)
  val INST_PAGE_FAULT      = 12.U(32.W)
  val LOAD_PAGE_FAULT      = 13.U(32.W)
  val STORE_PAGE_FAULT     = 15.U(32.W)
}

object PrivilegeModes {
  val USER_MODE       = "b00".U(2.W)
  val SUPERVISOR_MODE = "b01".U(2.W)
  val MACHINE_MODE    = "b11".U(2.W)
}
