package nucleusrv.components
import chisel3._
import chisel3.util._

class AtomicDecodeOut extends Bundle {
  val isLR   = Bool()
  val isSC   = Bool()
  val isAMO  = Bool()
  val amoOp  = UInt(4.W) // Encoded value for AMO operation type

  val rs1 = UInt(5.W)
  val rs2 = UInt(5.W)
  val rd  = UInt(5.W)
  val aq  = Bool()
  val rl  = Bool()
}

//atomic instructions (LR/SC/AMO)
class AtomicDecoder extends Module {
  val io = IO(new Bundle {
    val instr = Input(UInt(32.W))
    val out   = Output(new AtomicDecodeOut)
  })

  // Default
  io.out.isLR  := false.B
  io.out.isSC  := false.B
  io.out.isAMO := false.B
  io.out.amoOp := 0.U
  io.out.rs1   := 0.U
  io.out.rs2   := 0.U
  io.out.rd    := 0.U
  io.out.aq    := false.B
  io.out.rl    := false.B

  // instruction fields
  val opcode = io.instr(6,0)
  val rd     = io.instr(11,7)
  val funct3 = io.instr(14,12)
  val rs1    = io.instr(19,15)
  val rs2    = io.instr(24,20)
  val funct5 = io.instr(31,27)
  val aq     = io.instr(26)
  val rl     = io.instr(25)

  // Connect extracted fields
  io.out.rs1 := rs1
  io.out.rs2 := rs2
  io.out.rd  := rd
  io.out.aq  := aq
  io.out.rl  := rl

  // Opcode for atomic instructions
  val OPCODE_ATOMIC = "b0101111".U(7.W)

  // AMO operation codes
  val AMOADD  = 1.U(4.W)
  val AMOSWAP = 2.U(4.W)
  val AMOXOR  = 3.U(4.W)
  val AMOAND  = 4.U(4.W)
  val AMOOR   = 5.U(4.W)
  val AMOMIN  = 6.U(4.W)
  val AMOMAX  = 7.U(4.W)
  val AMOMINU = 8.U(4.W)
  val AMOMAXU = 9.U(4.W)

  // Decode atomic instructions
  when(opcode === OPCODE_ATOMIC && funct3 === "b010".U(3.W)) {
    switch(funct5) {
      is("b00010".U(5.W)) { io.out.isLR := true.B }       // LR.W
      is("b00011".U(5.W)) { io.out.isSC := true.B }       // SC.W
      is("b00000".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOADD }
      is("b00001".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOSWAP }
      is("b00100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOXOR }
      is("b01100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOAND }
      is("b01000".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOOR }
      is("b10000".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMIN }
      is("b10100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMAX }
      is("b11000".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMINU }
      is("b11100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMAXU }
    }
  }
}
