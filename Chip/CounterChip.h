//
//  CounterChip.h
//  CircuitModel
//
//  Created by Mayank on 9/6/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__CounterChip__
#define __CircuitModel__CounterChip__

#include <iostream>
#include "Chip.h"
#include "EdgeTriggeredInput.h"
#include "SingleBitOutput.h"

class CounterChip: public Chip
{
protected:
    short mCount;
    short forIndex; //pre-alloc for speed
public:
    CounterChip();
    void tick();
    EdgeTriggeredInput input;
    SingleBitOutput output[16];
    void clock();
    
    virtual std::string description() {return "counter";};

};


#endif /* defined(__CircuitModel__CounterChip__) */
