// =============================================================================
//  AIUtilities.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 6/1/1998 by fpoiker
// =============================================================================

#ifndef ___AIUTILITIES_H
#define ___AIUTILITIES_H

#include "tiPlatform.h"
#include "Blobs.h"
#include "ShipSelect.h"
#include "SpaceObj.h"
#include "Universe.h"
#include "Volume.h"

bool_t ShipAlreadyHyperspaceOut(Ship *ship);      // don't include singleplayer.h, just this

/*=============================================================================
    Macros:
=============================================================================*/
#define aiumemFree(x)                   if ((x) != NULL) {memFree((x));(x) = NULL;}
#define sizeof_blob_array(x)            sizeof(blob_array) + ((x) - 1) * sizeof(blob *)
#define sizeof_aiblob_array(x)          sizeof(aiblob_array) + ((x) - 1) * sizeof(aiblob *)
#define sizeof_Path(x)                  sizeof(Path) + ((x) - 1) * sizeof(vector)
#define aiuShipIsHidden(x)              bitTest((x)->flags, SOF_Hide)
#define aiuShipIsntSelectable(x)        (bitTest((x)->flags, SOF_Hide|SOF_Disabled|SOF_Crazy) || ShipAlreadyHyperspaceOut(x))
#define aiuShipIsntTargetable(x,player) (bitTest((x)->flags, SOF_Hide|SOF_Hyperspace) || \
                                         ((bitTest((x)->flags, SOF_Cloaked) && (!proximityCanPlayerSeeShip((player), (x))))))

#define aiuShipIsWorthCapturing(x)      ((!isShipOfClass(x, CLASS_Fighter)) && (!isShipOfClass(x, CLASS_Corvette)))

#define num_is_odd(x)                   ((x) & 0x1)

#define blob_to_aiblob(blob, aiblob)    (aiblob)->centre    = (blob)->centre; \
                                        (aiblob)->radius    = (blob)->radius; \
                                        (aiblob)->blobShips = (blob)->blobShips;\
                                        (aiblob)->primaryenemystrength = 0; \
                                        (aiblob)->primaryenemyvalue    = 0; \
                                        (aiblob)->otherenemystrength   = 0; \
                                        (aiblob)->otherenemyvalue      = 0; \
                                        (aiblob)->goodGuystrength      = 0; \
                                        (aiblob)->goodGuyvalue         = 0;

#define aiuFuelAbove(ship, level)       ((100.0 * ((ship)->fuel/(ship)->staticinfo->maxfuel)) > (level))
#define aiuHealthAbove(ship, level)     ((100.0 * ((ship)->health*(ship)->staticinfo->oneOverMaxHealth)) > (level))

#define aiuNewSelection(sel, size, string)  \
                                        (sel) = (SelectCommand *)memAlloc(sizeofSelectCommand((size)), (string), 0);\
                                        (sel)->numShips = 0;
#define aiuNewPyroSelection(sel, size, string)  \
                                        (sel) = (SelectCommand *)memAlloc(sizeofSelectCommand((size)), (string), Pyrophoric);\
                                        (sel)->numShips = 0;


#define aiuRandomRange(prob, range)     randyrandombetween(RANDOM_AI_PLAYER, ((prob)-(range)), ((prob)+(range)))

#define aiuGameTimePassed(time)         (universe.totaltimeelapsed > (time))

