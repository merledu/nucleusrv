package nucleusrv.components
import chisel3._
import chisel3.stage.ChiselStage
import nucleusrv.tracer._
import vaquita.configparameter.VaquitaConfig
import chisel3.util._




class Top(programFile:Option[String], dataFile:Option[String]) extends Module{

  val io = IO(new Bundle() {
    // val pin = Output(UInt(32.W))
    // val fcsr = Output(UInt(32.W))
    val led1 = Output(UInt(1.W)) 
    val led2 = Output(UInt(1.W))  
    val led3 = Output(UInt(1.W)) 
  })

  implicit val config = Configs(XLEN=32, M=true, C=true, TRACE=true)
  implicit val vec_config = VaquitaConfig (256,32,32,8)
  // implicit val config = new Configs {}
  // implicit val vec_config = new VaquitaConfig {}

  val core: Core = Module(new Core())
  core.io.stall := false.B

  val dmem = Module(new SRamTop(dataFile))
  val imem = Module(new SRamTop(programFile))

  // io.led := RegInit(0.U(1.W))
  // val detect_fpga_vec32 = VecInit(Seq.fill(32)(VecInit(Seq.fill(vec_config.count_lanes)(0.S(32.W)))))
  // detect_fpga_vec32 <> core.io.vec_top_data_out
  // val check = core.io.vec_top_data_out(0)(0).asUInt === ("b1".U) && core.io.vec_top_data_out(0)(1).asUInt === ("b10".U)
  // when(check===1.B){
  //   io.led1 := 1.U
  // }.otherwise{
    io.led1 := 0.U
  // }
  //   val check2 = core.io.vec_top_data_out(2)(0).asUInt === ("h0".U) && core.io.vec_top_data_out(2)(1).asUInt === ("h0".U)
  // when(check2===1.B){
  //   io.led2 := 1.U
  // }.otherwise{
    io.led2 := 0.U
  // }
  // val check3 = core.io.vec_top_data_out(3)(0).asUInt === ("hb".U) && core.io.vec_top_data_out(3)(1).asUInt === ("hc".U)
  // when(check3===1.B){
  //   io.led3 := 1.U
  // }.otherwise{
    io.led3 := 0.U
  // }




  // when(core.io.vec_top_data_out(29)(0) === ("b00101".U).asSInt){
  //   io.led3 := 1.U
  // }.otherwise{
  //   io.led3 := 0.U
  // }

  // dontTouch(detect_fpga_vec32)
  // val vec_dmem = Module(new SRamTop(dataFile))
  /*  Imem Interceonnections  */
    core.io.imemRsp <> imem.io.rsp
  imem.io.req <> core.io.imemReq
// val reg1 = RegNext(RegNext(RegNext(RegNext(core.io.vec_load_store_valid))))
// val vec_h1 = RegNext(core.io.vec_load_store_valid)
// val vec_h2 = RegNext(vec_h1)
// val vec_h3 = RegNext(vec_h2)
// val vec_read_h4 = RegNext(vec_h3)

// use this signals for fpga connection
  // val detect_fpga_core = WireInit(0.U(32.W))

  // val detect_fpga_vec = VecInit(Seq.fill(8)(VecInit(Seq.fill(vec_config.count_lanes)(0.S(32.W)))))
  // detect_fpga_vec <> core.io.vec_data_out_fpga_core
  // dontTouch(detect_fpga_vec)


   core.io.dmemRsp.bits.dataResponse := dmem.io.rsp.bits.dataResponse//Mux(reg1,core.io.vec_dmemRsp.bits.dataResponse,core.io.dmemRsp.bits.dataResponse)
  core.io.dmemRsp.valid := 1.B
  core.io.dmemReq.ready := 1.B
  dmem.io.rsp.ready := 1.B
  dmem.io.req.valid := 1.B
  dmem.io.req.bits.dataRequest := Mux(core.io.vec_load_store_valid,core.io.vec_dmemReq.bits.dataRequest,core.io.dmemReq.bits.dataRequest)
  dmem.io.req.bits.addrRequest := Mux(core.io.vec_load_store_valid===1.B,core.io.vec_dmemReq.bits.addrRequest,core.io.dmemReq.bits.addrRequest)
  dmem.io.req.bits.isWrite := Mux(core.io.vec_load_store_valid===1.B,core.io.vec_dmemReq.bits.isWrite,core.io.dmemReq.bits.isWrite)
  dmem.io.req.bits.activeByteLane := Mux(core.io.vec_load_store_valid===1.B,core.io.vec_dmemReq.bits.activeByteLane,core.io.dmemReq.bits.activeByteLane)
  


  core.io.vec_dmemRsp.bits.dataResponse := dmem.io.rsp.bits.dataResponse //Mux(core.io.vec_load_store_valid,dmem.io.rsp.bits.dataResponse,0.U)
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



  val pin = WireInit(0.U(32.W))
  pin := core.io.pin
  // fcsr := core.io.fcsr_o_data
  dontTouch(pin)

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

// `timescale 1ns / 1ps
// //////////////////////////////////////////////////////////////////////////////////
// // Company: 
// // Engineer: 
// // 
// // Create Date: 06.01.2025 17:57:50
// // Design Name: 
// // Module Name: v_vaquita128
// // Project Name: 
// // Target Devices: 
// // Tool Versions: 
// // Description: 
// // 
// // Dependencies: 
// // 
// // Revision:
// // Revision 0.01 - File Created
// // Additional Comments:
// // 
// //////////////////////////////////////////////////////////////////////////////////
// `include "sram_top.vh"
// `include "sram.vh" 


  // wire  pll_clk_in1; // @[Generator.scala 28:21]
  // wire  pll_clk_out1; // @[Generator.scala 28:21]
  // wire  gen_clock; // @[Generator.scala 27:21]
  // PLL_8MHz pll ( // @[Generator.scala 28:21]
  //   .clk_in1(pll_clk_in1),
  //   .clk_out1(pll_clk_out1)
  // );
  // assign gen_clock = pll_clk_out1;
  // assign pll_clk_in1 = clock; // @[Generator.scala 30:20]
  // assign core_clock = gen_clock;
  // also add gen clock in imem dmem and tracer