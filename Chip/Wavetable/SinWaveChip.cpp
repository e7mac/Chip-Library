//
//  SinWaveChip.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "SinWaveChip.h"
#include <math.h>

SinWaveChip::SinWaveChip()
{
    cache();
}


float SinWaveChip::waveFunction(short i)
{
    return sinf(2*M_PI*i/(1<<nbits));
}
