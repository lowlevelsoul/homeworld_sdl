// =============================================================================
//  B-Spline.h
//  - code for generic interpolation of beta-spline curves
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 11/29/1997 by lmoloney
// =============================================================================

#ifndef ___B_SPLINE_H
#define ___B_SPLINE_H 

#include "tiPlatform.h"
#include "Types.h"

/*=============================================================================
    Switches:
=============================================================================*/

#define BS_TEST                     0           //test the spline module

#ifdef HW_BUILD_FOR_DEBUGGING

#define BS_ERROR_CHECKING           1           //general error checking
#define BS_VERBOSE_LEVEL            1           //control specific output code

#else

#define BS_ERROR_CHECKING           0           //general error checking
#define BS_VERBOSE_LEVEL            0           //control specific output code

#endif

/*=============================================================================
    Definitions:
=============================================================================*/
//flags for spline curves
#define BS_NoPoint                  -1

/*=============================================================================
    Type definitions:
=============================================================================*/

//parameters for a control point
typedef struct
{
    real32 tension;
    real32 continuity;
    real32 bias;
}
tcb;

//info for a single spline curve
typedef struct
{
    real32 timeElapsed;
    sdword currentPoint;
    sdword nPoints;
//    hmatrix *currentM;
//    hvector *currentG;
    real32 *points;
    real32 *times;
    tcb *params;
}
splinecurve;

/*=============================================================================
    Functions:
=============================================================================*/

TI_API void bsStartup(void);
TI_API void bsShutdown(void);

TI_API splinecurve *bsCurveStart(sdword nPoints, real32 *points, real32 *times, tcb *params, bool_t bAlloc);
TI_API void bsCurveStartPrealloced(splinecurve *curve, sdword nPoints, real32 *values, real32 *times, tcb *params);
TI_API void bsCurveRestart(splinecurve *curve);
TI_API real32 bsCurveUpdate(splinecurve *curve, real32 timeElapsed);
TI_API void bsCurveDelete(splinecurve *curve);

#endif
