
/*=============================================================================
    Name    : options.h
    Purpose : Definitons for the options

    Created  11/05/1998 by yo
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/


#ifndef ___OPTIONS_H
#define ___OPTIONS_H

#include "tiPlatform.h"
#include "Key.h"
#include "Region.h"
#include "Types.h"

/*=============================================================================
    Definitions:
=============================================================================*/
#define OP_KEYMAPSIZE 80
    //4 chars needed per key

#define OP_TroubleShootPage "http://www.sierrastudios.com/games/homeworld/noflash/c-support.html"

#define OP_ResolutionFont "Arial_12.hff"
#define OP_RenderFont "Arial_12.hff"

#define OP_ResolutionSelectedColor  colRGB(255,255,105)
#define OP_ResolutionColor          colRGB(240,240,240)

#define OP_RenderSelectedColor      colRGB(255,255,105)
#define OP_RenderColor              colRGB(240,240,240)

#define OP_DimRenderColor     colRGB(192,192,192)
#define OP_RenderColorOutline colRGB(120,70,0)

extern uword opKeyDetour;
extern char opKeymap[OP_KEYMAPSIZE];

extern bool opReloading;
extern sdword opNoPalMB;
extern sdword opMusicVol;
extern sdword opSFXVol;
extern sdword opSpeechVol;
extern sdword opSpeakerSe;
extern sdword opEqualizer;
extern sdword opSpeakerSetting;
extern sdword opVoice0On;
extern sdword opVoice1On;
extern sdword opVoice2On;
extern sdword opVoiceComm;
extern sdword opVoiceStat;
extern sdword opVoiceChat;
extern sdword opMouseSens;
extern sdword opInfoOverlayVar;
extern sdword opBattleChatter;
extern sdword opEffectsVal;
extern sdword opBrightnessVal;
extern udword opDetailThresholdVal;
extern bool opCustomEffectsToggled;
extern sdword opNoLODVal;
extern sdword opNumChannels;
extern sdword opAutoChannel;
extern sdword opSoundQuality;

extern bool   opTimerActive;
extern real32 opTimerStart;
extern real32 opTimerLength;

// previously in LilOptions.h
extern udword opDeviceCRC;
extern sdword opDeviceIndex;
extern sdword opCPUDiff;
extern sdword opCPUAttack;

// Homeworld.cfg configurable values

extern udword opPauseOrders;
extern udword opShipRecoil;

TI_API void opOptionsSaveCustomEffectsSettings(void);


#define NUM_SMOOTHIES 32


struct SmoothieX;

typedef void (*smoothieFunc)(real32 data, struct SmoothieX *smoo);    //callback function

typedef struct SmoothieX
{
    real32 feedback;
    real32 buffer;
    real32 *source;
    real32 *dest;
    sdword *destint;
    real32 threshold;
    sdword *user;
    smoothieFunc callback;
}
Smoothie;



/*=============================================================================
    Function Prototypes:
=============================================================================*/

TI_API void opUpdateSettings(void);
TI_API char *opKeyToNiceString(keyindex key);
TI_API keyindex opKeyTranslate(keyindex key);
TI_API void opKeyAssign(uword func, keyindex key);
TI_API bool opValidKey(keyindex key);
TI_API void opDefineThisKey(keyindex key);
TI_API void opKeyboardLoad(void);
TI_API udword opMusicVolumeProcess(regionhandle reg, sdword ID, udword event, udword data);
TI_API udword opSFXVolumeProcess(regionhandle reg, sdword ID, udword event, udword data);
TI_API udword opSpeechVolumeProcess(regionhandle reg, sdword ID, udword event, udword data);
TI_API udword opNumChannelsProcess(regionhandle reg, sdword ID, udword event, udword data);

TI_API void opTimerExpired(void);

void InitSmoothie(Smoothie *smooothie,real32 feedback, real32 *source, real32 *dest,
                  sdword *destint, smoothieFunc callback, real32 threshold);
TI_API void AddSmoothie(Smoothie *smoo);
TI_API void RemoveSmoothie(Smoothie *smoo);

TI_API char ConvertSliderToAIPlayerDifficulty(sdword sliderval);

#endif
