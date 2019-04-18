/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMaskFilter.h"

#include "sk_maskfilter.h"

#include "sk_types_priv.h"


const struct {
    sk_blurstyle_t  fC;
    SkBlurStyle     fSk;
} gBlurStylePairs[] = {
    { NORMAL_SK_BLUR_STYLE, kNormal_SkBlurStyle },
    { SOLID_SK_BLUR_STYLE,  kSolid_SkBlurStyle },
    { OUTER_SK_BLUR_STYLE,  kOuter_SkBlurStyle },
    { INNER_SK_BLUR_STYLE,  kInner_SkBlurStyle },
};

static bool find_blurstyle(sk_blurstyle_t csrc, SkBlurStyle* dst) {
    for (size_t i = 0; i < SK_ARRAY_COUNT(gBlurStylePairs); ++i) {
        if (gBlurStylePairs[i].fC == csrc) {
            if (dst) {
                *dst = gBlurStylePairs[i].fSk;
            }
            return true;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////
// public APIs
///////////////////////////////////////////////////////////////////////////////////////////

void sk_maskfilter_ref(sk_maskfilter_t* cfilter) {
    SkSafeRef(AsMaskFilter(cfilter));
}

void sk_maskfilter_unref(sk_maskfilter_t* cfilter) {
    SkSafeUnref(AsMaskFilter(cfilter));
}

sk_maskfilter_t* sk_maskfilter_new_blur(sk_blurstyle_t cstyle, float sigma) {
    SkBlurStyle style;
    if (!find_blurstyle(cstyle, &style)) {
        return nullptr;
    }
    return ToMaskFilter(SkMaskFilter::MakeBlur(style, sigma).release());
}
