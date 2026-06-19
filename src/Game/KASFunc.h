#ifndef ___KASFUNC_H
#define ___KASFUNC_H

#include "tiPlatform.h"
#include "AIUtilities.h"
#include "ShipSelect.h"
#include "Volume.h"

//
//  --------------------------------
//  these are for the placeholder for a real fleet intelligence message window
//
//
//  PETER:  we can nuke all this now, right?
//

// seconds
#define POPUPTEXT_DURATION_PER_LINE  4

// chars
#define POPUPTEXT_MAX_LINE_LENGTH  128
#define POPUPTEXT_MAX_LINES  16

// pixels
#define POPUPTEXT_BOX_WIDTH  200

TI_API void kasfPopupTextDraw(void);
TI_API void kasfPopupText(char *line);
TI_API void kasfPopupTextClear(void);

//
//  --------------------------------
//


//
//  new function prototypes also need to go into KAS2C.C so the
//  translator will recognize them
//

TI_API void kasfMissionCompleted(void);
TI_API void kasfMissionFailed(void);

TI_API void kasfFadeToWhite(void);

TI_API void kasfVarCreate(char *name);
TI_API void kasfVarValueSet(char *name, sdword value);
TI_API void kasfVarCreateSet(char *name, sdword value);
TI_API void kasfVarValueInc(char *name);
TI_API void kasfVarValueDec(char *name);
TI_API sdword kasfVarValueGet(char *name);
TI_API void kasfVarDestroy(char *name);

TI_API void kasfCommandMessage(char *message);

TI_API void kasfTimerCreate(char *name);
TI_API void kasfTimerSet(char *name, sdword duration);
TI_API void kasfTimerStart(char *name);
TI_API void kasfTimerCreateSetStart(char *name, sdword duration);
TI_API void kasfTimerStop(char *name);
TI_API void kasfHarvest(void);
TI_API sdword kasfTimerRemaining(char *name);
TI_API sdword kasfTimerExpired(char *name);
TI_API sdword kasfTimerExpiredDestroy(char *name);
TI_API void kasfTimerDestroy(char *name);

TI_API sdword kasfMsgReceived(char *msg);

TI_API void kasfAttackMothership(void);
TI_API void kasfAttack(GrowSelection *targets);
TI_API void kasfAttackFlank(GrowSelection *targets);
TI_API void kasfAttackHarass(void);
TI_API void kasfAttackSpecial(GrowSelection *targets);
TI_API void kasfMoveAttack(GrowSelection *targets);
TI_API sdword kasfBulgeAttack(GrowSelection *targets, GrowSelection *bulgetargets, GrowSelection *attackers, sdword radius);
TI_API void kasfIntercept(GrowSelection *targets);
TI_API void kasfTargetDrop(void);
TI_API void kasfSetSwarmerTargets(GrowSelection *targets);
TI_API void kasfSwarmMoveTo(GrowSelection *targets);
TI_API void kasfShipsAttack(GrowSelection *targets, GrowSelection *attackers);

TI_API void kasfFormationDelta(void);
TI_API void kasfFormationBroad(void);
TI_API void kasfFormationDelta3D(void);
TI_API void kasfFormationClaw(void);
TI_API void kasfFormationWall(void);
TI_API void kasfFormationSphere(void);
TI_API void kasfFormationCustom(GrowSelection *shipsg);

TI_API sdword kasfRandom(sdword lowestNum, sdword highestNum);

TI_API void kasfGuardMothership(void);
TI_API void kasfGuardShips(GrowSelection *ships);

TI_API void kasfPatrolPath(Path *path);
TI_API void kasfPatrolActive(void);

TI_API void kasfLog(char *string);
TI_API void kasfLogInteger(char *string, sdword integer);

TI_API sdword kasfTeamHealthAverage(void);
TI_API sdword kasfTeamHealthLowest(void);
TI_API sdword kasfTeamFuelAverage(void);
TI_API sdword kasfTeamFuelLowest(void);
TI_API sdword kasfTeamCount(void);
TI_API sdword kasfTeamCountOriginal(void);
TI_API sdword kasfNewShipsAdded(void);

TI_API void kasfGrowSelectionClear(GrowSelection *ships);

TI_API void kasfTeamAttributesBitSet(sdword attributes);
TI_API void kasfTeamAttributesBitClear(sdword attributes);
TI_API void kasfTeamAttributesSet(sdword attributes);

TI_API void kasfShipsAttributesBitSet(GrowSelection *ships,sdword attributes);
TI_API void kasfShipsAttributesBitClear(GrowSelection *ships,sdword attributes);
TI_API void kasfShipsAttributesSet(GrowSelection *ships,sdword attributes);

