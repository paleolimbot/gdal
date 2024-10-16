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

#include "cpl_port.h"

// Very minimal extract of adbc.h
#define ADBC

CPL_C_START

typedef uint8_t AdbcStatusCode;
struct AdbcError;
typedef AdbcStatusCode (*AdbcDriverInitFunc)(int version, void *driver,
                                             struct AdbcError *error);

CPL_C_END

#include "gdal_adbc.h"

//! Thread local ADBC driver initialization function
static thread_local AdbcDriverInitFunc tlAdbcDriverInitFunc = nullptr;

/************************************************************************/
/*                       GDALSetAdbcDriverInitFunc()                    */
/************************************************************************/

/** Sets the ADBC driver initialization function that should be used during
 * the next calls to the OGR ADBC driver.
 *
 * This is a thread-local setting.
 *
 * When set, it is honored by the OGR ADBC driver to pass the specified
 * initialization function as the argument of
 * AdbcDriverManagerDatabaseSetInitFunc()
 *
 * Setting it to NULL resets to the the default behaviour of the ADBC driver,
 * which is to honor the ADBC_DRIVER open option.
 */
void GDALSetAdbcDriverInitFunc(AdbcDriverInitFunc init_func)
{
    tlAdbcDriverInitFunc = init_func;
}

/************************************************************************/
/*                       GDALGetAdbcDriverInitFunc()                    */
/************************************************************************/

/** Gets the ADBC driver initialization function for the current thread.
 */
AdbcDriverInitFunc GDALGetAdbcDriverInitFunc()
{
    return tlAdbcDriverInitFunc;
}
