#include "mpiric.h"

int32_t mpr_i32abs(int32_t x)
{
    return x < 0 ? -x : x;
}

int64_t mpr_i64abs(int64_t x)
{
    return x < 0 ? -x : x;
}

double mpr_f64abs(double x)
{
    return x < 0 ? -x : x;
}

float mpr_f32abs(float x)
{
    return x < 0 ? -x : x;
}

double mpr_recip(double x)
{
    int64_t y;
    double z;
    y = *(int64_t *) &x;
    y = 0x7fde6238da3c2118 - y;
    z = *(double *) &y;

    return z * (2.0 - (x * z));
}

float mpr_recipf(float x)
{
    int32_t y;
    float z;
    y = *(int32_t *) &x;
    y = 0x7ef311c7 - y;
    z = *(float *) &y;

    return z * (2.0 - (x * z));
}

double mpr_sqrt(double x)
{
    int64_t y;
    double z;
    y = *(int64_t *) &x;
    y = ((y - 0x0010000000000000) >> 1) + 0x2000000000000000;
    z = *(double *) &y;

    return (x / z + z) * 0.5;
}

float mpr_sqrtf(float x)
{
    int32_t y;
    float z;
    y = *(int32_t *) &x;
    y = ((y - 0x00800000) >> 1) + 0x20000000;
    z = *(float *) &y;

    return (x / z + z) * 0.5f;
}

double mpr_rsqrt(double x)
{
    int64_t y;
    double z;
    z = x * 0.5;
    y = *(int64_t *) &x;
    y = 0x5fe6eb50c7b537a9 - (y >> 1);
    x = *(double *) &y;

    return x * (1.5 - z * x * x);
}

float mpr_rsqrtf(float x)
{
    int32_t y;
    float z;
    z = x * 0.5f;
    y = *(int32_t *) &x;
    y = 0x5f375a86 - (y >> 1);
    x = *(float *) &y;

    return x * (1.5f - z * x * x);
}

double mpr_round(double x)
{
    x += 6755399441055744.0;
    x -= 6755399441055744.0;
    return x;
}

float mpr_roundf(float x)
{
    x += 12582912.0f;
    x -= 12582912.0f;
    return x;
}

double mpr_floor(double x)
{
    return mpr_round(x - 0.5);
}

float mpr_floorf(float x)
{
    return mpr_roundf(x - 0.5f);
}

double mpr_ceil(double x)
{
    return mpr_round(x + 0.5);
}

float mpr_ceilf(float x)
{
    return mpr_roundf(x + 0.5f);
}

double mpr_trunc(double x)
{
    return (double)(int64_t)x;
}

float mpr_truncf(float x)
{
    return (float)(int32_t)x;
}

double mpr_frac(double x)
{
    return x - mpr_trunc(x);
}

float mpr_fracf(float x)
{
    return x - mpr_truncf(x);
}

double mpr_remainder(double x, double y)
{
    return x - mpr_floor(x / y) * y;
}

float mpr_remainderf(float x, float y)
{
    return x - mpr_floorf(x / y) * y;
}

double mpr_fmod(double x, double y)
{
    return x - mpr_trunc(x / y) * y;
}

float mpr_fmodf(float x, float y)
{
    return x - mpr_truncf(x / y) * y;
}

double mpr_sin(double x)
{
    double y;
    x *= -0.31830988618379067;
    y = x + 13510798882111488.0;
    x -= y - 13510798882111488.0;
    x *= (x < 0 ? -x : x) - 1;
    return x * (3.5841304553896 * (x < 0 ? -x : x) + 3.1039673861526);
}

float mpr_sinf(float x)
{
    float y;
    x *= -0.318309886f;
    y = x + 25165824.0f;
    x -= y - 25165824.0f;
    x *= (x < 0 ? -x : x) - 1;
    return x * (3.5841304553896f * (x < 0 ? -x : x) + 3.1039673861526f);
}

double mpr_cos(double x)
{
    return mpr_sin(x + 1.57079632679489662);
}

float mpr_cosf(float x)
{
    return mpr_sinf(x + 1.570796327f);
}

double mpr_tan(double x)
{
    return mpr_sin(x) / mpr_cos(x);
}

float mpr_tanf(float x)
{
    return mpr_sinf(x) / mpr_cosf(x);
}

double mpr_asin(double x)
{
    x = mpr_sqrt(1 + x) - mpr_sqrt(1 - x);
    return x * (0.131754508171 * (x < 0 ? -x : x) + 0.924391722181);
}

float mpr_asinf(float x)
{
    x = mpr_sqrtf(1 + x) - mpr_sqrtf(1 - x);
    return x * (0.131754508171f * (x < 0 ? -x : x) + 0.924391722181f);
}

double mpr_acos(double x)
{
    return 1.57079632679489662 - mpr_asin(x);
}

float mpr_acosf(float x)
{
    return 1.570796327f - mpr_asinf(x);
}

double mpr_atan(double x)
{
    x /= (x < 0 ? -x : x) + 1;
    return x * ((x < 0 ? -x : x) *
                    (-1.45667498914 * (x < 0 ? -x : x) + 2.18501248371) +
                0.842458832225);
}

