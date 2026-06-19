// =============================================================================
//  AIMoves.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
// =============================================================================

#ifndef ___AIMOVES_H
#define ___AIMOVES_H

#include "tiPlatform.h"
#include "AITeam.h"

struct AITeam;
struct AITeamMove;
struct Path;
struct AlternativeShips;

/*=============================================================================
    Move Definitions:
=============================================================================*/
//moveto types
#define TIME_LIMITED        0
#define DISTANCE_LIMITED    1

/*=============================================================================
    Utility Functions:
=============================================================================*/
TI_API void aimInsertMove(struct AITeam *team, struct AITeamMove *move);

/*=============================================================================
    Move Process Functions:
=============================================================================*/
TI_API sdword aimProcessVarSet(struct AITeam *team);
TI_API sdword aimProcessVarInc(struct AITeam *team);
TI_API sdword aimProcessVarDec(struct AITeam *team);
TI_API sdword aimProcessVarWait(struct AITeam *team);
TI_API sdword aimProcessVarDestroy(struct AITeam *team);
TI_API sdword aimProcessGuardShips(struct AITeam *team);
TI_API sdword aimProcessFormation(struct AITeam *team);
TI_API sdword aimProcessGetShips(struct AITeam *team);
TI_API sdword aimProcessMoveDone(struct AITeam *team);
TI_API sdword aimProcessSpecial(struct AITeam *team);
TI_API sdword aimProcessAttack(struct AITeam *team);
TI_API sdword aimProcessAdvancedAttack(struct AITeam *team);
TI_API sdword aimProcessMoveAttack(struct AITeam *team);
TI_API sdword aimProcessIntercept(struct AITeam *team);
TI_API sdword aimProcessMoveTo(struct AITeam *team);
TI_API sdword aimProcessMoveSplit(struct AITeam *team);
TI_API sdword aimProcessCountShips(struct AITeam *team);
TI_API sdword aimProcessHarassAttack(struct AITeam *team);
TI_API sdword aimProcessFancyGetShips(struct AITeam *team);
TI_API sdword aimProcessGuardCooperatingTeam(struct AITeam *team);
TI_API sdword aimProcessDefendMothership(struct AITeam *team);
TI_API sdword aimProcessPatrolMove(struct AITeam *team);
TI_API sdword aimProcessActivePatrol(struct AITeam *team);
TI_API sdword aimProcessTempGuard(struct AITeam *team);
TI_API sdword aimProcessSupport(struct AITeam *team);
TI_API sdword aimProcessSwarmAttack(struct AITeam *team);
TI_API sdword aimProcessLaunch(struct AITeam *team);
TI_API sdword aimProcessResourceVolume(struct AITeam *team);
TI_API sdword aimProcessCapture(struct AITeam *team);
TI_API sdword aimProcessActiveCapture(struct AITeam *team);
TI_API sdword aimProcessActiveMine(struct AITeam *team);
TI_API sdword aimProcessMineVolume(struct AITeam *team);
TI_API sdword aimProcessSpecialDefense(struct AITeam *team);
TI_API sdword aimProcessKamikaze(struct AITeam *team);

