// package nucleusrv.components.vu

// import chisel3._ 
// import chisel3.util._ 

// class VMemAddrIO extends Bundle with Config {
//     // val UnitStride = Input(UInt(2.W)) //0 = unit stride store h
//     val evl = Input(UInt(8.W))
//     val emul = Input(UInt(4.W))
//     val vs3_data = Input(SInt(128.W))
//     val addr_in = Input (UInt(32.W))
//     val vl = Input(SInt(32.W))
//     val lsuType = Input(UInt(2.W))
//     val eew = Input(UInt(3.W))
//     val v_wData = Output(SInt(32.W))
//     val v_waddr = Output(UInt(32.W))
// }

// class VmemAddr extends Module {
//     val io = IO(new VMemAddrIO)

// // val eew_8_vs3_data = VecInit((0 until 16).map(i => io.vs3_data(8*i+7, 8*i).asSInt))
// // val eew_16_vs3_data = VecInit((0 until 8).map(i => io.vs3_data(16*i+15, 16*i).asSInt))
// val eew_32_vs3_data = VecInit((0 until 4).map(i => io.vs3_data(32*i+31, 32*i).asSInt))
// // val eew_64_vs3_data = VecInit((0 until 2).map(i => io.vs3_data(64*i+63, 64*i).asSInt))

// var count = 0.U
// var count64 = 0
// var addrcount = 0.U
// var elemntcount = RegInit(0.U(3.W))
// val data = WireInit(0.S(32.W))
//   when(io.lsuType === 0.U && count =/= 4.U) {
//     data := eew_32_vs3_data(count)
//     count = count + 1.U
//     addrcount = addrcount + 4.U
//     io.v_waddr := io.addr_in + addrcount
//   }.otherwise {
//     data := 0.S
//     count = 0.U
//     io.v_waddr := 0.U
//   }

//   io.v_wData := data
// }
//        // when (io.eew === 8.U ){

//         //     val data = Cat (eew_8_vs3_data(0 + count) , eew_8_vs3_data(1+count) , eew_8_vs3_data(2 + count), eew_8_vs3_data(3+count))
//         //     count = count + 4
//         //     io.v_wData := data.asSInt
//         // }.elsewhen (io.eew === 16.U ){
//         //     val data = Cat (eew_16_vs3_data(0 + count) , eew_16_vs3_data(1+count) )
//         //     count = count + 2
//         //     io.v_wData := data.asSInt
//         // }.elsewhen(io.eew === 32.U){
//         //     val data = eew_32_vs3_data(count)
//         //     count = count + 1
//         //     io.v_wData := data.asSInt
//         // }.elsewhen(io.eew === 64.U){
//         //     when(count64.asUInt =/= 32.U ){
//         //         val data = (eew_64_vs3_data(count))(count64,count64+31)
//         //         count64 = count64 + 32
//         //         count = count+ 0
//         //         io.v_wData := data.asSInt
//         //     }.otherwise{
//         //         val data = eew_64_vs3_data(count)(count64+31,count64)
                
//         //         count64 = 0
//         //         count = count + 1
//         //         io.v_wData := data.asSInt
//         //     }
//         // }