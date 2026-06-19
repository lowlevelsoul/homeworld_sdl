/*=============================================================================
    Name    : Gun.h
    Purpose : Definitions for Gun.c

    Created 6/30/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___GUN_H
#define ___GUN_H

#include "tiPlatform.h"
#include "SpaceObj.h"
#include "render.h"

/*=============================================================================
    Defines:
=============================================================================*/

#ifdef HW_BUILD_FOR_DISTRIBUTION

#define GUN_TUNE_MODE       0
#define GUN_VERBOSE_LEVEL   0

#else

#define GUN_TUNE_MODE       1
#define GUN_VERBOSE_LEVEL   1

#endif

#define GUN_RecoilTableLength   255
#define GUN_RecoilTime    0.05f
#define GUN_OneOverTime   20.0f
#define ONEPLUS_HIGH_TIME   1.05f

/*=============================================================================
    Functions:
=============================================================================*/

TI_API bool gunCanShoot(Ship *ship, Gun *gun);
TI_API bool gunOrientGimbleGun(Ship *ship,Gun *gun,SpaceObjRotImpTarg *target);
TI_API void missileShoot(Ship *ship,Gun *gun,SpaceObjRotImpTarg *target);
TI_API void gunShoot(Ship *ship,Gun *gun, SpaceObjRotImpTarg *target);
TI_API bool gunShootGunsAtTarget(Ship *ship,SpaceObjRotImpTarg *target,real32 range,vector *trajectory);
TI_API bool gunShootGunsAtMultipleTargets(Ship *ship);

TI_API bool gunMatrixUpdate(udword flags, hmatrix *startMatrix, hmatrix *matrix, void *data, smemsize ID);

#if RND_VISUALIZATION
TI_API void gunDrawGunInfo(Ship *ship);
#endif

//gun location in world code for silly sound boys
TI_API void gunGetGunPositionInWorld(vector *positionInWorldCoordSys,matrix *coordsys,Gun *gun);

//compute firepower
TI_API real32 gunFirePower(GunStatic *gunStatic, TacticsType tactics, real32 *fireTime);
TI_API real32 gunShipFirePower(ShipStaticInfo *info, TacticsType tactics);

TI_API void gunStartup(void);
TI_API void gunShutdown(void);
#if GUN_TUNE_MODE
TI_API void gunTuneGun(Ship *ship);
#endif

/*=============================================================================
    Macros:
=============================================================================*/
// only valid for GUN_MissileLauncher
#define gunHasMissiles(gun) ((gun)->numMissiles > 0)

/*=============================================================================
    Variables:
=============================================================================*/

#if GUN_TUNE_MODE
extern bool gunTuningMode;
extern sdword tuningGun;
#endif

#endif
