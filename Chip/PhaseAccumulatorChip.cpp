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
    clockInputRegister.setChip(this);
    resetInputRegister.setChip(this);
}

void PhaseAccumulatorChip::tickInput()
{
    clockInputRegister.refreshInput();
    if (clockInputRegister.getRisingEdge())
        clockInput();
    resetInputRegister.refreshInput();
    if (resetInputRegister.getRisingEdge())
        resetInput();
}

void PhaseAccumulatorChip::tickOutput()
{
    if (clockInputRegister.getRisingEdge())
        clockOutput();
    if (resetInputRegister.getRisingEdge())
        resetOutput();
}

void PhaseAccumulatorChip::clockInput()
{
    input.refreshInput();
}

void PhaseAccumulatorChip::clockOutput()
{
    output.outputRegister.leftCircularShift(1);
}

void PhaseAccumulatorChip::resetInput()
{
    mPhaseIncrementFloat = input.inputRegister.getValue();
    // TODO: efficiency
    mPhaseIncrementFloat = 1*powf(2, (mPhaseIncrementFloat/((float)(1<<nbits)-1)*log2f(srate/2))); //16 bit to keep it at full accuracy
    mPhaseIncrementFloat *= (float)((1<<16)-1)/srate;
    mPhaseIncrement = mPhaseIncrementFloat;
    mPhase = (mPhase + mPhaseIncrement)&((1<<16)-1);
}

void PhaseAccumulatorChip::resetOutput()
{
    output.outputRegister.setValue(mPhase>>(16-nbits));
}
