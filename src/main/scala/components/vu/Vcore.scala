// // package nucleusrv.components.vu

// // import chisel3._
// // import chisel3.util._

// // class Top extends Module{
// //     val io=IO(new Bundle{ 
// //         val out = Output(UInt(32.W))
// //          val addr = Output ( UInt ( 10 . W ) )

//     //val inst = Output ( UInt ( 32 . W ) )
//     // })
// // var temp = 0.U
// // val PCMod = Module(new nucleusrv.components.PC)
// // val ALUMod = Module(new ALU_)
// // val ALUcMod = Module (new Alu_Control)
// // // val BrcntrlMod = Module (new BranchControl_)
// // val CntrlDecMod = Module (new controldec)
// // // val datamemMod = Module (new datamem)
// // val ImmgenMod = Module(new ImmdValGen1)
// // val instmemMod = Module(new InstructionFetch)
// // // val jalrCompMod = Module (new jalr)
// // val regfileMod = Module (new nucleusrv.components.Registers())
// // val config= Module(new configure)
// // val vreg = Module (new vregfile)
// // val V_csr = Module(new v_csr)
// // val ID = Module(new InstructionDecode(TRACE))

// // dontTouch(config.io)
// // dontTouch(vreg.io)
// // PCMod.io.in := PCMod.io.pc4

// // instmemMod.io.req.bits.addrRequest := PCMod.io.out(11,2)
// // CntrlDecMod.io.Instruction := instmemMod.io.instruction
// // io.addr := instmemMod.io.address

// //regfile
// // regfileMod.io.RegWrite := CntrlDecMod.io.RegWrite
// // regfileMod.io.rs1:= instmemMod.io.instruction(19,15)
// // regfileMod.io.rs2 := instmemMod.io.instruction(24,20)
// // regfileMod.io.rd:=instmemMod.io.instruction(11,7)

// //vregfile
// // vreg.io.reg_write := CntrlDecMod.io.RegWrite
// // vreg.io.vs1_addr:= instmemMod.io.instruction(19,15)
// // vreg.io.vs2_addr := instmemMod.io.instruction(24,20)
// // vreg.io.vd_addr:= instmemMod.io.instruction(11,7)

// //immegen
// // ImmgenMod.io.instruction := instmemMod.io.instruction
// // ImmgenMod.io.pc := PCMod.io.pc

// //ALU Control
// // ALUcMod.io.aluOp := CntrlDecMod.io.aluop
// // ALUcMod.io.func3 := instmemMod.io.inst(14,12)
// // ALUcMod.io.func7 := instmemMod.io.inst(30)
// // ALUcMod.io.func6 := instmemMod.io.inst(31,26)
// // ALUcMod.io.V_inst := 1.B

// //csr
// // V_csr.io.vtypei :=ImmgenMod.io.z_imm
// // V_csr.io.vl  := config.io.vl
// // V_csr.io.vset := CntrlDecMod.io.vset

// //config
// // config.io.rs1 :=instmemMod.io.inst(19,15)
// // config.io.rd := instmemMod.io.inst(11,7)
// // config.io.rs1_readdata := regfileMod.io.rdata1
// // config.io.zimm := instmemMod.io.inst(30,20)
// // config.io.current_vl := 2.S

// //ALU
// //InA
// // ALUMod.io.in_A := MuxCase ( 0.S , Array (
// // (CntrlDecMod.io.opAsel ==="b00".U || CntrlDecMod.io.opAsel ==="b11".U) -> regfileMod.io.rdata1 ,
// // (CntrlDecMod.io.opAsel ==="b01".U) -> PCMod.io.pc4.asSInt ,
// // (CntrlDecMod.io.opAsel ==="b10".U) -> PCMod.io.pc.asSInt 
// // ))

// //InB
// // when(CntrlDecMod.io.Ex_sel === "b0000".U && CntrlDecMod.io.opBsel === 1.U){
// // 		ALUMod.io.in_B := ImmgenMod.io.i_imm
// // 	}.elsewhen(CntrlDecMod.io.Ex_sel === "b0001".U && CntrlDecMod.io.opBsel === 1.U){
// // 		ALUMod.io.in_B := ImmgenMod.io.s_imm
// // 	}.elsewhen(CntrlDecMod.io.Ex_sel === "b0010".U && CntrlDecMod.io.opBsel === 1.U){
// // 		ALUMod.io.in_B := ImmgenMod.io.u_imm
// // 	}.elsewhen(CntrlDecMod.io.Ex_sel === "b0011".U && CntrlDecMod.io.opBsel === 1.U){
// // 		ALUMod.io.in_B := ImmgenMod.io.z_imm
// // 	}.elsewhen(CntrlDecMod.io.Ex_sel === "b0100".U && CntrlDecMod.io.opBsel === 1.U){
// // 		ALUMod.io.in_B := ImmgenMod.io.addi_imm
// // 	}.otherwise{
// // 		ALUMod.io.in_B := regfileMod.io.rdata2
// // 	}
// // ALUMod.io.vs1 := vreg.io.vs1_data
// // ALUMod.io.vs2 := vreg.io.vs2_data
// // ALUMod.io.aluc := ALUcMod.io.aluc
// // ALUMod.io.vd_addr := instmemMod.io.inst(11,7)
// // ALUMod.io.sew := V_csr.io.vtype_out(5,3)
// // // ALUMod.io.sew := "b010".U
// // ALUMod.io.v_ins := CntrlDecMod.io.v_ins

