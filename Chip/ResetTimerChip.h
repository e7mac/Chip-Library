//
//  ResetTimerChip.h
//  ChipLibraryTestBed
//
//  Created by Mayank on 10/25/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __ChipLibraryTestBed__ResetTimerChip__
#define __ChipLibraryTestBed__ResetTimerChip__

#include <iostream>
#include "Chip.h"
#include "SingleBitOutput.h"
#include "EdgeTriggeredInput.h"

class ResetTimerChip: public Chip
{
protected:
    bool mState;
    int mCount;
public:
    ResetTimerChip();
    SingleBitOutput output;
    EdgeTriggeredInput input;
    
    void tickInput();
    void tickOutput();
    void clockInput();
    void clockOutput();
    
    virtual std::string description() {return "reset timer";};
};

#endif /* defined(__ChipLibraryTestBed__ResetTimerChip__) */
