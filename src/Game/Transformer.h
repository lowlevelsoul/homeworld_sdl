/*=============================================================================
    Name    : transformer.h
    Purpose : provides vertex buffer transformation

    Created 10/8/1998 by
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___TRANSFORMER_H
#define ___TRANSFORMER_H

#include "tiPlatform.h"
#include "Matrix.h"
#include "Mesh.h"
#include "Types.h"
#include "Vector.h"

extern hvector* eyeVertexList;
extern hvector* clipVertexList;

TI_API void transStartup(void);
TI_API void transShutdown(void);
TI_API void transGrowVertexLists(sdword nVertices);
TI_API void transTransformVertexList(sdword n, hvector* dest, vertexentry* source, hmatrix* m);
TI_API void transPerspectiveTransform(sdword n, hvector* dest, hvector* source, hmatrix* m);
TI_API void transGeneralPerspectiveTransform(sdword n, hvector* dest, hvector* source, hmatrix* m);
TI_API void transTransformCompletely(sdword n, hvector* dest, hvector* intermed, vertexentry* source, hmatrix* m0, hmatrix* m1);
TI_API bool_t transPerspectiveMatrix(hmatrix* m);

TI_API void transSinglePerspectiveTransform(hvector* screenSpace, hmatrix* projection, hvector* cameraSpace);
TI_API void transSingleTotalTransform(vector* screenSpace, hmatrix* modelview, hmatrix* projection, vector* worldSpace);

#endif
