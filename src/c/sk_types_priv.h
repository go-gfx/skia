/*
 * Copyright 2019 Tapir Liu.
 *
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_types_priv_DEFINED
#define sk_types_priv_DEFINED

#include "sk_types.h"

class SkMaskFilter;
class SkPaint;
class SkShader;
class SkData;
class SkPath;
class SkRect;
class SkCanvas;
class SkImageInfo;
class SkImage;
class SkPicture;
class SkPictureRecorder;
class SkMatrix;

static inline const SkPaint& AsPaint(const sk_paint_t& cpaint) {
    return reinterpret_cast<const SkPaint&>(cpaint);
}

static inline const SkPaint* AsPaint(const sk_paint_t* cpaint) {
    return reinterpret_cast<const SkPaint*>(cpaint);
}

static inline SkPaint* AsPaint(sk_paint_t* cpaint) {
    return reinterpret_cast<SkPaint*>(cpaint);
}

static inline SkMaskFilter* AsMaskFilter(sk_maskfilter_t* cfilter) {
    return reinterpret_cast<SkMaskFilter*>(cfilter);
}

static inline sk_maskfilter_t* ToMaskFilter(SkMaskFilter* filter) {
    return reinterpret_cast<sk_maskfilter_t*>(filter);
}

static inline SkShader* AsShader(sk_shader_t* cshader) {
    return reinterpret_cast<SkShader*>(cshader);
}

static inline SkData* AsData(const sk_data_t* cdata) {
    return reinterpret_cast<SkData*>(const_cast<sk_data_t*>(cdata));
}

static inline sk_data_t* ToData(SkData* data) {
    return reinterpret_cast<sk_data_t*>(data);
}

static inline sk_rect_t ToRect(const SkRect& rect) {
    return reinterpret_cast<const sk_rect_t&>(rect);
}

static inline const SkRect& AsRect(const sk_rect_t& crect) {
    return reinterpret_cast<const SkRect&>(crect);
}

static inline const SkPath& AsPath(const sk_path_t& cpath) {
    return reinterpret_cast<const SkPath&>(cpath);
}

static inline SkPath* as_path(sk_path_t* cpath) {
    return reinterpret_cast<SkPath*>(cpath);
}

static inline const SkImage* AsImage(const sk_image_t* cimage) {
    return reinterpret_cast<const SkImage*>(cimage);
}

static inline sk_image_t* ToImage(SkImage* cimage) {
    return reinterpret_cast<sk_image_t*>(cimage);
}

static inline sk_canvas_t* ToCanvas(SkCanvas* canvas) {
    return reinterpret_cast<sk_canvas_t*>(canvas);
}

static inline SkCanvas* AsCanvas(sk_canvas_t* ccanvas) {
    return reinterpret_cast<SkCanvas*>(ccanvas);
}

static inline SkPictureRecorder* AsPictureRecorder(sk_picture_recorder_t* crec) {
    return reinterpret_cast<SkPictureRecorder*>(crec);
}

static inline sk_picture_recorder_t* ToPictureRecorder(SkPictureRecorder* rec) {
    return reinterpret_cast<sk_picture_recorder_t*>(rec);
}

static inline const SkPicture* AsPicture(const sk_picture_t* cpic) {
    return reinterpret_cast<const SkPicture*>(cpic);
}

static inline SkPicture* AsPicture(sk_picture_t* cpic) {
    return reinterpret_cast<SkPicture*>(cpic);
}

static inline sk_picture_t* ToPicture(SkPicture* pic) {
    return reinterpret_cast<sk_picture_t*>(pic);
}

///////////////////////////////////////////////////////////////////////////////////////////
// private APIs
///////////////////////////////////////////////////////////////////////////////////////////

bool from_c_imageinfo(const sk_imageinfo_t& cinfo, SkImageInfo* info);

void from_c_matrix(const sk_matrix_t* cmatrix, SkMatrix* matrix);

#endif
