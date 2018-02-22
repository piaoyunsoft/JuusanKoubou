#include "ml.h"

VOID (*Stub_FF3_SetItemCountInBattle)();

NAKED VOID FF3_SetItemCountInBattle()
{
    INLINE_ASM
    {
        mov     eax, [esp + 4];
        push    esi;
        mov     esi, ecx;
        push    eax;
        call    [Stub_FF3_SetItemCountInBattle];

        mov     eax, [esp + 8];
        or      edx, -1;
        cmp     eax, 0xFF;
        cmova   eax, edx;
        mov     [esi + 2], al;

        pop     esi;

        ret     4;
    }
}

NAKED VOID FF3_SetItemCountInBag()
{
    INLINE_ASM
    {
        add     dword ptr [esp], 0Ah;
        or      eax, -1;
        cmp     ebx, 0xFF;
        cmova   ebx, eax;
        ret;
    }
}

NAKED VOID FF3_SetItemCountInSort()
{
    INLINE_ASM
    {
        add     dword ptr [esp], 0Ah;
        or      ecx, -1;
        cmp     eax, 0xFF;
        cmova   eax, ecx;
        ret;
    }
}
