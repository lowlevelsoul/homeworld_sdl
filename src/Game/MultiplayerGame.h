/*=============================================================================
    Name    : MultiplayerGame.h
    Purpose : definitions for MultiplayerGame.c

    Created 6/22/1998 by ddunlop
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___MULTIPLAYERGAME_H
#define ___MULTIPLAYERGAME_H

#include "tiPlatform.h"
#include "LinkedList.h"
#include "TitanInterfaceC.h"
#include "TimeoutTimer.h"
#include "UIControls.h"

/*=============================================================================
    defines:
=============================================================================*/

#ifdef _WIN32
#define MG_FIBFile          "FEMan\\Multiplayer_Game.FIB"
#else
#define MG_FIBFile          "FEMan/Multiplayer_Game.FIB"
#endif
#define MAX_GAMENAME_LENGTH     MAX_TITAN_GAME_NAME_LEN
#define MAX_MAPNAME_LENGTH      MAX_MAPNAME_LEN
#define MAX_CHANNELNAME_LENGTH  MAX_CHANNEL_NAME_LEN
#define MAX_DESCRIPTION_LENGTH  MAX_CHANNEL_DESCRIPTION_LEN
#define MAX_USERNAME_LENGTH     MAX_PERSONAL_NAME_LEN
#define MAX_PASSWORD_LENGTH     MAX_PASSWORD_LEN
#define MAX_CHATSTRING_LENGTH   256
#define MAX_STATUSSTRING_LENGTH 128
#define MAX_NUM_LENGTH          12

// defines for the multiplayer game options
#define MG_Small    0
#define MG_Medium   1
#define MG_Large    2
#define MG_BountiesOff  3

#define MG_LastMotherShip       BIT1
#define MG_CaptureCapitalShip   BIT2
#define MG_ResearchEnabled      BIT3
//#define MG_BountiesEnabled      BIT4      obsolete, check instead tpGameCreated.bountySize == MG_BountiesOff
#define MG_HarvestinEnabled     BIT5
#define MG_ResourceInjections   BIT6
#define MG_ResourceLumpSum      BIT7
#define MG_PasswordProtected    BIT8
#define MG_UnitCapsEnabled      BIT9
#define MG_FuelBurnEnabled      BIT10
#define MG_AlliedVictory        BIT11
#define MG_CratesEnabled        BIT12
#define MG_CarrierIsMothership  BIT13
#define MG_Hyperspace           BIT14

// defines for the type of packet being transfered between threads
#define MG_QUEUEROOMNEWUSERINFO     1
#define MG_QUEUEROOMGONEUSERINFO    2
#define MG_QUEUEROOMCHATINFO        3
#define MG_QUEUEPINGINFO            4
#define MG_QUEUESTATUSINFO          5
#define MG_QUEUEGAMEPLAYER          6
#define MG_QUEUEGAMECHATINFO        7
#define MG_QUEUEGAMEDISOLVED        8

#define MG_QUEUEGAMELISTGAMEADDED   9
#define MG_QUEUEGAMELISTGAMEREMOVED 10
#define MG_QUEUEGAMELISTGAMECHANGED 11
#define MG_QUEUEGAMELISTNEW         12

#define MG_QUEUECHATDISCONNECTED    13
#define MG_QUEUENUMPEOPLEROOM       14

#define MG_QUEUEKICKEDOUT           15

// defines for the type of message the chat is
#define MG_NORMALCHAT               1
#define MG_WHISPEREDCHAT            2
#define MG_MESSAGECHAT              3
#define MG_WRAPEDCHAT               4
#define MG_GENERALMESSAGE           5

/*=============================================================================
    Types:
=============================================================================*/

// type definitions for maintaining lists internal to the multiplayer game structure

typedef struct gamelist
{
    Node    link;
    tpscenario game;
    sdword  pingtime;
    listitemhandle item;
}
gamelist;

typedef struct lggamelist
{
    Node    link;
    tpscenario game;
    CaptainGameInfo captainGameInfo;  // used only for LAN play
    TTimer  gameTimeout;              // used only for LAN play
    listitemhandle item;
}
lggamelist;

typedef struct channellist
{
    Node            link;
    wchar_t         channelname[MAX_CHANNELNAME_LENGTH];
    wchar_t         description[MAX_DESCRIPTION_LENGTH];
    unsigned int    roomflags;
    sdword          numpeople;
    listitemhandle  item;
}
channellist;

