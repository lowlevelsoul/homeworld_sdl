// =============================================================================
//  Alliance.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 7/31/1998 by ddunlop
// =============================================================================

#ifndef ___ALLIANCE_H
#define ___ALLIANCE_H

#include "tiPlatform.h"
#include "CommandNetwork.h"
#include "Types.h"
#include "Universe.h"

// INTERFACE -------------------------------------------------------------------

#define ALLIANCE_FORM_NEW_ALLIANCE   1
#define ALLIANCE_BREAK_ALLIANCE      2

TI_API void allianceFormWith(udword playerindex);
TI_API void allianceBreakWith(udword playerindex);
TI_API void allianceFormRequestRecievedCB(ChatPacket *packet);
TI_API void allianceSetAlliance(udword AllianceType, uword playerone, uword playertwo);

TI_API bool_t allianceIsShipAlly(Ship *ship, Player *player);
TI_API bool_t allianceArePlayersAllied(Player *playerone, Player *playertwo);

TI_API void allianceBreakAll(void);

#endif
