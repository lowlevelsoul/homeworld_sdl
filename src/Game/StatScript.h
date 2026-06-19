/*=============================================================================
    Name    : statscript.h
    Purpose : Definitions for statscript.c (Static Scripting Utilities)

    Created 6/24/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___STATSCRIPT_H
#define ___STATSCRIPT_H

#include "tiPlatform.h"
#include "ObjTypes.h"
#include "Types.h"

/*=============================================================================
    Types:
=============================================================================*/

typedef void (*setVarCback)(char *directory,char *field,void *dataToFillIn);

typedef struct
{
    char *name;
    setVarCback setVarCB;
    void * offset1;     // should really be 1 offset, but I can't get rid of this strange compiler error
    void * offset2;
} scriptStructEntry;

typedef struct
{
    char *name;
    setVarCback setVarCB;
    void *dataPtr;
} scriptEntry;

///////DATA!!!!
extern char globalScriptFileName[50];  //file name of file loaded in a script callback function


/*=============================================================================
    Macros
=============================================================================*/

// for filling in scriptEntry
#define makeEntry(var,callback)  { strdollar(var), callback, &(var) }
#define END_SCRIPT_STRUCT_ENTRY  { NULL, NULL, 0, 0 }
#define END_SCRIPT_ENTRY         { NULL, NULL, NULL }

/*=============================================================================
    Functions:
=============================================================================*/

struct StaticInfoHealthGuidanceShipDerelict;
struct ShipStaticInfo;

TI_API void RemoveCommasFromString(char *field);
TI_API void StripTrailingSpaces(char *value);

TI_API void scriptSetRGBCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetRGBACB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetReal32CB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetReal32CB_ARRAY(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetReal32SqrCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetSbyteCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetUbyteCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetSwordCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetUwordCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetSdwordCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetUdwordCB(char *directory,char *field,void *dataToFillIn);
TI_API bool_t scriptStringToBool(char *boolString);
TI_API void scriptSetBool8(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetBool(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetBitUdword(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetBitUword(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetStringCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetStringPtrCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetCosAngCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetCosAngSqrCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetCosAngCB_ARRAY(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetSinAngCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetTanAngCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetAngCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetGunTypeCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetGunSoundTypeCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetBulletTypeCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetShipClassCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetShipRaceCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetShipTypeCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetVectorCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetLWToHWMonkeyVectorCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetFormationCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetTacticsCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetSalvagePointCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetSalvageStatCB(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetSalvageStatics(char *directory,char *filename,struct StaticInfoHealthGuidanceShipDerelict *statinfo);
TI_API void scriptSetDockOverideStatics(char *directory,char *filename,struct ShipStaticInfo *shipstatinfo);

TI_API void scriptSetStruct(char *directory,char *filename,scriptStructEntry info[],ubyte *structureToFillIn);
TI_API void scriptSet(char *directory,char *filename,scriptEntry info[]);
TI_API void scriptSetFileSystem(char *directory,char *filename,scriptEntry info[]);
TI_API void scriptSetGunStatics(char *directory,char *filename,struct ShipStaticInfo *shipstatinfo);
TI_API void scriptSetNAVLightStatics(char *directory,char *filename,struct ShipStaticInfo *shipstatinfo);
TI_API void scriptSetDockStatics(char *directory,char *filename,struct ShipStaticInfo *statinfo);
struct SphereStaticInfo *scriptSetSphereStaticInfo(char *directory,char *filename);
TI_API void scriptSetShipGroupSizeCB(char *directory, char *field, sdword *dataToFillIn);
TI_API void scriptSetShipProbCB(char *directory, char *field, real32 *dataToFillIn);
TI_API void scriptSetHyperspaceCostCB(char *directory, char *field, real32 *dataToFillIn);
TI_API void scriptSetSpecialDoorOffsetCB(char *directory, char *field, real32 *dataToFillIn);
TI_API void scriptSetBlobPropertyOverlap(char *directory,char *field,void *dataToFillIn);
TI_API void scriptSetBlobBiggestRadius(char *directory,char *field,void *dataToFillIn);

// sets all tweakable global variables in game
TI_API void scriptSetTweakableGlobals(void);

TI_API void mgGameTypeScriptInit(void);

#ifdef HW_BUILD_FOR_DEBUGGING
TI_API void CheckValidTacticsClass(TacticsType tactic,ShipClass shipclass,char *field);
#endif

#endif