/*=============================================================================
    Move Creation Functions:
=============================================================================*/
struct AITeamMove *aimCreateVarSet(struct AITeam *team, char *varName, sdword value, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateVarInc(struct AITeam *team, char *varName, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateVarDec(struct AITeam *team, char *varName, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateVarWait(struct AITeam *team, char *varName, sdword value, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateVarDestroy(struct AITeam *team, char *varName, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateGuardShips(struct AITeam *team, SelectCommand *ships, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateFormation(struct AITeam *team, TypeOfFormation formationtype, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateGetShips(struct AITeam *team, ShipType shiptype, sbyte num_ships, sdword priority, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveDone(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSpecial(struct AITeam *team, SelectCommand *targets, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateAttack(struct AITeam *team, SelectCommand *targets, TypeOfFormation formation, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateAdvancedAttack(struct AITeam *team, SelectCommand *targets, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateFlankAttack(struct AITeam *team, SelectCommand *targets, bool8 hyperspace, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveAttack(struct AITeam *team, SelectCommand *targets, bool Advanced, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveTeam(struct AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveTeamIndex(struct AITeam *team, vector destination, udword index, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveTeamSplit(struct AITeam *team, SelectCommand *ships, struct Path *destinations, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateHyperspace(struct AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateIntercept(struct AITeam *team, ShipPtr ship, real32 interval, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveTo(struct AITeam *team, vector destination, real32 limiter, udword type, TypeOfFormation formation, TacticsType tactics, bool wait, bool remove);
struct AITeamMove *aimCreateCountShips(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateHarassAttack(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateFancyGetShips(struct AITeam *team, ShipType shiptype, sbyte num_ships, struct AlternativeShips *alternatives, sdword priority, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateDock(struct AITeam *team, sdword dockmoveFlags, ShipPtr dockAt, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateLaunch(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateGuardCooperatingTeam(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateDefendMothership(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreatePatrolMove(struct AITeam *team, struct Path *path, udword startIndex, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActivePatrol(struct AITeam *team, udword patroltype, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateTempGuard(struct AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateReinforce(struct AITeam *team, struct AITeam *reinforceteam, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSupport(struct AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveRecon(struct AITeam *team, bool EnemyRecon, TypeOfFormation formation,TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateShipRecon(struct AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateArmada(struct AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateControlResources(struct AITeam *team, SelectCommand *ships, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSwarmAttack(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSwarmDefense(struct AITeam *team, SelectCommand *pods, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSwarmPod(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateResourceVolume(struct AITeam *team, Volume volume, bool8 strictVolume, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveResource(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMothershipMove(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateCapture(struct AITeam *team, ShipPtr ship, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveCapture(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveMine(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMineVolume(struct AITeam *team, Volume volume, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSpecialDefense(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateDeleteTeam(struct AITeam *team);
struct AITeamMove *aimCreateKamikaze(struct AITeam *team, SelectCommand *targets,TypeOfFormation formation, bool8 wait, bool8 remove);

/*=============================================================================
    Move Creation Without Linked List Add:
=============================================================================*/
struct AITeamMove *aimCreateFormationNoAdd(struct AITeam *team, TypeOfFormation formationtype, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateFancyGetShipsNoAdd(struct AITeam *team, ShipType shiptype, sbyte num_ships, struct AlternativeShips *alternatives, sdword priority, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSpecialNoAdd(struct AITeam *team, SelectCommand *targets, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateAttackNoAdd(struct AITeam *team, SelectCommand *targets, TypeOfFormation formation, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateAdvancedAttackNoAdd(struct AITeam *team, SelectCommand *target, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateFlankAttackNoAdd(struct AITeam *team, SelectCommand *targets, bool8 hyperspace, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveAttackNoAdd(struct AITeam *team, SelectCommand *targets, bool Advanced, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveTeamNoAdd(struct AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveTeamIndexNoAdd(struct AITeam *team, vector destination, udword index, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveTeamSplitNoAdd(struct AITeam *team, SelectCommand *ships, struct Path *destinations, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateHyperspaceNoAdd(struct AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateInterceptNoAdd(struct AITeam *team, ShipPtr ship, real32 interval, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMoveToNoAdd(struct AITeam *team, vector destination, real32 limiter, udword type, TypeOfFormation formation, TacticsType tactics, bool wait, bool remove);
struct AITeamMove *aimCreateCountShipsNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateDockNoAdd(struct AITeam *team, sdword dockmoveFlags, ShipPtr dockAt, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateLaunchNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateGuardCooperatingTeamNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateDefendMothershipNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreatePatrolMoveNoAdd(struct AITeam *team, struct Path *path, udword startIndex, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActivePatrolNoAdd(struct AITeam *team, udword patroltype, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateGetShipsNoAdd(struct AITeam *team, ShipType shiptype, sbyte num_ships, sdword priority, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateTempGuardNoAdd(struct AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateReinforceNoAdd(struct AITeam *team, struct AITeam *reinforceteam, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSupportNoAdd(struct AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveReconNoAdd(struct AITeam *team, bool EnemyRecon, TypeOfFormation formation,TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateShipReconNoAdd(struct AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateArmadaNoAdd(struct AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateControlResourcesNoAdd(struct AITeam *team, SelectCommand *ships, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSwarmAttackNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSwarmDefenseNoAdd(struct AITeam *team, SelectCommand *pods, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateResourceVolumeNoAdd(struct AITeam *team, Volume volume, bool8 strictVolume, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveResourceNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMothershipMove(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateCaptureNoAdd(struct AITeam *team, ShipPtr ship, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveCaptureNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateActiveMineNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateMineVolumeNoAdd(struct AITeam *team, Volume vol, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateSpecialDefenseNoAdd(struct AITeam *team, bool8 wait, bool8 remove);
struct AITeamMove *aimCreateDeleteTeamNoAdd(struct AITeam *team);
struct AITeamMove *aimCreateKamikazeNoAdd(struct AITeam *team, SelectCommand *targets,TypeOfFormation formation, bool8 wait, bool8 remove);

/*=============================================================================
    Save Move Functions
=============================================================================*/

TI_API void aimFix_MoveDone(struct AITeamMove *move);
TI_API void aimFix_GuardShips(struct AITeamMove *move);
TI_API void aimFix_DefMoship(struct AITeamMove *move);
TI_API void aimFix_TempGuard(struct AITeamMove *move);
TI_API void aimFix_GetShips(struct AITeamMove *move);
TI_API void aimFix_Formation(struct AITeamMove *move);
TI_API void aimFix_MoveTeam(struct AITeamMove *move);
TI_API void aimFix_MoveTeamIndex(struct AITeamMove *move);
TI_API void aimFix_MoveTeamSplit(struct AITeamMove *move);
TI_API void aimFix_Hyperspace(struct AITeamMove *move);
TI_API void aimFix_Intercept(struct AITeamMove *move);
TI_API void aimFix_MoveTo(struct AITeamMove *move);
TI_API void aimFix_PatrolMove(struct AITeamMove *move);
TI_API void aimFix_ActivePatrol(struct AITeamMove *move);
TI_API void aimFix_ActiveRecon(struct AITeamMove *move);
TI_API void aimFix_ShipRecon(struct AITeamMove *move);
TI_API void aimFix_CountShips(struct AITeamMove *move);
TI_API void aimFix_Special(struct AITeamMove *move);
TI_API void aimFix_Attack(struct AITeamMove *move);
TI_API void aimFix_AdvancedAttack(struct AITeamMove *move);
TI_API void aimFix_FlankAttack(struct AITeamMove *move);
TI_API void aimFix_MoveAttack(struct AITeamMove *move);
TI_API void aimFix_HarassAttack(struct AITeamMove *move);
TI_API void aimFix_FancyGetShips(struct AITeamMove *move);
TI_API void aimFix_Dock(struct AITeamMove *move);
TI_API void aimFix_Launch(struct AITeamMove *move);
TI_API void aimFix_Reinforce(struct AITeamMove *move);
TI_API void aimFix_VarSet(struct AITeamMove *move);
TI_API void aimFix_VarInc(struct AITeamMove *move);
TI_API void aimFix_VarDec(struct AITeamMove *move);
TI_API void aimFix_VarWait(struct AITeamMove *move);
TI_API void aimFix_VarDestroy(struct AITeamMove *move);
TI_API void aimFix_GuardCoopTeam(struct AITeamMove *move);
TI_API void aimFix_Support(struct AITeamMove *move);
TI_API void aimFix_Armada(struct AITeamMove *move);
TI_API void aimFix_ControlResources(struct AITeamMove *move);
TI_API void aimFix_SwarmAttack(struct AITeamMove *move);
TI_API void aimFix_SwarmDefense(struct AITeamMove *move);
TI_API void aimFix_SwarmPod(struct AITeamMove *move);
TI_API void aimFix_ResourceVolume(struct AITeamMove *move);
TI_API void aimFix_DeleteTeam(struct AITeamMove *move);
TI_API void aimFix_Capture(struct AITeamMove *move);
TI_API void aimFix_ActiveCapture(struct AITeamMove *move);
TI_API void aimFix_ActiveMine(struct AITeamMove *move);
TI_API void aimFix_MineVolume(struct AITeamMove *move);
TI_API void aimFix_SpecialDefense(struct AITeamMove *move);
TI_API void aimFix_ActiveResource(struct AITeamMove *move);
TI_API void aimFix_MothershipMove(struct AITeamMove *move);
TI_API void aimFix_Kamikaze(struct AITeamMove *move);

TI_API void aimLoad_GuardShips(struct AITeamMove *move);
TI_API void aimLoad_DefMoship(struct AITeamMove *move);
TI_API void aimLoad_PatrolMove(struct AITeamMove *move);
TI_API void aimLoad_MoveTeamSplit(struct AITeamMove *move);
TI_API void aimLoad_Special(struct AITeamMove *move);
TI_API void aimLoad_Attack(struct AITeamMove *move);
TI_API void aimLoad_AdvancedAttack(struct AITeamMove *move);
TI_API void aimLoad_FlankAttack(struct AITeamMove *move);
TI_API void aimLoad_MoveAttack(struct AITeamMove *move);
TI_API void aimLoad_Dock(struct AITeamMove *move);
TI_API void aimLoad_Support(struct AITeamMove *move);
TI_API void aimLoad_ShipRecon(struct AITeamMove *move);
TI_API void aimLoad_ControlResources(struct AITeamMove *move);
TI_API void aimLoad_SwarmAttack(struct AITeamMove *move);
TI_API void aimLoad_SwarmDefense(struct AITeamMove *move);
TI_API void aimLoad_ResourceVolume(struct AITeamMove *move);
TI_API void aimLoad_Kamikaze(struct AITeamMove *move);

TI_API void aimSave_GuardShips(struct AITeamMove *move);
TI_API void aimSave_DefMoship(struct AITeamMove *move);
TI_API void aimSave_PatrolMove(struct AITeamMove *move);
TI_API void aimSave_MoveTeamSplit(struct AITeamMove *move);
TI_API void aimSave_Special(struct AITeamMove *move);
TI_API void aimSave_Attack(struct AITeamMove *move);
TI_API void aimSave_AdvancedAttack(struct AITeamMove *move);
TI_API void aimSave_FlankAttack(struct AITeamMove *move);
TI_API void aimSave_MoveAttack(struct AITeamMove *move);
TI_API void aimSave_Dock(struct AITeamMove *move);
TI_API void aimSave_Support(struct AITeamMove *move);
TI_API void aimSave_ShipRecon(struct AITeamMove *move);
TI_API void aimSave_ControlResources(struct AITeamMove *move);
TI_API void aimSave_SwarmAttack(struct AITeamMove *move);
TI_API void aimSave_SwarmDefense(struct AITeamMove *move);
TI_API void aimSave_ResourceVolume(struct AITeamMove *move);
TI_API void aimSave_Kamikaze(struct AITeamMove *move);

TI_API void aimPreFix_Dock(struct AITeamMove *move);
TI_API void aimPreFix_GetShips(struct AITeamMove *move);
TI_API void aimPreFix_Intercept(struct AITeamMove *move);
TI_API void aimPreFix_PatrolMove(struct AITeamMove *move);
TI_API void aimPreFix_AdvancedAttack(struct AITeamMove *move);
TI_API void aimPreFix_MoveAttack(struct AITeamMove *move);
TI_API void aimPreFix_HarassAttack(struct AITeamMove *move);
TI_API void aimPreFix_FancyGetShips(struct AITeamMove *move);
TI_API void aimPreFix_Reinforce(struct AITeamMove *move);

/*=============================================================================
    Previously in AIMoves1.c.h (Falko)
=============================================================================*/

TI_API void aimInsertMove(AITeam *team, struct AITeamMove *newMove);
TI_API void aimMoveSplitShipDied(AITeam *team, AITeamMove *move, ShipPtr ship);
TI_API void aimMoveSplitClose(AITeam *team, AITeamMove *move);
TI_API void aimInterceptShipDied(AITeam *team, AITeamMove *move, ShipPtr ship);
TI_API void aimFlankAttackClose(AITeam *team, struct AITeamMove *move);
TI_API void aimFlankAttackShipDied(AITeam *team, struct AITeamMove *move, Ship *ship);
TI_API void aimAdvancedAttackClose(AITeam *team, struct AITeamMove *move);
TI_API void aimAdvancedAttackShipDied(AITeam *team, struct AITeamMove *move, Ship *ship);
TI_API void aimMoveAttackShipDied(AITeam *team, struct AITeamMove *move, ShipPtr ship);
TI_API void aimMoveAttackClose(AITeam *team, struct AITeamMove *move);
TI_API void aimHarassAttackShipDied(AITeam *team, struct AITeamMove *move, Ship *ship);
TI_API void aimDockClose(AITeam *team, struct AITeamMove *move);
TI_API void aimDockShipDied(AITeam *team, struct AITeamMove *move, Ship *ship);
TI_API void aimDefendMothershipClose(AITeam *team, struct AITeamMove *move);
TI_API void aimDefendMothershipShipDied(AITeam *team, struct AITeamMove *move, Ship *ship);
TI_API void aimPatrolMoveClose(AITeam *team, struct AITeamMove *move);
TI_API void aimSupportShipDied(AITeam *team, struct AITeamMove *move, Ship *ship);
TI_API void aimSupportClose(AITeam *team, struct AITeamMove *move);
TI_API void aimShipReconShipDied(AITeam *team, struct AITeamMove *move, Ship *ship);
TI_API void aimShipReconClose(AITeam *team, struct AITeamMove *move);
TI_API void aimControlResourcesShipDied(AITeam *team, struct AITeamMove *move, ShipPtr ship);
TI_API void aimSwarmAttackShipDied(AITeam *team, struct AITeamMove *move, ShipPtr ship);
TI_API void aimSwarmAttackClose(AITeam *team, AITeamMove *move);
TI_API void aimSwarmDefenseShipDied(AITeam *team, struct AITeamMove *move, ShipPtr ship);
TI_API void aimSwarmDefenseClose(AITeam *team, AITeamMove *move);
TI_API void aimResourceVolumeResourceDied(AITeam *team, AITeamMove *move, Resource *resource);
TI_API void aimResourceVolumeShipDied(AITeam *team, AITeamMove *move, ShipPtr ship);
TI_API void aimResourceVolumeClose(AITeam *team, AITeamMove *move);
TI_API void aimCaptureShipDied(AITeam *team, AITeamMove *move, ShipPtr ship);
TI_API void aimMothershipMoveShipDied(AITeam *team, AITeamMove *move, ShipPtr ship);
TI_API sdword aimProcessMove(AITeam *team);
TI_API sdword aimProcessMoveSplit(AITeam *team);
TI_API sdword aimProcessHyperspace(AITeam *team);
TI_API sdword aimProcessIntercept(AITeam *team);
TI_API sdword aimProcessMoveTo(AITeam *team);
TI_API sdword aimProcessCountShips(AITeam *team);
TI_API sdword aimProcessFlankAttack(AITeam *team);
TI_API sdword aimProcessMoveAttack(AITeam *team);
TI_API sdword aimProcessAdvancedAttack(AITeam *team);
TI_API sdword aimProcessHarassAttack(AITeam *team);
TI_API sdword aimProcessDock(AITeam *team);
TI_API sdword aimProcessDefendMothership(AITeam *team);
TI_API sdword aimProcessPatrolMove(AITeam *team);
TI_API sdword aimProcessActivePatrol(AITeam *team);
TI_API sdword aimProcessTempGuard(AITeam *team);
TI_API sdword aimProcessReinforce(AITeam *team);
TI_API sdword aimProcessSupport(AITeam *team);
TI_API sdword aimProcessActiveRecon(AITeam *team);
TI_API sdword aimProcessShipRecon(AITeam *team);
TI_API sdword aimProcessArmada(AITeam *team);
TI_API sdword aimProcessControlResources(AITeam *team);
TI_API sdword aimProcessSwarmAttack(AITeam *team);
TI_API sdword aimProcessSwarmDefense(AITeam *team);
TI_API sdword aimProcessSwarmPod(AITeam *team);
TI_API sdword aimProcessResourceVolume(AITeam *team);
TI_API sdword aimProcessActiveResource(AITeam *team);
TI_API sdword aimProcessMothershipMove(AITeam *team);
TI_API sdword aimProcessCapture(AITeam *team);
TI_API sdword aimProcessActiveCapture(AITeam *team);
TI_API sdword aimProcessActiveMine(AITeam *team);
TI_API sdword aimProcessMineVolume(AITeam *team);
TI_API sdword aimProcessSpecialDefense(AITeam *team);
TI_API AITeamMove *aimCreateMoveTeamNoAdd(AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateMoveTeam(AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API void aimFix_MoveTeam(AITeamMove *move);
TI_API AITeamMove *aimCreateMoveTeamIndexNoAdd(AITeam *team, vector destination, udword index, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateMoveTeamIndex(AITeam *team, vector destination, udword index, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_MoveTeamIndex(AITeamMove *move);
TI_API AITeamMove *aimCreateMoveTeamSplitNoAdd(AITeam *team, SelectCommand *ships, Path *destinations, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateMoveTeamSplit(AITeam *team, SelectCommand *ships, Path *destinations, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_MoveTeamSplit(AITeamMove *move);
TI_API void aimSave_MoveTeamSplit(AITeamMove *move);
TI_API void aimLoad_MoveTeamSplit(AITeamMove *move);
TI_API AITeamMove *aimCreateHyperspaceNoAdd(AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateHyperspace(AITeam *team, vector destination, TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API void aimFix_Hyperspace(AITeamMove *move);
TI_API AITeamMove *aimCreateInterceptNoAdd(AITeam *team, ShipPtr ship, real32 interval, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateIntercept(AITeam *team, ShipPtr ship, real32 interval, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_Intercept(AITeamMove *move);
TI_API void aimPreFix_Intercept(AITeamMove *move);
TI_API AITeamMove *aimCreateMoveToNoAdd(AITeam *team, vector destination, real32 limiter, udword type, TypeOfFormation formation, TacticsType tactics, bool wait, bool remove);
TI_API AITeamMove *aimCreateMoveTo(AITeam *team, vector destination, real32 limiter, udword type, TypeOfFormation formation, TacticsType tactics, bool wait, bool remove);
TI_API void aimFix_MoveTo(AITeamMove *move);
TI_API AITeamMove *aimCreateCountShipsNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateCountShips(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_CountShips(AITeamMove *move);
TI_API AITeamMove *aimCreateFlankAttackNoAdd(AITeam *team, SelectCommand *targets, bool8 hyperspace, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateFlankAttack(AITeam *team, SelectCommand *targets, bool8 hyperspace, bool8 wait, bool8 remove);
TI_API void aimFix_FlankAttack(AITeamMove *move);
TI_API void aimSave_FlankAttack(AITeamMove *move);
TI_API void aimLoad_FlankAttack(AITeamMove *move);
TI_API AITeamMove *aimCreateAdvancedAttackNoAdd(AITeam *team, SelectCommand *targets, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateAdvancedAttack(AITeam *team, SelectCommand *target, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimPreFix_AdvancedAttack(AITeamMove *move);
TI_API void aimSave_AdvancedAttack(AITeamMove *move);
TI_API void aimLoad_AdvancedAttack(AITeamMove *move);
TI_API void aimFix_AdvancedAttack(AITeamMove *move);
TI_API AITeamMove *aimCreateMoveAttackNoAdd(AITeam *team, SelectCommand *targets, bool Advanced, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateMoveAttack(AITeam *team, SelectCommand *targets, bool Advanced, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimPreFix_MoveAttack(AITeamMove *move);
TI_API void aimFix_MoveAttack(AITeamMove *move);
TI_API void aimSave_MoveAttack(AITeamMove *move);
TI_API void aimLoad_MoveAttack(AITeamMove *move);
TI_API AITeamMove *aimCreateHarassAttack(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_HarassAttack(AITeamMove *move);
TI_API void aimPreFix_HarassAttack(AITeamMove *move);
TI_API AITeamMove *aimCreateDockNoAdd(AITeam *team, sdword dockmoveFlags, ShipPtr dockAt, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateDock(AITeam *team, sdword dockmoveFlags, ShipPtr dockAt, bool8 wait, bool8 remove);
TI_API void aimPreFix_Dock(AITeamMove *move);
TI_API void aimFix_Dock(AITeamMove *move);
TI_API void aimSave_Dock(AITeamMove *move);
TI_API void aimLoad_Dock(AITeamMove *move);
TI_API AITeamMove *aimCreateDefendMothershipNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateDefendMothership(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_DefMoship(AITeamMove *move);
TI_API void aimSave_DefMoship(AITeamMove *move);
TI_API void aimLoad_DefMoship(AITeamMove *move);
TI_API AITeamMove *aimCreatePatrolMoveNoAdd(AITeam *team, Path *path, udword startIndex, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreatePatrolMove(AITeam *team, Path *path, udword startIndex, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_PatrolMove(AITeamMove *move);
TI_API void aimPreFix_PatrolMove(AITeamMove *move);
TI_API void aimSave_PatrolMove(AITeamMove *move);
TI_API void aimLoad_PatrolMove(AITeamMove *move);
TI_API AITeamMove *aimCreateActivePatrolNoAdd(AITeam *team, udword patroltype, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateActivePatrol(AITeam *team, udword patroltype, bool8 wait, bool8 remove);
TI_API void aimFix_ActivePatrol(AITeamMove *move);
TI_API AITeamMove *aimCreateTempGuardNoAdd(AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateTempGuard(AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_TempGuard(AITeamMove *move);
TI_API AITeamMove *aimCreateReinforceNoAdd(AITeam *team, AITeam *reinforceteam, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateReinforce(AITeam *team, AITeam *reinforceteam, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_Reinforce(AITeamMove *move);
TI_API void aimPreFix_Reinforce(AITeamMove *move);
TI_API AITeamMove *aimCreateSupportNoAdd(AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateSupport(AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_Support(AITeamMove *move);
TI_API void aimSave_Support(AITeamMove *move);
TI_API void aimLoad_Support(AITeamMove *move);
TI_API AITeamMove *aimCreateActiveReconNoAdd(AITeam *team, bool EnemyRecon, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateActiveRecon(AITeam *team, bool EnemyRecon, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_ActiveRecon(AITeamMove *move);
TI_API AITeamMove *aimCreateShipReconNoAdd(AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateShipRecon(AITeam *team, SelectCommand *ships, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_ShipRecon(AITeamMove *move);
TI_API void aimSave_ShipRecon(AITeamMove *move);
TI_API void aimLoad_ShipRecon(AITeamMove *move);
TI_API AITeamMove *aimCreateArmadaNoAdd(AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateArmada(AITeam *team, TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_Armada(AITeamMove *move);
TI_API AITeamMove *aimCreateControlResourcesNoAdd(AITeam *team, SelectCommand *ships, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateControlResources(AITeam *team, SelectCommand *ships, bool8 wait, bool8 remove);
TI_API void aimFix_ControlResources(AITeamMove *move);
TI_API void aimSave_ControlResources(AITeamMove *move);
TI_API void aimLoad_ControlResources(AITeamMove *move);
TI_API AITeamMove *aimCreateSwarmAttackNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateSwarmAttack(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_SwarmAttack(AITeamMove *move);
TI_API void aimSave_SwarmAttack(AITeamMove *move);
TI_API void aimLoad_SwarmAttack(AITeamMove *move);
TI_API AITeamMove *aimCreateSwarmDefenseNoAdd(AITeam *team, SelectCommand *pods, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateSwarmDefense(AITeam *team, SelectCommand *pods, bool8 wait, bool8 remove);
TI_API void aimFix_SwarmDefense(AITeamMove *move);
TI_API void aimSave_SwarmDefense(AITeamMove *move);
TI_API void aimLoad_SwarmDefense(AITeamMove *move);
TI_API AITeamMove *aimCreateSwarmPodNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateSwarmPod(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_SwarmPod(AITeamMove *move);
TI_API AITeamMove *aimCreateResourceVolumeNoAdd(AITeam *team, Volume volume, bool8 strictVolume, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateResourceVolume(AITeam *team, Volume volume, bool8 strictVolume, bool8 wait, bool8 remove);
TI_API void aimFix_ResourceVolume(AITeamMove *move);
TI_API void aimSave_ResourceVolume(AITeamMove *move);
TI_API void aimLoad_ResourceVolume(AITeamMove *move);
TI_API AITeamMove *aimCreateActiveResourceNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateActiveResource(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_ActiveResource(AITeamMove *move);
TI_API AITeamMove *aimCreateMothershipMoveNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateMothershipMove(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_MothershipMove(AITeamMove *move);
TI_API AITeamMove *aimCreateCaptureNoAdd(AITeam *team, ShipPtr ship, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateCapture(AITeam *team, ShipPtr ship, bool8 wait, bool8 remove);
TI_API void aimFix_Capture(AITeamMove *move);
TI_API AITeamMove *aimCreateActiveCaptureNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateActiveCapture(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_ActiveCapture(AITeamMove *move);
TI_API AITeamMove *aimCreateActiveMineNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateActiveMine(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_ActiveMine(AITeamMove *move);
TI_API AITeamMove *aimCreateMineVolumeNoAdd(AITeam *team, Volume volume, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateMineVolume(AITeam *team, Volume volume, bool8 wait, bool8 remove);
TI_API void aimFix_MineVolume(AITeamMove *move);
TI_API AITeamMove *aimCreateSpecialDefenseNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateSpecialDefense(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_SpecialDefense(AITeamMove *move);
TI_API AITeamMove *aimCreateDeleteTeamNoAdd(AITeam *team);
TI_API AITeamMove *aimCreateDeleteTeam(AITeam *team);
TI_API void aimFix_DeleteTeam(AITeamMove *move);

/*=============================================================================
    Previously in AIMoves2.c.h (Gary)
=============================================================================*/

TI_API sdword aimProcessGuardCooperatingTeam(AITeam *team);
TI_API AITeamMove *aimCreateGuardCooperatingTeamNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateGuardCooperatingTeam(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_GuardCoopTeam(AITeamMove *move);
TI_API sdword aimProcessLaunch(AITeam *team);
TI_API AITeamMove *aimCreateLaunchNoAdd(AITeam *team, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateLaunch(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_Launch(AITeamMove *move);
TI_API sdword aimProcessFormation(AITeam *team);
TI_API AITeamMove *aimCreateFormationNoAdd(AITeam *team, TypeOfFormation formationtype, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateFormation(AITeam *team, TypeOfFormation formationtype, bool8 wait, bool8 remove);
TI_API void aimFix_Formation(AITeamMove *move);
TI_API sdword aimProcessMoveDone(AITeam *team);
TI_API AITeamMove *aimCreateMoveDone(AITeam *team, bool8 wait, bool8 remove);
TI_API void aimFix_MoveDone(AITeamMove *move);
TI_API sdword aimProcessAttack(AITeam *team);
TI_API void aimShipDiedAttack(AITeam *team,AITeamMove *move,Ship *ship);
TI_API void aimCloseAttack(AITeam *team,AITeamMove *move);
TI_API AITeamMove *aimCreateAttackNoAdd(AITeam *team, SelectCommand *targets,TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateAttack(AITeam *team, SelectCommand *targets,TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API void aimFix_Attack(AITeamMove *move);
TI_API void aimSave_Attack(AITeamMove *move);
TI_API void aimLoad_Attack(AITeamMove *move);
TI_API sdword aimProcessSpecial(AITeam *team);
TI_API void aimSpecialShipDied(AITeam *team,AITeamMove *move,Ship *ship);
TI_API void aimSpecialClose(AITeam *team,AITeamMove *move);
TI_API AITeamMove *aimCreateSpecialNoAdd(AITeam *team, SelectCommand *targets,TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateSpecial(AITeam *team, SelectCommand *targets,TypeOfFormation formation, TacticsType tactics, bool8 wait, bool8 remove);
TI_API void aimFix_Special(AITeamMove *move);
TI_API void aimSave_Special(AITeamMove *move);
TI_API void aimLoad_Special(AITeamMove *move);
TI_API sdword aimProcessKamikaze(AITeam *team);
TI_API void aimShipDiedKamikaze(AITeam *team,AITeamMove *move,Ship *ship);
TI_API void aimCloseKamikaze(AITeam *team,AITeamMove *move);
TI_API AITeamMove *aimCreateKamikazeNoAdd(AITeam *team, SelectCommand *targets,TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateKamikaze(AITeam *team, SelectCommand *targets,TypeOfFormation formation, bool8 wait, bool8 remove);
TI_API void aimFix_Kamikaze(AITeamMove *move);
TI_API void aimSave_Kamikaze(AITeamMove *move);
TI_API void aimLoad_Kamikaze(AITeamMove *move);
TI_API void aimCloseFancyGetShips(AITeam *team,AITeamMove *move);
TI_API sdword aimProcessFancyGetShips(AITeam *team);
TI_API AITeamMove *aimCreateFancyGetShipsNoAdd(AITeam *team, ShipType shiptype, sbyte num_ships, AlternativeShips *alternatives, sdword priority, bool8 wait, bool8 remove);
TI_API AITeamMove *aimCreateFancyGetShips(AITeam *team, ShipType shiptype, sbyte num_ships, AlternativeShips *alternatives, sdword priority, bool8 wait, bool8 remove);
TI_API void aimFix_FancyGetShips(AITeamMove *move);
TI_API void aimPreFix_FancyGetShips(AITeamMove *move);

#endif