typedef struct serverlist
{
    Node            link;
    wchar_t ServerName[MAX_SERVER_NAME_LEN];
    wchar_t ServerDescription[MAX_SERVER_DESCRIPTION_LEN];
    unsigned int flags;
    unsigned int reliability;
    unsigned int ping;
    unsigned char addressstore[6];
    listitemhandle  item;
}
serverlist;

typedef struct userlist
{
    Node            link;
//    Node           *remove;
    char            userName[MAX_USERNAME_LENGTH];
    udword          userID;
    TTimer          userTimeout;        // used only for LAN play
    Address         userAddress;        // used only for LAN play
    listitemhandle  item;
}
userlist;

typedef struct chatlist
{
    Node            link;
    char            chatstring[MAX_CHATSTRING_LENGTH];
    char            userName[MAX_USERNAME_LENGTH];
    udword          baseColor;
    udword          messagetype;
    udword          index;
    udword          indent;
    listitemhandle  item;
}
chatlist;

typedef struct newping
{
    Node            link;
    udword          IP;
    udword          Port;
    sdword          pingtime;
}
newping;

typedef struct statusline
{
    Node            link;
    char            message[MAX_STATUSSTRING_LENGTH];
}
statusline;

typedef struct gameplayerinfo
{
    Node            link;
    char            name[MAX_PERSONAL_NAME_LEN];
    udword          baseColor;
    udword          stripeColor;
    udword          colorsPicked;
    udword          race;
    udword          index;
    listitemhandle  item;
}
gameplayerinfo;

typedef struct mgqueuegeneral
{
    uword           packettype;
}
mgqueuegeneral;

typedef struct mgqueueuserlist
{
    mgqueuegeneral  header;
    userlist        user;
}
mgqueueuserlist;

typedef struct mgqueuechatlist
{
    mgqueuegeneral  header;
    chatlist        chat;
}
mgqueuechatlist;

typedef struct mgqueuenewping
{
    mgqueuegeneral  header;
    newping         ping;
}
mgqueuenewping;

// used for MG_QUEUEGAMELISTGAMEADDED, MG_QUEUEGAMELISTGAMECHANGED, MG_QUEUEGAMELISTGAMEREMOVED
typedef struct mgqueuegamelistgame
{
    mgqueuegeneral  header;
    tpscenario      game;
}
mgqueuegamelistgame;

// used for MG_QUEUEGAMELISTNEW
typedef struct mgqueuegamelistnew
{
    mgqueuegeneral  header;
    // any extra info needed?
}
mgqueuegamelistnew;

typedef struct mgqueuestatusline
{
    mgqueuegeneral  header;
    statusline      status;
}
mgqueuestatusline;

typedef struct mgqueuegameplayerinfo
{
    mgqueuegeneral  header;
    gameplayerinfo  player;
}
mgqueuegameplayerinfo;

// for MG_QUEUENUMPEOPLEROOM
typedef struct mgqueuenumpeopleroominfo
{
    mgqueuegeneral  header;
    wchar_t         channelname[MAX_CHANNELNAME_LENGTH];
    sdword          numpeople;
} mgqueuenumpeopleroominfo;

#define MAX_GAME_NAME_CHAR 42       //pad to make struct below alligned by 4

typedef struct
{
    char gameName[MAX_GAME_NAME_CHAR];

    ubyte numComputers;
    ubyte startingFleet;
    ubyte bountySize;
    ubyte startingResources;

    udword resourceInjectionInterval;
    udword resourceInjectionsAmount;
    udword resourceLumpSumTime;
    udword resourceLumpSumAmount;

    uword flag;
    uword flagNeeded;
} GameType;

typedef struct
{
    udword numGameTypes;
    GameType gameType[1];    //ragged array...
} GameTypes;


/*=============================================================================
    Function Prototypes:
=============================================================================*/

struct ChatPacket;

TI_API void mgStartMultiPlayerGameScreens(regionhandle region, sdword ID, udword event, udword data, bool AlreadyLoggedIn);
TI_API void mgShutdownMultiPlayerGameScreens(void);

TI_API void mgFailedToConnectToChannel(bool existing);

TI_API void mgDisplayMessage(char *message);

