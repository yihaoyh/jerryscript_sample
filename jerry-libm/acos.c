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
 *
 * This file is based on work under the following copyright and permission
 * notice:
 *
 *     Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 *     Developed at SunSoft, a Sun Microsystems, Inc. business.
 *     Permission to use, copy, modify, and distribute this
 *     software is freely granted, provided that this notice
 *     is preserved.
 *
 *     @(#)e_acos.c 1.3 95/01/18
 */

#include "jerry-libm-internal.h"

/* acos(x)
 *
 * Method:
 *      acos(x)  = pi/2 - asin(x)
 *      acos(-x) = pi/2 + asin(x)
 * For |x|<=0.5
 *      acos(x) = pi/2 - (x + x*x^2*R(x^2))     (see asin.c)
 * For x>0.5
 *      acos(x) = pi/2 - (pi/2 - 2asin(sqrt((1-x)/2)))
 *              = 2asin(sqrt((1-x)/2))
 *              = 2s + 2s*z*R(z)        ...z=(1-x)/2, s=sqrt(z)
 *              = 2f + (2c + 2s*z*R(z))
 *     where f=hi part of s, and c = (z-f*f)/(s+f) is the correction term
 *     for f so that f+c ~ sqrt(z).
 * For x<-0.5
 *      acos(x) = pi - 2asin(sqrt((1-|x|)/2))
 *              = pi - 0.5*(s+s*z*R(z)), where z=(1-|x|)/2,s=sqrt(z)
 *
 * Special cases:
 *      if x is NaN, return x itself;
 *      if |x|>1, return NaN with invalid signal.
 *
 * Function needed: sqrt
 */

#define one      1.00000000000000000000e+00 /* 0x3FF00000, 0x00000000 */
#define pi       3.14159265358979311600e+00 /* 0x400921FB, 0x54442D18 */
#define pio2_hi  1.57079632679489655800e+00 /* 0x3FF921FB, 0x54442D18 */
#define pio2_lo  6.12323399573676603587e-17 /* 0x3C91A626, 0x33145C07 */
#define pS0      1.66666666666666657415e-01 /* 0x3FC55555, 0x55555555 */
#define pS1     -3.25565818622400915405e-01 /* 0xBFD4D612, 0x03EB6F7D */
#define pS2      2.01212532134862925881e-01 /* 0x3FC9C155, 0x0E884455 */
#define pS3     -4.00555345006794114027e-02 /* 0xBFA48228, 0xB5688F3B */
#define pS4      7.91534994289814532176e-04 /* 0x3F49EFE0, 0x7501B288 */
#define pS5      3.47933107596021167570e-05 /* 0x3F023DE1, 0x0DFDF709 */
#define qS1     -2.40339491173441421878e+00 /* 0xC0033A27, 0x1C8A2D4B */
#define qS2      2.02094576023350569471e+00 /* 0x40002AE5, 0x9C598AC8 */
#define qS3     -6.88283971605453293030e-01 /* 0xBFE6066C, 0x1B8D0159 */
#define qS4      7.70381505559019352791e-02 /* 0x3FB3B8C5, 0xB12E9282 */

double
acos (double x)
{
  double z, p, q, r, w, s, c;
  int hx, ix;

  hx = __HI (x);
  ix = hx & 0x7fffffff;
  if (ix >= 0x3ff00000) /* |x| >= 1 */
  {
    if (((ix - 0x3ff00000) | __LO (x)) == 0) /* |x| == 1 */
    {
      if (hx > 0) /* acos(1) = 0  */
      {
        return 0.0;
      }
      else /* acos(-1) = pi */
      {
        return pi + 2.0 * pio2_lo;
      }
    }
    return NAN; /* acos(|x|>1) is NaN */
  }
  if (ix < 0x3fe00000) /* |x| < 0.5 */
  {
    if (ix <= 0x3c600000) /* if |x| < 2**-57 */
    {
      return pio2_hi + pio2_lo;
    }
    z = x * x;
    p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
    q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
    r = p / q;
    return pio2_hi - (x - (pio2_lo - x * r));
  }
  else if (hx < 0) /* x < -0.5 */
  {
    z = (one + x) * 0.5;
    p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
    q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
    s = sqrt (z);
    r = p / q;
    w = r * s - pio2_lo;
    return pi - 2.0 * (s + w);
  }
  else /* x > 0.5 */
  {
    double_accessor df;
    z = (one - x) * 0.5;
    s = sqrt (z);
    df.dbl = s;
    df.as_int.lo = 0;
    c = (z - df.dbl * df.dbl) / (s + df.dbl);
    p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
    q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
    r = p / q;
    w = r * s + c;
    return 2.0 * (df.dbl + w);
  }
} /* acos */

#undef one
#undef pi
#undef pio2_hi
#undef pio2_lo
#undef pS0
#undef pS1
#undef pS2
#undef pS3
#undef pS4
#undef pS5
#undef qS1
#undef qS2
#undef qS3
#undef qS4
