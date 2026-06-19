/*=============================================================================
    Name    : GamePick.c
    Purpose : Code for choosing a Game

    Created 10/21/1997 by lmoloney
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___GAMEPICK_H
#define ___GAMEPICK_H

#include "tiPlatform.h"
#include "FEFlow.h"
#include "Region.h"

/*=============================================================================
    Switches:
=============================================================================*/

/*=============================================================================
    Definitions:
=============================================================================*/
#define GP_ScreenName           "Load_game"
#define GP_ListFont             "Arial_12.hff"
#define GP_NameFont             "Arial_12.hff"
#define GP_NonSelectedColor     colRGB(0, 75, 120)
#define GP_SelectedTabbedColor  colRGB(1, 170, 221)
#define GP_SelectedColor        GP_SelectedTabbedColor
#define GP_ListMarginInterLine  1
#define GP_ListMarginX          2
#define GP_ListMarginY          2
#define GP_DisplayListLength    11      //number of games displayed on the screen at one time
#define GP_VertSpacing          (fontHeight(" ") >> 1)
#define GP_GAMENAME_LENGTH      32

/*=============================================================================
    Type definitions:
=============================================================================*/
typedef struct
{
    char    *title;
    char    *fileSpec;
}
gpgame;

/*=============================================================================
    Data:
=============================================================================*/
extern gpgame *gpGames;             //list of available games
extern sdword gpCurrentSelected;    //current game index, if OK is pressed
extern char   *gpTextEntryName;     //text box entry name

extern bool gpLoadSinglePlayerGame;
extern bool gpLoadTutorial;

extern char TutorialSavedGamesPath[];

/*=============================================================================
    Functions:
=============================================================================*/

//startup/shutdown
TI_API void gpStartup(void);
TI_API void gpShutdown(void);
TI_API void gpReset(void);

//run the game picker
TI_API void gpGamePick(char *dest);

//close the picker, either with 'back' or with 'OK'
TI_API void gpDonePicking(char *name, featom *atom);
TI_API void gpBackPicking(char *name, featom *atom);

TI_API bool gpQuickSave(void);
TI_API bool gpQuickLoad(void);

TI_API bool gpGetGameName(char *name, featom *atom, char *filename);

TI_API sdword gpCountTrainingSavegames(void);

#endif
