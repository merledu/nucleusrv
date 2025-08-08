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

  dontTouch(io.stall)
  val state_reg = dontTouch(RegInit(0.U))
  val next_state = dontTouch(MuxCase(state_reg, Vector(
    ((state_reg === 0.U) || ((state_reg === 2.U) && io.coreInstrResp.valid)) -> 1.U,  // valid
    ((state_reg === 1.U) && io.coreInstrReq.ready && !io.stall) -> 2.U  // ready
  )))
  state_reg := next_state
  io.coreInstrResp.ready := state_reg === 2.U

//  io.coreInstrReq.ready := Mux(rst, false.B, true.B)

  io.coreInstrReq.bits.activeByteLane := "b1111".U
  io.coreInstrReq.bits.isWrite := false.B
  io.coreInstrReq.bits.dataRequest := DontCare

  io.coreInstrReq.bits.addrRequest := Mux(
    io.coreInstrReq.ready,
    Cat("b00".U, io.address(31, 2)),
    DontCare
  )
  io.coreInstrReq.valid := (state_reg === 1.U) & !io.stall

  io.instruction := Mux(
    io.coreInstrResp.valid,
    io.coreInstrResp.bits.dataResponse,
    DontCare
  )
}
