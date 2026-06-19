/*=============================================================================
    Name    : FeFlow.h
    Purpose : Definitions for loading/processing FEMan screens.

    Created 7/8/1997 by lmoloney
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___FEFLOW_H
#define ___FEFLOW_H

#include "tiPlatform.h"
#include "Color.h"
#include "Region.h"

/*=============================================================================
    Switches:
=============================================================================*/
#ifdef HW_BUILD_FOR_DEBUGGING

#define FEF_ERROR_CHECKING      1               //general error checking
#define FEF_VERBOSE_LEVEL       2               //print extra info
#define FEF_TEST                1               //test the module
#define FEF_TEXTURES_DISABLABLE 1

#else

#define FEF_ERROR_CHECKING      0               //general error checking
#define FEF_VERBOSE_LEVEL       0               //print extra info
#define FEF_TEST                0               //test the module
#define FEF_TEXTURES_DISABLABLE 0

#endif

/*=============================================================================
    Definitions:
=============================================================================*/
#define FIB_Identify            "Bananna"
#define FIB_Version             0x00000212

enum tagFIBLinkFlags
{
    FL_Enabled        = 1,
    FL_DefaultPrev    = 2,
    FL_DefaultNext    = 4,
    FL_RetainPrevious = 8,

    FL_LastFLF
};

//control flags
#define FAF_Link                0x00000001
#define FAF_Function            0x00000002
#define FAF_Bitmap              0x00000004
#define FAF_Modal               0x00000008
#define FAF_Popup               0x00000010
#define FAF_CallOnCreate        0x00000020
#define FAF_ContentsVisible     0x00000040
#define FAF_DefaultOK           0x00000080
#define FAF_DefaultBack         0x00000100
#define FAF_AlwaysOnTop         0x00000200
#define FAF_Draggable           0x00000400
#define FAF_BorderVisible       0x00000800
#define FAF_Disabled            0x00001000
#define FAF_DontCutoutBase      0x00002000
#define FAF_CallOnDelete        0x00004000
#define FAF_Hidden              0x00008000
#define FAM_Justification       0x00030000          //mask by this to get a justification index
#define FAM_JustLeft            0x00010000
#define FAM_JustRight           0x00020000
#define FAM_JustCentre          0x00030000
#define FAF_Background          0x00040000
#define FAM_DropShadow          0x0ff00000          //these bits not used by strings
#define FSB_DropShadow          20

// status flags for the region, SEPARATE from the flags variable
#define FAS_UseAlpha            0x00000001          //updated dynamically, depending on usage
#define FAS_Checked             0x00000002          //used for certain types of controls, updates real-time
#define FAS_OnCreate            0x00000004          // set if this is the first call after it is created.
#define FAS_OnDelete            0x00000008          // set if this is the last call before it is deleted.


//control type enumerations
enum tagFIBAtomFlagsff
{
    FA_UserRegion = 1,
    FA_StaticText,
    FA_Button,
    FA_CheckBox,
    FA_ToggleButton,
    FA_ScrollBar,
    FA_StatusBar,
    FA_TextEntry,
    FA_ListViewExpandButton,
    FA_TitleBar,
    FA_MenuItem,
    FA_RadioButton,
    FA_CutoutRegion,
    FA_DecorativeRegion,
    FA_Divider,
    FA_ListWindow,
    FA_BitmapButton,
    FA_HorizSlider,
    FA_VertSlider,
    FA_DragButton,
    FA_OpaqueDecorativeRegion,

    FA_LastFA
};

//flags for scroll bars
#define SBA_Vertical            0x00000001      //orientation (default is horiz)
#define SBA_AdjoinTop           0x00000002      //edges to draw non-rounded
#define SBA_AdjoinBottom        0x00000004
#define SBA_AdjoinLeft          SBA_AdjoinTop
#define SBA_AdjoinRight         SBA_AdjoinBottom
#define SBA_LeftRightKeys       0x00000008      //keys to assist in scrolling
#define SBA_UpDownKeys          0x00000010
#define SBA_HomeEndKeys         0x00000020
#define SBA_PageScrollKeys      0x00000040

//default parameters
#define FE_NumberCallbacks      400             //maximum number of callback functions
#define FE_NumberDrawCallbacks  150             //maximum number of draw callback functions
#define FE_NumberScreens        150             //max number of screens
#define FE_StackDepth           32              //depth of screen stack
#define FE_MenuSelectedColor    colRGB(54, 83, 45)//current menu selection color
#define FE_MenuFlags            (RPE_PressLeft | RPE_ReleaseLeft | RPE_Enter | RPE_Exit)  //default menu item handler messages

