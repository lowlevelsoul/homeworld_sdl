
#ifndef ___LEVELLOAD_H
#define ___LEVELLOAD_H

#include "tiPlatform.h"
#include "ObjTypes.h"
#include "ShipDefs.h"
#include "Universe.h"

/*=============================================================================
    Functions:
=============================================================================*/

TI_API void levelPreInit(char *directory,char *pickedMission);
TI_API void levelInit(char *directory,char *pickedMission);

void levelStartNext(char *directory,char *pickedMission);        // for single player game only

// utility functions
TI_API ShipType GetAppropriateShipTypeForRace(ShipType request,ShipRace shiprace);
TI_API void TryToFindMothershipsForPlayers(void);
TI_API ShipRace GetSinglePlayerRaceEquivalent(ShipRace race);

TI_API bool_t AddResourceToSphere(ResourceVolume *sphere,bool_t regrowing);
TI_API bool_t AddResourceToCylinder(ResourceVolume *cylinder,bool_t regrowing);
TI_API bool_t AddResourceToRectangle(ResourceVolume *rectangle,bool_t regrowing);

TI_API void SetInfoNeededForShipAndRelatedStaticInfo(ShipType type,ShipRace race,bool8 dataToFillIn);

/*=============================================================================
    Global variables:
=============================================================================*/

extern udword nebAttributes;
extern sdword SongNumber;

#endif

