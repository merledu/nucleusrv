// package components

// import chisel3._
// import chisel3 . util._
// import org.scalatest._
// import chisel3.experimental._
// import chiseltest._
// import chisel3.experimental.BundleLiterals._
// import chiseltest.experimental.TestOptionBuilder._
// import chiseltest.internal.VerilatorBackendAnnotation
// // import org.scalatest.flatspec.AnyFlatSpec



// class SRamTests extends FreeSpec with ChiselScalatestTester {

//   "SRAM" in {
//     test(new SRam()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
//        // c.io.csb0.poke(0.B)
//         //c.io.web0.poke(0.B)
//         //c.io.addr0.poke(3.U)
//         //c.io.din0.poke(2.U)
        
//         // //c.io.clk0.poke(clock.asUInt()(0).asClock())
//         // c.io.csb0.poke(0.B)
//         // c.io.web0.poke(0.B)
//         // c.io.addr0.poke(3.U)
//         // c.io.din0.poke(2.U)

//         // // c.io.rst_n.poke(0.B)
//         // // c.io.data_in.poke(8.U)
//         // // c.io.start.poke(1.B)

//         // // val clk0 = Input(Bool())
//         // // val csb0 = Input(Bool())
//         // // val web0 = Input(Bool())
//         // // val addr0 = Input(UInt(7.W))
//         // // val din0 = Input(UInt(32.W))
//         // // val dout0 = Output(UInt(32.W))
      
//       c.io.csb0.poke(0.B)
//       c.io.web0.poke(1.B)
//       c.io.addr0.poke(3.U)


//         c.clock.step(20)
//     }
//   }
// }
