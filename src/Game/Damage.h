/*=============================================================================
    Name    : damage.h
    Purpose : things necessary for showing ship damage

    Created 7/30/1998 by khent
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___DAMAGE_H
#define ___DAMAGE_H

#include "tiPlatform.h"
#include "SpaceObj.h"

#ifdef HW_BUILD_FOR_DEBUGGING

#define DMG_VERBOSE_LEVEL   1

#else

#define DMG_VERBOSE_LEVEL   0

#endif

TI_API void dmgStartup(void);
TI_API void dmgShutdown(void);
TI_API void dmgShipThink(Ship* ship);
TI_API void dmgStopEffect(Ship* ship, sdword level);
TI_API void dmgStopSingleEffect(Effect* effect);
TI_API void dmgForgetEffects(Ship* ship);
TI_API void dmgGetLights(Ship* ship);
TI_API void dmgClearLights(Ship* ship);

#endif
