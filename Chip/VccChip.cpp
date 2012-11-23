//
//  VccChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "VccChip.h"

VccChip::VccChip()
{
    output.setChip(this);
    output.setOutputBit(1); // Vcc
}