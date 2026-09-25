package nucleusrv.components
import chisel3._
import chisel3.util._ 

class MemoryFetch(XLEN:Int, TRACE: Boolean) extends Module {
  val io = IO(new Bundle {
    val aluResultIn: UInt = Input(UInt(XLEN.W))
    val writeData: UInt = Input(UInt(XLEN.W))
    val writeEnable: Bool = Input(Bool())
    val readEnable: Bool = Input(Bool())
    val readData: UInt = Output(UInt(XLEN.W))
    val stall: Bool = Output(Bool())
    val f3 = Input(UInt(3.W))

    // AMO / LR / SC
    val isAMO = Input(Bool())
    val isLR  = Input(Bool())
    val isSC  = Input(Bool())
    val amoOp = Input(UInt(5.W))
    val amoRdVal = Output(UInt(XLEN.W)) // old memory value for rd

    val dccmReq = Decoupled(new MemRequestIO(XLEN = XLEN))
    val dccmRsp = Flipped(Decoupled(new MemResponseIO(XLEN = XLEN)))

    val wmask = if (TRACE) Some(Output(UInt((XLEN / 8).W))) else None
    
    val amo_alu_result_in = Input(UInt(XLEN.W)) // Result from Execute stage
  })

  val BYTE_WIDTH  = 8
  val NUM_BYTES   = XLEN / BYTE_WIDTH
  val OFFSET_BITS = log2Ceil(NUM_BYTES)

  io.dccmRsp.ready := true.B
  
  // val amoALU = Module(new AMOALU) -- Moved to Execute
  val amo_old_value = RegInit(0.U(XLEN.W)) // Register to capture old memory value

  val wdata = Wire(Vec(NUM_BYTES, UInt(BYTE_WIDTH.W)))
  val rdata = Wire(UInt(XLEN.W))
  val offset = RegInit(0.U(OFFSET_BITS.W))
  val funct3 = RegInit(0.U(3.W))
  val offsetSW = io.aluResultIn(OFFSET_BITS - 1,0)

  when(!io.dccmRsp.valid){
    funct3 := io.f3
    offset := io.aluResultIn(OFFSET_BITS - 1,0)
  }.otherwise{
    funct3 := funct3
    offset := offset
  }

  wdata(0) := io.writeData(7,0)
  wdata(1) := io.writeData(15,8)
  wdata(2) := io.writeData(23,16)
  wdata(3) := io.writeData(31,24)

