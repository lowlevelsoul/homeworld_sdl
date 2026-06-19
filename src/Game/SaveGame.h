/*=============================================================================
    Name    : SaveGame.h
    Purpose : Definitions for SaveGame.c

    Created date by user
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___SAVEGAME_H
#define ___SAVEGAME_H

#include "tiPlatform.h"
#include "ShipSelect.h"
#include "SpaceObj.h"
#include "Types.h"

#define SAVE_VERSION_NUMBER_ORIGINAL    0x10ad0027  // save game version for original Homeworld (Relic)

#define SAVE_VERSION_NUMBER_HWSDL_1     0x10ad0028  // => (20031124) bump for Homeworld SDL project
#define SAVE_VERSION_NUMBER_HWSDL_2     0x10ad0029  // => (20061214) currentMission -> MissionEnum

// don't forget to update SaveGame.c: supportedVersionNumbers[] if you change this
#define SAVE_VERSION_NUMBER             SAVE_VERSION_NUMBER_HWSDL_2

#define BASIC_STRUCTURE                 0x80000000
#define VARIABLE_STRUCTURE              0x40000000
#define INFO_CHUNK                      0x20000000
#define LINKEDLISTSPACEOBJS             0x10000000
#define AIPLAYER                        0x08000000

#define SAVE_PING                       0x00001000
#define IDTOPTRTABLE                    0x00000f00
#define SAVE_SALVAGEINFO                0x00000e00
#define SAVESTRING                      0x00000d00
#define PATH                            0x00000c00
#define AITEAMMOVE                      0x00000b00
#define AITEAM                          0x00000a00
#define SELECTION                       0x00000900
#define SAVE_NEBTENDRIL                 0x00000800
#define SAVE_NEBCHUNK                   0x00000700
#define SAVE_SHIPSINPROGRESS            0x00000600
#define SAVE_ATTACKATOM                 0x00000500
#define SAVE_RETREATATOM                0x00000400
#define SAVE_SLAVEINFO                  0x00000300
#define SAVE_STATICINFO                 0x00000200
#define SAVE_MINEFORMATIONINFO          0x00000100
#define SAVE_SHIPSINSIDEME              0x000000f0
#define SAVE_MILITARYSLOT               0x000000e0
#define SAVE_MILITARYPARADE             0x000000d0
#define SAVE_RESEARCHTOPIC              0x000000c0
#define SAVE_CLOUDSYSTEM                0x000000b0
#define SAVE_COMMANDTODO                0x000000a0
#define SAVE_CAMERACOMMAND              0x00000090
#define SAVE_CAMERASTACKENTRY           0x00000080
#define SAVE_SHIPSINGLEPLAYERGAMEINFO   0x00000070
#define SAVE_DOCKINFO                   0x00000060
#define SAVE_GUNINFO                    0x00000050
#define SAVE_BLOB                       0x00000040
#define SAVE_ATTACKTARGETS              0x00000030
#define SAVE_UNIVERSE                   0x00000020
#define SAVE_SPACEOBJ                   0x00000010


#define SAVE_OBJTYPEMASK                0x0000000f

typedef sdword TypeOfSaveChunk;     // STRUCTURE | SAVE_xxx     e.g. BASIC_STRUCTURE|SAVE_UNIVERSE

typedef struct
{
    TypeOfSaveChunk type;
    sdword contentsSize;
    // chunk contents goes here
} SaveChunk;

typedef struct
{
    sdword info;
} InfoChunkContents;

#define chunkContents(c) ((void *) (((ubyte *)c) + sizeof(SaveChunk)))

#define sizeofSaveChunk(n) (sizeof(SaveChunk) + n)

#define VerifyChunk(c,t,s)              \
    dbgAssertOrIgnore(c);                       \
    dbgAssertOrIgnore((c)->type == (t));        \
    dbgAssertOrIgnore((c)->contentsSize == (s))

#define VerifyChunkNoSize(c,t)          \
    dbgAssertOrIgnore(c);                       \
    dbgAssertOrIgnore((c)->type == (t));

TI_API bool SaveGame(char *filename);
TI_API void LoadGame(char *filename);
TI_API void PreLoadGame(char *filename);

TI_API void SaveThisChunk(SaveChunk *thischunk);
TI_API SaveChunk *CreateChunk(TypeOfSaveChunk type,sdword contentsSize,void *contents);
TI_API SaveChunk *LoadNextChunk(void);

TI_API sdword SpaceObjRegistryGetID(SpaceObj *obj);
TI_API SpaceObj *SpaceObjRegistryGetObj(sdword id);
TI_API Ship *SpaceObjRegistryGetShip(sdword id);
TI_API Resource *SpaceObjRegistryGetResource(sdword id);
TI_API Bullet *SpaceObjRegistryGetBullet(sdword id);
TI_API TargetPtr SpaceObjRegistryGetTarget(sdword id);
TI_API void SaveInfoNumber(sdword info);
TI_API sdword LoadInfoNumber(void);
TI_API void *ConvertNumToPointerInList(LinkedList *list,sdword num);
TI_API sdword ConvertPointerInListToNum(LinkedList *list,void *entry);
TI_API void SpaceObjRegistryRegister(SpaceObj *obj);

TI_API void SaveSelection(SpaceObjSelection *selection);
TI_API SpaceObjSelection *LoadSelection(void);
TI_API SpaceObjSelection *LoadSelectionAndFix(void);
TI_API void FixSelection(SpaceObjSelection *selection);

TI_API void SaveGrowSelection(GrowSelection *grow);
TI_API void LoadGrowSelection(GrowSelection *grow);
TI_API void LoadGrowSelectionAndFix(GrowSelection *grow);
TI_API void FixGrowSelection(GrowSelection *grow);

TI_API void SaveMaxSelection(MaxSelection *maxselection);
TI_API void LoadMaxSelectionAndFix(MaxSelection *maxselection);

TI_API void SaveLinkedListOfInsideShips(LinkedList *list);
TI_API void LoadLinkedListOfInsideShips(LinkedList *list);
TI_API void FixLinkedListOfInsideShips(LinkedList *list);

#define SavePlayerToPlayerIndex(p) (((p) == NULL) ? -1 : (p)->playerIndex)
#define SavePlayerIndexToPlayer(i) ((((sdword)(i)) == -1) ? NULL : &universe.players[((sdword)(i))])

typedef void (*SaveStuffInLinkedListCB)(void *stuff);
typedef void (*LoadStuffInLinkedListCB)(LinkedList *list);
typedef void (*FixStuffInLinkedListCB)(void *stuff);

TI_API void SaveLinkedListOfStuff(LinkedList *list,SaveStuffInLinkedListCB savestuffCB);
TI_API void LoadLinkedListOfStuff(LinkedList *list,LoadStuffInLinkedListCB loadstuffCB);
TI_API void FixLinkedListOfStuff(LinkedList *list,FixStuffInLinkedListCB fixstuffCB);

TI_API void SaveStructureOfSize(void *structure,sdword size);
TI_API void *LoadStructureOfSize(sdword size);
TI_API void LoadStructureOfSizeToAddress(void *address,sdword size);

TI_API void Save_String(char *string);
TI_API char *Load_String(void);
TI_API void Load_StringToAddress(char *addr);

#define VERIFYSAVEFILE_OK               0
#define VERIFYSAVEFILE_ERROROPENING     -1
#define VERIFYSAVEFILE_BADVERSION       -2

TI_API sdword VerifySaveFile(char *filename);

TI_API bool LoadInfoNumberOptional(sdword *info);
TI_API SaveChunk *LoadNextChunkSafe(void);

#endif