TI_API sdword kasfShipsDisabled(GrowSelection *ships);

TI_API sdword kasfShipsCount(GrowSelection *ships);

TI_API sdword kasfPointInside(Volume *volume, hvector *location);

TI_API sdword kasfFindShipsInside(Volume *volume, GrowSelection *ships);
TI_API sdword kasfFindEnemiesInside(Volume *volume, GrowSelection *ships, sdword neighborRadius);
TI_API sdword kasfFindEnemiesNearby(GrowSelection *ships, sdword radius);
TI_API sdword kasfFindEnemiesNearTeam(GrowSelection *ships, sdword radius);
TI_API sdword kasfFindEnemyShipsOfType(GrowSelection *ships, char *shipType);
TI_API sdword kasfFindFriendlyShipsOfType(GrowSelection *ships, char *shipType);
TI_API sdword kasfFindEnemyShipsOfClass(GrowSelection *ships, char *shipClass);
TI_API sdword kasfFindFriendlyShipsOfClass(GrowSelection *ships, char *shipClass);
TI_API sdword kasfFindShipsNearPoint(GrowSelection *ships, hvector *location, sdword radius);

TI_API void kasfTeamSkillSet(sdword skillLevel);
TI_API sdword kasfTeamSkillGet(void);

TI_API void kasfDisablePlayerHyperspace(void);
TI_API void kasfHoldHyperspaceWindow(bool hold);
TI_API void kasfTeamHyperspaceIn(hvector *destination);
TI_API void kasfTeamHyperspaceInNear(hvector *destination, sdword distance);
TI_API void kasfTeamHyperspaceOut(void);
TI_API void kasfHyperspaceDelay(sdword milliseconds);

TI_API void kasfGateDestroy(hvector *gatePoint);
TI_API void kasfGateShipsIn(GrowSelection *ships, hvector *gatePoint);
TI_API void kasfGateShipsOut(GrowSelection *ships, hvector *gatePoint);
TI_API void kasfGateMoveToNearest(void);
TI_API sdword kasfGateShipsOutNearest(GrowSelection *ships);

TI_API void kasfMissionSkillSet(sdword skillLevel);
TI_API sdword kasfMissionSkillGet(void);

TI_API void kasfRequestShips(char *shipType, sdword numShips);
TI_API void kasfRequestShipsOriginal(sdword percentOriginal);

TI_API void kasfReinforce(struct AITeam *team);

TI_API void kasfTeamGiveToAI(void);

TI_API void kasfDisableAIFeature(sdword feature, sdword type);
TI_API void kasfEnableAIFeature(sdword feature, sdword type);
TI_API void kasfDisableAllAIFeatures(void);
TI_API void kasfEnableAllAIFeatures(void);

TI_API void kasfTeamSwitchPlayerOwner(void);
TI_API void kasfShipsSwitchPlayerOwner(GrowSelection *ships);

TI_API void kasfReinforceTeamWithShips(struct AITeam *teamtoreinforce,GrowSelection *shipstoadd);
TI_API void kasfTeamMakeCrazy(sdword makecrazy);

TI_API void kasfForceCombatStatus(GrowSelection *ships, sdword on);

TI_API sdword kasfThisTeamIs(struct AITeam *team);

TI_API void kasfMoveTo(hvector *destination);
TI_API void kasfShipsMoveTo(GrowSelection *ships, hvector *destination);

TI_API void kasfTacticsAggressive(void);
TI_API void kasfTacticsNeutral(void);
TI_API void kasfTacticsEvasive(void);

TI_API sdword kasfNearby(hvector *location, sdword distance);
TI_API sdword kasfFindDistance(hvector *location1, hvector *location2);

TI_API sdword kasfUnderAttack(GrowSelection *attackers);
TI_API sdword kasfUnderAttackElsewhere(struct AITeam *otherTeam, GrowSelection *attackers);

TI_API sdword kasfShipsCountType(GrowSelection *ships, char *shipType);

TI_API void kasfDock(struct AITeam *withTeam);
TI_API void kasfDockSupport(void);
TI_API void kasfDockSupportWith(struct AITeam * withTeam);
TI_API void kasfShipsDockSupportWith(GrowSelection *ships, GrowSelection *withShips);
TI_API void kasfDockStay(struct AITeam * withTeam);
TI_API void kasfShipsDockStay(GrowSelection *ships, GrowSelection *withShips);
TI_API void kasfDockStayMothership(void);
TI_API void kasfDockInstant(struct AITeam * withTeam);
TI_API void kasfLaunch(void);

