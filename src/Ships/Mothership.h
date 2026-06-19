// =============================================================================
//  Mothership.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 6/30/1997 by gshaw
// =============================================================================

#ifndef ___MOTHERSHIP_H
#define ___MOTHERSHIP_H

#include "tiPlatform.h"
#include "SpaceObj.h"
#include "Types.h"

typedef struct
{
    sdword doorFlags;
    SpaceObjRotImpTargGuidanceShipDerelict *doorCargo;
    SpaceObjRotImpTargGuidanceShipDerelict *droptarget[MAX_NUM_DROP];
    sdword dropstate[MAX_NUM_DROP];
    sdword dockindex[MAX_NUM_DROP];
    sdword CAP_NumInBuildCue;
    sdword CAPshiptype[SALVAGE_MAX_CAPTURABLE];
    sdword CAPshiprace[SALVAGE_MAX_CAPTURABLE];
    real32 CAPTimeToBuildShip[SALVAGE_MAX_CAPTURABLE];
    ubyte CAPcolorScheme[SALVAGE_MAX_CAPTURABLE];
    ubyte freedocktimer[3];
} MothershipSpec;

typedef struct
{
    vector specialDoorOffset[NUM_RACES][TOTAL_NUM_SHIPS];
    sdword specialDoorOrientationHeading[NUM_RACES][TOTAL_NUM_SHIPS];
    sdword specialDoorOrientationUp[NUM_RACES][TOTAL_NUM_SHIPS];
    real32 specialDoorInterpolationPerSecond;
} MothershipStatics;

extern CustShipHeader MothershipHeader;

TI_API void MothershipAttachObjectToDoor(Ship *ship,SpaceObjRotImpTargGuidanceShipDerelict *object);
TI_API void mothershipCleanDoorForHSInstant(Ship *ship);
TI_API void MothershipDettachObjectFromDoor(Ship *ship);
TI_API void MothershipDoorUpKeep(Ship *ship);
TI_API void mothershipGetCargoPosition(Ship *ship,SpaceObjRotImpTargGuidanceShipDerelict *cargo, vector *position, matrix *coordsys, vector *heading, vector *up,vector *right);

#endif
