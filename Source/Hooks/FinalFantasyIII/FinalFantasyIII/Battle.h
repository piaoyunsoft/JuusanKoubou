#ifndef _BATTLE_H_fb9019ef_b6e1_4c90_b42b_b342301b55a0_
#define _BATTLE_H_fb9019ef_b6e1_4c90_b42b_b342301b55a0_

#include "FF3.h"

typedef struct
{
    ULONG   HPCurrent;
    ULONG   HPMax;

} CHAR_BATTLE_INFO;

static const ULONG_PTR DamageNumberSize = 0xF4;
static const ULONG_PTR NumberCount = 5;
static const ULONG_PTR DamageNumberBufferSize = (DamageNumberSize * NumberCount + 4) * 0xC;
extern PBYTE DamageNumberBuffer;

extern VOID (NTAPI *StubDynamicConstructor)(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Constructor, PVOID Destructor);
VOID NTAPI DynamicConstructor(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Constructor, PVOID Destructor);

extern VOID (NTAPI *StubDynamicDestructor)(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Destructor);
VOID NTAPI DynamicDestructor(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Destructor);

PVOID GetDamageNumberBuffer();

NTSTATUS BattleInitialize();

#endif // _BATTLE_H_fb9019ef_b6e1_4c90_b42b_b342301b55a0_