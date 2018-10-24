#ifndef H_CYLGOM
#define H_CYLGOM

// typedefs for convenience and optimizations

#include <stdbool.h>
#include <stdint.h>

// 0 to save ram and optimize for embedded systems
// 1 to gain extra speed by replacing all floats by doubles
// 2 to gain extra speed by using bigger integers depending on arch
// level 2 "optimizations" will definitely eat your ram
#define CYLGOM_SPEED 0

///////////////////
// regular stuff //
///////////////////

// 100% standard
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// the floating point number representation is not defined by the C standard
// however, it strongly suggests using the IEEE 754 norm for that task
// "long double" is not redefined because it is compiler-dependant
typedef float f32;
typedef double f64;

///////////////////////////////
// black magic optimizations //
///////////////////////////////

// the best optimization out there
// doubles are usually slower than floats for various reasons
// on embedded systems though, it is most likely the opposite
#if CYLGOM_SPEED > 0
typedef f64 f32;
#endif

// the following block tries to optimize speed at the cost of ram
// we are testing the architecture in the most portable way possible
// the following macro is not mandatory, obscure systems might not provide it
// on 16 bits systems, 16-bit integer operations can be the fastest
// on 32 bits systems, 32-bit integer operations can be the fastest
// on 64 bits systems, 64-bit integer operations can be the fastest
#if CYLGOM_SPEED > 1
#if UINTPTR_MAX == 0xffff
typedef uint16_t u8;
typedef int16_t i8;
#elif UINTPTR_MAX == 0xffffffff
typedef uint32_t u8;
typedef int32_t i8;
typedef uint32_t u16;
typedef int32_t i16;
#elif UINTPTR_MAX == 0xffffffffffffffff
typedef uint64_t u8;
typedef int64_t i8;
typedef uint64_t u16;
typedef int64_t i16;
typedef uint64_t u32;
typedef int64_t i32;
#endif
#endif

#endif
