//
//  SinDac.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__SinDac__
#define __CircuitModel__SinDac__

#include <iostream>
#include "Chip.h"
#include "SerialInput.h"
#include "SerialOutput.h"
#include "EdgeTriggeredInput.h"

class WavetableChip:public Chip
{
protected:
    unsigned short mIndex;
    unsigned short mWavetableOut;
    float mWavetableOutFloat;
    float *wavetable;
    unsigned short forIndex;
public:
    WavetableChip();
    SerialInput input;
    SerialOutput output;
    EdgeTriggeredInput clockInput;
    EdgeTriggeredInput resetInput;
    void tick();
    void clock();
    void reset();
    void cache();

    float getWavetableOutFloat(){return mWavetableOutFloat;};
    unsigned short getWavetableOut(){return mWavetableOut;};
    virtual float waveFunction(short i) {return 0;};
    virtual std::string description() {return "wavetable";};

};

#endif /* defined(__CircuitModel__SinDac__) */
