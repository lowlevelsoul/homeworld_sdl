/*=============================================================================
    Name    : GameChat.h
    Purpose : This file has all of the prototypes fo the GameChat logic.

    Created 7/23/1998 by ddunlop
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/
#ifndef ___GAMECHAT_H
#define ___GAMECHAT_H

#include "tiPlatform.h"
#include "MultiplayerGame.h"

#define GC_NORMALMESSAGE        1
#define GC_WHISPEREDMESSAGE     2
#define GC_TEXTMESSAGE          3
#define GC_BUFFERSTART          4
#define GC_BUFFEREND            5
#define GC_WRAPMESSAGE          6

typedef struct chathistory
{
    Node            link;
    char            chatstring[MAX_CHATSTRING_LENGTH];
    char            userName[MAX_USERNAME_LENGTH];
    sdword          playerindex;
    udword          messageType;
    udword          col;
    sdword          indent;
}
chathistory;

extern bool gcRunning;
extern bool ViewingBuffer;

TI_API void gcRemoveAmpersands(char *dest, char *source);
TI_API void gcChatEntryStart(bool toAllies);
TI_API void gcRUTransferStart(uword playertosendto);
TI_API void gcProcessGameChatPacket(struct ChatPacket *packet);
TI_API void gcProcessGameTextMessage(char *message, udword col);
TI_API void gcPollForNewChat(void);

TI_API void gcPageDownProcess(void);
TI_API void gcPageUpProcess(void);
TI_API void gcCancelViewingBuffer(void);

TI_API void gcStartup(void);
TI_API void gcShutdown(void);


#endif
