package nucleusrv.components
import chisel3._
import chisel3.util._ 


class InstructionFetch extends Module {
  val io = IO(new Bundle {
    val address: UInt = Input(UInt(32.W))
    val instruction: UInt = Output(UInt(32.W))
    val stall: Bool = Input(Bool())
    val c_stall = Input(Bool())
    val c_phase = Input(Bool())
    val coreInstrReq = Decoupled(new MemRequestIO)
    val coreInstrResp = Flipped(Decoupled(new MemResponseIO))
    val halt_damn_pc = Output(Bool())
    val phase_valid = Output(Bool())
  })

  

  // when(~(reset.asBool)){
    val rst = Wire(Bool())
    rst := reset.asBool
    io.phase_valid := 0.B

    dontTouch(io.stall)

    val issa_dual = WireInit(0.B)
    val issa_uno = WireInit(0.B)

    dontTouch(issa_dual)
    dontTouch(issa_uno)
    // For a normal aligned instruction
    // Just single req fetch from imem
    when((io.c_phase===0.B && io.address(1)===1.B) || io.address(1)){

      issa_dual := 1.B

      // For mis-alinged, dual req imem fetch
      // since odd no. of C instruction occured
      // b/w 2 individual word instruction
      
      val requester_state_phase = dontTouch(RegInit(0.U(2.W))) // 3 states :: 0 - send first req :: 1 - send second req :: 2 - finished instruction
      val instruction_storage_reg_1 = dontTouch(RegInit(0.U(32.W)))
      val instruction_storage_reg_2 = dontTouch(RegInit(0.U(32.W)))


      io.halt_damn_pc := ~(requester_state_phase === 2.U) 

      val state_reg_dual = dontTouch(RegInit(0.U))
      val c_stall_reg = RegInit(false.B)
      c_stall_reg := io.c_stall

      // when(c_stall_reg && ~requester_state_phase){
      //   requester_state_phase := ~requester_state_phase
      // }

      val next_state = dontTouch(MuxCase(state_reg_dual, Vector(
        ((state_reg_dual === 0.U)) -> 1.U,  // valid
        ((state_reg_dual === 1.U) && io.coreInstrReq.ready && !(io.stall | io.c_stall | c_stall_reg) && (requester_state_phase =/= 2.U) && issa_dual) -> 2.U,  // ready
        ((state_reg_dual === 2.U) && (io.coreInstrResp.valid) && requester_state_phase =/= 2.U && issa_dual) -> 1.U
      )))
      state_reg_dual := next_state
      io.coreInstrResp.ready := state_reg_dual === 2.U

    //  io.coreInstrReq.ready := Mux(rst, false.B, true.B)

      io.coreInstrReq.bits.activeByteLane := "b1111".U
      io.coreInstrReq.bits.isWrite := false.B
      io.coreInstrReq.bits.dataRequest := DontCare

      io.coreInstrReq.bits.addrRequest := Mux(
        io.coreInstrReq.ready,
        // Mux(requester_state_phase, Cat("b00".U, io.address(31, 2)), Cat("b00".U, io.address(31, 2)) - 1.U)
        Mux(
          io.address(1),
          Mux(
            requester_state_phase === 0.U,
            Cat("b00".U, io.address(31, 2)),
            Mux(
              requester_state_phase === 1.U,
              Cat("b00".U, io.address(31, 2)) + 1.U,
              DontCare
            )
          ),
          Mux(
            requester_state_phase === 0.U,
            Cat("b00".U, io.address(31, 2)) - 1.U,
            Mux(
              requester_state_phase === 1.U,
              Cat("b00".U, io.address(31, 2)),
              DontCare
            )
          )
        ),
        DontCare
      )
      io.coreInstrReq.valid := (state_reg_dual === 1.U) & !(io.stall | io.c_stall | c_stall_reg)  & ~(requester_state_phase === 2.U)

      // io.instruction := Mux(
      //   io.coreInstrResp.valid,
      //   io.coreInstrResp.bits.dataResponse,
      //   DontCare
      // )

      io.instruction := Mux(
        issa_dual && requester_state_phase === 2.U,
        Cat(instruction_storage_reg_2(15,0), instruction_storage_reg_1(31,16)),
        "h00000013".U // nop
      )

      when(requester_state_phase === 2.U && issa_dual){
        requester_state_phase := 0.U
        io.phase_valid := 1.B
      }

        when(io.coreInstrResp.valid && issa_dual ){
          when(requester_state_phase === 0.U){
            instruction_storage_reg_1 := io.coreInstrResp.bits.dataResponse
            requester_state_phase := 1.U
          }.elsewhen(requester_state_phase === 1.U){
            instruction_storage_reg_2 := io.coreInstrResp.bits.dataResponse
            requester_state_phase := 2.U
          }
          // requester_state_phase := ~requester_state_phase
          // instruction_storage_reg := io.coreInstrResp.bits.dataResponse
        }

        // requester_state_phase := Mux(io.coreInstrReq.valid, ~requester_state_phase, requester_state_phase)
      
    }
    // {

