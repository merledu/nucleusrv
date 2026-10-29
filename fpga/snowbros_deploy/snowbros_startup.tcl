########################################################################
# NucleusRV Snow Bros (InfoNES) Startup Script  --  Digilent Zybo Z7-10
# Compatible with XSDB 2018.2+
#
# PORTABLE: All paths are relative to this script's own directory.
# Copy the entire "snowbros_deploy" folder to the lab PC and run from xsdb:
#
#   xsdb% source /path/to/snowbros_deploy/snowbros_startup.tcl
#
# This folder uses its own bitstream (nucleusrv_sw3reset_zybo_z7.bit):
# reset is on slide switch SW3 (up = held in reset), and BTN0 is a game
# button. The DOOM setup in fpga/deploy is separate and unchanged.
########################################################################

set SCRIPT_DIR [file dirname [file normalize [info script]]]

set BIT_FILE  [file join $SCRIPT_DIR "nucleusrv_sw3reset_zybo_z7.bit"]
set PS7_INIT  [file join $SCRIPT_DIR "ps7_init.tcl"]
set GAME_BIN  [file join $SCRIPT_DIR "snowbros.bin"]
set GAME_ROM  [file join $SCRIPT_DIR "snow_bros.nes"]

set GAME_BIN_ADDR  0x10000000   ;# RISC-V InfoNES executable
set GAME_ROM_ADDR  0x10800000   ;# NES ROM (must match infones_nucleusrv.cpp)

puts ""
puts "##############################################################"
puts "#     NucleusRV Snow Bros  --  Zybo Z7-10 Boot Script        #"
puts "##############################################################"
puts "  Script dir : $SCRIPT_DIR"
puts ""

foreach f [list $BIT_FILE $PS7_INIT $GAME_BIN $GAME_ROM] {
    if {![file exists $f]} {
        puts "ERROR: Missing file: $f"
        return
    }
}

puts "\[1/6\] Connecting to hardware..."
connect
after 500

# Tip: put SW3 UP before this step to keep the RISC-V core in reset while
# DDR3 is brought up and the game is loaded.
puts "\[2/6\] Programming FPGA bitstream..."
targets -set -filter {name =~ "xc7z010*"}
fpga $BIT_FILE
after 1000

puts "\[3/6\] Initializing PS7 (DDR3 + clocks)..."
targets -set -filter {name =~ "ARM*#0"}
configparams force-mem-accesses 1
source $PS7_INIT
ps7_init

puts "\[4/6\] Enabling PS-PL level shifters..."
ps7_post_config

puts "\[5/6\] Loading snowbros.bin into DDR3 at 0x10000000 ..."
dow -data $GAME_BIN $GAME_BIN_ADDR
after 500
set sentinel_hex [lindex [mrd $GAME_BIN_ADDR] end]
if {[string equal -nocase $sentinel_hex "00000013"]} {
    puts "       snowbros.bin OK -- sentinel 0x00000013 (nop) confirmed."
} else {
    puts "  *** WARNING: Value at 0x10000000 = $sentinel_hex (expected 00000013)"
}

puts "\[6/6\] Loading snow_bros.nes into DDR3 at 0x10800000 ..."
dow -data $GAME_ROM $GAME_ROM_ADDR
after 500
# iNES magic "NES\x1a" = little-endian 0x1A53454E
set magic_hex [lindex [mrd $GAME_ROM_ADDR] end]
if {[string equal -nocase $magic_hex "1A53454E"]} {
    puts "       snow_bros.nes OK -- iNES header confirmed."
} else {
    puts "  *** WARNING: ROM magic = $magic_hex (expected 1A53454E)"
}

puts ""
puts "##############################################################"
puts "#  READY!  Flip SW3 UP then DOWN to reset and start.          #"
puts "#                                                            #"
puts "#   BTN0 = Left     BTN1 = Right                             #"
puts "#   BTN2 = Jump (A) BTN3 = Shoot (B)                         #"
puts "#   SW0  = Start    SW1  = Select   SW2 = Up                 #"
puts "#   SW3  = Reset (up = held in reset)                        #"
puts "#                                                            #"
puts "#  Console log (no UART needed):                             #"
puts "#     xsdb% source $SCRIPT_DIR/game_log.tcl"
puts "##############################################################"
