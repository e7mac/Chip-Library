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

void ResetTimerChip::tick()
{
    input.refreshInput();
    if (input.getRisingEdge())
        clock();
}

void ResetTimerChip::clock()
{
    mCount++;
    mCount %= nbits;
    mState = !mCount;
    output.setOutputBit(mState);
}
