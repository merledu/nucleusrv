########################################################################
# Print the game's console log over JTAG (no UART needed).
#
# The game mirrors everything it prints into DDR3 at 0x13F00000 (it writes
# through the uncached alias 0x23F00000, so nothing is held in the cache):
#   0x13F00000  magic "DLOG" (0x474F4C44)
#   0x13F00004  total bytes written
#   0x13F00100  ring buffer, 0xFF00 bytes
#
# Usage, in the same xsdb session after snowbros_startup.tcl (any time, also
# while the game runs):
#   xsdb% source /path/to/deploy/doom_log.tcl
########################################################################

set DLOG_BASE 0x13F00000
set DLOG_DATA 0x13F00100
set DLOG_SIZE 0xFF00

targets -set -filter {name =~ "ARM*#0"}
set hdr   [mrd -force -value $DLOG_BASE 2]
set magic [lindex $hdr 0]
set count [lindex $hdr 1]

if {$magic != 0x474F4C44} {
    puts "No game log in DDR yet (magic = [format 0x%08X $magic]). Has SW3 been flipped up and down?"
    return
}

if {$count <= $DLOG_SIZE} {
    set start 0
    set n $count
} else {
    set start [expr {$count % $DLOG_SIZE}]
    set n $DLOG_SIZE
}

set bytes [mrd -force -value -size b $DLOG_DATA $DLOG_SIZE]
set text ""
for {set i 0} {$i < $n} {incr i} {
    set b [lindex $bytes [expr {($start + $i) % $DLOG_SIZE}]]
    if {$b != 13} { append text [format %c $b] }
}
puts "---------------- Game log ($count bytes written) ----------------"
puts $text
puts "-----------------------------------------------------------------"
