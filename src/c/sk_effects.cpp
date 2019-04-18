/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMatrix.h"

#include "../../include/effects/SkGradientShader.h"
#include "sk_shader.h"

#include "sk_types_priv.h"

const struct {
    sk_shader_tilemode_t    fC;
    SkShader::TileMode      fSK;
} gTileModeMap[] = {
    { CLAMP_SK_SHADER_TILEMODE,     SkShader::kClamp_TileMode },
    { REPEAT_SK_SHADER_TILEMODE,    SkShader::kRepeat_TileMode },
    { MIRROR_SK_SHADER_TILEMODE,    SkShader::kMirror_TileMode  },
};

static bool from_c_tilemode(sk_shader_tilemode_t cMode, SkShader::TileMode* skMode) {
    for (size_t i = 0; i < SK_ARRAY_COUNT(gTileModeMap); ++i) {
        if (cMode == gTileModeMap[i].fC) {
            if (skMode) {
                *skMode = gTileModeMap[i].fSK;
            }
            return true;
        }
    }
    return false;
}

static const SkPoint& to_skpoint(const sk_point_t& p) {
    return reinterpret_cast<const SkPoint&>(p);
}

///////////////////////////////////////////////////////////////////////////////////////////
// public APIs
///////////////////////////////////////////////////////////////////////////////////////////

void sk_shader_ref(sk_shader_t* cshader) {
    SkSafeRef(AsShader(cshader));
}

void sk_shader_unref(sk_shader_t* cshader) {
    SkSafeUnref(AsShader(cshader));
}

sk_shader_t* sk_shader_new_linear_gradient(const sk_point_t pts[2],
                                           const sk_color_t colors[],
                                           const float colorPos[],
                                           int colorCount,
                                           sk_shader_tilemode_t cmode,
                                           const sk_matrix_t* cmatrix) {
    SkShader::TileMode mode;
    if (!from_c_tilemode(cmode, &mode)) {
        return nullptr;
    }
    SkMatrix matrix;
    if (cmatrix) {
        from_c_matrix(cmatrix, &matrix);
    } else {
        matrix.setIdentity();
    }
    return (sk_shader_t*)SkGradientShader::MakeLinear(reinterpret_cast<const SkPoint*>(pts),
                                                      reinterpret_cast<const SkColor*>(colors),
                                                      colorPos, colorCount,
                                                      mode, 0, &matrix).release();
}

sk_shader_t* sk_shader_new_radial_gradient(const sk_point_t* ccenter,
                                           float radius,
                                           const sk_color_t colors[],
                                           const float colorPos[],
                                           int colorCount,
                                           sk_shader_tilemode_t cmode,
                                           const sk_matrix_t* cmatrix) {
    SkShader::TileMode mode;
    if (!from_c_tilemode(cmode, &mode)) {
        return nullptr;
    }
    SkMatrix matrix;
    if (cmatrix) {
        from_c_matrix(cmatrix, &matrix);
    } else {
        matrix.setIdentity();
    }
    SkPoint center = to_skpoint(*ccenter);
    return (sk_shader_t*)SkGradientShader::MakeRadial(center, (SkScalar)radius,
                                                      reinterpret_cast<const SkColor*>(colors),
                                                      reinterpret_cast<const SkScalar*>(colorPos),
                                                      colorCount, mode, 0, &matrix).release();
}

sk_shader_t* sk_shader_new_sweep_gradient(const sk_point_t* ccenter,
                                          const sk_color_t colors[],
                                          const float colorPos[],
                                          int colorCount,
                                          const sk_matrix_t* cmatrix) {
    SkMatrix matrix;
    if (cmatrix) {
        from_c_matrix(cmatrix, &matrix);
    } else {
        matrix.setIdentity();
    }
    return (sk_shader_t*)SkGradientShader::MakeSweep((SkScalar)(ccenter->x),
                                                     (SkScalar)(ccenter->y),
                                                     reinterpret_cast<const SkColor*>(colors),
                                                     reinterpret_cast<const SkScalar*>(colorPos),
                                                     colorCount, 0, &matrix).release();
}

sk_shader_t* sk_shader_new_two_point_conical_gradient(const sk_point_t* start,
                                                      float startRadius,
                                                      const sk_point_t* end,
                                                      float endRadius,
                                                      const sk_color_t colors[],
                                                      const float colorPos[],
                                                      int colorCount,
                                                      sk_shader_tilemode_t cmode,
                                                      const sk_matrix_t* cmatrix) {
    SkShader::TileMode mode;
    if (!from_c_tilemode(cmode, &mode)) {
        return nullptr;
    }
    SkMatrix matrix;
    if (cmatrix) {
        from_c_matrix(cmatrix, &matrix);
    } else {
        matrix.setIdentity();
    }
    SkPoint skstart = to_skpoint(*start);
    SkPoint skend = to_skpoint(*end);
    return (sk_shader_t*)SkGradientShader::MakeTwoPointConical(skstart, (SkScalar)startRadius,
                                                        skend, (SkScalar)endRadius,
                                                        reinterpret_cast<const SkColor*>(colors),
                                                        reinterpret_cast<const SkScalar*>(colorPos),
                                                        colorCount, mode, 0, &matrix).release();
}
