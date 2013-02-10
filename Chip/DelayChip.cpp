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
    clockInputRegister.setChip(this);
    for (forIndex=0;forIndex<nbits;forIndex++)
        output[forIndex].setChip(this);
}

void DelayChip::tickInput()
{
    clockInputRegister.refreshInput();
    if (clockInputRegister.getRisingEdge())
        clockInput();
}

void DelayChip::tickOutput()
{
    if (clockInputRegister.getRisingEdge())
        clockOutput();
}

void DelayChip::clockInput()
{
    input.refreshInput();
}

void DelayChip::clockOutput()
{
    for (forIndex=0;forIndex<nbits;forIndex++)
        output[forIndex].setOutputBit(input.inputRegister.getBitAtPosition(forIndex));
}