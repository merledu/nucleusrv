Build and Run C Programs on NucleusRV
=====================================

NucleusRV includes a build system to compile C programs for the core.

Create a Test Directory
-----------------------

Create a directory for your C project in ``tools/tests/``:

.. code-block:: bash

   mkdir tools/tests/my_test

Add your C source files and a ``main.c``.

Build with Make
---------------

Run ``make`` from the ``tools/`` directory:

.. code-block:: bash

   cd tools
   make PROGRAM=my_test

This will generate ``out/program.hex``, which you can use for simulation.

Simulate
--------

Generate Verilog using ``NRVDriver`` and run with Verilator as described in the :doc:`../quickstart`.
