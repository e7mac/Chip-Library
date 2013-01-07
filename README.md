Chip-Library
============

A Digital Circuit modeling library which gives access to the individual lines. Built with the motivation of re-creating circuit bending in software. 

Model
-----
Since we are interested in mangling the information while it is being transferred in between the 'Chip' modules, we stayed at the highest level possible - treating individual Chips as black boxes. 

Each Chip has an appropriate number of ChipInputs and ChipOutputs and can perform its calculation at the right time. Each Chip has a CLOCK and a RESET signal. On receiving a CLOCK, the Chip left-shifts the registers on its ChipInputs and pulls another bit into its ChipInput. On receiving a RESET, the Chip takes the value of the Registers on its ChipInputs, performs the right calculations, and puts the calculated value on its ChipOutputs.

Setup
-----
Simply include the 'ChipLibraryInclude.h' file in your project file. Make sure all the directories are included.

Use
---
To use the library, create a CircuitBoard object. Create all the chips that you need. Use board.addConnection(ChipOutput, ChipInput) to connect the chips together. Once all the connections are made, use board.updateConnections() to actually make the connections. Use board.tick() to tuick the board and take the outputs and inputs you need from the chips directly. Enjoy!