/******************************************************************************
 * Name:     gdal_adbc.h
 * Project:  GDAL Core
 * Purpose:  GDAL Core ADBC related declarations.
 * Author:   Even Rouault <even dot rouault at spatialys.com>
 *
 ******************************************************************************
 * Copyright (c) 2024, Even Rouault <even dot rouault at spatialys.com>
 *
 * SPDX-License-Identifier: MIT
 ****************************************************************************/

#ifndef GDAL_ADBC_H_INCLUDED
#define GDAL_ADBC_H_INCLUDED

/**
 * \file gdal_adbc.h
 *
 * C GDAL entry points for Arrow Database Connectivity (ADBC)
 *
 * This header can only be used if the ADBC macro is defined, indicating that
 * the adbc.h header has already been included before.
 *
 * \since GDAL 3.11
 */

#include "cpl_port.h"

#ifdef ADBC

CPL_C_START

void CPL_DLL GDALSetAdbcDriverInitFunc(AdbcDriverInitFunc init_func);

AdbcDriverInitFunc CPL_DLL GDALGetAdbcDriverInitFunc(void);

CPL_C_END

#endif

#endif
