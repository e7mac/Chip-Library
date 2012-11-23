//
//  SinDac.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "WavetableChip.h"
#include <math.h>

WavetableChip::WavetableChip()
{
    input.setChip(this);
    output.setChip(this);
    clockInput.setChip(this);
    resetInput.setChip(this);

}


void WavetableChip::cache()
{
    
    int num = 1<<nbits;
    wavetable = new float[num];
    for (int i = 0;i<num;i++)
        wavetable[i] = waveFunction(i);
}


void WavetableChip::tick()
{
    clockInput.refreshInput();
    if (clockInput.getRisingEdge())
        clock();
    resetInput.refreshInput();
    if (resetInput.getRisingEdge())
        reset();
}
void WavetableChip::clock()
{
    input.refreshInput();
    output.outputRegister.leftCircularShift(1);
}
void WavetableChip::reset()
{
    mIndex = input.inputRegister.getValue();
    mWavetableOutFloat = wavetable[mIndex];
    mWavetableOut = 0.5*(mWavetableOutFloat + 1) * ((1<<nbits) - 1);
    output.outputRegister.setValue(mWavetableOut);
}