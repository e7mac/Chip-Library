//
//  EdgeTriggeredInput.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__EdgeTriggeredInput__
#define __CircuitModel__EdgeTriggeredInput__

#include <iostream>
#include "ChipInput.h"
#include "ChipOutput.h"
#include "Register.h"

class EdgeTriggeredInput: public ChipInput
{
protected:
public:
    bool inputBit;
    bool state;
    bool risingEdge;
    
public:

    void refreshInput();
    bool getRisingEdge();
};



#endif /* defined(__CircuitModel__EdgeTriggeredInput__) */
