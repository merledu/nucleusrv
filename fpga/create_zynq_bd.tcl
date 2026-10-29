# Automated script to generate the Zynq PS7 + Dual AXI Slave Block Design
set PART_NAME "xc7z010clg400-1"
set BOARD_PART "digilentinc.com:zybo-z7-10:part0:1.1"
set BD_DIR "fpga/bd"

file mkdir $BD_DIR
create_project -force zynq_bd_proj $BD_DIR/proj -part $PART_NAME
set_property board_part $BOARD_PART [current_project]

create_bd_design "zynq_soc"

# 1. Instantiate PS7 with Digilent Zybo Z7-10 board preset
create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 ps7
apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "FIXED_IO, DDR" apply_board_preset "1" Master "Disable" Slave "Disable"} [get_bd_cells ps7]

# 2. Configure PS7: disable unused M_AXI_GP0, enable 32-bit S_AXI_HP0
set_property -dict [list \
    CONFIG.PCW_USE_M_AXI_GP0 {0} \
    CONFIG.PCW_USE_S_AXI_HP0 {1} \
    CONFIG.PCW_S_AXI_HP0_DATA_WIDTH {32} \
] [get_bd_cells ps7]

# 3. Add AXI Interconnect (2 Slaves: S00=IMEM, S01=DMEM -> 1 Master: M00=PS7 HP0)
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_mem_intercon
set_property -dict [list CONFIG.NUM_MI {1} CONFIG.NUM_SI {2}] [get_bd_cells axi_mem_intercon]

# 4. Connect Interconnect Master to PS7 HP0
connect_bd_intf_net [get_bd_intf_pins axi_mem_intercon/M00_AXI] [get_bd_intf_pins ps7/S_AXI_HP0]

# 5. Create External AXI4 Slave Ports for NucleusRV IMEM & DMEM
create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_imem
# Full AXI4 so the caches can refill/write back whole 32-byte lines as bursts
set_property -dict [list CONFIG.PROTOCOL AXI4 CONFIG.DATA_WIDTH 32 CONFIG.ADDR_WIDTH 32 CONFIG.ID_WIDTH 0] [get_bd_intf_ports s_axi_imem]
connect_bd_intf_net [get_bd_intf_pins axi_mem_intercon/S00_AXI] [get_bd_intf_ports s_axi_imem]

create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_dmem
# Full AXI4 so the caches can refill/write back whole 32-byte lines as bursts
set_property -dict [list CONFIG.PROTOCOL AXI4 CONFIG.DATA_WIDTH 32 CONFIG.ADDR_WIDTH 32 CONFIG.ID_WIDTH 0] [get_bd_intf_ports s_axi_dmem]
connect_bd_intf_net [get_bd_intf_pins axi_mem_intercon/S01_AXI] [get_bd_intf_ports s_axi_dmem]

# 6. Clocks & Resets
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

# 7. Map Address Segments (512 MB DDR3 mapped for both IMEM and DMEM)
assign_bd_address [get_bd_addr_segs {ps7/S_AXI_HP0/HP0_DDR_LOWOCM}]

# 8. Validate and Save
validate_bd_design
save_bd_design

# 9. Generate HDL Wrapper
make_wrapper -files [get_files [get_property FILE_NAME [current_bd_design]]] -top
add_files -norecurse $BD_DIR/proj/zynq_bd_proj.srcs/sources_1/bd/zynq_soc/hdl/zynq_soc_wrapper.v
update_compile_order -fileset sources_1

# 10. Generate Targets & ps7_init files
generate_target all [get_files [get_property FILE_NAME [current_bd_design]]]

# Copy key output files to fpga/bd root for direct access
file copy -force $BD_DIR/proj/zynq_bd_proj.srcs/sources_1/bd/zynq_soc/hdl/zynq_soc_wrapper.v $BD_DIR/zynq_soc_wrapper.v
file copy -force $BD_DIR/proj/zynq_bd_proj.srcs/sources_1/bd/zynq_soc/ip/zynq_soc_ps7_0/ps7_init.tcl $BD_DIR/ps7_init.tcl
file copy -force $BD_DIR/proj/zynq_bd_proj.srcs/sources_1/bd/zynq_soc/ip/zynq_soc_ps7_0/ps7_init.h $BD_DIR/ps7_init.h
file copy -force $BD_DIR/proj/zynq_bd_proj.srcs/sources_1/bd/zynq_soc/ip/zynq_soc_ps7_0/ps7_init.c $BD_DIR/ps7_init.c

puts "=========================================================="
puts "  ZYNQ PS7 BLOCK DESIGN AND WRAPPERS READY IN $BD_DIR !"
puts "=========================================================="
exit 0
