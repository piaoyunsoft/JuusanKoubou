#include "Battle.h"

//BYTE DamageNumberBuffer[DamageNumberBufferSize];
PBYTE DamageNumberBuffer;

NTSTATUS BattleInitialize()
{
    DamageNumberBuffer = (PBYTE)AllocateMemoryP(DamageNumberBufferSize);
    return STATUS_SUCCESS;
}

VOID (NTAPI *StubDynamicConstructor)(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Constructor, PVOID Destructor);

VOID NTAPI DynamicConstructor(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Constructor, PVOID Destructor)
{
    if (Buffer == FF3::gDamageNumberBuffer && SizeOfElement == 0x3D4 && Count == 0xC)
    {
        FillMemory(Buffer, SizeOfElement * Count, 0xFF);
        Buffer = DamageNumberBuffer;
        SizeOfElement = DamageNumberBufferSize / Count;
    }
    else if (SizeOfElement == DamageNumberSize && Count == 0x4 && (ULONG_PTR)Constructor == 0x41B020)
    {
        Count = NumberCount;
    }

    StubDynamicConstructor(Buffer, SizeOfElement, Count, Constructor, Destructor);
}

VOID (NTAPI *StubDynamicDestructor)(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Destructor);

VOID NTAPI DynamicDestructor(PVOID Buffer, ULONG_PTR SizeOfElement, ULONG_PTR Count, PVOID Destructor)
{
    if (Buffer == FF3::gDamageNumberBuffer && SizeOfElement == 0x3D4 && Count == 0xC)
    {
        Buffer = DamageNumberBuffer;
        SizeOfElement = DamageNumberBufferSize / Count;
    }

    StubDynamicDestructor(Buffer, SizeOfElement, Count, Destructor);
}

NAKED PVOID GetDamageNumberBuffer()
{
    INLINE_ASM
    {
        mov     esi, [DamageNumberBuffer];
        ret;
    }
}
