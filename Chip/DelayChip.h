//
//  DelayChip.h
//  ChipLibraryTestBed
//
//  Created by Kurt Werner on 11/25/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __ChipLibraryTestBed__DelayChip__
#define __ChipLibraryTestBed__DelayChip__

#include <iostream>
#include "Chip.h"
#include "EdgeTriggeredInput.h"
#include "SerialInput.h"
#include "SingleBitOutput.h"

class DelayChip: public Chip
{
protected:
    short forIndex;
public:
    SerialInput input;
    SingleBitOutput output[16];
    EdgeTriggeredInput clockInput;
    
    DelayChip();
    
    void tick();
    void clock();
    
    virtual std::string description() {return "delay";};
};

#endif /* defined(__ChipLibraryTestBed__DelayChip__) */
