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
 * Number built-in description
 */

#include "ecma-builtin-helpers-macro-defines.inc.h"

#if ENABLED (JERRY_BUILTIN_NUMBER)

/* Number properties:
 *  (property name, number value, writable, enumerable, configurable) */

NUMBER_VALUE (LIT_MAGIC_STRING_LENGTH,
              1,
              ECMA_PROPERTY_FLAG_DEFAULT_LENGTH)

/* ECMA-262 v5, 15.7.3.4 */
NUMBER_VALUE (LIT_MAGIC_STRING_NAN,
              ECMA_BUILTIN_NUMBER_NAN,
              ECMA_PROPERTY_FIXED)

/* ECMA-262 v5, 15.7.3.2 */
NUMBER_VALUE (LIT_MAGIC_STRING_MAX_VALUE_U,
              ECMA_BUILTIN_NUMBER_MAX,
              ECMA_PROPERTY_FIXED)

/* ECMA-262 v5, 15.7.3.3 */
NUMBER_VALUE (LIT_MAGIC_STRING_MIN_VALUE_U,
              ECMA_BUILTIN_NUMBER_MIN,
              ECMA_PROPERTY_FIXED)

/* ECMA-262 v5, 15.7.3.5 */
NUMBER_VALUE (LIT_MAGIC_STRING_POSITIVE_INFINITY_U,
              ECMA_BUILTIN_NUMBER_POSITIVE_INFINITY,
              ECMA_PROPERTY_FIXED)

/* ECMA-262 v5, 15.7.3.6 */
NUMBER_VALUE (LIT_MAGIC_STRING_NEGATIVE_INFINITY_U,
              ECMA_BUILTIN_NUMBER_NEGATIVE_INFINITY,
              ECMA_PROPERTY_FIXED)

#if ENABLED (JERRY_ESNEXT)

/* ECMA-262 v6, 20.1.2.1 */
NUMBER_VALUE (LIT_MAGIC_STRING_EPSILON_U,
              ECMA_BUILTIN_NUMBER_EPSILON,
              ECMA_PROPERTY_FIXED)

/* ECMA-262 v6, 20.1.2.6 */
NUMBER_VALUE (LIT_MAGIC_STRING_MAX_SAFE_INTEGER_U,
              ECMA_BUILTIN_NUMBER_MAX_SAFE_INTEGER,
              ECMA_PROPERTY_FIXED)

/* ECMA-262 v6, 20.1.2.8 */
NUMBER_VALUE (LIT_MAGIC_STRING_MIN_SAFE_INTEGER_U,
              ECMA_BUILTIN_NUMBER_MIN_SAFE_INTEGER,
              ECMA_PROPERTY_FIXED)

STRING_VALUE (LIT_MAGIC_STRING_NAME,
              LIT_MAGIC_STRING_NUMBER_UL,
              ECMA_PROPERTY_FLAG_CONFIGURABLE)
#endif /* ENABLED (JERRY_ESNEXT) */

/* Object properties:
 *  (property name, object pointer getter) */

/* ECMA-262 v5, 15.7.3.1 */
OBJECT_VALUE (LIT_MAGIC_STRING_PROTOTYPE,
              ECMA_BUILTIN_ID_NUMBER_PROTOTYPE,
              ECMA_PROPERTY_FIXED)

#endif /* ENABLED (JERRY_BUILTIN_NUMBER) */

/* Routine properties:
 *  (property name, C routine name, arguments number or NON_FIXED, value of the routine's length property) */
#if ENABLED (JERRY_ESNEXT)
ROUTINE (LIT_MAGIC_STRING_IS_FINITE, ECMA_NUMBER_OBJECT_ROUTINE_IS_FINITE, 1, 1)
ROUTINE (LIT_MAGIC_STRING_IS_NAN, ECMA_NUMBER_OBJECT_ROUTINE_IS_NAN, 1, 1)
ROUTINE (LIT_MAGIC_STRING_IS_INTEGER, ECMA_NUMBER_OBJECT_ROUTINE_IS_INTEGER, 1, 1)
ROUTINE (LIT_MAGIC_STRING_IS_SAFE_INTEGER, ECMA_NUMBER_OBJECT_ROUTINE_IS_SAFE_INTEGER, 1, 1)
INTRINSIC_PROPERTY (LIT_MAGIC_STRING_PARSE_FLOAT, LIT_MAGIC_STRING_PARSE_FLOAT, ECMA_PROPERTY_CONFIGURABLE_WRITABLE)
INTRINSIC_PROPERTY (LIT_MAGIC_STRING_PARSE_INT, LIT_MAGIC_STRING_PARSE_INT, ECMA_PROPERTY_CONFIGURABLE_WRITABLE)
#endif /* ENABLED (JERRY_ESNEXT) */
#include "ecma-builtin-helpers-macro-undefs.inc.h"
