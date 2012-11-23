//
//  AdcChip.cpp
//  ChipLibraryTestBed
//
//  Created by Mayank on 9/8/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "AdcChip.h"

AdcChip::AdcChip()
{
    resetInput.setChip(this);
    for(mForIndex=0; mForIndex<16; mForIndex++)
        output[mForIndex].setChip(this);
}

void AdcChip::setInputValue(float withInputValue)
{
    mInputValueFloat = withInputValue;
}

void AdcChip::tick()
{
    resetInput.refreshInput();
    if (resetInput.getRisingEdge())
        reset();
}

void AdcChip::reset()
{
    mInputValue = 0.5*(mInputValueFloat+1)*(1<<nbits);
    for(mForIndex=0; mForIndex<16; mForIndex++)
        output[mForIndex].setOutputBit(mInputValue&(1<<mForIndex));
}