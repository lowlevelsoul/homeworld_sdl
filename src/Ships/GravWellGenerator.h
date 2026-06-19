// =============================================================================
//  GravWellGenerator.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 01/06/1998 by bpasechnik
// =============================================================================

#ifndef ___GRAVWELLGENERATOR_H
#define ___GRAVWELLGENERATOR_H

#include "tiPlatform.h"
#include "LinkedList.h"
#include "SpaceObj.h"
#include "Types.h"

typedef struct
{
    real32 GravWellRadius;
    real32 GravWellRadiusSqr;
    real32 OperationTime;
    real32 EffectConstant;
    udword scanrate;
    real32 repulseForce;
    real32 warmupdowntime;
    real32 xrot;
    real32 yrot;
    real32 zrot;
} GravWellGeneratorStatics;

typedef struct
{
    sdword GravFieldOn;
    sdword GravFired;
    LinkedList  GravList;
    real32 TimeOn;
    real32 powertime;
    sdword ready;
    sdword GravDerelict;
    Effect *gravityEffect;
} GravWellGeneratorSpec;

extern CustShipHeader GravWellGeneratorHeader;

TI_API void GravWellGeneratorJustDisabled(Ship *ship);
TI_API bool_t gravwellIsShipStuckForHyperspaceing(Ship *ship);
TI_API void turnoffGravwell(Ship *ship);

#endif
