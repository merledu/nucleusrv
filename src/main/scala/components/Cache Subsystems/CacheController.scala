// package nucleusrv.components
// import chisel3._
// import chisel3.util._

// class CacheController extends Module {
//   val io = IO(new Bundle {
//     val CPURequest = Input(Bool())  // read/write
//     val IsWrite = Input(Bool())

//     val Addr = Input(UInt(32.W))             // 32bit address
//     val WriteData = Input(UInt(128.W))       // Write data (128-bit block)
//     val ReadData = Output(UInt(128.W))       // Read data (128-bit block)

//     val CacheReady = Output(Bool())          // Cache Ready signal
//     val MemWriteEnable = Output(Bool())      // Memory write enable
//     val MemReadEnable = Output(Bool())       // Memory read enable
//     val MemAddr = Output(UInt(32.W))         // Memory address
//     val MemWriteData = Output(UInt(128.W))   // Memory write data
//     val MemReadData = Input(UInt(128.W))     // Memory read data
//     val MemReady = Input(Bool())
//   })

//   val Idle :: CompareTag :: WriteBack :: Allocate :: Nil = Enum(4)
//   val State = RegInit(Idle)
//     // Cache storage
//   val NumSets = 64
//   val NumWays = 4
//   val TagBits = 22
//   val IndexBits = 6
//   val OffsetBits = 4

//   val Tags = Reg(Vec(NumSets, Vec(NumWays, UInt(TagBits.W))))
//   val ValidBits = Reg(Vec(NumSets, Vec(NumWays, Bool())))
//   val DirtyBits = Reg(Vec(NumSets, Vec(NumWays, Bool())))
//   val DataBlocks = SyncReadMem(NumSets, Vec(NumWays, UInt(128.W)))


//   val Tag = io.Addr(31, 10)  
//   val Index = io.Addr(9, 4)  
//   val Offset = io.Addr(3, 0)

//   // Internal signals
//   val WayHit = Wire(UInt(log2Ceil(NumWays).W))
//   val CacheHit = Wire(Bool())
//   val SelectedData = Wire(UInt(128.W))
//   val OldBlockIsDirty = Wire(Bool())

//   io.CacheReady := false.B
//   io.MemWriteEnable := false.B
//   io.MemReadEnable := false.B
//   io.MemAddr := 0.U
//   io.MemWriteData := 0.U
//   io.ReadData := 0.U

//   switch(State) {
//     is(Idle) {
//       when(io.CPURequest) {
//         State := CompareTag
//       }
//     }

//     is(CompareTag) {
//       // Compare tags valid bits
//       CacheHit := false.B
//       for (i <- 0 until NumWays) {
//         when(Tags(Index)(i) === Tag && ValidBits(Index)(i)) {
//           CacheHit := true.B
//           WayHit := i.U
//           SelectedData := DataBlocks.read(Index)(i)
//         }
//       }

//       when(CacheHit) {
//         io.CacheReady := true.B
//         when(io.IsWrite) {
//           // Write data to cache
//           DataBlocks.write(Index, VecInit(Seq.fill(NumWays)(io.WriteData)), WayHit)
//           DirtyBits(Index)(WayHit) := true.B
//         } otherwise {
//           // Read data from cache
//           io.ReadData := SelectedData
//         }
//         State := Idle
//       } otherwise {
//         // Cache Miss
//         OldBlockIsDirty := DirtyBits(Index)(WayHit)
//         when(OldBlockIsDirty) {
//           State := WriteBack
//         } otherwise {
//           State := Allocate
//         }
//       }
//     }

//     is(WriteBack) {
//       // Write old block to memory
//       io.MemWriteEnable := true.B
//       io.MemAddr := Cat(Tags(Index)(WayHit), Index, 0.U(OffsetBits.W))
//       io.MemWriteData := DataBlocks.read(Index)(WayHit)

//       when(io.MemReady) {
//         State := Allocate
//       }
//     }

//     is(Allocate) {
//       // Read new block from memory
//       io.MemReadEnable := true.B
//       io.MemAddr := Cat(Tag, Index, 0.U(OffsetBits.W))

//       when(io.MemReady) {
//         // Update cache with new block
//         Tags(Index)(WayHit) := Tag
//         ValidBits(Index)(WayHit) := true.B
//         DirtyBits(Index)(WayHit) := false.B
//         DataBlocks.write(Index, VecInit(Seq.fill(NumWays)(io.MemReadData)), WayHit)
//         State := CompareTag
//       }
//     }
//   }
// }