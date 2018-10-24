#ifndef H_MPIRIC
#define H_MPIRIC

#include "cylgom.h"

i32 mpr_i32abs(i32 x);
i64 mpr_i64abs(i64 x);
f64 mpr_f64abs(f64 x);
f32 mpr_f32abs(f32 x);

f64 mpr_recip(f64 x);
f32 mpr_recipf(f32 x);

f64 mpr_sqrt(f64 x);
f32 mpr_sqrtf(f32 x);

f64 mpr_rsqrt(f64 x);
f32 mpr_rsqrtf(f32 x);

f64 mpr_round(f64 x);
f32 mpr_roundf(f32 x);

f64 mpr_floor(f64 x);
f32 mpr_floorf(f32 x);

f64 mpr_ceil(f64 x);
f32 mpr_ceilf(f32 x);

f64 mpr_trunc(f64 x);
f32 mpr_truncf(f32 x);

f64 mpr_frac(f64 x);
f32 mpr_fracf(f32 x);

f64 mpr_remainder(f64 x, f64 y);
f32 mpr_remainderf(f32 x, f32 y);

f64 mpr_fmod(f64 x, f64 y);
f32 mpr_fmodf(f32 x, f32 y);

f64 mpr_sin(f64 x);
f32 mpr_sinf(f32 x);

f64 mpr_cos(f64 x);
f32 mpr_cosf(f32 x);

f64 mpr_tan(f64 x);
f32 mpr_tanf(f32 x);

f64 mpr_asin(f64 x);
f32 mpr_asinf(f32 x);

f64 mpr_acos(f64 x);
f32 mpr_acosf(f32 x);

f64 mpr_atan(f64 x);
f32 mpr_atanf(f32 x);

f64 mpr_atan2(f64 y, f64 x);
f32 mpr_atan2f(f32 y, f32 x);

f64 mpr_exp2(f64 x);
f32 mpr_exp2f(f32 x);

f64 mpr_log2(f64 x);
f32 mpr_log2f(f32 x);

f64 mpr_exp(f64 x);
f32 mpr_expf(f32 x);

f64 mpr_exp10(f64 x);
f32 mpr_exp10f(f32 x);

f64 mpr_log(f64 x);
f32 mpr_logf(f32 x);

f64 mpr_log10(f64 x);
f32 mpr_log10f(f32 x);

f64 mpr_pow(f64 a, f64 b);
f32 mpr_powf(f32 a, f32 b);

f64 mpr_sinh(f64 x);
f32 mpr_sinhf(f32 x);

f64 mpr_cosh(f64 x);
f32 mpr_coshf(f32 x);

f64 mpr_tanh(f64 x);
f32 mpr_tanhf(f32 x);

f64 mpr_asinh(f64 x);
f32 mpr_asinhf(f32 x);

f64 mpr_acosh(f64 x);
f32 mpr_acoshf(f32 x);

f64 mpr_atanh(f64 x);
f32 mpr_atanhf(f32 x);

f64 mpr_erf(f64 x);
f32 mpr_erff(f32 x);

f64 mpr_erfc(f64 x);
f32 mpr_erfcf(f32 x);

#endif
