# Test script to create Zynq PS7 + AXI HP0 Block Design for Zybo Z7-10
set PART_NAME "xc7z010clg400-1"
set BOARD_PART "digilentinc.com:zybo-z7-10:part0:1.1"
set PROJ_DIR "fpga/zynq_bd_test"

file mkdir $PROJ_DIR
create_project -force zynq_test $PROJ_DIR -part $PART_NAME
set_property board_part $BOARD_PART [current_project]

create_bd_design "zynq_soc"

# 1. Instantiate PS7 with Zybo Z7-10 preset
create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 ps7
apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "FIXED_IO, DDR" apply_board_preset "1" Master "Disable" Slave "Disable"} [get_bd_cells ps7]

# 2. Enable S_AXI_HP0 (32-bit) and disable unused M_AXI_GP0
set_property -dict [list \
    CONFIG.PCW_USE_M_AXI_GP0 {0} \
    CONFIG.PCW_USE_S_AXI_HP0 {1} \
    CONFIG.PCW_S_AXI_HP0_DATA_WIDTH {32} \
] [get_bd_cells ps7]

# 3. Add AXI Protocol Converter / Interconnect (2 Slaves: S00=IMEM, S01=DMEM)
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_mem_intercon
set_property -dict [list CONFIG.NUM_MI {1} CONFIG.NUM_SI {2}] [get_bd_cells axi_mem_intercon]

# 4. Connect Interconnect to PS7 HP0
connect_bd_intf_net [get_bd_intf_pins axi_mem_intercon/M00_AXI] [get_bd_intf_pins ps7/S_AXI_HP0]

# 5. Make S00_AXI (IMEM) and S01_AXI (DMEM) external ports
create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_imem
set_property CONFIG.PROTOCOL AXI4LITE [get_bd_intf_ports s_axi_imem]
connect_bd_intf_net [get_bd_intf_pins axi_mem_intercon/S00_AXI] [get_bd_intf_ports s_axi_imem]

create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_dmem
set_property CONFIG.PROTOCOL AXI4LITE [get_bd_intf_ports s_axi_dmem]
connect_bd_intf_net [get_bd_intf_pins axi_mem_intercon/S01_AXI] [get_bd_intf_ports s_axi_dmem]

create_bd_port -dir I -type clk clk_25mhz
set_property CONFIG.ASSOCIATED_RESET reset_n [get_bd_ports clk_25mhz]
set_property CONFIG.ASSOCIATED_BUSIF s_axi_imem:s_axi_dmem [get_bd_ports clk_25mhz]
connect_bd_net [get_bd_ports clk_25mhz] [get_bd_pins ps7/S_AXI_HP0_ACLK]
connect_bd_net [get_bd_ports clk_25mhz] [get_bd_pins axi_mem_intercon/ACLK]
connect_bd_net [get_bd_ports clk_25mhz] [get_bd_pins axi_mem_intercon/S00_ACLK]
connect_bd_net [get_bd_ports clk_25mhz] [get_bd_pins axi_mem_intercon/S01_ACLK]
connect_bd_net [get_bd_ports clk_25mhz] [get_bd_pins axi_mem_intercon/M00_ACLK]

create_bd_port -dir I -type rst reset_n
connect_bd_net [get_bd_ports reset_n] [get_bd_pins axi_mem_intercon/ARESETN]
connect_bd_net [get_bd_ports reset_n] [get_bd_pins axi_mem_intercon/S00_ARESETN]
connect_bd_net [get_bd_ports reset_n] [get_bd_pins axi_mem_intercon/S01_ARESETN]
connect_bd_net [get_bd_ports reset_n] [get_bd_pins axi_mem_intercon/M00_ARESETN]

# 6. Assign Addresses (512 MB DDR3 for both IMEM and DMEM)
assign_bd_address [get_bd_addr_segs {ps7/S_AXI_HP0/HP0_DDR_LOWOCM}]

# 7. Validate and Generate Block Design
validate_bd_design
save_bd_design

puts "=========================================================="
puts "  BLOCK DESIGN CREATED AND VALIDATED SUCCESSFULLY!"
puts "=========================================================="

# 8. Generate HDL wrapper
make_wrapper -files [get_files [get_property FILE_NAME [current_bd_design]]] -top
add_files -norecurse $PROJ_DIR/zynq_test.srcs/sources_1/bd/zynq_soc/hdl/zynq_soc_wrapper.v
update_compile_order -fileset sources_1

# 9. Generate ps7_init files for JTAG and standalone initialization
generate_target all [get_files [get_property FILE_NAME [current_bd_design]]]

puts "=========================================================="
puts "  ZYNQ PS7 INITIALIZATION & TARGETS GENERATED!"
puts "=========================================================="
exit 0
