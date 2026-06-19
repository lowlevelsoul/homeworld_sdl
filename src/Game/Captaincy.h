// =============================================================================
//  Captaincy.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 98/10/06 by gshaw
// =============================================================================

#ifndef ___CAPTAINCY_H
#define ___CAPTAINCY_H

#include "tiPlatform.h"
#include "MaxMultiplayer.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------

typedef enum CaptaincyEvent {
    CAPEVENT_STARTGAME,
    CAPEVENT_TIMEOUT1,
    CAPEVENT_TIMEOUT2,
    CAPEVENT_TWAITFORPAUSEACKS,
    CAPEVENT_GIVEUP_CAPTAINCY_NOTICE,
    CAPEVENT_CAPTAIN_PROPOSAL,
    CAPEVENT_PAUSE_TRANSFERRING_CAPTAIN,
    CAPEVENT_PAUSE_ACK,
    CAPEVENT_PAUSE_YOU_BE_CAPTAIN,
    CAPEVENT_I_AM_NEW_CAPTAIN,
    CAPEVENT_RECEIVED_SYNC_PKT
} CaptaincyEvent;

typedef struct CaptaincyCustomInfo
{
    udword custom[MAX_MULTIPLAYER_PLAYERS];
} CaptaincyCustomInfo;


TI_API void TransferCaptaincyGameEnded(void);
TI_API void TransferCaptaincyGameStarted(void);

TI_API void TransferCaptaincyStateMachine(CaptaincyEvent event, uword from, udword misc, CaptaincyCustomInfo *customInfo);
TI_API void TransferCaptaincySyncPacketReceivedNotify(void);

TI_API void TransferCaptaincyUpdate(void);

TI_API void TimeoutTimerInitAll(void);
TI_API void TimeoutTimerCloseAll(void);
TI_API void TimeoutTimerUpdateAll(void);

TI_API void GiveUpCaptaincy(void);

TI_API void captaincyLogInit(void);
TI_API void captaincyLog(bool echotoscreen, char *format, ...);


extern bool transferCaptaincyDisabled;
extern bool captaincyLogEnable;
extern bool printCaptainMessage;

extern real32 T1_Timeout;
extern real32 T2_Timeout;
extern real32 TWAITFORPAUSEACKS_Timeout;

#endif

