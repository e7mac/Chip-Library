//
//  ChipInput.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__ChipInput__
#define __CircuitModel__ChipInput__

#include <iostream>
#include "ChipIO.h"

class ChipOutput;

class ChipInput: public ChipIO
{
protected:
    ChipOutput *connection;
    
public:
    ChipInput() {connection=NULL;}
    void setConnection(ChipOutput *withConnection);
    virtual void refreshInput() {};
    bool isConnected() {
        return connection
    ;};
};

#endif /* defined(__CircuitModel__ChipInput__) */