TI_API sdword kasfTeamDocking(void);
TI_API sdword kasfTeamDockedReadyForLaunch(void);
TI_API sdword kasfTeamFinishedLaunching(void);

TI_API void kasfMsgSend(struct AITeam *team, char *msg);
TI_API void kasfMsgSendAll(char *msg);

TI_API sdword kasfRUsEnemyCollected(void);

TI_API sdword kasfPathNextPoint(void);

TI_API sdword kasfNISRunning(void);

TI_API void kasfTeamSetMaxVelocity(sdword maxVelocity);
TI_API void kasfTeamClearMaxVelocity(void);
TI_API void kasfShipsSetMaxVelocity(GrowSelection *ships, sdword maxVelocity);
TI_API void kasfShipsClearMaxVelocity(GrowSelection *ships, sdword maxVelocity);
TI_API void kasfShipsSetDamageFactor(GrowSelection *ships, sdword damagePercent);
TI_API void kasfShipsClearDamageFactor(GrowSelection *ships);
TI_API void kasfTeamSetPercentDamaged(sdword percentDamaged);
TI_API void kasfTeamSetPercentFueled(sdword percentFueled);

TI_API sdword kasfShipsSelectEnemy(GrowSelection *newShips, GrowSelection *originalShips);
TI_API sdword kasfShipsSelectFriendly(GrowSelection *newShips, GrowSelection *originalShips);
TI_API sdword kasfShipsSelectClass(GrowSelection *newShips, GrowSelection *originalShips, char *shipClass);
TI_API sdword kasfShipsSelectType(GrowSelection *newShips, GrowSelection *originalShips, char *shipType);
TI_API sdword kasfShipsSelectDamaged(GrowSelection *newShips, GrowSelection *originalShips, sdword maxHealthPercent);
TI_API sdword kasfShipsSelectMoving(GrowSelection *newShips, GrowSelection *originalShips);
TI_API sdword kasfShipsSelectCapital(GrowSelection *newShips, GrowSelection *originalShips);
TI_API sdword kasfShipsSelectNonCapital(GrowSelection *newShips, GrowSelection *originalShips);
TI_API sdword kasfShipsSelectNotDocked(GrowSelection *newShips, GrowSelection *originalShips);
TI_API sdword kasfShipsSelectIndex(GrowSelection *newShips, GrowSelection *originalShips, sdword Index);
TI_API sdword kasfShipsSelectNearby(GrowSelection *newShips, GrowSelection *originalShips, hvector *location, sdword distance);

TI_API sdword kasfShipsOrder(GrowSelection *ships);
TI_API sdword kasfShipsOrderAttributes(GrowSelection *ships);

#define kasSpecial_ReturningTechnology  1  //ships are salcapcorvettes returning technology
#define kasSpecial_ShipsDisabled        2  //ships have been disabled (salcapcorvette has locked on)
#define kasSpecial_ShipsAreArmed        3  //ships have arms on them - includes GravWellGenerator as an armed ship
#define kasSpecial_ShipsDefected        4  //ships have defected to the other side
TI_API sdword kasfShipsSelectSpecial(GrowSelection *newShips, GrowSelection *originalShips, sdword SpecialFlag);


TI_API sdword kasfShipsAdd(GrowSelection *shipsA, GrowSelection *shipsB);
TI_API sdword kasfShipsRemove(GrowSelection *shipsA, GrowSelection *shipsB);

TI_API void kasfShipsSetNonRetaliation(GrowSelection *ships);
TI_API void kasfShipsSetRetaliation(GrowSelection *ships);

TI_API void kasfPingAddSingleShip(GrowSelection *ships, char *label);
TI_API void kasfPingAddShips(GrowSelection *ships, char *label);
TI_API void kasfPingAddPoint(hvector *point, char *label);
TI_API void kasfPingRemove(char *label);

TI_API void kasfBuildControl(sdword on);
TI_API void kasfBuildingTeam(struct AITeam *builder);

TI_API void kasfStop(void);

TI_API void kasfKamikaze(GrowSelection *targets);
TI_API void kasfKamikazeEveryone(GrowSelection *targets);

TI_API void kasfPopup(char *text);
TI_API void kasfPopupInteger(char *text, sdword integer);

