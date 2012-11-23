//
//  BinaryGate.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "BinaryGate.h"

BinaryGate::BinaryGate()
{
    input[0].setChip(this);
    input[1].setChip(this);
    output.setChip(this);
}

void BinaryGate::tick()
{
    input[0].refreshInput();
    input[1].refreshInput();
    output.setOutputBit(logicalOperation(input[0].getInputBit(), input[1].getInputBit()));
}