// // ALUMod.io.vl:=V_csr.io.vl_out.asUInt
// // ALUMod.io.vta := V_csr.io.vtype_out(6).asUInt
// // ALUMod.io.vma := V_csr.io.vtype_out(7).asUInt
// // ALUMod.io.vm:= instmemMod.io.inst(25)
// // ALUMod.io.vd := vreg.io.vddata_o
// // ALUMod.io.vs0 := vreg.io.vs0_data
// // ALUMod.io.vstart := V_csr.io.vstart_out.asUInt


// //Branch

// // BrcntrlMod.io.branch := CntrlDecMod.io.Branch
// // BrcntrlMod.io.arg_x := 0.S
// // BrcntrlMod.io.arg_y := 0.S


// //In A
// // when (BrcntrlMod.io.branch === 1.B){
// //     BrcntrlMod.io.arg_x := MuxCase ( 0.S , Array (
// // (CntrlDecMod.io.opAsel ==="b00".U) -> regfileMod.io.rdata1 ,
// // (CntrlDecMod.io.opAsel ==="b01".U) -> (PCMod.io.pc4).asSInt ,
// // (CntrlDecMod.io.opAsel ==="b10".U ) -> (PCMod.io.pc).asSInt ,
// // (CntrlDecMod.io.opAsel ==="b11".U) -> regfileMod.io.rdata1)
// // )

// //In B
// when(CntrlDecMod.io.Ex_sel === "b00".U && CntrlDecMod.io.opBsel === 1.U){
// 		BrcntrlMod.io.arg_y := ImmgenMod.io.i_imm
// 	}.elsewhen(CntrlDecMod.io.Ex_sel === "b01".U && CntrlDecMod.io.opBsel === 1.U){
// 		BrcntrlMod.io.arg_y := ImmgenMod.io.s_imm
// 	}.elsewhen(CntrlDecMod.io.Ex_sel === "b10".U && CntrlDecMod.io.opBsel === 1.U){
// 		BrcntrlMod.io.arg_y := ImmgenMod.io.u_imm
// 	}.otherwise{
// 		BrcntrlMod.io.arg_y := regfileMod.io.rdata2
// 	}

// // } 
// BrcntrlMod.io.aluc := CntrlDecMod.io.aluop

// //jalr component
// // jalrCompMod.io.rs1 := regfileMod.io.rdata1
// // jalrCompMod.io.imm := ImmgenMod.io.i_imm

// // PCMod.io.input := MuxCase ( 0.U , Array (
// // (CntrlDecMod.io.nextPCsel === "b00".U ) -> PCMod.io.pc4 ,
// // (CntrlDecMod.io.nextPCsel === "b01".U) -> Mux(BrcntrlMod.io.br_taken,(ImmgenMod.io.sb_imm).asUInt,PCMod.io.pc4) ,
// // (CntrlDecMod.io.nextPCsel === "b10".U) -> (ImmgenMod.io.uj_imm).asUInt ,
// // (CntrlDecMod.io.nextPCsel === "b11".U) -> (jalrCompMod.io.out).asUInt)
// // )

// // datamemory
// datamemMod.io.Addr := (ALUMod.io.output(9,2)).asUInt
// datamemMod.io.Data := regfileMod.io.rdata2
// datamemMod.io.MemWrite := CntrlDecMod.io.MemWrite
// datamemMod.io.MemRead := CntrlDecMod.io.MemRead


// regfileMod.io.WriteData := MuxCase ( 0.S , Array (
// (CntrlDecMod.io.Mem2Reg === 0.B ) -> Mux(CntrlDecMod.io.vset,config.io.vl,ALUMod.io.output),
// (CntrlDecMod.io.Mem2Reg === 1.B ) -> datamemMod.io.out)
// )
// // vreg.io.vd_data := tail_mask.io.v_data_out.asSInt
// vreg.io.vd_data := ALUMod.io.v_output.asSInt
// io.out := 0.U

// // }