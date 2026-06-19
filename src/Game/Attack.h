// =============================================================================
//  Attack.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 10/7/1997 by gshaw
// =============================================================================

#ifndef ___ATTACK_H
#define ___ATTACK_H

#include "tiPlatform.h"
#include "SpaceObj.h"
#include "StatScript.h"

typedef struct
{
    real32 aitime;           // AI timestamp variable
    udword aidirection;      // AI miscellaneous variable
} AttackSideStep;

typedef struct
{
    real32 repositionTime;
    real32 circleRange;
    bool_t fullMovementFreedom;
} AttackSideStepParameters;

TI_API void attackPassiveRotate(Ship *ship,Ship *target);

TI_API void attackSideStepInit(AttackSideStep *attacksidestep);
TI_API void attackSideStep(Ship *ship,SpaceObjRotImpTarg *target,AttackSideStep *attacksidestep,AttackSideStepParameters *parameters);

TI_API void attackStraightForward(Ship *ship,SpaceObjRotImpTarg *target,real32 gunRange,real32 tooCloseRange);

TI_API void attackPassive(Ship *ship,Ship *target);

TI_API void attackSimple(Ship *ship,SpaceObjRotImpTarg *target);

/*=============================================================================
    Data:
=============================================================================*/

extern scriptStructEntry AttackSideStepParametersScriptTable[];

#endif

