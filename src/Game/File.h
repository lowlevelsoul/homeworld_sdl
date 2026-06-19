/*=============================================================================
    File.h:  Definitions for file I/O.  This includes .BIG files and regular
        files.

    Created June 1997 by Luke Moloney
=============================================================================*/

#ifndef ___FILE_H
#define ___FILE_H

#include "tiPlatform.h"
#include <stdio.h>

#ifdef __FreeBSD__
#include <sys/syslimits.h>
#endif

#include "BigFile.h"

/*=============================================================================
    Switches
=============================================================================*/
// If not already defined (such as through a configure setting), define
// whether or not case-insensitive searches for files should be performed
// based on the target platform.
#ifndef FILE_CASE_INSENSITIVE_SEARCH
    #if defined (_WIN32) || defined (_MACOSX)
        #define FILE_CASE_INSENSITIVE_SEARCH 0
    #else
        #define FILE_CASE_INSENSITIVE_SEARCH 1
    #endif
#endif

/*=============================================================================
    Definitions:
=============================================================================*/

//file seek locations
#define FS_Start                SEEK_SET
#define FS_Current              SEEK_CUR
#define FS_End                  SEEK_END

//results of file stream operations
#define FR_EndOfFile            -12             // some unlikely number to indicate end of file

//flags for opening files
#define FF_NoModifers           0x0000          // none of the below (initialiser)
#define FF_TextMode             0x0001          // open file in text mode
#define FF_IgnoreDisk           0x0002          // don't search on disk, look straight in the .BIG file
#define FF_DontUse0             0x0004          // These bits are reserved for flag compatability with memory module
#define FF_DontUse1             0x0008
#define FF_WriteMode            0x0010          // open file for writing to
#define FF_AppendMode           0x0020          // open file for appending to
#define FF_ReturnNULLOnFail     0x0040          // open file, but if fail return NULL instead of doing Fatal Error
#define FF_CDROM                0x0080          // open from CD-ROM
#define FF_IgnoreBIG            0x0100          // don't look in .BIG file, only try to load from disk
#define FF_IgnorePrepend        0x0200          // don't environment root path to beginning of file names
#define FF_UserSettingsPath     0x0400          // use user configuration root as the base path
#define FF_HomeworldDataPath    0x0800          // where the main data files are located

//names of log files
#define FN_OpenLog              "open.log"

// for /logFileLoads option
#define FILELOADSLOG            "FileLoads.log"

//.BIG file definitions
#define FBF_AllBIGFiles         -1

//length of file path fragments
#define FL_Path                 256             //max length of a full path

#define MAX_FILES_OPEN          32

#ifndef PATH_MAX
#   define PATH_MAX 258
#endif

/*=============================================================================
    Type definitions:
=============================================================================*/
typedef int32_t filehandle;

typedef struct {
    sdword inUse;
    char path[PATH_MAX];    // full path name of open file
    sdword usingBigfile;    // true if this has been "opened" within the bigfile instead of on disk
    FILE *fileP;            // valid if we've opened directly from disk
    // valid when usingBigfile:
    FILE *bigFP;            // could be using either the main
    bigTOC *bigTOC;         //  or updated bigfile
    sdword textMode;        // true/false
    long offsetStart;       // start of file in bigfile
    char *decompBuf;        // If necessary, a compressed file will be decompressed to this buf (upon opening it) to fake streamed i/o.
                            // So if this is non-NULL, offsetVirtual is a pointer into this buffer.
                            // This will be NULL if we're just re-directing the stream to the bigfile (ie, for an uncompressed file).
                            // If possible this will either point to an existing workspace that persists between file loads
                            //  (to avoid extra allocs/deallocs), or else to a newly allocated buffer that will be freed upon
                            //  "closing" the current file).
    long offsetVirtual;     // this tracks the virtual stream offset (from offsetStart), like stdio (0 = start, etc.)
    long length;            // length of file in bigfile (uncompressed length)
} fileOpenInfo;

extern char fileHomeworldDataPath [];
extern char fileUserSettingsPath  [];
extern char fileOverrideBigPath   [];
extern char fileCDROMPath         [];
extern char filePathTempBuffer    [];


/*=============================================================================
    Functions:
=============================================================================*/

TI_API char *filePathPrepend(char *fileName, udword flags);
TI_API void fileNameReplaceSlashesInPlace(char *fileName);

TI_API bool_t fileCDROMPathSet(char *path);
TI_API void fileHomeworldDataPathSet(char *path);
TI_API bool_t fileOverrideBigPathSet(char *path);
TI_API bool_t fileUserSettingsPathSet(char *path);


//load files directly into memory
TI_API sdword fileLoadAlloc(char *fileName, void **address, udword flags);
TI_API sdword fileLoad(char *fileName, void *address, udword flags);

//save files, if you want stream saving, use the ANSI C stream functions
TI_API sdword fileSave(char *fileName, void *address, sdword length);

//delete a file
TI_API void fileDelete(char *fileName);

//load files like ANSI C streams (fopen, fread etc)
TI_API filehandle fileOpen(char *fileName, udword flags);
TI_API void fileClose(filehandle handle);
TI_API sdword fileSeek(filehandle handle, sdword offset, sdword whence);
TI_API sdword fileBlockRead(filehandle handle, void *dest, sdword nBytes);
TI_API sdword fileBlockReadNoError(filehandle handle, void *dest, sdword nBytes);
TI_API sdword fileLineRead(filehandle handle, char *dest, sdword nChars);
TI_API sdword fileCharRead(filehandle handle);

// for using regular underlying i/o stream (filesystem, not bigfile)
TI_API sdword fileUsingBigfile(filehandle handle);
TI_API FILE *fileStream(filehandle handle);

//utility functions
TI_API bool8 fileMakeDirectory(const char *directoryName);
TI_API bool8 fileMakeDestinationDirectory(const char *fileName);
TI_API bool_t fileExistsInBigFile(char *fileName);
TI_API bool_t fileExists(char *fileName, udword flags);
TI_API sdword fileSizeGet(char *fileName, udword flags);

TI_API void logfileClear(char *logfile);
TI_API void logfileLog(char *logfile,char *str);
TI_API void logfileLogf(char *logfile,char *format, ...);

#endif
