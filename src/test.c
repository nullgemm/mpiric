#include "mpiric.h"
#include "cylgom.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#define BENCHMARK_RANGE 1000000.0
#define BENCHMARK_RANGEF 1000000.0f

// handles io during the plotting process
void plot_begin(FILE** fd, const char* name)
{
	static char buf[64];

	snprintf(buf, 63, "%s.crt", name);
	*fd = fopen(buf, "ab+");

#ifdef BENCHMARK
	printf("\n%s\n", name);
#endif
}

void plot_end(FILE* fd, const char* name)
{
	static char buf[64];

	fclose(fd);
	snprintf(buf, 63, "./charter_svg %s.crt >> %s.svg", name, name);
	system(buf);
}

// plotting process io
void crt_begin(FILE* fd)
{
	fprintf(fd, "plot:\n");
	fprintf(fd, " x range: 0.1 10.0 0.1\n");
	fprintf(fd, " y ");
}

void crt_end(FILE* fd, bool mpiric)
{
	fprintf(fd, "\n");
	fprintf(fd, " marker\n");
	fprintf(fd, " line-style %s\n", mpiric ? "-" : "--");
	fprintf(fd, " label %s\n", mpiric ? "mpiric" : "libm");
}

// benchmark
void benchmarkf64(f64 (*f)(f64), bool mpiric)
{
	struct timeval time;
	u64 time_present = 0;
	u64 time_past = 0;
	f64 total = 0;

	gettimeofday(&time, NULL);
	time_past = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	for (f64 i = 0.1; i<= BENCHMARK_RANGE; i += 0.1)
	{
		total += f(i);
	}

	gettimeofday(&time, NULL);
	time_present = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	printf("%s", mpiric ? "mpiric: " : "libm:   ");
	printf("%lf ns\n", (time_present - time_past) / BENCHMARK_RANGE * 1000.0);
}

void arg_benchmarkf64(f64 (*f)(f64, f64), bool mpiric, f64 x)
{
	struct timeval time;
	u64 time_present = 0;
	u64 time_past = 0;
	f64 total = 0;

	gettimeofday(&time, NULL);
	time_past = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	for (f64 i = 0.1; i<= BENCHMARK_RANGE; i += 0.1)
	{
		total += f(i, x);
	}

	gettimeofday(&time, NULL);
	time_present = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	printf("%s", mpiric ? "mpiric: " : "libm:   ");
	printf("%lf ns\n", (time_present - time_past) / BENCHMARK_RANGE * 1000.0);
}

void benchmarkf32(f32 (*f)(f32), bool mpiric)
{
	struct timeval time;
	u64 time_present = 0;
	u64 time_past = 0;
	f32 total = 0;

	gettimeofday(&time, NULL);
	time_past = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	for (f32 i = 0.1; i<= BENCHMARK_RANGEF; i += 0.1)
	{
		total += f(i);
	}

	gettimeofday(&time, NULL);
	time_present = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	printf("%s", mpiric ? "mpiric: " : "libm:   ");
	printf("%lf ns\n", (time_present - time_past) / BENCHMARK_RANGE * 1000.0);
}

void arg_benchmarkf32(f32 (*f)(f32, f32), bool mpiric, f32 x)
{
	struct timeval time;
	u64 time_present = 0;
	u64 time_past = 0;
	f32 total = 0;

	gettimeofday(&time, NULL);
	time_past = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	for (f32 i = 0.1; i<= BENCHMARK_RANGEF; i += 0.1)
	{
		total += f(i, x);
	}

	gettimeofday(&time, NULL);
	time_present = time.tv_usec + ((u64) 1000000) * time.tv_sec;

	printf("%s", mpiric ? "mpiric: " : "libm:   ");
	printf("%lf ns\n", (time_present - time_past) / BENCHMARK_RANGE * 1000.0);
}

