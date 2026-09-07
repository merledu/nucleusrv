package nucleusrv.components

case class Configs(
    XLEN    : Int     = 32,

    M       : Boolean = true,
    A       : Boolean = true,
    F       : Boolean = true,
    D       : Boolean = true,
    C       : Boolean = true,
    Zicsr   : Boolean = true,

    TRACE   : Boolean = true,

    HARTID  : Int     = 1,
    ARCHID  : Int     = 1
)
