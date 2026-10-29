current_dir := ${CURDIR}

ifeq ($(TARGET),zybo)
  TOP := zybo_hdmi_top
  XDC := ${current_dir}/zybo.xdc
else ifeq ($(TARGET),zybo_z7)
  TOP := zybo_hdmi_top
  XDC := ${current_dir}/zybo_z7.xdc
else ifeq ($(TARGET),arty_35)
  TOP := vga
  XDC := ${current_dir}/arty.xdc
else ifeq ($(TARGET),arty_100)
  TOP := vga
  XDC := ${current_dir}/arty.xdc
else ifeq ($(TARGET),nexys4ddr)
  TOP := vga
  XDC := ${current_dir}/nexys4ddr.xdc
else ifeq ($(TARGET),nexys_video)
  TOP := vga
  XDC := ${current_dir}/nexys_video.xdc
else ifeq ($(TARGET),basys3)
  TOP := vga
  XDC := ${current_dir}/basys3.xdc
else
  # Default to zybo HDMI top
  TARGET ?= zybo
  TOP := zybo_hdmi_top
  XDC := ${current_dir}/zybo.xdc
endif

SOURCES := $(wildcard ${current_dir}/*.v)

build:
	f4pga -vv build --flow ./flow.json

-include ${current_dir}/../../common/common.mk
