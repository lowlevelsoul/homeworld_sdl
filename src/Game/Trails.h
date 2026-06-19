/*=============================================================================
    Name    : Trails.h
    Purpose : Definitions for drawing ship trails

    Created 8/11/1997 by lmoloney
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___TRAILS_H
#define ___TRAILS_H

#include "tiPlatform.h"
#include "Color.h"
#include "MaxMultiplayer.h"
#include "Types.h"
#include "Vector.h"

/*=============================================================================
    Switches:
=============================================================================*/
#ifdef HW_BUILD_FOR_DISTRIBUTION

#define TRAIL_ERROR_CHECKING       0               //general error checking
#define TRAIL_VERBOSE_LEVEL        0               //print extra info
#define TRAIL_GATHER_STATS         0               //gather performance stats

#else

#define TRAIL_ERROR_CHECKING       1               //general error checking
#define TRAIL_VERBOSE_LEVEL        1               //print extra info
#define TRAIL_GATHER_STATS         0               //gather performance stats

#endif

/*=============================================================================
    Definitions:
=============================================================================*/
#if FIX_ENDIAN
    #define TP_KeyColor  0xffffff00
#else
    #define TP_KeyColor  0x00ffffff  //high bit (alpha) clear means this is a key color
#endif

/*=============================================================================
    Type definitions:
=============================================================================*/
//static trail information block
typedef struct
{
    sdword nSegments;                           //number in segments in trail
    sdword granularity;                         //frame-granularity counter.  Will act as a trail-length multiplier
    color *segmentColor[MAX_MULTIPLAYER_PLAYERS];//color of trail at each segment for each team
}
trailstatic;

typedef struct
{
    real32 position[3];
    real32 rotation[9];
    real32 translation[3];
    real32 horizontal[3];
    real32 vertical[3];
    real32 direction[3];
    bool8  wide;
    ubyte  pad[3];
}
trailsegment;

typedef struct
{
    vector position;
}
missiletrailsegment;

#define TRAIL_CONTRACTING 1
#define TRAIL_EXPANDING   2
#define TRAIL_CONTRACTED  4
#define TRAIL_EXPANDED    8

//dynamic trail structure
typedef struct
{
    trailstatic *staticInfo;            //non-dynamic trail info reference
    void*  vship;

    real32 width, height, angle;        //== -1.0f if defaults should be used
    real32 ribbonadjust;
    bool8  style;
    bool8  second;
    ubyte  trailNum;
    ubyte  state;
    ubyte  counter;

    bool_t   wobbly;

    real32 lastvelsquared;
    real32 prevvelsquared;
    sdword ranCounter;
    real32 ran;
    real32 exponent;
    real32 scalecap;
    sdword grainCounter;                //counter to reflect if the trail should be updated this time around
    sdword iHead, iTail, nLength;       //circular queue members
    trailsegment segments[1];           //trail segments
}
shiptrail;

typedef struct
{
    trailstatic* staticInfo;
    void* vmissile;

    real32 width, height;
    sdword grainCounter;
    sdword iHead, iTail, nLength;
    missiletrailsegment segments[1];
}
missiletrail;

/*=============================================================================
    Data:
=============================================================================*/
extern sdword trailInsertCount;

/*=============================================================================
    Macros:
=============================================================================*/
#define mistrailSize(n)     (sizeof(missiletrail) + (n)*sizeof(missiletrailsegment))
#define trailSize(n)        (sizeof(shiptrail) + (n)*sizeof(trailsegment))
#define trailStaticSize(n)  (sizeof(trailstatic) + (n) * sizeof(color) * MAX_MULTIPLAYER_PLAYERS)
#define trailInsertTrail()  ((trailInsertCount ^= TRUE) != 0)

/*=============================================================================
    Functions:
=============================================================================*/

//startup/shutdown
TI_API void trailStartup(void);
TI_API void trailShutdown(void);

//allocate and initialize a new missile trail
TI_API missiletrail* mistrailNew(trailstatic* staticInfo, void* vmissile);
TI_API void mistrailDelete(missiletrail* trail);
TI_API void mistrailUpdate(missiletrail* trail, vector* position);
TI_API void mistrailDraw(vector* current, missiletrail* trail, sdword LOD, sdword teamIndex);

//allocate and initialize a new ship trail
TI_API shiptrail *trailNew(trailstatic *staticInfo, void* vship, bool8 second, ubyte trailNum);
TI_API void trailDelete(shiptrail *trail);

//update a trail by adding in a new position into its queue
TI_API void trailUpdate(shiptrail *trail, vector *position);

//draw a ship trail
TI_API void trailDraw(vector *current, shiptrail *trail, sdword LOD, sdword teamIndex);
TI_API void trailZeroLength(shiptrail *trail);
TI_API void trailMove(shiptrail* trail, vector *delta);

//cause a trail or glow to enter/exit its "wobbly" state
TI_API void trailMakeWobbly(void* vship, bool_t state);

//parse a ship definition file and create a trailstatic structure
TI_API trailstatic *trailStaticInfoParse(char *directory, char *fileName);
TI_API void trailStaticDelete(trailstatic *tailInfo);

//recolorize trails
TI_API void trailRecolorize(trailstatic *trailStatic);
TI_API void trailsRecolorize(void);
TI_API void mistrailsRecolorize(void);

#endif
