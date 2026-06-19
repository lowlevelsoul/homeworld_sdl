/*=============================================================================
    Name    : Shipselect.h
    Purpose : Includes type definitions for selecting ships

    Created 10/11/1997 by gshaw
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___SHIPSELECT_H
#define ___SHIPSELECT_H

#include "tiPlatform.h"
#include "SpaceObj.h"

/*=============================================================================
    Defines:
=============================================================================*/

#define COMMAND_MAX_SHIPS 1000

/*=============================================================================
    Types:
=============================================================================*/

// select ships
typedef struct
{
    sdword numShips;
    real32 timeLastStatus;
    ShipPtr ShipPtr[1];
} SelectCommand;

typedef struct
{
    sdword numShips;
    real32 timeLastStatus;
    ShipPtr ShipPtr[6];
} SelectCommandMax6;

typedef struct
{
    sdword numShips;
    real32 timeLastStatus;
    ShipPtr ShipPtr[COMMAND_MAX_SHIPS];
} MaxSelection;

// select ships or targets
typedef struct
{
    sdword numTargets;
    real32 timeLastStatus;
    TargetPtr TargetPtr[1];
} SelectAnyCommand;

typedef struct
{
    sdword numTargets;
    real32 timeLastStatus;
    TargetPtr TargetPtr[6];
} SelectAnyCommandMax6;

typedef struct
{
    sdword numTargets;
    real32 timeLastStatus;
    TargetPtr TargetPtr[COMMAND_MAX_SHIPS];
} MaxAnySelection;

typedef struct
{
    sdword numResources;
    real32 timeLastStatus;
    ResourcePtr ResourcePtr[1];
} ResourceSelection;

typedef struct
{
    sdword numDerelicts;
    real32 timeLastStatus;
    DerelictPtr DerelictPtr[1];
} DerelictSelection;

typedef struct
{
    sdword numBullets;
    real32 timeLastStatus;
    BulletPtr BulletPtr[1];
} BulletSelection;

typedef struct
{
    sdword numMissiles;
    real32 timeLastStatus;
    MissilePtr MissilePtr[1];
} MissileSelection;

typedef struct
{
    sdword numSpaceObjs;
    real32 timeLastStatus;
    SpaceObjPtr SpaceObjPtr[1];
} SpaceObjSelection;

typedef struct
{
    sdword numShips;
    real32 timeLastStatus;
    ShipStaticInfo *ShipStaticPtr[1];
} SelectCommandStatic;

#define GROWSELECT_INITIALBATCH     16
#define GROWSELECT_ADDBATCH         8

typedef struct
{
    sdword maxNumShips;
    SelectCommand *selection;
} GrowSelection;

/*=============================================================================
    Macros:
=============================================================================*/

#define sizeofSelectCommand(n) (sizeof(SelectCommand) + sizeof(ShipPtr)*((n)-1))

/*=============================================================================
    Functions:
=============================================================================*/

// Adds a ship to a growable selection of ships.
TI_API void growSelectAddShip(GrowSelection *growSelect,Ship *ship);

// Returns TRUE if obj was removed
TI_API bool_t growSelectRemoveShip(GrowSelection *growSelect,Ship *ship);

// Removes ship at index index from growSelect
TI_API void growSelectRemoveShipIndex(GrowSelection *growSelect,sdword index);

// Initializes a growable selection of ships
TI_API void growSelectInit(GrowSelection *growSelect);

// Closes a growable selection of ships
TI_API void growSelectClose(GrowSelection *growSelect);

// Resets a growable selection (sets numShips to 0)
TI_API void growSelectReset(GrowSelection *growSelect);

// Add a ship to a growable selection without duplicating an existing ship pointer
TI_API void growSelectAddShipNoDuplication(GrowSelection *growSelect, Ship *ship);

// Adds a SpaceObj to selection before index
TI_API void AddSpaceObjToSelectionBeforeIndex(SpaceObj *obj,SpaceObjSelection *selection,sdword index);

// Adds a SpaceObj to selection after index
TI_API void AddSpaceObjToSelectionAfterIndex(SpaceObj *obj,SpaceObjSelection *selection,sdword index);

// Returns TRUE if obj was removed
TI_API bool_t RemoveSpaceObjFromSelectionPreserveOrder(SpaceObjSelection *selection,SpaceObj *obj);

// Returns TRUE if ship is in selection
TI_API bool_t ShipInSelection(SelectCommand *selection,Ship *ship);

// Returns number if ShipType "type"  in selection
TI_API udword ShiptypeInSelection(SelectCommand *selection, ShipType type);

