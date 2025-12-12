package nucleusrv.components
import chisel3._
import chisel3.util._ 

class MemoryFetch(TRACE: Boolean) extends Module {
  val io = IO(new Bundle {
    val aluResultIn: UInt = Input(UInt(32.W))
    val writeData: UInt = Input(UInt(32.W))
    val writeEnable: Bool = Input(Bool())
    val readEnable: Bool = Input(Bool())
    val readData: UInt = Output(UInt(32.W))
    val stall: Bool = Output(Bool())
    val f3 = Input(UInt(3.W))

    val dccmReq = Decoupled(new MemRequestIO)
    val dccmRsp = Flipped(Decoupled(new MemResponseIO))

    val wmask = if (TRACE) Some(Output(UInt(4.W))) else None

    val isAMO = Input(Bool())
    val isLR  = Input(Bool())
    val isSC  = Input(Bool())
    val amoOp = Input(UInt(5.W))
  })

  io.dccmRsp.ready := true.B

  val wdata = Wire(Vec(4, UInt(8.W)))
  val rdata = Wire(UInt(32.W))
  val offset = RegInit(0.U(2.W))
  val funct3 = RegInit(0.U(3.W))
  val offsetSW = io.aluResultIn(1,0)
  
  // AMO/LR/SC use full word access
  when(io.isAMO || io.isLR || io.isSC) {
    io.dccmReq.bits.activeByteLane := "b1111".U
    if (TRACE) io.wmask.get := Mux(io.writeEnable, "b1111".U, 0.U)
  }
  .elsewhen(!io.dccmRsp.valid){
    funct3 := io.f3
    offset := io.aluResultIn(1,0)
  }.otherwise{
    funct3 := funct3
    offset := offset
  }

  wdata(0) := io.writeData(7,0)
  wdata(1) := io.writeData(15,8)
  wdata(2) := io.writeData(23,16)
  wdata(3) := io.writeData(31,24)

  /* Store Byte */
  when(io.writeEnable && io.f3 === "b000".U && !io.isAMO && !io.isSC){
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
  .elsewhen(io.writeEnable && io.f3 === "b001".U && !io.isAMO && !io.isSC){
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
  // Store Word or AMO/SC 
  .otherwise{
    io.dccmReq.bits.activeByteLane := "b1111".U
    if (TRACE) io.wmask.get := Mux(io.writeEnable, "b1111".U, 0.U)
  }

  // AMO ALU - Instantiate inside MemoryFetch
  val amoALU = Module(new AMOALU)
  amoALU.io.memData := io.dccmRsp.bits.dataResponse
  amoALU.io.src2 := io.writeData
  amoALU.io.amoOp := io.amoOp

  // Memory Request Control
  io.dccmReq.bits.addrRequest := Cat("b00".U, (io.aluResultIn & "h3FFFFFFF".U)(31, 2))
  
  // For AMO: use AMO ALU result, for normal: use wdata
  io.dccmReq.bits.dataRequest := Mux(io.isAMO && io.writeEnable, 
                                     amoALU.io.result, 
                                     wdata.asUInt)
  
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := io.writeEnable | io.readEnable

  // Stall: wait for memory response
  io.stall := (io.writeEnable || io.readEnable) && !io.dccmRsp.valid

  // Read data
  rdata := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare)

  // Output read data based on operation type
  when(io.readEnable) {
    when(io.isAMO || io.isLR || funct3 === "b010".U) {
      // AMO/LR/LW: full word
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

  // Debug prints
  if (TRACE) {
    when(io.isAMO) {
      when(io.readEnable) {
        printf("[MEM] AMO Read: addr=%x\n", io.aluResultIn)
      }
      when(io.writeEnable && io.dccmRsp.valid) {
        printf("[MEM] AMO Write: addr=%x old=%x new=%x amoOp=%x\n", 
          io.aluResultIn, io.dccmRsp.bits.dataResponse, amoALU.io.result, io.amoOp)
      }
    }
  }
}