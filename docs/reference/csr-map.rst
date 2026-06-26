CSR Address Map Reference for NucleusRV
=======================================

NucleusRV implements a subset of RISC-V Machine-Mode CSRs and Floating-Point CSRs.

Machine-Mode CSRs
-----------------

+---------+-----------+-----------------------------------+
| Address | Name      | Description                       |
+=========+===========+===================================+
| 0x300   | mstatus   | Machine status register           |
+---------+-----------+-----------------------------------+
| 0x301   | misa      | Machine ISA register              |
+---------+-----------+-----------------------------------+
| 0x304   | mie       | Machine interrupt-enable register |
+---------+-----------+-----------------------------------+
| 0x305   | mtvec     | Machine trap-handler base address |
+---------+-----------+-----------------------------------+
| 0x340   | mscratch  | Scratch register for machine trap |
+---------+-----------+-----------------------------------+
| 0x341   | mepc      | Machine exception program counter |
+---------+-----------+-----------------------------------+
| 0x342   | mcause    | Machine trap cause                |
+---------+-----------+-----------------------------------+
| 0x343   | mtval     | Machine bad address or instruction|
+---------+-----------+-----------------------------------+
| 0x344   | mip       | Machine interrupt pending         |
+---------+-----------+-----------------------------------+
| 0xF12   | marchid   | Architecture ID                   |
+---------+-----------+-----------------------------------+
| 0xF14   | mhartid   | Hardware thread ID                |
+---------+-----------+-----------------------------------+

Floating-Point CSRs
-------------------

Enabled when ``F = true`` in the configuration.

+---------+-----------+-----------------------------------+
| Address | Name      | Description                       |
+=========+===========+===================================+
| 0x001   | fflags    | Floating-Point Accrued Exceptions |
+---------+-----------+-----------------------------------+
| 0x002   | frm       | Floating-Point Dynamic Rounding   |
+---------+-----------+-----------------------------------+
| 0x003   | fcsr      | Floating-Point Control and Status |
+---------+-----------+-----------------------------------+

Performance Counters
--------------------

+---------+-----------+-----------------------------------+
| Address | Name      | Description                       |
+=========+===========+===================================+
| 0xB00   | mcycle    | Machine cycle counter             |
+---------+-----------+-----------------------------------+
| 0xB02   | minstret  | Machine instructions-retired      |
+---------+-----------+-----------------------------------+
| 0x320   | mcountinh | Machine counter-inhibit register  |
+---------+-----------+-----------------------------------+

Detailed Field Maps
-------------------

MSTATUS Field Map
~~~~~~~~~~~~~~~~~

* **[22] TSR**: Trap SRET
* **[21] TW**: Timeout Wait
* **[20] TVM**: Trap Virtual Memory
* **[19] MXR**: Make Executable Readable
* **[18] SUM**: permit Supervisor User Memory access
* **[17] MPRV**: Memory Privilege
* **[12:11] MPP**: Machine Previous Privilege Mode
* **[8] SPP**: Supervisor Previous Privilege Mode
* **[7] MPIE**: Machine Previous Interrupt Enable
* **[6] UBE**: User Big-Endian
* **[5] SPIE**: Supervisor Previous Interrupt Enable
* **[3] MIE**: Machine Interrupt Enable
* **[1] SIE**: Supervisor Interrupt Enable

MIE and MIP Field Map
~~~~~~~~~~~~~~~~~~~~~

* **[11] MEIE/MEIP**: Machine External Interrupt
* **[7] MTIE/MTIP**: Machine Timer Interrupt
* **[3] MSIE/MSIP**: Machine Software Interrupt

FCSR Field Map
~~~~~~~~~~~~~~

* **[7:5] FRM**: Floating-Point Rounding Mode
* **[4] NV**: Invalid Operation
* **[3] DZ**: Divide by Zero
* **[2] OF**: Overflow
* **[1] UF**: Underflow
* **[0] NX**: Inexact

MCOUNTINHIBIT Field Map
~~~~~~~~~~~~~~~~~~~~~~~

* **[2] IR**: Inhibit ``minstret``
* **[0] CY**: Inhibit ``mcycle``
