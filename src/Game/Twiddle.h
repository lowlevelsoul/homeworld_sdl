// =============================================================================
//  Twiddle.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 7/7/1997 by lmoloney
// =============================================================================

#ifndef ___TWIDDLE_H
#define ___TWIDDLE_H

#include "tiPlatform.h"
#include "Types.h"

// count number of set bits in a number
TI_API udword bitNumberSet(udword target, udword nBits);

// find nearest exponent of 2
TI_API udword bitHighExponent2(udword number);
TI_API udword bitLowExponent2(udword number);

// find lowest/highest bit set in a number
TI_API udword bitLowBitPosition(udword number);

#endif
