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
    resetInput.setChip(this);
    for(forIndex=0; forIndex<16; forIndex++)
        input[forIndex].setChip(this);
}


void DacChip::tick()
{
    resetInput.refreshInput();
    if (resetInput.getRisingEdge())
        reset();
}

void DacChip::reset()
{
    mOutputValue = 0;
    for(forIndex=0; forIndex<16; forIndex++)
    {
        input[forIndex].refreshInput();
        mOutputValue += input[forIndex].getInputBit()*(1<<forIndex);
    }
    
    mOutputValueFloat = ((float)mOutputValue / (1<<nbits)) * 2 - 1;
}