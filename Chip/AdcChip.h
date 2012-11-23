//
//  AdcChip.h
//  ChipLibraryTestBed
//
//  Created by Mayank on 9/8/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__AdcChip__
#define __CircuitModel__AdcChip__

#include <iostream>
#include "Chip.h"
#include "SingleBitOutput.h"
#include "EdgeTriggeredInput.h"

class AdcChip:public Chip
{
public:
    float mInputValueFloat;
    unsigned short mInputValue;
    unsigned short mForIndex; // pre-allocating
public:
    AdcChip();
    EdgeTriggeredInput resetInput;
    SingleBitOutput output[16];
    
    void setInputValue(float withInputValue);
    void tick();
    void reset();
    
    virtual std::string description() {return "adc";};
};

#endif /* defined(__CircuitModel__AdcChip__) */
