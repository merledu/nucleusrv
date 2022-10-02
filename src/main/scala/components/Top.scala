package nucleusrv.components
import chisel3._
import rvfi_trace._


class Top(programFile:Option[String], dataFile:Option[String], rvfi:Boolean=false) extends Module{

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
  })


  val core: Core = Module(new Core(M = true, RVFI=rvfi))
  val tracer = if (rvfi) Some(Module(new RVFIUnit(rvfi))) else None
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
    tracer.get.io.mem_reg_ins,

    // Register read/write
    tracer.get.io.id_reg_rd1,
    tracer.get.io.id_reg_rd2,
    tracer.get.io.wb_rd,
    tracer.get.io.rs1_addr,
    tracer.get.io.rs2_addr,
    tracer.get.io.wb_data,
    tracer.get.io.writeEnable,

    // Program Counter
    tracer.get.io.mem_reg_pc,
    tracer.get.io.nextPC,

    // Memory Access
    tracer.get.io.ex_reg_result,
    tracer.get.io.readEnable,
    tracer.get.io.writeEnable,
    tracer.get.io.ex_reg_wd,
    tracer.get.io.readData
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
    x => x._1.get := x._2.get
  } else None
}
