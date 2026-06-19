// =============================================================================
//  LinkedList.h
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created June 1997 by Gary Shaw
// =============================================================================

#ifndef ___LINKEDLIST_H
#define ___LINKEDLIST_H

#include "tiPlatform.h"
#include "Types.h"

// INTERFACE -------------------------------------------------------------------


#ifdef HW_BUILD_FOR_DEBUGGING
    #define LL_ERROR_CHECKING       1           // general error checking
    #define LL_ANAL_CHECKING        0           // extra-anal error checking
    #define LL_VERBOSE_LEVEL        2           // control specific output code
#else
    #define LL_ERROR_CHECKING       0           // general error checking
    #define LL_ANAL_CHECKING        0           // extra-anal error checking
    #define LL_VERBOSE_LEVEL        0           // control specific output code
#endif


typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    struct LinkedList *belongto;
    void *structptr;     //  pointer to beginning of structure containing this node
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    udword num;
} LinkedList;

#define UNINITIALISED_LINKED_LIST  {NULL, NULL, 0}

//  this function should return true if firststruct > secondstruct for ascending order
typedef bool (*MergeSortCompareCb)(void *firststruct,void *secondstruct);


#define listGetStructOfNode(node)       (void *)((node)->structptr)
#define listGetStructOfNonPtrNode(node) (void *)((node).structptr)

#define ClearNode(node)                     \
        (node).next = NULL;                 \
        (node).prev = NULL;                 \
        (node).belongto = NULL;             \
        (node).structptr = NULL;

#define ClearNodePtr(node)                  \
        (node)->next = NULL;                \
        (node)->prev = NULL;                \
        (node)->belongto = NULL;            \
        (node)->structptr = NULL;


#if LL_ANAL_CHECKING
    #define listVerify(list)    listVerifyAnal(list)
#else
    #define listVerify(list)
#endif


#ifdef HW_BUILD_FOR_DEBUGGING
TI_API void listCheckSort(LinkedList *list);
TI_API void listCheckSortGeneral(LinkedList *list, MergeSortCompareCb compare);
#endif

#if LL_ERROR_CHECKING
TI_API void listVerifyAnal(LinkedList *list);
#endif


TI_API void listInit(LinkedList *list);
TI_API void listRemoveAll(LinkedList *list);
TI_API void listDeleteAll(LinkedList *list);
void listAddNode(LinkedList *list,Node *toadd,void *structure);             //  add node to end of list by default
void listAddNodeBeginning(LinkedList *list,Node *toadd,void *structure);    //  add node to beginning of list
TI_API void listAddNodeAfter(Node *node,Node *toadd,void *structure);
TI_API void listAddNodeBefore(Node *node,Node *toadd,void *structure);
TI_API void listMoveNodeToHead(Node *nodeToMove);
TI_API void listRemoveNode(Node *node);
TI_API void listDeleteNode(Node *node);
TI_API void listMoveContentsOfList(LinkedList *dest, LinkedList *source);
TI_API void listMergeSort(LinkedList *list);
TI_API void listInsertSort(LinkedList *list);
TI_API void listMergeSort2(LinkedList *list);
TI_API void listMergeSortGeneral(LinkedList *list, MergeSortCompareCb compare);


#endif
