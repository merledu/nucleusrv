package nucleusrv.components

import chisel3._
import chisel3.util._

class CacheFSM(NumWays: Int, OffsetBits: Int) extends Module {
  val io = IO(new Bundle {
    val CPURequest   = Input(Bool())
    val IsWrite      = Input(Bool())
    val WriteData    = Input(UInt(128.W))
    val ReadData     = Output(UInt(128.W))
    val CacheReady   = Output(Bool())
    val MemReadEnable = Output(Bool())
    val MemWriteEnable = Output(Bool())
    val MemAddr      = Output(UInt(32.W))
    val MemWriteData = Output(UInt(128.W))
    val MemReadData  = Input(UInt(128.W))
    val MemReady     = Input(Bool())
  })
    // 00          01            10           11
  val Idle :: CompareTag :: WriteBack :: Allocate :: Nil = Enum(4)
  val State = RegInit(Idle)

  val Tags = Reg(Vec(512, Vec(NumWays, UInt(19.W))))
  val ValidBits = Reg(Vec(512, Vec(NumWays, Bool())))
  val DirtyBits = Reg(Vec(512, Vec(NumWays, Bool())))
  val DataBlocks = SyncReadMem(512, Vec(NumWays, UInt(128.W)))

  val Index = Wire(UInt(9.W))
  val Tag = Wire(UInt(19.W))
  val CacheHit = Wire(Bool())
  // val WayHit = Reg(UInt(log2Ceil(NumWays).W))
  val SelectedData = Reg(UInt(128.W))
  val OldBlockIsDirty = Wire(Bool())

  io.CacheReady := false.B
  io.MemReadEnable := false.B
  io.MemWriteEnable := false.B
  io.ReadData := 0.U
  io.MemAddr := 0.U
  io.MemWriteData := 0.U

  switch(State) {
    is(Idle) {
      when(io.CPURequest) {
        State := CompareTag
      }
    }
    is(CompareTag) {
      CacheHit := false.B
      for (i <- 0 until NumWays) {
        when(Tags(Index)(i) === Tag && ValidBits(Index)(i)) {
          CacheHit := true.B
          WayHit := i.U
          SelectedData := DataBlocks.read(Index)(i)
        }
      }
      when(CacheHit) {
        io.CacheReady := true.B
        when(io.IsWrite) {
          DataBlocks.write(Index, VecInit(Seq.fill(NumWays)(io.WriteData)), WayHit)
          DirtyBits(Index)(WayHit) := true.B
        } .otherwise {
          io.ReadData := SelectedData
        }
        State := Idle
      } .otherwise {
        OldBlockIsDirty := DirtyBits(Index)(WayHit)
        when(OldBlockIsDirty) { // is dirty go to write back
          State := WriteBack
        } .otherwise {  // is clean goto allocate
          State := Allocate
        }
      }
    }

    is(WriteBack) {
      io.MemWriteEnable := true.B
      io.MemAddr := Cat(Tags(Index)(WayHit), Index, 0.U(OffsetBits.W))
      io.MemWriteData := DataBlocks.read(Index)(WayHit)
      when(io.MemReady) {
        State := Allocate
      }
    }
    is(Allocate) {
      io.MemReadEnable := true.B
      io.MemAddr := Cat(Tag, Index, 0.U(OffsetBits.W))
      when(io.MemReady) {
        Tags(Index)(WayHit) := Tag
        ValidBits(Index)(WayHit) := true.B
        DirtyBits(Index)(WayHit) := false.B
        DataBlocks.write(Index, VecInit(Seq.fill(NumWays)(io.MemReadData)), WayHit)
        State := CompareTag
      }
    }
  }
}

