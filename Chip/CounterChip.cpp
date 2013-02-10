//
//  CounterChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/6/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "CounterChip.h"

CounterChip::CounterChip()
{
    input.setChip(this);
    for (forIndex=0;forIndex<16;forIndex++)
        output[forIndex].setChip(this);
}

void CounterChip::tickInput()
{
    input.refreshInput();
    inputBit = input.getState();
    if (input.getRisingEdge())
        clockInput();
}

void CounterChip::tickOutput()
{
    output[0].setOutputBit(inputBit); // pass through
    if (input.getRisingEdge())
        clockOutput();
}

void CounterChip::clockInput()
{
    mCount++;
}

void CounterChip::clockOutput()
{
    for (forIndex=1;forIndex<16;forIndex++)
        output[forIndex].setOutputBit(mCount & (1<<(forIndex-1)) );
}