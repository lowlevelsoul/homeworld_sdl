#ifndef ___DCT_H
#define ___DCT_H
#include "tiPlatform.h"

#ifdef __cplusplus
extern "C" {
#endif

TI_API int Initdct(float *buf, udword len);
TI_API int idct(float *a, float *b, float *c, udword len);

#ifdef __cplusplus
}		// extern "C"
#endif

#endif
