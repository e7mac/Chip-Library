//
//  SerialInput.cpp
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "SerialInput.h"

void SerialInput::refreshInput()
{
    // TEST BLOCK
    if (connection){
        inputRegister.pushBit(connection->serialOutput());
    }
}