//
//  SerialOutput.cpp
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "SerialOutput.h"

bool SerialOutput::serialOutput()
{
    return outputRegister.getMsb();
}