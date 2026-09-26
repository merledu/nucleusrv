# ============================================================================
# File: fpga/zybo_hdmi.xdc
# Description: Master XDC constraints file for Zybo Z7 NucleusRV Pong system.
# ============================================================================

## 125 MHz onboard oscillator (Zybo Z7-10: pin K17 / H16)
set_property -dict { PACKAGE_PIN K17   IOSTANDARD LVCMOS33 } [get_ports { clk }];
create_clock -add -name sys_clk_pin -period 8.000 -waveform {0 4.000} [get_ports { clk }];

## Reset button (BTN0)
set_property -dict { PACKAGE_PIN K18   IOSTANDARD LVCMOS33 } [get_ports { btn_rst }];

## HDMI TX Clock (TMDS)
set_property -dict { PACKAGE_PIN H16   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_p }];
set_property -dict { PACKAGE_PIN H17   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_n }];

## HDMI TX Data (Blue - Channel 0)
set_property -dict { PACKAGE_PIN D19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[0] }];
set_property -dict { PACKAGE_PIN D20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[0] }];

## HDMI TX Data (Green - Channel 1)
set_property -dict { PACKAGE_PIN C20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[1] }];
set_property -dict { PACKAGE_PIN B20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[1] }];

## HDMI TX Data (Red - Channel 2)
set_property -dict { PACKAGE_PIN B19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[2] }];
set_property -dict { PACKAGE_PIN A20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[2] }];

## HDMI Output Enable (buffer power)
set_property -dict { PACKAGE_PIN E18   IOSTANDARD LVCMOS33 } [get_ports { hdmi_out_en }];

## Diagnostic LEDs (Bank 34)
set_property -dict { PACKAGE_PIN M14   IOSTANDARD LVCMOS33 } [get_ports { led[0] }];
set_property -dict { PACKAGE_PIN M15   IOSTANDARD LVCMOS33 } [get_ports { led[1] }];
set_property -dict { PACKAGE_PIN G14   IOSTANDARD LVCMOS33 } [get_ports { led[2] }];
set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { led[3] }];

## Paddle Control Buttons - external push buttons on Pmod Header JE
## Wire each button between the signal pin and Pmod 3.3V (active-high).
## Internal pulldown holds the pin LOW when the button is not pressed.
set_property -dict { PACKAGE_PIN V12   IOSTANDARD LVCMOS33   PULLTYPE PULLDOWN } [get_ports { btn_up }]; # je[1]
set_property -dict { PACKAGE_PIN W16   IOSTANDARD LVCMOS33   PULLTYPE PULLDOWN } [get_ports { btn_dn }]; # je[2]