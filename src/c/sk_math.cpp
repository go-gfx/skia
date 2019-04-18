/*
 * Copyright 2019 Tapir Liu.
 *
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMatrix.h"

#include "sk_types_priv.h"

///////////////////////////////////////////////////////////////////////////////////////////
// private APIs
///////////////////////////////////////////////////////////////////////////////////////////

// priv api
void from_c_matrix(const sk_matrix_t* cmatrix, SkMatrix* matrix) {
    matrix->setAll(cmatrix->mat[0], cmatrix->mat[1], cmatrix->mat[2],
                   cmatrix->mat[3], cmatrix->mat[4], cmatrix->mat[5],
                   cmatrix->mat[6], cmatrix->mat[7], cmatrix->mat[8]);
}

///////////////////////////////////////////////////////////////////////////////////////////
// public APIs
///////////////////////////////////////////////////////////////////////////////////////////
