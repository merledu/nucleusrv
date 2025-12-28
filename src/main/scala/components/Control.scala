package nucleusrv.components
import chisel3._
import chisel3.util._

import nucleusrv.components.FBitPats._

class Control(F: Boolean) extends Module {
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
    //atomic  signals
    val isAMO  = Output(Bool())
    val isLR   = Output(Bool())
    val isSC   = Output(Bool())

    val f_read = if (F) Some(Output(Vec(3, Bool()))) else None
    val f_wr = if (F) Some(Output(Bool())) else None
  })
  // Extract opcode and funct5 for atomic detection
  val opcode = io.in(6, 0)
  val funct3 = io.in(14, 12)
  val funct5 = io.in(31, 27)
  
  // Atomic opcode
  val OPCODE_AMO = "b0101111".U

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
      // CSR
      BitPat("b?????????????????????????1110011") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        1.U, // aluOp
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
      // LR.W
      BitPat("b00010????????????????????0101111") -> List(
        false.B, 
        1.U,   // memToReg (return memory value for AMO/LR)
        true.B,  // regWrite (all atomics write to rd)
        true.B,   // memRead
        false.B,  // memWrite
        false.B,   // branch
        0.U, 
        0.U, 
        0.U
      ),

      // SC.W
      BitPat("b00011????????????????????0101111") -> List(
        false.B, 
        0.U, 
        true.B,  // regWrite (Writes 0/1 to rd)
        false.B,   // memRead
        true.B,   // memWrite (SC is a conditional write, we enable write initially, Core checks reservation)
        false.B,  // branch
        0.U, 
        0.U, 
        0.U
      ),

      // all AMOs same control
      BitPat("b????0??????????????????0101111") -> List(
        false.B, 
        1.U,   // memToReg (return memory value for AMO/LR)
        true.B,  // regWrite (all atomics write to rd)
        false.B,   // memRead (Set to FALSE. Read is enabled by Core state machine !amo_read_done)
        false.B,  // memWrite (Set to FALSE. Write is enabled by Core state machine amo_read_done)
        false.B, // branch
        0.U,  
        0.U, 
        0.U
      )
    ) ++ (
      if (F) Array(
        flw -> List(
          false.B, // aluSrc
          1.U, // memToReg
          false.B, // regWrite
          true.B, // memRead
          false.B, // memWrite
          false.B, // branch
          0.U, // jump
          0.U, // aluOp
          0.U
        ),
        fsw -> List(
          false.B, // aluSrc
          0.U, // memToReg
          false.B, // regWrite
          false.B, // memRead
          true.B, // memWrite
          false.B, // branch
          0.U, // jump
          0.U, // aluOp
          0.U
        )
      ) ++ Array(
        fmadd_s,
        fmsub_s,
        fnmsub_s,
        fnmadd_s,
        fadd_s,
        fsub_s,
        fmul_s,
        fdiv_s,
        fsqrt_s,
        fsgnj_s,
        fsgnjn_s,
        fsgnjx_s,
        fmin_s,
        fmax_s,
        fcvt_s_w,
        fcvt_s_wu,
        fmv_w_x
      ).map(
        _ -> List(
          1.B, // aluSrc
          0.U, // memToReg
          0.B, // regWrite
          false.B, // memRead
          false.B, // memWrite
          false.B, // branch
          0.U, // jump
          1.U, // aluOp
          0.U // aluSrc1
        )
      ) ++ Array(
        fcvt_w_s,
        fcvt_wu_s,
        fmv_x_w,
        feq_s,
        flt_s,
        fle_s,
        fclass_s
      ).map(
        _ -> List(
          1.B, // aluSrc
          0.U, // memToReg
          1.B, // regWrite
          false.B, // memRead
          false.B, // memWrite
          false.B, // branch
          0.U, // jump
          1.U, // aluOp
          0.U // aluSrc1
        )
      ) else Array()
    )
  )
  io.aluSrc := signals(0)
  io.memToReg := signals(1)
  io.regWrite := signals(2)
  io.memRead := signals(3)
  io.memWrite := signals(4)
  io.branch := signals(5)
  io.jump := signals(6)
  io.aluOp := signals(7)
  io.aluSrc1 := signals(8)

  // Default: no atomic operation
  io.isAMO := false.B
  io.isLR  := false.B
  io.isSC  := false.B

  // Detect atomic instructions (opcode = 0101111, funct3 = 010)
  when(opcode === OPCODE_AMO && funct3 === "b010".U) {
    when(funct5 === "b00010".U) {
      // LR.W: Load-Reserved
      io.isLR := true.B
    }
    .elsewhen(funct5 === "b00011".U) {
      // SC.W: Store-Conditional
      io.isSC := true.B
    }
    .otherwise {
      io.isAMO := true.B
    }
  }

  if (F) {
    val f_ctrl = VecInit(Vector(
      flw,
      fsw,
      fmadd_s,
      fmsub_s,
      fnmsub_s,
      fnmadd_s,
      fadd_s,
      fsub_s,
      fmul_s,
      fdiv_s,
      fsqrt_s,
      fsgnj_s,
      fsgnjn_s,
      fsgnjx_s,
      fmin_s,
      fmax_s,
      fcvt_w_s,
      fcvt_wu_s,
      fmv_x_w,
      feq_s,
      flt_s,
      fle_s,
      fclass_s,
      fcvt_s_w,
      fcvt_s_wu,
      fmv_w_x
    ).map(_ === io.in))

    Vector(
      Range(2, 23),  // rs1
      Range(1, 10) ++ Range(11, 16) ++ Range(19, 22),  // rs2
      Range(2, 6)  // rs3
    ).zipWithIndex.foreach(
      f => io.f_read.get(f._2) := f._1.map(
        x => f_ctrl(x)
      ).reduce(_ || _)
    )

    io.f_wr.get := (
      Vector(0) ++ Range(2, 16) ++ Range(23, 26)
    ).map(
      f => f_ctrl(f)
    ).reduce(_ || _)
  }
}
