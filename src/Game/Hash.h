// =============================================================================
//  Hash.h
//  - reasonably generic hash table using uints as keys
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created 1/9/1998 by khent
// =============================================================================

#ifndef ___HASH_H
#define ___HASH_H

#include "tiPlatform.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------

typedef struct hash_s
{
    udword key;
    void*  data;
    struct hash_s* next;
} hash_t;

typedef struct
{
    udword  size;
    udword  maxkey;
    hash_t* table[1];
} hashtable;

TI_API hashtable* hashNewTable(udword size);
TI_API void  hashDeleteTable(hashtable* table);
TI_API void* hashLookup(hashtable const* table, udword key);
TI_API void  hashInsert(hashtable* table, udword key, void* data);
TI_API void  hashRemove(hashtable* table, udword key);
TI_API udword hashFindFreeKeyBlock(hashtable* table, udword numkeys);

#endif
