
#ifndef ___MAINSWITCHES_H
#define ___MAINSWITCHES_H

#include "tiPlatform.h"
#include "MaxMultiplayer.h"
#include "Types.h"

#ifndef STATVIEWER_PROGRAM
//statviewer program is compiling this bitch...lets not do this
#endif

//command-line switches and parameters
extern bool_t DebugWindow;
extern sdword MemoryHeapSize;
extern bool_t mouseClipped;
extern bool_t startupClipMouse;
extern bool_t showFrontEnd;
extern bool_t enableSFX;
extern bool_t enableSpeech;
extern bool_t reverseStereo;
extern bool_t useWaveout;
extern bool_t useDSound;
extern bool_t coopDSound;
extern bool_t noDefaultComputerPlayer;
extern bool8 ComputerPlayerEnabled[MAX_MULTIPLAYER_PLAYERS];
extern udword ComputerPlayerLevel[MAX_MULTIPLAYER_PLAYERS];
extern bool_t gatherStats;

extern bool_t showStatsFight;
extern udword showStatsFightI;
extern udword showStatsFightJ;

extern bool_t showStatsFancyFight;
extern char showStatsFancyFightScriptFile[50];

extern sdword GiveAllTechnology;

#ifdef DEBUG_TACTICS
    extern bool_t tacticsOn;
#endif
extern bool_t noRetreat;

extern bool_t recordPackets;
extern bool_t playPackets;
extern bool_t recordplayPacketsInGame;
extern bool_t recordFakeSendPackets;
#define MAX_RECORDPACKETFILENAME_STRLEN 50
extern char recordPacketFileName[MAX_RECORDPACKETFILENAME_STRLEN];
extern char recordPacketSaveFileName[MAX_RECORDPACKETFILENAME_STRLEN];

extern bool_t noAuthorization;

extern bool_t mainCDCheckEnabled;

extern bool_t SecretWON;
extern bool_t forceLAN;

extern bool_t ShortCircuitWON;

extern char versionString[];
extern char networkVersion[];
extern char languageVersion[];
extern char minorBuildVersion[];

extern bool_t autoSaveDebug;

extern bool_t determCompPlayer;

extern bool_t bkDisableKeyRemap;

extern bool_t debugPacketRecord;

extern bool_t pilotView;

#endif