#define aiuEnableResourceFeature(x)     (bitSet(aiplayer->ResourceFeatures, (x)))
#define aiuEnableAttackFeature(x)       (bitSet(aiplayer->AttackFeatures, (x)))
#define aiuEnableDefenseFeature(x)      (bitSet(aiplayer->DefenseFeatures, (x)))
#define aiuEnableTeamFeature(team, x)   (bitSet((team)->TeamFeatures, (x)))
#define aiuDisableResourceFeature(x)     (bitClear(aiplayer->ResourceFeatures, (x)))
#define aiuDisableAttackFeature(x)       (bitClear(aiplayer->AttackFeatures, (x)))
#define aiuDisableDefenseFeature(x)      (bitClear(aiplayer->DefenseFeatures, (x)))
#define aiuDisableTeamFeature(team, x)   (bitSet((team)->TeamFeatures, (x)))
#define aiuResourceFeatureEnabled(x)    (bitTest(aiCurrentAIPlayer->ResourceFeatures, (x)))
#define aiuAttackFeatureEnabled(x)      (bitTest(aiCurrentAIPlayer->AttackFeatures, (x)))
#define aiuDefenseFeatureEnabled(x)     (bitTest(aiCurrentAIPlayer->DefenseFeatures, (x)))
#define aiuTeamFeatureEnabled(team, x)  (bitTest((team)->TeamFeatures, (x)))

/*=============================================================================
    Constant Definitions:
=============================================================================*/
//#define NUM_FAST_PATROL_PATHPOINTS  4
#define FASTPATROL_STANDOFFDIST     2500

//flags for random standoff points
#define RSP_NORMAL      0
#define RSP_NEAR        1
#define RSP_FAR         2

//vulnerable ships flags
#define ALL_VULNERABLE_SHIPS    0
#define LARGE_VULNERABLE_SHIPS  1


#define ORIGIN_VECTOR {0,0,0}

/*=============================================================================
    Structures:
=============================================================================*/
typedef struct Path
{
    udword numPoints;
    bool_t   closed;
    vector point[1];
} Path;


/*=============================================================================
    Utility Functions:
=============================================================================*/
/*-----------------------------------------------------------------------------
    Coordinate and Vector Utility Functions:
-----------------------------------------------------------------------------*/
//generates a random vector
TI_API vector aiuGenerateRandomVector(void);

//generates a random standoff point
TI_API vector aiuGenerateRandomStandoffPoint(vector center, real32 radius, vector origin, udword flags);

//generates coordinates for a flank attack
TI_API vector aiuGenerateFlankCoordinates(vector center, vector origin, vector referencevec, real32 radius);

//finds the square of the distance between two points
TI_API real32 aiuFindDistanceSquared(vector point1, vector point2);

//finds a point that is within a range of a given destination
TI_API vector aiuFindRangeStandoffPoint(vector destination, vector location, real32 range);

//creates a path struct with every point at (-REALlyBig, -REALlyBig, -REALlyBig)
TI_API Path *aiuCreatePathStruct(udword numPoints, bool_t closed);

// allocates memory for and returns a new path (a perfect copy of the existing path)
TI_API Path *aiuPathDupe(Path *existing);

//adds a point to a path
TI_API void aiuAddPointToPath(vector point, udword pointnum, Path *path);

TI_API Path *aiuGenerateCircularPath(udword num_points, vector center, real32 radius, bool_t closed);

/*-----------------------------------------------------------------------------
    General Utility Functions:
-----------------------------------------------------------------------------*/
TI_API void aiuMoveShipSelection(MaxSelection *dest, MaxSelection *source, udword num);

/*-----------------------------------------------------------------------------
    Ship Related Utility Functions:
-----------------------------------------------------------------------------*/
struct AITeam;

//rescues (reinforces) a certain ship
TI_API bool_t aiuRescueShip(ShipPtr ship, struct AITeam *team);

//rescues (reinforces) a certain shiptype within the selection
TI_API ShipPtr aiuRescueShipType(SelectCommand *selection, struct AITeam *team, ShipType type);

//takes out a specific ship
TI_API bool_t aiuTakeoutShip(ShipPtr ship, struct AITeam *team);

//takes out a shiptype within a selection
TI_API ShipPtr aiuTakeoutShipType(SelectCommand *selection, struct AITeam *team, ShipType type);

//finds out if the ships are no longer attacking
TI_API bool_t aiuShipsNoLongerAttacking(SelectCommand *selection);

//finds out if the ship is an enemy mothership
TI_API bool_t aiuShipIsAnEnemyMothership(Ship *ship);

