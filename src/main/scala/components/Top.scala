package nucleusrv.components
import chisel3._
import chisel3.stage.ChiselStage
import nucleusrv.tracer._
import BabyKyber.BabyKyberTop


class Top(programFile:Option[String], dataFile:Option[String]) extends Module{
  val babyKyber = Module(new BabyKyberTop())
  

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
    val rvfi = new TracerO
  })

  implicit val config:Configs = Configs(
    XLEN = 32,
    M = true,
    F = true,
    C = false,
    Zicsr = true,
    TRACE = true
  )


  val core: Core = Module(new Core())
  core.io.stall := false.B


  // Enable is always on, triggers are from core
  babyKyber.io.enable := true.B
  babyKyber.io.key_enable := core.io.key_enable_trigger
  babyKyber.io.encryption_enable := core.io.encryption_enable_trigger
  babyKyber.io.decryption_enable := core.io.decryption_enable_trigger

  // Optionally, connect or monitor done signals
  // val keyDone = babyKyber.io.key_done
  // val encryptionDone = babyKyber.io.encryption_done
  // val decryptionDone = babyKyber.io.decryption_done

  // Connect BabyKyberTop to core.io.baby_kyber if present
  core.io.baby_kyber match {
    case Some(bkIO) =>
      babyKyber.io.req <> bkIO.req
      babyKyber.io.rsp <> bkIO.rsp
    case None => // Not enabled
  }

  
  

  val dmem = Module(new SRamTop(dataFile))
  val imem = Module(new SRamTop(programFile))

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
      new ChiselStage().emitVerilog(
        new Top(IMem, DMem),
        if (args.contains("--target-dir")) args.slice(
          args.indexOf("--target-dir"),
          args.indexOf("--target-dir") + 2
        ) else Array()
      )
  }
}
