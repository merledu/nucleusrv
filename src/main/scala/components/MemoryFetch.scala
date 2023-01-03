
package nucleusrv.components
import chisel3._
import chisel3.util._ 



class MemoryFetch extends Module {
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
  })

  io.dccmRsp.ready := true.B

  val wdata = Wire(Vec(4, UInt(8.W)))
  val rdata = Wire(UInt(32.W))
  val offset = RegInit(0.U(2.W))
  val funct3 = RegInit(0.U(3.W))
  val offsetSW = io.aluResultIn(1,0)

  when(!io.dccmRsp.valid){
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

  /* Store Half Word */
  when(io.writeEnable && io.f3 === "b000".U){
    when(offsetSW === 0.U){
      io.dccmReq.bits.activeByteLane := "b0001".U
    }.elsewhen(offsetSW === 1.U){
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(7,0)
      wdata(2) := io.writeData(23,16)
      wdata(3) := io.writeData(31,24)
      io.dccmReq.bits.activeByteLane := "b0010".U
    }.elsewhen(offsetSW === 2.U){
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(23,16)
      wdata(2) := io.writeData(7,0)
      wdata(3) := io.writeData(31,24)
      io.dccmReq.bits.activeByteLane := "b0100".U
    }.otherwise{
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(23,16)
      wdata(2) := io.writeData(31,24)
      wdata(3) := io.writeData(7,0)
      io.dccmReq.bits.activeByteLane := "b1000".U
    }
  }
    /* Store Half Word */
    .elsewhen(io.writeEnable && io.f3 === "b001".U){
    // offset will either be 0 or 2 since address will be 0x0000 or 0x0002
    when(offsetSW === 0.U){
      // data to be stored at lower 16 bits (15,0)
      io.dccmReq.bits.activeByteLane := "b0011".U
    }.elsewhen(offsetSW === 1.U){
      // data to be stored at lower 16 bits (15,0)
      io.dccmReq.bits.activeByteLane := "b0110".U
      wdata(0) := io.writeData(23,16)
      wdata(1) := io.writeData(7,0)
      wdata(2) := io.writeData(15,8)
      wdata(3) := io.writeData(31,24)
    }.otherwise{
      // data to be stored at upper 16 bits (31,16)
      io.dccmReq.bits.activeByteLane := "b1100".U
      wdata(2) := io.writeData(7,0)
      wdata(3) := io.writeData(15,8)
      wdata(0) := io.writeData(23,16)
      wdata(1) := io.writeData(31,24)
    }
  }
    /* Store Word */
    .otherwise{
    io.dccmReq.bits.activeByteLane := "b1111".U
  }

  io.dccmReq.bits.dataRequest := wdata.asUInt()
  io.dccmReq.bits.addrRequest := (io.aluResultIn & "h00001fff".U) >> 2
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  io.stall := (io.writeEnable || io.readEnable) && !io.dccmRsp.valid

  rdata := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare)


  when(io.readEnable) {
    when(funct3 === "b010".U) {
      // load word
      io.readData := rdata
    }
      .elsewhen(funct3 === "b000".U) {
        // load byte
        when(offset === "b00".U) {
          // addressing memory with 0,4,8...
          io.readData := Cat(Fill(24,rdata(7)),rdata(7,0))
        } .elsewhen(offset === "b01".U) {
          // addressing memory with 1,5,9...
          io.readData := Cat(Fill(24, rdata(15)),rdata(15,8))
        } .elsewhen(offset === "b10".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Fill(24, rdata(23)),rdata(23,16))
        } .elsewhen(offset === "b11".U) {
          // addressing memory with 3,7,11...
          io.readData := Cat(Fill(24, rdata(31)),rdata(31,24))
        } .otherwise {
          // this condition would never occur but using to avoid Chisel generating VOID errors
          io.readData := DontCare
        }
      }
      .elsewhen(funct3 === "b100".U) {
        //load byte unsigned
        when(offset === "b00".U) {
          // addressing memory with 0,4,8...
          io.readData := Cat(Fill(24, 0.U), rdata(7, 0))
        }.elsewhen(offset === "b01".U) {
          // addressing memory with 1,5,9...
          io.readData := Cat(Fill(24, 0.U), rdata(15, 8))
        }.elsewhen(offset === "b10".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Fill(24, 0.U), rdata(23, 16))
        }.elsewhen(offset === "b11".U) {
          // addressing memory with 3,7,11...
          io.readData := Cat(Fill(24, 0.U), rdata(31, 24))
        } .otherwise {
          // this condition would never occur but using to avoid Chisel generating VOID errors
          io.readData := DontCare
        }
      }
      .elsewhen(funct3 === "b101".U) {
        // load halfword unsigned
        when(offset === "b00".U) {
          // addressing memory with 0,4,8...
          io.readData := Cat(Fill(16, 0.U),rdata(15,0))
        } .elsewhen(offset === "b01".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Fill(16, 0.U),rdata(23,8))
        } .elsewhen(offset === "b10".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Fill(16, 0.U),rdata(31,16))
        } .otherwise {
          // this condition would never occur but using to avoid Chisel generating VOID errors
          io.readData := DontCare
        }
      }
      .elsewhen(funct3 === "b001".U) {
        // load halfword
        when(offset === "b00".U) {
          // addressing memory with 0,4,8...
          io.readData := Cat(Fill(16, rdata(15)),rdata(15,0))
        } .elsewhen(offset === "b01".U) {
          // addressing memory with 1,3,7...
          io.readData := Cat(Fill(16, rdata(23)),rdata(23,8))
        } .elsewhen(offset === "b10".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Fill(16, rdata(31)),rdata(31,16))
        } .otherwise {
          // this condition would never occur but using to avoid Chisel generating VOID errors
          io.readData := DontCare
        }
      }
      .otherwise {
      // unknown func3 bits
      io.readData := DontCare
    }
  } .otherwise {
    io.readData := DontCare
  }


  when(io.writeEnable && io.aluResultIn(31, 28) === "h8".asUInt()){
    printf("%x\n", io.writeData)
  }

}