float mpr_atanf(float x)
{
    x /= (x < 0 ? -x : x) + 1;
    return x * ((x < 0 ? -x : x) *
                    (-1.45667498914f * (x < 0 ? -x : x) + 2.18501248371f) +
                0.842458832225f);
}

double mpr_atan2(double y, double x)
{
    double t;
    t = 3.1415926535897932 - (y < 0) * 6.28318530717958648;
    y = mpr_atan(y / (x + !x)) + (x < 0) * t;
    return y + !x * (t * 0.5 - y);
}

float mpr_atan2f(float y, float x)
{
    float t;
    t = 3.141592653f - (y < 0) * 6.283185307f;
    y = mpr_atanf(y / (x + !x)) + (x < 0) * t;
    return y + !x * (t * 0.5f - y);
}

double mpr_exp2(double x)
{
    double y;
    int64_t exponent;
    exponent = (int64_t)(x + 1023);
    x += 1023 - exponent;
    exponent <<= 52;
    y = *(double *) &exponent;
    x *= x * 0.339766027260413688582 + 0.660233972739586311418;
    return (x + 1) * y;
}

float mpr_exp2f(float x)
{
    float y;
    int32_t exponent;
    exponent = (int32_t)(x + 127);
    x += 127 - exponent;
    exponent <<= 23;
    y = *(float *) &exponent;
    x *= x * 0.339766027f + 0.660233972f;
    return (x + 1) * y;
}

double mpr_log2(double x)
{
    int64_t y;
    double result;
    y = *(int64_t *) &x;
    y >>= 52;
    result = (double)y;
    y = *(int64_t *) &x;
    y = (y & 0x000fffffffffffff) | 0x3ff0000000000000;
    x = *(double *) &y;
    result += -1024 + x * (x * -0.33333333333333333 + 2) - 0.66666666666666666;
    return result;
}

float mpr_log2f(float x)
{
    int32_t y;
    float result;
    y = *(int32_t *) &x;
    y >>= 23;
    result = (float)y;
    y = *(int32_t *) &x;
    y = (y & 0x007fffff) | 0x3f800000;
    x = *(float *) &y;
    result += -128 + x * (x * -0.333333333f + 2) - 0.666666666f;
    return result;
}

double mpr_exp(double x)
{
    return mpr_exp2(x * 1.44269504088896341);
}

float mpr_expf(float x)
{
    return mpr_exp2f(x * 1.442695041f);
}

double mpr_exp10(double x)
{
    return mpr_exp2(x * 3.321928094887362348);
}

float mpr_exp10f(float x)
{
    return mpr_exp2f(x * 3.32192809f);
}

double mpr_log(double x)
{
    return mpr_log2(x) * 0.6931471805599453094;
}

float mpr_logf(float x)
{
    return mpr_log2f(x) * 0.693147181f;
}

double mpr_log10(double x)
{
    return mpr_log2(x) * 0.3010299956639811952;
}

float mpr_log10f(float x)
{
    return mpr_log2f(x) * 0.301029996f;
}

double mpr_pow(double a, double b)
{
    return mpr_exp2(b * mpr_log2(a));
}

float mpr_powf(float a, float b)
{
    return mpr_exp2f(b * mpr_log2f(a));
}

double mpr_sinh(double x)
{
    x = mpr_exp(x);
    return (x - 1 / x) * 0.5;
}

float mpr_sinhf(float x)
{
    x = mpr_expf(x);
    return (x - 1 / x) * 0.5f;
}

double mpr_cosh(double x)
{
    x = mpr_exp(x);
    return (x + 1 / x) * 0.5;
}

float mpr_coshf(float x)
{
    x = mpr_expf(x);
    return (x + 1 / x) * 0.5f;
}

double mpr_tanh(double x)
{
    x = mpr_exp(x * -2);
    return (1 - x) / (1 + x);
}

float mpr_tanhf(float x)
{
    x = mpr_expf(x * -2);
    return (1 - x) / (1 + x);
}

double mpr_asinh(double x)
{
    return mpr_log(x + mpr_sqrt(x * x + 1));
}

float mpr_asinhf(float x)
{
    return mpr_logf(x + mpr_sqrtf(x * x + 1));
}

double mpr_acosh(double x)
{
    return mpr_log(x + mpr_sqrt(x * x - 1));
}

float mpr_acoshf(float x)
{
    return mpr_logf(x + mpr_sqrtf(x * x - 1));
}

double mpr_atanh(double x)
{
    return mpr_log((1 + x) / (1 - x)) * 0.5;
}

float mpr_atanhf(float x)
{
    return mpr_logf((1 + x) / (1 - x)) * 0.5f;
}

double mpr_erf(double x)
{
    x = mpr_exp2(x * 3.47203417614113462733);
    return x / ((x < 0 ? -x : x) + 1) * 2 - 1;
}

float mpr_erff(float x)
{
    x = mpr_exp2f(x * 3.472034176f);
    return x / ((x < 0 ? -x : x) + 1) * 2 - 1;
}

double mpr_erfc(double x)
{
    return 1 - mpr_erf(x);
}

float mpr_erfcf(float x)
{
    return 1 - mpr_erff(x);
}
