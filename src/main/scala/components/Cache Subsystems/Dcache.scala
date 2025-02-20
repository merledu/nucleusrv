package nucleusrv.components
import chisel3._
import chisel3.util._
//datacache block
class CacheLine extends Bundle {
  val valid = Bool()
  val tag   = UInt(19.W)
  val data  = UInt(128.W) 
}

class DataCache extends Module {
  val io = IO(new Bundle {
    val addr   = Input(UInt(32.W))    // 32bit addr
    val write  = Input(Bool())        // write enable
    val writeData = Input(UInt(128.W))// data to write (whole block, 0000....32b) 
    val read   = Input(Bool())        // read enable
    val dataOut = Output(UInt(128.W)) // read output
    val hit    = Output(Bool())
  })
  val dcache = Module(new datacache_sramTop(programFile))

  val NUM_SETS = 512  // 2^9 sets
  val WAYS = 4

  val index  = io.addr(17, 9)  // 9bit 
  val tag    = io.addr(31, 13) // 19bit 
  val offset = io.addr(8, 5)   // 4bit

  // Cache Memory: 512 sets, 4 ways
  // 512 sets.. Each set contains 4 cache lines: CacheLine structure
  val Dcache = RegInit(VecInit(Seq.fill(NUM_SETS)(VecInit(Seq.fill(WAYS)(0.U.asTypeOf(new CacheLine))))))
  
}
