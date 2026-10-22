package nucleusrv.components

case class Configs(
    XLEN    : Int     = 64,

    M       : Boolean = false,
    A       : Boolean = true,
    F       : Boolean = false,
    D       : Boolean = false,
    C       : Boolean = false,
    Zicsr   : Boolean = false,

    TRACE   : Boolean = true,

    HARTID  : Int     = 1,
    ARCHID  : Int     = 1
)
