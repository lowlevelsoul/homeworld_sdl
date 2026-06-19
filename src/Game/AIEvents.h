// =============================================================================
//  AIEvents.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
// =============================================================================

#ifndef ___AIEVENTS_H
#define ___AIEVENTS_H

#include "tiPlatform.h"
#include "ShipSelect.h"
#include "SpaceObj.h"

struct AITeam;

//
//  the voids should actual be AITeams, but
//  I seem to have a recursive definition problem
//  then, between AITeam and AIEvents.
//
typedef void (*aieHandlerSimple) (struct AITeam *team);
typedef void (*aieHandlerShip)   (struct AITeam *team, ShipPtr ship);
typedef void (*aieHandlerShips)  (struct AITeam *team, SelectCommand *ships);
typedef void (*aieHandlerInt)    (struct AITeam *team, udword *intvar);

//
//  parameters and handlers for various events that
//  can be watched for during move execution
//
//  the watch* members are essentially parameters on
//  when the event should be fired
//
//  there are function prototypes below for enabling
//  handlers on a particular move.
//
//  default is a NULL handler
//
typedef struct {
    struct {
        bool8               oneShot;
        bool8               triggered;
        aieHandlerShips     handler;
    } gettingRocked;  // team is under attack

    struct {
        real32              watchRadius;
        bool8               oneShot;
        bool8               triggered;
        aieHandlerShips     handler;
    } enemyNearby;  // enemy within certain radius

    struct {
        real32              watchRadius;
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } enemyNotNearby;   // enemy is not (no longer) within certain radius

    struct {
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } firing;  // team has started to fire (usually this will be a one-shot)

    struct {
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } disengage; //team has stopped firing (usually this will be a one-shot)
                    //note this event only gets checked if the firing event has been triggered

    struct {
        sdword              watchPercentage;
        bool8               watchIndividual;
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } healthLow;  // team health drops below certain level

    struct {
        sdword              watchPercentage;
        bool8               watchIndividual;
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } healthHigh;  // team health rises above certain level

    struct {
        sdword              watchPercentage;
        sdword              watchBaseCount; // # of ships
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } numbersLow;  // team size drops below certain # of ships

    struct {
        sdword              watchPercentage;
        sdword              watchBaseCount; // # of ships
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } numbersHigh;  // team size rises above certain # of ships

    struct {
        sdword              watchPercentage;
        bool8               watchIndividual;
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } fuelLow;  // team fuel drops below certain level

    struct {
        sdword              watchPercentage;
        bool8               watchIndividual;
        bool8               oneShot;
        bool8               triggered;
        aieHandlerSimple    handler;
    } fuelHigh;  // team fuel rises above certain level

    struct {
        bool8               oneShot;
        bool8               triggered;
        aieHandlerShip      handler;
    } shipDied;  // team member dies

    struct {
        aieHandlerSimple    handler;
    } teamDied;  // last team member dies

    struct {
        bool8               oneShot;
        bool8               triggered;
        udword              interval;       //how often to skip this event before triggering
        udword              intervalcnt;    //counter to keep track of skips
        udword              *intvar;
        aieHandlerInt       handler;
    } interrupt;

} AIEvents;

TI_API sdword aieCheckGettingRocked(struct AITeam *team, SelectCommand **ships);
TI_API sdword aieCheckEnemyNearby(struct AITeam *team, SelectCommand **ships);
TI_API sdword aieCheckEnemyNotNearby(struct AITeam *team);
TI_API sdword aieCheckFiring(struct AITeam *team);
TI_API sdword aieCheckDisengage(struct AITeam *team);
TI_API sdword aieCheckHealthLow(struct AITeam *team);
TI_API sdword aieCheckHealthHigh(struct AITeam *team);
TI_API sdword aieCheckNumbersLow(struct AITeam *team);
TI_API sdword aieCheckNumbersHigh(struct AITeam *team);
TI_API sdword aieCheckFuelLow(struct AITeam *team);
TI_API sdword aieCheckFuelHigh(struct AITeam *team);
TI_API sdword aieCheckShipDied(void);
TI_API sdword aieCheckTeamDied(struct AITeam *team);
TI_API sdword aieCheckInterrupt(struct AITeam *team);

struct AITeamMove;

TI_API void aieHandlerSetGettingRocked (struct AITeamMove *move, bool8 oneShot, aieHandlerShips handler);
TI_API void aieHandlerSetEnemyNearby(struct AITeamMove *move, real32 watchRadius, bool8 oneShot, aieHandlerShips handler);
TI_API void aieHandlerSetEnemyNotNearby(struct AITeamMove *move, real32 watchRadius, bool8 oneShot, aieHandlerSimple hander);
TI_API void aieHandlerSetFiring(struct AITeamMove *move, bool8 oneShot, aieHandlerSimple handler);
TI_API void aieHandlerSetDisengage(struct AITeamMove *move, bool8 oneShot, aieHandlerSimple handler);
TI_API void aieHandlerSetHealthLow(struct AITeamMove *move, sdword watchPrecentage, bool8 watchIndividual, bool8 oneShot, aieHandlerSimple handler);
TI_API void aieHandlerSetHealthHigh (struct AITeamMove *move, sdword watchPercentage, bool8 watchIndividual, bool8 oneShot, aieHandlerSimple handler);
//note: if watchBaseCount in "SetNumbersLow/High" is 0, the initial value will be set
//      using the number of ships in the team the first time the event is checked
TI_API void aieHandlerSetNumbersLow(struct AITeamMove *move, sdword watchPercentage, sdword watchBaseCount, bool8 oneShot, aieHandlerSimple handler);
TI_API void aieHandlerSetNumbersHigh (struct AITeamMove *move, sdword watchPercentage, sdword watchBaseCount, bool8 oneShot, aieHandlerSimple handler);
TI_API void aieHandlerSetFuelLow(struct AITeamMove *move, sdword watchPercentage, bool8 watchIndividual, bool8 oneShot, aieHandlerSimple handler);
TI_API void aieHandlerSetFuelHigh(struct AITeamMove *move, sdword watchPercentage, bool8 watchIndividual, bool8 oneShot, aieHandlerSimple handler);
TI_API void aieHandlerSetShipDied(struct AITeamMove *move, bool8 oneShot, aieHandlerShip handler);
TI_API void aieHandlerSetTeamDied(struct AITeamMove *move, aieHandlerSimple handler);
TI_API void aieHandlerSetInterrupt(struct AITeamMove *move, udword *intvar, udword interval, bool8 oneShot, aieHandlerInt handler);

TI_API void aieHandlersClear (struct AITeamMove *move);

TI_API void aieExecute(struct AITeam *team);

// SaveGame Stuff
TI_API void aieFixAIEvents(struct AITeamMove *move);
TI_API void aiePreFixAIEvents(struct AITeamMove *move);

TI_API aieHandlerSimple aieNumToHandler(sdword num);
TI_API sdword aieHandlerToNum(aieHandlerSimple handler);

#endif
