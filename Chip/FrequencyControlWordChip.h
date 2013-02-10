//
//  FrequencyControlWordChip.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__FrequencyControlWordChip__
#define __CircuitModel__FrequencyControlWordChip__

#include <iostream>
#include "Chip.h"
#include "SerialOutput.h"
#include "SerialInput.h"
#include "EdgeTriggeredInput.h"

class FrequencyControlWordChip:public Chip
{
protected:
    float mCenterFrequency;
    float mDeltaFrequency; // maximum deviation around center frequency
    float mFrequency;
    float mBeta; // modulation index
    float mDeviationFloat;
    float mDeviationAmountFloat;
    
    unsigned short mControlWord;
    unsigned short mDeviation;

public:
    FrequencyControlWordChip();
    SerialInput deviationInput;
    SerialOutput output;
    EdgeTriggeredInput clockInputRegister;
    EdgeTriggeredInput resetInputRegister;
    
    void setCenterFrequency(float withFrequency);
    void setDeviation(float withDeviation);
    void setBeta(float withBeta);
    
    float getFrequency() {return mFrequency;}
    unsigned short getControlWord() {return mControlWord;}
    unsigned short getDeviation(){return mDeviation;}
    float getBeta(){return mBeta;}
    float* getBetaAddress(){return &mBeta;}

    
    void tickInput();
    void tickOutput();
    void clockInput();
    void clockOutput();
    void resetInput();
    void resetOutput();
    
    virtual std::string description() {return "freq control word";};
};

#endif /* defined(__CircuitModel__FrequencyControlWordChip__) */
