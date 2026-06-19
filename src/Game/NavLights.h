/*=============================================================================
    Name    : NavLights.h
    Purpose : Header file for NavLights.c

    Created 6/21/1997 by agarden
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___NAVLIGHTS_H
#define ___NAVLIGHTS_H

#include "tiPlatform.h"
#include "SpaceObj.h"

TI_API void RenderNAVLights(Ship *ship);
TI_API void navLightStaticInfoDelete(NAVLightStaticInfo *staticInfo);

#endif

