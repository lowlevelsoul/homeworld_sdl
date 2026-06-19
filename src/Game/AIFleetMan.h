// =============================================================================
//  AIFleetMan.h
//  - Controls construction of ships requested from combatman, defenseman, resourceman
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 1998/05/28 by gshaw
// =============================================================================

#ifndef ___AIFLEETMAN_H
#define ___AIFLEETMAN_H

#include "tiPlatform.h"
#include "AIPlayer.h"

TI_API void aifFleetCommand(void);

TI_API void aifInit(AIPlayer *aiplayer);
TI_API void aifClose(void);

TI_API void aifTeamDied(AIPlayer *aiplayer, AITeam *team, bool removeAllReferencesToTeam);

TI_API bool aifShipDied(AIPlayer *aiplayer, ShipPtr ship);

TI_API void aifResourceManRequestsShipsCB(ShipType shiptype, sdword number, sdword priority);
TI_API void aifAttackManRequestsShipsCB(ShipType shiptype, sdword number, sdword priority);
TI_API void aifDefenseManRequestsShipsCB(ShipType shiptype, sdword number, sdword priority);

TI_API void aifTeamRequestsShipsCB(ShipType shiptype, sdword number, AITeam *team, char *doneSetVar, sdword priority);

TI_API void aifHyperspaceInit(AIPlayer *aiplayer);

#endif
