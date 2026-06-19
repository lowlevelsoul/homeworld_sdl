// =============================================================================
//  AIDefenseMan.h
//  - Defense manager
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 1998/05/28 by gshaw
// =============================================================================

#ifndef ___AIDEFENSEMAN_H
#define ___AIDEFENSEMAN_H

#include "tiPlatform.h"
#include "AIPlayer.h"

TI_API void aidDefenseManager(void);
TI_API bool aidShipDied(AIPlayer *aiplayer, ShipPtr ship);
TI_API void aidTeamDied(AIPlayer *aiplayer, AITeam *team);

TI_API void aidInit(AIPlayer *aiplayer);
TI_API void aidClose(AIPlayer *aiplayer);

TI_API void aidSendDistressSignal(SelectCommand *ships);
TI_API void aidClearDistressSignal(AIPlayer *aiplayer);

#endif

