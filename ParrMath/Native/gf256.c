/* SPDX-License-Identifier: AGPL-3.0-only */

#include "WolframLibrary.h"
#include <stdint.h>

DLLEXPORT mint WolframLibrary_getVersion(void) {
    return WolframLibraryVersion;
}

DLLEXPORT int WolframLibrary_initialize(
    WolframLibraryData libData
) {
    (void)libData;
    return LIBRARY_NO_ERROR;
}

DLLEXPORT void WolframLibrary_uninitialize(
    WolframLibraryData libData
) {
    (void)libData;
}

DLLEXPORT int gf256mul(
    WolframLibraryData libData,
    mint Argc,
    MArgument *Args,
    MArgument Res
) {
    (void)libData;

    if (Argc != 2)
        return LIBRARY_FUNCTION_ERROR;

    mint a = MArgument_getInteger(Args[0]);
    mint b = MArgument_getInteger(Args[1]);

    if (a < 0 || a > 255 || b < 0 || b > 255)
        return LIBRARY_FUNCTION_ERROR;

    uint32_t x = (uint32_t)a;
    uint32_t y = (uint32_t)b;
    uint32_t r = 0;

    for (int i = 0; i < 8; ++i) {
        if (y & 1u) r ^= x;
        y >>= 1;
        x <<= 1;
        if (x & 0x100u) x ^= 0x11Bu;
    }

    MArgument_setInteger(Res, (mint)(r & 0xFFu));
    return LIBRARY_NO_ERROR;
}
