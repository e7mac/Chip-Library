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
    clockInput.setChip(this);
    resetInput.setChip(this);
    for (forIndex=0;forIndex<2;forIndex++)
        input[forIndex].setChip(this);
    output.setChip(this);
}

void MultiplierChip::tick()
{
    clockInput.refreshInput();
    if (clockInput.getRisingEdge())
        clock();
    resetInput.refreshInput();
    if (resetInput.getRisingEdge())
        reset();
}
void MultiplierChip::clock()
{
    for (forIndex=0;forIndex<2;forIndex++)
        input[forIndex].refreshInput();
    output.outputRegister.leftCircularShift(1);
}
void MultiplierChip::reset()
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
    output.outputRegister.setValue(mOutputValue);
}