//finds out if a ship is not an enemy mothership
TI_API bool_t aiuShipIsntAnEnemyMothership(Ship *ship);

//finds out if any of the selection of ships is a capital ship
TI_API bool_t aiuAnyShipsAreCapitalShips(SelectCommand *ships);

//finds out if the ship is a fighter
TI_API bool_t aiuShipIsFighter(Ship *ship);

//finds out if the ship are not good against fighters
TI_API bool_t aiuShipNotGoodAgainstFighters(Ship *ship);

//function name pretty self explanatory
TI_API bool_t aiuSelectionNotGoodAtKillingTheseTargets(SelectCommand *selection, SelectCommand *targets, real32 strengthratio);

//finds out if any of the selection of ships is hidden
TI_API bool_t aiuShipsAreHidden(SelectCommand *selection);

//filters out any ship that is disabled
TI_API udword aiuFilterDisabledShips(SelectCommand *selection, MaxSelection *filtered);

//filters out any ship that isn't selectable
TI_API udword aiuFilterSelectableShips(SelectCommand *selection, MaxSelection *filtered);

//tells whether any of the selection of ships isn't targetable
TI_API bool_t aiuShipsArentTargetable(SelectCommand *selection);

//returns TRUE if ship is a dangerous ship
TI_API bool_t aiuIsShipDangerous(Ship *ship);

//returns TRUE if the ship is a primary enemy
TI_API bool_t aiuIsShipPrimaryEnemy(Ship *ship);

TI_API void aiuRateShip(udword *strength, udword *value, ShipPtr ship);

//Returns the enemy ships found in the mothership blob
TI_API SelectCommand *aiuEnemyShipsInMothershipBlob(void);

//finds the nearest enemy ship in the mothership blob
TI_API ShipPtr aiuFindNearestMothershipAttacker(SelectCommand *teamShips);

//returns the player's mothership coordinates
TI_API vector aiuPlayerMothershipCoords(Player *player);

// Returns the enemy mothership of player
TI_API Ship *aiuFindEnemyMothership(Player *player);

// eliminates ships that aren't dangerous to the mothership from the selection
TI_API void aiuMakeShipsOnlyDangerousToMothership(SelectCommand *enemyships);

//finds the coordinates of the enemy mothership
TI_API vector aiuFindEnemyMothershipCoords(Player *player);

//returns TRUE if ships are less than dist away from the current players' enemy mothership
TI_API bool_t aiuShipsCloseToEnemyMothership(Player *player, SelectCommand *ships, real32 dist);

//finds the safest point a given distance away from the center of the
//selected ships
TI_API vector aiuFindSafestStandoffPoint(SelectCommand *ships, real32 distance);

//generates a patrol path for fast ships
TI_API Path *aiuGeneratePatrolPath(udword patroltype);

//finds all the unarmed undefended enemy ships
TI_API SelectCommand *aiuFindUnarmedUndefendedEnemyShips(void);

//finds all the unarmed enemy ships
TI_API SelectCommand *aiuFindUnarmedEnemyShips(void);

//finds the best volume to mine
TI_API Volume *aiuFindBestVolumeToMine(SelectCommand *selection);

//finds all of a player's resource collectors
TI_API SelectCommand *aiuFindResourceCollectors(void);

//finds an ideal place for the resource controller to go
TI_API vector aiuFindResourceControllerDestination(void);

//makes sure no other mothership is moving towards or near this destination
TI_API bool_t aiuDestinationNotNearOtherMothership(vector destination, real32 radiussq);

//finds the slowest ship in the selection
TI_API real32 aiuFindSlowestShipMaxSpeed(SelectCommand *ships);

//returns the ship in the selection that is closest to "ship"
TI_API ShipPtr aiuGetClosestShip(SelectCommand *selection, ShipPtr ship);

//finds a small selection of unarmed or lightly armed good guy ships
TI_API SelectCommand *aiuFindClosestVulnerableGoodGuyShips(ShipPtr ship, udword type);