    //   issa_uno := 1.B
    //   val requester_state_phase_uno = dontTouch(RegInit(0.U(2.W))) // 3 states :: 0 - send req :: 1 - get rsp :: 2 - finished instruction
    //   val instruction_storage_reg_0 = dontTouch(RegInit(0.U(32.W)))
    //   // val instruction_storage_reg_2 = dontTouch(RegInit(0.U(32.W)))


    //   io.halt_damn_pc := ~(requester_state_phase_uno === 2.U) 

    //   val state_reg_uno = dontTouch(RegInit(0.U))
    //   val c_stall_reg = RegInit(false.B)
    //   c_stall_reg := io.c_stall

    //   // when(c_stall_reg && ~requester_state_phase){
    //   //   requester_state_phase := ~requester_state_phase
    //   // }

    //   val next_state = dontTouch(MuxCase(state_reg_uno, Vector(
    //     ((state_reg_uno === 0.U) || ((state_reg_uno === 2.U) && (io.coreInstrResp.valid) && (io.c_phase || ~io.address(1)))) -> 1.U,  // valid
    //     ((state_reg_uno === 1.U) && io.coreInstrReq.ready && !(io.stall | io.c_stall | c_stall_reg) && (requester_state_phase_uno =/= 2.U) && (io.c_phase || ~io.address(1))) -> 2.U  // ready
    //   )))
    //   state_reg_uno := next_state
    //   io.coreInstrResp.ready := state_reg_uno === 2.U

    // //  io.coreInstrReq.ready := Mux(rst, false.B, true.B)

    //   io.coreInstrReq.bits.activeByteLane := "b1111".U
    //   io.coreInstrReq.bits.isWrite := false.B
    //   io.coreInstrReq.bits.dataRequest := DontCare

    //   io.coreInstrReq.bits.addrRequest := Mux(
    //     io.coreInstrReq.ready,
    //     Mux(
    //       io.address(1),
    //       Cat("b00".U, io.address(31, 2)) + 1.U,
    //       Cat("b00".U, io.address(31, 2))
    //     ),
    //     // Mux(requester_state_phase, Cat("b00".U, io.address(31, 2)), Cat("b00".U, io.address(31, 2)) - 1.U)
    //     // Mux(
    //     //   io.address(1),
    //     //   Mux(
    //     //     requester_state_phase_uno === 0.U,
    //     //     Cat("b00".U, io.address(31, 2)),
    //     //     Mux(
    //     //       requester_state_phase_uno === 1.U,
    //     //       Cat("b00".U, io.address(31, 2)) + 1.U,
    //     //       DontCare
    //     //     )
    //     //   ),
    //     //   Mux(
    //     //     requester_state_phase_uno === 0.U,
    //     //     Cat("b00".U, io.address(31, 2)) - 1.U,
    //     //     Mux(
    //     //       requester_state_phase_uno === 1.U,
    //     //       Cat("b00".U, io.address(31, 2)),
    //     //       DontCare
    //     //     )
    //     //   )
    //     // ),
    //     DontCare
    //   )
      
    //   io.coreInstrReq.valid := (state_reg_uno === 1.U) & !(io.stall | io.c_stall | c_stall_reg)  & (requester_state_phase_uno === 0.U)

    //   // io.instruction := Mux(
    //   //   io.coreInstrResp.valid,
    //   //   io.coreInstrResp.bits.dataResponse,
    //   //   DontCare
    //   // )

    //   io.instruction := Mux(
    //     (io.c_phase || ~io.address(1)) && requester_state_phase_uno === 2.U,
    //     instruction_storage_reg_0,//Cat(instruction_storage_reg_2(15,0), instruction_storage_reg_1(31,16)),
    //     "h00000013".U // nop
    //   )

    //   when(requester_state_phase_uno === 0.U){
    //     requester_state_phase_uno := 1.U
    //   }

    //   when(requester_state_phase_uno === 2.U){
    //     requester_state_phase_uno := 0.U
    //     io.phase_valid := 1.B
    //   }

    //     when(io.coreInstrResp.valid && (io.c_phase || ~io.address(1)) && requester_state_phase_uno === 1.U ){
    //       instruction_storage_reg_0 := io.coreInstrResp.bits.dataResponse
    //       requester_state_phase_uno := 2.U
    //       // when(requester_state_phase === 0.U){
    //       //   instruction_storage_reg_1 := io.coreInstrResp.bits.dataResponse
    //       //   requester_state_phase := 1.U
    //       // }.elsewhen(requester_state_phase === 1.U){
    //       //   instruction_storage_reg_2 := io.coreInstrResp.bits.dataResponse
    //       //   requester_state_phase := 2.U
    //       // }
    //       // requester_state_phase := ~requester_state_phase
    //       // instruction_storage_reg := io.coreInstrResp.bits.dataResponse
    //     }

