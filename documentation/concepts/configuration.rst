Configuring NucleusRV: Extensions and Core Options
==================================================

NucleusRV is highly configurable via the ``Configs`` case class in Scala/Chisel.

The Configs Case Class
----------------------

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

Parameter Reference
-------------------

- ``XLEN``: Data width (currently only 32 is supported).
- ``M``: Enable/Disable Integer Multiply/Divide.
- ``F``: Enable/Disable Floating-Point Unit.
- ``C``: Enable/Disable Compressed instruction support.
- ``A``: Enable/Disable Atomic Memory Operations.
- ``Zicsr``: Enable/Disable CSR instructions.
- ``TRACE``: Enable/Disable RVFI tracing (useful for verification).
- ``HARTID``: Hardware Thread ID (drives ``mhartid`` CSR).
- ``ARCHID``: Architecture ID (drives ``marchid`` CSR).

Instantiating with Custom Configuration
--------------------------------------

In your top-level Chisel module, you can instantiate the core with a custom config:

.. code-block:: scala

   implicit val config: Configs = Configs(M = true, C = true, TRACE = false)
   val core = Module(new Core())

Common Configurations
---------------------

- **Minimal RV32I**: Disable all optional extensions to minimize area.
- **Full RV32IMAFC**: Enable all supported extensions.
- **Synthesis Config**: Disable ``TRACE`` when synthesizing for hardware to save area.
