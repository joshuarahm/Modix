#ifndef ARCH_TYPES_H_
#define ARCH_TYPES_H_

typedef unsigned int u32_t;
typedef signed int s32_t;
typedef unsigned long long u64_t;
typedef signed long long s64_t;
typedef unsigned char u8_t;
typedef signed char s8_t;
typedef unsigned short u16_t;
typedef signed short s16_t;

typedef unsigned long ksize_t;
typedef ksize_t kword_t;
typedef u64_t kptr_t;

typedef long double f128_t;
typedef double      f64_t;
typedef float       f32_t;

typedef long long unsigned int largest_int_t;

#endif
