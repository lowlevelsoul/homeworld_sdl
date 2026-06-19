// =============================================================================
//  StringSupport.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 5/7/1998 by ddunlop
// =============================================================================

#ifndef ___STRINGSUPPORT_H
#define ___STRINGSUPPORT_H

// try not to include too many files in here since StringSupport.h may be included
// by jpeg files, etc.

#include "tiPlatform.h"
#include "StringsOnly.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------

typedef enum
{
    languageEnglish,
    languageFrench,
    languageGerman,
    languageSpanish,
    languageItalian
} strLanguageType;

extern udword strCurLanguage;
extern udword strCurKeyboardLanguage;

TI_API bool8 strLoadLanguage(strLanguageType language);
TI_API bool8 strFreeLanguage(void);
TI_API void  strSetStringCB(char *directory, char *field, void *dataToFillIn);
TI_API strGamesMessages strNameToEnum(char *string);
TI_API void strSetCurKeyboard(void);

#endif
