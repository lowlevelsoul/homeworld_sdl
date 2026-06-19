#include "tiPlatform.h"
/*=============================================================================
    Name    : rinit.h
    Purpose : rGL / OpenGL enumeration initialization routines

    Created 1/5/1999 by khent
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/

#ifndef ___RINIT_H
#define ___RINIT_H

typedef struct rmode
{
    int width, height;
    int depth;
    struct rmode* next;
} rmode;

#define RIN_TYPE_OPENGL   1
#define RIN_TYPE_DIRECT3D 2
#define RIN_TYPE_SOFTWARE 4

typedef struct rdevice
{
    int type;
    char data[64];
    char name[64];
    unsigned int devcaps;
    unsigned int devcaps2;

    struct rmode* modes;

    struct rdevice* next;
} rdevice;

#ifdef __cplusplus
extern "C" {
#endif

TI_API int rinEnumerateDevices(void);
TI_API int rinFreeDevices(void);
TI_API unsigned int rinDirectXVersion(void);
TI_API rdevice* rinGetDeviceList(void);

TI_API unsigned int rinDeviceCRC(void);

#ifdef __cplusplus
}
#endif

#endif

