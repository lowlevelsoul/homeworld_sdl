// =============================================================================
//  DDDFrigate.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 6/30/1997 by gshaw
// =============================================================================

#ifndef ___DDDFRIGATE_H
#define ___DDDFRIGATE_H

#include "tiPlatform.h"
#include "SpaceObj.h"
#include "Types.h"

#define MAX_NUM_DRONES      24

typedef struct
{
    udword DDDstate;
    real32 lasttimeRegenerated;
    ShipPtr DronePtrs[MAX_NUM_DRONES];
} DDDFrigateSpec;

typedef struct
{
    real32 attackRange;
    real32 tooCloseRange;
    real32 internalRegenerateRate;
    real32 externalRegenerateRate;
    real32 droneDeploymentRange;
} DDDFrigateStatics;

extern CustShipHeader DDDFrigateHeader;

TI_API void DDDFrigateDockAllDronesInstantly(Ship *ship);
TI_API void DDDFrigateJustDisabled(Ship *ship);
TI_API void DDDFrigateMakeReadyForHyperspace(Ship *ship);
TI_API void DDDFrigateMakeSureItCanGuard(Ship *ship);
TI_API void DDDFrigateSwitchSides(Ship *dddf, sdword player);

#endif
