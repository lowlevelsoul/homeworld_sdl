//
//  Created 1997/07/01  Darren Stone
//

//
//  support for named, low-resolution timers
//  (specified in seconds, based on universe time)
//
//  the named referencing of these timers make using
//  them a little slower, but friendly for scripting, etc.
//

#ifndef ___TIMER_H
#define ___TIMER_H

#include "tiPlatform.h"
#include "Types.h"

#define TIMER_NAME_MAX_LENGTH 47

#define TIMER_ALLOC_INCREMENT 16

typedef struct {
    char name[TIMER_NAME_MAX_LENGTH+1];
    real32 startTime;
    real32 duration;
    real32 pauseTime;
    bool8 enabled;
    bool8 bPaused;
} Timer;

TI_API void timTimerCreate(char *name);
TI_API void timTimerStart(char *name);
TI_API void timTimerStop(char *name);
TI_API sdword timTimerExpired(char *name);
TI_API sdword timTimerExpiredDestroy(char *name);
TI_API sdword timTimerRemaining(char *name);
TI_API void timTimerSet(char *name, sdword duration);
TI_API void timTimerCreateSetStart(char *name, sdword duration);
TI_API void timTimerDestroy(char *name);
TI_API void timTimerDestroyAll(void);
TI_API void timTimerPause(Timer *tim);
TI_API void timTimerPauseAllNotScoped(char *scopeName);
TI_API void timTimerUnpause(Timer *tim);
TI_API void timTimerUnpauseAll(void);

TI_API void timTimerSave(void);
TI_API void timTimerLoad(void);

#endif
