//
//  FloatingVoltageChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "FloatingVoltageChip.h"

FloatingVoltageChip::FloatingVoltageChip()
{
    output.setChip(this);
}

void FloatingVoltageChip::tick()
{
    output.setOutputBit(rand()%2); // TO DO: is there a better way to do this? rand() inefficient? This only gets a new number every tick, not every time it is accessed - is that okay? Maybe extend the singleBitOutput subclass, like RandomBitOutput...
}