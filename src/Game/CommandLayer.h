// =============================================================================
//  CommandLayer.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 7/2/1997 by gshaw
// =============================================================================

#ifndef ___COMMANDLAYER_H
#define ___COMMANDLAYER_H

#include "tiPlatform.h"
#include "Dock.h"
#include "Formation.h"
#include "ResCollect.h"


#ifdef HW_BUILD_FOR_DEBUGGING

#define CL_TEXTFEEDBACK     1

#else

#define CL_TEXTFEEDBACK     0

#endif
/*=============================================================================
    Types:
=============================================================================*/

//Ru Transfer types for one person
#define RUTRANS_BUILDCANCEL     101
#define RUTRANS_BUILTSHIP       102
#define RUTRANS_GENERATEDRUS    103

//defines for hyperspaceing states
#define COM_HYPERSPACE_START    0
#define COM_HYPERSPACE_OUT      1
#define COM_HYPERSPACE_WAIT     2
#define COM_HYPERSPACE_IN       3

typedef struct
{
    vector heading;
    vector destination;
} MoveCommand;

typedef SelectAnyCommand AttackCommand;
typedef SelectAnyCommandMax6 AttackCommandMax6;
typedef SelectAnyCommand SpecialCommand;

#define PROTECTFLAGS_JUST_FOLLOW     1
typedef SelectCommand ProtectCommand;
typedef SelectCommandMax6 ProtectCommandMax6;

#define IAmAWingman(attackvar) ((attackvar)->myLeaderIs)
#define IAmALeader(attackvar) ((attackvar)->myWingmanIs)

typedef struct
{
    ShipPtr receiverShip;
} LaunchShipCommand;

typedef struct
{
    ShipType shipType;
    ShipRace shipRace;
    ShipPtr creator;
    udword frameAtWhichToCreate;
    udword playerIndex;
} BuildingShipCommand;

typedef struct
{
    uword order;
    uword attributes;
} CommandOrder;

typedef struct CommandToDo
{
    Node todonode;
    SelectCommand *selection;
    CommandOrder ordertype;
    MoveCommand move;
    AttackCommand *attack;
    FormationCommand formation;
    DockCommand dock;
    LaunchShipCommand launchship;
    CollectResourceCommand collect;
    ProtectCommand *protect;
    udword protectFlags;
    SpecialCommand *specialtargets;
    MilitaryParadeCommand *militaryParade;
    BuildingShipCommand buildingship;
    real32 tacticalupdatetime;                 //needed for optimal scanning of ship list in enemy detection for tactics
    real32 holdingStartTime;                //time that a command entered a holding pattern
    real32 hyperSpaceingTime;
    sdword hyperspaceState;
    sdword turnAroundTimes;
    vector holdingPatternVec;
    real32 pingUpdateTime;                  //last time this command was processed by pings
    void *updatedPing;                      //what ping it was last updated for
} CommandToDo;

typedef struct CommandLayer
{
    LinkedList todolist;
} CommandLayer;

/*=============================================================================
    Macros:
=============================================================================*/

#define sizeofAttackCommand sizeofSelectCommand
#define sizeofProtectCommand sizeofSelectCommand

// any variables you want to reset in CommandToDo upon initialization, put here
#define InitCommandToDo(command) memset(command,0,sizeof(CommandToDo))

/*=============================================================================
    Data:
=============================================================================*/
#if CL_TEXTFEEDBACK
extern bool_t enableTextFeedback;
#endif

/*=============================================================================
    Functions:
=============================================================================*/

// Initializing, Closing, Processing
TI_API void clInit(CommandLayer *comlayer);
TI_API void clClose(CommandLayer *comlayer);
TI_API void clReset(CommandLayer *comlayer);
TI_API void clProcess(CommandLayer *comlayer);
TI_API void clPostProcess(CommandLayer *comlayer);

TI_API void clChecksum(void);

