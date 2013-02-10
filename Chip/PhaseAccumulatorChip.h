//
//  PhaseAccumulatorChip.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__PhaseAccumulatorChip__
#define __CircuitModel__PhaseAccumulatorChip__

#include <iostream>
#include "Chip.h"
#include "SerialInput.h"
#include "SerialOutput.h"
#include "EdgeTriggeredInput.h"

class PhaseAccumulatorChip: public Chip
{
protected:
public:
    unsigned short mPhase;
    unsigned short mPhaseIncrement;
    float mPhaseIncrementFloat;
    float mPhaseFloat;
public:
    SerialInput input;
    SerialOutput output;
    EdgeTriggeredInput clockInputRegister;
    EdgeTriggeredInput resetInputRegister;

    PhaseAccumulatorChip();
    void tickInput();
    void tickOutput();
    void clockInput();
    void clockOutput();
    void resetInput();
    void resetOutput();
    unsigned short getPhaseIncrement() { return mPhaseIncrement;}
    float getPhaseIncrementFloat() { return mPhaseIncrementFloat;}
    unsigned short getPhase() { return mPhase;}    
    float getPhaseFloat() { return mPhaseFloat;}
    
    virtual std::string description() {return "phase";};    
};


#endif /* defined(__CircuitModel__PhaseAccumulatorChip__) */
