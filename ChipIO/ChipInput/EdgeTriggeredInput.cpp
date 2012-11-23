//
//  EdgeTriggeredInput.cpp
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "EdgeTriggeredInput.h"
#include "Chip.h"

void EdgeTriggeredInput::refreshInput()
{
    // TEST BLOCK
    if (connection)
    {
    inputBit = connection->serialOutput();
    risingEdge  = inputBit>state;
    state = inputBit;
    }
}

bool EdgeTriggeredInput::getRisingEdge()
{
    return risingEdge;
}