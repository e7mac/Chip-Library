//
//  Chip.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__Chip__
#define __CircuitModel__Chip__

#include <iostream>
#include "Register.h"
#include <string>

class Chip
{
protected:
    
public:
    static short nbits;
    static int srate;
    virtual void tickInput() {};
    virtual void tickOutput() {};
    virtual std::string description() = 0;
};

#endif /* defined(__CircuitModel__Chip__) */
