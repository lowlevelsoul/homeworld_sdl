// =============================================================================
//  Animatic.h
//  - playback of animatics via OpenGL
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 2/11/1999 by khent
// =============================================================================

#ifndef ___ANIMATIC_H
#define ___ANIMATIC_H

#include "tiPlatform.h"
#include "Types.h"

extern sdword animaticJustPlayed;

TI_API void animStartup(void);
TI_API void animShutdown(void);

TI_API void animAviSetup(bool_t on);
TI_API bool_t animAviPlay(sdword a, sdword b);
TI_API void animAviEnd(void);

TI_API bool_t animBinkPlay(sdword a, sdword b);

TI_API void animAviDecode(sdword frame);

#endif
