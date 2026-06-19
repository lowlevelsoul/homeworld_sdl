/*=============================================================================
    Name    : univupdate.h
    Purpose : Definitions for univupdate.c

    Created 10/4/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___UNIVUPDATE_H
#define ___UNIVUPDATE_H

#include "tiPlatform.h"
#include "LinkedList.h"
#include "ShipSelect.h"
#include "SpaceObj.h"
#include "Types.h"

/*=============================================================================
    Types:
=============================================================================*/

typedef struct DeleteShip
{
    Node objlink;
    Ship *ship;
    sdword deathBy;
} DeleteShip;

typedef struct DeleteResource
{
    Node objlink;
    Resource *resource;
} DeleteResource;

typedef struct DeleteMissile
{
    Node objlink;
    Missile *missile;
    sdword deathBy;
} DeleteMissile;

typedef struct DeleteDerelict
{
    Node objlink;
    Derelict *derelict;
    sdword deathBy;
} DeleteDerelict;

// For Ship ID Decoding:
typedef struct IDToPtrTable
{
    sdword numEntries;
    SpaceObjPtr *objptrs;
} IDToPtrTable;

/*=============================================================================
    Functions:
=============================================================================*/

TI_API void univupdateReset(void);
TI_API void univupdateInit(void);
TI_API void univupdateClose(void);

TI_API void univupdateCloseAllObjectsAndMissionSpheres(void);

TI_API bool_t univUpdate(real32 phystimeelapsed);

TI_API void univRotateObjYaw(SpaceObjRot *robj,real32 rot);
TI_API void univRotateObjPitch(SpaceObjRot *robj,real32 rot);
TI_API void univRotateObjRoll(SpaceObjRot *robj,real32 rot);

TI_API Ship *univCreateShip(ShipType shiptype,ShipRace shiprace,vector *shippos,struct Player *playerowner,sdword built);
TI_API Ship *univAddShip(ShipType shiptype,ShipRace shiprace,vector *shippos,struct Player *playerowner,sdword built);
TI_API Asteroid *univAddAsteroid(AsteroidType asteroidtype,vector *astpos);
TI_API DustCloud *univAddDustCloud(DustCloudType dustcloudtype,vector *cloudpos);
TI_API GasCloud *univAddGasCloud(GasCloudType gascloudtype,vector *cloudpos);
TI_API Nebula *univAddNebula(NebulaType nebulatype, vector *nebpos, void *stub);
TI_API Effect *univAddEffect(Ship *ship, etgeffectstatic *stat);
TI_API //Effect *univAddEffect(Ship *ship, EffectType type);

TI_API void univFreeShipContents(Ship *ship);
TI_API void univFreeBulletContents(Bullet *bullet);
TI_API void univFreeMissileContents(Missile *missile);
TI_API void univFreeEffectContents(Effect *effect);

TI_API void univFreeResourceContents(Resource *resource);
TI_API void univFreeAsteroidContents(Asteroid *asteroid);
TI_API void univFreeNebulaContents(Nebula *nebula);
TI_API void univFreeGasCloudContents(GasCloud *gascloud);
TI_API void univFreeDustCloudContents(DustCloud *dustcloud);

TI_API void univFreeDerelictContents(Derelict *derelict);

TI_API void MakeNewGasCloudStaticInfo(GasCloud *gascloud);
TI_API void MakeNewAsteroidStaticInfo(Asteroid *asteroid);
TI_API void MakeNewDustCloudStaticInfo(DustCloud *dustcloud);

TI_API void univDeleteEffect(Effect *effect);
TI_API void univRemoveShipFromOutside(Ship *ship);
TI_API void univDeleteWipeInsideShipOutOfExistence(Ship *ship);
void univDeleteDeadShip(Ship *ship, sdword deathBy);// deletes ship, but lets part of it hang around for explosion
void univWipeShipOutOfExistence(Ship *ship);                // totally deletes ship, frees memory
void univWipeDerelictOutOfExistance(Derelict *derelict);    //totally deletes the derelict, frees memory and spawns no new effects
void univReallyDeleteThisShipRightNow(Ship *ship);      //totally deletes it immediately
TI_API void univReallyDeleteThisResourceRightNow(Resource *resource);
TI_API void univReallyDeleteThisDerelictRightNow(Derelict *derelict);
bool8 univRemoveShipFromHotkeyGroup(Ship *ship, bool8 PlayDefeat); // removes ship from hotkey group
void univHideShipFromSpheres(Ship *ship);           //hides from all mission spheres
TI_API void univUnhideJustAboutEverything(void);
TI_API void univHideJustAboutEverything(void);

TI_API void univGetResourceStatistics(sdword *resourceValue,sdword *numHarvestableResources,sdword *numAsteroid0s);
TI_API Resource *univFindNearestResource(Ship *ship,real32 volumeRadius,vector *volumePosition);

TI_API void univRemoveObjFromRenderList(SpaceObj *spaceobj);
TI_API void univAddObjToRenderListIf(SpaceObj *newobj,SpaceObj *ifobj);
TI_API void univAddObjToRenderList(SpaceObj *newobj);
TI_API bool_t univSpaceObjInRenderList(SpaceObj *spaceobj);