// functions execution
void arg_funcf64(FILE* fd, f64 (*f)(f64, f64), bool mpiric, f64 x)
{
	crt_begin(fd);

	for (f64 i = 0.1; i <= 10.0; i += 0.1)
	{
		fprintf(fd, "%lf ", f(i, x));
	}

#ifdef BENCHMARK
	arg_benchmarkf64(f, mpiric, x);
#endif

	crt_end(fd, mpiric);
}


void funcf64(FILE* fd, f64 (*f)(f64), bool mpiric)
{
	crt_begin(fd);

	for (f64 i = 0.1; i <= 10.0; i += 0.1)
	{
		fprintf(fd, "%lf ", f(i));
	}

#ifdef BENCHMARK
	benchmarkf64(f, mpiric);
#endif

	crt_end(fd, mpiric);
}

void arg_funcf32(FILE* fd, f32 (*f)(f32, f32), bool mpiric, f32 x)
{
	crt_begin(fd);

	for (f32 i = 0.1; i <= 10.0; i += 0.1)
	{
		fprintf(fd, "%f ", f(i, x));
	}

#ifdef BENCHMARK
	arg_benchmarkf32(f, mpiric, x);
#endif

	crt_end(fd, mpiric);
}

void funcf32(FILE* fd, f32 (*f)(f32), bool mpiric)
{
	crt_begin(fd);

	for (f32 i = 0.1; i <= 10.0; i += 0.1)
	{
		fprintf(fd, "%f ", f(i));
	}

#ifdef BENCHMARK
	benchmarkf32(f, mpiric);
#endif

	crt_end(fd, mpiric);
}

// plotting types (one line, two lines, multiple lines for two exressions with arguments)
void lone_plotf64(const char* name, f64 (*f)(f64))
{
	FILE* fd;

	plot_begin(&fd, name);

	if (fd == NULL)
	{
		return;
	}

	funcf64(fd, f, true);

	plot_end(fd, name);
}

void arg_plotf64(const char* name, f64 (*f)(f64, f64), f64 (*m)(f64, f64))
{
	FILE* fd;

	plot_begin(&fd, name);

	if (fd == NULL)
	{
		return;
	}

	arg_funcf64(fd, f, true, 1);
	arg_funcf64(fd, m, false, 1);
	arg_funcf64(fd, f, true, 2);
	arg_funcf64(fd, m, false, 2);
	arg_funcf64(fd, f, true, 3);
	arg_funcf64(fd, m, false, 3);

	plot_end(fd, name);
}

void plotf64(const char* name, f64 (*f)(f64), f64 (*m)(f64))
{
	FILE* fd;
	plot_begin(&fd, name);

	if (fd == NULL)
	{
		return;
	}

	funcf64(fd, f, true);
	funcf64(fd, m, false);

	plot_end(fd, name);
}

void lone_plotf32(const char* name, f32 (*f)(f32))
{
	FILE* fd;

	plot_begin(&fd, name);

	if (fd == NULL)
	{
		return;
	}

	funcf32(fd, f, true);

	plot_end(fd, name);
}

void arg_plotf32(const char* name, f32 (*f)(f32, f32), f32 (*m)(f32, f32))
{
	FILE* fd;

	plot_begin(&fd, name);

	if (fd == NULL)
	{
		return;
	}

	arg_funcf32(fd, f, true, 1);
	arg_funcf32(fd, m, false, 1);
	arg_funcf32(fd, f, true, 2);
	arg_funcf32(fd, m, false, 2);
	arg_funcf32(fd, f, true, 3);
	arg_funcf32(fd, m, false, 3);

	plot_end(fd, name);
}

void plotf32(const char* name, f32 (*f)(f32), f32 (*m)(f32))
{
	FILE* fd;
	plot_begin(&fd, name);

	if (fd == NULL)
	{
		return;
	}

	funcf32(fd, f, true);
	funcf32(fd, m, false);

	plot_end(fd, name);
}

// helper functions used for comparison
f64 rsqrtf64(f64 x)
{
	return 1.0 / sqrt(x);
}

f64 recipf64(f64 x)
{
	return 1.0 / x;
}

f32 rsqrtf32(f32 x)
{
	return 1.0f / sqrt(x);
}

