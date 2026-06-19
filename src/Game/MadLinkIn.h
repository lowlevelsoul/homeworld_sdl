/*=============================================================================
    Name    : madLinkIn.h
    Purpose : defines and prototypes for madlinkin.c

    Created 31/08/1998 by bryce pasechnik
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___MADLINKIN_H
#define ___MADLINKIN_H

#include "tiPlatform.h"
#include "CommandLayer.h"
#include "SpaceObj.h"

//general prototypes
TI_API void madLinkInUpdateMeshAnimations(Ship *ship);
TI_API void madLinkInSetUpInitialBuiltMadState(Ship *ship);
TI_API void madLinkInSetUpInitialPlacedMadState(Ship *ship);

//gun opening closing
TI_API void madLinkInOpenGuns(CommandToDo *command,udword priority);
TI_API void madLinkInCloseGuns(CommandToDo *command,udword priority);
TI_API void madOpenGunsShip(Ship *ship);
TI_API void madLinkInCloseGunsShip(Ship *ship);

//docking oriented (fins opening closing)
TI_API void madLinkInPreDocking(CommandToDo *command,udword priority);
TI_API void madLinkInPreDockingShip(Ship *ship);
TI_API void madLinkInPostDocking(CommandToDo *command,udword priority);
TI_API void madLinkInPostDockingShip(Ship *ship);
TI_API void madLinkInOpenSpecialShip(Ship *ship);
TI_API void madLinkInCloseSpecialShip(Ship *ship);

TI_API void madLinkInOpenDoor(Ship *ship);
TI_API void madLinkInCloseDoor(Ship *ship);
TI_API bool_t madLinkInGetDoorInfo(Ship *ship, matrix *coordsys, vector *position);

#endif

