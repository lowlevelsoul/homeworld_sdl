// =============================================================================
//  ChannelFSM.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
// =============================================================================

#ifndef ___CHANNELFSM_H
#define ___CHANNELFSM_H

#include "tiPlatform.h"
#include "Types.h"

TI_API bool cCreateChannel(wchar_t *name, wchar_t *desc);
TI_API bool cJoinChannelRequest(wchar_t *name, wchar_t *desc);
TI_API void cNotifyChatConnected(void);
TI_API void cResetFSM(void);
TI_API bool cJoinADefaultRoom(void);
TI_API void cNotifyChatBadResponse(void);

#endif

