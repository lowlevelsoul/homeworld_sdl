/*
	Tutor.h - types & protoypes for the Tutorial System
*/

#ifndef ___TUTOR_H
#define ___TUTOR_H

#include "tiPlatform.h"
#include "FEFlow.h"
#include "prim2d.h"
#include "ShipDefs.h"
#include "ShipSelect.h"
#include "SpaceObj.h"
#include "Types.h"
#include "Volume.h"

/*=============================================================================
    Definitions:
=============================================================================*/
//tutorial pointer types
#define TUT_PointerTypeNone         0
#define TUT_PointerTypeXY           1
#define TUT_PointerTypeShip         2
#define TUT_PointerTypeShips        3
#define TUT_PointerTypeShipHealth   4
#define TUT_PointerTypeShipGroup    5
#define TUT_PointerTypeRegion       6
#define TUT_PointerTypeAIVolume     7

#define TUT_PointerPulseInc         8           //pointer pulse rate
#define TUT_PointerPulseMin         100         //pointer pulse minimum

//length of a pointer name string
#define TUT_PointerNameLength       60
#define TUT_PointerNameMax          (TUT_PointerNameLength - 1)

#define TUT_NumberPointers          16  //max number of pointers

#define TUT_ArrowheadAngle          (PI / 12.0f)
#define TUT_ArrowheadLength         13.0f
#define TUT_ShipCircleSizeMin       primScreenToGLScaleX(4)

/*=============================================================================
    Type definitions:
=============================================================================*/
typedef struct
{
	udword	bKASFrame:1;	// For internal use only by the game
	udword	bGameRunning:1;	// Turned off, it pauses the universe, but not KAS

	// The following bit fields enable their respective commands
	udword	bBuildManager:1;
	udword	bSensorsManager:1;
	udword	bResearchManager:1;
    udword  bPauseGame:1;
	udword	bDock:1;
    udword  bFormation:1;
	udword	bLaunch:1;
	udword	bMove:1;
    udword  bMoveIssue:1;
	udword	bAttack:1;
    udword  bHarvest:1;
    udword  bCancelCommand:1;
    udword  bScuttle:1;
    udword  bRetire:1;
	udword	bClickSelect:1;
	udword	bBandSelect:1;
	udword	bCancelSelect:1;
	udword	bSpecial:1;
	udword	bBuildBuildShips:1;
	udword	bBuildPauseJobs:1;
	udword	bBuildCancelJobs:1;
	udword	bBuildClose:1;
    udword  bBuildArrows:1;
    udword  bSensorsClose:1;
	udword	bContextMenus:1;
    udword  bContextFormDelta:1;
    udword  bContextFormBroad:1;
    udword  bContextFormX:1;
    udword  bContextFormClaw:1;
    udword  bContextFormWall:1;
    udword  bContextFormSphere:1;
    udword  bContextFormCustom:1;
    udword  bEvasive:1;
    udword  bNeutral:1;
    udword  bAgressive:1;
	udword	bTaskbarOpen:1;
	udword	bTaskbarClose:1;
	udword	bResearchSelectTech:1;
	udword	bResearchSelectLab:1;
	udword	bResearchResearch:1;
	udword	bResearchClearLab:1;
	udword	bResearchClose:1;
	udword	bFocus:1;
	udword	bFocusCancel:1;
	udword  bMothershipFocus:1;
	udword	bLaunchSelectShips:1;
	udword	bLaunchLaunch:1;
	udword	bLaunchLaunchAll:1;
	udword	bLaunchClose:1;
} tutGameEnableFlags;

//structure of a named pointer
typedef struct
{
    char name[TUT_PointerNameLength];           //name of pointer
    sdword pointerType;                         //type of object the pointer points to
    sdword x, y;                                //if the pointer points at a point on screen
    ShipPtr ship;                               //if the pointer points to a ship
    rectangle rect;                             //if the pointer points to a rectangle of some sort
    Volume *volume;                             //if it points to an AI point
    SelectCommand *selection;                   //optional selection of ships
}
tutpointer;

extern bool tutPointersDrawnThisFrame;

