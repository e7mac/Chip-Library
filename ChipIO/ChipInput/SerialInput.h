//
//  SerialInput.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__SerialInput__
#define __CircuitModel__SerialInput__

#include <iostream>
#include "ChipInput.h"
#include "ChipOutput.h"
#include "Register.h"

class SerialInput: public ChipInput
{
protected:
public:
    Register inputRegister;
    void refreshInput();
};

#endif /* defined(__CircuitModel__SerialInput__) */
