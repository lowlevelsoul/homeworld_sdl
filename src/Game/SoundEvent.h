/*=============================================================================
    Name    : SoundEvent.h
    Purpose : Defines for SoundEvent.c

    Created 7/24/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___SOUNDEVENT_H
#define ___SOUNDEVENT_H

#include "tiPlatform.h"
#include "SoundEventDefs.h"
#include "SoundMusic.h"
#include "SoundStructs.h"
#include "SpaceObj.h"
#include "SpeechEvent.h"
#include "Types.h"

/*=============================================================================
    Switches:
=============================================================================*/

#ifdef HW_BUILD_FOR_DEBUGGING

#define SE_ERROR_CHECKING          1           //general error checking
#define SE_VERBOSE_LEVEL           1           //control specific output code
#define SE_DEBUG                   1           //switch for command line options

#else

#define SE_ERROR_CHECKING          0           //general error checking
#define SE_VERBOSE_LEVEL           0           //control specific output code
#define SE_DEBUG                   0           //switch for command line options

#endif


#define SOUND_NOTINITED             -1

#define SOUND_EVENT_DEFAULT			-1

#define SOUND_FRONTEND_TRACK		AMB12_FrontEnd

#define SPEECH_HYPERSPACE_DELAY		2.5f

/*=============================================================================
    Tweaks
=============================================================================*/

extern real32	SPEECH_MOSHIP_WARNING_TIME;
extern real32	SPEECH_WARNING_TIME;

extern Ship *lastshiptospeak;
extern sdword lastgrouptospeak;


/* generic functions */
void soundEventInit(void);				/* Initializes audio mixer, stream and DirectSound/Waveout */
void soundEventClose(void);				/* Shuts down the mixer and frees resources, any soundevent calls will fail */
void soundEventReset(void);				/* Shuts down the mixer but does not free resources, soundevent calls will continue to work */
void soundEventUpdate(void);			/* Update function that does panning, volume, etc for objects in the universe */
void soundEventInitStruct(SOUNDEVENT *pseStruct);	/* initializes a SOUNDEVENT structure for use, all ships have a SOUNDEVENT structure */
void soundEventPause(bool bPause);		/* Shuts down or restore the mixer */
TI_API void soundEventReloadVolumes(void);
TI_API void soundEventShutdown(void);
TI_API void soundEventRestart(void);

/* sound FX functions */
TI_API sdword soundEventPlay(void *object, sdword event, Gun *gun);
#define soundEvent(a,b)					soundEventPlay(a, b, NULL)
#define soundEventMisc(a)				soundEventPlay(NULL, a, NULL)
#define soundEventStartEngine(a)		soundEventPlay(a, ShipCmn_Engine, NULL)
#define soundEventBurstFire(a,b)		soundEventPlay(a, Gun_WeaponFireLooped, b)

TI_API sdword soundEffect(void *effect, sdword event);
TI_API sdword soundEffectType(Effect *effect, sdword event, sdword objecttype);

TI_API sdword soundEventStopSound(sdword soundhandle, sdword numblocks);
#define soundEventStop(a)				soundEventStopSound(a, 0)

TI_API void soundEventBurstStop(Ship *ship, Gun *gun);

TI_API void soundEventShipDied(Ship *deadship);
TI_API void soundEventShipRemove(Ship *ship);
TI_API void soundEventDerelictRemove(Derelict *pDerelict);

TI_API void soundEventStopSFX(real32 fadetime);


/* speech functions */
void speechEventUpdate(void);			/* Update function so that speech continues to stream */
TI_API //sdword speechEventPlay(void *object, sdword event, sdword var, sdword playernum, sdword variation);
//#define speechEventFleet(a,b,c)			speechEventPlay(NULL, a, b, c, SOUND_NOTINITED)
//#define speechEvent(a,b,c)				speechEventPlay(a, b, c, SOUND_NOTINITED, SOUND_NOTINITED)
//#define speechEventVar(a, b, c, d)		speechEventPlay(a, b, c, SOUND_NOTINITED, d)

