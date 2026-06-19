#ifndef ___KAS_H
#define ___KAS_H

#include "tiPlatform.h"
#include "AIUtilities.h"
#include "ShipSelect.h"
#include "Vector.h"

// run-time scoping for variables, timers, etc.
enum {
    KAS_SCOPE_MISSION,
    KAS_SCOPE_FSM,
    KAS_SCOPE_STATE};

typedef void (*KASInitFunction) (void);
typedef void (*KASWatchFunction) (void);

//  these have corresponding #defines in kas2c.h
#define KAS_MISSION_NAME_MAX_LENGTH 47
#define KAS_FSM_NAME_MAX_LENGTH 47
#define KAS_STATE_NAME_MAX_LENGTH 47

//  user variables for SHIPS
#define KASSELECTION_ALLOC_INCREMENT 16
#define KASSELECTION_MAX_LABEL_LENGTH 47
typedef struct {
    char label[KASSELECTION_MAX_LABEL_LENGTH+1];
    GrowSelection shipList;
} KasSelection;

//
//  labelled entities in mission layout file
//
#define KAS_MAX_LABEL_LENGTH 47
#define KAS_LABELLED_ENTITY_ALLOC_INCREMENT 16
//  team labels are stored in AITeam struct
typedef struct {
    char label[KAS_MAX_LABEL_LENGTH+1];
    Path *path;
} LabelledPath;
typedef struct {
    char label[KAS_MAX_LABEL_LENGTH+1];
    hvector *hvector;
} LabelledVector;
typedef struct {
    char label[KAS_MAX_LABEL_LENGTH+1];
    Volume *volume;
} LabelledVolume;


/*=============================================================================
    Functions
=============================================================================*/
//  to fill in table of labelled mission layout entities
TI_API void kasLabelsInit(void);
TI_API //void kasLabelledAITeamAdd(char *label);
TI_API Path *kasLabelledPathAdd(char *label, sdword numPoints, sdword closed);
TI_API hvector *kasLabelledVectorAdd(char *label, real32 x, real32 y, real32 z,real32 w);
TI_API Volume *kasLabelledVolumeAdd(char *label);

TI_API void kasMissionStart(char *name, KASInitFunction initFunction, KASWatchFunction watchFunction);
TI_API void kasExecute(void);

// keywords of KAS language
TI_API void kasJump(char *stateName, KASInitFunction initFunction, KASWatchFunction watchFunction);
TI_API void kasFSMCreate(char *fsmName, KASInitFunction initFunction, KASWatchFunction watchFunction, struct AITeam *team);

// labels: resolves references from script to mission layout file
struct AITeam *kasAITeamPtr(char *label);
TI_API GrowSelection *kasAITeamShipsPtr(char *label);
TI_API hvector *kasShipsVectorPtr(char *label);
TI_API hvector *kasTeamsVectorPtr(char *label);
TI_API hvector *kasVolumeVectorPtr(char *label);
TI_API hvector *kasThisTeamsVectorPtr(void);
TI_API Path   *kasPathPtr(char *label);
TI_API Path *kasPathPtrNoErrorChecking(char *label);
TI_API Volume *kasVolumePtr(char *label);
TI_API hvector *kasVectorPtr(char *label);
TI_API hvector *kasVectorPtrIfExists(char *label);
TI_API GrowSelection *kasGrowSelectionPtr(char *label);

TI_API GrowSelection *kasGetGrowSelectionPtrIfExists(char *label);

TI_API void kasShipDied(Ship *ship);

TI_API void kasGrowSelectionClear(GrowSelection *ships);

TI_API void kasLabelledEntitiesDestroy(void);

TI_API void kasAddShipToTeam(Ship *ship,char *str);

#define KAS_TEAM_NAME_MAX_LENGTH 47
TI_API char *kasAITeamName(struct AITeam *team, char *teamName);

TI_API void kasTakeADump(void);
TI_API void kasDebugDraw(void);
#define KAS_DEBUG_TEXTCOLOR            colRGB(64, 255, 196)

TI_API void kasTeamDied(struct AITeam *team);

TI_API void kasClose(void);
TI_API void kasInit(void);

// Save Game Stuff
TI_API void kasSave(void);
TI_API void kasLoad(void);
TI_API void *kasConvertOffsetToFuncPtr(sdword offset);
TI_API sdword kasConvertFuncPtrToOffset(void *func);


#endif
