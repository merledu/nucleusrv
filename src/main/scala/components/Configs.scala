package nucleusrv.components

case class Configs(
    XLEN    : Int     = 64,

    M       : Boolean = false,
    A       : Boolean = false,
    F       : Boolean = true,
    D       : Boolean = false,
    C       : Boolean = false,
    Zicsr   : Boolean = true,

    TRACE   : Boolean = true,

    HARTID  : Int     = 1,
    ARCHID  : Int     = 1
)
