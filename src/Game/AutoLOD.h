// =============================================================================
//  AutoLOD.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 9/8/1998 by khent
// =============================================================================

#ifndef ___AUTOLOD_H
#define ___AUTOLOD_H

#include "tiPlatform.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------

TI_API void alodStartup(void);
TI_API void alodReset(void);
TI_API void alodShutdown(void);
TI_API void alodSetMinMax(real32 minScale, real32 maxScale);
TI_API real32 alodGetMin(void);
TI_API real32 alodGetMax(void);
TI_API void alodSetTargetPolys(udword targetPolys, udword polyDelta);
TI_API void alodGetTargetPolys(udword* targetPolys, udword* polyDelta);
TI_API void alodSetPolys(udword polys);
TI_API void alodIncPolys(udword polys);
TI_API void alodEnable(bool_t enable);
TI_API void alodAdjustScaleFactor(void);
TI_API udword alodGetPolys(void);
TI_API bool_t alodGetPanic(void);
TI_API void alodSetPanic(bool_t panic);

#endif
