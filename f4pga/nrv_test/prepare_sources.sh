#!/usr/bin/env bash
# Generate nrv_core.v from Chisel; keep Top.v as the fixed board wrapper.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
NRV_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
HEX_FILE="${NRV_ROOT}/tools/out/program.hex"

echo "NucleusRV root: ${NRV_ROOT}"
echo "F4PGA test dir: ${SCRIPT_DIR}"

source "${HOME}/.bashrc" 2>/dev/null || true
cd "${NRV_ROOT}/tools"
make PROGRAM=fibonacci

cd "${NRV_ROOT}"
sbt "runMain nucleusrv.components.NRVDriver \
  --imem ${HEX_FILE} \
  --dmem ${HEX_FILE} \
  --target-dir ${NRV_ROOT}/fpga_rtl"

sed 's/^module Top(/module NucleusRV(/' "${NRV_ROOT}/fpga_rtl/Top.v" > "${SCRIPT_DIR}/nrv_core.v"
cp "${NRV_ROOT}/src/main/resources/sram.v" "${SCRIPT_DIR}/sram.v"
cp "${NRV_ROOT}/src/main/resources/sram_top.v" "${SCRIPT_DIR}/sram_top.v"

echo ""
echo "Ready:"
echo "  ${SCRIPT_DIR}/Top.v       (board wrapper — do not overwrite)"
echo "  ${SCRIPT_DIR}/nrv_core.v  (generated core, module NucleusRV)"
echo "  ${SCRIPT_DIR}/sram.v"
echo "  ${SCRIPT_DIR}/sram_top.v"
echo ""
echo "Update IFILE path inside nrv_core.v for your PC, then:"
echo "  TARGET=arty_100 make -C ~/f4pga-examples/xc7/nrv_test"
