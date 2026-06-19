// =============================================================================
//  DefaultShip.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 6/30/1997 by gshaw
// =============================================================================

#ifndef ___DEFAULTSHIP_H
#define ___DEFAULTSHIP_H

#include "tiPlatform.h"
#include "SpaceObj.h"

extern CustShipHeader DefaultShipHeader;
extern CustShipHeader DoNothingShipHeader;
extern CustShipHeader StationaryGunHeader;
extern CustShipHeader MiningBaseHeader;

TI_API void DefaultShipFire(Ship *ship, SpaceObjRotImpTarg *target);

#endif
