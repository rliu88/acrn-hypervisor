/*
 * Copyright (C) 2021 Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __PTM_H__
#define __PTM_H__

#include "passthru.h"

int ptm_probe(struct vmctx *ctx, struct passthru_dev *pdev);

#endif