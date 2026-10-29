#!/usr/bin/env bash
# Builds the SoC + behavioral DDR simulation: sim/ddr/obj/tb_ddr_boot
set -e
cd "$(dirname "$0")/../.."
H="VGA/HDMI Code Files"
verilator --cc --exe --build -O2 -j 8 --Mdir sim/ddr/obj --top-module nucleusrv_soc_top \
  -Wno-fatal -Wno-lint -Wno-style --public-flat-rw --savable \
  rtl/nucleusrv_soc_top.v rtl/Core.v rtl/bus_interconnect.v rtl/uart_timer_peripheral.v \
  rtl/uart_tx.v rtl/uart_rx.v rtl/doom_framebuffer_hdmi.v rtl/icache.v rtl/dcache.v rtl/axi4_line_master.v \
  "$H/hdmi_tx.v" "$H/tmds_encoder.v" "$H/zybo_pll.v" sim/ddr/zynq_soc_wrapper_sim.v \
  "$PWD/sim/ddr/tb_ddr_boot.cpp" -o tb_ddr_boot
