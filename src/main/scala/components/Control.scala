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
       // Atomic instructions (opcode = 0101111)
      // Base pattern for all atomics - will be overridden by specific logic below
      BitPat("b?????????????????????????0101111") -> List(
        true.B,  // aluSrc (rs1 is base address)
        1.U,     // memToReg (return memory value for AMO/LR)
        true.B,  // regWrite (all atomics write to rd)
        false.B, // memRead (controlled by Core state machine)
        false.B, // memWrite (controlled by Core state machine)
        false.B, // branch
        0.U,     // jump
        0.U,     // aluOp (address calculation)
        0.U      // aluSrc1
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

  //Atomic instruction detection and control override
  // Default: no atomic operation
  io.isAMO := false.B
  io.isLR  := false.B
  io.isSC  := false.B

  // Detect atomic instructions (opcode = 0101111, funct3 = 010)
  when(opcode === OPCODE_AMO && funct3 === "b010".U) {
    when(funct5 === "b00010".U) {
      // LR.W: Load-Reserved
      io.isLR := true.B
      // LR needs: memRead (handled by Core), regWrite=true, memToReg=1 (return memory value)
      // These are already set by the ListLookup pattern above
    }
    .elsewhen(funct5 === "b00011".U) {
      // SC.W: Store-Conditional
      io.isSC := true.B
      // SC needs: regWrite=true (write success/fail), memToReg=0 (use computed result)
      io.memToReg := 0.U  // Override: SC returns 0 or 1, not memory value
    }
    .otherwise {
      // AMO operations (AMOADD, AMOSWAP, etc.)
      io.isAMO := true.B
      // AMO needs: regWrite=true, memToReg=1 (return OLD memory value to rd)
      // These are already set by the ListLookup pattern above
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
