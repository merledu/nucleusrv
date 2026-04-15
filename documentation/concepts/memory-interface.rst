NucleusRV Memory Interface: Instruction and Data Ports
======================================================

NucleusRV uses separate instruction and data memory ports (Harvard architecture) based on a simple Decoupled request/response protocol.

Bundle Definitions
------------------

The memory interface uses ``MemRequestIO`` and ``MemResponseIO`` bundles wrapped in ``Decoupled`` interfaces.

MemRequestIO Fields
~~~~~~~~~~~~~~~~~~~

- ``addrRequest``: 32-bit byte address.
- ``dataRequest``: 32-bit write data (ignored on reads).
- ``activeByteLane``: 4-bit byte-enable mask.
- ``isWrite``: 1 for write, 0 for read.

MemResponseIO Fields
~~~~~~~~~~~~~~~~~~~~

- ``dataResponse``: 32-bit read data.

Handshake Protocol
------------------

A transaction occurs when both ``valid`` and ``ready`` are asserted on the same clock edge.

- **Request**: Core drives ``valid`` and request fields; Memory drives ``ready``.
- **Response**: Memory drives ``valid`` and ``dataResponse``; Core drives ``ready``.

Timing
------

- **Instruction Port**: Fetches occur every cycle unless stalled or waiting for response.
- **Data Port**: Stores and loads initiate in the EX/MEM stage transition and complete when ``dmemRsp.valid`` is asserted.
