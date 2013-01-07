//
//  CircuitBoard.h
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__CircuitBoard__
#define __CircuitModel__CircuitBoard__

#include <iostream>
#include "Chip.h"
#include "ChipInput.h"
#include "ChipOutput.h"
#include <set>
#include <map>
#include <vector>


class CircuitBoard
{
protected:
    std::set<Chip *> mChips_set;
    std::vector<Chip *> mChips;
    std::map<ChipInput *, ChipOutput *> mConnections;
    
public:
    void addChip(Chip *withChip);
    void removeChip(Chip *removeChip);
    Chip *getChipAtIndex(int i);
    int getNumberOfChips();
    
    void addConnection(ChipOutput *chipOutput, ChipInput *chipInput);
    void removeConnection(ChipInput *chipInput);
    void updateConnections();
    
    void tick();
    
};

#endif /* defined(__CircuitModel__CircuitBoard__) */
