// package nucleusrv.components
// import chisel3._
// import chisel3.stage.ChiselStage
// import nucleusrv.tracer._


// class Top(programFile:Option[String], dataFile:Option[String]) extends Module{

//   val io = IO(new Bundle() {
//     val pin = Output(UInt(32.W))
//     val fcsr = Output(UInt(32.W))
//   })

//   implicit val config:Configs = Configs(XLEN=32, M=true, C=true, TRACE=true)

//   val core: Core = Module(new Core())
//   core.io.stall := false.B

//   val dmem = Module(new SRamTop(dataFile, dataFile))    // do for 64 bit
//   val imem = Module(new SRamTop(programFile, programFile))  // do for 64 bit

//   /*  Imem Interceonnections  */
//   core.io.imemRsp <> imem.io.rsp
//   imem.io.req <> core.io.imemReq

//   println(programFile)
//   /*  Dmem Interconnections  */
//   core.io.dmemRsp <> dmem.io.rsp
//   dmem.io.req <> core.io.dmemReq

//   io.pin := core.io.pin
//   io.fcsr := core.io.fcsr_o_data

//   if (config.TRACE) {
//     val tracer = Module(new Tracer())

//     Seq(
//       (tracer.io.rvfiUInt, core.io.rvfiUInt.get),
//       (tracer.io.rvfiSInt, core.io.rvfiSInt.get),
//       (tracer.io.rvfiBool, core.io.rvfiBool.get),
//       (tracer.io.rvfiRegAddr, core.io.rvfiRegAddr.get)
//     ).map(
//       tr => tr._1 <> tr._2
//     )
//     tracer.io.rvfiMode := core.io.rvfiMode.get
//   }
// }

// object NRVDriver {
//   // generate verilog
//   def main(args: Array[String]): Unit = {
//       val IMem =  if (args.length > 0) args(0) else "program.hex"
//       new ChiselStage().emitVerilog(new Top(Some(IMem), Some("data.hex")))
//   }
// }