  if (XLEN == 32){
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
    /* Store Word or AMO/LR/SC */
    .otherwise{
      io.dccmReq.bits.activeByteLane := "b1111".U
      if (TRACE) io.wmask.get := Mux(io.writeEnable, "b1111".U, 0.U)
    }
  }
  else {
    wdata(4) := io.writeData(39,32)
    wdata(5) := io.writeData(47,40)
    wdata(6) := io.writeData(55,48)
    wdata(7) := io.writeData(63,56)

    /* Store Byte */
    when(io.writeEnable && io.f3 === "b000".U && !io.isAMO && !io.isSC){
      when(offsetSW === 0.U){
        io.dccmReq.bits.activeByteLane := "b00000001".U
        if (TRACE) io.wmask.get := "b00000001".U
      }.elsewhen(offsetSW === 1.U){
        wdata(0) := io.writeData(15,8)
        wdata(1) := io.writeData(7,0)
        wdata(2) := io.writeData(23,16)
        wdata(3) := io.writeData(31,24)
        wdata(4) := io.writeData(39,32)
        wdata(5) := io.writeData(47,40)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
        io.dccmReq.bits.activeByteLane := "b00000010".U
        if (TRACE) io.wmask.get := "b00000010".U
      }.elsewhen(offsetSW === 2.U){
        wdata(0) := io.writeData(15,8)
        wdata(1) := io.writeData(23,16)
        wdata(2) := io.writeData(7,0)
        wdata(3) := io.writeData(31,24)
        wdata(4) := io.writeData(39,32)
        wdata(5) := io.writeData(47,40)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
        io.dccmReq.bits.activeByteLane := "b00000100".U
        if (TRACE) io.wmask.get := "b00000100".U
      }.elsewhen(offsetSW === 3.U){
        wdata(0) := io.writeData(15,8)
        wdata(1) := io.writeData(23,16)
        wdata(2) := io.writeData(31,24)
        wdata(3) := io.writeData(7,0)
        wdata(4) := io.writeData(39,32)
        wdata(5) := io.writeData(47,40)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
        io.dccmReq.bits.activeByteLane := "b00001000".U
        if (TRACE) io.wmask.get := "b00001000".U
      }.elsewhen(offsetSW === 4.U){
        wdata(0) := io.writeData(15,8)
        wdata(1) := io.writeData(23,16)
        wdata(2) := io.writeData(31,24)
        wdata(3) := io.writeData(39,32)
        wdata(4) := io.writeData(7,0)
        wdata(5) := io.writeData(47,40)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
        io.dccmReq.bits.activeByteLane := "b00010000".U
        if (TRACE) io.wmask.get := "b00010000".U
      }.elsewhen(offsetSW === 5.U){
        wdata(0) := io.writeData(15,8)
        wdata(1) := io.writeData(23,16)
        wdata(2) := io.writeData(31,24)
        wdata(3) := io.writeData(39,32)
        wdata(4) := io.writeData(47,40)
        wdata(5) := io.writeData(7,0)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
        io.dccmReq.bits.activeByteLane := "b00100000".U
        if (TRACE) io.wmask.get := "b00100000".U
      }.elsewhen(offsetSW === 6.U){
        wdata(0) := io.writeData(15,8)
        wdata(1) := io.writeData(23,16)
        wdata(2) := io.writeData(31,24)
        wdata(3) := io.writeData(39,32)
        wdata(4) := io.writeData(47,40)
        wdata(5) := io.writeData(55,48)
        wdata(6) := io.writeData(7,0)
        wdata(7) := io.writeData(63,56)
        io.dccmReq.bits.activeByteLane := "b01000000".U
        if (TRACE) io.wmask.get := "b01000000".U
      }.otherwise{
        wdata(0) := io.writeData(15,8)
        wdata(1) := io.writeData(23,16)
        wdata(2) := io.writeData(31,24)
        wdata(3) := io.writeData(39,32)
        wdata(4) := io.writeData(47,40)
        wdata(5) := io.writeData(55,48)
        wdata(6) := io.writeData(63,56)
        wdata(7) := io.writeData(7,0)
        io.dccmReq.bits.activeByteLane := "b10000000".U
        if (TRACE) io.wmask.get := "b10000000".U
    }
  // /* Store Half Word */
    }.elsewhen(io.writeEnable && io.f3 === "b001".U && !io.isAMO && !io.isSC){
      when(offsetSW === 0.U){
        io.dccmReq.bits.activeByteLane := "b00000011".U
        if (TRACE) io.wmask.get := "b00000011".U
      }.elsewhen(offsetSW === 1.U){
        io.dccmReq.bits.activeByteLane := "b00000110".U
        if (TRACE) io.wmask.get := "b00000110".U
        wdata(0) := io.writeData(23,16)
        wdata(1) := io.writeData(7,0)
        wdata(2) := io.writeData(15,8)
        wdata(3) := io.writeData(31,24)
        wdata(4) := io.writeData(39,32)
        wdata(5) := io.writeData(47,40)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
      }.elsewhen(offsetSW === 2.U){
        io.dccmReq.bits.activeByteLane := "b00001100".U
        if (TRACE) io.wmask.get := "b00001100".U
        wdata(0) := io.writeData(23,16)
        wdata(1) := io.writeData(31,24)
        wdata(2) := io.writeData(7,0)
        wdata(3) := io.writeData(15,8)
        wdata(4) := io.writeData(39,32)
        wdata(5) := io.writeData(47,40)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
      }.elsewhen(offsetSW === 3.U){
        io.dccmReq.bits.activeByteLane := "b00011000".U
        if (TRACE) io.wmask.get := "b00011000".U
        wdata(0) := io.writeData(23,16)
        wdata(1) := io.writeData(31,24)
        wdata(2) := io.writeData(39,32)
        wdata(3) := io.writeData(7,0)
        wdata(4) := io.writeData(15,8)
        wdata(5) := io.writeData(47,40)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
      }.elsewhen(offsetSW === 4.U){
        io.dccmReq.bits.activeByteLane := "b00110000".U
        if (TRACE) io.wmask.get := "b00110000".U
        wdata(0) := io.writeData(23,16)
        wdata(1) := io.writeData(31,24)
        wdata(2) := io.writeData(39,32)
        wdata(3) := io.writeData(47,40)
        wdata(4) := io.writeData(7,0)
        wdata(5) := io.writeData(15,8)
        wdata(6) := io.writeData(55,48)
        wdata(7) := io.writeData(63,56)
      }.elsewhen(offsetSW === 5.U){
        io.dccmReq.bits.activeByteLane := "b01100000".U
        if (TRACE) io.wmask.get := "b01100000".U
        wdata(0) := io.writeData(23,16)
        wdata(1) := io.writeData(31,24)
        wdata(2) := io.writeData(39,32)
        wdata(3) := io.writeData(47,40)
        wdata(4) := io.writeData(55,48)
        wdata(5) := io.writeData(7,0)
        wdata(6) := io.writeData(15,8)
        wdata(7) := io.writeData(63,56)
      }.otherwise{
        io.dccmReq.bits.activeByteLane := "b11000000".U
        if (TRACE) io.wmask.get := "b11000000".U
        wdata(0) := io.writeData(23,16)
        wdata(1) := io.writeData(31,24)
        wdata(2) := io.writeData(39,32)
        wdata(3) := io.writeData(47,40)
        wdata(4) := io.writeData(55,48)
        wdata(5) := io.writeData(63,56)
        wdata(6) := io.writeData(7,0)
        wdata(7) := io.writeData(15,8)
      }
    }// /* Store Word */
    .elsewhen(io.writeEnable && io.f3 === "b010".U){
      when(offsetSW === 0.U){
        io.dccmReq.bits.activeByteLane := "b00001111".U
        if (TRACE) io.wmask.get := "b00001111".U
      }.elsewhen(offsetSW === 1.U){
        io.dccmReq.bits.activeByteLane := "b00011110".U
        if (TRACE) io.wmask.get := "b00011110".U
        wdata(0) := io.writeData(63,56)
        wdata(1) := io.writeData(7,0)
        wdata(2) := io.writeData(15,8)
        wdata(3) := io.writeData(23,16)
        wdata(4) := io.writeData(31,24)
        wdata(5) := io.writeData(39,32)
        wdata(6) := io.writeData(47,40)
        wdata(7) := io.writeData(55,48)
    }.elsewhen(offsetSW === 2.U){
        io.dccmReq.bits.activeByteLane := "b00111100".U
        if (TRACE) io.wmask.get := "b00111100".U
        wdata(0) := io.writeData(55,48)
        wdata(1) := io.writeData(63,56)
        wdata(2) := io.writeData(7,0)
        wdata(3) := io.writeData(15,8)
        wdata(4) := io.writeData(23,16)
        wdata(5) := io.writeData(31,24)
        wdata(6) := io.writeData(39,32)
        wdata(7) := io.writeData(47,40)
    }.elsewhen(offsetSW === 3.U){
        io.dccmReq.bits.activeByteLane := "b01111000".U
        if (TRACE) io.wmask.get := "b01111000".U
        wdata(0) := io.writeData(47,40)
        wdata(1) := io.writeData(55,48)
        wdata(2) := io.writeData(63,56)
        wdata(3) := io.writeData(7,0)
        wdata(4) := io.writeData(15,8)
        wdata(5) := io.writeData(23,16)
        wdata(6) := io.writeData(31,24)
        wdata(7) := io.writeData(39,32)
    }.otherwise{
        io.dccmReq.bits.activeByteLane := "b11110000".U
        if (TRACE) io.wmask.get := "b11110000".U
        wdata(0) := io.writeData(39,32)
        wdata(1) := io.writeData(47,40)
        wdata(2) := io.writeData(55,48)
        wdata(3) := io.writeData(63,56)
        wdata(4) := io.writeData(7,0)
        wdata(5) := io.writeData(15,8)
        wdata(6) := io.writeData(23,16)
        wdata(7) := io.writeData(31,24)
    }
      // /* Store Double Word or AMO/LR/SC */
    }.otherwise{
        io.dccmReq.bits.activeByteLane := "b11111111".U
        if (TRACE) io.wmask.get := Mux(io.writeEnable, "b11111111".U, 0.U)
      }
    }


//   for (i <- 0 until NUM_BYTES) {
//       wdata(i) :=  io.writeData((i + 1) * BYTE_WIDTH - 1, i * BYTE_WIDTH)
//   }

