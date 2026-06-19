// =============================================================================
//  CommandWrap.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 7/30/1997 by gshaw
// =============================================================================

#ifndef ___COMMANDWRAP_H
#define ___COMMANDWRAP_H

#include "tiPlatform.h"
#include "CommandLayer.h"
#include "Globals.h"

TI_API void clCommandMessage(char CommandMessage[MAX_MESSAGE_LENGTH]);

TI_API void clWrapMove(CommandLayer *comlayer,SelectCommand *selectcom,vector from,vector to);
TI_API void clWrapAttack(CommandLayer *comlayer,SelectCommand *selectcom,AttackCommand *attackcom);
TI_API void clWrapFormation(CommandLayer *comlayer,SelectCommand *selectcom,TypeOfFormation formation);
TI_API void clWrapDock(CommandLayer *comlayer,SelectCommand *selectcom,DockType dockType,ShipPtr dockwith);
TI_API void clWrapCreateShip(CommandLayer *comlayer,ShipType shipType,ShipRace shipRace,uword playerIndex,ShipPtr creator);
TI_API void clWrapBuildShip(CommandLayer *comlayer,ShipType shipType,ShipRace shipRace,uword playerIndex,ShipPtr creator);

void clWrapDeterministicBuild(udword command,
                              CommandLayer* comlayer, sdword numShips,
                              ShipType shipType, ShipRace shipRace,
                              uword playerIndex, ShipPtr creator);

TI_API void clWrapCollectResource(CommandLayer *comlayer,SelectCommand *selectcom,ResourcePtr resource);
TI_API void clWrapProtect(CommandLayer *comlayer,SelectCommand *selectcom,ProtectCommand *protectcom);
TI_API void clWrapSpecial(CommandLayer *comlayer,SelectCommand *selectcom,SpecialCommand *targets);
TI_API void clWrapHalt(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clWrapScuttle(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clWrapAutoLaunch(udword OnOff,udword playerIndex);
TI_API void clWrapSetAlliance(udword AllianceType, uword curalliance, uword newalliance);
TI_API void clWrapLaunchMultipleShips(CommandLayer *comlayer,SelectCommand *selectcom,ShipPtr launchFrom);
TI_API void clWrapSetTactics(CommandLayer *comlayer,SelectCommand *selectcom,TacticsType tacticstype);
TI_API void clWrapSetKamikaze(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clWrapSetMilitaryParade(CommandLayer *comlayer,SelectCommand *selectcom);
TI_API void clWrapRUTransfer(CommandLayer *comlayer,sdword fromIndex,sdword toIndex, sdword resourceUnits,ubyte flags);
TI_API void clWrapMpHyperspace(CommandLayer *comlayer,SelectCommand *selectcom,vector from,vector to);
TI_API void clWrapResearch(udword type, udword playernum, udword labnum, udword tech);
#endif
