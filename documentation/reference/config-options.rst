NucleusRV Configuration Options Reference
========================================

Complete reference for the ``Configs`` class parameters.

Case Class Definition
---------------------

.. code-block:: scala

   case class Configs(
     XLEN : Int = 32,
     M : Boolean = true,
     F : Boolean = true,
     C : Boolean = false,
     A : Boolean = true,
     Zicsr : Boolean = true,
     TRACE : Boolean = true,
     HARTID : Int = 1,
     ARCHID : Int = 1
   )

Parameter Details
-----------------

XLEN
~~~~
- Type: ``Int``
- Default: ``32``
- Support: Only 32 is currently supported.

M
~
- Type: ``Boolean``
- Default: ``true``
- Description: Enables the Multiply/Divide Unit (MDU).

F
~
- Type: ``Boolean``
- Default: ``true``
- Description: Enables the Floating-Point Unit (FPU).

C
~
- Type: ``Boolean``
- Default: ``false``
- Description: Enables Compressed instruction support (Realigner and CompressedDecoder).

A
~
- Type: ``Boolean``
- Default: ``true``
- Description: Enables Atomic instruction support (AMOALU and ReservationFile).

Zicsr
~~~~~
- Type: ``Boolean``
- Default: ``true``
- Description: Enables CSR instructions and the CSR file.

TRACE
~~~~~
- Type: ``Boolean``
- Default: ``true``
- Description: Enables the RVFI (RISC-V Formal Interface) tracing ports.

HARTID
~~~~~~
- Type: ``Int``
- Default: ``1``
- Description: Sets the hardware thread ID.

ARCHID
~~~~~~
- Type: ``Int``
- Default: ``1``
- Description: Sets the architecture ID.