  // Capture old memory value ONLY when AMO read completes
  when(io.dccmRsp.valid && io.readEnable && io.isAMO) {
    amo_old_value := rdata
  }

  // io.amoRdVal is unused by Core, keeping 0
  io.amoRdVal := 0.U

  // For AMO writes: use AMOALU result (from input), for normal stores: use wdata
  val writeDataFinal = Mux(io.isAMO && io.writeEnable, io.amo_alu_result_in, wdata.asUInt)

  io.dccmReq.bits.dataRequest := writeDataFinal
  if (XLEN == 32)
    {io.dccmReq.bits.addrRequest := Cat("b00".U, (io.aluResultIn & "h3FFFFFFF".U)(31, 2))}
  else
    {io.dccmReq.bits.addrRequest := Cat("b000".U, (io.aluResultIn & "h3FFFFFFF".U)(31, 3))}
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  // Stall logic:
  // 1. Standard: Write or Read pending and no response
  // 2. AMO Transition: We just got the Read Response (valid) but we are still in AMO sequence (need to do write next).
  //    Wait, if we stall here, the pipeline holds 'ex_reg' as AMO.
  //    Core state machine will advance 'amo_read_done' to true.
  //    So next cycle, this stall condition will clear because 'readEnable' will be false (amo_read_done is true).
  val amo_transition_stall = io.isAMO && io.readEnable && io.dccmRsp.valid
  //io.stall := ((io.writeEnable || io.readEnable) && !io.dccmRsp.valid) || amo_transition_stall
  io.stall := ((io.writeEnable && !io.dccmReq.ready) || (io.readEnable && !io.dccmRsp.valid)) || amo_transition_stall

