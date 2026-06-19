// =============================================================================
//  SalCapCorvette.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 11/5/1997 by khent
// =============================================================================

#ifndef ___SALCAPCORVETTE_H
#define ___SALCAPCORVETTE_H

#include "tiPlatform.h"
#include "Attack.h"
#include "ShipSelect.h"
#include "render.h"

#define SALVAGE_AT_GET_TECH       0x01

#define SAL_WL_FLYTOCONEORIGIN    7

typedef struct
{
    AttackSideStep attacksidestep;
    sdword salvageState;               //sal/cap corv aistate for salvaging
    SpaceObjRotImpTargGuidanceShipDerelict *target;
    Ship *dockwith;
    sdword dockindex;
    sdword salvageIndex;
    sdword salvageAttributes;
    real32 timeCounter;
    real32 getTechTime;
    sdword tractorBeam;
    sdword noAvoid;
    real32 noDamageTargetTime;
    sdword groupme;
	SpaceObjRotImpTargGuidanceShipDerelict *noDamageTarget;
} SalCapCorvetteSpec;

typedef struct
{
    AttackSideStepParameters sidestepParameters;
    real32 HealthThreshold;
    real32 healthRemovedPerSecond;
    real32 getTechTime;
    real32 flyToDistance;
    real32 maxPushingVelocitySingle;
    real32 noLightClampingDistance;
} SalCapCorvetteStatics;

extern CustShipHeader JunkYardDawgHeader;
extern CustShipHeader SalCapCorvetteHeader;

TI_API bool_t DropTargetInShip(Ship *dockwith,sdword *targetDepotState, SpaceObjRotImpTargGuidanceShipDerelict *target,sdword *dockindex);
TI_API bool_t isThereAnotherTargetForMe(Ship *ship,SelectAnyCommand *targets);
TI_API void salCapCleanUpCloakingTarget(Ship *ship, Ship *shiptoremove);
TI_API void salCapClearTechBool(void);
TI_API void SalCapDropTarget(Ship *ship);
TI_API void salCapExtraSpecialOrderCleanUp(SelectCommand *selection,udword ordertype,Ship *dockwith,SelectCommand *targets);
TI_API void salCapHarvestTarget(SpaceObjRotImpTargGuidanceShipDerelict *target,Ship *dockwith);
TI_API sdword salCapNeedBig(Ship *ship,SpaceObjRotImpTargGuidanceShipDerelict *target);
TI_API void SalCapOrderChangedCleanUp(Ship *ship);
TI_API void salCapRemoveDerelictReferences(Ship *ship,Derelict *d);

#if RND_VISUALIZATION
TI_API void dockDrawSalvageInfo(SpaceObjRotImpTargGuidanceShipDerelict *obj);
#endif

#endif