#define univRemoveObjFromMinorRenderList univRemoveObjFromRenderList
#define univSpaceObjInMinorRenderList univSpaceObjInRenderList

TI_API real32 univGetChecksum(sdword *numShipsInChecksum);
TI_API udword univCalcShipChecksum(void);


TI_API void univUpdateRenderList(void);
TI_API void univUpdateMinorRenderList(void);

TI_API Ship *univFindShipIAmInside(Ship *me);
TI_API bool_t univAmIInsideThisShip(Ship *me,Ship *ship);

TI_API Ship *ShipIDtoShip(ShipID shipID,bool_t considerInsideShips);
TI_API ResourcePtr ResourceIDtoResourcePtr(ResourceID resourceID);
TI_API MissilePtr MissileIDtoMissilePtr(MissileID missileID);
TI_API DerelictPtr DerelictIDToDerelictPtr(DerelictID derelictID);

TI_API void univInitSpaceObjPosRot(SpaceObj *obj,vector *position,bool_t randomOrientation);
TI_API void univUpdateObjRotInfo(SpaceObjRot *robj);

TI_API void AddResourceToDeleteResourceList(Resource *resource);
TI_API void AddDerelictToDeleteDerelictList(Derelict *derelict,GunSoundType damageType);
TI_API void AddMissileToDeleteMissileList(Missile *missile,GunSoundType damageType);
TI_API void AddShipToDeleteShipList(Ship *ship,GunSoundType damageType);
TI_API void AddTargetToDeleteList(SpaceObjRotImpTarg *target,GunSoundType soundType);
TI_API void univAddToWorldList(Derelict *world);
TI_API void univRemoveFromWorldList(Derelict *world);

TI_API Missile *univAddMissile(ShipRace race);

TI_API Derelict *univAddDerelict(DerelictType derelicttype,vector *pos);
TI_API Derelict *univAddDerelictByStatInfo(DerelictType derelictType, DerelictStaticInfo *stat, vector *pos);
TI_API Derelict *univAddHyperspaceGateAsDerelict(hvector *posAndRotation);

TI_API void ObjectsCollided(SpaceObjRotImpTarg *obj1,SpaceObjRotImpTarg *obj2,real32 colldist,vector *distvector,real32 dist,real32 distsquared);
TI_API void ApplyDamageToCollidingObjects(SpaceObjRotImpTarg *obj1,SpaceObjRotImpTarg *obj2,vector *distvector,real32 dist);
TI_API bool_t ApplyDamageToTarget(SpaceObjRotImpTarg *target,real32 damagetaken,GunSoundType soundType,sdword damageHow,sdword playerIndex);

TI_API void univBulletCollidedWithTarget(SpaceObjRotImpTarg *target,StaticHeader *targetstaticheader,Bullet *bullet,real32 collideLineDist,sdword collSide);
TI_API void univMissileCollidedWithTarget(SpaceObjRotImpTarg *target,StaticHeader *targetstaticheader,Missile *missile,real32 collideLineDist,sdword collSide);

TI_API SelectCommand *getEnemiesWithinProximity(Ship *thisship,real32 retaliateZone);

#define PLAYERKILLED_DROPPEDOUT         -1
#define PLAYERKILLED_STANDARDDEATH      0
#define PLAYERKILLED_CAPTUREDSHIP       1
#define PLAYERKILLED_LOSTMISSION        2

TI_API void univKillPlayer(sdword i,sdword playerdeathtype);

TI_API void CheckPlayerWin(void);

TI_API void InitializeEngineTrails(Ship *newship);

TI_API shipbindings *univMeshBindingsDupe(ShipStaticInfo *shipstaticinfo, Ship *newShip);
TI_API void univResetNewGimbleGun(Gun *gun);

TI_API void InitializeNavLights(Ship *newship);

TI_API bool_t univFindBackupMothership(struct Player *player);

// fast id table lookup stuff
TI_API void univInitFastNetworkIDLookups(void);
TI_API void univCloseFastNetworkIDLookups(void);
TI_API void univResetFastNetworkIDLookups(void);
TI_API void IDToPtrTableAdd(IDToPtrTable *table,uword ID,SpaceObj *obj);
// fast id table save stuff
TI_API void LoadIDToPtrTable(IDToPtrTable *table);
TI_API void SaveIDToPtrTable(IDToPtrTable *table);

TI_API void ApplyCareenRotationDirectly(Ship *ship);

TI_API bool_t univObjectOutsideWorld(SpaceObj *obj);

TI_API void univKillOtherPlayersIfDead(Ship *ship);


/*=============================================================================
    Data:
=============================================================================*/

extern udword NUM_STARS;
extern udword NUM_BIG_STARS;

extern vector defaultshipupvector;
extern vector defaultshiprightvector;
extern vector defaultshipheadingvector;
extern matrix defaultshipmatrix;

extern IDToPtrTable ShipIDToPtr;
extern IDToPtrTable ResourceIDToPtr;
extern IDToPtrTable DerelictIDToPtr;
extern IDToPtrTable MissileIDToPtr;

#endif
