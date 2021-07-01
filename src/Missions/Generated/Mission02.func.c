//
//  ../Generated/Mission02.func.c
//
//  Finite state machine function pointers for "Mission02" mission
//
//  This code was autogenerated from Mission02.kpp by KAS2C Version 2.05sdl
//


#include "../Generated/Mission02.h"  // prototypes and #includes for exposed game functions

// FSM init/watch function pointers.
const void* Mission02_FunctionPointers[] =
{
	(void*)Init_Mission02_FleetIntel,
	(void*)Watch_Mission02_FleetIntel,
	(void*)Init_Mission02_FleetIntel_FCIntro,
	(void*)Watch_Mission02_FleetIntel_FCIntro,
	(void*)Init_Mission02_FleetIntel_FIIntro,
	(void*)Watch_Mission02_FleetIntel_FIIntro,
	(void*)Init_Mission02_FleetIntel_FCSignalling,
	(void*)Watch_Mission02_FleetIntel_FCSignalling,
	(void*)Init_Mission02_FleetIntel_FCSignalling2,
	(void*)Watch_Mission02_FleetIntel_FCSignalling2,
	(void*)Init_Mission02_FleetIntel_FISendProbeLBXIn,
	(void*)Watch_Mission02_FleetIntel_FISendProbeLBXIn,
	(void*)Init_Mission02_FleetIntel_FISendProbeLBXIn2,
	(void*)Watch_Mission02_FleetIntel_FISendProbeLBXIn2,
	(void*)Init_Mission02_FleetIntel_FISendProbeOpenSensors,
	(void*)Watch_Mission02_FleetIntel_FISendProbeOpenSensors,
	(void*)Init_Mission02_FleetIntel_FISendProbe,
	(void*)Watch_Mission02_FleetIntel_FISendProbe,
	(void*)Init_Mission02_FleetIntel_FISendProbe2,
	(void*)Watch_Mission02_FleetIntel_FISendProbe2,
	(void*)Init_Mission02_FleetIntel_FISendProbePING,
	(void*)Watch_Mission02_FleetIntel_FISendProbePING,
	(void*)Init_Mission02_FleetIntel_FISendProbeLBXOut,
	(void*)Watch_Mission02_FleetIntel_FISendProbeLBXOut,
	(void*)Init_Mission02_FleetIntel_FISendProbeWAITEND,
	(void*)Watch_Mission02_FleetIntel_FISendProbeWAITEND,
	(void*)Init_Mission02_FleetIntel_FISendProbeEND,
	(void*)Watch_Mission02_FleetIntel_FISendProbeEND,
	(void*)Init_Mission02_FleetIntel_FCUnderAttack,
	(void*)Watch_Mission02_FleetIntel_FCUnderAttack,
	(void*)Init_Mission02_FleetIntel_FISalvageVessel,
	(void*)Watch_Mission02_FleetIntel_FISalvageVessel,
	(void*)Init_Mission02_FleetIntel_FISalvageKSLBXIn,
	(void*)Watch_Mission02_FleetIntel_FISalvageKSLBXIn,
	(void*)Init_Mission02_FleetIntel_FISalvageKSLBXIn2,
	(void*)Watch_Mission02_FleetIntel_FISalvageKSLBXIn2,
	(void*)Init_Mission02_FleetIntel_FISalvageKSOpenSensors,
	(void*)Watch_Mission02_FleetIntel_FISalvageKSOpenSensors,
	(void*)Init_Mission02_FleetIntel_FISalvageKS,
	(void*)Watch_Mission02_FleetIntel_FISalvageKS,
	(void*)Init_Mission02_FleetIntel_FISalvageKS2,
	(void*)Watch_Mission02_FleetIntel_FISalvageKS2,
	(void*)Init_Mission02_FleetIntel_FISalvageKSWAITEND,
	(void*)Watch_Mission02_FleetIntel_FISalvageKSWAITEND,
	(void*)Init_Mission02_FleetIntel_FISalvageKSEND,
	(void*)Watch_Mission02_FleetIntel_FISalvageKSEND,
	(void*)Init_Mission02_FleetIntel_FISCDiedStillNeedData,
	(void*)Watch_Mission02_FleetIntel_FISCDiedStillNeedData,
	(void*)Init_Mission02_FleetIntel_FIKilledNISTeam,
	(void*)Watch_Mission02_FleetIntel_FIKilledNISTeam,
	(void*)Init_Mission02_FleetIntel_FCMothershipIsOK,
	(void*)Watch_Mission02_FleetIntel_FCMothershipIsOK,
	(void*)Init_Mission02_FleetIntel_FIDefendSalvageTeam,
	(void*)Watch_Mission02_FleetIntel_FIDefendSalvageTeam,
	(void*)Init_Mission02_FleetIntel_FIDefendSalvageTeam2,
	(void*)Watch_Mission02_FleetIntel_FIDefendSalvageTeam2,
	(void*)Init_Mission02_FleetIntel_FISCDockedSafely,
	(void*)Watch_Mission02_FleetIntel_FISCDockedSafely,
	(void*)Init_Mission02_FleetIntel_FocusOnKharSelim,
	(void*)Watch_Mission02_FleetIntel_FocusOnKharSelim,
	(void*)Init_Mission02_FleetIntel_WaitOnKharSelim,
	(void*)Watch_Mission02_FleetIntel_WaitOnKharSelim,
	(void*)Init_Mission02_FleetIntel_AllShipsRecording,
	(void*)Watch_Mission02_FleetIntel_AllShipsRecording,
	(void*)Init_Mission02_FleetIntel_FIAllShipsRecordingLBXOut,
	(void*)Watch_Mission02_FleetIntel_FIAllShipsRecordingLBXOut,
	(void*)Init_Mission02_FleetIntel_FIDefendMothershipLBXIn,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothershipLBXIn,
	(void*)Init_Mission02_FleetIntel_FIDefendMothershipLBXIn2,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothershipLBXIn2,
	(void*)Init_Mission02_FleetIntel_FIDefendMothershipOpenSensors,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothershipOpenSensors,
	(void*)Init_Mission02_FleetIntel_FIDefendMothership,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothership,
	(void*)Init_Mission02_FleetIntel_FIDefendMothershipPING,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothershipPING,
	(void*)Init_Mission02_FleetIntel_FIDefendMothershipLBXOut,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothershipLBXOut,
	(void*)Init_Mission02_FleetIntel_FIDefendMothershipWAITEND,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothershipWAITEND,
	(void*)Init_Mission02_FleetIntel_FIDefendMothershipEND,
	(void*)Watch_Mission02_FleetIntel_FIDefendMothershipEND,
	(void*)Init_Mission02_FleetIntel_FIInvestigateP1Mothership,
	(void*)Watch_Mission02_FleetIntel_FIInvestigateP1Mothership,
	(void*)Init_Mission02_FleetIntel_FISeenP1Mothership,
	(void*)Watch_Mission02_FleetIntel_FISeenP1Mothership,
	(void*)Init_Mission02_FleetIntel_FIDestroyAllP1,
	(void*)Watch_Mission02_FleetIntel_FIDestroyAllP1,
	(void*)Init_Mission02_FleetIntel_FIDestroyAllP12,
	(void*)Watch_Mission02_FleetIntel_FIDestroyAllP12,
	(void*)Init_Mission02_FleetIntel_FIObjectivesComplete,
	(void*)Watch_Mission02_FleetIntel_FIObjectivesComplete,
	(void*)Init_Mission02_FleetIntel_FIObjectivesComplete2,
	(void*)Watch_Mission02_FleetIntel_FIObjectivesComplete2,
	(void*)Init_Mission02_FleetIntel_FIDone,
	(void*)Watch_Mission02_FleetIntel_FIDone,
	(void*)Init_Mission02_FleetIntel_FIIdle,
	(void*)Watch_Mission02_FleetIntel_FIIdle,
	(void*)Init_Mission02_NISTeamFighter,
	(void*)Watch_Mission02_NISTeamFighter,
	(void*)Init_Mission02_NISTeamFighter_AttackMothership,
	(void*)Watch_Mission02_NISTeamFighter_AttackMothership,
	(void*)Init_Mission02_NISTeamFighter_Attack,
	(void*)Watch_Mission02_NISTeamFighter_Attack,
	(void*)Init_Mission02_NISTeamFighter_WatchAttack,
	(void*)Watch_Mission02_NISTeamFighter_WatchAttack,
	(void*)Init_Mission02_NISTeamFighter_DockForGood,
	(void*)Watch_Mission02_NISTeamFighter_DockForGood,
	(void*)Init_Mission02_NISTeamFighter_BugginOut,
	(void*)Watch_Mission02_NISTeamFighter_BugginOut,
	(void*)Init_Mission02_NISTeamFighter_NullState,
	(void*)Watch_Mission02_NISTeamFighter_NullState,
	(void*)Init_Mission02_NISTeamCorvette,
	(void*)Watch_Mission02_NISTeamCorvette,
	(void*)Init_Mission02_NISTeamCorvette_Attack,
	(void*)Watch_Mission02_NISTeamCorvette_Attack,
	(void*)Init_Mission02_NISTeamCorvette_WatchAttack,
	(void*)Watch_Mission02_NISTeamCorvette_WatchAttack,
	(void*)Init_Mission02_NISTeamCorvette_DockForGood,
	(void*)Watch_Mission02_NISTeamCorvette_DockForGood,
	(void*)Init_Mission02_NISTeamCorvette_BugginOut,
	(void*)Watch_Mission02_NISTeamCorvette_BugginOut,
	(void*)Init_Mission02_NISTeamCorvette_NullState,
	(void*)Watch_Mission02_NISTeamCorvette_NullState,
	(void*)Init_Mission02_DoggedFighter,
	(void*)Watch_Mission02_DoggedFighter,
	(void*)Init_Mission02_DoggedFighter_AllDeadWaitForShips,
	(void*)Watch_Mission02_DoggedFighter_AllDeadWaitForShips,
	(void*)Init_Mission02_DoggedFighter_DockInstant,
	(void*)Watch_Mission02_DoggedFighter_DockInstant,
	(void*)Init_Mission02_DoggedFighter_WatchingForSC,
	(void*)Watch_Mission02_DoggedFighter_WatchingForSC,
	(void*)Init_Mission02_DoggedFighter_Launch,
	(void*)Watch_Mission02_DoggedFighter_Launch,
	(void*)Init_Mission02_DoggedFighter_AttackSC,
	(void*)Watch_Mission02_DoggedFighter_AttackSC,
	(void*)Init_Mission02_DoggedFighter_AttackSCsReturning,
	(void*)Watch_Mission02_DoggedFighter_AttackSCsReturning,
	(void*)Init_Mission02_DoggedFighter_IHaveNoTarget,
	(void*)Watch_Mission02_DoggedFighter_IHaveNoTarget,
	(void*)Init_Mission02_DoggedFighter_Defend,
	(void*)Watch_Mission02_DoggedFighter_Defend,
	(void*)Init_Mission02_DoggedFighter_AttacknisVolume,
	(void*)Watch_Mission02_DoggedFighter_AttacknisVolume,
	(void*)Init_Mission02_DoggedFighter_DockWithMothership,
	(void*)Watch_Mission02_DoggedFighter_DockWithMothership,
	(void*)Init_Mission02_DoggedFighter_Docked,
	(void*)Watch_Mission02_DoggedFighter_Docked,
	(void*)Init_Mission02_DoggedFighter_Launch2,
	(void*)Watch_Mission02_DoggedFighter_Launch2,
	(void*)Init_Mission02_DoggedFighter_WatchingForSC2,
	(void*)Watch_Mission02_DoggedFighter_WatchingForSC2,
	(void*)Init_Mission02_DoggedFighter_DockForGood,
	(void*)Watch_Mission02_DoggedFighter_DockForGood,
	(void*)Init_Mission02_DoggedFighter_BugginOutForGood,
	(void*)Watch_Mission02_DoggedFighter_BugginOutForGood,
	(void*)Init_Mission02_DoggedFighter_BugginOut,
	(void*)Watch_Mission02_DoggedFighter_BugginOut,
	(void*)Init_Mission02_DoggedFighter_NullState,
	(void*)Watch_Mission02_DoggedFighter_NullState,
	(void*)Init_Mission02_SCFighters,
	(void*)Watch_Mission02_SCFighters,
	(void*)Init_Mission02_SCFighters_AllDeadWaitForShips,
	(void*)Watch_Mission02_SCFighters_AllDeadWaitForShips,
	(void*)Init_Mission02_SCFighters_DockInstant,
	(void*)Watch_Mission02_SCFighters_DockInstant,
	(void*)Init_Mission02_SCFighters_WatchingForSC,
	(void*)Watch_Mission02_SCFighters_WatchingForSC,
	(void*)Init_Mission02_SCFighters_Launch,
	(void*)Watch_Mission02_SCFighters_Launch,
	(void*)Init_Mission02_SCFighters_AttackSC,
	(void*)Watch_Mission02_SCFighters_AttackSC,
	(void*)Init_Mission02_SCFighters_AttackSCsReturning,
	(void*)Watch_Mission02_SCFighters_AttackSCsReturning,
	(void*)Init_Mission02_SCFighters_Defend,
	(void*)Watch_Mission02_SCFighters_Defend,
	(void*)Init_Mission02_SCFighters_IHaveNoTarget,
	(void*)Watch_Mission02_SCFighters_IHaveNoTarget,
	(void*)Init_Mission02_SCFighters_Defend2,
	(void*)Watch_Mission02_SCFighters_Defend2,
	(void*)Init_Mission02_SCFighters_AttacknisVolume,
	(void*)Watch_Mission02_SCFighters_AttacknisVolume,
	(void*)Init_Mission02_SCFighters_DockWithMothership,
	(void*)Watch_Mission02_SCFighters_DockWithMothership,
	(void*)Init_Mission02_SCFighters_Docked,
	(void*)Watch_Mission02_SCFighters_Docked,
	(void*)Init_Mission02_SCFighters_Launch2,
	(void*)Watch_Mission02_SCFighters_Launch2,
	(void*)Init_Mission02_SCFighters_WatchingForSC2,
	(void*)Watch_Mission02_SCFighters_WatchingForSC2,
	(void*)Init_Mission02_SCFighters_DockForGood,
	(void*)Watch_Mission02_SCFighters_DockForGood,
	(void*)Init_Mission02_SCFighters_BugginOutForGood,
	(void*)Watch_Mission02_SCFighters_BugginOutForGood,
	(void*)Init_Mission02_SCFighters_BugginOut,
	(void*)Watch_Mission02_SCFighters_BugginOut,
	(void*)Init_Mission02_SCFighters_NullState,
	(void*)Watch_Mission02_SCFighters_NullState,
	(void*)Init_Mission02_ACT3Fighters,
	(void*)Watch_Mission02_ACT3Fighters,
	(void*)Init_Mission02_ACT3Fighters_AllDeadWaitForShips,
	(void*)Watch_Mission02_ACT3Fighters_AllDeadWaitForShips,
	(void*)Init_Mission02_ACT3Fighters_DockInstant,
	(void*)Watch_Mission02_ACT3Fighters_DockInstant,
	(void*)Init_Mission02_ACT3Fighters_Launch,
	(void*)Watch_Mission02_ACT3Fighters_Launch,
	(void*)Init_Mission02_ACT3Fighters_MASTERLooking,
	(void*)Watch_Mission02_ACT3Fighters_MASTERLooking,
	(void*)Init_Mission02_ACT3Fighters_AttackMothershipSphere,
	(void*)Watch_Mission02_ACT3Fighters_AttackMothershipSphere,
	(void*)Init_Mission02_ACT3Fighters_AttackEntireWorld,
	(void*)Watch_Mission02_ACT3Fighters_AttackEntireWorld,
	(void*)Init_Mission02_ACT3Fighters_AttackMothership,
	(void*)Watch_Mission02_ACT3Fighters_AttackMothership,
	(void*)Init_Mission02_ACT3Fighters_Defend,
	(void*)Watch_Mission02_ACT3Fighters_Defend,
	(void*)Init_Mission02_ACT3Fighters_GoHelpP1Mothership,
	(void*)Watch_Mission02_ACT3Fighters_GoHelpP1Mothership,
	(void*)Init_Mission02_ACT3Fighters_DockForGood,
	(void*)Watch_Mission02_ACT3Fighters_DockForGood,
	(void*)Init_Mission02_ACT3Fighters_BugginOut,
	(void*)Watch_Mission02_ACT3Fighters_BugginOut,
	(void*)Init_Mission02_ACT3Fighters_NullState,
	(void*)Watch_Mission02_ACT3Fighters_NullState,
	(void*)Init_Mission02_ACT3Corvettes1,
	(void*)Watch_Mission02_ACT3Corvettes1,
	(void*)Init_Mission02_ACT3Corvettes1_AllDeadWaitForShips,
	(void*)Watch_Mission02_ACT3Corvettes1_AllDeadWaitForShips,
	(void*)Init_Mission02_ACT3Corvettes1_DockInstant,
	(void*)Watch_Mission02_ACT3Corvettes1_DockInstant,
	(void*)Init_Mission02_ACT3Corvettes1_Launch,
	(void*)Watch_Mission02_ACT3Corvettes1_Launch,
	(void*)Init_Mission02_ACT3Corvettes1_MASTERLooking,
	(void*)Watch_Mission02_ACT3Corvettes1_MASTERLooking,
	(void*)Init_Mission02_ACT3Corvettes1_AttackMothershipSphere,
	(void*)Watch_Mission02_ACT3Corvettes1_AttackMothershipSphere,
	(void*)Init_Mission02_ACT3Corvettes1_AttackEntireWorld,
	(void*)Watch_Mission02_ACT3Corvettes1_AttackEntireWorld,
	(void*)Init_Mission02_ACT3Corvettes1_AttackMothership,
	(void*)Watch_Mission02_ACT3Corvettes1_AttackMothership,
	(void*)Init_Mission02_ACT3Corvettes1_Defend,
	(void*)Watch_Mission02_ACT3Corvettes1_Defend,
	(void*)Init_Mission02_ACT3Corvettes1_GoHelpP1Mothership,
	(void*)Watch_Mission02_ACT3Corvettes1_GoHelpP1Mothership,
	(void*)Init_Mission02_ACT3Corvettes1_DockForGood,
	(void*)Watch_Mission02_ACT3Corvettes1_DockForGood,
	(void*)Init_Mission02_ACT3Corvettes1_BugginOut,
	(void*)Watch_Mission02_ACT3Corvettes1_BugginOut,
	(void*)Init_Mission02_ACT3Corvettes1_NullState,
	(void*)Watch_Mission02_ACT3Corvettes1_NullState,
	(void*)Init_Mission02_ACT3Corvettes2,
	(void*)Watch_Mission02_ACT3Corvettes2,
	(void*)Init_Mission02_ACT3Corvettes2_AllDeadWaitForShips,
	(void*)Watch_Mission02_ACT3Corvettes2_AllDeadWaitForShips,
	(void*)Init_Mission02_ACT3Corvettes2_DockInstant,
	(void*)Watch_Mission02_ACT3Corvettes2_DockInstant,
	(void*)Init_Mission02_ACT3Corvettes2_Launch,
	(void*)Watch_Mission02_ACT3Corvettes2_Launch,
	(void*)Init_Mission02_ACT3Corvettes2_MASTERLooking,
	(void*)Watch_Mission02_ACT3Corvettes2_MASTERLooking,
	(void*)Init_Mission02_ACT3Corvettes2_AttackMothershipSphere,
	(void*)Watch_Mission02_ACT3Corvettes2_AttackMothershipSphere,
	(void*)Init_Mission02_ACT3Corvettes2_AttackEntireWorld,
	(void*)Watch_Mission02_ACT3Corvettes2_AttackEntireWorld,
	(void*)Init_Mission02_ACT3Corvettes2_AttackMothership,
	(void*)Watch_Mission02_ACT3Corvettes2_AttackMothership,
	(void*)Init_Mission02_ACT3Corvettes2_Defend,
	(void*)Watch_Mission02_ACT3Corvettes2_Defend,
	(void*)Init_Mission02_ACT3Corvettes2_GoHelpP1Mothership,
	(void*)Watch_Mission02_ACT3Corvettes2_GoHelpP1Mothership,
	(void*)Init_Mission02_ACT3Corvettes2_DockForGood,
	(void*)Watch_Mission02_ACT3Corvettes2_DockForGood,
	(void*)Init_Mission02_ACT3Corvettes2_BugginOut,
	(void*)Watch_Mission02_ACT3Corvettes2_BugginOut,
	(void*)Init_Mission02_ACT3Corvettes2_NullState,
	(void*)Watch_Mission02_ACT3Corvettes2_NullState,
	(void*)Init_Mission02_P1Mothership,
	(void*)Watch_Mission02_P1Mothership,
	(void*)Init_Mission02_P1Mothership_Hide,
	(void*)Watch_Mission02_P1Mothership_Hide,
	(void*)Init_Mission02_P1Mothership_Amble,
	(void*)Watch_Mission02_P1Mothership_Amble,
	(void*)Init_Mission02_P1Mothership_Retreat,
	(void*)Watch_Mission02_P1Mothership_Retreat,
	(void*)Init_Mission02_P1Mothership_GetIntoPosition,
	(void*)Watch_Mission02_P1Mothership_GetIntoPosition,
	(void*)Init_Mission02_P1Mothership_InPosition,
	(void*)Watch_Mission02_P1Mothership_InPosition,
	(void*)Init_Mission02_P1Mothership_DefendYourself,
	(void*)Watch_Mission02_P1Mothership_DefendYourself,
	(void*)Init_Mission02_P1Mothership_BackInPosition,
	(void*)Watch_Mission02_P1Mothership_BackInPosition,
	(void*)Init_Mission02_P1Mothership_PatrolPlayerFleet,
	(void*)Watch_Mission02_P1Mothership_PatrolPlayerFleet,
	(void*)Init_Mission02_P1Mothership_Retreat2,
	(void*)Watch_Mission02_P1Mothership_Retreat2,
	(void*)Init_Mission02_P1Mothership_OuttaHereLikeVladimir,
	(void*)Watch_Mission02_P1Mothership_OuttaHereLikeVladimir,
	(void*)Init_Mission02_P1Mothership_HyperspaceOut,
	(void*)Watch_Mission02_P1Mothership_HyperspaceOut,
	(void*)Init_Mission02_P1Mothership_NullState,
	(void*)Watch_Mission02_P1Mothership_NullState,
	(void*)Init_Mission02,
	(void*)Watch_Mission02,
};

// Number of FSM init/watch function pointers.
const unsigned int Mission02_FunctionPointerCount = 304;
