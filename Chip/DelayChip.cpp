//
//  DelayChip.cpp
//  ChipLibraryTestBed
//
//  Created by Kurt Werner on 11/25/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "DelayChip.h"

DelayChip::DelayChip()
{
    input.setChip(this);
    clockInput.setChip(this);
    for (forIndex=0;forIndex<nbits;forIndex++)
        output[forIndex].setChip(this);
}

void DelayChip::tick()
{
    clockInput.refreshInput();
    if (clockInput.getRisingEdge())
        clock();
}

void DelayChip::clock()
{
    input.refreshInput();
    for (forIndex=0;forIndex<nbits;forIndex++)
        output[forIndex].setOutputBit(input.inputRegister.getBitAtPosition(forIndex));
}