TI_API bool speechEventAttack(void);
TI_API void speechEventUnderAttack(Ship *target);

TI_API sdword speechEventQueue(void *object, sdword event, sdword var, sdword variation, sdword actornum, sdword playernum, sdword linkto, real32 timeout, sword volume);
#define speechEventFleet(a,b,c)		speechEventQueue(NULL, a, b, -1, 0, c, -1, 5.0f, -1)
#define speechEventFleetSpec(a,b,c,d)	speechEventQueue(a, b, c, -1, 0, d, -1, 5.0f, -1)
#define speechEventFleetVar(a,b,c,d)	speechEventQueue(NULL, a, b, c, 0, d, -1, 5.0f, -1)
#define speechEvent(a,b,c)			speechEventQueue(a, b, c, -1, -1, -1, -1, 0.0f, -1)
#define speechEventPlay(a, b, c, d, e)	speechEventQueue(a, b, c, e, -1, e, -1, 0.0f, -1)
#define speechEventVar(a, b, c, d)	speechEventQueue(a, b, c, d, -1, -1, -1, 0.0f, -1)

TI_API sdword speechEventRemoveShip(Ship *pShip);
TI_API sdword speechEventStop(sdword handle, real32 fadetime, bool addstatic);
TI_API sdword speechEventStopAllSpecific(real32 fadetime, sdword speechType);
#define speechEventStopAll(ft)		speechEventStopAllSpecific(ft, SPEECH_TYPE_SINGLE_PLAYER)
TI_API sdword speechEventActorStop(udword actorMask, real32 fadetime);
#define speechEventFleetIntelStop(ft)       speechEventActorStop(SPEECH_ACTOR_FLEET_INTELLIGENCE, (ft))
#define speechEventFleetCommandStop(ft)     speechEventActorStop(SPEECH_ACTOR_FLEET_COMMAND, (ft))
#define ACTOR_ALL_ACTORS    (SPEECH_ACTOR_FLEET_COMMAND | SPEECH_ACTOR_FLEET_INTELLIGENCE | SPEECH_ACTOR_TRADERS | SPEECH_ACTOR_P2_KADESHI | SPEECH_ACTOR_ALL_ENEMY_SHIPS | SPEECH_ACTOR_AMBASSADOR)
TI_API sdword speechEventCleanup(void);


/* Redbook audio functions */
TI_API void soundEventPlayCD(uword tracknum);
TI_API void soundEventStopCD(void);

/* Streamed Music functions */
TI_API void soundEventPlayMusic(sdword tracknum);
TI_API void soundEventStopMusic(real32 fadetime);
TI_API void soundEventStopTrack(sdword tracknum, real32 fadetime);
TI_API void musicEventNextTrack(void);
TI_API void musicEventPrevTrack(void);
TI_API sdword musicEventCurrentTrack(void);

/* Setup and Control functions */
TI_API void soundEventSFXVol(real32);
TI_API void soundEventSFXMasterVol(real32);
TI_API void soundEventSpeechVol(real32);
TI_API void soundEventSpeechMasterVol(real32);
TI_API void soundEventMusicVol(real32);
TI_API void soundEventMusicMasterVol(real32);
TI_API void soundEventMusicVolNOW(real32 level);
TI_API void soundEventMusicMasterVolNOW(real32 level);
TI_API void soundEventMasterEQ(real32 *pmasterEQ);
TI_API void soundEventSetActor(sdword actornum, bool bOn);
TI_API void soundEventVocalSettings(bool bCommands, bool bStatus, bool bChatter);
TI_API void soundEventGetVolume(real32 *sfxvol, real32 *speechvol, real32 *musicvol);
TI_API void soundEventHearActor(sdword actornum);
TI_API void soundEventSetActorFlag(sdword actorflag, bool bOn);

#endif
