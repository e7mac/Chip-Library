//
//  TimerChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/6/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "TimerChip.h"

TimerChip::TimerChip()
{
    output.setChip(this);
}

void TimerChip::tick()
{
    mState = !mState;
    output.setOutputBit(mState);
}