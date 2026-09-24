## NucleusRV — Arty A7-100T Rev D/E (matches Digilent master XDC pin-for-pin)
## Top.v port names must match get_ports { ... } below exactly.

## Clock (master: CLK100MHZ @ E3)
set_property -dict { PACKAGE_PIN E3    IOSTANDARD LVCMOS33 } [get_ports { CLK100MHZ }]
create_clock -add -name sys_clk_pin -period 10.000 -waveform {0.000 5.000} [get_ports { CLK100MHZ }]

## Switches (master: sw[0]=A8, sw[1]=C11 → Top uses sw_run, sw_step)
set_property -dict { PACKAGE_PIN A8    IOSTANDARD LVCMOS33 } [get_ports { sw_run }]
set_property -dict { PACKAGE_PIN C11   IOSTANDARD LVCMOS33 } [get_ports { sw_step }]
set_property PULLDOWN true [get_ports sw_run]
set_property PULLDOWN true [get_ports sw_step]

## Four green LEDs (master: led[0..3] @ H5,J5,T9,T10 — schematic Sch=led[4..7])
## Board silkscreen: LD4, LD5, LD6, LD7
set_property -dict { PACKAGE_PIN H5    IOSTANDARD LVCMOS33 } [get_ports { g_ld4 }]
set_property -dict { PACKAGE_PIN J5    IOSTANDARD LVCMOS33 } [get_ports { g_ld5 }]
set_property -dict { PACKAGE_PIN T9    IOSTANDARD LVCMOS33 } [get_ports { g_ld6 }]
set_property -dict { PACKAGE_PIN T10   IOSTANDARD LVCMOS33 } [get_ports { g_ld7 }]

## RGB LEDs (master: led0..led3 r/g/b — Top drives all low = off)
set_property -dict { PACKAGE_PIN E1    IOSTANDARD LVCMOS33 } [get_ports { rgb0_b }]
set_property -dict { PACKAGE_PIN F6    IOSTANDARD LVCMOS33 } [get_ports { rgb0_g }]
set_property -dict { PACKAGE_PIN G6    IOSTANDARD LVCMOS33 } [get_ports { rgb0_r }]
set_property -dict { PACKAGE_PIN G4    IOSTANDARD LVCMOS33 } [get_ports { rgb1_b }]
set_property -dict { PACKAGE_PIN J4    IOSTANDARD LVCMOS33 } [get_ports { rgb1_g }]
set_property -dict { PACKAGE_PIN G3    IOSTANDARD LVCMOS33 } [get_ports { rgb1_r }]
set_property -dict { PACKAGE_PIN H4    IOSTANDARD LVCMOS33 } [get_ports { rgb2_b }]
set_property -dict { PACKAGE_PIN J2    IOSTANDARD LVCMOS33 } [get_ports { rgb2_g }]
set_property -dict { PACKAGE_PIN J3    IOSTANDARD LVCMOS33 } [get_ports { rgb2_r }]
set_property -dict { PACKAGE_PIN K2    IOSTANDARD LVCMOS33 } [get_ports { rgb3_b }]
set_property -dict { PACKAGE_PIN H6    IOSTANDARD LVCMOS33 } [get_ports { rgb3_g }]
set_property -dict { PACKAGE_PIN K1    IOSTANDARD LVCMOS33 } [get_ports { rgb3_r }]
