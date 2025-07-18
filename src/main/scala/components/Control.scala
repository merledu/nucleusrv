
package nucleusrv.components
import chisel3._
import chisel3.util._

class Control extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(32.W))
    val aluSrc = Output(Bool())
    val memToReg = Output(UInt(2.W))
    val regWrite = Output(Bool())
    val memRead = Output(Bool())
    val memWrite = Output(Bool())
    val branch = Output(Bool())
    val aluOp = Output(UInt(2.W))
    val jump = Output(UInt(2.W))
    val aluSrc1 = Output(UInt(2.W))
    
    // New CSR and system instruction signals
    val csr_read = Output(Bool())
    val csr_write = Output(Bool())
    val csr_op = Output(UInt(3.W))
    val is_ecall = Output(Bool())
    val is_ebreak = Output(Bool())
    val is_mret = Output(Bool())
    val is_system = Output(Bool())
  })

  import Instructions._

  // Extract instruction fields
  val opcode = io.in(6, 0)
  val funct3 = io.in(14, 12)
  val funct12 = io.in(31, 20)
  val rs1 = io.in(19, 15)

  // Detect system instructions
  val is_system_inst = opcode === SYSTEM_OPCODE
  val is_csr_inst = is_system_inst && (funct3 =/= 0.U)
  val is_ecall_inst = is_system_inst && (funct3 === 0.U) && (funct12 === ECALL_FUNCT12) && (rs1 === 0.U)
  val is_ebreak_inst = is_system_inst && (funct3 === 0.U) && (funct12 === EBREAK_FUNCT12) && (rs1 === 0.U)
  val is_mret_inst = is_system_inst && (funct3 === 0.U) && (funct12 === MRET_FUNCT12) && (rs1 === 0.U)

  val signals = ListLookup(
    io.in,
    /*   aluSrc  ToReg regWrite memRead  memWrite branch  jump  aluOp aluSrc1*/
    List(false.B, 0.U, false.B, false.B, false.B, false.B, 0.U, 0.U, 0.U),
    Array(
      // R-Type
      BitPat("b?????????????????????????0110011") -> List(
        true.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        2.U, // aluOp
        0.U // aluSrc1
      ),
      // I-Type
      BitPat("b?????????????????????????0010011") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        2.U, // aluOp
        0.U
      ),
      // Load
      BitPat("b?????????????????????????0000011") -> List(
        false.B, // aluSrc
        1.U, // memToReg
        true.B, // regWrite
        true.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        0.U
      ),
      // Store
      BitPat("b?????????????????????????0100011") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        false.B, // regWrite
        false.B, // memRead
        true.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        0.U
      ),
      // SB-Type
      BitPat("b?????????????????????????1100011") -> List(
        true.B, // aluSrc
        0.U, // memToReg
        false.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        true.B, // branch
        0.U, // jump
        0.U, // aluOp
        0.U
      ),
      // lui
      BitPat("b?????????????????????????0110111") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        2.U  // aluSrc1
      ),
      // auipc
      BitPat("b?????????????????????????0010111") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        1.U  // aluSrc1
      ),
      // jal
      BitPat("b?????????????????????????1101111") -> List(
        false.B, // aluSrc
        2.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        1.U, // jump
        0.U, // aluOp
        0.U
      ),
      // jalr
      BitPat("b?????????????????????????1100111") -> List(
        false.B, // aluSrc
        2.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        2.U, // jump
        0.U, // aluOp
        0.U
      ),
      // System instructions (CSR, ECALL, EBREAK, MRET)
      BitPat("b?????????????????????????1110011") -> List(
        false.B, // aluSrc
        3.U, // memToReg (CSR data to register)
        true.B, // regWrite (for CSR reads)
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        0.U
      )
    )
  )
  
  io.aluSrc := signals(0)
  io.memToReg := signals(1)
  io.regWrite := signals(2) && (!is_ecall_inst && !is_ebreak_inst && !is_mret_inst)  // Don't write for system calls
  io.memRead := signals(3)
  io.memWrite := signals(4)
  io.branch := signals(5)
  io.jump := signals(6)
  io.aluOp := signals(7)
  io.aluSrc1 := signals(8)
  
  // CSR and system instruction control signals
  io.csr_read := is_csr_inst
  io.csr_write := is_csr_inst && (funct3 === CSRRW || funct3 === CSRRS || funct3 === CSRRC ||
                                  funct3 === CSRRWI || funct3 === CSRRSI || funct3 === CSRRCI) &&
                                  (rs1 =/= 0.U || funct3 === CSRRW || funct3 === CSRRWI)
  io.csr_op := funct3
  io.is_ecall := is_ecall_inst
  io.is_ebreak := is_ebreak_inst
  io.is_mret := is_mret_inst
  io.is_system := is_system_inst
}