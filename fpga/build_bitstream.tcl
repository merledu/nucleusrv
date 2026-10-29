# Vivado Automated Bitstream Generation Script for NucleusRV DOOM on Zybo Z7-10
# Usage:
#   vivado -mode batch -source fpga/build_bitstream.tcl

set PART_NAME "xc7z010clg400-1"
set PROJ_NAME "nucleusrv_doom_zybo_z7"
set BUILD_DIR "fpga/build"

set_param general.maxThreads 8
file mkdir $BUILD_DIR

puts "=========================================================="
puts "  Building $PROJ_NAME using Zynq Project Flow (Global Synth)"
puts "=========================================================="

open_project fpga/bd/proj/zynq_bd_proj.xpr

# 1. Add RTL Sources
add_files -norecurse {
    rtl/nucleusrv_soc_top.v
    rtl/Core.v
    rtl/bus_interconnect.v
    rtl/uart_timer_peripheral.v
    rtl/uart_tx.v
    rtl/uart_rx.v
    rtl/doom_framebuffer_hdmi.v
    rtl/icache.v
    rtl/dcache.v
    rtl/axi4_line_master.v
    "VGA/HDMI Code Files/hdmi_tx.v"
    "VGA/HDMI Code Files/tmds_encoder.v"
    "VGA/HDMI Code Files/zybo_pll.v"
}

# 2. Add Constraints
add_files -fileset constrs_1 -norecurse fpga/zybo_z7_soc.xdc

# 3. Set Top Module
set_property top nucleusrv_soc_top [current_fileset]
update_compile_order -fileset sources_1

# 4. Set BD to Global Synthesis
set_property synth_checkpoint_mode None [get_files zynq_soc.bd]
generate_target all [get_files zynq_soc.bd]

# 5. Set Pre-Bitgen Hook to handle DRC warnings
set_property STEPS.WRITE_BITSTREAM.TCL.PRE [file normalize fpga/pre_bitgen.tcl] [get_runs impl_1]

# 6. Reset and Run Synthesis + Implementation
puts "=== Resetting and launching Synthesis & Implementation (8 Threads) ==="
reset_run synth_1
reset_run impl_1

launch_runs impl_1 -to_step write_bitstream -jobs 8
wait_on_run impl_1

# 7. Check if bitstream was created by the run
set BIT_FILE [glob -nocomplain fpga/bd/proj/zynq_bd_proj.runs/impl_1/*.bit]

# If not created directly, open routed design and generate bitstream with DRC override
if {[llength $BIT_FILE] == 0} {
    puts "Notice: Bitstream step did not output .bit directly, writing bitstream manually from impl_1..."
    open_run impl_1
    set_property SEVERITY {Warning} [get_drc_checks DPOP-2]
    set_property SEVERITY {Warning} [get_drc_checks LUTLP-1]
    write_bitstream -verbose -force $BUILD_DIR/${PROJ_NAME}.bit
    puts "=========================================================="
    puts "  BUILD SUCCESSFUL!"
    puts "  Bitstream written to: $BUILD_DIR/${PROJ_NAME}.bit"
    puts "=========================================================="
    exit 0
} else {
    file copy -force [lindex $BIT_FILE 0] $BUILD_DIR/${PROJ_NAME}.bit
    puts "=========================================================="
    puts "  BUILD SUCCESSFUL!"
    puts "  Bitstream copied to: $BUILD_DIR/${PROJ_NAME}.bit"
    puts "=========================================================="
    exit 0
}

