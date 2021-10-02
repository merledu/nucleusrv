// package components

// import chisel3._
// import chisel3.util._
// import caravan.bus.common.{BusConfig, AbstrRequest, AbstrResponse}

// class MemoryWrapper(val req:AbstrRequest, val rsp:AbstrResponse)(implicit val config:BusConfig) extends Module {
//     val io = IO(new Bundle{
//         val request = Flipped(Decoupled(req))   // req aaygi
//         val response = Decoupled(rsp)           // resp jaayga
//     })

//     io.request.ready := true.B

//     // for sending request
//     when(io.request.fire() & io.request.isWrite){                                       // if req is of write
//         val maskedData = io.request.bits.dataRequest.asTypeOf(Vec(4, UInt(8.W)))        // breaking into Vecs to apply masking
//         val data = io.request.bits.activeByteLane zip maskedData map {                  // applying maskiing a/c to mask bits (activeByteLane)
//             case (b:Bool, i:UInt) => Mux(b, i, 0.U)
//         }

//         // feed these pins into the BLACK BOX of SRAM/Peripheral
//         data.asUInt                     // ye data hy 
//         io.request.bits.addrRequest     // ye address hay
//         io.request.bits.isWrite         // ye write enable hy

//     } elsewhen(io.request.fire() & !io.request.isWrite){                                // if req is of read
        
//         io.request.bits.addrRequest     // ye address hy
//         io.request.bits.dataRequest     // ye data hy, but kisi kaam ka nahi
//         io.request.bits.isWrite         // ye write enable h, low hga read k lye

//     } otherwise {
//         // DontCares feed krdena, if needed
//     }

//     // For recieveing response
//     val responseData =                  // yahan data phek do, response se any wala

//     // CAUTION => If data is coming after 1 or more cycles, you have preserve the io.request.bits.activeByteLane pin
//     // until the data comes back as response
//     // If your Module(SRAM/Peripheral) can done masking inside of it then it willbe good. Otherwise PRESERVE IT!
    
//     val maskedData = responseData.asTypeOf(Vec(4, UInt(8.W)))                       // breaking into Vecs to apply masking
//     val data = io.request.bits.activeByteLane zip maskedData map {                  // applying maskiing a/c to mask bits (activeByteLane)
//         case (b:Bool, i:UInt) => Mux(b, i, 0.U)
//     }

//     io.response.bits.dataResponse := data.asUInt        // sending data as response
//     io.response.bits.error := Mux()                     // implement a logic for error here, if the response has error
//     io.response.valid := Mux()                          // implement a logic for indicating that the requested READ/WRITE operation is done and the response signal coming is valud
//                                                         // valid pin shall be high for one cycle ONLY
// }