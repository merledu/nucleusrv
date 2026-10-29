package nucleusrv.components

case class Configs(
    XLEN    : Int     = 32,

    M       : Boolean = true,
    A       : Boolean = true,
    F       : Boolean = false,
    D       : Boolean = false,
    C       : Boolean = true,
    Zicsr   : Boolean = true,

    TRACE   : Boolean = false,

    HARTID  : Int     = 1,
    ARCHID  : Int     = 1
)
