Integrate NucleusRV into an FPGA Design
=======================================

Instantiate NucleusRV in your FPGA project and connect it to your system.

Generate Synthesis-Ready Verilog
--------------------------------

Ensure you disable ``TRACE`` in your config to save area and remove debug ports:

.. code-block:: scala

   implicit val config: Configs = Configs(TRACE = false)

Emit Verilog using ``NRVDriver``.

Connect the Core
----------------

Instantiate the ``Top`` module in your HDL. Connect the instruction and data memory interfaces to your on-chip memory (e.g., BRAM).

.. image:: /_static/fpga_integration_diagram.png
   :alt: FPGA Integration Diagram

Synthesis Tips
--------------

- **Clock Domain**: NucleusRV is a single-clock design.
- **Reset Polarity**: The reset port is active-high synchronous.
- **Area Optimization**: Disable unused extensions (M, F, A, C) in ``Configs``.
- **Timing Closure**: The core is designed for 100MHz+ on modern FPGAs.
