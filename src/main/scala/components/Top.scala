package nucleusrv.components
import chisel3._
import chisel3.stage.ChiselStage
import nucleusrv.tracer._


class Top(programFile:Option[String], dataFile:Option[String], dataFile1:Option[String]) extends Module{

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
    val rvfi = new TracerO
  })

  implicit val config:Configs = Configs()

  val core: Core = Module(new Core())
  core.io.stall := false.B

  val dmem = Module(new SRamTop(programFile = dataFile, programFile1 = dataFile1, XLEN = config.XLEN))
  val imem = Module(new SRamTop(programFile = programFile, programFile1 = None, XLEN = 32))

  /*  Imem Interceonnections  */
  core.io.imemRsp <> imem.io.rsp
  imem.io.req <> core.io.imemReq


  /*  Dmem Interconnections  */
  core.io.dmemRsp <> dmem.io.rsp
  dmem.io.req <> core.io.dmemReq

  io.pin := core.io.pin

  if (config.TRACE) {
    val tracer = Module(new Tracer)
    tracer.rvfi_i <> core.io.rvfi.get
    io.rvfi <> tracer.rvfi_o
  }
}

object NRVDriver {
  // generate verilog
  def main(args: Array[String]): Unit = {
      val IMem = if (args.contains("--imem")) Some(args(args.indexOf("--imem") + 1)) else None
      val DMem = if (args.contains("--dmem")) Some(args(args.indexOf("--dmem") + 1)) else None
      val DMem1 = if (args.contains("--dmem1")) Some(args(args.indexOf("--dmem1") + 1)) else None
      new ChiselStage().emitVerilog(
        new Top(IMem, DMem, DMem1),
        if (args.contains("--target-dir")) args.slice(
          args.indexOf("--target-dir"),
          args.indexOf("--target-dir") + 2
        ) else Array()
      )
  }
}
