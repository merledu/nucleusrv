open_hw
connect_hw_server
set targets [get_hw_targets]
if {[llength $targets] == 0} {
    puts "=========================================================="
    puts "Error: No hardware targets (JTAG cables) detected."
    puts "Please ensure your Zybo Z7 is plugged in and powered on."
    puts "=========================================================="
    exit 1
}
open_hw_target [lindex $targets 0]
set hw_device [lindex [get_hw_devices xc7z010_1] 0]
if {[string length $hw_device] == 0} {
    set hw_device [lindex [get_hw_devices] 0]
}
current_hw_device $hw_device
refresh_hw_device -update_hw_probes false $hw_device
set_property PROGRAM.FILE {fpga/build/nucleusrv_doom_zybo_z7.bit} $hw_device
program_hw_devices $hw_device
puts "=========================================================="
puts "  FPGA PROGRAMMED SUCCESSFULLY!"
puts "=========================================================="
exit 0
