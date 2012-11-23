//
//  TimerChip.h
//  CircuitModel
//
//  Created by Mayank on 9/6/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__TimerChip__
#define __CircuitModel__TimerChip__

#include <iostream>
#include "Chip.h"
#include "SingleBitOutput.h"

class TimerChip: public Chip
{
protected:
    bool mState;
public:
    TimerChip();
    SingleBitOutput output;
    void tick();

    virtual std::string description() {return "timer";};    
};

#endif /* defined(__CircuitModel__TimerChip__) */
