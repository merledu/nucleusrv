## Digilent Zybo Z7-10 SoC Constraints for NucleusRV DOOM
## Target: XC7Z010CLG400-1

## Clock signal (125 MHz onboard oscillator on K17)
set_property -dict { PACKAGE_PIN K17   IOSTANDARD LVCMOS33 } [get_ports { clk }];
create_clock -add -name sys_clk_pin -period 8.00 -waveform {0 4} [get_ports { clk }];

## Reset on slide switch SW3 (up = held in reset)
set_property -dict { PACKAGE_PIN T16   IOSTANDARD LVCMOS33 } [get_ports { btn_rst }];

## Push Buttons (BTN0..BTN3) for interactive input
set_property -dict { PACKAGE_PIN P16   IOSTANDARD LVCMOS33 } [get_ports { btn[0] }]; # BTN1
set_property -dict { PACKAGE_PIN K19   IOSTANDARD LVCMOS33 } [get_ports { btn[1] }]; # BTN2
set_property -dict { PACKAGE_PIN Y16   IOSTANDARD LVCMOS33 } [get_ports { btn[2] }]; # BTN3
set_property -dict { PACKAGE_PIN K18   IOSTANDARD LVCMOS33 } [get_ports { btn[3] }]; # BTN0

## Slide Switches (SW0, SW1, SW2); SW3 is the reset above
set_property -dict { PACKAGE_PIN G15   IOSTANDARD LVCMOS33 } [get_ports { sw[0] }]; # SW0
set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { sw[1] }]; # SW1
set_property -dict { PACKAGE_PIN W13   IOSTANDARD LVCMOS33 } [get_ports { sw[2] }]; # SW2

## Diagnostic LEDs
set_property -dict { PACKAGE_PIN M14   IOSTANDARD LVCMOS33 } [get_ports { led[0] }]; # PLL Locked
set_property -dict { PACKAGE_PIN M15   IOSTANDARD LVCMOS33 } [get_ports { led[1] }]; # Heartbeat
set_property -dict { PACKAGE_PIN G14   IOSTANDARD LVCMOS33 } [get_ports { led[2] }]; # CPU Active
set_property -dict { PACKAGE_PIN D18   IOSTANDARD LVCMOS33 } [get_ports { led[3] }]; # UART RX / Button Activity

## HDMI TX Signals (DVI / TMDS Differential Pairs)
set_property -dict { PACKAGE_PIN H16   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_p }];
set_property -dict { PACKAGE_PIN H17   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_n }];
set_property -dict { PACKAGE_PIN D19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[0] }];  # Blue +
set_property -dict { PACKAGE_PIN D20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[0] }];  # Blue -
set_property -dict { PACKAGE_PIN C20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[1] }];  # Green +
set_property -dict { PACKAGE_PIN B20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[1] }];  # Green -
set_property -dict { PACKAGE_PIN B19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[2] }];  # Red +
set_property -dict { PACKAGE_PIN A20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[2] }];  # Red -

## UART Serial Ports on Pmod JE (Terminal Keyboard Input & Output)
## Connect Pmod USBUART or USB-to-UART FTDI cable to Pmod JE:
##   JE Pin 1 (V12) -> TX from FPGA
##   JE Pin 2 (J15) -> RX into FPGA
set_property -dict { PACKAGE_PIN V12   IOSTANDARD LVCMOS33 } [get_ports { uart_txd }];
set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 PULLUP true } [get_ports { uart_rxd }];

## Clock Domain Crossing (CDC) False Path
set_false_path -to [get_pins -hier -filter {NAME =~ *pixclk_sync_reg[0]/D}]


