#!/usr/bin/env bash
set -e
if [ -f "/opt/vivado_2018.2/settings64.sh" ]; then
    source /opt/vivado_2018.2/settings64.sh
fi
vivado -mode batch -source fpga/flash.tcl