TI_API void kasfObjectiveCreate(char *label, char *briefText, char *fullText);
TI_API void kasfObjectiveCreateSecondary(char *label, char* briefText, char* fullText);
TI_API void kasfObjectiveSet(char *label, sdword status);
TI_API //void kasfObjectivePopupAll(void);
TI_API sdword kasfObjectiveGet(char *label);
TI_API sdword kasfObjectiveGetAll(void);
TI_API void kasfObjectiveDestroy(char *label);
TI_API void kasfObjectiveDestroyAll(void);

TI_API void kasfSpecialToggle(void);

TI_API void kasfShipsDamage(GrowSelection *ships, sdword points);

TI_API void kasfForceTaskbar(void);

// Tutorial helper functions for kas ------------
TI_API void kasfBuilderRestrictShipTypes(char *shipTypes);
TI_API void kasfBuilderUnrestrictShipTypes(char *shipTypes);
TI_API void kasfBuilderRestrictAll(void);
TI_API void kasfBuilderRestrictNone(void);
TI_API void kasfBuilderCloseIfOpen(void);
TI_API void kasfForceBuildShipType(char *shipType);

TI_API sdword kasfCameraGetAngleDeg(void);
TI_API sdword kasfCameraGetDeclinationDeg(void);
TI_API sdword kasfCameraGetDistance(void);

TI_API sdword kasfSelectNumSelected(void);
TI_API sdword kasfSelectIsSelectionShipType(sdword Index, char *shipType);
TI_API sdword kasfSelectContainsShipTypes(char *shipTypes);
TI_API sdword kasfSelectedShipsInFormation(sdword formation);
TI_API sdword kasfShipsInFormation(GrowSelection *ships, sdword formation);

TI_API void kasfTutSetPointerTargetXY(char *name, sdword x, sdword y);
TI_API void kasfTutSetPointerTargetXYRight(char *name, sdword x, sdword y);
TI_API void kasfTutSetPointerTargetXYBottomRight(char *name, sdword x, sdword y);
TI_API void kasfTutSetPointerTargetXYTaskbar(char *name, sdword x, sdword y);
TI_API void kasfTutSetPointerTargetXYFE(char *name, sdword x, sdword y);
TI_API void kasfTutSetPointerTargetShip(char *name, GrowSelection *ships);
TI_API void kasfTutSetPointerTargetShipSelection(char *name, GrowSelection *ships);
TI_API void kasfTutSetPointerTargetShipHealth(char *name, GrowSelection *ships);
TI_API void kasfTutSetPointerTargetShipGroup(char *name, GrowSelection *ships);
TI_API void kasfTutSetPointerTargetFERegion(char *name, char *pAtomName);
TI_API void kasfTutSetPointerTargetRect(char *name, sdword x0, sdword y0, sdword x1, sdword y1);
TI_API void kasfTutSetPointerTargetAIVolume(char *name, Volume *volume);
TI_API void kasfTutRemovePointer(char *name);
TI_API void kasfTutRemoveAllPointers(void);

TI_API void kasfTutSetTextDisplayBoxGame(sdword x, sdword y, sdword width, sdword height);
TI_API void kasfTutSetTextDisplayBoxFE(sdword x, sdword y, sdword width, sdword height);
TI_API void kasfTutSetTextDisplayBoxToSubtitleRegion(void);
TI_API void kasfTutShowText(char *szText);
TI_API void kasfTutHideText(void);
TI_API void kasfTutShowNextButton(void);
TI_API void kasfTutHideNextButton(void);
TI_API sdword kasfTutNextButtonClicked(void);
TI_API void kasfTutShowBackButton(void);
TI_API void kasfTutHideBackButton(void);
TI_API void kasfTutShowPrevButton(void);
TI_API void kasfTutSaveLesson(sdword Num, char *pName);

TI_API void kasfTutShowImages(char *szImages);
TI_API void kasfTutHideImages(void);

TI_API void kasfTutEnableEverything(void);
TI_API void kasfTutDisableEverything(void);
TI_API void kasfTutEnableFlags(char *pFlags);
TI_API void kasfTutDisableFlags(char *pFlags);
TI_API void kasfTutForceUnpaused(void);

TI_API sdword kasfTutGameSentMessage(char *commandNames);
TI_API void kasfTutResetGameMessageQueue(void);
TI_API sdword kasfTutContextMenuDisplayedForShipType(char *shipType);
TI_API void  kasfTutResetContextMenuShipTypeTest(void);
TI_API void kasfTutRedrawEverything(void);

TI_API sdword kasfBuildManagerShipTypeInBatchQueue(char *shipType);
TI_API sdword kasfBuildManagerShipTypeInBuildQueue(char *shipType);
TI_API sdword kasfBuildManagerShipTypeSelected(char *shipType);

