#include "FF3.h"

ULONG
NTAPI
FF3_GetModuleFileNameA(
    PVOID   Module,
    PSTR    Filename,
    ULONG   Size
)
{
    PLDR_MODULE Exe;
    ULONG_PTR SizeInBytes;

    // static CHAR ExeName[] = "FF3_Win32.exe";

    Exe = Ldr::FindLdrModuleByHandle(nullptr);

    Nls::UnicodeToAnsi(Filename, Size, Exe->FullDllName.Buffer, Exe->FullDllName.Length / sizeof(Exe->FullDllName.Buffer[0]), &SizeInBytes);

    strcpy(findnamea(Filename), "FF3_Win32.exe");

    return StrLengthA(Filename);
}

ULONG FF3_GetCurrentLangID()
{
    ULONG LangID;

    switch (FF3::gCurrentLangID)
    {
        case LangID::English:
        default:
            LangID = LocaleID::English;
            strcpy(FF3::gCurrentLangName, "en");
            break;

        case LangID::French:
            LangID = LocaleID::French;
            strcpy(FF3::gCurrentLangName, "fr");
            break;

        case LangID::Italian:
            LangID = LocaleID::Italian;
            strcpy(FF3::gCurrentLangName, "it");
            break;

        case LangID::German:
            LangID = LocaleID::German;
            strcpy(FF3::gCurrentLangName, "de");
            break;

        case LangID::Spanish:
            LangID = LocaleID::Spanish;
            strcpy(FF3::gCurrentLangName, "es");
            break;

        case LangID::Japanese:
            LangID = LocaleID::Japanese;
            strcpy(FF3::gCurrentLangName, "ja");
            break;

        case LangID::ChineseS:
            LangID = LocaleID::ChineseS;
            strcpy(FF3::gCurrentLangName, "zh_CN");
            break;

        case LangID::ChineseT:
            LangID = LocaleID::ChineseT;
            strcpy(FF3::gCurrentLangName, "zh_TW");
            break;
    }

    return LangID;
}

NAKED ULONG FF3_NakedGetCurrentLangID()
{
    INLINE_ASM
    {
        push    edx;
        push    ecx;
        call    FF3_GetCurrentLangID;
        pop     ecx;
        pop     edx;
        ret;
    }
}

PVOID
CDECL
FF3_TTF_OpenFont(
    PCSTR   FileName,
    LONG    PointSize
)
{
    CHAR Buffer[0x100];

    switch (FF3::gCurrentLangID)
    {
        case LangID::Japanese:
        case LangID::ChineseS:
        case LangID::ChineseT:
            if (FF3::gCurrentLangName[0] == 0)
                break;

            _snprintf(Buffer, countof(Buffer), "%s.ttf", FF3::gCurrentLangName);
            FileName = Buffer;
            break;
    }

    return TTF_OpenFont(FileName, PointSize);
}

PVOID
CDECL
ff3_libiconv_open(
    PCSTR tocode,
    PCSTR fromcode
)
{
    if (strcmp(fromcode, "Big5") == 0 || strcmp(fromcode, "GB2312") == 0)
        fromcode = "UTF-8";

    return libiconv_open(tocode, fromcode);
}