f32 recipf32(f32 x)
{
	return 1.0f / x;
}

// testing sequence
int main()
{
	lone_plotf64("abs", mpr_f64abs);
	plotf64("recip", mpr_recip, recipf64);
	plotf64("sqrt", mpr_sqrt, sqrt);
	plotf64("rsqrt", mpr_rsqrt, rsqrtf64);
	plotf64("round", mpr_round, round);
	plotf64("floor", mpr_floor, floor);
	plotf64("ceil", mpr_ceil, ceil);
	plotf64("trunc", mpr_trunc, trunc);
	lone_plotf64("frac", mpr_frac);
	arg_plotf64("trunc", mpr_remainder, remainder);
	arg_plotf64("fmod", mpr_fmod, fmod);
	plotf64("sin", mpr_sin, sin);
	plotf64("cos", mpr_cos, cos);
	plotf64("tan", mpr_tan, tan);
	plotf64("asin", mpr_asin, asin);
	plotf64("acos", mpr_acos, acos);
	plotf64("atan", mpr_atan, atan);
	arg_plotf64("atan2", mpr_atan2, atan2);
	plotf64("exp2", mpr_exp2, exp2);
	plotf64("log2", mpr_log2, log2);
	plotf64("exp", mpr_exp, exp);
	plotf64("log", mpr_log, log);
	lone_plotf64("exp10", mpr_exp10);
	lone_plotf64("log10", mpr_log10);
	arg_plotf64("pow", mpr_pow, pow);
	plotf64("sinh", mpr_sinh, sinh);
	plotf64("cosh", mpr_cosh, cosh);
	plotf64("tanh", mpr_tanh, tanh);
	plotf64("asinh", mpr_asinh, asinh);
	plotf64("acosh", mpr_acosh, acosh);
	plotf64("atanh", mpr_atanh, atanh);
	plotf64("erf", mpr_erf, erf);
	plotf64("erfc", mpr_erfc, erfc);

	lone_plotf32("absf", mpr_f32abs);
	plotf32("recipf", mpr_recipf, recipf32);
	plotf32("sqrtf", mpr_sqrtf, sqrtf);
	plotf32("rsqrtf", mpr_rsqrtf, rsqrtf32);
	plotf32("roundf", mpr_roundf, roundf);
	plotf32("floorf", mpr_floorf, floorf);
	plotf32("ceilf", mpr_ceilf, ceilf);
	plotf32("truncf", mpr_truncf, truncf);
	lone_plotf32("fracf", mpr_fracf);
	arg_plotf32("truncf", mpr_remainderf, remainderf);
	arg_plotf32("fmodf", mpr_fmodf, fmodf);
	plotf32("sinf", mpr_sinf, sinf);
	plotf32("cosf", mpr_cosf, cosf);
	plotf32("tanf", mpr_tanf, tanf);
	plotf32("asinf", mpr_asinf, asinf);
	plotf32("acosf", mpr_acosf, acosf);
	plotf32("atanf", mpr_atanf, atanf);
	arg_plotf32("atan2f", mpr_atan2f, atan2f);
	plotf32("exp2f", mpr_exp2f, exp2f);
	plotf32("log2f", mpr_log2f, log2f);
	plotf32("expf", mpr_expf, expf);
	plotf32("logf", mpr_logf, logf);
	lone_plotf32("exp10f", mpr_exp10f);
	lone_plotf32("log10f", mpr_log10f);
	arg_plotf32("powf", mpr_powf, powf);
	plotf32("sinhf", mpr_sinhf, sinhf);
	plotf32("coshf", mpr_coshf, coshf);
	plotf32("tanhf", mpr_tanhf, tanhf);
	plotf32("asinhf", mpr_asinhf, asinhf);
	plotf32("acoshf", mpr_acoshf, acoshf);
	plotf32("atanhf", mpr_atanhf, atanhf);
	plotf32("erff", mpr_erff, erff);
	plotf32("erfcf", mpr_erfcf, erfcf);
	return 0;
}
