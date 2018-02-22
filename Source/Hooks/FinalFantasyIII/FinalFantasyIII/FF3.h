#ifndef _FF3_H_9eaadcd6_9cc0_402a_801c_9657a557eb3b_
#define _FF3_H_9eaadcd6_9cc0_402a_801c_9657a557eb3b_

#include "ml.h"
#include "Offset.h"

using ml::String;

/*++

    i18n

--*/

struct LangID
{
    enum
    {
        English     = 0,
        French      = 1,
        Italian     = 2,
        German      = 3,
        Spanish     = 4,
        Japanese    = 5,
        ChineseS    = 6,
        ChineseT    = 7,
    };
};

struct LocaleID
{
    enum
    {
        Japanese    = 0,
        English     = 1,
        French      = 2,
        German      = 3,
        Italian     = 4,
        Spanish     = 5,
        ChineseS    = 6,
        ChineseT    = 7,
    };
};

EXTC_IMPORT PVOID CDECL TTF_OpenFont(PCSTR FileName, LONG PointSize);
EXTC_IMPORT PVOID CDECL libiconv_open(PCSTR tocode, PCSTR fromcode);
EXTC_IMPORT ULONG_PTR CDECL libiconv(PVOID cd, PCSTR* inbuf, PULONG_PTR inbytesleft, PSTR* outbuf, PULONG_PTR outbytesleft);
EXTC_IMPORT LONG CDECL libiconv_close(PVOID cd);

ULONG
NTAPI
FF3_GetModuleFileNameA(
    PVOID   Module,
    PSTR    Filename,
    ULONG   Size
);

PVOID
CDECL
FF3_TTF_OpenFont(
    PCSTR   FileName,
    LONG    PointSize
);

PVOID
CDECL
FF3_libiconv_open(
    PCSTR tocode,
    PCSTR fromcode
);

LONG
CDECL
FF3_strncmp(
    PCSTR       Str1,
    PCSTR       Str2,
    ULONG_PTR   MaxCount
);

ULONG FF3_NakedGetCurrentLocaleID();

BOOL CDECL FF3_VerifySaveData(/* PVOID Begin @ ecx, PVOID End @ edx */ ULONG ExpectedCheckSum);

VOID NTAPI FF3_glResetMatrix();

extern VOID (FASTCALL *StubRenderString)(PVOID This, PVOID Dummy, PCSTR Text, ULONG p1, ULONG p2);
VOID FASTCALL FF3_RenderString(PVOID This, PVOID Dummy, PCSTR Text, ULONG p1, ULONG p2);


/*++

    item

--*/

extern VOID (*Stub_FF3_SetItemCountInBattle)();
VOID FF3_SetItemCountInBattle();

VOID FF3_SetItemCountInBag();
VOID FF3_SetItemCountInSort();

#endif // _FF3_H_9eaadcd6_9cc0_402a_801c_9657a557eb3b_
