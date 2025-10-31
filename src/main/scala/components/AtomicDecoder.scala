package nucleusrv.components
import chisel3._
import chisel3.util._

class AtomicDecodeOut extends Bundle {
  val isLR   = Bool()
  val isSC   = Bool()
  val isAMO  = Bool()
  val amoOp  = UInt(4.W) // Encoded value for AMO operation type
}

class AtomicDecoder extends Module {
  val io = IO(new Bundle {
    val instr = Input(UInt(32.W))
    val out   = Output(new AtomicDecodeOut)
  })

  // Default values
  io.out.isLR  := false.B
  io.out.isSC  := false.B
  io.out.isAMO := false.B
  io.out.amoOp := 0.U

  // Instruction fields
  val opcode = io.instr(6,0)
  val funct5 = io.instr(31,27)
  val funct3 = io.instr(14,12)

  // Opcode for atomic instructions (7 bits)
  val OPCODE_ATOMIC = "b0101111".U(7.W)

  // AMO operation codes (constants)
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
      is("b00010".U(5.W)) { 
        io.out.isLR := true.B }   // LR.W
      is("b00011".U(5.W)) { 
        io.out.isSC := true.B }   // SC.W
      is("b00000".U(5.W)) { 
        io.out.isAMO := true.B; io.out.amoOp := AMOADD } //0
      is("b00001".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOSWAP } //1
      is("b00100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOXOR } //4
      is("b01100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOAND } //12
      is("b01000".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOOR } //8
      is("b10000".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMIN } //16
      is("b10100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMAX } //20
      is("b11000".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMINU } //24
      is("b11100".U(5.W)) { io.out.isAMO := true.B; io.out.amoOp := AMOMAXU } //28
    }
  }
}
