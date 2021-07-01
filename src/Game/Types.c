// =============================================================================
//  Types.c
// =============================================================================

#include "Types.h"

uint32_t Swap32(const uint32_t val ) {
	uint32_t retVal;
	uint8_t* retValBytes = (uint8_t*) &retVal;
	const uint8_t* valBytes = (const uint8_t*) &val;

	retValBytes[0] = valBytes[3];
	retValBytes[1] = valBytes[2];
	retValBytes[2] = valBytes[1];
	retValBytes[3] = valBytes[0];

	return retVal;
}

float SwapFloat32( float val )
{
	union
	{
		float  f;
		uint32_t i;
	} swap;

	swap.f = val;
	swap.i = Swap32( swap.i );
    
	return swap.f;
}

udword Real32ToUdword(real32 a)
{
 return (*(udword*)(&a));
}

udword Real32ToSdword(real32 a)
{
 return (*(sdword*)(&a));
}

real32 UdwordToReal32(udword a)
{
 return (*(real32*)(&a));
}

real32 SdwordToReal32(sdword a)
{
 return (*(real32*)(&a));
}

real32 MemsizeToReal32(memsize a)
{
    return (*(real32 *)(&a));
}
