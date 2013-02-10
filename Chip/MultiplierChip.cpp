//
//  MultiplierChip.cpp
//  ChipLibraryTestBed
//
//  Created by Mayank on 10/17/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "MultiplierChip.h"

MultiplierChip::MultiplierChip()
{
    clockInputRegister.setChip(this);
    resetInputRegister.setChip(this);
    for (forIndex=0;forIndex<2;forIndex++)
        input[forIndex].setChip(this);
    output.setChip(this);
}

void MultiplierChip::tickInput()
{
    clockInputRegister.refreshInput();
    if (clockInputRegister.getRisingEdge())
        clockInput();
    resetInputRegister.refreshInput();
    if (resetInputRegister.getRisingEdge())
        resetInput();
}

void MultiplierChip::tickOutput()
{
    if (clockInputRegister.getRisingEdge())
        clockOutput();
    if (resetInputRegister.getRisingEdge())
        resetOutput();
}

void MultiplierChip::clockInput()
{
    for (forIndex=0;forIndex<2;forIndex++)
        input[forIndex].refreshInput();
}

void MultiplierChip::clockOutput()
{
    output.outputRegister.leftCircularShift(1);
}

void MultiplierChip::resetInput()
{
    for (forIndex=0;forIndex<2;forIndex++)
    {
        mInputValue[forIndex] = input[forIndex].inputRegister.getValue(); // 0->max
        mInputValueFloat[forIndex] = (float)(mInputValue[forIndex]+1) / ((1<<nbits)); // 0->1 (just below)
        mInputValueFloat[forIndex] = mInputValueFloat[forIndex]*2-1; // -1 -> 1 (just below)
    }
    mOutputValueFloat = mInputValueFloat[0]*mInputValueFloat[1]; // -1 ->1
    mOutputValueFloat = (mOutputValueFloat + 1 ) * 0.5; // 0->1 (just below)
    mOutputValue = mOutputValueFloat * ((1<<nbits)) - 1;
    mOutputValueFloat = mOutputValueFloat*2 - 1;
}

void MultiplierChip::resetOutput()
{
    output.outputRegister.setValue(mOutputValue);
}