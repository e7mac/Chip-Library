//
//  Register.cpp
//  CircuitModel
//
//  Created by Mayank on 9/5/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "Register.h"

void Register::setValue(unsigned short withValue)
{
    mValue = withValue;
}
unsigned short Register::getValue()
{
    return mValue & ((1<<nbits)-1);  //bit masking to get nbits of data only
}

bool Register::getBitAtPosition(short pos)
{
    return (mValue & (1<<pos));
}

bool Register::getMsb()
{
    return getBitAtPosition(nbits-1);
}

bool Register::getLsb()
{
    return getBitAtPosition(0);
}

void Register::pushBit(bool newBit)
{
    leftShift(1);
    mValue = (mValue | newBit); // check int & bool
}

void Register::leftShift(short shift)
{
    mValue = mValue << shift; //check circular bit shift or not
}
void Register::rightShift(short shift)
{
    mValue = mValue >> shift;
    //need to mask bits above nbits
    mValue = mValue & ((1<<nbits)-1);
}

void Register::leftCircularShift(short shift)
{
    //need to mask bits above nbits
    mValue = mValue & ((1<<nbits)-1);
    mValue = (mValue>>(nbits-shift)) | (mValue<<shift);
    //need to mask bits above nbits
    mValue = mValue & ((1<<nbits)-1);
}
void Register::rightCircularShift(short shift)
{
    //need to mask bits above nbits
    mValue = mValue & ((1<<nbits)-1);
    mValue = (mValue>>shift) | (mValue<<(nbits-shift));
    //need to mask bits above nbits
    mValue = mValue & ((1<<nbits)-1);
}
