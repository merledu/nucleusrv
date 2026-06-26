Install NucleusRV Dependencies and Toolchain
============================================

To build and simulate NucleusRV, you need to install several tools on your Linux system.

Install Verilator
-----------------

Verilator is required for simulation:

.. code-block:: bash

   sudo apt-get install -y git help2man perl python3 make autoconf g++ flex bison ccache
   sudo apt-get install -y libgoogle-perftools-dev numactl perl-doc libfl2 libfl-dev zlib1g zlib1g-dev

   git clone https://github.com/verilator/verilator.git
   cd verilator
   git checkout stable
   autoconf
   ./configure
   make -j$(nproc)
   sudo make install

Install RISC-V GNU Toolchain
----------------------------

Install the toolchain for RV32:

.. code-block:: bash

   git clone https://github.com/riscv/riscv-gnu-toolchain
   cd riscv-gnu-toolchain
   ./configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32
   make -j$(nproc)

Add the toolchain to your ``PATH``:

.. code-block:: bash

   export PATH=/opt/riscv/bin:$PATH

Install Java, sbt, and Scala
----------------------------

NucleusRV is written in Chisel (Scala):

.. code-block:: bash

   sudo apt-get install -y default-jdk
   # Install sbt via official repositories
   # ... (follow sbt installation instructions for your distro)

Verify Your Setup
-----------------

.. code-block:: bash

   verilator --version
   riscv32-unknown-elf-gcc --version
   java -version
   sbt --version
