// =============================================================================
//  AIResourceMan.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 5/27/1998 by gshaw
// =============================================================================

#ifndef ___AIRESOURCEMAN_H
#define ___AIRESOURCEMAN_H

#include "tiPlatform.h"
#include "AIPlayer.h"

TI_API void airResourceManager(void);

TI_API void airInit(AIPlayer *aiplayer);
TI_API void airClose(AIPlayer *aiplayer);

TI_API bool_t airShipDied(AIPlayer *aiplayer, ShipPtr ship);
TI_API void airTeamDied(AIPlayer *aiplayer, AITeam *team);

TI_API sdword NumberOfEasilyAccesibleRUs(Player *player);
TI_API sdword NumRUDockPointsOnThisShip(Ship *ship);

TI_API void airAddNewShip(Ship *ship);
TI_API void airProcessSpecialTeams(void);

#endif

