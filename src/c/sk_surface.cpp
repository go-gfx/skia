/*
 * Copyright 2019 Tapir Liu.
 *
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkSurface.h"

#include "sk_surface.h"

#include "sk_types_priv.h"

const struct {
    sk_pixelgeometry_t fC;
    SkPixelGeometry    fSK;
} gPixelGeometryMap[] = {
    { UNKNOWN_SK_PIXELGEOMETRY, kUnknown_SkPixelGeometry },
    { RGB_H_SK_PIXELGEOMETRY,   kRGB_H_SkPixelGeometry   },
    { BGR_H_SK_PIXELGEOMETRY,   kBGR_H_SkPixelGeometry   },
    { RGB_V_SK_PIXELGEOMETRY,   kRGB_V_SkPixelGeometry   },
    { BGR_V_SK_PIXELGEOMETRY,   kBGR_V_SkPixelGeometry   },
};


static bool from_c_pixelgeometry(sk_pixelgeometry_t cGeom, SkPixelGeometry* skGeom) {
    for (size_t i = 0; i < SK_ARRAY_COUNT(gPixelGeometryMap); ++i) {
        if (gPixelGeometryMap[i].fC == cGeom) {
            if (skGeom) {
                *skGeom = gPixelGeometryMap[i].fSK;
            }
            return true;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////
// public APIs
///////////////////////////////////////////////////////////////////////////////////////////

sk_surface_t* sk_surface_new_raster(const sk_imageinfo_t* cinfo,
                                    const sk_surfaceprops_t* props) {
    SkImageInfo info;
    if (!from_c_imageinfo(*cinfo, &info)) {
        return NULL;
    }
    SkPixelGeometry geo = kUnknown_SkPixelGeometry;
    if (props && !from_c_pixelgeometry(props->pixelGeometry, &geo)) {
        return NULL;
    }

    SkSurfaceProps surfProps(0, geo);
    return (sk_surface_t*)SkSurface::MakeRaster(info, &surfProps).release();
}

sk_surface_t* sk_surface_new_raster_direct(const sk_imageinfo_t* cinfo, void* pixels,
                                           size_t rowBytes,
                                           const sk_surfaceprops_t* props) {
    SkImageInfo info;
    if (!from_c_imageinfo(*cinfo, &info)) {
        return NULL;
    }
    SkPixelGeometry geo = kUnknown_SkPixelGeometry;
    if (props && !from_c_pixelgeometry(props->pixelGeometry, &geo)) {
        return NULL;
    }

    SkSurfaceProps surfProps(0, geo);
    return (sk_surface_t*)SkSurface::MakeRasterDirect(info, pixels, rowBytes, &surfProps).release();
}

void sk_surface_unref(sk_surface_t* csurf) {
    SkSafeUnref((SkSurface*)csurf);
}

sk_canvas_t* sk_surface_get_canvas(sk_surface_t* csurf) {
    SkSurface* surf = (SkSurface*)csurf;
    return (sk_canvas_t*)surf->getCanvas();
}

sk_image_t* sk_surface_new_image_snapshot(sk_surface_t* csurf) {
    SkSurface* surf = (SkSurface*)csurf;
    return (sk_image_t*)surf->makeImageSnapshot().release();
}

