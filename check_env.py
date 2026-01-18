import subprocess
import sys

def check_toolchain():
    tools = ["riscv64-unknown-elf-gcc", "verilator", "sbt"]
    print("?? Checking MERL Development Environment...")
    for tool in tools:
        try:
            subprocess.check_output([tool, "--version"], stderr=subprocess.STDOUT)
            print(f"? {tool} is installed.")
        except Exception:
            print(f"? {tool} NOT found. Please install it to build NucleusRV.")

if __name__ == "__main__":
    check_toolchain()
