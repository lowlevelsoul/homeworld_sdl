// =============================================================================
//  Bounties.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created oct 6th, bpasechn
// =============================================================================

#ifndef ___BOUNTIES_H
#define ___BOUNTIES_H

#include "tiPlatform.h"
#include "Universe.h"

TI_API void BountyInit(sdword bountySettingSize);
TI_API sdword getPlayerBountyRender(Player *player);
void calculatePlayerBounties(void);                   //updates all players 'bounty' variable

TI_API sdword getBountyOnShip(Ship *ship);
TI_API void bountyShipWasKilled(Ship *ship);

#endif
