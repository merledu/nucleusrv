package nucleusrv.components
import chisel3._
import chisel3.util._


class InstructionFetch extends Module {
  val io = IO(new Bundle {
    val address: UInt = Input(UInt(32.W))
    val instruction: UInt = Output(UInt(32.W))
    val stall: Bool = Input(Bool())
    // PC is being redirected this cycle (taken branch / jump resolved in ID)
    val redirect: Bool = Input(Bool())
    // A fetch is outstanding and no usable instruction arrived this cycle: PC must hold
    val waiting: Bool = Output(Bool())
    // A usable instruction is delivered this cycle
    val inst_valid: Bool = Output(Bool())
    val coreInstrReq = Decoupled(new MemRequestIO)
    val coreInstrResp = Flipped(Decoupled(new MemResponseIO))
  })

  val rst = Wire(Bool())
  rst := reset.asBool

  dontTouch(io.stall)
  val init :: valid :: ready :: Nil = Enum(3)
  val state_reg = dontTouch(RegInit(0.U))
  val next_state = dontTouch(MuxCase(state_reg, Vector(
    //((state_reg === 0.U) || ((state_reg === 2.U) && io.coreInstrResp.valid && !io.stall)) -> valid,
    //((state_reg === 1.U) && io.coreInstrReq.ready && !io.stall) -> ready
    ((state_reg === init) && (!io.stall || !rst)) -> valid,
    ((state_reg === valid) && !io.stall && io.coreInstrReq.fire) -> ready,
    ((state_reg === ready) && io.coreInstrResp.fire) -> valid,
    rst -> init
  )))
  state_reg := next_state

  // The response to the outstanding request belongs to a PC that a redirect has
  // since replaced: drop it when it arrives and fetch again from the new PC.
  val kill = RegInit(false.B)
  when(io.coreInstrResp.fire) {
    kill := false.B
  }
  when((state_reg === ready) && io.redirect && !io.coreInstrResp.fire) {
    kill := true.B
  }

  // A killed response is consumed even while stalled; a live one only when the pipeline can take it
  io.coreInstrResp.ready := (state_reg === ready) && (kill || io.redirect || !io.stall)
  val deliver = io.coreInstrResp.fire && !kill && !io.redirect

  io.inst_valid := deliver
  io.waiting := (state_reg === ready) && !deliver

//  io.coreInstrReq.ready := Mux(rst, false.B, true.B)

  io.coreInstrReq.bits.activeByteLane := "b1111".U
  io.coreInstrReq.bits.isWrite := false.B
  io.coreInstrReq.bits.dataRequest := DontCare

  // Unconditional: the SoC derives imem ready from the address, so gating on ready is a combinational loop
  io.coreInstrReq.bits.addrRequest := io.address
  io.coreInstrReq.valid := (state_reg === valid) & !io.stall

  // Bubble (0) whenever no usable instruction is delivered
  io.instruction := Mux(deliver, io.coreInstrResp.bits.dataResponse, 0.U)
}
