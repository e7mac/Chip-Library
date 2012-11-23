//
//  ChipOutput.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__ChipOutput__
#define __CircuitModel__ChipOutput__

#include <iostream>
#include "ChipIO.h"

class ChipInput;

class ChipOutput: public ChipIO
{
protected:
//    ChipInput *connection;
    
public:
//    void setConnection(ChipInput *withConnection);
    virtual bool serialOutput() {return 0;};
};

#endif /* defined(__CircuitModel__ChipOutput__) */
