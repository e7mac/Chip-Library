//
//  SingleBitOutput.h
//  CircuitModel
//
//  Created by Mayank on 9/6/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__SingleBitOutput__
#define __CircuitModel__SingleBitOutput__

#include <iostream>
#include "ChipOutput.h"
#include "Register.h"

class SingleBitOutput: public ChipOutput
{
public:
    bool outputBit;
public:
    void setOutputBit(bool withBit);
    bool serialOutput();
};



#endif /* defined(__CircuitModel__SingleBitOutput__) */
