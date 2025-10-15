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

  io.out.isLR  := false.B
  io.out.isSC  := false.B
  io.out.isAMO := false.B
  io.out.amoOp := 0.U

  val opcode = io.instr(6,0)
  val funct5 = io.instr(31,27)
  val funct3 = io.instr(14,12)

  // opcode for atomic instructions
  val OPCODE_ATOMIC = "b0101111".U

  when(opcode === OPCODE_ATOMIC && funct3 === "b010".U) {
    switch(funct5) {
      is("b00010".U) { 
        io.out.isLR := true.B }      // LR.W
      is("b00011".U) { 
        io.out.isSC := true.B }      // SC.W

      is("b00000".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 1.U } // AMOADD
      is("b00001".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 2.U } // AMOSWAP
      is("b00100".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 3.U } // AMOXOR
      is("b01100".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 4.U } // AMOAND
      is("b01000".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 5.U } // AMOOR
      is("b10000".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 6.U } // AMOMIN
      is("b10100".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 7.U } // AMOMAX
      is("b11000".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 8.U } // AMOMINU
      is("b11100".U) { 
        io.out.isAMO := true.B; 
        io.out.amoOp := 9.U } // AMOMAXU
    }
  }
}