// Ship Command Layer
TI_API void clMove(CommandLayer *comlayer,SelectCommand *selectcom,vector from,vector to);
TI_API CommandToDo *clAttackThese(CommandLayer *comlayer,SelectCommand *selectcom,AttackCommand *attackcom);
TI_API void clAttack(CommandLayer *comlayer,SelectCommand *selectcom,AttackCommand *attackcom);
TI_API void clPassiveAttack(CommandLayer *comlayer,SelectCommand *selectcom,AttackCommand *attackcom);
TI_API void clFormation(CommandLayer *comlayer,SelectCommand *selectcom,TypeOfFormation formation);
TI_API sdword clDock(CommandLayer *comlayer,SelectCommand *selectcom,DockType dockType,ShipPtr dockwith);
TI_API Ship *clCreateShip(CommandLayer *comlayer,ShipType shipType,ShipRace shipRace,uword playerIndex,ShipPtr creator);
TI_API void clBuildShip(CommandLayer *comlayer,ShipType shipType,ShipRace shipRace,uword playerIndex,ShipPtr creator);
TI_API void clCollectResource(CommandLayer *comlayer,SelectCommand *selectcom,ResourcePtr resource);
TI_API CommandToDo *clProtect(CommandLayer *comlayer,SelectCommand *selectcom,ProtectCommand *protectcom);
TI_API void clSpecial(CommandLayer *comlayer,SelectCommand *selectcom,SpecialCommand *targets);
TI_API void clHalt(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clHaltThese(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clScuttle(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clAutoLaunch(udword OnOff,udword playerIndex);
TI_API void clSetAlliance(udword AllianceType, uword curalliance, uword newalliance);
TI_API void clLaunchMultipleShips(CommandLayer *comlayer,SelectCommand *selectcom,ShipPtr launchFrom);
TI_API void clSetTactics(CommandLayer *comlayer,SelectCommand *selectcom,TacticsType tacticstype);
TI_API void clSetKamikaze(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clSetMilitaryParade(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clRUTransfer(CommandLayer *comlayer, sdword toIndex, sdword fromIndex, sdword resourceUnits,ubyte flags);
TI_API void clMpHyperspace(CommandLayer *comlayer,SelectCommand *selectcom,vector from,vector to);
TI_API void clSetResearch(udword type, udword playernum, udword labnum, udword tech);
TI_API void clDeterministicBuild(udword command, CommandLayer* comlayer, sdword numShips, ShipType shipType, ShipRace shipRace, uword playerIndex, ShipPtr creator);

// does ship have to launch
TI_API bool_t ShipHasToLaunch(Ship *InsideShip, Ship *ship);

// launch functions
TI_API void LaunchAllInternalShipsOfPlayerThatMustBeLaunched(struct Player *player);
TI_API sdword LaunchAllInternalShipsOfPlayer(struct Player *player, udword carriermask);

// checks if can ChangeOrderToPassiveAttack
TI_API bool_t canChangeOrderToPassiveAttack(CommandToDo *alreadycommand,AttackCommand *attack);

// changes order to passive attack
// WARNING: Must call canChangeOrderToPassiveAttack to see if you can call this
TI_API void ChangeOrderToPassiveAttack(CommandToDo *alreadycommand,AttackCommand *attackcom);

// changes order to attack
TI_API void ChangeOrderToAttack(CommandToDo *alreadycommand,AttackCommand *attackcom);

// changes order to move
TI_API void ChangeOrderToMove(CommandToDo *alreadycommand,vector from,vector to);

// Returns allocated command containing the ship
TI_API CommandToDo *getShipAndItsCommand(CommandLayer *comlayer,ShipPtr ship);
TI_API SelectCommand *getShipAndItsCommandSelection(CommandLayer *comlayer,ShipPtr ship,bool_t *parade);

// Returns allocated command containing the ship and its formation
TI_API CommandToDo *getShipAndItsFormationCommand(CommandLayer *comlayer,ShipPtr ship);

// Returns allocated selectcommand containing the ship and its formation
TI_API SelectCommand *getShipAndItsFormation(CommandLayer *comlayer,ShipPtr ship);

// returns TRUE if searchfor is in comlayer
TI_API bool_t CommandInCommandLayer(CommandLayer *comlayer,CommandToDo *searchfor);

// Call this function to see if this selection is already in formation
TI_API TypeOfFormation clSelectionAlreadyInFormation(CommandLayer *comlayer,SelectCommand *selectcom);

// Call this function to update ship command layer when ship dies
TI_API void clShipDied(CommandLayer *comlayer,ShipPtr deadship);

// Call this function to update ship command layer when resource dies
TI_API void clResourceDied(CommandLayer *comlayer,ResourcePtr resource);

// Call this function to update ship command layer when derelict dies
TI_API void clDerelictDied(CommandLayer *comlayer,DerelictPtr derelict);

// Call this function to update ship command layer when missile dies
TI_API void clMissileDied(CommandLayer *comlayer,MissilePtr missile);

// Tells if selectcom is already doing something in the command layer
TI_API CommandToDo *IsSelectionAlreadyDoingSomething(CommandLayer *comlayer,SelectCommand *selectcom);

// Removes ships in selectcom from doing stuff in the command layer
TI_API void RemoveShipsFromDoingStuff(CommandLayer *comlayer,SelectCommand *selectcom);

// values for removeFlag for RemoveShipFromBeingTargeted
#define REMOVE_PROTECT          1
#define REMOVE_CLOAKED          2
#define REMOVE_DISABLED         4
#define REMOVE_DISAPPEARED      8
#define REMOVE_HYPERSPACING     16

// Removes ship from being targeted in the command layer
TI_API void RemoveShipFromBeingTargeted(CommandLayer *comlayer,ShipPtr shiptoremove,udword removeFlag);

// cleans up game when a ship goes out of view..
TI_API void shipHasJustCloaked(Ship *ship);

// cleans up game when a ship becomes disabled
TI_API void shipHasJustBeenDisabled(Ship *ship);

// when ship just disappeared (SOF_Hide) e.g. univRemoveShipFromOutside
TI_API void shipHasJustDisappeared(Ship *ship);

// removes target info from command regarding shiptoremove
TI_API void RemoveShipReferencesFromExtraAttackInfo(Ship *shiptoremove,CommandToDo *todo);
TI_API void RemoveAttackTargetFromExtraAttackInfo(SpaceObjRotImpTarg *targettoremove,CommandToDo *todo);
TI_API void removeShipsFromDockingWithThisShip(Ship *ship);

TI_API void RemoveShipFromAttacking(Ship *ship);

// Initializes ship's AI state variables
TI_API void InitShipAI(Ship *ship,bool_t fresh);

// Initializes selection ships AI state variables
TI_API void InitShipsForAI(SelectCommand *selection,bool_t fresh);

// clears any protecting in command
TI_API void ClearProtecting(CommandToDo *command);

// clears any passive attack command
TI_API void ClearPassiveAttacking(CommandToDo *command);

// frees last order of command, so new order can be put in
TI_API void FreeLastOrder(CommandToDo *command);

// adds a ship to a formation group
TI_API void AddShipToFormationGroup(ShipPtr ship,CommandToDo *group);

// adds a ship to a command group
TI_API void AddShipToGroup(ShipPtr ship,CommandToDo *group);

// Adds a ship to the proper group around aroundShip
TI_API void GroupShip(CommandLayer *comlayer,ShipPtr ship,ShipPtr aroundShip);

// groups ship into military parade around aroundShip
TI_API void GroupShipIntoMilitaryParade(CommandLayer *comlayer,ShipPtr ship,ShipPtr aroundShip);

// sets ships to correct position according to command layer
TI_API void clPresetShipsToPosition(CommandLayer *comlayer);

// cleans up formation ship stuff
TI_API void RemoveShipFromFormation(Ship *ship);

TI_API void fixFlipTurnSelection(SelectCommand *selection,SelectCommand *global);

TI_API CommandToDo *GetMilitaryGroupAroundShip(CommandLayer *comlayer,Ship *aroundShip);

// call whenever creating a new command in command layer or ships changing their command
TI_API void PrepareShipsForCommand(CommandToDo *command,bool_t rowClear);
TI_API void PrepareOneShipForCommand(Ship *ship,CommandToDo *command,bool_t rowClear);

// call whenever removing command
TI_API void RemoveShipsFromCommand(CommandToDo *command);
// call whenever removing a ship from command (e.g. removing ship from command->selection)
TI_API void RemoveShipFromCommand(Ship *ship);

//returns cost of selSelected to hyperspace to distance
TI_API real32 hyperspaceCost(real32 distance,SelectCommand *selection);

TI_API void FillInCarrierMothershipInfo(struct Player *player,Ship **mothership,Ship *carrierX[]);

//cancels all current players launching ship(single player game only)
TI_API void clCancelAllLaunchOrdersFromPlayer(struct Player *player);

// tells ship to stay nearby protectThisShip - actual logic for attack if protectThisShip being attacked not in this routine
TI_API void protectShip(Ship *ship,Ship *protectThisShip,bool_t passiveAttacked);

/*=============================================================================
    Data:
=============================================================================*/

#endif