TI_API void mgProcessGameChatPacket(struct ChatPacket *packet);

TI_API void mgJoinGameConfirmed(void);
TI_API void mgJoinGameDenied(void);
TI_API void mgUpdateGameInfo(void);

TI_API void mgChatConnectionFailed(void);
TI_API void mgGameAlreadyExists(void);
TI_API void mgCreateGameConfirmed(void);

TI_API void mgStartup(void);
TI_API void mgShutdown(void);

//sets the game options based on gameName
TI_API void mgSetGameType(char *gameName);

TI_API void mgScreensDisappear(void);

TI_API bool mgAccelerator(void);
TI_API void mgAcceleratorRelease(void);

TI_API void LockMutex(void *mutex);
TI_API void UnLockMutex(void *mutex);
void *gameCreateMutex(void);          // no windows handles, etc, required!
TI_API void gameCloseMutex(void *mutex);

TI_API void titanJoinGameRequest(tpscenario *gametojoin);

TI_API bool mgInvalidGameName(void);

TI_API bool mgInvalidGamePassword(void);

TI_API void mgPrepareMessageBox(char *string1,char *string2);

TI_API bool mgIsPlayerInList(LinkedList *list, gameplayerinfo *find);

void GeneralMessageBox(char *string1,char *string2);        // designed for external use

TI_API void mgSetGameTypeByStruct(GameType *game);
TI_API void mgSetGameTypeByNum(sdword i);
TI_API void mgGameTypesOtherButtonPressed(void);

TI_API void mgBackuptpGameCreated(void);
TI_API void mgRestoretpGameCreated(void);
TI_API void mgResetNamePassword(void);

TI_API bool mgIsUserBanned(char *name);

/*=============================================================================
    Data:
=============================================================================*/

#define LANIPX_VALID    1
#define LANTCPIP_VALID  2
#define LANIPXANDTCPIPVALID     (LANIPX_VALID|LANTCPIP_VALID)
extern int LanProtocalsValid;

extern int LanProtocalButton;

extern bool mgRunning;

// N    P   M   D   u   p        nc  sf  bs  sr   ii    ia     lt    la   ad  ab  p     f
//= {L"", L"", "", "", 0,  {0,0,0},  0,  1,  3,   1, 1440, 2000, 19200, 2000, 50, 50, 0, 22058};
extern CaptainGameInfo tpGameCreated;

extern GameTypes *preSetGames;

extern sdword lastScreen;
extern sdword currentScreen;

extern CaptainGameInfo BackupGameCreated;
extern sdword          spCurrentSelectedBack;

extern int patchComplete;

extern sdword mgConnectingScreenGoto;

extern udword mgPlayerLimit;

// enumeration for all of the screens in the multiplayer front end.

enum
{

    MGS_Connection_Method,
    MGS_Internet_Login,
    MGS_Password_Change,
    MGS_LAN_Login,
    MGS_Connecting,
    MGS_New_Account,
    MGS_Channel_Chat,
    MGS_Available_Channels,
    MGS_Player_Options,
    MGS_Create_Channel,
    MGS_Available_Games,
    MGS_Player_Wait,
    MGS_Captain_Wait,
    MGS_Basic_Options,
    MGS_Advanced_Options,
    MGS_Resource_Options,
    MGS_Basic_Options_Change,
    MGS_Advanced_Options_Change,
    MGS_Resource_Options_Change,
    MGS_Basic_Options_View,
    MGS_Advanced_Options_View,
    MGS_Resource_Options_View,
    MGS_Skirmish_Basic,
    MGS_Skirmish_Advanced,
    MGS_Skirmish_Resource,
    MGS_Game_Password,
    MGS_Room_Password,
    MGS_Quit_WON,
    MGS_Message_Box,
    MGS_Download_Patch,
    MGS_Downloading_Patch,

    LGS_LAN_Login,
    LGS_Channel_Chat,
    LGS_Player_Options,
    LGS_Available_Games,
    LGS_Player_Wait,
    LGS_Captain_Wait,
    LGS_Basic_Options,
    LGS_Basic_Options_Change,
    LGS_Basic_Options_View,
    LGS_Quit_WON,
    LGS_Message_Box,
    LGS_Game_Password,

    // Choose Server screens
    MGS_Choose_Server

};

#define NEED_MIN_TWO_HUMAN_PLAYERS  1

#endif
