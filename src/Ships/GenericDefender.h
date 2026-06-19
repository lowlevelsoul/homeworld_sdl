// =============================================================================
//  GenericDefender.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 6/30/1997 by gshaw
// =============================================================================

#ifndef ___GENERICDEFENDER_H
#define ___GENERICDEFENDER_H

#include "tiPlatform.h"
#include "SpaceObj.h"

extern CustShipHeader GenericDefenderHeader;

TI_API void doKamikazeAttack(Ship *ship, SpaceObjRotImpTarg *target);

#endif
