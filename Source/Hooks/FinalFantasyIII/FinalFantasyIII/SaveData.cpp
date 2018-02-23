#include "FF3.h"

BOOL CDECL FF3_VerifySaveData(/* PVOID Begin @ ecx, PVOID End @ edx */ ULONG ExpectedCheckSum)
{
    return TRUE;
}

ULONG
NTAPI
FF3_GetModuleFileNameA(
    PVOID   Module,
    PSTR    FileName,
    ULONG   Size
)
{
    PLDR_MODULE Exe;
    ULONG_PTR SizeInBytes;

    Exe = Ldr::FindLdrModuleByHandle(nullptr);
    Nls::UnicodeToAnsi(FileName, Size, Exe->FullDllName.Buffer, Exe->FullDllName.Length / sizeof(Exe->FullDllName.Buffer[0]), &SizeInBytes);
    strcpy(findnamea(FileName), "FF3_Win32.exe");
    //*findnamea(FileName) = 0;

    return StrLengthA(FileName);
}

HRESULT
NTAPI
FF3_SHGetFolderPathA(
    HWND    hwnd, 
    int     csidl, 
    HANDLE  Token, 
    DWORD   Flags, 
    PSTR    Path
)
{
    FF3_GetModuleFileNameA(nullptr, Path, MAX_PATH);
    strcpy(findnamea(Path), "SaveData");
    return S_OK;
}
