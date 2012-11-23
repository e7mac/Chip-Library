//
//  PhaseAccumulatorChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "PhaseAccumulatorChip.h"
#include <math.h>

PhaseAccumulatorChip::PhaseAccumulatorChip()
{
    mPhase=0;
    input.setChip(this);
    output.setChip(this);
    clockInput.setChip(this);
    resetInput.setChip(this);
}

void PhaseAccumulatorChip::tick()
{
    clockInput.refreshInput();
    if (clockInput.getRisingEdge())
        clock();
    resetInput.refreshInput();
    if (resetInput.getRisingEdge())
        reset();
}
void PhaseAccumulatorChip::clock()
{
    input.refreshInput();
    output.outputRegister.leftCircularShift(1);
}


void PhaseAccumulatorChip::reset()
{
    mPhaseIncrementFloat = input.inputRegister.getValue();
    // TODO: efficiency
    mPhaseIncrementFloat = 1*powf(2, (mPhaseIncrementFloat/((float)(1<<nbits)-1)*log2f(srate/2))); //16 bit to keep it at full accuracy
    mPhaseIncrementFloat *= (float)((1<<16)-1)/srate;
    mPhaseIncrement = mPhaseIncrementFloat;
    mPhase = (mPhase + mPhaseIncrement)&((1<<16)-1);
    output.outputRegister.setValue(mPhase>>(16-nbits));
}
