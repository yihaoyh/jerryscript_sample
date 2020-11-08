/* Copyright JS Foundation and other contributors, http://js.foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Date.prototype built-in description
 */

#include "ecma-builtin-helpers-macro-defines.inc.h"

#if ENABLED (JERRY_BUILTIN_DATE)

OBJECT_VALUE (LIT_MAGIC_STRING_CONSTRUCTOR,
              ECMA_BUILTIN_ID_DATE,
              ECMA_PROPERTY_CONFIGURABLE_WRITABLE)

ROUTINE (LIT_MAGIC_STRING_TO_STRING_UL, ECMA_DATE_PROTOTYPE_TO_STRING, 0, 0)
ROUTINE (LIT_MAGIC_STRING_TO_DATE_STRING_UL, ECMA_DATE_PROTOTYPE_TO_DATE_STRING, 0, 0)
ROUTINE (LIT_MAGIC_STRING_TO_TIME_STRING_UL, ECMA_DATE_PROTOTYPE_TO_TIME_STRING, 0, 0)
ROUTINE (LIT_MAGIC_STRING_TO_LOCALE_STRING_UL, ECMA_DATE_PROTOTYPE_TO_STRING, 0, 0)
ROUTINE (LIT_MAGIC_STRING_TO_LOCALE_DATE_STRING_UL, ECMA_DATE_PROTOTYPE_TO_DATE_STRING, 0, 0)
ROUTINE (LIT_MAGIC_STRING_TO_LOCALE_TIME_STRING_UL, ECMA_DATE_PROTOTYPE_TO_TIME_STRING, 0, 0)
ROUTINE (LIT_MAGIC_STRING_VALUE_OF_UL, ECMA_DATE_PROTOTYPE_GET_TIME, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_TIME_UL, ECMA_DATE_PROTOTYPE_GET_TIME, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_FULL_YEAR_UL, ECMA_DATE_PROTOTYPE_GET_FULL_YEAR, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_FULL_YEAR_UL, ECMA_DATE_PROTOTYPE_GET_UTC_FULL_YEAR, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_MONTH_UL, ECMA_DATE_PROTOTYPE_GET_MONTH, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_MONTH_UL, ECMA_DATE_PROTOTYPE_GET_UTC_MONTH, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_DATE_UL, ECMA_DATE_PROTOTYPE_GET_DATE, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_DATE_UL, ECMA_DATE_PROTOTYPE_GET_UTC_DATE, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_DAY_UL, ECMA_DATE_PROTOTYPE_GET_DAY, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_DAY_UL, ECMA_DATE_PROTOTYPE_GET_UTC_DAY, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_HOURS_UL, ECMA_DATE_PROTOTYPE_GET_HOURS, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_HOURS_UL, ECMA_DATE_PROTOTYPE_GET_UTC_HOURS, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_MINUTES_UL, ECMA_DATE_PROTOTYPE_GET_MINUTES, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_MINUTES_UL, ECMA_DATE_PROTOTYPE_GET_UTC_MINUTES, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_SECONDS_UL, ECMA_DATE_PROTOTYPE_GET_SECONDS, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_SECONDS_UL, ECMA_DATE_PROTOTYPE_GET_UTC_SECONDS, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_MILLISECONDS_UL, ECMA_DATE_PROTOTYPE_GET_MILLISECONDS, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_UTC_MILLISECONDS_UL, ECMA_DATE_PROTOTYPE_GET_UTC_MILLISECONDS, 0, 0)
ROUTINE (LIT_MAGIC_STRING_GET_TIMEZONE_OFFSET_UL, ECMA_DATE_PROTOTYPE_GET_UTC_TIMEZONE_OFFSET, 0, 0)
ROUTINE (LIT_MAGIC_STRING_SET_TIME_UL, ECMA_DATE_PROTOTYPE_SET_TIME, 1, 1)
ROUTINE (LIT_MAGIC_STRING_SET_MILLISECONDS_UL, ECMA_DATE_PROTOTYPE_SET_MILLISECONDS, 1, 1)
ROUTINE (LIT_MAGIC_STRING_SET_UTC_MILLISECONDS_UL, ECMA_DATE_PROTOTYPE_SET_UTC_MILLISECONDS, 1, 1)
ROUTINE (LIT_MAGIC_STRING_SET_SECONDS_UL, ECMA_DATE_PROTOTYPE_SET_SECONDS, 2, 2)
ROUTINE (LIT_MAGIC_STRING_SET_UTC_SECONDS_UL, ECMA_DATE_PROTOTYPE_SET_UTC_SECONDS, 2, 2)
ROUTINE (LIT_MAGIC_STRING_SET_MINUTES_UL, ECMA_DATE_PROTOTYPE_SET_MINUTES, NON_FIXED, 3)
ROUTINE (LIT_MAGIC_STRING_SET_UTC_MINUTES_UL, ECMA_DATE_PROTOTYPE_SET_UTC_MINUTES, NON_FIXED, 3)
ROUTINE (LIT_MAGIC_STRING_SET_HOURS_UL, ECMA_DATE_PROTOTYPE_SET_HOURS, NON_FIXED, 4)
ROUTINE (LIT_MAGIC_STRING_SET_UTC_HOURS_UL, ECMA_DATE_PROTOTYPE_SET_UTC_HOURS, NON_FIXED, 4)
ROUTINE (LIT_MAGIC_STRING_SET_DATE_UL, ECMA_DATE_PROTOTYPE_SET_DATE, 1, 1)
ROUTINE (LIT_MAGIC_STRING_SET_UTC_DATE_UL, ECMA_DATE_PROTOTYPE_SET_UTC_DATE, 1, 1)
ROUTINE (LIT_MAGIC_STRING_SET_MONTH_UL, ECMA_DATE_PROTOTYPE_SET_MONTH, 2, 2)
ROUTINE (LIT_MAGIC_STRING_SET_UTC_MONTH_UL, ECMA_DATE_PROTOTYPE_SET_UTC_MONTH, 2, 2)
ROUTINE (LIT_MAGIC_STRING_SET_FULL_YEAR_UL, ECMA_DATE_PROTOTYPE_SET_FULL_YEAR, NON_FIXED, 3)
ROUTINE (LIT_MAGIC_STRING_SET_UTC_FULL_YEAR_UL, ECMA_DATE_PROTOTYPE_SET_UTC_FULL_YEAR, NON_FIXED, 3)
ROUTINE (LIT_MAGIC_STRING_TO_ISO_STRING_UL, ECMA_DATE_PROTOTYPE_TO_ISO_STRING, 0, 0)
ROUTINE (LIT_MAGIC_STRING_TO_JSON_UL, ECMA_DATE_PROTOTYPE_TO_JSON, 1, 1)
#if ENABLED (JERRY_ESNEXT)
ROUTINE_CONFIGURABLE_ONLY (LIT_GLOBAL_SYMBOL_TO_PRIMITIVE, ECMA_DATE_PROTOTYPE_TO_PRIMITIVE, 1, 1)
INTRINSIC_PROPERTY (LIT_MAGIC_STRING_TO_UTC_STRING_UL, LIT_MAGIC_STRING_TO_UTC_STRING_UL,
                    ECMA_PROPERTY_CONFIGURABLE_WRITABLE)
