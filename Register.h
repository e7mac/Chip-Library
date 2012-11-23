//
//  Register.h
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__Register__
#define __CircuitModel__Register__

#include <iostream>

class Register
{
protected:
    unsigned short mValue;
public:
    static short nbits;
    
    void setValue(unsigned short withValue);
    unsigned short getValue();

    bool getBitAtPosition(short pos);
    bool getMsb();
    bool getLsb();

    void pushBit(bool newBit);
    
    void leftShift(short shift);
    void rightShift(short shift);
    void leftCircularShift(short shift);
    void rightCircularShift(short shift);
};


#endif /* defined(__CircuitModel__Register__) */