//weeds out ships that are farther away from a reference point than a specified point
TI_API SelectCommand *aiuRejectShipsPastLocation(SelectCommand *selection, vector reference, vector location);

//finds the closest unarmed undefended enemy ship
TI_API ShipPtr aiuFindClosestUnarmedUndefendedEnemyShip(ShipPtr ship);

//finds the best unarmed enemy ship
TI_API ShipPtr aiuFindBestUnarmedEnemyShip(SelectCommand *teamShips, real32 range);

//finds dangerous enemy ships close to primarytarget
TI_API SelectCommand *aiuFindNearbyDangerousEnemyShips(Ship *primarytarget,real32 range);

//makes targets only be primary enemy ships
TI_API void aiuMakeShipsOnlyPrimaryEnemyShips(SelectCommand *selection);

//finds the ships attacking "ship"
TI_API SelectCommand *aiuFindAttackingShips(ShipPtr ship);

//finds enemy ships close to primarytarget
TI_API SelectCommand *aiuFindNearbyEnemyShips(Ship *primarytarget,real32 range);

//finds the most likely enemy target to harass
TI_API ShipPtr aiuFindHarassTarget(SelectCommand *teamShips);

//finds the juiciest target for capturing
//note: SelectCommand structure not used as normal, see function comments
TI_API SelectCommand *aiuFindCaptureTarget(SelectCommand *capturingShips);

//finds the nearest target from the aiCurrentAIPlayer->Targets list
TI_API SelectCommand *aiuFindSwarmerTarget(struct AITeam *team);

//finds targets for the P2 swarmers
TI_API SelectCommand *aiuFindSwarmTargets(SelectCommand *teamShips, udword numTargets, bool_t harass);

//finds out if a point is within the sphere of influence
TI_API bool_t aiuPointWithinSphereOfInfluence(vector point);

//finds one ship in a group of ships within the computer player's sphere of influence
TI_API SelectCommand *aiuFindLeadShipInSphereOfInfluence(vector centre, real32 radiussq);

//finds standoff points to the next nearest blob (going outwards from or inwards towards the source from the holder)
TI_API vector aiuFindStandoffOfNextNearestBlobOut(ShipPtr source, ShipPtr holder);
TI_API vector aiuFindStandoffOfNextNearestBlobIn(ShipPtr source, ShipPtr holder);
TI_API vector aiuFindStandoffOfNextNearestEnemyBlobOut(ShipPtr source, ShipPtr holder);
TI_API vector aiuFindStandoffOfNextNearestEnemyBlobIn(ShipPtr source, ShipPtr holder);

//returns all the resources in a particular volume
TI_API ResourceSelection *aiuFindResourcesInVolume(Volume volume);

//returns true if resourcer is busy
TI_API bool_t aiuShipIsResourcingOrSomething(ShipPtr ship);

//returns the best resource for the ship to harvest
TI_API Resource *aiuFindBestResource(Resource **biggetsResource, ShipPtr ship, ResourceSelection *resources);

//returns a rating for a blob w.r.t resourcing
TI_API real32 aiuRateBlobForResourcing(blob *thisBlob);

//finds the best blob to collect resources
TI_API bool_t aiuFindBestResourceBlob(vector *destination);

//finds the nearest resource blob
TI_API blob *aiuFindNearestResourceBlob(SelectCommand *ships);

//find the aiblob the ship is in
//returns NULL if the ships are not in the same blob if retentive == TRUE
struct aiblob *aiuFindShipsAIBlob(SelectCommand *ships, bool_t retentive);

//same as above, but for one ship (doesn't return NULL)
struct aiblob *aiuFindShipAIBlob(ShipPtr ship);

//returns TRUE if the enemy ship is visible
TI_API bool_t aiuEnemyShipIsVisible(ShipPtr ship);

//returns the smallest gun range distance among the armed ships in "ships"
//    Note: This function scales the minimum gun ranges to work better
//          with the move attack command
TI_API real32 aiuFindMinimumGunRangeSquared(SelectCommand *ships);

