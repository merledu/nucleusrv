package nucleusrv.components
import chisel3._
import chisel3.util._ 



class MemoryFetch extends Module {
  val io = IO(new Bundle {
    val aluResultIn: UInt = Input(UInt(32.W))
    val v_addr: UInt = Input(UInt(32.W))
    val v_ins:Bool = Input(Bool())
    val writeData: UInt = Input(UInt(32.W))
    val v_writeData: UInt = Input(UInt(32.W))
    val vs0: UInt = Input(UInt(4.W))

    val ins: UInt = Input(UInt(32.W))
    val load_addr: UInt = Input(UInt(32.W))
    val vd_Data: UInt = Input(UInt(32.W))
    val m_v0: UInt = Input(UInt(4.W))
    val l_m_b  = Input(Bool()) //define load mask bit
    val eew: UInt = Input(UInt(4.W))


    val writeEnable: Bool = Input(Bool())
    val readEnable: Bool = Input(Bool())
    val readData: UInt = Output(UInt(32.W))
    val stall: Bool = Output(Bool())
    val f3 = Input(UInt(3.W))

    val dccmReq = Decoupled(new MemRequestIO)
    val dccmRsp = Flipped(Decoupled(new MemResponseIO))
  })
  dontTouch(io.vd_Data)
 dontTouch(io.v_addr)
 dontTouch(io.vs0)
  io.dccmRsp.ready := true.B
  var addr = WireInit(0.U(32.W))
  var data = WireInit(0.U(32.W))
  dontTouch(addr)
  dontTouch(data)
  when(io.v_ins === 1.B){
    addr := io.load_addr
    data := io.v_writeData
  }.otherwise{
    addr := io.aluResultIn
    data := io.writeData
  }
  val  mu = WireInit(false.B)
  val wdata = Wire(Vec(4, UInt(8.W)))
  val rdata = Wire(UInt(32.W))
  val offset = RegInit(0.U(2.W))
  val funct3 = RegInit(0.U(3.W))
  val m_v0 = RegInit(0.U(4.W))
  val v_ins =RegInit(false.B)
  val eew = RegInit(0.U(4.W))
  val vd_data = RegInit(0.U(32.W))
  val l_m_b = RegInit(false.B)
  val offsetSW = addr(1,0)

  v_ins := io.v_ins
  when(!io.dccmRsp.valid){
    funct3 := io.f3
    offset := addr(1,0)
  }.otherwise{
    funct3 := funct3
    offset := offset
  }
  m_v0 := io.m_v0
  eew := io.eew
  vd_data := io.vd_Data
  l_m_b := io.l_m_b

  wdata(0) := data(7,0)
  wdata(1) := data(15,8)
  wdata(2) := data(23,16)
  wdata(3) := data(31,24)

  /* Store Half Word */
  when(io.v_ins === 1.B){
     wdata(0) := data(7,0)
     wdata(1) := data(15,8)
     wdata(2) := data(23,16)
     wdata(3) := data(31,24)
      io.dccmReq.bits.activeByteLane := io.vs0
  }.otherwise{
  when(io.writeEnable && io.f3 === "b000".U){
    when(offsetSW === 0.U){
      io.dccmReq.bits.activeByteLane := "b0001".U
    }.elsewhen(offsetSW === 1.U){
      wdata(0) := data(15,8)
      wdata(1) := data(7,0)
      wdata(2) := data(23,16)
      wdata(3) := data(31,24)
      io.dccmReq.bits.activeByteLane := "b0010".U
    }.elsewhen(offsetSW === 2.U){
      wdata(0) := data(15,8)
      wdata(1) := data(23,16)
      wdata(2) := data(7,0)
      wdata(3) := data(31,24)
      io.dccmReq.bits.activeByteLane := "b0100".U
    }.otherwise{
      wdata(0) := data(15,8)
      wdata(1) := data(23,16)
      wdata(2) := data(31,24)
      wdata(3) := data(7,0)
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
      wdata(0) := data(23,16)
      wdata(1) := data(7,0)
      wdata(2) := data(15,8)
      wdata(3) := data(31,24)
    }.otherwise{
      // data to be stored at upper 16 bits (31,16)
      io.dccmReq.bits.activeByteLane := "b1100".U
      wdata(2) := data(7,0)
      wdata(3) := data(15,8)
      wdata(0) := data(23,16)
      wdata(1) := data(31,24)
    }
  }
    /* Store Word */
    .otherwise{
    io.dccmReq.bits.activeByteLane := "b1111".U
  }
  }
  io.dccmReq.bits.dataRequest := wdata.asUInt()
  io.dccmReq.bits.addrRequest := (addr & "h00001fff".U) >> 2
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  io.stall := (io.writeEnable || io.readEnable) && !io.dccmRsp.valid

