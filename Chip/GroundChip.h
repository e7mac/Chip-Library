//
//  GroundChip.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__GroundChip__
#define __CircuitModel__GroundChip__

#include <iostream>
#include "SingleBitOutput.h"
#include "Chip.h"

class GroundChip:public Chip
{
protected:
    SingleBitOutput output;
    
public:
    GroundChip();
    virtual std::string description() {return "ground";};

};
#endif /* defined(__CircuitModel__GroundChip__) */
