package nucleusrv.components.fpu

trait Parameters {
  val flen          : Int = 32
  val regAddrWidth  : Int = 5
  val bias          : Int = 127
  val expWidth      : Int = 8
  val sigWidth      : Int = 23
  val signWidth     : Int = 1
  val roundModeWidth: Int = 3
  val f5Width       : Int = 5
  val fOpcodeWidth  : Int = 7
  val fFmtWidth     : Int = 2
  val rmWidth       : Int = 3
}
