//
//  CircuitBoard.cpp
//  CircuitModel
//
//  Created by Mayank on 9/7/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "CircuitBoard.h"

void CircuitBoard::addChip(Chip *withChip)
{
    if (mChips_set.find(withChip)==mChips_set.end())
    {
        mChips_set.insert(withChip);
        mChips.push_back(withChip);
    }
}

void CircuitBoard::removeChip(Chip *removeChip)
{
    mChips_set.erase(removeChip);
    for (std::vector<Chip *>::iterator i=mChips.begin();i!=mChips.end();i++)
    {
        
        if (*i==removeChip)
            mChips.erase(i);
    }
}

void CircuitBoard::addConnection(ChipOutput *chipOutput,ChipInput *chipInput)
{
    mConnections[chipInput] = chipOutput;
    addChip(chipOutput->chip);
    addChip(chipInput->chip);

}
void CircuitBoard::removeConnection(ChipInput *chipInput)
{
    mConnections[chipInput] = NULL;
}
void CircuitBoard::updateConnections()
{
    for (std::map<ChipInput *, ChipOutput*>::iterator chipPair=mConnections.begin();chipPair!=mConnections.end();chipPair++)
    {
        chipPair->first->setConnection(chipPair->second);
    }
}

void CircuitBoard::tick()
{
    for (int i=0;i<mChips.size();i++)
    {
        mChips[i]->tick();
    }
}

Chip* CircuitBoard::getChipAtIndex(int i)
{
    return mChips[i];
}
int CircuitBoard::getNumberOfChips()
{
    return mChips.size();
}
