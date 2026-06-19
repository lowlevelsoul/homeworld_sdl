// =============================================================================
//  AIHandler.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 6/19/1998 by fpoiker
// =============================================================================

#ifndef ___AIHANDLER_H
#define ___AIHANDLER_H

#include "tiPlatform.h"
#include "AITeam.h"

#define GENERIC_STRENGTHRATIO   1.5

/*=============================================================================
    Function Prototypes:
=============================================================================*/
TI_API void aihGenericEmptyFuelHandler(AITeam *team);
TI_API void aihSwarmerEmptyFuelHandler(AITeam *team);
TI_API void aihGenericFuelLowHandler(AITeam *team);
TI_API void aihHarassNumbersLowHandler(AITeam *team);
TI_API void aihHarassFiringSingleShipHandler(AITeam *team);
TI_API void aihHarassDisengageSingleShipHandler(AITeam *team);
TI_API void aihKamikazeHealthLowHandler(AITeam *team);
TI_API void aihFastDefenseNumbersLowHandler(AITeam *team);
TI_API void aihSlowDefenseNumbersLowHandler(AITeam *team);
TI_API void aihGenericGettingRockedHandler(AITeam *team, SelectCommand *ships);
TI_API void aihPatrolEnemyNearbyHandler(AITeam *team, SelectCommand *ships);
TI_API void aihGravWellEnemyNearbyHandler(AITeam *team, SelectCommand *ships);
TI_API void aihGravWellEnemyNotNearbyHandler(AITeam *team);
TI_API void aihFastDefenseDistressHandler(AITeam *team, udword *intvar);
TI_API void aihSlowDefenseDistressHandler(AITeam *team, udword *intvar);

//team died handlers
TI_API void aihFastDefenseTeamDiedHandler(AITeam *team);
TI_API void aihSlowDefenseTeamDiedHandler(AITeam *team);
TI_API void aihGuardShipsTeamDiedHandler(AITeam *team);
TI_API void aihReconaissanceTeamDiedHandler(AITeam *team);
TI_API void aihReconShipTeamDiedHandler(AITeam *team);
TI_API void aihHarassTeamDiedHandler(AITeam *team);
TI_API void aihPatrolTeamDiedHandler(AITeam *team);
TI_API void aihRemoveTeamDiedHandler(AITeam *team);


#endif