//size of default borders for differing controls
#define FBA_TextEntry           6
#define FBA_ScrollBar           6

#define FE_NumberLanguages      5

//hot key modifiers
#define HKM_Control         0x01
#define HKM_Alt             0x02
#define HKM_Shift           0x04

/*=============================================================================
    Type definitions:
=============================================================================*/
//.FIB file header
typedef struct tagfibfileheader
{
    char identify[8];
    uword version;
    uword nScreens;
}
fibfileheader;

//structure for a screen
typedef struct tagfescreen
{
    char *name;                                 //name of screen for link purposes
    udword flags;                               //flags for this screen
    uword nLinks;                               //number of links in this screen
    uword nAtoms;                               //number of atoms in screen
    struct tagfelink *links;                    //pointer to list of links
    struct tagfeatom *atoms;                    //pointer to list of atoms
}
fescreen;

//structure for a link
typedef struct tagfelink
{
    char *name;                                 //optional name of this link
    udword flags;                               //flags controlling behaviour of link
    char *linkToName;                           //name of screen to link to
}
felink;

//scroll-bar info structure referenced by the pData member of scroll bar atoms
typedef struct
{
    real32 rangeLow, rangeHi;
    udword scrollFlags;
}
fescrollinfo;

//structure for an atom of a screen
typedef struct tagfeatom
{
    char  *name;                                //optional name of control
    udword flags;                               //flags to control behavior
    udword status;                              //status flags for this atom, checked etc.
    ubyte  type;                                //type of control (button, scroll bar, etc.)
    ubyte  borderWidth;                         //width, in pixels, of the border
    uword  tabstop;                             //denotes the tab ordering of UI controls
    color  borderColor;                         //optional color of border
    color  contentColor;                        //optional color of content
    sword  x,      loadedX;
    sword  y,      loadedY;
    sword  width,  loadedWidth;
    sword  height, loadedHeight;
    ubyte *pData;                               //pointer to type-specific data
    ubyte *attribs;                             //sound(button atom) or font(static text atom) reference
    char   hotKeyModifiers;
    char   hotKey[FE_NumberLanguages];
    char   pad2[2];
    udword drawstyle[2];
    void*  region;
    udword pad[2];
}
featom;

//type of a function callback for a front end
typedef void (*fefunction)(char *name, featom *atom);

//structure for a namestring/callback mapping
typedef struct
{
    fefunction function;
    char *name;
}
fecallback;

//function type for front end draw callback
typedef void (*fedrawfunction)(featom *atom, regionhandle region);

//structure for namestring/draw callback mapping
typedef struct
{
    fedrawfunction function;
    char *name;
}
fedrawcallback;

typedef struct
{
    fescreen *screen;
    regionhandle baseRegion;
    regionhandle parentRegion;
}
festackentry;

typedef enum
{
    KA_TAB,
    KA_RIGHT_ARROW, KA_LEFT_ARROW,
    KA_UP_ARROW, KA_DOWN_ARROW,
    KA_SPACE, KA_RETURN,
    KA_PGUP, KA_PGDOWN,
    KA_HOME, KA_END
} fekeycontroltype;


/*=============================================================================
    Data:
=============================================================================*/
extern sdword feNumberCallbacks;
extern sdword feNumberScreens;
extern udword feTabStop;
//front-end screen stack
extern festackentry feStack[FE_StackDepth];     //actual stack data
extern sdword feStackIndex;                     //index of CURRENT screen on stack
extern fescreen *feTempMenuScreen;
extern bool   feSavingMouseCursor;
extern bool   feRenderEverything;
extern sdword feMenuLevel;
extern sdword feDontFlush;

#if FEF_TEXTURES_DISABLABLE
extern bool fetEnableTextures;
#endif

/*=============================================================================
    Data:
=============================================================================*/
//you should always compare control names using this macro as they may
//not always be character strings
#define feNamesEqual(a, b)  (!strcmp((a), (b)))

/*=============================================================================
    Macros:
=============================================================================*/
// macros for testing if an checkbox is checked etc.
#define FECHECKED(atom)     (atom->status&FAS_Checked)
#define FEFIRSTCALL(atom)   ((atom) && ((atom)->status&FAS_OnCreate))
#define FELASTCALL(atom)    (atom->status&FAS_OnDelete)

