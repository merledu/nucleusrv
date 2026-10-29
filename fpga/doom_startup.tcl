########################################################################
# NucleusRV DOOM Startup Script  --  Digilent Zybo Z7-10
# Compatible with XSDB 2018.2+
#
# PORTABLE: All paths are relative to this script's own directory.
# Copy the entire "deploy" folder to the lab PC and run from xsdb:
#
#   xsdb% source /path/to/deploy/doom_startup.tcl
########################################################################

# --- Resolve script directory (works from any working dir) ------------
set SCRIPT_DIR [file dirname [file normalize [info script]]]

# --- File Paths (all relative to SCRIPT_DIR) --------------------------
set BIT_FILE  [file join $SCRIPT_DIR "nucleusrv_doom_zybo_z7.bit"]
set PS7_INIT  [file join $SCRIPT_DIR "ps7_init.tcl"]
set DOOM_BIN  [file join $SCRIPT_DIR "doom.bin"]
set DOOM_WAD  [file join $SCRIPT_DIR "DOOM1.WAD"]

# --- DDR3 Memory Map (must match doomgeneric_nucleusrv.c) -------------
set DOOM_BIN_ADDR  0x10000000   ;# RISC-V DOOM executable
set DOOM_WAD_ADDR  0x10800000   ;# DOOM1.WAD (memory-mapped, 4.2 MB)

puts ""
puts "##############################################################"
puts "#        NucleusRV DOOM  --  Zybo Z7-10 Boot Script         #"
puts "##############################################################"
puts "  Script dir : $SCRIPT_DIR"
puts "  Bitstream  : $BIT_FILE"
puts "  DOOM bin   : $DOOM_BIN"
puts "  DOOM WAD   : $DOOM_WAD"
puts "  ps7_init   : $PS7_INIT"
puts ""

# Sanity check — abort early if any file is missing
foreach f [list $BIT_FILE $PS7_INIT $DOOM_BIN $DOOM_WAD] {
    if {![file exists $f]} {
        puts "ERROR: Missing file: $f"
        puts "       Copy all deploy files to the same folder as this script."
        return
    }
}
puts "  All files present. Starting boot sequence..."
puts ""

# ======================================================================
# STEP 1  --  Connect to Zybo Z7 via JTAG
# ======================================================================
puts "\[1/6\] Connecting to hardware..."
connect
after 500

# ======================================================================
# STEP 2  --  Program FPGA bitstream
#             PL is held in reset here — RISC-V is NOT executing yet
# ======================================================================
puts "\[2/6\] Programming FPGA bitstream..."
targets -set -filter {name =~ "xc7z010*"}
fpga $BIT_FILE
after 1000
puts "       Bitstream programmed OK."

# ======================================================================
# STEP 3  --  Initialize PS7  (DDR3, clocks, MIO)
#             *** MUST come BEFORE ps7_post_config ***
#             Without this step DDR3 is NOT initialized and all AXI
#             reads to 0x10000000 will stall the HP0 FIFO permanently.
# ======================================================================
puts "\[3/6\] Initializing PS7 (DDR3 + clocks)..."
targets -set -filter {name =~ "ARM*#0"}
configparams force-mem-accesses 1
source $PS7_INIT
ps7_init
puts "       ps7_init done — DDR3 controller is up."

# ======================================================================
# STEP 4  --  Enable PS-PL level shifters
#             *** MUST come AFTER ps7_init ***
#             Without this the AXI HP0 bus is not connected to PL.
# ======================================================================
puts "\[4/6\] Enabling PS-PL level shifters..."
ps7_post_config
puts "       ps7_post_config done — AXI HP0 is now live."

# ======================================================================
# STEP 5  --  Load DOOM binary at 0x10000000
#
#             The BRAM bootloader polls address 0x10000000 for the
#             value 0x00000013 (nop instruction) before jumping.
#             Load the binary NOW so it is ready when BTN0 is pressed.
# ======================================================================
puts "\[5/6\] Loading doom.bin into DDR3 at 0x10000000 ..."
# dow -data works in XSDB 2018.2 (mwr -bin -file requires newer XSDB)
dow -data $DOOM_BIN_ADDR -bin $DOOM_BIN
after 500

# Verify sentinel: first word of doom.bin must be 0x00000013 (nop)
set raw_sentinel [mrd $DOOM_BIN_ADDR]
# mrd returns a string like "10000000:   00000013" — extract the hex value
set sentinel_hex [lindex $raw_sentinel end]
if {[string equal -nocase $sentinel_hex "00000013"]} {
    puts "       doom.bin OK -- sentinel 0x00000013 (nop) confirmed."
} else {
    puts "  *** WARNING: Value at 0x10000000 = $sentinel_hex"
    puts "  *** Expected 00000013. Binary may not have loaded correctly."
}

# ======================================================================
# STEP 6  --  Load DOOM1.WAD at 0x10800000
#
#             DOOM reads the WAD directly from DDR3 via memory map.
#             Address is hard-coded in doomgeneric_nucleusrv.c:
#               #define WAD_DDR3_ADDR  ((byte*)0x10800000)
# ======================================================================
puts "\[6/6\] Loading DOOM1.WAD into DDR3 at 0x10800000 ..."
dow -data $DOOM_WAD_ADDR -bin $DOOM_WAD
after 500

# Verify IWAD magic: first 4 bytes = "IWAD" = little-endian 0x44415749
set raw_magic [mrd $DOOM_WAD_ADDR]
set magic_hex [lindex $raw_magic end]
if {[string equal -nocase $magic_hex "44415749"]} {
    puts "       DOOM1.WAD OK -- IWAD magic confirmed."
} else {
    puts "  *** WARNING: WAD magic = $magic_hex"
    puts "  *** Expected 44415749 ('IWAD'). WAD file may be corrupt or wrong path."
}

# ======================================================================
# READY
# ======================================================================
puts ""
puts "##############################################################"
puts "#                                                            #"
puts "#   READY!  Press BTN0 on the Zybo Z7 to start DOOM.       #"
puts "#                                                            #"
puts "#   Expected HDMI sequence after BTN0:                      #"
puts "#     GREEN  bar  =  Bootloader started, polling DDR        #"
puts "#     YELLOW bar  =  Sentinel found, loading DOOM           #"
puts "#     Screen clears + DOOM title = SUCCESS                  #"
puts "#                                                            #"
puts "#   UART debug output: J12 connector, 115200 8N1            #"
puts "#     picocom -b 115200 /dev/ttyUSBx                        #"
puts "#                                                            #"
puts "##############################################################"
