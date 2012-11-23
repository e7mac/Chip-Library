//
//  SingleBitInput.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__SingleBitInput__
#define __CircuitModel__SingleBitInput__

#include <iostream>
#include "ChipInput.h"
#include "ChipOutput.h"
#include "Register.h"

class SingleBitInput: public ChipInput
{
protected:
    bool inputBit;
public:
    SingleBitInput();
    void refreshInput();
    void setInputBit(bool withBit);
    bool getInputBit();
};


#endif /* defined(__CircuitModel__SingleBitInput__) */