// Relic scaled all their FE graphics to the minimum resolution they supported
// and centred it on screen. With today's resolutions that's a tad small...
#define FE_RELIC_SCREEN_WIDTH   640
#define FE_RELIC_SCREEN_HEIGHT  480

#define FE_SCALE_TO_FIT_FACTOR(to_fit_width, to_fit_height, current_width, current_height)  \
    min(((real32)(to_fit_width)  / (real32)(current_width)),                                \
        ((real32)(to_fit_height) / (real32)(current_height)))

#define FE_SCALE_TO_FIT_FACTOR_RELIC_SCREEN                                  \
    FE_SCALE_TO_FIT_FACTOR(MAIN_WindowWidth,      MAIN_WindowHeight,         \
                           FE_RELIC_SCREEN_WIDTH, FE_RELIC_SCREEN_HEIGHT)

/*=============================================================================
    Functions:
=============================================================================*/
//startup/shutdown the front end
TI_API sdword feStartup(void);
TI_API void feReset(void);
TI_API void feShutdown(void);

TI_API void feFunctionExecute(char *name, featom *atom, bool firstcall);

TI_API bool feShouldSaveMouseCursor(void);

//load in a front end screen
TI_API fibfileheader *feScreensLoad(char *fileName);
TI_API sdword feScreensDelete(fibfileheader *screens);

//execute a screen
TI_API regionhandle feScreenStart(regionhandle parent, char *screenName);
TI_API regionhandle feMenuStart(regionhandle parent, fescreen *screen, sdword x, sdword y);
TI_API void feCurrentScreenDelete(void);

#define FE_DONT_DELETE_REGION_IF_SCREEN_NOT_FOUND   1
TI_API void feScreenDeleteFlags(regionhandle baseRegion,sdword flags);
#define feScreenDelete(r) feScreenDeleteFlags(r,0)
TI_API void feAllScreensDelete(void);
TI_API void feAllMenusDelete(void);

//add a callback for a menu item etc.
TI_API sdword feCallbackAdd(char *controlName, fefunction function);
TI_API sdword feCallbackAddMultiple(fecallback *table);
TI_API sdword feDrawCallbackAdd(char *controlName, fedrawfunction function);
TI_API sdword feDrawCallbackAddMultiple(fedrawcallback *table);

TI_API void feAllCallOnCreate(fescreen *screen);

//add a screen entry point (typically at load time)
TI_API sdword feScreenEntryAdd(fescreen *screen);
TI_API sdword feScreenEntryRemove(fescreen *screen);

//find things
TI_API fescreen *feScreenFind(char *name);
TI_API featom *feAtomFindInScreen(fescreen *screen, char *atomName);
TI_API featom *feAtomFindNextInScreen(fescreen *screen, featom *atom, char *atomName);
TI_API regionhandle feRegionFindByFunction(char *name);

//manipulating screen stack
TI_API fescreen *feScreenPush(void);
TI_API fescreen *feScreenPop(void);

//drawing front-end screens
TI_API void feStaticTextDraw(regionhandle region);
TI_API void feStaticRectangleDraw(regionhandle region);
TI_API void feBaseRegionDraw(regionhandle region);
TI_API void feDividerDraw(regionhandle region);

//control-type specific calls
TI_API void feRadioButtonSet(char *name, sdword index);
TI_API void feToggleButtonSet(char *name, sdword bPressed);

//misc...
TI_API void feScreenDisappear(char *string, featom *atom);
TI_API void feMenuDisappear(char *string, featom *atom);
TI_API regionhandle feRegionsAdd(regionhandle parent, fescreen *screen, bool moveToFront);
TI_API regionhandle feFindRadioButtonRegion(regionhandle temp, bool selected);

struct uiclistwindow;
TI_API void feWheelNegative(struct uiclistwindow *listwindow);
TI_API void feWheelPositive(struct uiclistwindow *listwindow);

TI_API void feUserRegionDraw(regionhandle region);
TI_API void feAcceleratorSet(regionhandle reg, featom *atom);
TI_API void feScreenAllHotKeysUpdate(fescreen *screen);

TI_API sdword feResRepositionCentredX(sdword x);
TI_API sdword feResRepositionCentredY(sdword y);
TI_API sdword feResRepositionScaledX(sdword x);
TI_API sdword feResRepositionScaledY(sdword y);

TI_API bool feAllScreensReposition(void);

TI_API udword feButtonProcess(regionhandle region, smemsize ID, udword event, udword data);

#endif
