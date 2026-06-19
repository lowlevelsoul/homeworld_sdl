// =============================================================================
//  AIAttackMan.h
//  - Attack manager
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 1998/05/28 by gshaw
// =============================================================================

#ifndef ___AIATTACKMAN_H
#define ___AIATTACKMAN_H

#include "tiPlatform.h"
#include "AIPlayer.h"
#include "AITeam.h"

TI_API AITeam *aiaSendRecon(SelectCommand *ships);
TI_API void aiaAttackManager(void);
TI_API void aiaProcessSpecialTeams(void);
TI_API bool aiaShipDied(AIPlayer *aiplayer, ShipPtr ship);
TI_API void aiaTeamDied(AIPlayer *aiplayer, AITeam *team);

TI_API void aiaP2AttackManager(void);

TI_API void aiaInit(AIPlayer *aiplayer);
TI_API void aiaClose(AIPlayer *aiplayer);

#endif

