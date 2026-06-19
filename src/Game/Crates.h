// =============================================================================
//  Crates.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created bryce in november
// =============================================================================

#ifndef ___CRATES_H
#define ___CRATES_H
 
#include "tiPlatform.h"
#include "SpaceObj.h"
      
//prototypes      
TI_API void cratesUpdate(void);
TI_API void cratesReportCratePlacement(Derelict *crate);
TI_API void crateInit(void);

       
#endif //CRATES_H 
