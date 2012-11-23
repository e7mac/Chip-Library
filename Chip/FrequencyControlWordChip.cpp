//
//  FrequencyControlWordChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "FrequencyControlWordChip.h"
#include <math.h>

FrequencyControlWordChip::FrequencyControlWordChip()
{
    clockInput.setChip(this);
    resetInput.setChip(this);
    output.setChip(this);
    deviationInput.setChip(this);
}


void FrequencyControlWordChip::setBeta(float withBeta)
{
    mBeta = withBeta;
}

void FrequencyControlWordChip::setDeviation(float withDeviation)
{
    mDeviation = withDeviation;
}


void FrequencyControlWordChip::setCenterFrequency(float withFrequency)
{
    mCenterFrequency = withFrequency;
}

using namespace std;
void FrequencyControlWordChip::tick()
{
    clockInput.refreshInput();
    if (clockInput.getRisingEdge())
        clock();
    resetInput.refreshInput();
    if (resetInput.getRisingEdge())
        reset();
}
void FrequencyControlWordChip::clock()
{
    if (deviationInput.isConnected()){
        deviationInput.refreshInput();
    }
    output.outputRegister.leftCircularShift(1);

}
void FrequencyControlWordChip::reset()
{
    if (deviationInput.isConnected())
    {
        mDeviation = deviationInput.inputRegister.getValue();
        mDeviationFloat =  (float)mDeviation / ((1<<nbits)-1);
        mDeviationFloat = mDeviationFloat*2-1;
    }
    mDeltaFrequency = mCenterFrequency * mBeta;
    mDeviationAmountFloat = mDeviationFloat*mDeltaFrequency;
    mFrequency = mCenterFrequency + mDeviationAmountFloat;
    
    // TODO: efficienct
    mControlWord = log2f((mCenterFrequency+mDeviationAmountFloat)/1)/log2f(srate/2)*((1<<nbits)-1); //log2f(srate/0.002) = 24.39428
    output.outputRegister.setValue(mControlWord);
}
