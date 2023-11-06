package nucleusrv.components

trait BaseConfig {
    val XLEN    : Int       = 32  
    val M       : Boolean   = true
    val C       : Boolean   = true
    val TRACE   : Boolean   = true
}

case class DefaultConfig() extends BaseConfig