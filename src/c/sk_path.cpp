/*
 * Copyright 2019 Tapir Liu.
 *
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPath.h"

#include "sk_path.h"

#include "sk_types_priv.h"

//class SkPath;

const struct {
    sk_path_direction_t fC;
    SkPath::Direction   fSk;
} gPathDirMap[] = {
    { CW_SK_PATH_DIRECTION,  SkPath::kCW_Direction },
    { CCW_SK_PATH_DIRECTION, SkPath::kCCW_Direction },
};

static bool from_c_path_direction(sk_path_direction_t cdir, SkPath::Direction* dir) {
    for (size_t i = 0; i < SK_ARRAY_COUNT(gPathDirMap); ++i) {
        if (gPathDirMap[i].fC == cdir) {
            if (dir) {
                *dir = gPathDirMap[i].fSk;
            }
            return true;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////
// public APIs
///////////////////////////////////////////////////////////////////////////////////////////

sk_path_t* sk_path_new() { return (sk_path_t*)new SkPath; }

void sk_path_delete(sk_path_t* cpath) { delete as_path(cpath); }

void sk_path_move_to(sk_path_t* cpath, float x, float y) {
    as_path(cpath)->moveTo(x, y);
}

void sk_path_line_to(sk_path_t* cpath, float x, float y) {
    as_path(cpath)->lineTo(x, y);
}

//void sk_path_arc_to_1(sk_path_t* cpath, const sk_rect_t* oval, float startAngle, float sweepAngle, bool forceMoveTo) {
//    as_path(cpath)->arcTo(AsRect(*oval), startAngle, sweepAngle, forceMoveTo);
//}

void sk_path_arc_to(sk_path_t* cpath, float x1, float y1, float x2, float y2, float radius) {
    as_path(cpath)->arcTo(x1, y1, x2, y2, radius);
}

void sk_path_quad_to(sk_path_t* cpath, float x0, float y0, float x1, float y1) {
    as_path(cpath)->quadTo(x0, y0, x1, y1);
}

void sk_path_conic_to(sk_path_t* cpath, float x0, float y0, float x1, float y1, float w) {
    as_path(cpath)->conicTo(x0, y0, x1, y1, w);
}

void sk_path_cubic_to(sk_path_t* cpath, float x0, float y0, float x1, float y1, float x2, float y2) {
    as_path(cpath)->cubicTo(x0, y0, x1, y1, x2, y2);
}

void sk_path_close(sk_path_t* cpath) {
    as_path(cpath)->close();
}

void sk_path_add_rect(sk_path_t* cpath, const sk_rect_t* crect, sk_path_direction_t cdir) {
    SkPath::Direction dir;
    if (!from_c_path_direction(cdir, &dir)) {
        return;
    }
    as_path(cpath)->addRect(AsRect(*crect), dir);
}

void sk_path_add_oval(sk_path_t* cpath, const sk_rect_t* crect, sk_path_direction_t cdir) {
    SkPath::Direction dir;
    if (!from_c_path_direction(cdir, &dir)) {
        return;
    }
    as_path(cpath)->addOval(AsRect(*crect), dir);
}

void sk_path_add_arc(sk_path_t* cpath, const sk_rect_t* oval, float startAngle, float sweepAngle) {
    as_path(cpath)->addArc(AsRect(*oval), startAngle, sweepAngle);
}

bool sk_path_get_bounds(const sk_path_t* cpath, sk_rect_t* crect) {
    const SkPath& path = AsPath(*cpath);

    if (path.isEmpty()) {
        if (crect) {
            *crect = ToRect(SkRect::MakeEmpty());
        }
        return false;
    }

    if (crect) {
        *crect = ToRect(path.getBounds());
    }
    return true;
}

