#ifndef ___MIXFFT_H
#define ___MIXFFT_H
#include "tiPlatform.h"

#ifdef __cplusplus
extern "C" {
#endif

void fft(long n,float *xRe,float *xIm,float *yRe,float *yIm);

#ifdef __cplusplus
}		// extern "C"
#endif

#endif
