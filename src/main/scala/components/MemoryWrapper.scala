package nucleusrv.components

import chisel3._
import chisel3.util._
import caravan.bus.common.{BusConfig, AbstrRequest, AbstrResponse}

class MemoryWrapper(val req:AbstrRequest, val rsp:AbstrResponse)(implicit val config:BusConfig) extends Module {
    val io = IO(new Bundle{
        val request = Flipped(Decoupled(req))   
        val response = Decoupled(rsp)          
    })

    io.request.ready := true.B

    val data = Wire(Vec(4,UInt()))
    val mem = Module(new SRam)

    //clock and csb
    // val clk0 = Input(Bool())
    // val csb0 = Input(Bool())

    // for sending request
    when(io.request.fire() & io.request.bits.isWrite){                                      
        val maskedData = io.request.bits.dataRequest.asTypeOf(Vec(4, UInt(8.W)))        
        data := io.request.bits.activeByteLane.asBools zip maskedData map {                  
            case (b:Bool, i:UInt) => Mux(b, i, 0.U)
        }

        // feed these pins into the BLACK BOX of SRAM/Peripheral
        mem.io.din0 := data.asUInt                     // ye data hy 
        mem.io.addr0 := io.request.bits.addrRequest     // ye address hay
        mem.io.web0 := ~io.request.bits.isWrite         // ye write enable hy
        mem.io.csb0 := 1.B

    }.elsewhen(io.request.fire() & ~io.request.bits.isWrite){                                // if req is of read
        
        mem.io.din0 := io.request.bits.addrRequest     // ye address hy
        mem.io.addr0 := io.request.bits.dataRequest     // ye data hy, but kisi kaam ka nahi
        mem.io.web0 := ~io.request.bits.isWrite         // ye write enable h, low hga read k lye
        mem.io.csb0 := 1.B

    }.otherwise{
        mem.io.din0 := DontCare
        mem.io.addr0 := DontCare  
        mem.io.web0 := DontCare
        mem.io.csb0 := DontCare

        

    }

    // For recieveing response
    val responseData =  mem.io.dout0                // yahan data phek do, response se any wala

    // CAUTION => If data is coming after 1 or more cycles, you have preserve the io.request.bits.activeByteLane pin
    // until the data comes back as response
    // If your Module(SRAM/Peripheral) can done masking inside of it then it willbe good. Otherwise PRESERVE IT!
    
    val maskedData = responseData.asTypeOf(Vec(4, UInt(8.W)))                       // breaking into Vecs to apply masking
    data := io.request.bits.activeByteLane.asBools zip maskedData map {                  // applying maskiing a/c to mask bits (activeByteLane)
        case (b:Bool, i:UInt) => Mux(b, i, 0.U)
    }

    io.response.bits.dataResponse := data.asUInt        // sending data as response
    io.response.bits.error := false.B                    // implement a logic for error here, if the response has error
    io.response.valid := true.B                          // implement a logic for indicating that the requested READ/WRITE operation is done and the response signal coming is valud
                                                        // valid pin shall be high for one cycle ONLY
}