/*=============================================================================
    UTILITY.H: General utility declarations for the Windows interface system
    of Homeworld.

        Created June 1997 by Luke Moloney.
=============================================================================*/

#ifndef ___UTILITY_H
#define ___UTILITY_H

#include "tiPlatform.h"
#include "FEFlow.h"
#include "ObjTypes.h"
#include "Region.h"
#include "TitanInterfaceC.h"
#include "Types.h"

/*=============================================================================
    Switches:
=============================================================================*/
#ifdef HW_BUILD_FOR_DEBUGGING

#define UTY_ERROR_CHECKING      1               //basic error checking
#define UTY_VERBOSE_LEVEL       1               //control verbose printing
#define UTY_PLAYER_LOGGING      1               //PlayerStart.log

#else

#define UTY_ERROR_CHECKING      0               //no error ckecking in retail
#define UTY_VERBOSE_LEVEL       0               //don't print any verbose strings in retail
#define UTY_PLAYER_LOGGING      0               //PlayerStart.log

#endif

/*=============================================================================
    Definitions:
=============================================================================*/
#define UTY_ErrorStringLength       256
#define UTY_TimerResolutionMax      240         //maximum timer resolution
//bit-field flags stating which system has started properly
typedef enum
{
    SSA_DebugWindow,
    SSA_MemoryHeap,
    SSA_MemoryModule,
    SSA_Timer,
    SSA_Task,
    SSA_Mouse,
    SSA_Region,
    SSA_Render,
    SSA_Texture,
    SSA_Universe,
    SSA_Selection,
    SSA_MainRegion,
    SSA_UIControls,
    SSA_FEFlow,
    SSA_MouseClipped,
    SSA_ConstructionManager,
    SSA_Effect,
    SSA_FrontEndData,
    SSA_Undo,
    SSA_FontReg,
    SSA_TacticalOverlay,
    SSA_ShipTrails,
    SSA_Lights,
    SSA_TextureRegistry,
    SSA_RegistryRefreshed,
    SSA_TaskBar,
    SSA_SensorsManager,
    SSA_ColorPicker,
    SSA_Teams,
    SSA_ScenarioPicker,
    SSA_RandomNumbers,
    SS2_BSpline,
    SS2_NIS,
    SS2_NetworkQueues,
    SS2_Guns,
    SS2_MultiplayerGame,
    SS2_AIPlayer,
    SS2_Strings,
    SS2_LaunchMgr,
    SS2_DemoMode,
    SS2_ResearchMgr,
    SS2_PlugScreen,
    SS2_Prim3D,
    SS2_BabyCallBackRegistry,
    SS2_InfoOverlay,
    SS2_GamePicker,
    SS2_GameChat,
    SS2_ShipView,
    SS2_Ping,
    SS2_BattleChatter,
    SS2_SubTitle,
    SS2_Tutorial,
    SS2_ToggleKeys,
    SS2_SoundEngine,

    SS2_SystemStarted,

    SSA_NumberBits
}
startupbit;

/*=============================================================================
    Macros:
=============================================================================*/
//these macrs defined in case we have to create a mapping from windows virtual
//key codes to our own internal key codes.
#define KeyMapFromWindows(n)        (n)
#define utyTest(f)              (utyStartedBits[f])
#define utySet(f)               (utyStartedBits[f] = TRUE)
#define utyClear(f)             (utyStartedBits[f] = FALSE)
#define utyTest2(f)             utyTest(f)
#define utySet2(f)              utySet(f)
#define utyClear2(f)            utyClear(f)


/*=============================================================================
    Data:
=============================================================================*/
//flag stating system has started properly
extern sdword utySystemStarted;
extern regionhandle ghMainRegion;
extern sdword enableTextures;
extern sdword enableSmoothing;
extern sdword enableStipple;
extern ShipRace whichRaceSelected;

extern color utyBaseColor;
extern color utyStripeColor;
extern bool  utyShipsAlwaysUseOwnerColors;

extern char utyName[MAX_PERSONAL_NAME_LEN];
extern char utyPassword[MAX_PERSONAL_NAME_LEN];

extern char levelfile[];
extern char dirfile[];

extern udword utyNFrameTicks;
extern taskhandle utyRenderTask;
#if defined (HW_GAME_DEMO) || defined (HW_GAME_RAIDER_RETREAT)
extern bool utyPlugScreens;
#endif
extern bool utyCreditsSequence;

extern bool8 utyStartedBits[SSA_NumberBits];

extern char utyMusicFilename[];
extern char utyVoiceFilename[];


/*=============================================================================
    Functions:
=============================================================================*/
//handles the message loop for fatal errors
TI_API void utyFatalErrorWaitLoop(int exitCode);
TI_API sdword utyNonFatalErrorWaitLoop(void);

//startup/shutdown game systems
TI_API char *utyGameSystemsPreInit(void);
TI_API char *utyGameSystemsPreShutdown(void);
TI_API char *utyGameSystemsInit(void);
TI_API char *utyGameSystemsShutdown(void);

TI_API udword utyCloseOK(regionhandle region, sdword ID, udword event, udword data);

TI_API void gameStart(char *loadfilename);
TI_API void gameEnd(void);

//query system timer and call task manager
TI_API void utyTasksDispatch(void);
void utyTaskTimerClear(void);                   //cancels all previous task time

//get client rect in screen coords
TI_API void utyClientRectGet(rectangle *rect);
TI_API void utyMouseButtonsClear(void);
TI_API void utyForceTopmost(bool bTopMost);

//clip the mouse
TI_API void utyClipMouse(sdword clip);

TI_API void utyNewGameStart(char *name, featom *atom);
TI_API void utyGameQuit(char *name, featom *atom);
TI_API void utyGameQuitToMain(char *name, featom *atom);

//load/save options from disk
TI_API void utyOptionsFileRead(void);
TI_API void utyOptionsFileWrite(void);

//text entry things
TI_API real32 utyCaretBlinkRate(void);
TI_API void utyDoubleClick(void);

TI_API void utyLoadSinglePlayerGameGivenFilename(char *filename);
TI_API void utyLoadMultiPlayerGameGivenFilename(char *filename);

TI_API bool utyChangeResolution(sdword width, sdword height, sdword depth);

TI_API bool utyBrowserExec(char *URL);
TI_API void utyGetFirstCDPath(char *szPath);

//toggle key things
TI_API void utyToggleKeyStatesSave(void);
TI_API void utyToggleKeyStatesRestore(void);
TI_API bool utyCapsLockToggleState(void);

// Start the player dropped dialog box.
TI_API void utyStartDroppedDialog(sdword playernum);

extern sdword utyPlayerDroppedDisplay;

#endif
