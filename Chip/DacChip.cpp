//
//  DacChip.cpp
//  ChipLibraryTestBed
//
//  Created by Mayank on 9/8/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "DacChip.h"

DacChip::DacChip()
{
    resetInputRegister.setChip(this);
    for(forIndex=0; forIndex<16; forIndex++)
        input[forIndex].setChip(this);
}

void DacChip::tickInput()
{
    resetInputRegister.refreshInput();
    if (resetInputRegister.getRisingEdge())
        resetInput();
}

void DacChip::tickOutput()
{
    if (resetInputRegister.getRisingEdge())
        resetOutput();
}

void DacChip::resetInput()
{
    for(forIndex=0; forIndex<16; forIndex++)
    {
        input[forIndex].refreshInput();
    }
}

void DacChip::resetOutput()
{
    mOutputValue = 0;
    for(forIndex=0; forIndex<16; forIndex++)
    {
        mOutputValue += input[forIndex].getInputBit()*(1<<forIndex);
    }
    mOutputValueFloat = ((float)mOutputValue / (1<<nbits)) * 2 - 1;
}