// Returns the first instance of the specified type in the selection
TI_API ShipPtr FindFirstInstanceOfShipType(SelectCommand *selection, ShipType type);

// Does not delete entry - just removes reference to it.
// Returns TRUE if any ship was removed
TI_API bool_t clRemoveTargetFromSelection(SelectAnyCommand *selection,TargetPtr removeTargetPtr);

#define clRemoveShipFromSelection(sel,ship) clRemoveTargetFromSelection((SelectAnyCommand *)(sel),(TargetPtr)ship)

// returns true if any ships in theseShips are in selection
TI_API bool_t AnyOfTheseShipsAreInSelection(SelectCommand *theseShips,SelectCommand *selection);

// returns true if all of these ships are in selection
TI_API bool_t TheseShipsAreInSelection(SelectCommand *theseShips,SelectCommand *selection);

// returns true if selections 1 and 2 are equivalent (ignores order)
TI_API bool_t SelectionsAreEquivalent(SelectCommand *selection1,SelectCommand *selection2);

// returns true if selections 1 and 2 are equivalent (including order)
TI_API bool_t SelectionsAreTotallyEquivalent(SelectCommand *selection1,SelectCommand *selection2);

// Makes sure that ships in selection do not include theseships
TI_API void MakeShipsNotIncludeTheseShips(SelectCommand *selection,SelectCommand *theseships);

// Makes sure that the targets in selection are not missiles.
TI_API void MakeTargetsNotIncludeMissiles(SelectAnyCommand *selection);

// Returns true if ship can harvest
TI_API bool_t ShipCanHarvest(ShipStaticInfo *shipstatic);

// Makes targets all be within range of comparewith, but don't include comparewith
TI_API void MakeTargetsOnlyBeWithinRangeAndNotIncludeMe(SelectAnyCommand *selection,SpaceObjRotImpTarg *comparewith,real32 range);

// Makes sure that targets in selection are ships and enemies
TI_API void MakeTargetsOnlyEnemyShips(SelectAnyCommand *selection,struct Player *curplayer);

// Same as MakeTargetsOnlyEnemyShips except includes stuff like hyperspace gates
TI_API void MakeTargetsOnlyNonForceAttackTargets(SelectAnyCommand *selection,struct Player *curplayer);

// Makes targets only be salvageable ships/derelicts
TI_API void MakeTargetsSalvageable(SelectAnyCommand *selection,struct Player *curplayer);

typedef bool_t (*ShipConstraintsCB)(Ship *ship);
// Makes sure that all ships in selection follow shipConstraintsCB
TI_API void MakeShipsOnlyFollowConstraints(SelectCommand *selection,ShipConstraintsCB shipConstraintsCB);
// Returns TRUE if any ships in selection follow shipConstraintsCB
TI_API bool_t DoAnyShipsFollowConstraints(SelectCommand *selection,ShipConstraintsCB shipConstraintsCB);
// Returns TRUE if all ships in selection follow shipConstraintsCB
TI_API bool_t DoAllShipsFollowConstraints(SelectCommand *selection,ShipConstraintsCB shipConstraintsCB);

// Makes sure that ships in selection are friendly ships (are curplayer's ships)
TI_API void MakeShipsFriendlyShips(SelectCommand *selection,struct Player *curplayer);

// Makes sure that ships in the selection are friendly, i.e. allies and curplayer's ships
TI_API void MakeShipsFriendlyAndAlliesShips(SelectCommand *selection,struct Player *curplayer);

// Makes sure that ships are harvest capable
TI_API sdword MakeShipsHarvestCapable(SelectCommand *dest, SelectCommand *source);

// Makes sure that ships are attack capable
TI_API sdword MakeShipsAttackCapable(SelectCommand *dest, SelectCommand *source);
TI_API //void MakeShipsAttackCapable(SelectCommand *selection);

// Returns TRUE if all ships are attack capable
TI_API bool_t AreAllShipsAttackCapable(SelectCommand *selection);

// returns TRUE if any ships are attack capable
TI_API bool_t AreAnyShipsAttackCapable(SelectCommand *selection);

// Returns TRUE if ship is attack capable
TI_API bool_t isShipAttackCapable(Ship *ship);

// Returns TRUE if all ships are attack capable
TI_API bool_t AreAllShipsPassiveAttackCapable(SelectCommand *selection);

// returns TRUE if any ships are attack capable
TI_API bool_t AreAnyShipsPassiveAttackCapable(SelectCommand *selection);

