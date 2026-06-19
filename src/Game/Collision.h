// =============================================================================
//  Collision.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 9/25/1997 by gshaw
// =============================================================================

#ifndef ___COLLISION_H
#define ___COLLISION_H

#include "tiPlatform.h"
#include "Blobs.h"
#include "SpaceObj.h"

TI_API real32 RangeToTarget(Ship *ship,SpaceObjRotImpTarg *target,vector *trajectory);
TI_API real32 RangeToTargetGivenDist(Ship *ship,SpaceObjRotImpTarg *target,real32 dist);
TI_API void collUpdateCollRectangle(SpaceObjRotImp *irobj);
TI_API void collDrawCollisionInfo(SpaceObjRotImp *irobj);
TI_API void collZeroRectInfo(StaticCollInfo *staticCollInfo);
TI_API real32 collCheckRectLine(SpaceObjRotImp *obj1,vector *univpoint,vector *univdir,real32 linelength,sdword *collSide);
TI_API bool collCheckRectPoint(SpaceObjRotImp *obj1,vector *point);
TI_API bool collCheckRectInRect(SpaceObjRotImp *obj1,SpaceObjRotImp *obj2);
TI_API bool collCheckLineOfSight(Ship* source, Ship* target, vector* sourcePosition, vector* direction);

#define collAddSpaceObjToCollBlobs(obj) bobAddObjToNearestBlob(&universe.collBlobList,obj)
#define collAddSpaceObjToSpecificBlob(tblob,tobj) bobAddObjToSpecificBlob(tblob,tobj)

TI_API void collUpdateCollBlobs(void);
TI_API void collUpdateObjsInCollBlobs(void);

TI_API void collCheckAllBumpCollisions(void);
TI_API void collCheckAllBulletMissileCollisions(void);

#define COLLISION_CHECK_STATS  1

/*=============================================================================
    Data:
=============================================================================*/
#if COLLISION_CHECK_STATS

extern udword shipsavoidingstuff;
extern udword shipsavoidedwalks;
extern udword shipsavoidedchecks;

extern udword shipshipwalks;
extern udword shipresourcewalks;
extern udword shipderelictwalks;
extern udword shipshipchecks;
extern udword shipresourcechecks;
extern udword shipderelictchecks;

extern udword bulletwalks;
extern udword bulletchecks;

extern udword missilewalks;
extern udword missilechecks;

extern udword minewalks;
extern udword minechecks;

#endif

#endif