  rdata := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare)

  when(io.readEnable) {
    when(funct3 === "b000".U) {
      // load byte (signed)
      if (XLEN == 32) {
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
      } else {
        when(offset === "b000".U) {
          io.readData := Cat(Fill(56,rdata(7)),rdata(7,0))
        } .elsewhen(offset === "b001".U) {
          io.readData := Cat(Fill(56, rdata(15)),rdata(15,8))
        } .elsewhen(offset === "b010".U) {
          io.readData := Cat(Fill(56, rdata(23)),rdata(23,16))
        } .elsewhen(offset === "b011".U) {
          io.readData := Cat(Fill(56, rdata(31)),rdata(31,24))
        } .elsewhen(offset === "b100".U) {
          io.readData := Cat(Fill(56, rdata(39)),rdata(39,32))
        } .elsewhen(offset === "b101".U) {
          io.readData := Cat(Fill(56, rdata(47)),rdata(47,40))
        } .elsewhen(offset === "b110".U) {
          io.readData := Cat(Fill(56, rdata(55)),rdata(55,48))
        } .elsewhen(offset === "b111".U) {
          io.readData := Cat(Fill(56, rdata(63)),rdata(63,56))
        } .otherwise {
          io.readData := DontCare
        }
    }
    }.elsewhen(funct3 === "b100".U) {
      // load byte unsigned
      if (XLEN == 32) {
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
      } else {
        when(offset === "b100".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(7, 0))
        }.elsewhen(offset === "b001".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(15, 8))
        }.elsewhen(offset === "b010".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(23, 16))
        }.elsewhen(offset === "b011".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(31, 24))
        }.elsewhen(offset === "b100".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(39, 32))
        }.elsewhen(offset === "b101".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(47, 40))
        }.elsewhen(offset === "b110".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(55, 48))
        }.elsewhen(offset === "b111".U) {
          io.readData := Cat(Fill(56, 0.U), rdata(63, 56))
        } .otherwise {
          io.readData := DontCare
        }
      }
    }
    .elsewhen(funct3 === "b001".U) {
      // load halfword (signed)
      if (XLEN == 32) {
          when(offset === "b00".U) {
          io.readData := Cat(Fill(16, rdata(15)),rdata(15,0))
        } .elsewhen(offset === "b01".U) {
          io.readData := Cat(Fill(16, rdata(23)),rdata(23,8))
        } .elsewhen(offset === "b10".U) {
          io.readData := Cat(Fill(16, rdata(31)),rdata(31,16))
        } .otherwise {
          io.readData := DontCare
        }
      } else {
        when(offset === "b001".U) {
          io.readData := Cat(Fill(48, rdata(15)),rdata(15,0))
        } .elsewhen(offset === "b001".U) {
          io.readData := Cat(Fill(48, rdata(23)),rdata(23,8))
        } .elsewhen(offset === "b010".U) {
          io.readData := Cat(Fill(48, rdata(31)),rdata(31,16))
        } .elsewhen(offset === "b011".U) {
          io.readData := Cat(Fill(48, rdata(39)),rdata(39,24))
        } .elsewhen(offset === "b100".U) {
          io.readData := Cat(Fill(48, rdata(47)),rdata(47,32))
        } .elsewhen(offset === "b101".U) {
          io.readData := Cat(Fill(48, rdata(55)),rdata(55,40))
        } .elsewhen(offset === "b110".U) {
          io.readData := Cat(Fill(48, rdata(63)),rdata(63,48))
        } .otherwise {
          io.readData := DontCare
        }
      }
    }
    .elsewhen(funct3 === "b101".U) {
      // load halfword unsigned
      if (XLEN == 32) { 
        when(offset === "b00".U) {
          io.readData := Cat(Fill(16, 0.U),rdata(15,0))
        } .elsewhen(offset === "b01".U) {
          io.readData := Cat(Fill(16, 0.U),rdata(23,8))
        } .elsewhen(offset === "b10".U) {
          io.readData := Cat(Fill(16, 0.U),rdata(31,16))
        } .otherwise {
          io.readData := DontCare
        }
      } else {
        when(offset === "b101".U) {
          io.readData := Cat(Fill(48, 0.U),rdata(15,0))
        } .elsewhen(offset === "b001".U) {
          io.readData := Cat(Fill(48, 0.U),rdata(23,8))
        } .elsewhen(offset === "b010".U) {
          io.readData := Cat(Fill(48, 0.U),rdata(31,16))
        } .elsewhen(offset === "b011".U) {
          io.readData := Cat(Fill(48, 0.U),rdata(39,24))
        } .elsewhen(offset === "b100".U) {
          io.readData := Cat(Fill(48, 0.U),rdata(47,32))
        } .elsewhen(offset === "b101".U) {
          io.readData := Cat(Fill(48, 0.U),rdata(55,40))
        } .elsewhen(offset === "b110".U) {
          io.readData := Cat(Fill(48, 0.U),rdata(63,48))
        } .otherwise {
          io.readData := DontCare
        }
      }
    }
    .elsewhen(funct3 === "b010".U || io.isAMO || io.isLR) {
      // load word signed or AMO/LR
      if (XLEN == 32) {
        io.readData := rdata
      } else {
        when(offset === "b000".U) {
          io.readData := Cat(Fill(32, rdata(31)),rdata(31,0))
        } .elsewhen(offset === "b001".U) {
          io.readData := Cat(Fill(32, rdata(39)),rdata(39,8))
        } .elsewhen(offset === "b010".U) {
          io.readData := Cat(Fill(32, rdata(47)),rdata(47,16))
        } .elsewhen(offset === "b011".U) {
          io.readData := Cat(Fill(32, rdata(55)),rdata(55,24))
        } .elsewhen(offset === "b100".U) {
          io.readData := Cat(Fill(32, rdata(63)),rdata(63,32))
        } .otherwise {
          io.readData := DontCare
        }
      }
    }
    .elsewhen(funct3 === "b110".U) {
      // load word unsigned
      if (XLEN == 32) {
        io.readData := rdata
      } else {
        when(offset === "b000".U) {
          io.readData := Cat(Fill(32, 0.U),rdata(31,0))
        } .elsewhen(offset === "b001".U) {
          io.readData := Cat(Fill(32, 0.U),rdata(39,8))
        } .elsewhen(offset === "b010".U) {
          io.readData := Cat(Fill(32, 0.U),rdata(47,16))
        } .elsewhen(offset === "b011".U) {
          io.readData := Cat(Fill(32, 0.U),rdata(55,24))
        } .elsewhen(offset === "b100".U) {
          io.readData := Cat(Fill(32, 0.U),rdata(63,32))
        } .otherwise {
          io.readData := DontCare
        }
      }
    }
    .elsewhen(funct3 === "b110".U) {
      io.readData := rdata
    }
    .otherwise {
      io.readData := DontCare
    }
    }.otherwise {
      io.readData := DontCare
    }
}