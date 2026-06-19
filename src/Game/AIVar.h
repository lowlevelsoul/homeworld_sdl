// =============================================================================
//  AIVar.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
// =============================================================================

#ifndef ___AIVAR_H
#define ___AIVAR_H

#include "tiPlatform.h"
#include "Types.h"


// INTERFACE -------------------------------------------------------------------

#define AIVAR_LABEL_MAX_LENGTH 47

typedef struct AIVar
{
    sdword value;
    char label[AIVAR_LABEL_MAX_LENGTH+1];
} AIVar;

TI_API void aivarStartup(void);
TI_API void aivarShutdown(void);
TI_API AIVar *aivarCreate(char *label);
TI_API AIVar *aivarFind(char *label);
TI_API AIVar *aivarFindAnyFSM(char *label);
TI_API char *aivarLabelGenerate(char *label);
TI_API char *aivarLabelGet(AIVar *var);
TI_API void aivarLabelSet(AIVar *var, char *label);
TI_API void aivarDestroy(AIVar *var);
TI_API void aivarDestroyAll(void);
TI_API void aivarValueSet(AIVar *var, sdword value);
TI_API sdword aivarValueGet(AIVar *var);
TI_API void aivarSave(void);
TI_API void aivarLoad(void);
TI_API sdword AIVarToNumber(AIVar *aivar);
TI_API AIVar *NumberToAIVar(sdword number);

extern AIVar *aivRenderMainScreen;

#endif
