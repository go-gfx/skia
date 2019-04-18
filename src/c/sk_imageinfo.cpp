/*
 * Copyright 2019 Tapir Liu.
 *
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkImageInfo.h"

#include "sk_types_priv.h"



const struct {
    sk_colortype_t  fC;
    SkColorType     fSK;
} gColorTypeMap[] = {
    { UNKNOWN_SK_COLORTYPE,     kUnknown_SkColorType    },
    { RGBA_8888_SK_COLORTYPE,   kRGBA_8888_SkColorType  },
    { BGRA_8888_SK_COLORTYPE,   kBGRA_8888_SkColorType  },
    { ALPHA_8_SK_COLORTYPE,     kAlpha_8_SkColorType    },
};

static bool from_c_colortype(sk_colortype_t cCT, SkColorType* skCT) {
    for (size_t i = 0; i < SK_ARRAY_COUNT(gColorTypeMap); ++i) {
        if (gColorTypeMap[i].fC == cCT) {
            if (skCT) {
                *skCT = gColorTypeMap[i].fSK;
            }
            return true;
        }
    }
    return false;
}

static bool to_c_colortype(SkColorType skCT, sk_colortype_t* cCT) {
    for (size_t i = 0; i < SK_ARRAY_COUNT(gColorTypeMap); ++i) {
        if (gColorTypeMap[i].fSK == skCT) {
            if (cCT) {
                *cCT = gColorTypeMap[i].fC;
            }
            return true;
        }
    }
    return false;
}

const struct {
    sk_alphatype_t  fC;
    SkAlphaType     fSK;
} gAlphaTypeMap[] = {
    { OPAQUE_SK_ALPHATYPE,      kOpaque_SkAlphaType     },
    { PREMUL_SK_ALPHATYPE,      kPremul_SkAlphaType     },
    { UNPREMUL_SK_ALPHATYPE,    kUnpremul_SkAlphaType   },
};

static bool from_c_alphatype(sk_alphatype_t cAT, SkAlphaType* skAT) {
    for (size_t i = 0; i < SK_ARRAY_COUNT(gAlphaTypeMap); ++i) {
        if (gAlphaTypeMap[i].fC == cAT) {
            if (skAT) {
                *skAT = gAlphaTypeMap[i].fSK;
            }
            return true;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////
// private APIs
///////////////////////////////////////////////////////////////////////////////////////////

// priv api
bool from_c_imageinfo(const sk_imageinfo_t& cinfo, SkImageInfo* info) {
    SkColorType ct;
    SkAlphaType at;

    if (!from_c_colortype(cinfo.colorType, &ct)) {
        // optionally report error to client?
        return false;
    }
    if (!from_c_alphatype(cinfo.alphaType, &at)) {
        // optionally report error to client?
        return false;
    }
    if (info) {
        *info = SkImageInfo::Make(cinfo.width, cinfo.height, ct, at);
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////
// public APIs
///////////////////////////////////////////////////////////////////////////////////////////

sk_colortype_t sk_colortype_get_default_8888() {
    sk_colortype_t ct;
    if (!to_c_colortype(kN32_SkColorType, &ct)) {
        ct = UNKNOWN_SK_COLORTYPE;
    }
    return ct;
}
