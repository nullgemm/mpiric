#ifndef H_MPIRIC
#define H_MPIRIC

#include <stdint.h>

int32_t mpr_i32abs(int32_t x);
int64_t mpr_i64abs(int64_t x);
double mpr_f64abs(double x);
float mpr_f32abs(float x);

double mpr_recip(double x);
float mpr_recipf(float x);

double mpr_sqrt(double x);
float mpr_sqrtf(float x);

double mpr_rsqrt(double x);
float mpr_rsqrtf(float x);

double mpr_round(double x);
float mpr_roundf(float x);

double mpr_floor(double x);
float mpr_floorf(float x);

double mpr_ceil(double x);
float mpr_ceilf(float x);

double mpr_trunc(double x);
float mpr_truncf(float x);

double mpr_frac(double x);
float mpr_fracf(float x);

double mpr_remainder(double x, double y);
float mpr_remainderf(float x, float y);

double mpr_fmod(double x, double y);
float mpr_fmodf(float x, float y);

double mpr_sin(double x);
float mpr_sinf(float x);

double mpr_cos(double x);
float mpr_cosf(float x);

double mpr_tan(double x);
float mpr_tanf(float x);

double mpr_asin(double x);
float mpr_asinf(float x);

double mpr_acos(double x);
float mpr_acosf(float x);

double mpr_atan(double x);
float mpr_atanf(float x);

double mpr_atan2(double y, double x);
float mpr_atan2f(float y, float x);

double mpr_exp2(double x);
float mpr_exp2f(float x);

double mpr_log2(double x);
float mpr_log2f(float x);

double mpr_exp(double x);
float mpr_expf(float x);

double mpr_exp10(double x);
float mpr_exp10f(float x);

double mpr_log(double x);
float mpr_logf(float x);

double mpr_log10(double x);
float mpr_log10f(float x);

double mpr_pow(double a, double b);
float mpr_powf(float a, float b);

double mpr_sinh(double x);
float mpr_sinhf(float x);

double mpr_cosh(double x);
float mpr_coshf(float x);

double mpr_tanh(double x);
float mpr_tanhf(float x);

double mpr_asinh(double x);
float mpr_asinhf(float x);

double mpr_acosh(double x);
float mpr_acoshf(float x);

double mpr_atanh(double x);
float mpr_atanhf(float x);

double mpr_erf(double x);
float mpr_erff(float x);

double mpr_erfc(double x);
float mpr_erfcf(float x);

#endif
