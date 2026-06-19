
#ifndef ___FORMATION_H
#define ___FORMATION_H

#include "tiPlatform.h"
#include "FormationDefs.h"
#include "ShipSelect.h"
#include "SpaceObj.h"

/*=============================================================================
    Defines:
=============================================================================*/

#define DEBUG_FORMATIONS 0

#define MIN_SHIPS_IN_FORMATION 2
#define ABSOLUTE_MIN_SHIPS_IN_FORMATION 1

#define FORMATION_SORT_BIGGEST_THEN_CLOSEST 1

/*=============================================================================
    Types:
=============================================================================*/

// specific types for sphere formation

typedef struct
{
    real32 cosdeclination;
    real32 sindeclination;
    sdword numAnglePoints;
    real32 cosrotang;
    real32 sinrotang;
} SphereDeclination;

typedef struct
{
    sdword numShipsCanHandle;
    sdword numDeclinations;
    SphereDeclination sphereDeclinations[1];
} SphereTableEntry;

typedef struct SphereStaticInfo
{
    sdword numTableEntries;
    SphereTableEntry *sphereTableEntryPtrs[1];
} SphereStaticInfo;

// general formation types

// changed to defines for speech tool (in FormationDefs.h)
typedef udword TypeOfFormation;

typedef struct
{
    TypeOfFormation formationtype;
    bool formationLocked;            //flag indicating status of formation
    matrix coordsys;
    //fix later to make these bit masks
    sdword tacticalState;            //loose or tight
    real32 tacticsUpdate;            //time formation was updated..so it is only updated once per univupdate
    bool flipselectionfixed;        //flag to indicate a certain state of the formation
    bool needFix;                   //another state flag for formation
    bool enders;                    //flag set if formation has been 'modified' to include target at center...should fix later and put in sphere specifics
    real32 travelvel;               // formation's travel velocity
    real32 percentmaxspeed;         // how much error is in formation positioning
    bool16 flagTravelSlowestShip;
    bool16 doneInitialAttack;
    udword sortorder;
    //for the tactical overlay
    bool pulse;
    sdword flipState;               //variable used to determine that flipped state of the formation <if it has been flipped or not during a combat turnaround>
    void *formationSpecificInfo;    // if you use this, first sdword of custom structure should be size of structure
//    bool formAroundProtectedShip;
} FormationCommand;

/*=============================================================================
    Stuff for Military parade
=============================================================================*/

typedef struct
{
    ShipPtr ship;
} Subslot;

typedef struct
{
    sdword highestSlotUsed;
    sdword numSubslots;
    Subslot subslots[1];
} MilitarySlot;

#define sizeofMilitarySlot(n) (sizeof(MilitarySlot) + sizeof(Subslot)*((n)-1))

#define SLOT_Fighter0               0
#define SLOT_Fighter1               1
#define SLOT_Fighter2               2
#define SLOT_Fighter3               3
#define SLOT_Fighter4               4
#define SLOT_Fighter5               5
#define SLOT_Corvette0              6
#define SLOT_Corvette1              7
#define SLOT_Corvette2              8
#define SLOT_Corvette3              9
#define SLOT_Frigate                10
#define SLOT_ResCollector           11
#define SLOT_ResourceController     12
#define SLOT_Destroyer              13
#define SLOT_HeavyCruiser           14
#define SLOT_NonCombat              15
#define SLOT_Carrier                16
#define SLOT_SupportCorvette        17
#define SLOT_SensorArray            18
#define SLOT_ResearchShip           19
#define SLOT_P1Fighter              20
#define SLOT_P1IonArrayFrigate      21
#define SLOT_P1MissileCorvette      22
#define SLOT_P1StandardCorvette     23
#define SLOT_P2Swarmer0             24
#define SLOT_P2Swarmer1             25
#define SLOT_P2Swarmer2             26
#define SLOT_P2Swarmer3             27
#define SLOT_P2AdvanceSwarmer0      28
#define SLOT_P2AdvanceSwarmer1      29
#define SLOT_P2AdvanceSwarmer2      30
#define SLOT_P2AdvanceSwarmer3      31
#define SLOT_P2FuelPod0             32
#define SLOT_P2FuelPod1             33
#define SLOT_P2FuelPod2             34
#define SLOT_P2FuelPod3             35
#define SLOT_P2MultiBeamFrigate0    36
#define SLOT_P2MultiBeamFrigate1    37
#define SLOT_P2MultiBeamFrigate2    38
#define SLOT_P2MultiBeamFrigate3    39
#define SLOT_Misc                   40
#define MAX_MILITARY_SLOTS          41

