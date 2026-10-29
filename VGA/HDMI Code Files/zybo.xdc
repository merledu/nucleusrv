## Digilent Zybo (Rev B) Master Constraints for HDMI Output
## Target Board: Digilent Zybo (XC7Z010CLG400-1)

## Clock signal (125 MHz onboard oscillator)
set_property -dict { PACKAGE_PIN L16   IOSTANDARD LVCMOS33 } [get_ports { clk }]; #IO_L11P_T1_SRCC_35 Sch=sysclk
create_clock -add -name sys_clk_pin -period 8.00 -waveform {0 4} [get_ports { clk }];

## Buttons (Reset on BTN0)
set_property -dict { PACKAGE_PIN R18   IOSTANDARD LVCMOS33 } [get_ports { btn_rst }]; #IO_L20N_T3_34 Sch=BTN0

## LEDs
set_property -dict { PACKAGE_PIN M14   IOSTANDARD LVCMOS33 } [get_ports { led[0] }]; #IO_L23P_T3_35 Sch=LED0 (PLL Locked)
set_property -dict { PACKAGE_PIN M15   IOSTANDARD LVCMOS33 } [get_ports { led[1] }]; #IO_L23N_T3_35 Sch=LED1 (Heartbeat)
set_property -dict { PACKAGE_PIN G14   IOSTANDARD LVCMOS33 } [get_ports { led[2] }]; #IO_0_35       Sch=LED2 (VSync)
set_property -dict { PACKAGE_PIN D18   IOSTANDARD LVCMOS33 } [get_ports { led[3] }]; #IO_L3N_T0_DQS_AD1N_35 Sch=LED3 (DE)

## HDMI TX Signals
set_property -dict { PACKAGE_PIN H16   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_p }]; #IO_L13P_T2_MRCC_35 Sch=HDMI_CLK_P
set_property -dict { PACKAGE_PIN H17   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_clk_n }]; #IO_L13N_T2_MRCC_35 Sch=HDMI_CLK_N
set_property -dict { PACKAGE_PIN D19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[0] }];  #IO_L4P_T0_35 Sch=HDMI_D0_P (Blue)
set_property -dict { PACKAGE_PIN D20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[0] }];  #IO_L4N_T0_35 Sch=HDMI_D0_N
set_property -dict { PACKAGE_PIN C20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[1] }];  #IO_L1P_T0_AD0P_35 Sch=HDMI_D1_P (Green)
set_property -dict { PACKAGE_PIN B20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[1] }];  #IO_L1N_T0_AD0N_35 Sch=HDMI_D1_N
set_property -dict { PACKAGE_PIN B19   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_p[2] }];  #IO_L2P_T0_AD8P_35 Sch=HDMI_D2_P (Red)
set_property -dict { PACKAGE_PIN A20   IOSTANDARD TMDS_33 } [get_ports { hdmi_tx_n[2] }];  #IO_L2N_T0_AD8N_35 Sch=HDMI_D2_N

## HDMI TX Output Enable (Required on Zybo Rev B to power HDMI buffer)
set_property -dict { PACKAGE_PIN F17   IOSTANDARD LVCMOS33 } [get_ports { hdmi_out_en }];   #IO_L6N_T0_VREF_35 Sch=HDMI_OUT_EN
