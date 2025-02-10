package nucleusrv.components

import chisel3._
import chisel3.util._

class FSM extends Module {
  val io = IO(new Bundle {
    val cpuRequest = Input(Bool())      // CPU request for read/write
    val cacheHit = Input(Bool())        // Cache hit
    val dirtyBit = Input(Bool())        // Dirty bit
    val memoryReady = Input(Bool())    // Memory ready

    val setTag = Output(Bool())         // Set tag field
    val setValid = Output(Bool())       
    val setDirty = Output(Bool())       
    val writeBack = Output(Bool())      // Write back
    val memoryRead = Output(Bool())     // Read new block from mem
    val cacheReady = Output(Bool())     // Cache ready 
    val miss = Output(Bool())           // Cache miss
  })
    // 00          01            10           11
  val sIdle :: sCompareTag :: sAllocate :: sWriteBack :: Nil = Enum(4)
  val state = RegInit(sIdle)

  io.setTag := false.B
  io.setValid := false.B
  io.setDirty := false.B
  io.writeBack := false.B
  io.memoryRead := false.B
  io.cacheReady := false.B
  io.miss := false.B

  switch(state) {
    is(sIdle) {
      when(io.cpuRequest) {
        state := sCompareTag
      }
    }
    is(sCompareTag) {
      when(io.cacheHit) { // Cache hit
        io.cacheReady := true.B
        io.setValid := true.B
        io.setTag := true.B
        when(io.cpuRequest) {
          io.setDirty := true.B // Set dirty bit on a write
        }
        state := sIdle
      }.otherwise { // Cache miss
        io.miss := true.B
        when(io.dirtyBit) { // Dirty block.. go to Write-Back(11)
          state := sWriteBack
        }.otherwise { // Clean block..go to Allocate(10)
          state := sAllocate
        }
      }
    }
    is(sWriteBack) { // Write dirty block to mem
      io.writeBack := true.B
      when(io.memoryReady) {
        state := sAllocate // After writeback go Allocate(10)
      }
    }
    is(sAllocate) {  // get new block from mem
      io.memoryRead := true.B
      when(io.memoryReady) {
        state := sCompareTag // go to Comparetag to update cache
      }
    }
  }
}
