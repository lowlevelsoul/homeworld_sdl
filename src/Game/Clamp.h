// =============================================================================
//  Clamp.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 5/8/1998 by bpasechn
// =============================================================================

#ifndef ___CLAMP_H
#define ___CLAMP_H

#include "tiPlatform.h"
#include "SpaceObj.h"

// to expand clamping to others than just ships, must modify line
// in univupdate to check for more than just ships with clamp status

TI_API void clampObjToObj(SpaceObjRotImpTargGuidance *obj,SpaceObjRotImpTargGuidance *dest);
TI_API void unClampObj(SpaceObjRotImpTargGuidance *obj);
TI_API void updateClampedObject(SpaceObjRotImpTargGuidance *obj);

#endif
