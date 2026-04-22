Run RISC-V Architecture Compliance Tests
========================================

Validate NucleusRV against official RISC-V architectural test suites using the ``riscof`` framework.

Setup the Environment
---------------------

1. Create a Python virtual environment:

   .. code-block:: bash

      python3 -m venv .venv
      source .venv/bin/activate

2. Install ``riscof`` and required plugins:

   .. code-block:: bash

      pip3 install git+https://github.com/riscv/riscof.git
      pip3 install -e riscof/riscv-arch-test/riscv-ctg riscof/riscv-arch-test/riscv-isac

Run the Tests
-------------

Execute the test runner script:

.. code-block:: bash

   python3 run_riscv_arch_tests.py

This script invokes ``riscof``, which runs tests on both NucleusRV (the DUT) and Spike (the reference), comparing their memory signatures.

Review Results
--------------

Results are stored in ``riscof/riscof_work/``. View the ``report.html`` file for a detailed pass/fail summary.
