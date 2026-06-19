/*=============================================================================
    Name    : titannet.h
    Purpose : Definitions for the titan game networking stuff.

    Created 6/23/1998 by ddunlop
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___TITANNET_H
#define ___TITANNET_H

#include "tiPlatform.h"
#include "TitanInterfaceC.h"
#include "Types.h"

extern real32 TITAN_PICKER_REFRESH_TIME;

TI_API void generateDirectoryCustomInfo(DirectoryCustomInfoMax *buildDirectoryCustomInfo);

TI_API void captainGameStartCB(void);
TI_API void titanGameDisolved(bool_t shutdown);
TI_API void titanUpdatePlayer(bool_t captain);

TI_API void titanResetGameCreated(void);

TI_API void titanGameStartup(void);
TI_API void titanGameShutdown(void);

TI_API void titanGameEnded(void);

extern wchar_t RemoveGameRequest[];

extern wchar_t CurrentChannel[];
extern wchar_t CurrentChannelDescription[];

extern real32 KEEPALIVE_SEND_IAMALIVE_TIME;
extern real32 KEEPALIVE_IAMALIVE_TIMEOUT;
extern real32 KEEPALIVE_SEND_ALIVESTATUS_TIME;

TI_API bool_t titanCheckValidVersion(char *myversion);
TI_API bool_t CheckNetworkVersionCompatibility(char *netversion);

extern bool_t HaveValidVersions;
extern char ValidVersions[];

extern udword ROOM_MIN_THRESHOLD;
extern udword ROOM_MAX_THRESHOLD;

TI_API bool_t titanKickPlayer(udword i);

#endif
