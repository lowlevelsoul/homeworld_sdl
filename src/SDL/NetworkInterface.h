#ifndef ___NETWORKINTERFACE_H
#define ___NETWORKINTERFACE_H

#include "tiPlatform.h"
#include "SDL.h"
#include "SDL_thread.h"
#ifdef HW_ENABLE_NETWORK
#include "SDL_net.h"

typedef struct IpElemTmp { IPaddress IP; struct IpElemTmp *nextIP; } IpElem;

typedef IpElem* IpList;

typedef struct { TCPsocket sock; IPaddress IP; } Client;

void initNetwork(void)
void shutdownNetwork(void)

int broadcastStartThread(void*);
int TCPServerStartThread(void*);
TI_API void sendBroadcastPacket(const void*, int);
TI_API Uint32 connectToServer(Uint32);

TI_API Client * addSockToList(TCPsocket);
TI_API TCPsocket findSockInList(Uint32);
TI_API void removeSockFromList(int);

TI_API int checkList(IPaddress, IpList);
TI_API IpList addList(IPaddress, IpList);

Uint32 getMyAddress(void)
int pingSendThread(void*);


// Function defined depending on the protocol used
TI_API void putPacket(Uint32, unsigned char, const void*, unsigned short);
unsigned char getPacket(TCPsocket, unsigned char*, Uint8**, unsigned short*);

// Callback to the function that Handle messages.
TI_API void HandleTCPMessage(Uint32, unsigned char, const void*, unsigned short);

TI_API void HandleJoinGame(Uint32, const void*, unsigned short);
TI_API void HandleJoinConfirm(Uint32, const void*, unsigned short);
TI_API void HandleGameData(const void*, unsigned short);
TI_API void HandleGameStart(const void*, unsigned short);
TI_API void HandleGameMsg(const void*, unsigned short);


#define TCPPORT 10500
#define UDPPORT 10600

#endif
#endif
