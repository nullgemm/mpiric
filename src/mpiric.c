#include "mpiric.h"
#include "cylgom.h"

i32 mpr_i32abs(i32 x)
{
    return x < 0 ? -x : x;
}

i64 mpr_i64abs(i64 x)
{
    return x < 0 ? -x : x;
}

f64 mpr_f64abs(f64 x)
{
    return x < 0 ? -x : x;
}

f32 mpr_f32abs(f32 x)
{
    return x < 0 ? -x : x;
}

f64 mpr_recip(f64 x)
{
    i64 y;
    f64 z;
    y = *(i64 *) &x;
    y = 0x7fde6238da3c2118 - y;
    z = *(f64 *) &y;

    return z * (2.0 - (x * z));
}

f32 mpr_recipf(f32 x)
{
    i32 y;
    f32 z;
    y = *(i32 *) &x;
    y = 0x7ef311c7 - y;
    z = *(f32 *) &y;

    return z * (2.0 - (x * z));
}

f64 mpr_sqrt(f64 x)
{
    i64 y;
    f64 z;
    y = *(i64 *) &x;
    y = ((y - 0x0010000000000000) >> 1) + 0x2000000000000000;
    z = *(f64 *) &y;

    return (x / z + z) * 0.5;
}

f32 mpr_sqrtf(f32 x)
{
    i32 y;
    f32 z;
    y = *(i32 *) &x;
    y = ((y - 0x00800000) >> 1) + 0x20000000;
    z = *(f32 *) &y;

    return (x / z + z) * 0.5f;
}

f64 mpr_rsqrt(f64 x)
{
    i64 y;
    f64 z;
    z = x * 0.5;
    y = *(i64 *) &x;
    y = 0x5fe6eb50c7b537a9 - (y >> 1);
    x = *(f64 *) &y;

    return x * (1.5 - z * x * x);
}

f32 mpr_rsqrtf(f32 x)
{
    i32 y;
    f32 z;
    z = x * 0.5f;
    y = *(i32 *) &x;
    y = 0x5f375a86 - (y >> 1);
    x = *(f32 *) &y;

    return x * (1.5f - z * x * x);
}

f64 mpr_round(f64 x)
{
    x += 6755399441055744.0;
    x -= 6755399441055744.0;
    return x;
}

f32 mpr_roundf(f32 x)
{
    x += 12582912.0f;
    x -= 12582912.0f;
    return x;
}

f64 mpr_floor(f64 x)
{
    return mpr_round(x - 0.5);
}

f32 mpr_floorf(f32 x)
{
    return mpr_roundf(x - 0.5f);
}

f64 mpr_ceil(f64 x)
{
    return mpr_round(x + 0.5);
}

f32 mpr_ceilf(f32 x)
{
    return mpr_roundf(x + 0.5f);
}

f64 mpr_trunc(f64 x)
{
    return (f64)(i64)x;
}

f32 mpr_truncf(f32 x)
{
    return (f32)(i32)x;
}

f64 mpr_frac(f64 x)
{
    return x - mpr_trunc(x);
}

f32 mpr_fracf(f32 x)
{
    return x - mpr_truncf(x);
}

f64 mpr_remainder(f64 x, f64 y)
{
    return x - mpr_floor(x / y) * y;
}

f32 mpr_remainderf(f32 x, f32 y)
{
    return x - mpr_floorf(x / y) * y;
}

f64 mpr_fmod(f64 x, f64 y)
{
    return x - mpr_trunc(x / y) * y;
}

f32 mpr_fmodf(f32 x, f32 y)
{
    return x - mpr_truncf(x / y) * y;
}

f64 mpr_sin(f64 x)
{
    f64 y;
    x *= -0.31830988618379067;
    y = x + 13510798882111488.0;
    x -= y - 13510798882111488.0;
    x *= (x < 0 ? -x : x) - 1;
    return x * (3.5841304553896 * (x < 0 ? -x : x) + 3.1039673861526);
}

f32 mpr_sinf(f32 x)
{
    f32 y;
    x *= -0.318309886f;
    y = x + 25165824.0f;
    x -= y - 25165824.0f;
    x *= (x < 0 ? -x : x) - 1;
    return x * (3.5841304553896f * (x < 0 ? -x : x) + 3.1039673861526f);
}

f64 mpr_cos(f64 x)
{
    return mpr_sin(x + 1.57079632679489662);
}

f32 mpr_cosf(f32 x)
{
    return mpr_sinf(x + 1.570796327f);
}

f64 mpr_tan(f64 x)
{
    return mpr_sin(x) / mpr_cos(x);
}

f32 mpr_tanf(f32 x)
{
    return mpr_sinf(x) / mpr_cosf(x);
}

f64 mpr_asin(f64 x)
{
    x = mpr_sqrt(1 + x) - mpr_sqrt(1 - x);
    return x * (0.131754508171 * (x < 0 ? -x : x) + 0.924391722181);
}

f32 mpr_asinf(f32 x)
{
    x = mpr_sqrtf(1 + x) - mpr_sqrtf(1 - x);
    return x * (0.131754508171f * (x < 0 ? -x : x) + 0.924391722181f);
}

f64 mpr_acos(f64 x)
{
    return 1.57079632679489662 - mpr_asin(x);
}

f32 mpr_acosf(f32 x)
{
    return 1.570796327f - mpr_asinf(x);
}

f64 mpr_atan(f64 x)
{
    x /= (x < 0 ? -x : x) + 1;
    return x * ((x < 0 ? -x : x) *
                    (-1.45667498914 * (x < 0 ? -x : x) + 2.18501248371) +
                0.842458832225);
}

