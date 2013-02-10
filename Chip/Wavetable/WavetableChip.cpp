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
    clockInputRegister.setChip(this);
    resetInputRegister.setChip(this);

}


void WavetableChip::cache()
{
    
    int num = 1<<nbits;
    wavetable = new float[num];
    for (int i = 0;i<num;i++)
        wavetable[i] = waveFunction(i);
}

void WavetableChip::tickInput()
{
    clockInputRegister.refreshInput();
    if (clockInputRegister.getRisingEdge())
        clockInput();
    resetInputRegister.refreshInput();
    if (resetInputRegister.getRisingEdge())
        resetInput();
}

void WavetableChip::tickOutput()
{
    if (clockInputRegister.getRisingEdge())
        clockOutput();
    if (resetInputRegister.getRisingEdge())
        resetOutput();
}

void WavetableChip::clockInput()
{
    input.refreshInput();
}

void WavetableChip::clockOutput()
{
    output.outputRegister.leftCircularShift(1);
}

void WavetableChip::resetInput()
{
    mIndex = input.inputRegister.getValue();
    mWavetableOutFloat = wavetable[mIndex];
    mWavetableOut = 0.5*(mWavetableOutFloat + 1) * ((1<<nbits) - 1);
}

void WavetableChip::resetOutput()
{
    output.outputRegister.setValue(mWavetableOut);
}