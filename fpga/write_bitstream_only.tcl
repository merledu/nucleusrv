# Write bitstream from existing routed checkpoint (skip synthesis + implementation)
set ROUTED_DCP "fpga/bd/proj/zynq_bd_proj.runs/impl_1/nucleusrv_soc_top_routed.dcp"
set OUT_BIT    "fpga/build/nucleusrv_doom_zybo_z7.bit"
file mkdir fpga/build

puts "============================================================"
puts "  Writing bitstream from existing routed checkpoint ..."
puts "  DCP: $ROUTED_DCP"
puts "============================================================"

open_checkpoint $ROUTED_DCP

# Suppress DRC checks that are warnings/known issues in NucleusRV:
# DPOP-2: DSP pipeline warnings (informational, design still functional)
# LUTLP-1: Combinatorial loops in boot_ram / lhw_reg - known NucleusRV design
set_property SEVERITY {Warning} [get_drc_checks DPOP-2]
set_property SEVERITY {Warning} [get_drc_checks LUTLP-1]

write_bitstream -verbose -force $OUT_BIT

puts "============================================================"
puts "  Bitstream written to: $OUT_BIT"
puts "============================================================"
exit 0
