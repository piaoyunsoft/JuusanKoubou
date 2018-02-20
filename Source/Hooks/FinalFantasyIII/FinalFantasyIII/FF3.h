#ifndef _FF3_H_9eaadcd6_9cc0_402a_801c_9657a557eb3b_
#define _FF3_H_9eaadcd6_9cc0_402a_801c_9657a557eb3b_

#include "ml.h"
#include "Offset.h"

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
        English     = 1,
        French      = 2,
        Italian     = 4,
        German      = 3,
        Spanish     = 5,
        Japanese    = 0,
        ChineseS    = 6,
        ChineseT    = 7,
    };
};

#undef libiconv_open

EXTC_IMPORT PVOID CDECL TTF_OpenFont(PCSTR FileName, LONG PointSize);
EXTC_IMPORT PVOID CDECL libiconv_open(PCSTR tocode, PCSTR fromcode);

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
ff3_libiconv_open(
    PCSTR tocode,
    PCSTR fromcode
);

ULONG FF3_NakedGetCurrentLangID();

#endif // _FF3_H_9eaadcd6_9cc0_402a_801c_9657a557eb3b_
