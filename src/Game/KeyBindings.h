/*=============================================================================
    Name    : KeyBindings.h
    Purpose : This file contains all of the defines and headers for the Key
              bindings system.

    Created 8/04/1999 by Drew Dunlop
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___KEYBINDINGS_H
#define ___KEYBINDINGS_H

#include "tiPlatform.h"
#include "FEFlow.h"
#include "font.h"

/*=============================================================================
    Defines :
=============================================================================*/


/*=============================================================================
    Structure Prototypes :
=============================================================================*/

typedef enum
{
    kbNEXT_FORMATION=0,
    kbBUILD_MANAGER,
    kbPREVIOUS_FOCUS,
    kbNEXT_FOCUS,
    kbDOCK,
    kbSELECT_ALL_VISIBLE,
    kbFOCUS,
    kbRESEARCH_MANAGER,
    kbHARVEST,
    kbMOVE,
    kbNEXT_TACTIC,
    kbPREVIOUS_TACTIC,
    kbSCUTTLE,
    kbSHIP_SPECIAL,
    kbTACTICAL_OVERLAY,
//    kbSENSORS_MANAGER,
    kbMOTHERSHIP,
    kbKAMIKAZE,
    kbCANCEL_ORDERS,
    kbLAUNCH_MANAGER,
    kbTOTAL_COMMANDS
} CommandsToBind;

#define KB_NormalBound      0
#define KB_NotBound         1
#define KB_GetKeyPress      2

typedef struct kbBoundKeys
{
    udword      command;
    udword      defaultkey;
    udword      primarykey;
    udword      resettokey;
    udword      status;
} kbBoundKeys;


/*=============================================================================
    External Variables :
=============================================================================*/

extern fonthandle kbKeyListFont;

extern udword kbKeySavedKeys[20];

/*=============================================================================
    Function Prototypes :
=============================================================================*/

TI_API void kbListWindowCB(char *string, featom *atom);
TI_API void kbKeyResetToDefault(char *string, featom *atom);

TI_API void kbPoolListWindowCB(char *string, featom *atom);

TI_API sdword kbCheckBindings(sdword keypressed);

TI_API void kbRestoreSavedSettings(void);
TI_API void kbSaveSettings(void);

TI_API udword kbKeyBoundToCommand(udword command);
TI_API bool kbCommandKeyIsHit(udword command);

TI_API void kbInitKeyBindings(void);

#endif
