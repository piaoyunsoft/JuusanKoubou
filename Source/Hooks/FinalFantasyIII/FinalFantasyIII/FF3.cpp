#pragma comment(linker, "/ENTRY:DllMain")
#pragma comment(linker, "/SECTION:.text,ERW /MERGE:.rdata=.text /MERGE:.data=.text /MERGE:.text1=.text /SECTION:.idata,ERW")
#pragma comment(linker, "/SECTION:.Asuna,ERW /MERGE:.text=.Asuna")

#include "FF3.h"
#include "Battle.h"
#include "ml.cpp"

BOOL UnInitialize(PVOID BaseAddress)
{
    return FALSE;
}

BOOL Initialize(PVOID BaseAddress)
{
    using namespace Mp;

    LdrDisableThreadCalloutsForDll(BaseAddress);

    BOOL IsLauncher = ImageNtHeaders(Ps::CurrentPeb()->ImageBaseAddress)->FileHeader.TimeDateStamp != 0x5385F4FD;

    ml::MlInitialize();

    SetProcessDPIAware();
    BattleInitialize();

    BaseAddress = Ldr::GetExeModuleHandle();

    ULONG64 damage_2e0_start = (ULONG64)(DamageNumberBuffer + 4 + DamageNumberSize * (NumberCount - 1));
    ULONG64 damage_2e0_end   = damage_2e0_start + DamageNumberBufferSize;
    ULONG64 damage_size      = (ULONG64)(DamageNumberSize * NumberCount + 4);

    PATCH_MEMORY_DATA p[] =
    {
        MemoryPatchVa((ULONG64)FF3_SHGetFolderPathA,    sizeof(&FF3_SHGetFolderPathA),      IATLookupRoutineByHash(BaseAddress, HashAPI("SHGetFolderPathA"))),
        MemoryPatchVa((ULONG64)FF3_GetModuleFileNameA,  sizeof(&FF3_GetModuleFileNameA),    IATLookupRoutineByHash(BaseAddress, KERNEL32_GetModuleFileNameA)),

        MemoryPatchVa((ULONG64)FF3_strncmp,             sizeof(&FF3_strncmp),               IATLookupRoutineByHash(BaseAddress, HashAPI("strncmp"))),
        MemoryPatchVa((ULONG64)FF3_TTF_OpenFont,        sizeof(&FF3_TTF_OpenFont),          IATLookupRoutineByEntryNoFix(BaseAddress, TTF_OpenFont)),
        MemoryPatchVa((ULONG64)FF3_libiconv_open,       sizeof(&FF3_libiconv_open),         IATLookupRoutineByEntryNoFix(BaseAddress, libiconv_open)),

        // item max num
        MemoryPatchRva(0x74FFull,       2,  FF3::CheckItemCountInShop),
        MemoryPatchRva(0x745EFFull,     3,  FF3::CheckItemCountInShop2),
        MemoryPatchRva(0xFFull,         4,  FF3::CheckItemCountInBuy),
        MemoryPatchRva(0xEBull,         1,  FF3::CheckItemCountInBuyConfirm),
        MemoryPatchRva(0xEBull,         1,  FF3::CheckItemCountInBuyConfirm4),

        // battle damage
        FunctionJumpRva(FF3::DynamicConstructor,    DynamicConstructor,         &StubDynamicConstructor),
        FunctionJumpRva(FF3::DynamicDestructor,     DynamicDestructor,          &StubDynamicDestructor),
        FunctionCallRva(FF3::GetDamageNumberBuffer, GetDamageNumberBuffer),

        MemoryPatchVa((ULONG64)DamageNumberBuffer,     sizeof(DamageNumberBuffer),        0x4570C4),
        MemoryPatchVa((ULONG64)DamageNumberBuffer,     sizeof(DamageNumberBuffer),        0x4571D4),

        MemoryPatchRva(99999ull,            4,  0x428644 - FF3::ImageBase),
        MemoryPatchRva(10000ull,            4,  0x428651 - FF3::ImageBase),
        MemoryPatchRva((ULONG64)NumberCount,1,  0x4287A2 - FF3::ImageBase),
        MemoryPatchRva((ULONG64)NumberCount,1,  0x4287C6 - FF3::ImageBase),

        MemoryPatchRva(damage_size,         4,  0x429FFF - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x429F29 - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x42AF18 - FF3::ImageBase),

        MemoryPatchRva(damage_2e0_start,    4,  0x44EA54 - FF3::ImageBase),
        MemoryPatchRva(damage_2e0_end,      4,  0x44EA89 - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x44EA7D - FF3::ImageBase),

        MemoryPatchRva(damage_2e0_start,    4,  0x440E08 - FF3::ImageBase),
        MemoryPatchRva(damage_2e0_end,      4,  0x440E45 - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x440E39 - FF3::ImageBase),

        MemoryPatchRva(damage_2e0_start,    4,  0x44AD59 - FF3::ImageBase),
        MemoryPatchRva(damage_2e0_end,      4,  0x44AD7E - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x44AD78 - FF3::ImageBase),

        MemoryPatchRva(damage_2e0_start,    4,  0x44DEB3 - FF3::ImageBase),
        MemoryPatchRva(damage_2e0_end,      4,  0x44DED8 - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x44DED2 - FF3::ImageBase),

        MemoryPatchRva(damage_2e0_start,    4,  0x44E39B - FF3::ImageBase),
        MemoryPatchRva(damage_2e0_end,      4,  0x44E3C9 - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x44E3BD - FF3::ImageBase),

        MemoryPatchRva(damage_2e0_start,    4,  0x455593 - FF3::ImageBase),
        MemoryPatchRva(damage_2e0_end,      4,  0x4555C9 - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x4555BD - FF3::ImageBase),

        MemoryPatchRva(damage_2e0_start,    4,  0x455621 - FF3::ImageBase),
        MemoryPatchRva(damage_2e0_end,      4,  0x455655 - FF3::ImageBase),
        MemoryPatchRva(damage_size,         4,  0x45564E - FF3::ImageBase),

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

    PatchMemory(p, IsLauncher ? 1 : countof(p), BaseAddress);

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
