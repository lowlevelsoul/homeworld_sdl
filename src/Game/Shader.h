/*=============================================================================
        Name    : shader.h
        Purpose : shader provides specialized shading models for non-rGL renderers

Created 22/06/1998 by khent
Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___SHADER_H
#define ___SHADER_H

#include "tiPlatform.h"
#include "Color.h"
#include "Matrix.h"
#include "Types.h"
#include "Vector.h"

typedef struct
{
    ubyte c[4];
} shColor;

extern shColor* colorList;

#define shColorSetIndexed(index) \
    { \
        shColor* c; \
        \
        c = colorList + index; \
        glColor4ub(c->c[0], c->c[1], c->c[2], c->c[3]); \
    }

TI_API void shStartup(void);
TI_API void shShutdown(void);
TI_API void shTransformNormal(vector* out, vector* in, real32* m);
TI_API void shTransformVertex(vector* out, vector* in, real32* m);
TI_API real32 shPow(real32 a, real32 b);
void shSpecularColour(sdword specInd, sdword side, vector* vobj, vector* norm,
                      ubyte* color, real32* m, real32* minv);
TI_API void shColour(sdword side, vector* norm, ubyte* color, real32* minv);
TI_API void shColourSet(sdword side, vector* norm, real32* minv);
TI_API void shColourSet0(vector* norm);
TI_API void shInvertMatrix(real32* out, real32 const* m);
TI_API void shSetExponent(sdword index, real32 exponent);
TI_API void shSetLightPosition(sdword index, real32* position, real32* m);
TI_API void shSetGlobalAmbient(real32* ambient);
TI_API void shSetMaterial(real32* ambient, real32* diffuse);
TI_API void shSetLighting(sdword index, real32* diffuse, real32* ambient);
TI_API void shUpdateLighting(void);
TI_API void shGammaUp(void);
TI_API void shGammaDown(void);
TI_API void shGammaReset(void);
TI_API void shGammaSet(sdword gamma);
TI_API sdword shGammaGet(void);

TI_API void shGrowBuffers(sdword nVertices);
TI_API void shShadeBuffer(sdword nVertices, hvector* source);

TI_API void shDockLight(real32 t);
TI_API void shDockLightColor(color c);

TI_API void shPushLightMatrix(hmatrix *pMat);
TI_API void shPopLightMatrix(void);

#endif
