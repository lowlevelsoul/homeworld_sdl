// =============================================================================
//  AIOrders.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
// =============================================================================

#ifndef ___AIORDERS_H
#define ___AIORDERS_H

#include "tiPlatform.h"
#include "AIUtilities.h"
#include "ShipSelect.h"

/*=============================================================================
    Constant Definitions:
=============================================================================*/
#define RECON_STANDOFF_DISTANCE     15000
#define HARASS_STANDOFF_DISTANCE    25000
#define HARASS_LIGHTINT_INITNUM     15
#define HARASS_LIGHTINT_REPLACE     12
#define HARASS_HEAVYINT_EQUIVNUM    14
#define HARASS_BOMBER_EQUIVNUM      14

/*=============================================================================
    Structures:
=============================================================================*/
typedef enum
{
    RECON_MOTHERSHIP,
    RECON_ACTIVE_GENERAL,
    RECON_ACTIVE_ENEMY,
    NUM_RECONTYPE
} ReconType;

typedef enum
{
    SUPPORT_STRIKECRAFT,
    SUPPORT_RESOURCE,
    SUPPORT_MOTHERSHIP,
    NUM_SUPPORTTYPE
} SupportType;

TI_API void aioCreateGuardShips(struct AITeam *team, SelectCommand *ships);
TI_API void aioCreateReconaissance(struct AITeam *team, ReconType type);
TI_API void aioCreateTakeoutTarget(struct AITeam *team,Ship *target);
TI_API void aioCreateHarass(struct AITeam *team);
TI_API void aioCreateTakeoutMothershipFast(struct AITeam *team,Ship *mothership);
TI_API void aioCreateTakeoutMothershipGuard(struct AITeam *team,Ship *mothership);
TI_API void aioCreateTakeoutMothershipHuge(struct AITeam *team, Ship *mothership);
TI_API void aioCreateTakeoutMothershipBig(struct AITeam *team,Ship *mothership, bool_t ForceBig);
TI_API void aioCreateTakeoutTargetsWithCurrentTeam(struct AITeam *team,SelectCommand *targets);
TI_API void aioCreateTakeoutTargetWithCurrentTeam(struct AITeam *team,Ship *ship);
TI_API void aioCreateFancyTakeoutTarget(struct AITeam *team,Ship *target);
TI_API void aioCreateDefendMothership(struct AITeam *team);
TI_API void aioCreatePatrol(struct AITeam *team, Path *path);
TI_API void aioCreateFastRovingDefense(struct AITeam *team);
TI_API void aioCreateSlowRovingDefense(struct AITeam *team);
TI_API void aioCreateActiveSupport(struct AITeam *team, SelectCommand *ships, SupportType type);
TI_API void aioCreateFighterStrike(struct AITeam *team);
TI_API void aioCreateCorvetteStrike(struct AITeam *team);
TI_API void aioCreateFrigateStrike(struct AITeam *team);
TI_API void aioCreateResourcer(struct AITeam *team);
TI_API void aioCreateCapture(struct AITeam *team);
TI_API void aioCreateMine(struct AITeam *team);
TI_API void aioCreateSpecialDefense(struct AITeam *team, ShipType type);
TI_API void aioCreateSwarmAttack(struct AITeam *team);
TI_API void aioCreateSwarmDefense(struct AITeam *team, SelectCommand *Pod);
TI_API void aioCreateSwarmSupport(struct AITeam *team);
TI_API void aioCreateMultiBeamAttack(struct AITeam *team);
TI_API void aioCreateP2MothershipAttack(struct AITeam *team);

TI_API void aioCreateTakeoutMothershipFast(struct AITeam *team,Ship *mothership);
TI_API void aioCreateTakeoutMothershipBig(struct AITeam *team,Ship *mothership, bool_t ForceBig);
TI_API void aioCreateTakeoutMothershipHuge(struct AITeam *team,Ship *mothership);
TI_API void aioCreateTakeoutMothershipGuard(struct AITeam *team,Ship *mothership);
TI_API void aioCreateTakeoutTargetsWithCurrentTeam(struct AITeam *team,SelectCommand *targets);
TI_API void aioCreateTakeoutTargetWithCurrentTeam(struct AITeam *team,Ship *ship);
TI_API void aioCreateTakeoutTarget(struct AITeam *team,Ship *target);
TI_API void aioCreateFancyTakeoutTarget(struct AITeam *team,Ship *target);

#endif
