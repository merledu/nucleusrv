package nucleusrv.components
import chisel3._

//import TraceUnit
//import tracer.Params


class Top(programFile:Option[String], dataFile:Option[String], trace:Option[String]) extends Module{

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
  })

  implicit val config:Configs = Configs(XLEN=32, M=false, C=false)

  val core: Core = Module(new Core()(config, TRACE=true))
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

  if (true) {
    val tracer= Module(new TraceUnit(Params.default))

    Seq(
      (tracer.io.rvfiUIntVec, core.io.rvfiUIntVec),
      (tracer.io.rvfiRegAddrVec, core.io.rvfiRegAddrVec),
      (tracer.io.rvfiSIntVec, core.io.rvfiSIntVec),
      (tracer.io.rvfiBoolVec, core.io.rvfiBoolVec)
    ) map (tr => tr._1 <> tr._2.get)

    tracer.io.rvfi_mode := core.io.rvfi_mode.get
  } else None
}
