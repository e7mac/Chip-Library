//
//  ResetTimerChip.cpp
//  ChipLibraryTestBed
//
//  Created by Mayank on 10/25/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "ResetTimerChip.h"

ResetTimerChip::ResetTimerChip()
{
    input.setChip(this);
    output.setChip(this);
    mCount = 0;
}

void ResetTimerChip::tickInput()
{
    input.refreshInput();
    if (input.getRisingEdge())
        clockInput();
}

void ResetTimerChip::tickOutput()
{
    if (input.getRisingEdge())
        clockOutput();
}

void ResetTimerChip::clockInput()
{
    mCount++;
    mCount %= nbits;
    mState = !mCount;
}

void ResetTimerChip::clockOutput()
{
    output.setOutputBit(mState);
}
