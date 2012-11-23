//
//  SingleBitOutput.cpp
//  CircuitModel
//
//  Created by Mayank on 9/6/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "SingleBitOutput.h"

void SingleBitOutput::setOutputBit(bool withBit)
{
    outputBit = withBit;
}


bool SingleBitOutput::serialOutput()
{
    return outputBit;
}