//
//  NandBinaryGate.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "NandBinaryGate.h"

bool NandBinaryGate::logicalOperation(bool in0, bool in1)
{
    return !(in0&in1);
}
