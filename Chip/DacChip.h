//
//  DacChip.h
//  ChipLibraryTestBed
//
//  Created by Mayank on 9/8/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__DacChip__
#define __CircuitModel__DacChip__

#include <iostream>
#include "Chip.h"
#include "SingleBitInput.h"
#include "EdgeTriggeredInput.h"

class DacChip:public Chip
{
public:
    float mOutputValueFloat;
    unsigned short mOutputValue;
    unsigned short forIndex; // pre-allocating
public:
    DacChip();
    EdgeTriggeredInput resetInputRegister;
    SingleBitInput input[16];
    
    float getOutputValue(){return mOutputValue;};
    float getOutputValueFloat(){return mOutputValueFloat;};

    void tickInput();
    void tickOutput();
    void resetInput();
    void resetOutput();
    virtual std::string description() {return "dac";};

};


#endif /* defined(__CircuitModel__DacChip__) */
