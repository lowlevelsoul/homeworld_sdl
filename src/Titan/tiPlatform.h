
/*
========================================================================================================================
========================================================================================================================
*/

#ifndef _TI_PLATFORM_H_
#define _TI_PLATFORM_H_

#if defined(_WIN32) || defined(_WIN64)
#	include "tiPlatform_win.h"
#elif defined(_APPLE_)
#	include "tiPlatform_apple.h"
#endif

#if defined(__cplusplus) || defined(__cplusplus__)
#	define TI_API extern "C"
#else
#	define TI_API
#endif

#endif