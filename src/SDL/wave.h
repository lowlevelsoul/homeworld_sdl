#include "tiPlatform.h"
// Copyright (c) 1999 Relic Entertainment Inc.
// Written by Janik Joire
//
// $History: $

#ifndef ___WAVE_H
#define ___WAVE_H

// General constants
#ifndef OK
#define OK		0
#endif

#ifndef ERR
#define ERR		-1
#endif

// Other constants
#define STOP	0
#define PLAY	1
                
#define WAVE_BUFSIZE 32768		// buffer about 32K
#define WAVE_SAMPLERATE	22050	// sample rate
#define WAVE_BITSAMPLE	16		// bits per sample
#define WAVE_NUMCHAN	2		// number of channels

// External functions 
#ifdef __cplusplus
extern "C" {
#endif

TI_API int InitWave(DWORD *dwNumDevs);
TI_API int EndWave( void );

TI_API int StartWavePlay(DWORD nDeviceID);
TI_API int StopWavePlay( void );

#ifdef __cplusplus
}
#endif

// Internal functions 
TI_API int AllocWaveFormat( void );
TI_API int FreeWaveFormat( void );

TI_API int AllocWaveHeaders( void );
TI_API int InitWaveHeaders( void );
TI_API int FreeWaveHeaders( void );

TI_API int AllocWaveBuffers( void );
TI_API int FreeWaveBuffers( void );

TI_API int CloseWavePlay( void );
TI_API int QueueWaveBuffer( void );
TI_API int ReadWaveBuffer( void );

TI_API int GetFormatTagDetails(WORD wFormatTag);
TI_API int GetFormatDetails(LPWAVEFORMATEX pFormatIn);

// Thread functions
TI_API int InitWaveThread(void);
TI_API int CleanWaveThread(void);
TI_API int CheckWaveThread(void);
TI_API DWORD WINAPI ExecWaveThread(void);
TI_API LRESULT CALLBACK WaveWndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

#endif
