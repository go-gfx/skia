/*
 * Copyright 2019 Tapir Liu.
 *
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkImage.h"

#include "sk_image.h"

#include "sk_types_priv.h"


///////////////////////////////////////////////////////////////////////////////////////////
// public APIs
///////////////////////////////////////////////////////////////////////////////////////////

sk_image_t* sk_image_new_raster_copy(const sk_imageinfo_t* cinfo, const void* pixels,
                                     size_t rowBytes) {
    SkImageInfo info;
    if (!from_c_imageinfo(*cinfo, &info)) {
        return NULL;
    }
    return (sk_image_t*)SkImage::MakeRasterCopy(SkPixmap(info, pixels, rowBytes)).release();
}

sk_image_t* sk_image_new_from_encoded(const sk_data_t* cdata, const sk_irect_t* subset) {
    return ToImage(SkImage::MakeFromEncoded(sk_ref_sp(AsData(cdata)),
                                           reinterpret_cast<const SkIRect*>(subset)).release());
}

sk_data_t* sk_image_encode(const sk_image_t* cimage) {
    return ToData(AsImage(cimage)->encodeToData().release());
}

void sk_image_ref(const sk_image_t* cimage) {
    AsImage(cimage)->ref();
}

void sk_image_unref(const sk_image_t* cimage) {
    AsImage(cimage)->unref();
}

int sk_image_get_width(const sk_image_t* cimage) {
    return AsImage(cimage)->width();
}

int sk_image_get_height(const sk_image_t* cimage) {
    return AsImage(cimage)->height();
}

uint32_t sk_image_get_unique_id(const sk_image_t* cimage) {
    return AsImage(cimage)->uniqueID();
}