  rdata := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare)

  when(v_ins===0.B){
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
  }}
  .otherwise{
    when(io.readEnable===1.B){
    when(eew === "b000".U && l_m_b===0.B) {
        //load byte unsigned
        when(m_v0 === "b0001".U) {
          // addressing memory with 0,4,8...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,8),Fill(24,1.U)),rdata(7,0))
        }.elsewhen(m_v0 === "b0010".U) {
          // addressing memory with 1,5,9...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,16),Fill(16,1.U)),rdata(15,8),Mux((l_m_b===0.B && mu===0.B),vd_data(7,0),Fill(8,1.U)))
        }.elsewhen(m_v0 === "b0100".U) {
         // addressing memory with 2,6,10...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,24),Fill(8,1.U)),rdata(23,16),Mux((l_m_b===0.B && mu===0.B),vd_data(15,0),Fill(16,1.U)))
        }.elsewhen(m_v0 === "b1000".U) {
          // addressing memory with 3,7,11...
          io.readData := Cat(rdata(31,24),Mux((l_m_b===0.B && mu===0.B),vd_data(23,0),Fill(24,1.U)))
        } .elsewhen(m_v0 === "b0011".U) {
          // addressing memory with 0,4,8...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,16),Fill(16,1.U)),rdata(15,0))
        } .elsewhen(m_v0 === "b0110".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,24),Fill(8,1.U)),rdata(23,8),Mux((l_m_b===0.B && mu===0.B),vd_data(7,0),Fill(8,1.U)))
        } .elsewhen(m_v0 === "b1100".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(rdata(31,16),Mux((l_m_b===0.B && mu===0.B),vd_data(15,0),Fill(16,1.U)))
          }.elsewhen(m_v0 === "b0101".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,24),Fill(8,1.U)),rdata(23,16),Mux((l_m_b===0.B && mu===0.B),vd_data(15,8),Fill(8,1.U)),rdata(7,0))
        }.elsewhen(m_v0 === "b1010".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(rdata(31,24),Mux((l_m_b===0.B && mu===0.B),vd_data(23,16),Fill(8,1.U)),rdata(15,8),Mux((l_m_b===0.B && mu===0.B),vd_data(7,0),Fill(8,1.U)))
        }.elsewhen(m_v0 === "b1001".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(rdata(31,24), Mux((l_m_b===0.B && mu===0.B),vd_data(23,8),Fill(16,1.U)), rdata(7,0))
        }.elsewhen(m_v0 === "b0111".U) {
          // addressing memory with 0,4,8...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,24),Fill(8,1.U)),rdata(23,0))
        } .elsewhen(m_v0 === "b1110".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(rdata(31,8), Mux((l_m_b===0.B && mu===0.B),vd_data(7,0),Fill(8,1.U)))
        } .elsewhen(m_v0 === "b1101".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(rdata(31,16), Mux((l_m_b===0.B && mu===0.B),vd_data(15,8),Fill(8,1.U)),rdata(7,0))
        }.elsewhen(m_v0 === "b1011".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(rdata(31,24), Mux((l_m_b===0.B && mu===0.B),vd_data(23,16),Fill(8,1.U)),rdata(15,0))
        }.elsewhen(m_v0 === "b0000".U) {
          // this condition would never occur but using to avoid Chisel generating VOID errors
          io.readData := Mux((l_m_b===0.B && mu===0.B),vd_data,Fill(32,1.U))
        }.elsewhen(m_v0 === "b1111".U) {
          // this condition would never occur but using to avoid Chisel generating VOID errors
          io.readData := rdata
        }.otherwise{
          io.readData := rdata
        }
      }.elsewhen(eew==="b101".U  && l_m_b===0.B){ //1 element width=16 bits
           when(m_v0 === "b0011".U) {
          // addressing memory with 0,4,8...
          io.readData := rdata
        } .elsewhen(m_v0 === "b0001".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(Mux((l_m_b===0.B && mu===0.B),vd_data(31,16),Fill(16,1.U)),rdata(15,0))
        } .elsewhen(m_v0 === "b0010".U) {
          // addressing memory with 2,6,10...
          io.readData := Cat(rdata(31,16),Mux((l_m_b===0.B && mu===0.B),vd_data(15,0),Fill(16,1.U)))
        }.otherwise{
          // addressing memory with 2,6,10...
          io.readData := Mux((l_m_b===0.B && mu===0.B),vd_data,Fill(32,1.U))
        }
      }.elsewhen(eew==="b110".U && l_m_b===0.B){ //1 element width=32 bits
           when(m_v0 === "b0001".U) {
          // addressing memory with 0,4,8...
              io.readData := rdata
        }.otherwise{
          io.readData := Mux((l_m_b===0.B && mu===0.B),vd_data,Fill(32,1.U))
        }}
        .elsewhen(l_m_b===1.B){
          io.readData := rdata
        }

      .otherwise {
          // this condition would never occur but using to avoid Chisel generating VOID errors
          io.readData := rdata
        }
        }
        .otherwise {
    io.readData := DontCare
  }
  }
  dontTouch(io.l_m_b)
  dontTouch(mu)


  when(io.writeEnable){
    printf("%x\n", data)
  }

}