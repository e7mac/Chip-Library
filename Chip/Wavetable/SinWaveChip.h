//
//  SinWaveChip.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__SinWaveChip__
#define __CircuitModel__SinWaveChip__

#include <iostream>
#include "WavetableChip.h"

class SinWaveChip:public WavetableChip
{
public:
    SinWaveChip();
    float waveFunction(short i);
    virtual std::string description() {return "sin wave";};

};


#endif /* defined(__CircuitModel__SinWaveChip__) */
