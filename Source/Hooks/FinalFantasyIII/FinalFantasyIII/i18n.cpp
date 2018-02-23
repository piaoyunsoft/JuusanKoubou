#include "FF3.h"

ULONG FF3_GetCurrentLocaleID()
{
    ULONG LocaleID;

    switch (FF3::gCurrentLangID)
    {
        case LangID::English:
        default:
            LocaleID = LocaleID::English;
            strcpy(FF3::gCurrentLangName, "en");
            break;

        case LangID::French:
            LocaleID = LocaleID::French;
            strcpy(FF3::gCurrentLangName, "fr");
            break;

        case LangID::Italian:
            LocaleID = LocaleID::Italian;
            strcpy(FF3::gCurrentLangName, "it");
            break;

        case LangID::German:
            LocaleID = LocaleID::German;
            strcpy(FF3::gCurrentLangName, "de");
            break;

        case LangID::Spanish:
            LocaleID = LocaleID::Spanish;
            strcpy(FF3::gCurrentLangName, "es");
            break;

        case LangID::Japanese:
            LocaleID = LocaleID::Japanese;
            strcpy(FF3::gCurrentLangName, "ja");
            break;

        case LangID::ChineseS:
            LocaleID = LocaleID::ChineseS;
            strcpy(FF3::gCurrentLangName, "zh_CN");
            break;

        case LangID::ChineseT:
            LocaleID = LocaleID::ChineseT;
            strcpy(FF3::gCurrentLangName, "zh_TW");
            break;
    }

    return LocaleID;
}

NAKED ULONG FF3_NakedGetCurrentLocaleID()
{
    INLINE_ASM
    {
        push    edx;
        push    ecx;
        call    FF3_GetCurrentLocaleID;
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

            _snprintf(Buffer, countof(Buffer), "font_%s.ttf", FF3::gCurrentLangName);
            FileName = Buffer;
            break;
    }

    return TTF_OpenFont(FileName, PointSize);
}

PVOID
CDECL
FF3_libiconv_open(
    PCSTR tocode,
    PCSTR fromcode
)
{
    if (strcmp(fromcode, "Big5") == 0 || strcmp(fromcode, "GB2312") == 0)
    {
        fromcode = "UTF-8";
    }
    // else if (strcmp(fromcode, "SJIS") == 0)
    // {
    //     tocode = "SJIS";
    //     fromcode = "SJIS";
    // }

    return libiconv_open(tocode, fromcode);
}

LONG
CDECL
FF3_strncmp(
    PCSTR       Str1,
    PCSTR       Str2,
    ULONG_PTR   MaxCount
)
{
    LOOP_ONCE
    {
        if (FF3::gCurrentLangID != LangID::Japanese)
            continue;

        if (strcmp(Str2, "e") != 0)
            break;

        if (strstr(Str1, ".msd") == nullptr)
            break;

        return 1;
    }

    return strncmp(Str1, Str2, MaxCount);
}

NTSTATUS GetCPFileNameFromRegistry(String& NlsFile, ULONG NlsIndex, PCWSTR SubKey = L"System\\CurrentControlSet\\Control\\Nls\\CodePage")
{
    BOOL        Success;
    WCHAR       NlsIndexBuffer[16];
    NTSTATUS    Status;
    PKEY_VALUE_PARTIAL_INFORMATION FileName;

    _snwprintf(NlsIndexBuffer, countof(NlsIndexBuffer), L"%d", NlsIndex);

    Status = GetKeyValue(HKEY_LOCAL_MACHINE, SubKey, NlsIndexBuffer, &FileName);
    FAIL_RETURN(Status);

    NlsFile.CopyFrom((PWSTR)FileName->Data, FileName->DataLength / sizeof(WCHAR));

    FreeKeyInfo(FileName);

    return STATUS_SUCCESS;
}

