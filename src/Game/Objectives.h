//
//  SINGLE-PLAYER MISSION OBJECTIVES
//

#ifndef ___OBJECTIVES_H
#define ___OBJECTIVES_H

#include "tiPlatform.h"
#include "FEFlow.h"
#include "LinkedList.h"


#define MAX_OBJECTIVE_LABEL_LENGTH 32
#define OBJECTIVES_ALLOC_INITIAL 8
#define OBJECTIVES_ALLOC_INCREMENT 8

typedef struct {
    Node   node;         // Linked list node
    bool8  showOnce;     // Shown and then removed from linked list
    bool8  showNow;      // Internal status of intelligence window (force creating popup)
    char   *description; // Pointer to fleet intelligence text array
}
FleetIntelligence;

typedef struct {
    char label[MAX_OBJECTIVE_LABEL_LENGTH+1];
    char *description;                    // Objectives described once
    FleetIntelligence *fleetIntelligence; // So the task bar knows which window to bring up on double clicking
    sdword status;                        // Complete / Incomplete
    sdword primary;
}
Objective;

extern LinkedList poFleetIntelligence;

TI_API void poPlayerObjectivesBegin(regionhandle region);
TI_API void poClose(char *string, featom *atom);

TI_API void objectiveStartup(void);
TI_API void objectiveShutdown(void);

TI_API void objectiveSave(void);
TI_API void objectiveLoad(void);

// *briefDescription is the text found in the list box under the taskbar
// *fullDescription is the text found in the fleet intelligence window
// The fullDescription pointer can be NULL
// showOnce forces Fleet Intelligence to be drawn once and then deleted
TI_API Objective *objectiveAndFleetIntelligenceCreate(char *label, char *briefDescription, char* fullDescription, bool8 showOnce, bool primary);

// Called independently if you wish to show fleet intelligence only once and right away
TI_API FleetIntelligence *fleetIntelligenceCreate(char *description, bool8 showOnce);

TI_API Objective *objectiveFind(char *label);
TI_API void objectiveSet(char *label, sdword status);
TI_API sdword objectiveGet(char *label);
TI_API sdword objectiveGetAll(void);
TI_API void objectiveDestroyAll(void);
TI_API void objectiveDestroy(char *label);

void objectiveDrawStatus(void); // OBSOLETE
TI_API void objectivePopupAll(void);

TI_API void poPopupFleetIntelligence(Objective* objective);

#endif
