/*=============================================================================
    Name    : Stats.h
    Purpose : Definitions for Stats.c

    Created 4/1/1998 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___STATS_H
#define ___STATS_H

#include "tiPlatform.h"
#include "ShipDefs.h"
#include "ShipSelect.h"
#include "StatScript.h"
#include "Types.h"

#define NUM_SHIPS_TO_GATHER_STATS_FOR   (TOTAL_STD_SHIPS+TOTAL_STD_SHIPS+TOTAL_P1_SHIPS+TOTAL_P2_SHIPS+TOTAL_P3_SHIPS)

typedef struct FightStats
{
    ubyte shiptype[2];
    ubyte shiprace[2];

    ubyte numShips[2];
    ubyte numShipsAfter[2];
    real32 totalHPAfter[2];

//    real32 numFracShipsAfter[2];
//    real32 RUratio;        // numRUsDead[1] / numRUsDead[0]
//    real32 Killratio;      // numShipsDied[1] / numShipsDied[0]
    real32 fracRUratio;    // same as above, but uses fractional ships
    real32 fracKillratio;  // same as above, but uses fractional ships
    real32 battleTime;     // length in seconds of battle

} FightStats;

typedef struct FightStatsSum
{
    real32 RUratio;
    real32 Killratio;
} FightStatsSum;

#define FightStatsCalculated(fightstats) (fightstats.numShips[0])
#define FightStatsPtrCalculated(fightstats) (fightstats->numShips[0])

#define MAX_SHIPS_TO_EVER_CONSIDER      30

extern FightStats FightStatsTable[NUM_SHIPS_TO_GATHER_STATS_FOR][NUM_SHIPS_TO_GATHER_STATS_FOR];

extern FightStatsSum FightStatsColumnSum[NUM_SHIPS_TO_GATHER_STATS_FOR];
extern FightStatsSum FightStatsRowSum[NUM_SHIPS_TO_GATHER_STATS_FOR];

extern bool_t ShowFancyFights;

/*=============================================================================
    Functions:
=============================================================================*/

TI_API void statsGatherFightStats(void);
TI_API void statsLoadFightStats(void);
TI_API void statsPrintTable(void);
TI_API void statsShowFight(sdword i,sdword j);
TI_API void statsShowFancyFight(sdword i,sdword j);
TI_API void statsShowFancyFightUpdate(void);

TI_API void statsSetOverkillfactor(real32 factor);

TI_API real32 statsGetShipRURatingAgainstShip(ShipStaticInfo *thisShip,ShipStaticInfo *againstShip);
TI_API real32 statsGetShipKillRatingAgainstShip(ShipStaticInfo *thisShip,ShipStaticInfo *againstShip);
TI_API real32 statsGetOverallRURating(ShipStaticInfo *shipstatic);
TI_API real32 statsGetOverallKillRating(ShipStaticInfo *shipstatic);

typedef bool_t (*statShipConstraintsCB)(ShipStaticInfo *shipstatic);
//typedef bool_t (*ShipConstraintsCB)(Ship *ship);
TI_API bool_t ShipConstraintsNoneCB(Ship *ship);
TI_API bool_t statShipConstraintsNoneCB(ShipStaticInfo *shipstatic);
TI_API bool_t statShipConstraintsFrigatesOrWorseCB(ShipStaticInfo *shipstatic);
TI_API bool_t statShipConstraintsFrigatesOrBetterCB(ShipStaticInfo *shipstatic);
TI_API bool_t statShipConstraintsFightingShipsCB(ShipStaticInfo *shipstatic);
TI_API bool_t statShipConstraintsCarrierFightingShipsCB(ShipStaticInfo *shipstatic);

TI_API real32 statsGetKillRatingAgainstFleet(ShipStaticInfo *shipstatic,SelectCommand *fleet);
TI_API real32 statsGetRURatingAgainstFleet(ShipStaticInfo *shipstatic,SelectCommand *fleet);
TI_API Ship *statsGetMostDangerousShipNonStatConstraints(SelectCommand *selection,ShipConstraintsCB constraintsCB);
#define statsGetMostDangerousShip(sel) statsGetMostDangerousShipNonStatConstraints(sel,ShipConstraintsNoneCB)

TI_API real32 statsGetKillRatingAgainstFleetStatic(ShipStaticInfo *shipstatic,SelectCommandStatic *fleetStatic);
TI_API real32 statsGetRURatingAgainstFleetStatic(ShipStaticInfo *shipstatic,SelectCommandStatic *fleetStatic);
TI_API ShipStaticInfo *statsGetMostDangerousShipStaticConstraints(SelectCommandStatic *selection,statShipConstraintsCB constraintsCB);
#define statsGetMostDangerousShipStatic(sel) statsGetMostDangerousShipStaticConstraints(sel,statShipConstraintsNoneCB)

TI_API ShipStaticInfo *statsBestShipToBuyToKillShip(ShipRace shipRace,statShipConstraintsCB constraintsCB,ShipStaticInfo *targetstatic);
TI_API ShipStaticInfo *statsBestShipToBuyToKillFleet(ShipRace shipRace,statShipConstraintsCB constraintsCB,SelectCommand *targetFleet);
TI_API ShipStaticInfo *statsBestShipToBuyToKillFleetStatic(ShipRace shipRace,statShipConstraintsCB constraintsCB,SelectCommandStatic *targetFleetStatic);
TI_API Ship *statsBestShipToUseToKillShip(SelectCommand *freeShips,ShipStaticInfo *targetstatic);
TI_API Ship *statsBestShipToUseToKillFleet(SelectCommand *freeShips,SelectCommand *targetFleet);

TI_API sdword statsNumShipsNeededToKillTarget(ShipStaticInfo *shipstatic,ShipStaticInfo *targetstatic);
TI_API sdword statsNumShipsNeededToKillFleet(ShipStaticInfo *shipstatic,SelectCommand *targetFleet);

// strength of fleet2 against fleet1, e.g. fleet2/fleet1
TI_API real32 statsGetRelativeFleetStrengths(SelectCommand *fleet1,SelectCommand *fleet2);
// strength of ship against fleet strength, e.g. targetstatic strength / fleet1 strength
TI_API real32 statsGetRelativeFleetStrengthAgainstShip(SelectCommand *fleet1,ShipStaticInfo *targetstatic);

TI_API SelectCommand *statsBestShipsToUseToKillTarget(SelectCommand *freeships,ShipStaticInfo *targetstatic,bool_t *goodEnough);
TI_API SelectCommand *statsBestShipsToUseToKillFleet(SelectCommand *freeships,SelectCommand *targetFleet,bool_t *goodEnough);

// returns a selection of ships which are efficient for killer to kill
// efficiencyFactor should be < 1, and the lower it is, the more ships killer will think it can take out
TI_API SelectCommand *statsGetMostEfficientShipsToKill(ShipStaticInfo *killer,SelectCommand *fleet,real32 efficiencyFactor);



/*=============================================================================
    Cheat detection:
=============================================================================*/
// returns a checksum of the statistics gathered by the game
/*real32 statsGetStatsChecksum(void)*/
TI_API udword statsGetStatChecksum(void);

#endif
