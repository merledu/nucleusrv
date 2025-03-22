package nucleusrv.components
import chisel3._
import chisel3.stage.ChiselStage
import nucleusrv.tracer._
import vaquita.configparameter.VaquitaConfig
import chisel3.util._




class Top(programFile:Option[String], dataFile:Option[String]) extends Module{

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
    val fcsr = Output(UInt(32.W))
    

  })

  implicit val config = Configs(XLEN=32, M=true, C=true, TRACE=true)
  implicit val vec_config = VaquitaConfig (256,32,32,8)

  val core: Core = Module(new Core())
  core.io.stall := false.B

  val dmem = Module(new SRamTop(dataFile))
  val imem = Module(new SRamTop(programFile))

  // val vec_dmem = Module(new SRamTop(dataFile))
  /*  Imem Interceonnections  */
    core.io.imemRsp <> imem.io.rsp
  imem.io.req <> core.io.imemReq
// val reg1 = RegNext(RegNext(RegNext(RegNext(core.io.vec_load_store_valid))))
val vec_h1 = RegNext(core.io.vec_load_store_valid)
val vec_h2 = RegNext(vec_h1)
val vec_h3 = RegNext(vec_h2)
val vec_read_h4 = RegNext(vec_h3)



   core.io.dmemRsp.bits.dataResponse := dmem.io.rsp.bits.dataResponse//Mux(reg1,core.io.vec_dmemRsp.bits.dataResponse,core.io.dmemRsp.bits.dataResponse)
  core.io.dmemRsp.valid := 1.B
  core.io.dmemReq.ready := 1.B
  dmem.io.rsp.ready := 1.B
  dmem.io.req.valid := 1.B
  dmem.io.req.bits.dataRequest := Mux(vec_h3===1.B,core.io.vec_dmemReq.bits.dataRequest,core.io.dmemReq.bits.dataRequest)
  dmem.io.req.bits.addrRequest := Mux(vec_h3===1.B,core.io.vec_dmemReq.bits.addrRequest,core.io.dmemReq.bits.addrRequest)
  dmem.io.req.bits.isWrite := Mux(vec_h3===1.B,core.io.vec_dmemReq.bits.isWrite,core.io.dmemReq.bits.isWrite)
  dmem.io.req.bits.activeByteLane := Mux(vec_h3===1.B,core.io.vec_dmemReq.bits.activeByteLane,core.io.dmemReq.bits.activeByteLane)
  


  core.io.vec_dmemRsp.bits.dataResponse := Mux(vec_read_h4,dmem.io.rsp.bits.dataResponse,0.U)
  core.io.vec_dmemRsp.valid := 1.B
  // io.vec_dmemRsp.ready := 1.B
  core.io.vec_dmemReq.ready := 1.B
  // io.vec_dmemReq.valid := 1.B
  // io.vec_dmemReq.bits.dataRequest := 0.U
  // io.vec_dmemReq.bits.addrRequest := 0.U
  // io.vec_dmemReq.bits.isWrite := 1.B
  // io.vec_dmemReq.bits.activeByteLane := "b1111".U
  // }


  //   when(core.io.vec_load_store_valid){
  // core.io.vec_dmemRsp <> io.vec_dmemRsp
  // io.vec_dmemReq <> core.io.vec_dmemReq
  // }.otherwise{
  // core.io.dmemRsp <> dmem.io.rsp
  // dmem.io.req <> core.io.dmemReq
  // }


  println(programFile)




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
}

object NRVDriver {
  // generate verilog
  def main(args: Array[String]): Unit = {
      val IMem =  if (args.length > 0) args(0) else "program.hex"
      new ChiselStage().emitVerilog(new Top(Some(IMem), Some("data.hex")))
  }
}