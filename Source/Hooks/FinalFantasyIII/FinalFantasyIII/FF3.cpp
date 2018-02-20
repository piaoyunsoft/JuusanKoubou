#pragma comment(linker, "/ENTRY:DllMain")
#pragma comment(linker, "/SECTION:.text,ERW /MERGE:.rdata=.text /MERGE:.data=.text /MERGE:.text1=.text /SECTION:.idata,ERW")
#pragma comment(linker, "/SECTION:.Asuna,ERW /MERGE:.text=.Asuna")
#pragma comment(linker, "/EXPORT:MessageBoxA=USER32.MessageBoxA")

#include "FF3.h"
#include "ml.cpp"

BOOL UnInitialize(PVOID BaseAddress)
{
    return FALSE;
}

BOOL Initialize(PVOID BaseAddress)
{
    using namespace Mp;

    LdrDisableThreadCalloutsForDll(BaseAddress);
    ml::MlInitialize();

    SetProcessDPIAware();

    BaseAddress = Ldr::GetExeModuleHandle();

    PATCH_MEMORY_DATA p[] =
    {
        MemoryPatchVa((ULONG64)FF3_GetModuleFileNameA,  sizeof(&FF3_GetModuleFileNameA),    IATLookupRoutineByHash(BaseAddress, KERNEL32_GetModuleFileNameA)),
        MemoryPatchVa((ULONG64)FF3_TTF_OpenFont,        sizeof(&FF3_TTF_OpenFont),          IATLookupRoutineByEntryNoFix(BaseAddress, TTF_OpenFont)),
        MemoryPatchVa((ULONG64)ff3_libiconv_open,       sizeof(&ff3_libiconv_open),         IATLookupRoutineByEntryNoFix(BaseAddress, libiconv_open)),

        FunctionJumpRva(FF3::GetCurrentLangID, FF3_NakedGetCurrentLangID),
    };

    PatchMemory(p, countof(p), BaseAddress);

    return TRUE;
}

BOOL WINAPI DllMain(PVOID BaseAddress, ULONG Reason, PVOID Reserved)
{
    switch (Reason)
    {
        case DLL_PROCESS_ATTACH:
            return Initialize(BaseAddress) || UnInitialize(BaseAddress);

        case DLL_PROCESS_DETACH:
            UnInitialize(BaseAddress);
            break;
    }

    return TRUE;
}
