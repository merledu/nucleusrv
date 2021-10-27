
// Copyright (C) 2020-2021 the original author or authors.
// See the LICENCE.txt file distributed with this work for additional
// information regarding copyright ownership.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package nucleusrv.components
import chisel3._
import chisel3.util._

class AluControl extends Module {
  val io = IO(new Bundle {
    val aluOp: UInt = Input(UInt(2.W))
    val f7: UInt = Input(UInt(1.W))
    val f3: UInt = Input(UInt(3.W))
    val aluSrc: Bool = Input(Bool())
    val out: UInt = Output(UInt(4.W))
  })

  io.out := 15.U

  when(io.aluOp === 0.U) {
    io.out := 2.U
  }.otherwise { //(io.aluOp === 2.U)
    switch(io.f3) {
      is(0.U) {
        when(!io.aluSrc || io.f7 === 0.U) {
          io.out := 2.U
        } //add
          .otherwise {
            io.out := 3.U
          } // sub
      }
      is(1.U) {
        io.out := 6.U
      } // sll
      is(2.U) {
        io.out := 4.U
      } // slt
      is(3.U) {
        io.out := 5.U
      } // sltu
      is(5.U) {
        when(io.f7 === 0.U) {
          io.out := 7.U // srl
        }.otherwise {
          io.out := 8.U // sra
        }
      }
      is(7.U) {
        io.out := 0.U
      } // and
      is(6.U) {
        io.out := 1.U
      } // or
      is(4.U) {
        io.out := 9.U
      } //xor
    }
  }
}
