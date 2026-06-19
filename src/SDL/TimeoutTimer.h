/*=============================================================================
    Name    : TimeoutTimer.h
    Purpose : Definitions for TimeoutTimers

    Created 98/11/13 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___TIMEOUTTIMER_H
#define ___TIMEOUTTIMER_H

#include "tiPlatform.h"
#include "Types.h"

typedef struct TTimer
{
    bool enabled;
    bool timedOut;
    sqword timerLast;
    udword timeoutTicks;
} TTimer;

TI_API void TTimerInit(TTimer *timer);
TI_API void TTimerClose(TTimer *timer);
TI_API void TTimerDisable(TTimer *timer);
TI_API bool TTimerUpdate(TTimer *timer);
TI_API void TTimerReset(TTimer *timer);
TI_API void TTimerStart(TTimer *timer,real32 timeout);
TI_API bool TTimerIsTimedOut(TTimer *timer);

TI_API void GetRawTime(sqword *time);

#endif

