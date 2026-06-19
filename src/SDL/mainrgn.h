/*=============================================================================
    Name    : mainrgn.h
    Purpose : Logic for handling region events for the main game screen.

    Created 6/27/1997 by lmoloney
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___MAINRGN_H
#define ___MAINRGN_H

#include "tiPlatform.h"
#include "Camera.h"
#include "FEFlow.h"
#include "SpaceObj.h"
#include "Types.h"

/*=============================================================================
    Switches:
=============================================================================*/
#define MR_GUI_SINGLECLICK          1

#ifdef HW_BUILD_FOR_DEBUGGING

#define MR_ERROR_CHECKING           1           //general error checking
#define MR_VERBOSE_LEVEL            2           //control specific output code
#define MR_TEST_HPB                 0           //test heading/pitch/bank interactively
#define MR_RELEASE_MOUSE            1           //allow the mouse to be freed from the window
#define MR_TEST_GUNS                1           //allow the game testing mode
#define MR_SOUND_RELOAD_VOLUMES     1           //permits reloading of volume tables
#define MR_CAN_FOCUS_ROIDS          1           //can focus on asteroids,dust clouds and derelicts with an alt-click
#define MR_KEYBOARD_CHEATS          1           //enable typing in cheats on the keyboard

#else

#define MR_ERROR_CHECKING           0           //general error checking
#define MR_VERBOSE_LEVEL            0           //control specific output code
#define MR_TEST_PING                0           //test ping time
#define MR_TEST_HPB                 0           //test heading/pitch/bank interactively
#define MR_RELEASE_MOUSE            0           //allow the mouse to be freed from the window
#define MR_TEST_GUNS                0           //allow the game testing mode
#define MR_SOUND_RELOAD_VOLUMES     0           //permits reloading of volume tables
#define MR_CAN_FOCUS_ROIDS          0           //can focus on asteroids,dust clouds and derelicts with an alt-click
#define MR_KEYBOARD_CHEATS          0           //enable typing in cheats on the keyboard

#endif

/*=============================================================================
    Definitions:
=============================================================================*/
//message display definitions
#define MR_MESSAGE_LINE_SPACING     12
#define MR_MESSAGE_LINE_START       400
#define MR_MouseMovementClickLimit  12
#define MR_FormationDelay           1.0f
#define MR_NumberDoublePressTime    0.5
#define MR_FastMoveShipClickTime    0.5
#define MR_FastMoveShipClickX       5
#define MR_FastMoveShipClickY       5

#define MR_LetterboxGrey            0.5f, 0.5f, 0.5f

/*=============================================================================
    Data:
=============================================================================*/
//data exported for the benefit of other modules with similar functionality
extern bool mrWhiteOut;
extern real32 mrWhiteOutT;
extern sdword mrRenderMainScreen;
extern sdword mrOldMouseX, mrOldMouseY;
extern sdword mrMouseHasMoved;
extern sdword mrMouseMovementClickLimit;

//extern ShipPtr mrLastClosestShip;
extern real32 MAX_INGAME_MOVECOMMAND_DISTANCE;
extern real32 mrClosestDistance;

//camera rendering in the main region
extern Camera *mrCamera;

extern void (*mrHoldLeft)(void);
extern void (*mrHoldRight)(void);

extern char *mrMenuItemByTactic[];

extern bool helpinfoactive;

extern real32 mrNumberDoublePressTime;
extern sdword mrLastKeyPressed;
extern real32 mrLastKeyTime;

extern bool mrDisabled;

#if MR_CAN_FOCUS_ROIDS
bool mrCanFocusRoids;
#endif

/*=============================================================================
    Functions:
=============================================================================*/
//startup/shutdown of main region code
TI_API void mrStartup(void);
TI_API void mrShutdown(void);
TI_API void mrReset(void);

TI_API void mrShipDied(struct Ship *ship);

//region-process routine for the main region
TI_API udword mrRegionProcess(struct tagRegion *reg, sdword ID, udword event, udword data);
//region-draw routine for the main region
TI_API void mrRegionDraw(regionhandle reg);

//right-click callback functions
TI_API void mrDockingOrders(char *string, featom *atom);
TI_API void mrDeltaFormation(char *string, featom *atom);
TI_API void mrBroadFormation(char *string, featom *atom);
TI_API void mrXFormation(char *string, featom *atom);
TI_API void mrClawFormation(char *string, featom *atom);
TI_API void mrWallFormation(char *string, featom *atom);
TI_API void mrSphereFormation(char *string, featom *atom);
TI_API void mrCustomFormation(char *string, featom *atom);
TI_API void mrHarvestResources(char *string, featom *atom);
TI_API void mrBuildShips(char *string, featom *atom);
TI_API void mrTradeStuff(char *string, featom *atom);
TI_API void mrMoveShips(char *string, featom *atom);
TI_API void mrInfo(char *string, featom *atom);
TI_API void mrCancel(char *string, featom *atom);
TI_API void mrScuttle(char *string, featom *atom);
TI_API void mrRetire(char *string, featom *atom);
TI_API void mrUpdateHyperspaceStatus(bool goForLaunch);
TI_API void mrHyperspace(char *string, featom *atom);
TI_API void mrLaunch(char *string, featom *atom);
TI_API void mrResearch(char *string, featom *atom);
TI_API void mrEvasiveTactics(char *string, featom *atom);
TI_API void mrNeutralTactics(char *string, featom *atom);
TI_API void mrAgressiveTactics(char *string, featom *atom);
TI_API void mrFormAlliance(char *string, featom *atom);
TI_API void mrBreakAlliance(char *string, featom *atom);
TI_API void mrTransferRUS(char *string, featom *atom);

//misc functions
TI_API void mrCameraMotion(void);
TI_API void mrPlayerNameDraw(sdword playerIndex, sdword x, sdword y);
TI_API void mrCommandMessageDraw(void);
TI_API void mrSelectRectBuild(rectangle *dest, sdword anchorX, sdword anchorY);
TI_API sdword mrCursorText(SpaceObj *cursorobj);
TI_API void mrEnable(void);
TI_API void mrDisable(void);
TI_API void mrNULL(void);
TI_API void mrSelectHold(void);
TI_API void mrShipDied(Ship *ship);
TI_API void mrTacticalOverlayState(bool bTactical);

TI_API void bigmessageDisplay(char *msg,sdword position);
TI_API void bigmessageErase(sdword position);

//probe hack functions
TI_API bool mrNeedProbeHack(void);
TI_API void mrProbeHack(void);
TI_API void mrRemoveAllProbesFromSelection(void);

//nis strangeness prevention:
TI_API void mrNISStarting(void);
TI_API void mrNISStopping(void);

#endif
