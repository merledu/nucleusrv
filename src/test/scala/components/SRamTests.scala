package nucleusrv.components

import chisel3._
import chisel3.util._
import org.scalatest._
import chiseltest._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class CacheSRAMTests extends FreeSpec with ChiselScalatestTester {
    "New SRAM Test" in {
        test(new new_SRamTop(None)).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
            // Write data to a specific address
            c.io.req.valid.poke(true.B)
            c.io.req.bits.isWrite.poke(true.B)           // Write operation
            c.io.req.bits.addrRequest.poke(100.U)        // Address to write
            c.io.req.bits.dataRequest.poke(42.U)         // Data to write
            c.io.req.bits.activeByteLane.poke("b1111".U) // Enable all bytes
            c.clock.step(10)                             // Allow time for write to complete

            // Read data back from the same address
            c.io.req.bits.isWrite.poke(false.B)          // Read operation
            c.io.req.bits.addrRequest.poke(100.U)        // Address to read
            c.clock.step(10)                             // Allow time for read
            c.io.rsp.bits.dataResponse.expect(42.U)      // Verify the data

            // Test another address
            c.io.req.bits.addrRequest.poke(5000000.U)    // Address to write (large address within range)
            c.io.req.bits.dataRequest.poke(123.U)        // Data to write
            c.io.req.bits.isWrite.poke(true.B)           // Write operation
            c.clock.step(10)                             // Allow time for write

            c.io.req.bits.isWrite.poke(false.B)          // Read operation
            c.io.req.bits.addrRequest.poke(5000000.U)    // Address to read
            c.clock.step(10)                             // Allow time for read
            c.io.rsp.bits.dataResponse.expect(123.U)     // Verify the data
        }
    }
}






//     "Instruction Cache SRAM Test" in {
//         test(new Instruction_SRamTop(None)).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
//             // Write instruction to cache
//             c.io.req.valid.poke(true.B)
//             c.io.req.bits.isWrite.poke(true.B)           // Write operation
//             c.io.req.bits.addrRequest.poke(100.U)        // Instruction address
//             c.io.req.bits.dataRequest.poke(123.U)        // Instruction data
//             c.io.req.bits.activeByteLane.poke("b1111".U) // Enable all bytes
//             c.clock.step(15)

//             // Read instruction back
//             c.io.req.bits.isWrite.poke(false.B)          // Read operation
//             c.io.req.bits.addrRequest.poke(100.U)        // Instruction address
//             c.clock.step(15)
//             c.io.rsp.bits.dataResponse.expect(123.U)     // Verify data
            
//             // Test another address
//             c.io.req.bits.addrRequest.poke(200.U)
//             c.io.req.bits.dataRequest.poke(456.U)
//             c.io.req.bits.isWrite.poke(true.B)
//             c.clock.step(15)

//             c.io.req.bits.isWrite.poke(false.B)
//             c.io.req.bits.addrRequest.poke(200.U)
//             c.clock.step(15)
//             c.io.rsp.bits.dataResponse.expect(456.U)
//         }
//     }
// }







    // "Data Cache SRAM Test" in {
    // test(new Data_SRamTop(None)).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
    //     // // Write to the memory
    //     // c.io.req.valid.poke(true.B)
    //     // c.io.req.bits.isWrite.poke(true.B)      // Indicate a write operation
    //     // c.io.req.bits.addrRequest.poke(5.U)    // Address to write
    //     // c.io.req.bits.dataRequest.poke(84.U)   // Data to write
    //     // c.io.req.bits.activeByteLane.poke("b1111".U) // Enable all bytes
    //     // c.clock.step(15)

    //     // // Read from the memory
    //     // c.io.req.valid.poke(true.B)
    //     // c.io.req.bits.isWrite.poke(false.B)    // Indicate a read operation
    //     // c.io.req.bits.addrRequest.poke(5.U)    // Address to read
    //     // c.clock.step(15)

    //     // c.io.rsp.bits.dataResponse.expect(84.U) // Verify the read data



    //    // Write to the memory
    //     c.io.req.valid.poke(true.B)
    //     c.io.req.bits.isWrite.poke(true.B)
    //     c.io.req.bits.addrRequest.poke(100.U)
    //     c.io.req.bits.dataRequest.poke(42.U)
    //     c.io.req.bits.activeByteLane.poke("b1111".U)
    //     c.clock.step(15) // Allow enough time for the write to complete

    //     // Write to another address
    //     c.io.req.bits.addrRequest.poke(200.U)
    //     c.io.req.bits.dataRequest.poke(84.U)
    //     c.clock.step(15)

    //     // Read back the first address
    //     c.io.req.valid.poke(true.B)
    //     c.io.req.bits.isWrite.poke(false.B)
    //     c.io.req.bits.addrRequest.poke(100.U)
    //     c.clock.step(15) // Allow enough time for the read
    //     c.io.rsp.bits.dataResponse.expect(42.U)

    //     // Read back the second address
    //     c.io.req.bits.addrRequest.poke(200.U)
    //     c.clock.step(15)
    //     c.io.rsp.bits.dataResponse.expect(84.U)
//     }
// }
// }


















