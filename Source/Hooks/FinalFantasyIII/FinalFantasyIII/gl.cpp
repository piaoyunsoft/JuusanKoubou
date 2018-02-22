#include "FF3.h"

EXTC_IMPORT VOID NTAPI glLoadIdentity();

VOID NTAPI FF3_glResetMatrix()
{
    // disable screen mirroring
    glLoadIdentity();
}
