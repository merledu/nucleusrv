package nucleusrv.components
import chisel3._
import chisel3.util._

class AtomicDecodeOut extends Bundle {
  val isLR   = Bool()
  val isSC   = Bool()
  val isAMO  = Bool()
  val amoOp  = UInt(5.W)    // AMO operation type (funct5 from instruction)

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
  val ADD  = "b00000".U
  val SWAP = "b00001".U
  val XOR  = "b00100".U
  val AND  = "b01100".U
  val OR   = "b01000".U
  val MIN  = "b10000".U
  val MAX  = "b10100".U
  val MINU = "b11000".U
  val MAXU = "b11100".U

  when(opcode === OPCODE_ATOMIC && funct3 === "b010".U) {
    switch(funct5) {
      is("b00010".U) { io.out.isLR  := true.B; io.out.amoOp := "b00010".U }             // LR.W
      is("b00011".U) { io.out.isSC  := true.B; io.out.amoOp := "b00011".U}             // SC.W

      is(ADD)  { io.out.isAMO := true.B; io.out.amoOp := ADD } // AMOADD
      is(SWAP) { io.out.isAMO := true.B; io.out.amoOp := SWAP } // AMOSWAP
      is(XOR)  { io.out.isAMO := true.B; io.out.amoOp := funct5 } // AMOXOR
      is(AND)  { io.out.isAMO := true.B; io.out.amoOp := funct5 } // AMOAND
      is(OR)   { io.out.isAMO := true.B; io.out.amoOp := funct5 } // AMOOR
      is(MIN)  { io.out.isAMO := true.B; io.out.amoOp := funct5 } // AMOMIN
      is(MAX)  { io.out.isAMO := true.B; io.out.amoOp := funct5 } // AMOMAX
      is(MINU) { io.out.isAMO := true.B; io.out.amoOp := funct5 } // AMOMINU
      is(MAXU) { io.out.isAMO := true.B; io.out.amoOp := funct5 } // AMOMAXU
    }
  }
}
