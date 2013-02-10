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
    resetInputRegister.setChip(this);
    for(mForIndex=0; mForIndex<16; mForIndex++)
        output[mForIndex].setChip(this);
}

void AdcChip::setInputValue(float withInputValue)
{
    mInputValueFloat = withInputValue;
}

void AdcChip::tickInput()
{
    resetInputRegister.refreshInput();
    if (resetInputRegister.getRisingEdge())
        resetInput();
}

void AdcChip::tickOutput()
{
    if (resetInputRegister.getRisingEdge())
        resetOutput();
}


void AdcChip::resetInput()
{
    mInputValue = 0.5*(mInputValueFloat+1)*(1<<nbits);
}

void AdcChip::resetOutput()
{
    for(mForIndex=0; mForIndex<16; mForIndex++)
        output[mForIndex].setOutputBit(mInputValue&(1<<mForIndex));
}