package nucleusrv.components

case class Configs(
    XLEN    : Int     = 32,
    M       : Boolean = false,
    F       : Boolean = false,
    C       : Boolean = false,
    A       : Boolean = true,
    Zicsr   : Boolean = false,
    TRACE   : Boolean = true,
    HARTID  : Int     = 1,
    ARCHID  : Int     = 1
)
