//
//  NorBinaryGate.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "NorBinaryGate.h"

bool NorBinaryGate::logicalOperation(bool in0, bool in1)
{
    return !(in0|in1);
}
