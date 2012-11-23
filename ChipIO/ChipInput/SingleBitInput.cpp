//
//  SingleBitInput.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "SingleBitInput.h"

SingleBitInput::SingleBitInput()
{
    connection = 0; // SO that we can trigger noteOn independently ... check if connection exists or not
}

void SingleBitInput::refreshInput()
{
    inputBit = connection->serialOutput();
}

bool SingleBitInput::getInputBit()
{
    return inputBit;
}