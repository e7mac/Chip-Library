//
//  FloatingVoltageChip.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__FloatingVoltageChip__
#define __CircuitModel__FloatingVoltageChip__

#include <iostream>
#include "SingleBitOutput.h"
#include "Chip.h"

class FloatingVoltageChip:public Chip
{
protected:
    SingleBitOutput output;
    
public:
    FloatingVoltageChip();
    
    void tickInput();
    void tickOutput();
    virtual std::string description() {return "floating voltage";};

};
#endif /* defined(__CircuitModel__FloatingVoltageChip__) */
