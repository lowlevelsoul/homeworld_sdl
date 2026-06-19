/*=============================================================================
    Name    : Netcheck.h
    Purpose : Definitions for Netcheck.c

    Created 8/3/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___NETCHECK_H
#define ___NETCHECK_H

#include "tiPlatform.h"
#include "CommandNetwork.h"
#include "Switches.h"
#include "Types.h"

#define PKTS_EXTENSION  ".pkts"

#define BINNETLOG       1

TI_API void netcheckReset(void);
TI_API void netcheckInit(void);
TI_API void netcheckClose(void);
TI_API void netcheckShow(HWPacketHeader *packet);
#if SYNC_CHECK
TI_API void netcheckFillInChecksum(HWPacketHeader *packet);
TI_API void netcheckCheckChecksum(NetSyncChecksums *checksum);
#endif
TI_API //void netcheckShow(HWPacketHeader *packet);
TI_API //void netcheckFillInChecksum(HWPacketHeader *packet);
TI_API //void netcheckCheckChecksum(NetSyncChecksums *checksum);

/*=============================================================================
    Public Variables:
=============================================================================*/

#if SYNC_CHECK
extern udword randSyncErr;
extern udword univSyncErr;
extern udword blobSyncErr;
extern udword pktSyncErr;

extern udword randSyncErrFrame;
extern udword univSyncErrFrame;
extern udword blobSyncErrFrame;
#endif

extern FILE *netlogfile;

TI_API void recPackRecordInit(void);
TI_API void recPackRecordPacket(ubyte *packet,udword sizeofPacket);
TI_API void recPackRecordPacketFilename(ubyte *packet,udword sizeofPacket,char *filename);
TI_API ubyte *recPackPlayGetNextPacket(udword *sizeofPacket);
TI_API void recPackPlayInit(void);
TI_API void recPackPlayClose(void);
TI_API void recPackPlayInGameInit(void);
TI_API void recPackInGameStartCB(char *filename);
TI_API void recPackInGameStartCBSafeToStart(void);
TI_API void recPackInGameStopCB(void);

extern char OrigRecordPacketFileName[];

#ifdef GOD_LIKE_SYNC_CHECKING
TI_API void syncDebugDump(char *filename,sdword counter,bool_t save);
TI_API void industrialStrengthSyncDebugging(sdword FrameNumber);
TI_API void netcheckIndustrialChecksum(void);
TI_API void netReceivedSyncFromNonCaptain(void *checksums,udword frame,udword playerIndex);
TI_API void godSyncInit(void);
TI_API void godSyncShutDown(void);

#endif

#if BINNETLOG

typedef struct binnetlogPacket
{
    udword header;
    uword packetnum;
    uword randcheck;
    real32 univcheck;
    udword blobcheck;
    uword numShipsInChecksum;
    uword numBlobsInChecksum;
    udword univUpdateCounter;
} binnetlogPacket;

typedef struct binnetlogCheatInfo
{
    udword header;
    udword totalships;
    udword resourceunits;
    udword shiptotals;
    udword classtotals;
    udword hastechnology;
    udword listoftopicsnum;
} binnetlogCheatInfo;

typedef struct binnetlogBountyInfo
{
    udword header;
    ubyte bounties[8];
} binnetlogBountyInfo;

typedef struct binnetlogShipInfo
{
    udword header;
    uword shipID;
    ubyte playerIndex;
    ubyte shiprace;
    ubyte shiptype;
    sbyte shiporder;
    sbyte shipattributes;
    ubyte tacticstype;
    ubyte isDodging;
    ubyte DodgeDir;
    real32 health;
    real32 x,y,z;
    real32 vx,vy,vz;
    real32 fuel;
} binnetlogShipInfo;

// resource info if harvesting
typedef struct binnetlogShipResourceInfo
{
    udword header;
    uword resourceID;
    real32 volume;
    real32 x,y,z;
} binnetlogShipResourceInfo;

// dock info if docking
typedef struct binnetlogShipDockInfo
{
    udword header;
    uword busyness;
    uword numDockPoints;
    udword thisDockBusy;
} binnetlogShipDockInfo;

// mad info if mesh animations
typedef struct binnetlogShipMadInfo
{
    udword header;
    ubyte info[8];
} binnetlogShipMadInfo;

typedef struct binnetlogBulletInfo
{
    udword header;
    uword bullettype;
    uword bulletplayerowner;
    uword bulletowner;
    real32 x,y,z;
    real32 vx,vy,vz;
    real32 timelived;
    real32 totallifetime;
    real32 traveldist;
    real32 damage;
    real32 damageFull;
    real32 DFGFieldEntryTime;
    real32 BulletSpeed;
    real32 collBlobSortDist;
} binnetlogBulletInfo;

typedef struct binnetDerelictInfo
{
    udword header;
    uword derelictid;
    uword derelicttype;
    real32 health;
    real32 x,y,z;
    real32 vx,vy,vz;
} binnetDerelictInfo;

typedef struct binnetResourceInfo
{
    udword header;
    uword resourceid;
    uword resourcetype;
    sdword resourceValue;
    real32 health;
    real32 x,y,z;
    real32 vx,vy,vz;
} binnetResourceInfo;

typedef struct binnetBlobInfo
{
    udword header;
    sdword numSpaceObjs;
    real32 collBlobSortDist;
    real32 x,y,z,r;
} binnetBlobInfo;

typedef struct binnetCmdLayerInfo
{
    udword header;
    uword order;
    uword attributes;
    uword numShips;
    uword ShipID[1];
} binnetCmdLayerInfo;

typedef struct binnetCmdLayerInfoMax
{
    udword header;
    uword order;
    uword attributes;
    uword numShips;
    uword ShipID[500];
} binnetCmdLayerInfoMax;

#define sizeofbinnetCmdLayerInfo(x) ( sizeof(binnetCmdLayerInfo) + sizeof(uword)*((x)-1) )

typedef struct binnetselection
{
    udword header;
    uword numShips;
    uword ShipID[1];
} binnetselection;

typedef struct binnetselectionMax
{
    udword header;
    uword numShips;
    uword ShipID[500];
} binnetselectionMax;

#define sizeofbinnetselection(x) ( sizeof(binnetselection) + sizeof(uword)*((x)-1) )

typedef struct binnetanyselection
{
    udword header;
    uword numTargets;
    udword TargetID[1];
} binnetanyselection;

typedef struct binnetanyselectionMax
{
    udword header;
    uword numTargets;
    udword TargetID[500];
} binnetanyselectionMax;

#define sizeofbinnetanyselection(x) ( sizeof(binnetanyselection) + sizeof(udword)*((x)-1) )

#define makenetcheckHeader(x,y,z,w) ((x) | ((y) << 8) | ((z) << 16) | ((w) << 24))

#endif

#endif