f32 mpr_atanf(f32 x)
{
    x /= (x < 0 ? -x : x) + 1;
    return x * ((x < 0 ? -x : x) *
                    (-1.45667498914f * (x < 0 ? -x : x) + 2.18501248371f) +
                0.842458832225f);
}

f64 mpr_atan2(f64 y, f64 x)
{
    f64 t;
    t = 3.1415926535897932 - (y < 0) * 6.28318530717958648;
    y = mpr_atan(y / (x + !x)) + (x < 0) * t;
    return y + !x * (t * 0.5 - y);
}

f32 mpr_atan2f(f32 y, f32 x)
{
    f32 t;
    t = 3.141592653f - (y < 0) * 6.283185307f;
    y = mpr_atanf(y / (x + !x)) + (x < 0) * t;
    return y + !x * (t * 0.5f - y);
}

f64 mpr_exp2(f64 x)
{
    f64 y;
    i64 exponent;
    exponent = (i64)(x + 1023);
    x += 1023 - exponent;
    exponent <<= 52;
    y = *(f64 *) &exponent;
    x *= x * 0.339766027260413688582 + 0.660233972739586311418;
    return (x + 1) * y;
}

f32 mpr_exp2f(f32 x)
{
    f32 y;
    i32 exponent;
    exponent = (i32)(x + 127);
    x += 127 - exponent;
    exponent <<= 23;
    y = *(f32 *) &exponent;
    x *= x * 0.339766027f + 0.660233972f;
    return (x + 1) * y;
}

f64 mpr_log2(f64 x)
{
    i64 y;
    f64 result;
    y = *(i64 *) &x;
    y >>= 52;
    result = (f64)y;
    y = *(i64 *) &x;
    y = (y & 0x000fffffffffffff) | 0x3ff0000000000000;
    x = *(f64 *) &y;
    result += -1024 + x * (x * -0.33333333333333333 + 2) - 0.66666666666666666;
    return result;
}

f32 mpr_log2f(f32 x)
{
    i32 y;
    f32 result;
    y = *(i32 *) &x;
    y >>= 23;
    result = (f32)y;
    y = *(i32 *) &x;
    y = (y & 0x007fffff) | 0x3f800000;
    x = *(f32 *) &y;
    result += -128 + x * (x * -0.333333333f + 2) - 0.666666666f;
    return result;
}

f64 mpr_exp(f64 x)
{
    return mpr_exp2(x * 1.44269504088896341);
}

f32 mpr_expf(f32 x)
{
    return mpr_exp2f(x * 1.442695041f);
}

f64 mpr_exp10(f64 x)
{
    return mpr_exp2(x * 3.321928094887362348);
}

f32 mpr_exp10f(f32 x)
{
    return mpr_exp2f(x * 3.32192809f);
}

f64 mpr_log(f64 x)
{
    return mpr_log2(x) * 0.6931471805599453094;
}

f32 mpr_logf(f32 x)
{
    return mpr_log2f(x) * 0.693147181f;
}

f64 mpr_log10(f64 x)
{
    return mpr_log2(x) * 0.3010299956639811952;
}

f32 mpr_log10f(f32 x)
{
    return mpr_log2f(x) * 0.301029996f;
}

f64 mpr_pow(f64 a, f64 b)
{
    return mpr_exp2(b * mpr_log2(a));
}

f32 mpr_powf(f32 a, f32 b)
{
    return mpr_exp2f(b * mpr_log2f(a));
}

f64 mpr_sinh(f64 x)
{
    x = mpr_exp(x);
    return (x - 1 / x) * 0.5;
}

f32 mpr_sinhf(f32 x)
{
    x = mpr_expf(x);
    return (x - 1 / x) * 0.5f;
}

f64 mpr_cosh(f64 x)
{
    x = mpr_exp(x);
    return (x + 1 / x) * 0.5;
}

f32 mpr_coshf(f32 x)
{
    x = mpr_expf(x);
    return (x + 1 / x) * 0.5f;
}

f64 mpr_tanh(f64 x)
{
    x = mpr_exp(x * -2);
    return (1 - x) / (1 + x);
}

f32 mpr_tanhf(f32 x)
{
    x = mpr_expf(x * -2);
    return (1 - x) / (1 + x);
}

f64 mpr_asinh(f64 x)
{
    return mpr_log(x + mpr_sqrt(x * x + 1));
}

f32 mpr_asinhf(f32 x)
{
    return mpr_logf(x + mpr_sqrtf(x * x + 1));
}

f64 mpr_acosh(f64 x)
{
    return mpr_log(x + mpr_sqrt(x * x - 1));
}

f32 mpr_acoshf(f32 x)
{
    return mpr_logf(x + mpr_sqrtf(x * x - 1));
}

f64 mpr_atanh(f64 x)
{
    return mpr_log((1 + x) / (1 - x)) * 0.5;
}

f32 mpr_atanhf(f32 x)
{
    return mpr_logf((1 + x) / (1 - x)) * 0.5f;
}

f64 mpr_erf(f64 x)
{
    x = mpr_exp2(x * 3.47203417614113462733);
    return x / ((x < 0 ? -x : x) + 1) * 2 - 1;
}

f32 mpr_erff(f32 x)
{
    x = mpr_exp2f(x * 3.472034176f);
    return x / ((x < 0 ? -x : x) + 1) * 2 - 1;
}

f64 mpr_erfc(f64 x)
{
    return 1 - mpr_erf(x);
}

f32 mpr_erfcf(f32 x)
{
    return 1 - mpr_erff(x);
}