NTSTATUS
CustomCPToUnicodeSize(
    PCPTABLEINFO    CustomCP,
    PULONG          BytesInUnicodeString,
    PCSTR           MultiByteString,
    ULONG           BytesInMultiByteString
)
{
    ULONG   cbUnicode = 0;
    PUSHORT NlsLeadByteInfo;

    if (CustomCP->DBCSCodePage)
    {
        NlsLeadByteInfo = CustomCP->DBCSOffsets;

        while (BytesInMultiByteString--)
        {
            if (NlsLeadByteInfo[*(PUCHAR)MultiByteString++])
            {
                if (BytesInMultiByteString == 0)
                {
                    cbUnicode += sizeof(WCHAR);
                    break;
                }
                else
                {
                    BytesInMultiByteString--;
                    MultiByteString++;
                }
            }

            cbUnicode += sizeof(WCHAR);
        }

        *BytesInUnicodeString = cbUnicode;
    }
    else
    {
        *BytesInUnicodeString = BytesInMultiByteString * sizeof(WCHAR);
    }

    return STATUS_SUCCESS;
}

NTSTATUS MultiBytesToUTF8(ULONG_PTR Encoding, PCSTR Input, ULONG_PTR InputLength, PSTR Output, ULONG_PTR OutputSize, PULONG_PTR BytesWritten = nullptr)
{
    NTSTATUS Status;

    static PBYTE        CPFileBuffer;
    static CPTABLEINFO  CodePageTable;

    if (CodePageTable.CodePage == 0)
    {
        String          NlsFileName;
        NtFileMemory    NlsFile;

        Status = GetCPFileNameFromRegistry(NlsFileName, Encoding);
        FAIL_RETURN(Status);

        Status = NlsFile.Open(String(L"\\SystemRoot\\system32\\") + NlsFileName, NFD_NOT_RESOLVE_PATH);
        FAIL_RETURN(Status);

        CPFileBuffer = (PBYTE)AllocateMemoryP(NlsFile.GetSize32());
        if (CPFileBuffer == nullptr)
            return STATUS_NO_MEMORY;

        CopyMemory(CPFileBuffer, NlsFile.GetBuffer(), NlsFile.GetSize32());

        RtlInitCodePageTable((PUSHORT)CPFileBuffer, &CodePageTable);
    }

    PWSTR UnicodeString;
    ULONG BytesInUnicodeString;
    ULONG UTF8StringActualByteCount;

    Status = CustomCPToUnicodeSize(&CodePageTable, &BytesInUnicodeString, Input, InputLength);
    FAIL_RETURN(Status);

    UnicodeString = (PWSTR)AllocStack(BytesInUnicodeString);
    Status = RtlCustomCPToUnicodeN(&CodePageTable, UnicodeString, BytesInUnicodeString, &BytesInUnicodeString, Input, InputLength);
    FAIL_RETURN(Status);

    Status = RtlUnicodeToUTF8N(Output, OutputSize, &UTF8StringActualByteCount, UnicodeString, BytesInUnicodeString);
    FAIL_RETURN(Status);

    if (UTF8StringActualByteCount < OutputSize && Output[UTF8StringActualByteCount - 1] != 0)
        Output[UTF8StringActualByteCount] = 0;

    return Status;
}

VOID (FASTCALL *StubRenderString)(PVOID This, PVOID Dummy, PCSTR Text, ULONG p1, ULONG p2);

VOID FASTCALL FF3_RenderString(PVOID This, PVOID Dummy, PCSTR Text, ULONG p1, ULONG p2)
{
    PSTR        Buffer;
    ULONG_PTR   InputLength, OutputLength;
    FLOAT       x, y;

    INLINE_ASM
    {
        movss   x, xmm2;
        movss   y, xmm3;
    }

    LOOP_ONCE
    {
        if (FF3::gCurrentLangID != LangID::Japanese)
            break;

        //PrintConsole(L"Render '%S'\n", Text);

        InputLength = StrLengthA(Text) + 1;
        OutputLength = InputLength * 3;
        Buffer = (PSTR)AllocStack(OutputLength);

        if (NT_FAILED(MultiBytesToUTF8(CP_SHIFTJIS, Text, InputLength, Buffer, OutputLength)))
        {
            Text = "<MultiBytesToUTF8 FAILED>";
            break;
        }

        Text = Buffer;
    }

    INLINE_ASM
    {
        movss   xmm2, x;
        movss   xmm3, y;
    }

    StubRenderString(This, Dummy, Text, p1, p2);
}
