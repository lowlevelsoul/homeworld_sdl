// =============================================================================
//  Undo.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 8/4/1997 by lmoloney
// =============================================================================

#ifndef ___UNDO_H
#define ___UNDO_H

#include "tiPlatform.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------

typedef bool_t (*undofunc)(sdword userID, ubyte *userData, sdword length);

typedef struct undoinfo
{
    undofunc function;        // function to call to undo
    sdword userID;            // arbitrary user ID
    ubyte *userData;          // allocated user data
    sdword length;            // length of allocated user data
} undoinfo;

TI_API void udStartup(void);
TI_API void udShutdown(void);

TI_API sdword udLatestThingPush(undofunc function, sdword userID, ubyte *userData, sdword length);
TI_API sdword udLatestThingUndo(void);

#endif
