# 🚀 NucleusRV

<p align="center">
  <b>A 5-Stage Pipelined RV32I CPU written in Chisel</b><br>
  Lightweight • Educational • Hackable
</p>

<p align="center">
  <a href="https://github.com/merledu/nucleusrv/stargazers">
    <img src="https://img.shields.io/github/stars/merledu/nucleusrv?style=for-the-badge" />
  </a>
  <a href="https://github.com/merledu/nucleusrv/network/members">
    <img src="https://img.shields.io/github/forks/merledu/nucleusrv?style=for-the-badge" />
  </a>
  <a href="https://github.com/merledu/nucleusrv/issues">
    <img src="https://img.shields.io/github/issues/merledu/nucleusrv?style=for-the-badge" />
  </a>
  <a href="https://gitter.im/merledu/nucleusrv">
    <img src="https://img.shields.io/badge/chat-gitter-brightgreen?style=for-the-badge" />
  </a>
</p>

---

## 📌 Overview

**NucleusRV** is a Chisel-based implementation of a **5-stage pipelined RISC-V processor** supporting the 32-bit base ISA.

It is designed for:

* 🎓 Learning computer architecture
* 🧪 Experimenting with RISC-V microarchitecture
* 🛠 Extending ISA features
* 🔬 Academic research & hobby development

> Current ISA Support: **RV32IMAFC-Zicsr**

---

## 🧠 Architecture

* 5-Stage Pipeline

  * IF — Instruction Fetch
  * ID — Instruction Decode
  * EX — Execute
  * MEM — Memory
  * WB — Writeback
* Written in **Chisel**
* Simulated using **Verilator**
* Supports architectural test execution via **RISCOF**

---

## 🛠 Dependencies

| Tool                                                                    | Purpose                 |
| ----------------------------------------------------------------------- | ----------------------- |
| [`verilator >= 5.002`](https://verilator.org/guide/latest/install.html) | Simulation              |
| [`riscv-gnu-toolchain`](https://github.com/riscv/riscv-gnu-toolchain)   | Building C programs     |
| `sbt`                                                                   | Scala/Chisel build tool |
| `Java 17`                                                               | Required runtime        |

---

## 📥 Getting Started

### 1️⃣ Clone the Repository

```bash
git clone --recurse-submodules https://github.com/merledu/nucleusrv.git
cd nucleusrv
```

---

## ▶ Running RISC-V Assembly

### Generate Verilog

```bash
sbt "nucleusrv.components.NRVDriver \
--imem /path/to/imem.hex \
--dmem /path/to/dmem.hex \
--target-dir /path/to/output"
```

### Build & Run with Verilator

```bash
export NRV_ROOT=$PWD
cd /path/to/output

verilator --cc --exe --build --trace --no-timing \
$NRV_ROOT/tb_Top.cpp Top.v

./obj_dir/VTop
```

📊 Waveforms will be available at:

```
/path/to/output/logs
```

---

## 🧪 Running RISC-V Architectural Tests

Make sure `verilator` and `riscv-gnu-toolchain` are in your `PATH`.

### Setup Python Environment

```bash
python3 -m venv .venv
source .venv/bin/activate

pip install -e riscof/riscv-arch-test/riscv-ctg \
               riscof/riscv-arch-test/riscv-isac

pip install git+https://github.com/riscv/riscof.git
```

### Run Tests

```bash
python3 run_riscv_arch_tests.py
```

---

## 🧾 Building C Programs

1. Navigate to:

```
tools/tests
```

2. Create a new folder and add your `main.c`

3. Build:

```bash
cd tools
make PROGRAM=<your_test_folder_name>
```

4. Generate Verilog using `sbt` as shown earlier.

---

### 🔹 Optional: Direct HEX Execution

Instead of compiling C:

* Write hex instructions directly into:

```
tools/out/program.hex
```

---

# ⚠️ Troubleshooting

## 🔥 If `sbt` Breaks

Sometimes `sbt` cache becomes corrupted.

If you see unexplained build errors:

```bash
rm -rf project/ target/
sbt clean
sbt compile
```

If issues persist:

```bash
rm -rf ~/.ivy2/cache
rm -rf ~/.sbt
```

Then retry.

---

# ✅ Tested Environment (Last Known Working Setup)

If builds fail, verify your versions match below.

## 🛠 SBT

```
Project SBT Version: 1.12.0
Runner SBT Version:  1.12.0
```

---

## ☕ Java

```
OpenJDK 17.0.18
```

⚠️ **Java 25 does NOT work. Use Java 17.**

---

## 🐧 Arch Linux Users

Arch defaults to newer Java versions.
You must switch to Java 17:

```bash
sudo pacman -S jdk17-openjdk
sudo archlinux-java set java-17-openjdk
java -version
```

Ensure it prints:

```
openjdk version "17.x.x"
```

---

# 🤝 Contributing

Contributions are welcome!

1. Fork the repo
2. Create a feature branch
3. Submit a PR

For major changes, please open an issue first.

---

# 💬 Community

Join the discussion:

👉 [https://gitter.im/merledu/nucleusrv](https://gitter.im/merledu/nucleusrv)

---

# ⭐ Support

If this project helped you:

* Star the repo
* Share it
* Build something cool with it