## Digilent Zybo Z7 Master Constraints for HDMI Output
## Target Board: Digilent Zybo Z7-10 / Zybo Z7-20 (XC7Z010CLG400-1 / XC7Z020CLG400-1)

## Clock signal (125 MHz onboard oscillator on K17)
set_property -dict { PACKAGE_PIN K17   IOSTANDARD LVCMOS33 } [get_ports { clk }]; #IO_L12P_T1_MRCC_35 Sch=sysclk
create_clock -add -name sys_clk_pin -period 8.00 -waveform {0 4} [get_ports { clk }];

## Buttons (Reset on BTN0)
set_property -dict { PACKAGE_PIN K18   IOSTANDARD LVCMOS33 } [get_ports { btn_rst }]; #IO_L12N_T1_MRCC_35 Sch=btn[0]

## LEDs
set_property -dict { PACKAGE_PIN M14   IOSTANDARD LVCMOS33 } [get_ports { led[0] }]; #IO_L23P_T3_35 Sch=led[0] (PLL Locked)
set_property -dict { PACKAGE_PIN M15   IOSTANDARD LVCMOS33 } [get_ports { led[1] }]; #IO_L23N_T3_35 Sch=led[1] (Heartbeat)
set_property -dict { PACKAGE_PIN G14   IOSTANDARD LVCMOS33 } [get_ports { led[2] }]; #IO_0_35       Sch=led[2] (VSync)
set_property -dict { PACKAGE_PIN D18   IOSTANDARD LVCMOS33 } [get_ports { led[3] }]; #IO_L3N_T0_DQS_AD1N_35 Sch=led[3] (DE)

## HDMI TX Signals
set_property -dict { PACKAGE_PIN H16   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_p }]; #IO_L13P_T2_MRCC_35 Sch=hdmi_tx_clk_p
set_property -dict { PACKAGE_PIN H17   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_n }]; #IO_L13N_T2_MRCC_35 Sch=hdmi_tx_clk_n
set_property -dict { PACKAGE_PIN D19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[0] }];  #IO_L4P_T0_35 Sch=hdmi_tx_p[0] (Blue)
set_property -dict { PACKAGE_PIN D20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[0] }];  #IO_L4N_T0_35 Sch=hdmi_tx_n[0]
set_property -dict { PACKAGE_PIN C20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[1] }];  #IO_L1P_T0_AD0P_35 Sch=hdmi_tx_p[1] (Green)
set_property -dict { PACKAGE_PIN B20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[1] }];  #IO_L1N_T0_AD0N_35 Sch=hdmi_tx_n[1]
set_property -dict { PACKAGE_PIN B19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[2] }];  #IO_L2P_T0_AD8P_35 Sch=hdmi_tx_p[2] (Red)
set_property -dict { PACKAGE_PIN A20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[2] }];  #IO_L2N_T0_AD8N_35 Sch=hdmi_tx_n[2]
