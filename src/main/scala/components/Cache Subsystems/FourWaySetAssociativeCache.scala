package nucleusrv.components

import chisel3._
import chisel3.util._

class FourWaySetAssociativeCache extends Module {
  val io = IO(new Bundle {
    val addr = Input(UInt(32.W)) 
    val cacheTags = Input(Vec(4, UInt(22.W)))
    val cacheData = Input(Vec(4, UInt(32.W)))
    val validBits = Input(Vec(4, Bool()))    

    val hit = Output(Bool())                
    val data = Output(UInt(32.W))      
  })
  // io.index := io.addr(9, 1)
  // offset from bit 0
  // io.offset := io.addr(0)
  val tag = io.addr(31, 10)

  //if input tag === cache tags and valibits
  val tagMatch0 = (tag === io.cacheTags(0)) && io.validBits(0)
  val tagMatch1 = (tag === io.cacheTags(1)) && io.validBits(1)
  val tagMatch2 = (tag === io.cacheTags(2)) && io.validBits(2)
  val tagMatch3 = (tag === io.cacheTags(3)) && io.validBits(3)

  io.hit := tagMatch0 || tagMatch1 || tagMatch2 || tagMatch3

  val data0 = Mux(tagMatch0, io.cacheData(0), 0.U)
  val data1 = Mux(tagMatch1, io.cacheData(1), 0.U)
  val data2 = Mux(tagMatch2, io.cacheData(2), 0.U)
  val data3 = Mux(tagMatch3, io.cacheData(3), 0.U)

  // io.data := Mux(tagMatch0, data0, Mux(tagMatch1, data1, Mux(tagMatch2,data2, Mux(tagMatch3, data3))))
  io.data := data0 | data1 | data2 | data3
}