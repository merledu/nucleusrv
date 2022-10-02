package nucleusrv.components
import chisel3._
import rvfi_trace._


class Top(programFile:Option[String], dataFile:Option[String], rvfi:Boolean=false) extends Module{

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
  })


  val core: Core = Module(new Core(M = true))
  val tracer = if (rvfi) Module(new RVFIUnit(rvfi)) else None
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

  /*  RVFI Tracer Interconnections  */
  if (rvfi) Seq(
    // Instruction metadata
    tracer.io.mem_reg_ins,

    // Register read/write
    tracer.io.id_reg_rd1,
    tracer.io.id_reg_rd2,
    tracer.io.wb_rd,
    tracer.io.rs1_addr,
    tracer.io.rs2_addr,
    tracer.io.wb_data,
    tracer.io.writeEnable,

    // Program Counter
    tracer.io.mem_reg_pc,
    tracer.io.nextPC,

    // Memory Access
    tracer.io.ex_reg_result,
    tracer.io.readEnable,
    tracer.io.writeEnable,
    tracer.io.ex_reg_wd,
    tracer.io.readData
  ) zip Seq(
    // Instruction metadata
    core.io.ins,

    // Register read/write
    core.io.rd1,
    core.io.rd2,
    core.io.rdAddr,
    core.io.rs1Addr,
    core.io.rs2Addr,
    core.io.rdData,
    core.io.mem_reg_ctl_regWrite,

    // Program Counter
    core.io.pc,
    core.io.npc,

    // Memory Access
    core.io.memAddr,
    core.io.rEnable,
    core.io.wEnable,
    core.io.memWdata,
    core.io.memRdata
  ) foreach {
    x => x._1 := x._2
  } else None
}
