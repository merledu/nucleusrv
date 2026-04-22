package nucleusrv.components
import chisel3._
import chisel3.util._ 

class MemoryFetch(
  A: Boolean,
  TRACE: Boolean
) extends Module {
  val io = IO(new Bundle {
    val aluResultIn: UInt = Input(UInt(32.W))
    val writeData: UInt = Input(UInt(32.W))
    val writeEnable: Bool = Input(Bool())
    val readEnable: Bool = Input(Bool())
    val readData: UInt = Output(UInt(32.W))
    val stall: Bool = Output(Bool())
    val f3 = Input(UInt(3.W))

    // AMO / LR / SC
    val isAMO = if (A) Some(Input(Bool())) else None
    val isLR  = if (A) Some(Input(Bool())) else None
    val isSC  = if (A) Some(Input(Bool())) else None
    val amoOp = if (A) Some(Input(UInt(5.W))) else None
    val amoRdVal = if (A) Some(Output(UInt(32.W))) else None // old memory value for rd
    val amo_stall = if (A) Some(Output(Bool())) else None

    val dccmReq = Decoupled(new MemRequestIO)
    val dccmRsp = Flipped(Decoupled(new MemResponseIO))

    val wmask = if (TRACE) Some(Output(UInt(4.W))) else None
    
    val amo_alu_result_in = if (A) Some(Input(UInt(32.W))) else None // Result from Execute stage
  })

  io.dccmRsp.ready := true.B
  
  // val amoALU = Module(new AMOALU) -- Moved to Execute
  val amo_old_value = if (A) Some(RegInit(0.U(32.W))) else None // Register to capture old memory value

  val wdata = Wire(Vec(4, UInt(8.W)))
  val rdata = Wire(UInt(32.W))
  val offset = WireInit(0.U(2.W))
  val funct3 = WireInit(0.U(3.W))
  val offsetSW = io.aluResultIn(1,0)

  //when(!io.dccmRsp.valid){
    funct3 := io.f3
    offset := io.aluResultIn(1,0)
  //}.otherwise{
    //funct3 := funct3
    //offset := offset
  //}

  wdata(0) := io.writeData(7,0)
  wdata(1) := io.writeData(15,8)
  wdata(2) := io.writeData(23,16)
  wdata(3) := io.writeData(31,24)

  /* Store Byte */
  when(io.writeEnable && io.f3 === "b000".U && (
    if (A) !io.isAMO.get && !io.isSC.get else 1.B
  )){
    when(offsetSW === 0.U){
      io.dccmReq.bits.activeByteLane := "b0001".U
      if (TRACE) io.wmask.get := "b0001".U
    }.elsewhen(offsetSW === 1.U){
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(7,0)
      wdata(2) := io.writeData(23,16)
      wdata(3) := io.writeData(31,24)
      io.dccmReq.bits.activeByteLane := "b0010".U
      if (TRACE) io.wmask.get := "b0010".U
    }.elsewhen(offsetSW === 2.U){
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(23,16)
      wdata(2) := io.writeData(7,0)
      wdata(3) := io.writeData(31,24)
      io.dccmReq.bits.activeByteLane := "b0100".U
      if (TRACE) io.wmask.get := "b0100".U
    }.otherwise{
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(23,16)
      wdata(2) := io.writeData(31,24)
      wdata(3) := io.writeData(7,0)
      io.dccmReq.bits.activeByteLane := "b1000".U
      if (TRACE) io.wmask.get := "b1000".U
    }
  }
  /* Store Half Word */
  .elsewhen(io.writeEnable && io.f3 === "b001".U && (
    if (A) !io.isAMO.get && !io.isSC.get else 1.B
  )){
    // offset will either be 0 or 2 since address will be 0x0000 or 0x0002
    when(offsetSW === 0.U){
      io.dccmReq.bits.activeByteLane := "b0011".U
      if (TRACE) io.wmask.get := "b0011".U
    }.elsewhen(offsetSW === 1.U){
      io.dccmReq.bits.activeByteLane := "b0110".U
      if (TRACE) io.wmask.get := "b0110".U
      wdata(0) := io.writeData(23,16)
      wdata(1) := io.writeData(7,0)
      wdata(2) := io.writeData(15,8)
      wdata(3) := io.writeData(31,24)
    }.otherwise{
      io.dccmReq.bits.activeByteLane := "b1100".U
      if (TRACE) io.wmask.get := "b1100".U
      wdata(2) := io.writeData(7,0)
      wdata(3) := io.writeData(15,8)
      wdata(0) := io.writeData(23,16)
      wdata(1) := io.writeData(31,24)
    }
  }
  /* Store Word or AMO/LR/SC */
  .otherwise{
    io.dccmReq.bits.activeByteLane := "b1111".U
    if (TRACE) io.wmask.get := Mux(io.writeEnable, "b1111".U, 0.U)
  }

  // Capture old memory value ONLY when AMO read completes
  if (A) {
    when(io.dccmRsp.valid && io.readEnable && io.isAMO.get) {
      amo_old_value.get := rdata
    }
  }

  // io.amoRdVal is unused by Core, keeping 0
  if (A) {
    io.amoRdVal.get := 0.U
  }

  // For AMO writes: use AMOALU result (from input), for normal stores: use wdata
  val writeDataFinal = if (A) Mux(io.isAMO.get && io.writeEnable, io.amo_alu_result_in.get, wdata.asUInt) else wdata.asUInt

  val addr = Cat("b00".U, (io.aluResultIn & "h3FFFFFFF".U)(31, 2))
  //val addr = io.aluResultIn
  io.dccmReq.bits.dataRequest := writeDataFinal
  io.dccmReq.bits.addrRequest := dontTouch(addr)
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  // Stall logic:
  // 1. Standard: Write or Read pending and no response
  // 2. AMO Transition: We just got the Read Response (valid) but we are still in AMO sequence (need to do write next).
  //    Wait, if we stall here, the pipeline holds 'ex_reg' as AMO.
  //    Core state machine will advance 'amo_read_done' to true.
  //    So next cycle, this stall condition will clear because 'readEnable' will be false (amo_read_done is true).
  val amo_transition_stall = if (A) Some(io.isAMO.get && io.readEnable && io.dccmRsp.valid) else None
  dontTouch(io.stall) := (false.B
  //  io.writeEnable && io.dccmReq.ready
  //) || (
  //  io.readEnable && !io.dccmRsp.valid
  )
  if (A) {
    io.amo_stall.get := amo_transition_stall.get
  }

  rdata := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare)

  when(io.readEnable) {
    when(funct3 === "b010".U || (
      if (A) (io.isAMO.get || io.isLR.get) else 0.B
    )) {
      // load word or AMO/LR
      io.readData := rdata
    }
    .elsewhen(funct3 === "b000".U) {
      // load byte (signed)
      when(offset === "b00".U) {
        io.readData := Cat(Fill(24,rdata(7)),rdata(7,0))
      } .elsewhen(offset === "b01".U) {
        io.readData := Cat(Fill(24, rdata(15)),rdata(15,8))
      } .elsewhen(offset === "b10".U) {
        io.readData := Cat(Fill(24, rdata(23)),rdata(23,16))
      } .elsewhen(offset === "b11".U) {
        io.readData := Cat(Fill(24, rdata(31)),rdata(31,24))
      } .otherwise {
        io.readData := DontCare
      }
    }
    .elsewhen(funct3 === "b100".U) {
      // load byte unsigned
      when(offset === "b00".U) {
        io.readData := Cat(Fill(24, 0.U), rdata(7, 0))
      }.elsewhen(offset === "b01".U) {
        io.readData := Cat(Fill(24, 0.U), rdata(15, 8))
      }.elsewhen(offset === "b10".U) {
        io.readData := Cat(Fill(24, 0.U), rdata(23, 16))
      }.elsewhen(offset === "b11".U) {
        io.readData := Cat(Fill(24, 0.U), rdata(31, 24))
      } .otherwise {
        io.readData := DontCare
      }
    }
    .elsewhen(funct3 === "b101".U) {
      // load halfword unsigned
      when(offset === "b00".U) {
        io.readData := Cat(Fill(16, 0.U),rdata(15,0))
      } .elsewhen(offset === "b01".U) {
        io.readData := Cat(Fill(16, 0.U),rdata(23,8))
      } .elsewhen(offset === "b10".U) {
        io.readData := Cat(Fill(16, 0.U),rdata(31,16))
      } .otherwise {
        io.readData := DontCare
      }
    }
    .elsewhen(funct3 === "b001".U) {
      // load halfword (signed)
      when(offset === "b00".U) {
        io.readData := Cat(Fill(16, rdata(15)),rdata(15,0))
      } .elsewhen(offset === "b01".U) {
        io.readData := Cat(Fill(16, rdata(23)),rdata(23,8))
      } .elsewhen(offset === "b10".U) {
        io.readData := Cat(Fill(16, rdata(31)),rdata(31,16))
      } .otherwise {
        io.readData := DontCare
      }
    }
    .otherwise {
      io.readData := DontCare
    }
  } .otherwise {
    io.readData := DontCare
  }
}
