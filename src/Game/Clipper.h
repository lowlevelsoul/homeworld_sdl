// =============================================================================
//  Clipper.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 4/10/1998 by khent
// =============================================================================

#ifndef ___CLIPPER_H
#define ___CLIPPER_H

#include "tiPlatform.h"
#include "Vector.h"

TI_API sdword clipViewclipLine(real32* vectors, udword* i, udword* j);
TI_API void clipTransformPoints(udword n, real32* vobj, real32* vEye, real32* m);
TI_API bool_t clipIsPerspective(real32* m);
void clipProjectPoints(udword n, real32* vEye, real32* vClip, ubyte* clipmask,
                       ubyte* clipormask, ubyte* clipandmask, real32* m);
void clipViewportMap(udword n, real32* vClip, ubyte* clipmask, real32* vWin,
                     vector* viewportS, vector* viewportT, bool_t force);

TI_API bool_t clipLineToScreen(vector* pa, vector* pb, real32* modelview, real32* projection, vector* screenA, vector* screenB);
TI_API bool_t clipPointToScreen(vector* p, vector* screen, bool_t force);
TI_API bool_t clipPointToScreenWithMatrices(vector* p, vector* screen, real32* modelview, real32* projection, bool_t force);
TI_API bool_t clipBBoxIsClipped(real32* collrectoffset, real32 uplength, real32 rightlength, real32 forwardlength);

#endif

