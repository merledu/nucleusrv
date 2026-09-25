#!/usr/bin/env python3
# ============================================================================
# File: sw/pc_pong_controller.py
# Description: PC-side Python script for controlling Zybo Z7 NucleusRV Pong.
#              Captures W/S keys and sends 'w'/'s' characters over USB-UART.
# ============================================================================

import sys
import time
import argparse
import serial
import serial.tools.list_ports

def find_zybo_port():
    ports = serial.tools.list_ports.comports()
    for port in ports:
        if "USB" in port.description or "FTDI" in port.description or "ttyUSB" in port.device or "COM" in port.device:
            return port.device
    return None

def main():
    parser = argparse.ArgumentParser(description="PC Keyboard Controller for NucleusRV Pong")
    parser.add_argument("-p", "--port", type=str, help="Serial port (e.g. /dev/ttyUSB0 or COM3)")
    parser.add_argument("-b", "--baud", type=int, default=115200, help="Baud rate (default: 115200)")
    args = parser.parse_args()

    port_name = args.port if args.port else find_zybo_port()
    if not port_name:
        print("❌ Error: Could not auto-detect Zybo USB-UART port.")
        print("Please specify port manually using: python3 pc_pong_controller.py -p /dev/ttyUSB0")
        sys.exit(1)

    print(f"🔌 Connecting to Zybo UART on {port_name} at {args.baud} baud...")
    try:
        ser = serial.Serial(port_name, args.baud, timeout=0.1)
        print("✅ Connected!")
        print("\n🎮 Pong Controller Active!")
        print("   Press 'W' to move paddle UP")
        print("   Press 'S' to move paddle DOWN")
        print("   Press 'Q' or Ctrl+C to quit\n")
    except Exception as e:
        print(f"❌ Failed to open serial port {port_name}: {e}")
        sys.exit(1)

    try:
        import keyboard
        print("Using global keyboard hook...")
        while True:
            if keyboard.is_pressed('w') or keyboard.is_pressed('W'):
                ser.write(b'w')
                time.sleep(0.03)
            elif keyboard.is_pressed('s') or keyboard.is_pressed('S'):
                ser.write(b's')
                time.sleep(0.03)
            elif keyboard.is_pressed('q') or keyboard.is_pressed('Q'):
                print("Exiting...")
                break
            time.sleep(0.01)

    except ImportError:
        print("Notice: 'keyboard' module not installed (or missing root permissions).")
        print("Falling back to standard terminal input mode. Type 'w' + Enter or 's' + Enter:")
        try:
            import tty
            import termios

            def getch():
                fd = sys.stdin.fileno()
                old_settings = termios.tcgetattr(fd)
                try:
                    tty.setraw(sys.stdin.fileno())
                    ch = sys.stdin.read(1)
                finally:
                    termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
                return ch

            while True:
                char = getch()
                if char.lower() == 'w':
                    ser.write(b'w')
                elif char.lower() == 's':
                    ser.write(b's')
                elif char.lower() == 'q' or ord(char) == 3: # Ctrl+C
                    break
        except Exception:
            # Fallback line input
            while True:
                cmd = input("Command (w/s/q): ").strip().lower()
                if 'w' in cmd:
                    ser.write(b'w')
                elif 's' in cmd:
                    ser.write(b's')
                elif 'q' in cmd:
                    break

    ser.close()
    print("Serial connection closed.")

if __name__ == "__main__":
    main()
