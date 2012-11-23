//
//  ADSRChip.cpp
//  ChipLibraryTestBed
//
//  Created by Mayank on 10/13/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#include "ADSREnvelopeChip.h"
#include "math.h"
ADSREnvelopeChip::ADSREnvelopeChip()
{
    mEnvelopeValue=0;
    mEnvelopeValueFloat=0;
    mStage = -1;
    noteOnInput.setChip(this);
    clockInput.setChip(this);
    resetInput.setChip(this);
    output.setChip(this);
}
void ADSREnvelopeChip::setAttackTime(float withTime)
{
    aTime = withTime;
}
void ADSREnvelopeChip::setDecayTime(float withTime)
{
    dTime = withTime;
}
void ADSREnvelopeChip::setSustainLevel(float withLevel)
{
    sLevel = withLevel;
}
void ADSREnvelopeChip::setReleaseTime(float withTime)
{
    rTime = withTime;
}

void ADSREnvelopeChip::attack()
{
    mEnvelopeDeltaValueFloat = (1-mEnvelopeValueFloat)/(aTime*srate);
    mStage = 1;
}
void ADSREnvelopeChip::decay()
{
    mEnvelopeDeltaValueFloat = (sLevel - mEnvelopeValueFloat)/(dTime*srate);
    mStage = 2;
}
void ADSREnvelopeChip::sustain()
{
    mEnvelopeDeltaValueFloat = 0;
    mStage = 3;
}

void ADSREnvelopeChip::release()
{
    mEnvelopeDeltaValueFloat = -mEnvelopeValueFloat/(rTime*srate);
    mStage = 4;
}

void ADSREnvelopeChip::tick()
{
    clockInput.refreshInput();
    if (clockInput.getRisingEdge())
        clock();
    resetInput.refreshInput();
    
    if (noteOnInput.isConnected())
        noteOnInput.refreshInput();     // if not connected, then no error.. allows us to trigger independtly
    
    if (resetInput.getRisingEdge())
        reset();
}

void ADSREnvelopeChip::clock()
{
    output.outputRegister.leftCircularShift(1);
}

void ADSREnvelopeChip::reset()
{
    update();
    if (noteOnInput.isConnected())
        mNoteOn = noteOnInput.getInputBit();
    mEnvelopeValue = (mEnvelopeValueFloat * 0.5 + 0.5) * ((1<<nbits)-1);
    output.outputRegister.setValue(mEnvelopeValue);    // move from 0-1 to 0.5 - 1 to deal with the multiplier later
}

void ADSREnvelopeChip::update()
{
    mEnvelopeValueFloat += mEnvelopeDeltaValueFloat;
    mEnvelopeValueFloat = fmaxf(0,mEnvelopeValueFloat);
    if (!mNoteOn && noteOnInput.getInputBit())
        attack();
    else if (mNoteOn && !noteOnInput.getInputBit())
        release();
    if (mEnvelopeValueFloat>=1 && mEnvelopeDeltaValueFloat>0)
    {
        mEnvelopeValueFloat = 1;
        decay();
    }
    else if (mEnvelopeValueFloat<=sLevel && mEnvelopeDeltaValueFloat<0 && mStage == 2)
        sustain();
}