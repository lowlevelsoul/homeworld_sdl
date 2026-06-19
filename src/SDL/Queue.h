
#ifndef ___QUEUE_H
#define ___QUEUE_H

#include "tiPlatform.h"
#include "SDL.h"
#include "Types.h"

/*=============================================================================
    Types:
=============================================================================*/

typedef struct
{
    //void *mutex;
    SDL_mutex *mutex;
    ubyte *buffer;
    udword buffersize;
    udword head;
    udword tail;
    udword num;
    udword totalsize;
    udword totaltotalsize;
    udword overruns;
} Queue;

/*=============================================================================
    Functions:
=============================================================================*/

TI_API void InitQueue(Queue *queue,udword buffersize);
TI_API void CloseQueue(Queue *queue);
TI_API void ResetQueue(Queue *queue);
TI_API void HWEnqueue(Queue *queue,ubyte *packet,udword sizeofPacket);
TI_API udword HWDequeue(Queue *queue,ubyte **packet);
TI_API udword Peekqueue(Queue *queue,ubyte **packet);
TI_API void LockQueue(Queue *queue);
TI_API void UnLockQueue(Queue *queue);

/*=============================================================================
    Macros:
=============================================================================*/

#define queueNumberEntries(q) ((q).num)
#define queueNumberOverruns(q) ((q).overruns)

#endif

