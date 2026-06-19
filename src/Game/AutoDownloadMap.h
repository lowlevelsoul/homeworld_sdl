// =============================================================================
//  AutoDownloadMap.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 99/03/29 by gshaw
// =============================================================================

#ifndef ___AUTODOWNLOADMAP_H
#define ___AUTODOWNLOADMAP_H

#include "tiPlatform.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------

TI_API void autodownloadmapStartup(void);
TI_API void autodownloadmapShutdown(void);
TI_API void autodownloadmapReset(void);
TI_API void autodownloadmapGetFilesOfMap(void);
TI_API void autodownloadmapGotMapName(char *mapname, sdword numPlayers, sdword minPlayers, sdword maxPlayers);
TI_API bool autodownloadmapRequired(void);
TI_API void receivedFilePacketCB(ubyte *packet,udword sizeofPacket);
TI_API bool autodownloadmapReceivedAllFiles(void);
TI_API void autodownloadmapSendAllFiles(void);
TI_API void autodownloadmapPrintStatusStart(void);
TI_API real32 autodownloadmapPercentReceivedFiles(void);
TI_API real32 autodownloadmapPercentSentFiles(void);
TI_API bool autodownloadmapSendAFile(void);

#endif

