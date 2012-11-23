//
//  Gate.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__Gate__
#define __CircuitModel__Gate__

#include <iostream>
#include "SingleBitOutput.h"
#include "Chip.h"

class Gate:public Chip
{
protected:

public:
    SingleBitOutput output;
    virtual std::string description() {return "gate";};

};
#endif /* defined(__CircuitModel__Gate__) */
