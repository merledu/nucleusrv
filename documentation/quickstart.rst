Get Started with NucleusRV
==========================

Learn how to clone NucleusRV, generate Verilog from Chisel sources, and run your first simulation with Verilator in under 10 minutes.

Clone the Repository
--------------------

Clone the repository with submodules:

.. code-block:: bash

   git clone --recurse-submodules https://github.com/merledu/nucleusrv.git
   cd nucleusrv

Prepare Your Program
--------------------

Generate a hex file from an assembly or C program using the provided tools:

.. code-block:: bash

   cd tools
   make PROGRAM=fibonacci
   cd ..

Generate Verilog
----------------

Use the ``NRVDriver`` to generate Verilog from Chisel:

.. code-block:: bash

   sbt "nucleusrv.components.NRVDriver \
     --imem tools/out/program.hex \
     --dmem tools/out/program.hex \
     --target-dir generated"

Compile with Verilator
----------------------

Set ``NRV_ROOT`` and compile:

.. code-block:: bash

   export NRV_ROOT=$PWD
   cd generated
   verilator --cc --exe --build --trace --no-timing $NRV_ROOT/tb_Top.cpp Top.v

Run the Simulation
------------------

.. code-block:: bash

   ./obj_dir/VTop

Inspect Waveforms
-----------------

If tracing was enabled, waveforms are saved in the ``logs/`` directory:

.. code-block:: bash

   gtkwave logs/top.vcd
