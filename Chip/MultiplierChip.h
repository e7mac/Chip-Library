//
//  MultiplierChip.h
//  ChipLibraryTestBed
//
//  Created by Mayank on 10/17/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__MultiplierChip__
#define __CircuitModel__MultiplierChip__

#include <iostream>
#include "Chip.h"
#include "SerialOutput.h"
#include "SerialInput.h"
#include "EdgeTriggeredInput.h"

class MultiplierChip:public Chip
{
protected:
    unsigned short mInputValue[2],mOutputValue;
    float mInputValueFloat[2],mOutputValueFloat;
    unsigned short forIndex;
public:
    MultiplierChip();
    SerialInput input[2];
    SerialOutput output;
    EdgeTriggeredInput clockInput;
    EdgeTriggeredInput resetInput;
    
    void tick();
    void clock();
    void reset();
    float getOutputValueFloat() {return  mOutputValueFloat;}
    unsigned short getOutputValue() {return mOutputValue;}
    
    virtual std::string description() {return "multiplier";};

};



#endif /* defined(__CircuitModel__MultiplierChip__) */
