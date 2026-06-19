/*=============================================================================
    Name    : Physics.h
    Purpose : Definitions for physics.c

    Created 6/18/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___PHYSICS_H
#define ___PHYSICS_H

#include "tiPlatform.h"
#include "SpaceObj.h"

/*=============================================================================
    Macros:
=============================================================================*/

#define physApplyForceVectorToObj(obj,forcevector) vecAddTo((obj)->posinfo.force,(forcevector))

/*=============================================================================
    Functions:
=============================================================================*/

TI_API void physApplyForceToObj(SpaceObj *obj,real32 force,uword transdir);
TI_API void physApplyRotToObj(SpaceObjRot *obj,real32 torque,uword rotdir);
TI_API void physUpdateObjPosVel(SpaceObj *obj,real32 phystimeelapsed);
TI_API bool_t physUpdateBulletPosVel(Bullet *bullet,real32 phystimeelapsed);

TI_API void physUpdateObjPosVelShip(Ship *obj,real32 phystimeelapsed);
TI_API void physUpdateObjPosVelDerelicts(Derelict *obj,real32 phystimeelapsed);
TI_API void physUpdateObjPosVelMissile(Missile *obj,real32 phystimeelapsed);
TI_API void physUpdateObjPosVelBasic(SpaceObj *obj,real32 phystimeelapsed);

#endif
