Chip-Library
============

A Digital Circuita modeling library which gives access to the individual lines. Built with the motivation of re-creating circuit bending in software. 

Model
Since we are interested in mangling the information while it is being transferred in between the 'Chip' modules, we stayed at the highest level possible - treating individual Chips as black boxes. 

Each Chip has an appropriate number of ChipInputs and ChipOutputs and can perform its calculation at the right time. Each Chip has a CLOCK and a RESET signal. On receiving a CLOCK, the Chip left-shifts the registers on its ChipInputs and pulls another bit into its ChipInput. On receiving a RESET, the Chip takes the value of the Registers on its ChipInputs, performs the right calculations, and puts the calculated value on its ChipOutputs.