#if ENABLED (JERRY_BUILTIN_ANNEXB)
INTRINSIC_PROPERTY (LIT_MAGIC_STRING_TO_GMT_STRING_UL, LIT_MAGIC_STRING_TO_UTC_STRING_UL,
                    ECMA_PROPERTY_CONFIGURABLE_WRITABLE)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#else /* !ENABLED (JERRY_ESNEXT) */
ROUTINE (LIT_MAGIC_STRING_TO_UTC_STRING_UL, ECMA_DATE_PROTOTYPE_TO_UTC_STRING, 0, 0)
#if ENABLED (JERRY_BUILTIN_ANNEXB)
ROUTINE (LIT_MAGIC_STRING_TO_GMT_STRING_UL, ECMA_DATE_PROTOTYPE_TO_UTC_STRING, 0, 0)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#endif /* !ENABLED (JERRY_ESNEXT) */

#if ENABLED (JERRY_BUILTIN_ANNEXB)

ROUTINE (LIT_MAGIC_STRING_GET_YEAR_UL, ECMA_DATE_PROTOTYPE_GET_YEAR, 0, 0)
ROUTINE (LIT_MAGIC_STRING_SET_YEAR_UL, ECMA_DATE_PROTOTYPE_SET_YEAR, 1, 1)

#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */

#endif /* ENABLED (JERRY_BUILTIN_DATE) */

#include "ecma-builtin-helpers-macro-undefs.inc.h"
