//
//  ADSRChip.h
//  ChipLibraryTestBed
//
//  Created by Mayank on 10/13/12.
//  Copyright (c) 2012 Mayank, Kurt. All rights reserved.
//

#ifndef __CircuitModel__ADSREnvelopeChip__
#define __CircuitModel__ADSREnvelopeChip__

#include <iostream>
#include "Chip.h"
#include "SingleBitInput.h"
#include "SerialOutput.h"
#include "EdgeTriggeredInput.h"

class ADSREnvelopeChip : public Chip
{protected:
    float aTime,dTime,sLevel,rTime;
    unsigned short mEnvelopeValue,mEnvelopeDeltaValue;
    float mEnvelopeValueFloat,mEnvelopeDeltaValueFloat;
    bool mNoteOn;
    short mStage;
public:
    ADSREnvelopeChip();
    void setAttackTime(float withTime);
    float getAttackTime() {return aTime;};
    float* getAttackTimeAddress() {return &aTime;};
    
    void setDecayTime(float withTime);
    float getDecayTime(){return dTime;};
    float* getDecayTimeAddress(){return &dTime;};

    void setSustainLevel(float withLevel);
    float getSustainLevel(){return sLevel;};
    float* getSustainLevelAddress(){return &sLevel;};
    
    void setReleaseTime(float withTime);
    float getReleaseTime(){return rTime;};
    float* getReleaseTimeAddress(){return &rTime;};

    unsigned short getEnvelopeValue(){return mEnvelopeValue;}
    unsigned short getEnvelopeValueFloat(){return mEnvelopeValueFloat;}
    unsigned short getEnvelopeDeltaValue(){return mEnvelopeDeltaValue;}
    unsigned short getEnvelopeDeltaValueFloat(){return mEnvelopeDeltaValueFloat;}
    
    bool getNoteOn() {return mNoteOn;}

    void update();
    void attack();
    void decay();
    void sustain();
    void release();
    
    void tick();
    void clock();
    void reset();
    
    EdgeTriggeredInput clockInput;
    EdgeTriggeredInput resetInput;
    SingleBitInput noteOnInput;
    SerialOutput output;
    virtual std::string description() {return "adsr";};

};
#endif /* defined(__CircuitModel__ADSRChip__) */
