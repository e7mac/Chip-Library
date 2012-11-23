//
//  OrBinaryGate.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__OrBinaryGate__
#define __CircuitModel__OrBinaryGate__

#include <iostream>
#include "BinaryGate.h"

class OrBinaryGate: public BinaryGate
{
protected:
    
public:
    bool logicalOperation(bool in0,bool in1);
};

#endif /* defined(__CircuitModel__OrBinaryGate__) */
