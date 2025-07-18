package nucleusrv.components
import chisel3._
import chisel3.util._

class CSRUnit extends Module {
  val io = IO(new Bundle {
    // Control signals from decode stage
    val csr_op = Input(UInt(3.W))
    val csr_read = Input(Bool())
    val csr_write = Input(Bool())
    val is_ecall = Input(Bool())
    val is_ebreak = Input(Bool())
    val is_mret = Input(Bool())
    
    // Instruction fields
    val csr_addr = Input(UInt(12.W))
    val rs1_data = Input(UInt(32.W))
    val rs1_addr = Input(UInt(5.W))
    val pc = Input(UInt(32.W))
    
    // Outputs
    val csr_data = Output(UInt(32.W))
    val exception = Output(Bool())
    val exception_pc = Output(UInt(32.W))
    val mret_pc = Output(UInt(32.W))
    val take_trap = Output(Bool())
    val take_mret = Output(Bool())
    
    // Performance monitoring
    val inst_retired = Input(Bool())
  })

  import Instructions._
  import Exceptions._
  
  // Instantiate CSR register file
  val csr = Module(new CSR)
  
  // CSR operation logic
  val csr_wdata = Wire(UInt(32.W))
  val csr_wmask = Wire(UInt(32.W))
  val csr_rdata = csr.io.read_data
  
  // Connect CSR address for reading
  csr.io.read_addr := io.csr_addr
  
  // Generate write data and mask based on CSR operation
  when(io.csr_op === CSRRW || io.csr_op === CSRRWI) {
    // Write: replace entire CSR value
    csr_wdata := Mux(io.csr_op === CSRRWI, io.rs1_addr.asUInt, io.rs1_data)
    csr_wmask := "hFFFFFFFF".U
  }.elsewhen(io.csr_op === CSRRS || io.csr_op === CSRRSI) {
    // Set: set bits in CSR
    val set_data = Mux(io.csr_op === CSRRSI, io.rs1_addr.asUInt, io.rs1_data)
    csr_wdata := csr_rdata | set_data
    csr_wmask := set_data
  }.elsewhen(io.csr_op === CSRRC || io.csr_op === CSRRCI) {
    // Clear: clear bits in CSR
    val clear_data = Mux(io.csr_op === CSRRCI, io.rs1_addr.asUInt, io.rs1_data)
    csr_wdata := csr_rdata & (~clear_data)
    csr_wmask := clear_data
  }.otherwise {
    csr_wdata := 0.U
    csr_wmask := 0.U
  }
  
  // Connect CSR write signals
  csr.io.write_addr := io.csr_addr
  csr.io.write_data := csr_wdata
  csr.io.write_enable := io.csr_write && (csr_wmask =/= 0.U)
  
  // Exception detection and handling
  val exception_occurred = io.is_ecall || io.is_ebreak
  val exception_cause = Wire(UInt(32.W))
  
  when(io.is_ecall) {
    // For now, assume M-mode ecall
    exception_cause := ECALL_FROM_M
  }.elsewhen(io.is_ebreak) {
    exception_cause := BREAKPOINT
  }.otherwise {
    exception_cause := 0.U
  }
  
  // Connect exception signals to CSR
  csr.io.exception := exception_occurred
  csr.io.exception_pc := io.pc
  csr.io.exception_cause := exception_cause
  csr.io.exception_tval := 0.U  // No additional trap value for now
  csr.io.mret := io.is_mret
  csr.io.inst_retired := io.inst_retired
  
  // Output signals
  io.csr_data := csr_rdata
  io.exception := exception_occurred
  io.exception_pc := csr.io.trap_vector
  io.mret_pc := csr.io.mepc_out
  io.take_trap := exception_occurred
  io.take_mret := io.is_mret
}
