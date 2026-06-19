/*=============================================================================
        Name    : hs.h
        Purpose : hyperspace rendering & management routines

Created 7/10/1998 by khent
Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___HS_H
#define ___HS_H

#include "tiPlatform.h"
#include "SpaceObj.h"

TI_API void hsStart(Ship* ship, real32 cliptDelta, bool into, bool displayEffect);
TI_API void hsContinue(Ship* ship, bool displayEffect);
TI_API void hsEnd(Ship* ship, bool displayEffect);
TI_API void hsUpdate(Ship* ship);
TI_API void hsFinish(Ship* ship);
TI_API bool hsShouldDisplayEffect(Ship* ship);

#define HS_STATIC_ACTIVE        1
#define HS_STATIC_COLLAPSING    2
#define HS_STATIC_EXPANDING     3

#define HSGATE_LABEL_LEN        16

typedef struct hsStaticGate
{
    bool   active;
    vector position;
    real32 rotation;
    sdword state;
    sdword counter;
    Derelict *derelict;
    char label[HSGATE_LABEL_LEN];
} hsStaticGate;

// for hyperspace gates
TI_API void hsDerelictDied(Derelict *derelict);
TI_API void hsDerelictTakesDamage(Derelict *derelict);

void hsStaticInit(sdword nVectors); //level start (init structs)
void hsStaticReset(void);   //level reset (clear structs)
void hsStaticDestroy(hvector*); //destroy a gate
void hsSetStaticData(sdword size, ubyte* data); //set static gate data (for loading)
void hsStaticRender(void);  //render all static gates
TI_API void hsNoGate(bool state);

TI_API void SaveHyperspaceGates(void);
TI_API void LoadHyperspaceGates(void);

TI_API Derelict *GetHyperspaceGateFromVector(vector *compare);

#endif
