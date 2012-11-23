//
//  ChipIO.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__ChipIO__
#define __CircuitModel__ChipIO__

#include <iostream>

class Chip;

class ChipIO
{
protected:

public:
    ChipIO() {chip=NULL;}
    Chip* chip;
    void setChip(Chip *withChip);
};

#endif /* defined(__CircuitModel__ChipIO__) */