TI_API sdword kasfTutCameraFocusedOnShipType(char *shipTypes);
TI_API void kasfTutCameraFocus(GrowSelection *ships);
TI_API void kasfTutCameraFocusDerelictType(char *derelictType);
TI_API void kasfTutCameraFocusFar(GrowSelection *ships);
TI_API void kasfTutCameraFocusCancel(void);

TI_API void kasfDisablePlayer(bool toggle);

TI_API sdword kasfTutShipsInView(GrowSelection *ships);
TI_API sdword kasfTutShipsTactics(GrowSelection *ships);

TI_API sdword kasfTutPieDistance(void);
TI_API sdword kasfTutPieHeight(void);

TI_API void kasfForceFISensors(void);
TI_API void kasfOpenSensors(sdword flag);
TI_API void kasfCloseSensors(sdword flag);
TI_API sdword kasfSensorsIsOpen(sdword flag);
TI_API void kasfSensorsWeirdness(sdword flag);

TI_API void kasfAllowPlayerToResearch(char *name);
TI_API void kasfAllowPlayerToPurchase(char *name);
TI_API void kasfPlayerAcquiredTechnology(char *name);
TI_API sdword kasfCanPlayerResearch(char *name);
TI_API sdword kasfCanPlayerPurchase(char *name);
TI_API sdword kasfDoesPlayerHave(char *name);
TI_API void kasfSetBaseTechnologyCost(char *name, sdword cost);
TI_API sdword kasfGetBaseTechnologyCost(char *name);
TI_API sdword kasfTechIsResearching(void);

TI_API void kasfEnableTraderGUI(void);
TI_API sdword kasfTraderGUIActive(void);
TI_API void kasfSetTraderDialog(sdword dialogNum, char *text);
TI_API void kasfSetTraderPriceScale(sdword percent);
TI_API sdword kasfGetTraderPriceScale(void);
TI_API void kasfSetTraderDisabled(sdword disable);

TI_API sdword kasfRUsGet(sdword player);
TI_API void kasfRUsSet(sdword player, sdword RUs);

TI_API sdword kasfGetWorldResources(void);

TI_API void kasfSoundEvent(sdword event);
TI_API void kasfSoundEventShips(GrowSelection *ships, sdword event);

TI_API void kasfSpeechEvent(sdword event, sdword variable);
TI_API void kasfSpeechEventShips(GrowSelection *ships, sdword event, sdword variable);

TI_API void kasfToggleActor(sdword Actor, sdword on);

TI_API void kasfMusicPlay(sdword trackNum);
TI_API void kasfMusicStop(sdword fadeTime);

TI_API sdword kasfRenderedShips(GrowSelection *ships, sdword LOD);
TI_API void kasfResetShipRenderFlags(GrowSelection *ships);
TI_API sdword kasfRenderedDerelicts(char *derelictType, sdword LOD);
TI_API void kasfResetDerelictRenderFlags(char *derelicttype);

TI_API udword kasfFindSelectedShips(GrowSelection *ships);

TI_API void kasfSaveLevel(sdword num, char *name);

TI_API void kasfClearScreen(void);

TI_API void kasfWideScreenIn(sdword frames);
TI_API void kasfWideScreenOut(sdword frames);
TI_API void kasfSubtitleSimulate(sdword actor, sdword milliseconds, char *speech);
TI_API void kasfLocationCard(sdword milliseconds, char *location);
TI_API void kasfHideShips(GrowSelection *ships);
TI_API void kasfUnhideShips(GrowSelection *ships);

TI_API void kasfDeleteShips(GrowSelection *ships);

TI_API void kasfRotateDerelictType(char *derelictType, sdword rot_x, sdword rot_y, sdword rot_z, sdword variation);

TI_API sdword kasfRaceOfHuman(void);
TI_API void kasfUniversePause(void);
TI_API void kasfUniverseUnpause(void);
TI_API void kasfPauseBuildShips(void);
TI_API void kasfUnpauseBuildShips(void);
TI_API void kasfOtherKASPause(void);
TI_API void kasfOtherKASUnpause(void);

TI_API sdword kasfIntelEventEnded(void);
TI_API void kasfIntelEventNotEnded(void);
TI_API void kasfForceIntelEventEnded(void);

//turn sensors manager static on/off
TI_API void kasfSensorsStaticOn(void);
TI_API void kasfSensorsStaticOff(void);

//end the game right now and start plugscreens
TI_API void kasfGameEnd(void);

TI_API void kasfSpawnEffect(GrowSelection *ships, char *effectName, sdword parameter);

#endif
