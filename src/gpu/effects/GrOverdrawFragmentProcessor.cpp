/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrOverdrawFragmentProcessor.fp; do not modify.
 **************************************************************************************************/
#include "GrOverdrawFragmentProcessor.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "GrTexture.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLOverdrawFragmentProcessor : public GrGLSLFragmentProcessor {
public:
    GrGLSLOverdrawFragmentProcessor() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrOverdrawFragmentProcessor& _outer = args.fFp.cast<GrOverdrawFragmentProcessor>();
        (void)_outer;
        auto color0 = _outer.color0();
        (void)color0;
        auto color1 = _outer.color1();
        (void)color1;
        auto color2 = _outer.color2();
        (void)color2;
        auto color3 = _outer.color3();
        (void)color3;
        auto color4 = _outer.color4();
        (void)color4;
        auto color5 = _outer.color5();
        (void)color5;
        fragBuilder->codeAppendf(
                "half alpha = half(255.0 * float(%s.w));\nif (float(alpha) < 0.5) {\n    %s = "
                "half4(%f, %f, %f, %f);\n} else if (float(alpha) < 1.5) {\n    %s = half4(%f, %f, "
                "%f, %f);\n} else if (float(alpha) < 2.5) {\n    %s = half4(%f, %f, %f, %f);\n} "
                "else if (float(alpha) < 3.5) {\n    %s = half4(%f, %f, %f, %f);\n} else if "
                "(float(alpha) < 4.5) {\n    %s = half4(%f, %f, %f, %f);\n} else {\n    %s = "
                "half4(%f, %f, %f, %f);\n}\n",
                args.fInputColor, args.fOutputColor, SkGetPackedR32(_outer.color0()) / 255.0,
                SkGetPackedG32(_outer.color0()) / 255.0, SkGetPackedB32(_outer.color0()) / 255.0,
                SkGetPackedA32(_outer.color0()) / 255.0, args.fOutputColor,
                SkGetPackedR32(_outer.color1()) / 255.0, SkGetPackedG32(_outer.color1()) / 255.0,
                SkGetPackedB32(_outer.color1()) / 255.0, SkGetPackedA32(_outer.color1()) / 255.0,
                args.fOutputColor, SkGetPackedR32(_outer.color2()) / 255.0,
                SkGetPackedG32(_outer.color2()) / 255.0, SkGetPackedB32(_outer.color2()) / 255.0,
                SkGetPackedA32(_outer.color2()) / 255.0, args.fOutputColor,
                SkGetPackedR32(_outer.color3()) / 255.0, SkGetPackedG32(_outer.color3()) / 255.0,
                SkGetPackedB32(_outer.color3()) / 255.0, SkGetPackedA32(_outer.color3()) / 255.0,
                args.fOutputColor, SkGetPackedR32(_outer.color4()) / 255.0,
                SkGetPackedG32(_outer.color4()) / 255.0, SkGetPackedB32(_outer.color4()) / 255.0,
                SkGetPackedA32(_outer.color4()) / 255.0, args.fOutputColor,
                SkGetPackedR32(_outer.color5()) / 255.0, SkGetPackedG32(_outer.color5()) / 255.0,
                SkGetPackedB32(_outer.color5()) / 255.0, SkGetPackedA32(_outer.color5()) / 255.0);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrOverdrawFragmentProcessor::onCreateGLSLInstance() const {
    return new GrGLSLOverdrawFragmentProcessor();
}
void GrOverdrawFragmentProcessor::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                        GrProcessorKeyBuilder* b) const {}
bool GrOverdrawFragmentProcessor::onIsEqual(const GrFragmentProcessor& other) const {
    const GrOverdrawFragmentProcessor& that = other.cast<GrOverdrawFragmentProcessor>();
    (void)that;
    if (fColor0 != that.fColor0) return false;
    if (fColor1 != that.fColor1) return false;
    if (fColor2 != that.fColor2) return false;
    if (fColor3 != that.fColor3) return false;
    if (fColor4 != that.fColor4) return false;
    if (fColor5 != that.fColor5) return false;
    return true;
}
GrOverdrawFragmentProcessor::GrOverdrawFragmentProcessor(const GrOverdrawFragmentProcessor& src)
        : INHERITED(kGrOverdrawFragmentProcessor_ClassID, src.optimizationFlags())
        , fColor0(src.fColor0)
        , fColor1(src.fColor1)
        , fColor2(src.fColor2)
        , fColor3(src.fColor3)
        , fColor4(src.fColor4)
        , fColor5(src.fColor5) {}
std::unique_ptr<GrFragmentProcessor> GrOverdrawFragmentProcessor::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrOverdrawFragmentProcessor(*this));
}
