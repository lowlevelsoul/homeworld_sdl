/*=============================================================================
    Name    : TradeMgr.h
    Purpose : Definitions for the trade manager.

    Created 10/07/1997 by yo
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___TRADEMGR_H
#define ___TRADEMGR_H

#include "tiPlatform.h"
#include "FEFlow.h"
#include "Region.h"
#include "SpaceObj.h"
#include "Types.h"

/*=============================================================================
    Switches:
=============================================================================*/
#define TM_NUM_TECHS 50


//for tmTechForSale[]
#define TM_TECH_IS_NOT_FOR_SALE         0
#define TM_TECH_IS_FOR_SALE             1
#define TM_TECH_IS_ALREADY_OWNED        2

//for tmTechResearchable[]
#define TM_TECH_IS_NOT_RESEARCHABLE     0
#define TM_TECH_IS_RESEARCHABLE         1



/*=============================================================================
    Type definitions:
=============================================================================*/

typedef sword TechType;


//ships available

typedef enum {
    DialogWelcome=0,
    DialogFirstClick,
    DialogCantAffordThat,
    DialogCantAffordAnything,
    DialogPurchaseMade,
    DialogNothingForSale,   //maybe implemented
} TradeDialogType;


/*=============================================================================
    Data:
=============================================================================*/


extern udword tmTechForSale[TM_NUM_TECHS];
extern bool tmCheaptechs;
extern sword tmTechResearchable[TM_NUM_TECHS];



/*=============================================================================
    Functions:
=============================================================================*/
TI_API void tmStartup(void);
TI_API void tmShutdown(void);

TI_API void tmTechInit(void);
TI_API void tmReset(void);
TI_API void tmClearTechs(void);


TI_API sdword tmTradeBegin(regionhandle region, sdword ID, udword event, udword data);
TI_API void tmLeave(char *string, featom *atom);

TI_API void tmCostListDraw(featom *atom, regionhandle region);
TI_API void tmDialogDraw(featom *atom, regionhandle region);
TI_API void tmTechInfoDraw(featom *atom, regionhandle region);




TI_API void AllowPlayerToResearch(char *techname);
TI_API void AllowPlayerToPurchase(char *techname);
TI_API void PlayerAcquiredTechnology(char *techname);
TI_API sdword CanPlayerResearch(char *techname);
TI_API sdword CanPlayerPurchase(char *techname);
TI_API sdword DoesPlayerHave(char *techname);
TI_API sdword GetBaseTechnologyCost(char *techname);
TI_API void SetBaseTechnologyCost(char *techname, sdword cost);



TI_API void tmEnableTraderGUI(void);
TI_API bool tmTraderGUIActive(void);
TI_API void tmSetDialog(sdword phrasenum, char *sentence);
TI_API void tmSetPriceScale(udword percent);
TI_API uword tmGetPriceScale(void);
TI_API void tmSetTradeDisabled(bool trade);

// Save Game stuff
TI_API void tmSave(void);
TI_API void tmLoad(void);





#define WK_MAX_SHIPS 100




typedef struct
{

    Ship           *ship;
    real32          x;
    real32          y;
    real32          vx;
    real32          vy;
    real32          ang;
    real32          vang;
    real32          vangacc;
    real32          vangmax;
    real32          acc;
    real32          maxvel;
    real32          revacc;
    real32          strafeacc;
    sword           controlthrust;
    sword           controlrot;
    sword           controlstrafe;
    sword           controlfire;
}
wkTradeType;

extern wkTradeType wkTradeShips[WK_MAX_SHIPS];
extern bool wkTradeStuffActive;
TI_API void mrTradeStuffTest(sdword *a, sdword *b);
TI_API void wkTradeUpdate(void);


#endif
