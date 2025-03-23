package nucleusrv.components

import chisel3._
import chisel3.util._

class CacheWrapper extends Module {
  val io = IO(new Bundle {
    val addr    = Input(UInt(32.W))
    val wdata   = Input(UInt(128.W))

    val wen     = Input(Bool())

    val rdata   = Output(UInt(128.W))
    val validOut = Output(Bool())
    val tagOut   = Output(UInt(19.W))  // tag is 19 bits
  })
    // Addr Breakdown
  val index  = io.addr(17, 9)  // 9-bit index (128 sets)
  val tag    = io.addr(31, 13) // 19bit tag
  val offset = io.addr(8, 5)   // 4bit offset (32 bytes per block)

  // Dcache instance
  val dcache = Module(new DatacacheSRAMTop)
  // Dcache Inputs
  dcache.io.addr  := io.addr
  dcache.io.wdata := io.wdata
  dcache.io.wen   := io.wen

  // val TagBlocks  = RegInit(VecInit(Seq.fill(128)(VecInit(Seq.fill(4)(0.U(19.W)))))) // 4-way tag storage
  // val ValidBits  = RegInit(VecInit(Seq.fill(128)(VecInit(Seq.fill(4)(false.B)))))  // Valid bits
  
  // Cache Storage (4-way associative, 128 sets)
  val TagBlocks = Vec(128, Vec(4, UInt(19.W)))   //  19 bit tags
  val ValidBits = Vec(128, Vec(4, Bool()))    // 1 bit valid

  // Select Set Using index
  val selectedSet = TagBlocks(index) // Get all 4 tags for this set
  // compare tags & check valid bits for each way
  val tagMatches = VecInit(
    (tag === selectedSet(0)) && ValidBits(index)(0),
    (tag === selectedSet(1)) && ValidBits(index)(1),
    (tag === selectedSet(2)) && ValidBits(index)(2),
    (tag === selectedSet(3)) && ValidBits(index)(3)
  )
  // cache Hit if any tag matches
  val hit = tagMatches(0) || tagMatches(1) || tagMatches(2) || tagMatches(3)
  io.validOut := hit // Valid only if a hit occurs

  //Select Correct Way’s Data Block
  val blockData = MuxCase(0.U, Seq(
    tagMatches(0) -> dcache.io.rdata(0),
    tagMatches(1) -> dcache.io.rdata(1),
    tagMatches(2) -> dcache.io.rdata(2),
    tagMatches(3) -> dcache.io.rdata(3)
  ))

  // OffsetBased word selection (Extract 32-bit word from 128-bit block)
  val wordOffset = offset >> 2  // Convert byte offset to word offset (0-3)
  io.rdata := MuxLookup(wordOffset, 0.U(32.W), Seq(
    0.U  -> blockData(31, 0),
    1.U  -> blockData(63, 32),
    2.U  -> blockData(95, 64),
    3.U  -> blockData(127, 96)
  ))


}
