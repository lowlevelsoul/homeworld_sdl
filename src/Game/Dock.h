/*=============================================================================
    Name    : Dock.h
    Purpose : Definitions for dock.c

    Created 11/25/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___DOCK_H
#define ___DOCK_H

#include "tiPlatform.h"
#include "render.h"
#include "ShipSelect.h"
#include "SpaceObj.h"

#define DOCK_FOR_BOTHREFUELANDREPAIR    1
#define DOCK_FOR_REFUEL                 2
#define DOCK_FOR_REPAIR                 4
#define DOCK_TO_DEPOSIT_RESOURCES       8       // for DockType
#define DOCK_PERMANENTLY                16
#define DOCK_FOR_RESEARCH               32      //special docking for Research Ships
#define DOCK_AT_SPECIFIC_SHIP           64      //dock at a ship specified by user, which is parameter dockwith of clDock
#define DOCK_FOR_REFUELREPAIR           (DOCK_FOR_REFUEL|DOCK_FOR_REPAIR)
#define DOCK_STAY_TILL_EXPLICITLAUNCH   128
#define DOCK_INSTANTANEOUSLY            256
#define DOCK_FOR_RETIRE                 512
typedef udword DockType;

typedef struct
{
    DockType dockType;
    udword formationToGoIntoAfterDockingID;
    bool8 wasHarvesting;
    bool8 allDockingWithSameShip;
    bool8 allNearShip;
    bool8 haveFlyedFarEnoughAway;
} DockCommand;

#if RND_VISUALIZATION
TI_API void dockDrawDockInfo(Ship *ship);
#endif

TI_API void dockInitializeCustomFunctions(ShipStaticInfo *statinfo,ShipType type,ShipRace race);

TI_API sdword dockFindDockIndex(char *name,DockStaticInfo *dockstaticinfo);
/*static void dockReserveDockPoint(Ship *ship,Ship *dockwith,sdword dockpointindex);*/
/*void dockReserveDockPoint(Ship *ship,Ship *dockwith,sdword dockpointindex);*/

TI_API void dockPutShipInside(Ship *ship,Ship *dockwith);
TI_API void dockInitShipForLaunch(Ship *ship);
TI_API void dockRemoveShipFromInside(Ship *ship,Ship *dockwith);
TI_API void dockPutShipOutside(Ship *ship,Ship *creator,vector *createat,udword headingdirection,udword updirection);

TI_API void RemoveShipFromLaunching(Ship *ship);
TI_API void RemoveShipFromDocking(Ship *ship);

TI_API void dockPrepareSingleShipForLaunch(Ship *ship,Ship *dockship);
TI_API void dockChangeSingleShipToDock(struct CommandToDo *command,Ship *ship,Ship *dock,bool wasHarvesting,DockType dockType);
TI_API void DockCleanup(struct CommandToDo *docktodo);
TI_API void LaunchCleanup(struct CommandToDo *launchtodo);
TI_API bool processDockToDo(struct CommandToDo *docktodo);

TI_API bool ShipWithinDockRange(Ship *ship,Ship *target);
TI_API Ship *FindNearestShipToDockAt(Ship *ship,DockType dockType);

// specific docking for certain ships
TI_API bool LaunchShipFromDDDF(Ship *ship,Ship *dockwith);
TI_API bool DroneDocksAtDDDF(struct Ship *ship,struct Ship *dockwith);
TI_API void dockPrepareDroneForDocking(Ship *ship,Ship *dockship);

TI_API bool ShipIsRefuelingAtCarrierMother(struct Ship *ship);
TI_API bool ShipIsWaitingForSoftLaunch(struct Ship *ship);
TI_API Ship *FindAnotherResearchShiptoDockWith(Ship *ship);
TI_API void dockMakeMaster(Ship *master);
TI_API void dockAddSlave(Ship *master, Ship *slave);
TI_API void bitClearAllSlaves(Ship *ship);

TI_API sdword **GetLaunchPoints(ShipStaticInfo *shipstatic,ShipStaticInfo *dockwithstatic);

TI_API DockType dockGetAppropriateTypeOfDocking(SelectCommand *selectcom);

//slaveables...
TI_API void dockDealWithDeadSlaveable(Ship *ship);
TI_API void dockUpdateSlaves(Ship *master);
TI_API void dockCrushMaster(Ship *master);

typedef struct
{
    sdword size;
    real32 dockmisc;
    sdword docktoindex;
    sdword dockingindex;
} AtResearchShipDockInfo;

/*  Defines needed in another file */
#define ASF_WAITLATCHPOINT     1
#define ASF_FLYTOINSIDECONE    2
#define ASF_FLYTOCONEORIGIN    3
#define ASF_REFUEL             4
#define ASF_BACKUP             5
#define ASF_WAIT               6

#endif