//returns TRUE if the ships in selection 1 are in gun range of their attack targets
TI_API bool_t aiuShipsInGunRangeOfTargets(SelectCommand *selection1);

//returns the number of ships an aiplayer can build according to unit caps
TI_API udword aiuUnitCapCanBuildShip(struct AIPlayer *aiplayer, ShipType shiptype, sdword numShips);

/*-----------------------------------------------------------------------------
    Armada Functions:
-----------------------------------------------------------------------------*/
TI_API bool_t aiuFindArmadaTarget(vector *dest, SelectCommand **sel_target, SelectCommand *team_ships);

/*-----------------------------------------------------------------------------
    Wrap Functions:
-----------------------------------------------------------------------------*/
//computer player wrap of the attack command
TI_API SelectCommand *aiuAttack(struct AITeam *team, SelectCommand *targets);

//splits the attackers into smaller groups.  Recommended for strikecraft vs strikecraft battles only
TI_API void aiuSplitAttack(SelectCommand *attackers, SelectCommand *targets);

//special swarm dock command
TI_API void aiuSwarmDock(SelectCommand *ships, SelectCommand *Pods);

TI_API bool_t aiuWrapAttack(SelectCommand *attackers, SelectCommand *targets);
TI_API bool_t aiuWrapMove(SelectCommand *ships, vector destination);
TI_API bool_t aiuWrapDock(SelectCommand *ships, DockType docktype, ShipPtr dockwith);
TI_API bool_t aiuWrapFormation(SelectCommand *ships, TypeOfFormation formation);
TI_API bool_t aiuWrapProtect(SelectCommand *ships, SelectCommand *shipstoguard);
TI_API bool_t aiuWrapSpecial(SelectCommand *ships, SelectCommand *targets);
TI_API bool_t aiuWrapCollectResource(SelectCommand *ships, ResourcePtr resource);
TI_API bool_t aiuWrapSetTactics(SelectCommand *ships, TacticsType tactics);
TI_API bool_t aiuWrapHalt(SelectCommand *ships);
TI_API bool_t aiuWrapScuttle(SelectCommand *ships);
TI_API bool_t aiuWrapSetKamikaze(SelectCommand *ships);

// like aiuWrapFormation, except doesn't filter out hidden ships
TI_API bool_t aiuKasWrapFormation(SelectCommand *ships, TypeOfFormation formation);

//gets the collision blob of the selection of ships
TI_API blob *aiuWrapGetCollBlob(SelectCommand *ships);

/*-----------------------------------------------------------------------------
    Enemy Stats Utility Functions:
-----------------------------------------------------------------------------*/
//makes changes in the aiplayer structure if the primary enemy changes
TI_API void aiuChangePrimaryEnemy(struct AIPlayer *aiplayer);

//finds cloak capable ships in the gathered enemy statistics
TI_API bool_t aiuFindCloakersInEnemyShipsIAmAwareOf(bool_t Red_Alert);


/*-----------------------------------------------------------------------------
    Blob Utility Functions:
-----------------------------------------------------------------------------*/
//returns the number of enemy blobs
TI_API udword aiuGetNumEnemyBlobs(void);

//fills the EnemyShipsIAmAwareOf arrays in the aiplayer struct
TI_API void aiuUpdateKnowledgeOfEnemyShips(struct AIPlayer *aiplayer);

//creates two arrays of pointers to the blobs containing enemy ship
//and the good guy ships
TI_API void aiuCreateBlobArrays(Player *player);

//deletes the two blob arrays
TI_API void aiuDeleteBlobArrays(void);

// Returns TRUE if current AI player can build ships of shiptype
TI_API bool_t aiuCanBuildShipType(ShipType shiptype,bool_t scriptteam);

// Returns TRUE if current AI player already has num ships of shiptype
TI_API bool_t aiuAlreadyHasShipType(ShipType shiptype, udword num);

#endif
