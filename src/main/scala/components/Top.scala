package nucleusrv.components
import chisel3._
import nucleusrv.tracer._
import chisel3.stage.ChiselStage


class Top(programFile:Option[String], dataFile:Option[String]) extends Module{

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
    val v_pin = Output(UInt(128.W))
    val fcsr = Output(UInt(32.W))
  })

  implicit val config:Configs = Configs(XLEN=32, M=true, C=true, TRACE=true, V=true)

  val core: Core = Module(new Core())
  // dontTouch(core.io)
  core.io.stall := false.B

  val dmem = Module(new SRamTop(dataFile))
  val imem = Module(new SRamTop(programFile))

  /*  Imem Interceonnections  */
  core.io.imemRsp <> imem.io.rsp
  imem.io.req <> core.io.imemReq


  /*  Dmem Interconnections  */
  core.io.dmemRsp <> dmem.io.rsp
  dmem.io.req <> core.io.dmemReq

  io.pin := core.io.pin
  io.fcsr := core.io.fcsr_o_data

  if (config.TRACE) {
    val tracer = Module(new Tracer())

    Seq(
      (tracer.io.rvfiUInt, core.io.rvfiUInt.get),
      (tracer.io.rvfiSInt, core.io.rvfiSInt.get),
      (tracer.io.rvfiBool, core.io.rvfiBool.get),
      (tracer.io.rvfiRegAddr, core.io.rvfiRegAddr.get)
    ).map(
      tr => tr._1 <> tr._2
    )
    tracer.io.rvfiMode := core.io.rvfiMode.get
  }
  io.v_pin := core.io.Vpin
}

// object Top extends App{
//   // generate verilog
//   new ChiselStage().emitVerilog(new Top(Some("program.hex"), Some("data.hex")))
//   //chisel3.Driver.execute(args, () => new Top(Some("program.hex"), Some("data.hex")))
// }