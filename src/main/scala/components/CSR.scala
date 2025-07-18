package nucleusrv.components
import chisel3._
import chisel3.util._

class CSRIO extends Bundle {
  val read_addr    = Input(UInt(12.W))
  val write_addr   = Input(UInt(12.W))
  val write_data   = Input(UInt(32.W))
  val write_enable = Input(Bool())
  val read_data    = Output(UInt(32.W))
  
  // Exception handling
  val exception    = Input(Bool())
  val exception_pc = Input(UInt(32.W))
  val exception_cause = Input(UInt(32.W))
  val exception_tval  = Input(UInt(32.W))
  val mret         = Input(Bool())
  
  // Output signals
  val trap_vector  = Output(UInt(32.W))
  val mepc_out     = Output(UInt(32.W))
  val current_priv = Output(UInt(2.W))
  
  // Performance counters
  val inst_retired = Input(Bool())
}

class CSR extends Module {
  val io = IO(new CSRIO)
  
  import CSRs._
  import Exceptions._
  import PrivilegeModes._
  
  // CSR Register File
  val mstatus   = RegInit("h00001800".U(32.W))  // Initialize with MPP=11 (Machine mode)
  val misa      = RegInit("h40001100".U(32.W))  // RV32I base + M extension
  val mie       = RegInit(0.U(32.W))
  val mtvec     = RegInit(0.U(32.W))
  val mscratch  = RegInit(0.U(32.W))
  val mepc      = RegInit(0.U(32.W))
  val mcause    = RegInit(0.U(32.W))
  val mtval     = RegInit(0.U(32.W))
  val mip       = RegInit(0.U(32.W))
  
  // Performance counters
  val mcycle    = RegInit(0.U(64.W))
  val minstret  = RegInit(0.U(64.W))
  
  // Machine info registers (read-only)
  val mvendorid = 0.U(32.W)      // Vendor ID
  val marchid   = 0.U(32.W)      // Architecture ID  
  val mimpid    = 1.U(32.W)      // Implementation ID
  val mhartid   = 0.U(32.W)      // Hardware thread ID
  
  // Current privilege mode
  val current_privilege = RegInit(MACHINE_MODE)
  
  // Update performance counters
  mcycle := mcycle + 1.U
  when(io.inst_retired) {
    minstret := minstret + 1.U
  }
  
  // CSR Read Logic
  io.read_data := MuxLookup(io.read_addr, 0.U, Seq(
    MSTATUS   -> mstatus,
    MISA      -> misa,
    MIE       -> mie,
    MTVEC     -> mtvec,
    MSCRATCH  -> mscratch,
    MEPC      -> mepc,
    MCAUSE    -> mcause,
    MTVAL     -> mtval,
    MIP       -> mip,
    MCYCLE    -> mcycle(31, 0),
    MCYCLEH   -> mcycle(63, 32),
    MINSTRET  -> minstret(31, 0),
    MINSTRETH -> minstret(63, 32),
    MVENDORID -> mvendorid,
    MARCHID   -> marchid,
    MIMPID    -> mimpid,
    MHARTID   -> mhartid
  ))
  
  // CSR Write Logic
  when(io.write_enable) {
    switch(io.write_addr) {
      is(MSTATUS) {
        // Only allow writing to certain fields
        mstatus := (mstatus & "hFFFF7F77".U) | (io.write_data & "h00008088".U)
      }
      is(MIE) {
        mie := io.write_data
      }
      is(MTVEC) {
        mtvec := io.write_data & "hFFFFFFFC".U  // Align to 4-byte boundary
      }
      is(MSCRATCH) {
        mscratch := io.write_data
      }
      is(MEPC) {
        mepc := io.write_data & "hFFFFFFFC".U  // Align to 4-byte boundary
      }
      is(MCAUSE) {
        mcause := io.write_data
      }
      is(MTVAL) {
        mtval := io.write_data
      }
      // Performance counters are writable
      is(MCYCLE) {
        mcycle := Cat(mcycle(63, 32), io.write_data)
      }
      is(MCYCLEH) {
        mcycle := Cat(io.write_data, mcycle(31, 0))
      }
      is(MINSTRET) {
        minstret := Cat(minstret(63, 32), io.write_data)
      }
      is(MINSTRETH) {
        minstret := Cat(io.write_data, minstret(31, 0))
      }
    }
  }
  
  // Exception/Interrupt Handling
  when(io.exception) {
    mepc := io.exception_pc
    mcause := io.exception_cause
    mtval := io.exception_tval
    
    // Update MSTATUS
    val new_mstatus = Wire(UInt(32.W))
    new_mstatus := mstatus
    
    // Save current MIE to MPIE and clear MIE
    new_mstatus := (new_mstatus & "hFFFFFF77".U) | 
                   ((mstatus & "h00000008".U) << 4) |  // MPIE = MIE
                   "h00000000".U                        // MIE = 0
    
    // Save current privilege mode to MPP and set to Machine mode
    new_mstatus := (new_mstatus & "hFFFFE7FF".U) | 
                   (current_privilege << 11)           // MPP = current_privilege
    
    mstatus := new_mstatus
    current_privilege := MACHINE_MODE
  }
  
  // MRET Handling
  when(io.mret) {
    // Restore privilege mode from MPP
    current_privilege := (mstatus >> 11) & "h3".U
    
    // Restore MIE from MPIE and set MPIE to 1
    val new_mstatus = Wire(UInt(32.W))
    new_mstatus := (mstatus & "hFFFFFF77".U) | 
                   ((mstatus & "h00000080".U) >> 4) |  // MIE = MPIE
                   "h00000080".U                        // MPIE = 1
    
    // Clear MPP to User mode
    new_mstatus := new_mstatus & "hFFFFE7FF".U
    
    mstatus := new_mstatus
  }
  
  // Output signals
  io.trap_vector := mtvec
  io.mepc_out := mepc
  io.current_priv := current_privilege
}
