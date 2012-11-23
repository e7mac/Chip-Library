//
//  VccChip.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__VccChip__
#define __CircuitModel__VccChip__

#include <iostream>
#include "SingleBitOutput.h"
#include "Chip.h"

class VccChip:public Chip
{
protected:
    SingleBitOutput output;
    
public:
    VccChip();
};
#endif /* defined(__CircuitModel__VccChip__) */
