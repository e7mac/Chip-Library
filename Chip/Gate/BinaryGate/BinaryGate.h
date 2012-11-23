//
//  BinaryGate.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__BinaryGate__
#define __CircuitModel__BinaryGate__

#include <iostream>
#include "Gate.h"
#include "SingleBitInput.h"

class BinaryGate:public Gate
{
protected:
    
public:
    BinaryGate();
    SingleBitInput input[2];
    void tick();
    virtual bool logicalOperation(bool logicIn0, bool logicIn1) {return 0;};
};

#endif /* defined(__CircuitModel__BinaryGate__) */
