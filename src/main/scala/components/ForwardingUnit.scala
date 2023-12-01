package nucleusrv.components
import chisel3._

class ForwardingUnit extends Module {
  val io = IO(new Bundle {
    val ex_reg_rd = Input(UInt(5.W))
    val mem_reg_rd = Input(UInt(5.W))
    val reg_rs1 = Input(UInt(5.W))
    val reg_rs2 = Input(UInt(5.W))
    val ex_regWrite = Input(Bool())
    val mem_regWrite = Input(Bool())
    
    // For vector
    val ex_reg_vd = Input(UInt(5.W))
    val mem_reg_vd = Input(UInt(5.W))
    val reg_vs1 = Input(UInt(5.W))
    val reg_vs2 = Input(UInt(5.W))
    val reg_vs3 = Input(UInt(5.W))
   // val reg_vs0 = Input(UInt(5.W))
    val ex_reg_write = Input(Bool())
    val mem_reg_write = Input(Bool())

    val forwardA = Output(UInt(2.W))
    val forwardB = Output(UInt(2.W))
    val forwardC = Output(UInt(2.W))
   // val forward0 = Output(UInt(2.W))
  })

  io.forwardA := DontCare
  io.forwardB := DontCare
  io.forwardC := DontCare
  //io.forward0 := DontCare
  
  when(io.reg_rs1 === io.ex_reg_rd && io.ex_reg_rd =/= 0.U && io.ex_regWrite){
    io.forwardA := 1.U
  }.elsewhen(io.reg_vs1 === io.ex_reg_vd && io.ex_reg_vd =/= 0.U && io.ex_reg_write){
    io.forwardA := 1.U
  }.elsewhen(io.reg_rs1 === io.mem_reg_rd && io.mem_reg_rd =/= 0.U && io.mem_regWrite){ 
    io.forwardA := 2.U
  }.elsewhen(io.reg_vs1 === io.mem_reg_vd && io.mem_reg_vd =/= 0.U && io.mem_reg_write){
    io.forwardA := 2.U
  }.otherwise{
    io.forwardA := 0.U
  }

  when(io.reg_rs2 === io.ex_reg_rd && io.ex_reg_rd =/= 0.U && io.ex_regWrite){
    io.forwardB := 1.U  
  }.elsewhen(io.reg_vs2 === io.ex_reg_vd && io.ex_reg_vd =/= 0.U && io.ex_reg_write){
    io.forwardB := 1.U
  }.elsewhen(io.reg_rs2 === io.mem_reg_rd && io.mem_reg_rd =/= 0.U && io.mem_regWrite){
    io.forwardB := 2.U
  }.elsewhen(io.reg_vs2 === io.mem_reg_vd && io.mem_reg_vd =/= 0.U && io.mem_reg_write){
    io.forwardB := 2.U
  }.otherwise{
    io.forwardB := 0.U
  }

  when(io.reg_vs3 === io.ex_reg_vd && io.ex_reg_vd =/= 0.U && io.ex_reg_write){
    io.forwardC := 1.U  
  }.elsewhen(io.reg_vs3 === io.mem_reg_vd && io.mem_reg_vd =/= 0.U && io.mem_reg_write){
    io.forwardC := 2.U
  //}.elsewhen(io.reg_vs3 === io.id_reg_vd && io.id_reg_vd =/= 0.U && io.ex_reg_write && )
  }.otherwise{
    io.forwardC := 0.U
  }

  // when(io.reg_vs0 === io.ex_reg_rd  && io.ex_regWrite){
  //   io.forwardC := 1.U  
  // }.elsewhen(io.reg_vs0 === io.mem_reg_vd && io.mem_reg_vd =/= 0.U && io.mem_reg_write){
  //   io.forwardC := 2.U
  // }.otherwise{
  //   io.forwardC := 0.U
  // }

}