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

static uint8_t gf_mul(uint8_t a, uint8_t b) {
    uint32_t x = a, y = b, r = 0;
    for (int i = 0; i < 8; ++i) {
        if (y & 1u) r ^= x;
        y >>= 1;
        x <<= 1;
        if (x & 0x100u) x ^= 0x11Bu;
    }
    return (uint8_t)(r & 0xFFu);
}

static uint8_t gf_inv(uint8_t a) {
    if (a == 0) return 0;
    uint8_t r = 1, b = a;
    int e = 254;
    while (e > 0) {
        if (e & 1) r = gf_mul(r, b);
        b = gf_mul(b, b);
        e >>= 1;
    }
    return r;
}

static uint8_t affine(uint8_t b) {
    uint8_t r = 0;
    for (int i = 0; i < 8; ++i) {
        uint8_t bit = ((b >> i) & 1)
                    ^ ((b >> ((i + 4) & 7)) & 1)
                    ^ ((b >> ((i + 5) & 7)) & 1)
                    ^ ((b >> ((i + 6) & 7)) & 1)
                    ^ ((b >> ((i + 7) & 7)) & 1)
                    ^ ((0x63 >> i) & 1);
        r |= (bit << i);
    }
    return r;
}

static uint8_t inv_affine(uint8_t b) {
    uint8_t r = 0;
    const uint8_t c = 0x05;
    for (int i = 0; i < 8; ++i) {
        uint8_t bit = ((b >> ((i + 2) & 7)) & 1)
                    ^ ((b >> ((i + 5) & 7)) & 1)
                    ^ ((b >> ((i + 7) & 7)) & 1)
                    ^ ((c >> i) & 1);
        r |= (bit << i);
    }
    return r;
}

DLLEXPORT int gf256mul(
    WolframLibraryData libData,
    mint Argc,
    MArgument *Args,
    MArgument Res
) {
    (void)libData;
    if (Argc != 2) return LIBRARY_FUNCTION_ERROR;
    mint a = MArgument_getInteger(Args[0]);
    mint b = MArgument_getInteger(Args[1]);
    if (a < 0 || a > 255 || b < 0 || b > 255)
        return LIBRARY_FUNCTION_ERROR;
    MArgument_setInteger(Res, gf_mul((uint8_t)a, (uint8_t)b));
    return LIBRARY_NO_ERROR;
}

DLLEXPORT int aes_sbox(
    WolframLibraryData libData,
    mint Argc,
    MArgument *Args,
    MArgument Res
) {
    (void)libData;
    if (Argc != 1) return LIBRARY_FUNCTION_ERROR;
    mint a = MArgument_getInteger(Args[0]);
    if (a < 0 || a > 255) return LIBRARY_FUNCTION_ERROR;
    MArgument_setInteger(Res, affine(gf_inv((uint8_t)a)));
    return LIBRARY_NO_ERROR;
}

DLLEXPORT int aes_inv_sbox(
    WolframLibraryData libData,
    mint Argc,
    MArgument *Args,
    MArgument Res
) {
    (void)libData;
    if (Argc != 1) return LIBRARY_FUNCTION_ERROR;
    mint a = MArgument_getInteger(Args[0]);
    if (a < 0 || a > 255) return LIBRARY_FUNCTION_ERROR;
    MArgument_setInteger(Res, gf_inv(inv_affine((uint8_t)a)));
    return LIBRARY_NO_ERROR;
}