    //     // requester_state_phase := Mux(io.coreInstrReq.valid, ~requester_state_phase, requester_state_phase)
    // }
  // }

  // .otherwise{
  //   io.halt_damn_pc := 0.B
  //   io.phase_valid := 0.B
  //   io.coreInstrReq.valid := 0.B
  //   io.coreInstrReq.bits.addrRequest := 0.U
  //   io.coreInstrReq.bits.activeByteLane := 0.U
  //   io.coreInstrReq.bits.isWrite := 0.B
  //   io.coreInstrReq.bits.dataRequest := 0.U
  //   io.coreInstrResp.ready := 0.B
  //   io.instruction := "h00000013".U
  // }


  .otherwise{
    issa_uno := 1.B
    val state_reg = dontTouch(RegInit(0.U))
    val c_stall_reg = RegInit(false.B)
    c_stall_reg := io.c_stall

    val instruction_storage_reg_0 = RegInit(0.U(32.W))

    val next_state = dontTouch(MuxCase(state_reg, Vector(
      ((state_reg === 0.U)) -> 1.U,  // valid
      ((state_reg === 1.U) && io.coreInstrReq.ready && !(io.stall | io.c_stall) && issa_uno) -> 2.U,  // ready
      ((state_reg === 2.U) && io.coreInstrResp.valid && issa_uno) -> 3.U, // finish instr
      ((state_reg === 3.U) && issa_uno) -> 1.U
    )))
    state_reg := next_state
    io.coreInstrResp.ready := state_reg === 2.U
    io.halt_damn_pc := (state_reg === 1.U) || (state_reg === 2.U) // 0.B


  //  io.coreInstrReq.ready := Mux(rst, false.B, true.B)

    io.coreInstrReq.bits.activeByteLane := "b1111".U
    io.coreInstrReq.bits.isWrite := false.B
    io.coreInstrReq.bits.dataRequest := DontCare

    io.coreInstrReq.bits.addrRequest := Mux(
      io.coreInstrReq.ready,
      Mux(
        io.address(1),
        Cat("b00".U, io.address(31, 2)) + 1.U,
        Cat("b00".U, io.address(31, 2))
      ),
      DontCare
    )
    io.coreInstrReq.valid := (state_reg === 1.U) & !(io.stall | io.c_stall)

    when((state_reg === 2.U) && io.coreInstrResp.valid && (io.c_phase || ~io.address(1))){
      instruction_storage_reg_0 := io.coreInstrResp.bits.dataResponse
    }

    io.instruction := Mux(
      // io.coreInstrResp.valid,
      // io.coreInstrResp.bits.dataResponse,
      // DontCare
      state_reg === 3.U,
      instruction_storage_reg_0,
      "h00000013".U
    )

    io.phase_valid := (state_reg === 3.U)
  }
  
  
  // {
  //   io.halt_damn_pc := 0.B
  //   val state_reg = dontTouch(RegInit(0.U))
  //   val c_stall_reg = RegInit(false.B)
  //   c_stall_reg := io.c_stall

  //   val next_state = dontTouch(MuxCase(state_reg, Vector(
  //     ((state_reg === 0.U) || ((state_reg === 2.U) && io.coreInstrResp.valid) && (io.c_phase || ~io.address(1))) -> 1.U,  // valid
  //     ((state_reg === 1.U) && io.coreInstrReq.ready && !(io.stall | io.c_stall) && (io.c_phase || ~io.address(1))) -> 2.U  // ready
  //   )))
  //   state_reg := next_state
  //   io.coreInstrResp.ready := state_reg === 2.U

  // //  io.coreInstrReq.ready := Mux(rst, false.B, true.B)

  //   io.coreInstrReq.bits.activeByteLane := "b1111".U
  //   io.coreInstrReq.bits.isWrite := false.B
  //   io.coreInstrReq.bits.dataRequest := DontCare

  //   io.coreInstrReq.bits.addrRequest := Mux(
  //     io.coreInstrReq.ready,
  //     Mux(
  //       io.address(1),
  //       Cat("b00".U, io.address(31, 2)) + 1.U,
  //       Cat("b00".U, io.address(31, 2))
  //     ),
  //     DontCare
  //   )
  //   io.coreInstrReq.valid := (state_reg === 1.U) & !(io.stall | io.c_stall)

  //   io.instruction := Mux(
  //     io.coreInstrResp.valid,
  //     io.coreInstrResp.bits.dataResponse,
  //     DontCare
  //   )
  // }
}
