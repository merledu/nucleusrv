# Unified XSDB Runner Script for Full DOOM on NucleusRV (Digilent Zybo Z7-10)
# Usage (run from nucleusrv/ repo root):
#   xsdb fpga/run_doom.tcl
#
# Steps performed:
#   1. Connects to Zybo Z7 via JTAG
#   2. Resets ARM processor only (preserves PL/DDR state for re-runs)
#   3. Initializes Zynq PS7 clocks and 512 MB DDR3 SDRAM (ps7_init)
#   4. Loads doom.bin  -> DDR3 @ 0x10000000  (492 KB)
#   5. Loads DOOM1.WAD -> DDR3 @ 0x10800000  (4.0 MB)
#   6. Programs PL with NucleusRV SoC bitstream
#      -> NucleusRV boot ROM jumps to 0x10000000 automatically

puts "=========================================================="
puts "  Connecting to Digilent Zybo Z7 via JTAG..."
puts "=========================================================="
connect

# 1. Target ARM Core 0 for PS7 initialization
targets -set -filter {name =~ "ARM*#0"}
rst -processor

# 2. Run ps7_init to bring up DDR3 controller and clocks
puts "Initializing Zynq PS7 (DDR3 controller, clocks)..."
source fpga/bd/ps7_init.tcl
ps7_init
puts "\[PASS\] Zynq PS7 & 512 MB DDR3 Controller Initialized."

# 3. Download DOOM executable binary and WAD to DDR3
puts "Loading doom.bin into DDR3 @ 0x10000000 (492 KB)..."
dow -data doom/doom.bin 0x10000000
puts "\[PASS\] DOOM Binary Loaded."

puts "Loading DOOM1.WAD into DDR3 @ 0x10800000 (4.0 MB)..."
dow -data doom/DOOM1.WAD 0x10800000
puts "\[PASS\] DOOM1.WAD Loaded (4196020 bytes)."

# 4. Program FPGA PL with NucleusRV SoC bitstream
targets -set -filter {name =~ "xc7z010*"}
puts "Programming FPGA with nucleusrv_doom_zybo_z7.bit..."
fpga fpga/build/nucleusrv_doom_zybo_z7.bit
puts "\[PASS\] FPGA Bitstream Programmed."

# 5. CRITICAL: Enable PS-PL Level Shifters AFTER FPGA is programmed
#    Programming the FPGA resets LVL_SHFTR_EN to 0. ps7_post_config
#    MUST be called after fpga to connect PL AXI to PS DDR3!
targets -set -filter {name =~ "ARM*#0"}
puts "Enabling PS-PL Level Shifters (ps7_post_config)..."
ps7_post_config
puts "\[PASS\] PS-PL Level Shifters Active."

puts ""
puts "=========================================================="
puts "  FULL DOOM IS LOADED!"
puts "  >>> Press BTN0 on the Zybo Z7 board once to reset & run! <<<"
puts "  - BTN0 = Hardware Reset (K18)"
puts "  - BTN1 = Fire (P16)"
puts "  - BTN2 = Use / Open Door (K19)"
puts "  - BTN3 = Move Forward (Y16)"
puts "=========================================================="
exit

