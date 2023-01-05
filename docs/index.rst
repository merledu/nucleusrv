NucleusRV: A 32 bit RISC-V core
===================================

.. note::

   This project is under active development.

**NucleusRV** is a 32-bit 5 stage pipelined RISC-V core written in Chisel. It implements I base ISA, M multiply and divide, and C compressed instructions (RV32IMC). NucleusRV has been taped out in Google's sponsered OpenMPW-6 shuttle on SKY130nm process node.

The documentation is split into 3 sections.

The :doc:`Overview <01_overview/index>` section explores the features of NucleusRV from bird's eye view. 

The :doc:`User Guide <02_user/index>` section provides information necessary to setup and run
NucleusRV. It is aimed at software developers writing software for NucleusRV.

The :doc:`Developer Guide <03_dev/index>` section gives detailed explanation of source code and different
design decisions. It highlights contribution guidelines and will be helpful for people making
changes to NucleusRV

.. toctree::
   :maxdepth: 2
   :hidden:

   01_overview/index.rst
   02_user/index.rst
   03_dev/index.rst
