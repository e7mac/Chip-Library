//
//  GroundChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "GroundChip.h"

GroundChip::GroundChip()
{
    output.setChip(this);
    output.setOutputBit(0); // ground
}