typedef struct
{
    Ship *aroundShip;
    sdword paradeType;
    MilitarySlot *militarySlots[MAX_MILITARY_SLOTS];
} MilitaryParadeCommand;

struct CommandLayer;

struct CommandToDo *CreateMilitaryGroupAroundShip(struct CommandLayer *comlayer,ShipPtr ship,ShipPtr aroundShip);
TI_API void processMilitaryParadeToDo(struct CommandToDo *command,bool passiveAttacked);
TI_API void AddShipToMilitaryGroup(ShipPtr ship,struct CommandToDo *militaryGroup);
TI_API void RemoveShipFromMilitaryParade(Ship *shiptoremove,MilitaryParadeCommand *militaryParade);
TI_API void FreeMilitaryParadeContents(MilitaryParadeCommand *militaryParade);
TI_API void setMilitaryParade(struct CommandToDo *command);
TI_API bool shipInMilitaryParade(ShipPtr ship);
TI_API void paradeSetTweakables(void);

/*=============================================================================
    Macros:
=============================================================================*/

#define sizeofFormationSphereInfo(n) (sizeof(FormationSphereInfo) + sizeof(SphereVar)*((n)-1))
#define sizeofSphereStaticInfo(n) (sizeof(SphereStaticInfo) + sizeof(SphereTableEntry *)*((n)-1))
#define sizeofSphereTableEntry(n) (sizeof(SphereTableEntry) + sizeof(SphereDeclination)*((n)-1))

/*=============================================================================
    Functions:
=============================================================================*/

// routines for converting between string and enumeration for TypeOfFormation
TI_API char *TypeOfFormationToStr(TypeOfFormation formation);
TI_API TypeOfFormation StrToTypeOfFormation(char *str);

TI_API char *TypeOfFormationToNiceStr(TypeOfFormation formation);
TI_API TypeOfFormation NiceStrToTypeOfFormation(char *str);

TI_API void formationContentHasChanged(struct CommandToDo *command);
TI_API void formationTypeHasChanged(struct CommandToDo *command);
TI_API void formationArrangeOptimum(struct CommandToDo *formationtodo);
TI_API void processFormationToDo(struct CommandToDo *formationtodo,bool steadyFormation,bool passiveAttacked);
TI_API void setFormationToDo(struct CommandToDo *formationtodo);

TI_API void freeSphereStaticInfo(struct SphereStaticInfo *sphereStaticInfo);
struct SphereStaticInfo *createSphereStaticInfo(void);

TI_API void formationWingmanTrackLeader(struct Ship *ship,struct Ship *leader,bool rotate);

TI_API void FillInShipFormationStuff(Ship *ship,struct CommandToDo *formationcommand);

//formation locking variables
TI_API void lockFormation(struct CommandToDo *formationcommand,udword specialEffect);
TI_API void unlockFormation(struct CommandToDo *formationcommand);

//function that recalculates a formations minimum travel velocity...
TI_API void setFormationTravelVelocity(struct CommandToDo *formationCommand);

TI_API void FormationCalculateOffsets(struct CommandToDo *formationtodo);

// returns the selection's velocity at which it can all travel, scaled by scalevel
TI_API real32 GetShipsTravelVel(SelectCommand *selection,real32 scalevel);

// returns -1 if not found, ship index if found
TI_API sdword formationRemoveShipFromSelection(struct CommandToDo *formationtodo,Ship *removeship);

/*=============================================================================
    Data:
=============================================================================*/

extern udword formationSortType[NO_FORMATION];
extern real32 STRIKECRAFT_PADDING_MODIFIER;

#endif
