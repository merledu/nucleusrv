#!/usr/bin/env python3
"""Map [PCS] samples from tb_ddr_boot output to function names in doom.elf."""
import bisect, glob, subprocess, sys

nm = glob.glob("/tools/riscv/*/bin/riscv32-unknown-elf-nm")[0]
syms = []
for line in subprocess.run([nm, "-n", "doom/doom.elf"], capture_output=True, text=True).stdout.splitlines():
    parts = line.split()
    if len(parts) == 3 and parts[1] in "tTwW":
        syms.append((int(parts[0], 16), parts[2]))
addrs = [a for a, _ in syms]

def name(pc):
    if pc < 0x10000000:
        return "<boot BRAM>"
    i = bisect.bisect_right(addrs, pc) - 1
    return syms[i][1] if i >= 0 else "?"

for line in open(sys.argv[1], errors="replace"):
    if line.startswith("[PCS]"):
        _, cyc, pc, sp = line.split()[:4]
        print(f"{int(cyc):>11}  {pc}  {sp}  {name(int(pc, 16))}")
