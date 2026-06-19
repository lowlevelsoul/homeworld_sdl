// =============================================================================
//  ConsMgr.h
//  - construction manager
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 7/18/1997 by lmoloney
// =============================================================================

#ifndef ___CONSMGR_H
#define ___CONSMGR_H

#include "tiPlatform.h"
#include "ClassDefs.h"
#include "ObjTypes.h"
#include "Region.h"
#include "ShipDefs.h"
#include "SpaceObj.h"
#include "Task.h"

/*=============================================================================
    Switches:
=============================================================================*/
#ifdef HW_BUILD_FOR_DEBUGGING
    #define CM_ERROR_CHECKING       1    // general error checking
    #define CM_VERBOSE_LEVEL        2    // print extra info
    #define CM_CAP_JOBS_PER_CLASS   0
    #define CM_CHEAP_SHIPS          1    // enable the 'cheapShips' flag
#else
    #define CM_ERROR_CHECKING       0
    #define CM_VERBOSE_LEVEL        0
    #define CM_CAP_JOBS_PER_CLASS   0
    #define CM_CHEAP_SHIPS          0
#endif

/*=============================================================================
    Type definitions:
=============================================================================*/
//structure for a ship under construction
typedef struct
{
    sdword nJobs;
    sdword nJobsTotal;
    sdword timeStart;
    sdword timeLeft;
    sdword timeFraction; // Simulates floating point so that fraction is accounted for in decrement
    sdword selected;
    sdword paused;
    sdword costSoFar;
    ShipStaticInfo *info;
}
shipinprogress;
//structure for all ships under construction at a certain site
typedef struct
{
    Node node;
    struct Ship *ship;
    bool canBuildBigShips;
    shipinprogress progress[TOTAL_STD_SHIPS];
}
shipsinprogress;

//ships available
typedef struct
{
    sdword nJobs;
    sbyte  itemtype;
    sbyte  itemstat;
    ShipType type;
    ShipStaticInfo *info;
}
shipavailable;



typedef struct
{
    sword       key;
    ShipType    ship;
}
KeysToShips;


typedef struct
{
    struct Ship   *ship;
    struct Player *owner;
}
CarrierInfo;


/*=============================================================================
    Data:
=============================================================================*/

extern CarrierInfo *cmCarriers;
extern sdword cmNumCarriers;
extern sdword cmNumPlayersCarriers;


#if CM_CHEAP_SHIPS
extern bool cmCheapShips;
#endif

#define CM_SHIFT 256

extern KeysToShips cmShipTypes[];
extern bool cmPrintHotKey;

extern sdword shiplagtotals[TOTAL_NUM_SHIPS];

extern bool cmActive;

extern sdword cmMaxJobsPerClass[NUM_CLASSES];

/*=============================================================================
    Functions:
=============================================================================*/
TI_API void cmStartup(void);
TI_API void cmShutdown(void);
TI_API void cmLoadTextures(void);
TI_API void cmCloseTextures(void);

// cancels all jobs of a certain shiptype
TI_API void cmForceBuildShipType(ShipType type);

void cmReset(void); // Free carrier ship pointers used by construction manager

//start the construction manager.  It will kill itself when you hit the quit button.
TI_API sdword cmConstructionBegin(regionhandle region, smemsize ID, udword event, udword data);

//start a new build job
TI_API void cmBuildJobsAdd(shipsinprogress *factory, ShipStaticInfo *info, sdword index);

TI_API void cmAddFactory(struct Ship *ship,bool canBuildBigShips);
TI_API void cmRemoveFactory(struct Ship *ship);

TI_API void cmCloseIfOpen(void);

TI_API bool cmCanBuildShipType(Ship *factoryship,ShipType shiptype,bool checkResearch);

TI_API bool cmBuildHotKey(keyindex key, bool shift);
TI_API ShipType cmKeyToShipType(uword key);
TI_API uword cmShipTypeToKey(ShipType ship);

TI_API void cmUpdateShipsAvailable(void);

TI_API void cmPauseAllJbos(void);
TI_API void cmUnPauseAllJobs(void);

#define CMD_START   1
#define CMD_PAUSE   2
#define CMD_UNPAUSE 3
#define CMD_CANCEL  4

void cmDeterministicBuild(udword command, sdword numShips,
                          ShipType shipType, ShipRace shipRace,
                          uword playerIndex, ShipPtr creator);
TI_API void cmDeterministicBuildProcess(void);
TI_API void cmDeterministicBuildDisplay(void);
TI_API void cmDeterministicReset(void);
// Not really a task anymore.
TI_API void cmBuildTaskFunction(void);

TI_API void LoadConsMgrDetermOptional(void);
TI_API void SaveConsMgrDetermOptional(void);

#endif
