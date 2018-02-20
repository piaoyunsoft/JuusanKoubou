#ifndef _OFFSET_H_c833450a_3361_4ee5_bb60_337357d936f3_
#define _OFFSET_H_c833450a_3361_4ee5_bb60_337357d936f3_

#include "ml.h"

ML_NAMESPACE_BEGIN(FF3)

static const ULONG_PTR ImageBase           = 0x400000;

static const ULONG_PTR GetCurrentLangID    = 0x4F2330 - ImageBase;

static const ULONG&    gCurrentLangID      = *(PULONG)0x5BCA1C;
static const PSTR      gCurrentLangName    = (PSTR)0x5B8720;

ML_NAMESPACE_END

#endif // _OFFSET_H_c833450a_3361_4ee5_bb60_337357d936f3_
