Generate and View Waveforms with NucleusRV
==========================================

NucleusRV supports waveform tracing during simulation to help with debugging.

Enabling Waveform Tracing
-------------------------

Pass the ``--trace`` flag to Verilator during compilation:

.. code-block:: bash

   verilator --cc --exe --build --trace --no-timing $NRV_ROOT/tb_Top.cpp Top.v

Where Waveforms are Saved
-------------------------

During simulation, a VCD file is generated at ``logs/top.vcd`` within your simulation directory.

Opening Waveforms in GTKWave
----------------------------

Use GTKWave to view the signal transitions:

.. code-block:: bash

   gtkwave logs/top.vcd

Key Signals to Watch
--------------------

- ``clock`` and ``reset``
- ``io_imemReq_valid`` / ``io_imemRsp_valid`` (Instruction Fetch)
- ``io_dmemReq_valid`` / ``io_dmemRsp_valid`` (Data Memory Access)
- ``io_pin`` (Write-back data output)
