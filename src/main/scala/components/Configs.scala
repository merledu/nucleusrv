package nucleusrv.components

case class Configs(
    XLEN      : Int     = 32,
    M         : Boolean = true,
    F         : Boolean = true,
    C         : Boolean = true,
    Zicsr     : Boolean = true,
    TRACE     : Boolean = true,
    BABY_KYBER: Boolean = true
)