/*=============================================================================
    Functions:
=============================================================================*/
TI_API void tutPreInitTutorial(char *dirfile, char *levelfile);
TI_API void tutInitTutorial(char *dirfile, char *levelfile);

extern tutGameEnableFlags tutEnable;
extern char tutBuildRestrict[TOTAL_STD_SHIPS];
extern ShipType tutFEContextMenuShipType;
extern ShipPtr tutPointerShip;
extern rectangle *tutPointerShipHealthRect;
extern rectangle *tutPointerShipGroupRect;

TI_API void tutSaveLesson(sdword Num, char *pName);

TI_API void tutSaveTutorialGame(void);
TI_API void tutLoadTutorialGame(void);

TI_API void tutTutorial1(char *name, featom *atom);

TI_API void tutSetPointerTargetXY(char *name, sdword x, sdword y);
TI_API void tutSetPointerTargetXYRight(char *name, sdword x, sdword y);
TI_API void tutSetPointerTargetXYBottomRight(char *name, sdword x, sdword y);
TI_API void tutSetPointerTargetXYTaskbar(char *name, sdword x, sdword y);
TI_API void tutSetPointerTargetXYFE(char *name, sdword x, sdword y);
TI_API void tutSetPointerTargetShip(char *name, ShipPtr ship);
TI_API void tutSetPointerTargetShipSelection(char *name, SelectCommand *ships);
TI_API void tutSetPointerTargetShipHealth(char *name, ShipPtr ship);
TI_API void tutSetPointerTargetShipGroup(char *name, ShipPtr ship);
TI_API void tutPlayerShipDied(ShipPtr ship);
TI_API void tutSetPointerTargetFERegion(char *name, char *pAtomName);
TI_API void tutSetPointerTargetRect(char *name, sdword x0, sdword y0, sdword x1, sdword y1);
TI_API void tutSetPointerTargetAIVolume(char *name, Volume *volume);
TI_API void tutRemovePointerByName(char *name);
TI_API void tutRemoveAllPointers(void);
TI_API void tutRemoveAllPointers(void);
TI_API void tutDrawTextPointers(rectangle *pRect);

TI_API void tutSetTextDisplayBox(sdword x, sdword y, sdword width, sdword height, bool bScale);
TI_API void tutSetTextDisplayBoxToSubtitleRegion(void);
TI_API void tutShowText(char *szText);
TI_API void tutHideText(void);
TI_API void tutShowNextButton(void);
TI_API void tutHideNextButton(void);
TI_API sdword tutNextButtonClicked(void);
TI_API void tutShowBackButton(void);
TI_API void tutHideBackButton(void);
TI_API void tutShowPrevButton(void);
TI_API void tutShowImages(char *szImages);
TI_API void tutHideImages(void);

TI_API void tutStartup(void);
TI_API void tutShutdown(void);
TI_API void tutInitialize(void);
TI_API void tutUnInitialize(void);

TI_API void tutEnableEverything(void);
TI_API void tutDisableEverything(void);
TI_API void tutSetEnableFlags(char *pFlagString, long Val);

TI_API void tutBuilderSetRestrictions(char *pShipTypes, bool bRestricted);
TI_API void tutBuilderRestrictAll(void);
TI_API void tutBuilderRestrictNone(void);


TI_API sdword tutIsBuildShipRestricted(sdword shipType);
TI_API sdword tutSelectedContainsShipTypes(char *pShipTypes);

TI_API void tutGameMessage(char *commandName);
TI_API bool tutGameSentMessage(char *commandName);
TI_API bool tutGameMessageInQueue(char *commandNames);
TI_API void tutResetGameMessageQueue(void);
TI_API sdword tutContextMenuDisplayedForShipType(char *pShipType);
TI_API void  tutResetContextMenuShipTypeTest(void);

TI_API sdword tutBuildManagerShipTypeInBatchQueue(char *pShipType);
TI_API sdword tutBuildManagerShipTypeInBuildQueue(char *pShipType);
TI_API sdword tutBuildManagerShipTypeSelected(char *pShipType);

TI_API sdword tutCameraFocusedOnShipType(char *pShipTypes);

#endif
