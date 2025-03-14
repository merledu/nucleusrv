package nucleusrv.components
import chisel3._
import chisel3.util._ 


class InstructionFetch extends Module {
  val io = IO(new Bundle {
    val address: UInt = Input(UInt(32.W))
    val instruction: UInt = Output(UInt(32.W))
    val stall: Bool = Input(Bool())
    val coreInstrReq = Decoupled(new MemRequestIO)
    val coreInstrResp = Flipped(Decoupled(new MemResponseIO))
  })

  val rst = Wire(Bool())
  rst := reset.asBool

  val valid_reg = dontTouch(RegInit(0.B))
  val ready = RegInit(0.B)

  valid_reg := !(rst || io.stall) && !valid_reg
  io.coreInstrReq.valid := valid_reg

  Vector(
    (io.coreInstrReq.bits.activeByteLane, "b1111".U),
    (io.coreInstrReq.bits.isWrite, false.B),
    (io.coreInstrReq.bits.addrRequest, io.address >> 2)
  ) foreach(
    i => i._1 := Mux(
      dontTouch(io.coreInstrReq.ready) && valid_reg,
      i._2, DontCare
    )
  )
  io.coreInstrReq.bits.dataRequest := DontCare

  ready := valid_reg
  io.coreInstrResp.ready := ready
  io.instruction := Mux(io.coreInstrResp.valid && ready, io.coreInstrResp.bits.dataResponse, DontCare)
}
