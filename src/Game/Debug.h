// =============================================================================
//  Debug.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created June 1997 by Luke Moloney
// =============================================================================

#ifndef ___DEBUG_H
#define ___DEBUG_H

#include "tiPlatform.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------

#ifdef HW_BUILD_FOR_DEBUGGING
    #define DBG_ASSERT                 1   // assertion checking
    #define DBG_FILE_LINE              1   // print file and line
    #define DBG_STACK_CONTEXT          1   // dump stack context at fatal error time
#else
    #define DBG_ASSERT                 0
    #define DBG_FILE_LINE              0
    #define DBG_STACK_CONTEXT          0
#endif


#if DBG_FILE_LINE
    #define DBG_Loc  __FILE__, __LINE__
#else
    #define DBG_Loc  NULL, 0
#endif


#if DBG_ASSERT
    #define dbgAssertOrIgnore(expr) if (!(expr)) { dbgFatalf(DBG_Loc, "Assertion of (%s) failed.", #expr); }
    #define dbgAssertAlwaysDo(expr) dbgAssertOrIgnore(expr)
#else
    #define dbgAssertOrIgnore(expr) ((void)0)
    #define dbgAssertAlwaysDo(expr) (expr)
#endif


// maximum length of a single string for format printing
#define DBG_BufferLength        2048
#define DBG_BufferMax           (DBG_BufferLength - 1)


#if DBG_STACK_CONTEXT
    extern udword dbgStackBase;
#endif

extern sdword dbgAllowInterrupts;

TI_API void dbgMessage  ( const char *string     );
TI_API void dbgMessagef ( const char *format, ...);

TI_API void dbgWarning  ( const char *file, sdword line, const char * string      );
TI_API void dbgWarningf ( const char *file, sdword line, const char * format, ... );

TI_API void dbgFatal    ( const char *file, sdword line, const char * string      );
TI_API void dbgFatalf   ( const char *file, sdword line, const char * format, ... );

TI_API void dbgNonFatal ( const char *file, sdword line, const char * string      );
TI_API void dbgNonFatalf( const char *file, sdword line, const char * format, ... );

#endif
