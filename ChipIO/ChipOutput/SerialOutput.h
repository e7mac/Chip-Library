//
//  SerialOutput.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__SerialOutput__
#define __CircuitModel__SerialOutput__

#include <iostream>
#include "ChipOutput.h"
#include "Register.h"

class SerialOutput: public ChipOutput
{
protected:
    
public:
    Register outputRegister;
    bool serialOutput();
};

#endif /* defined(__CircuitModel__SerialOutput__) */
