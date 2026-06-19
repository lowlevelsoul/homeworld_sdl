/*============================================================================= 
    Name    : ShipView.h
    Purpose : Renders a specific ship to a window

    Created 7/27/1998 by pgrant
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___SHIPVIEW_H
#define ___SHIPVIEW_H

#include "tiPlatform.h"
#include "FEFlow.h"
#include "Region.h"
#include "ShipDefs.h"

TI_API void svStartup(void);
TI_API void svShutdown(void);

TI_API void svSelectShip(ShipType type);
TI_API void svClose(void);

TI_API void svDirtyShipView(void);

TI_API void svShipViewRender(featom* atom, regionhandle region);

#endif
