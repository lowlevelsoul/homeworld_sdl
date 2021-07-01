// =============================================================================
//  standard_library.h
// =============================================================================
//  It may be called the "Standard Library" but that's not to say it's in a
//  standard location or file on a particular platform! This header attempts
//  to put all those platform-specific "#include <*>" tweaks in one place.
// =============================================================================

#include <stdarg.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>

// memory allocation

#ifdef _MACOSX
    #include <malloc/malloc.h>
#elif !defined(_WIN32)
    #include <stdlib.h>
#endif

// filesystem directory traversal; symlink handling

#ifdef __MINGW32__
    #include <windows.h>
    #include <direct.h>
#elif defined(_MSC_VER)
// jsteele NO!! Never EVER include windows in some sort of god-header. WTF were you thinking? Fucking shit coders.
//    #include <windows.h>
//    #include <direct.h>
    #include <io.h>
#else
    #include <sys/stat.h>
    #include <dirent.h>
    #include <unistd.h>
#endif

// utility time functions

#ifdef _WIN32
// jsteele NO!! Never EVER include windows in some sort of god-header. WTF were you thinking? Fucking shit coders.
    //#include <windows.h>
#else
    #include <sys/time.h>
#endif