// Returns TRUE if ship is attack capable
TI_API bool_t isShipPassiveAttackCapable(Ship *ship);

// Makes sure that ships are guard capable
TI_API void MakeShipsGuardCapable(SelectCommand *selection);

// Makes sure the ships have a special activate function
TI_API void MakeShipsSpecialActivateCapable(SelectCommand *selection);

// Makes sure the ships have special targeting capability
TI_API void MakeShipsSpecialTargetCapable(SelectCommand *selection, bool_t bFriendlies);

// Makes sure that ships are mobile
TI_API void MakeShipsMobile(SelectCommand *selection);
TI_API bool_t AreShipsMobile(SelectCommand *selection);

// Makes sure ships aren't capital ships
TI_API void MakeShipsNonCapital(SelectCommand *selection);

// Makes sure ships are only capital ships
TI_API void MakeShipsOnlyCapital(SelectCommand *selection);

// Makes sure selection don't have cloaked enemy ships
TI_API void MakeSelectionNotHaveCloakedEnemyShips(SelectCommand *selection, struct Player *curplayer);

// Makes sure selection doesn't have non-visible cloaked enemy ships
// Note: takes into account proximity sensors detecting cloaked ships
TI_API void MakeSelectionNotHaveNonVisibleEnemyShips(SelectCommand *selection, struct Player *curplayer);

// Adds slaves to a selection list if the master is in it
TI_API void MakeShipMastersIncludeSlaves(SelectCommand *selection);

// Removes Research Ships from Selection
TI_API void MakeSelectionNonResearchShips(SelectCommand *selection);

// removes ships that can't dock from the selection
TI_API void makeShipsDockCapable(SelectCommand *selection);
TI_API void makeShipsRetireable(SelectCommand *selection);

// rmakes list contain no docking ships <ships in docking cones>
TI_API void makeShipsControllable(SelectCommand *selection,sdword newCommand);

// makes list contains ships that can gointo formation..probe is removed
TI_API void makeShipsFormationCapable(SelectCommand *selection);

// removes the player's mothership from selection
TI_API void makeShipsNotIncludeSinglePlayerMotherships(SelectCommand *selection);

//Removes non Kamikazeable ships
TI_API bool_t MakeSelectionKamikazeCapable(SelectCommand *selection);

//remove any ships not allowed to hyperspace
TI_API void makeSelectionHyperspaceCapable(SelectCommand *selection);

//removes certain ships from an attack selection so that guarding ships
//isn't wacky
TI_API void makeShipsNotHaveNonCombatShipsForGuardAttack(SelectCommand *selection);

// convert a LinkedList of ships into the equivalent SelectCommand
TI_API SelectCommand * shipLinkedListAsSelectCommand(LinkedList *list, char *label);

// Selects all of the current player's non-hyperspacing ships
TI_API SelectCommand *selectAllCurrentPlayersNonHyperspacingShips(void);

// Selects all of the current player's hyperspacing ships
TI_API SelectCommand *selectAllCurrentPlayersHyperspacingShips(void);

// Selects all of a player's ships
TI_API SelectCommand *selectAllPlayersShips(struct Player *player);

// returns a new selection consisting of the ships in both selection 1 and selection 2
// Note: the new selection created with a memAlloc and therefore must be freed later
TI_API SelectCommand *selectSelectionIntersection(SelectCommand *selection1, SelectCommand *selection2);

//select all ships with the canSingleClickSpecialActivate flag set
TI_API sdword MakeShipsSingleClickSpecialCapable(SelectCommand *dest, SelectCommand *source);

//select all visible ships
TI_API sdword MakeShipsNotHidden(SelectCommand *dest, SelectCommand *source);

TI_API sdword MothershipOrCarrierIndexInSelection(SelectCommand *selection);

// Merge two selections
#define NO_DEALLOC      0   //no selections are deallocated
#define DEALLOC1        1   //the first selection is deallocated
#define DEALLOC2        2   //the second selection is deallocated
#define DEALLOC_BOTH    3   //both selections are deallocated
TI_API SelectCommand *selectMergeTwoSelections(SelectCommand *selection1, SelectCommand *selection2, udword dealloc);

// Duplicate a selection
TI_API SelectCommand *selectMemDupSelection(SelectCommand *selection, char *str, udword memflag);
#define selectDupSelection(sel)     selectMemDupSelection(sel, "selDup", 0)

#define ShipCanHyperspace(ship) (isCapitalShip(ship) && (ship->shiptype != CryoTray) && (ship->shiptype != Probe))

#endif

