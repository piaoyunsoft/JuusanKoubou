#ifndef _OFFSET_H_c833450a_3361_4ee5_bb60_337357d936f3_
#define _OFFSET_H_c833450a_3361_4ee5_bb60_337357d936f3_

#include "ml.h"

ML_NAMESPACE_BEGIN(FF3)

static const ULONG_PTR  ImageBase                   = 0x400000;

static const ULONG_PTR  GetCurrentLocaleID          = 0x4F2330 - ImageBase;
static const ULONG_PTR  VerifySaveData              = 0x415DB0 - ImageBase;
static const ULONG_PTR  DebugLog                    = 0x402170 - ImageBase;
static const ULONG_PTR  glResetMatrix               = 0x4036A0 - ImageBase;
static const ULONG_PTR  RenderString                = 0x402D70 - ImageBase;
static const ULONG_PTR  SetItemCountInBattle        = 0x436190 - ImageBase;
static const ULONG_PTR  SetItemCountInBag           = 0x4CF9E8 - ImageBase;
static const ULONG_PTR  SetItemCountInSort          = 0x4D0102 - ImageBase;
static const ULONG_PTR  DynamicConstructor          = 0x4F81EB - ImageBase;
static const ULONG_PTR  DynamicDestructor           = 0x4F811E - ImageBase;
static const ULONG_PTR  GetDamageNumberBuffer       = 0x42AF02 - ImageBase;

static const ULONG&     gCurrentLangID              = *(PULONG)0x5BCA1C;
static const ULONG&     gStageFlags                 = *(PULONG)0x5A5F84;
static const PSTR       gCurrentLangName            = (PSTR)0x5B8720;
static const PBYTE      gSaveData                   = (PBYTE)0x5BCA28;
static const PVOID      gDamageNumberBuffer         = (PVOID)0x56E85C;

static const ULONG_PTR  CheckItemCountInBuy         = (ULONG_PTR)0x48F011 - ImageBase;
static const ULONG_PTR  CheckItemCountInBuyConfirm  = (ULONG_PTR)0x4EF0BE - ImageBase;
static const ULONG_PTR  CheckItemCountInBuyConfirm1 = (ULONG_PTR)0x4EF0BD - ImageBase;
static const ULONG_PTR  CheckItemCountInBuyConfirm2 = (ULONG_PTR)0x4EF0C4 - ImageBase;
static const ULONG_PTR  CheckItemCountInBuyConfirm3 = (ULONG_PTR)0x4EF0D2 - ImageBase;
static const ULONG_PTR  CheckItemCountInBuyConfirm4 = (ULONG_PTR)0x4EF0E7 - ImageBase;
static const ULONG_PTR  CheckItemCountInShop        = (ULONG_PTR)0x48D392 - ImageBase;
static const ULONG_PTR  CheckItemCountInShop2       = (ULONG_PTR)0x4EE96D - ImageBase;

static const ULONG_PTR  MaxDamageDisplay            = (ULONG_PTR)0x42864A - ImageBase;

static const ULONG_PTR  ScreenMirrorOffset          = 0x255B;
static const ULONG_PTR  SizeOfSingleSaveData        = 0x3B40;

ML_NAMESPACE_END

#endif // _OFFSET_H_c833450a_3361_4ee5_bb60_337357d936f3_
