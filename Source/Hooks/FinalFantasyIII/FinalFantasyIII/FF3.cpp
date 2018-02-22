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
        MemoryPatchVa((ULONG64)FF3_strncmp,             sizeof(&FF3_strncmp),               IATLookupRoutineByHash(BaseAddress, HashAPI("strncmp"))),
        MemoryPatchVa((ULONG64)FF3_TTF_OpenFont,        sizeof(&FF3_TTF_OpenFont),          IATLookupRoutineByEntryNoFix(BaseAddress, TTF_OpenFont)),
        MemoryPatchVa((ULONG64)FF3_libiconv_open,       sizeof(&FF3_libiconv_open),         IATLookupRoutineByEntryNoFix(BaseAddress, libiconv_open)),

        MemoryPatchRva(0x74FFull,       2,  FF3::CheckItemCountInShop),
        MemoryPatchRva(0x745EFFull,     3,  FF3::CheckItemCountInShop2),
        MemoryPatchRva(0xFFull,         4,  FF3::CheckItemCountInBuy),
        MemoryPatchRva(0xEBull,         1,  FF3::CheckItemCountInBuyConfirm),
        MemoryPatchRva(0xEBull,         1,  FF3::CheckItemCountInBuyConfirm4),

        // MemoryPatchRva(0x75FFull,       2,  FF3::CheckItemCountInBuyConfirm1),
        // MemoryPatchRva(0xFFull,         1,  FF3::CheckItemCountInBuyConfirm2),
        // MemoryPatchRva(0xFFull,         1,  FF3::CheckItemCountInBuyConfirm3),

        FunctionJumpRva(FF3::GetCurrentLocaleID,    FF3_NakedGetCurrentLocaleID),
        FunctionJumpRva(FF3::VerifySaveData,        FF3_VerifySaveData),
        FunctionJumpRva(FF3::glResetMatrix,         FF3_glResetMatrix),
        FunctionJumpRva(FF3::SetItemCountInBattle,  FF3_SetItemCountInBattle,   &Stub_FF3_SetItemCountInBattle),
        FunctionCallRva(FF3::SetItemCountInBag,     FF3_SetItemCountInBag),
        FunctionCallRva(FF3::SetItemCountInSort,    FF3_SetItemCountInSort),
        // FunctionJumpRva(FF3::RenderString,          FF3_RenderString,   &StubRenderString),
    };

    PatchMemory(p, countof(p), BaseAddress);

    //AllocConsole();

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
