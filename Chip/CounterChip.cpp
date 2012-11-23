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

void CounterChip::tick()
{
    input.refreshInput();
    if (input.getRisingEdge())
        clock();
}

void CounterChip::clock()
{
    mCount++;
    for (forIndex=0;forIndex<16;forIndex++)
        output[forIndex].setOutputBit(mCount & (1<<forIndex) );
}