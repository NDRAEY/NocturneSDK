#pragma once

#include "stdint.h"
#include "stddef.h"

#define PI (3.1415926535897)

#define ABS(a) ((a) >= 0 ? (a) : -(a))

#define MIN(a, b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
   _a < _b ? _a : _b; })

#define MAX(a, b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
   _a > _b ? _a : _b; })

#define NAN int2float(0x7fc00000)
#define INFINITY int2float(0x7f800000)

union intfloat32 {
   uint32_t i;
   float    f;
};

union intfloat64 {
   uint64_t i;
   double   f;
};

static inline float int2float(uint32_t i) {
    union intfloat32 v;
    v.i = i;
    return v.f;
}

static inline double int2double(uint64_t i) {
    union intfloat64 v;
    v.i = i;
    return v.f;
}

static inline bool is_nan(float value) {
   union intfloat32 value_union;
   value_union.f = value;

   int exponent = (value_union.i >> 23) & 0xFF;
   int fraction = value_union.i & 0x7FFFFF;

   return exponent == 0xFF && fraction != 0;
}

static inline bool is_inf(float value) {
   union intfloat32 value_union;
   value_union.f = value;

   unsigned int exponent = (value_union.i >> 23) & 0xFF;
   unsigned int fraction = value_union.i & 0x7FFFFF;

   return (exponent == 0xFF) && (fraction == 0);
}

static inline double floor(double x) {
   int intPart = (int)x;
   
   return intPart - (x < 0 && x != intPart);
}

static inline double ceil(double x) {
   int intPart = (int)x;

   return intPart + (x > 0 && x != intPart);
}

static inline double fabs(double x) {
   return (x < 0) ? -x : x;
}


#define ASIN_STEPS 6000
#define ATAN_STEPS 6000

size_t fac(size_t x);

double deg2rad(double degrees);
double rad2deg(double radians);

double sin(double x);
double cos(double x);
double tan(double x);

double pow(double base, double exponent);

double trapezoidal_rule(double (*f)(double), double a, double b, unsigned int steps);

double log(double x);
double exp(double x);

double asin(double x);
double acos(double x);
double atan(double x);

double sqrt(double x);
double cbrt(double x);
double modf(double value, double* intPart);
float fmodf(float x, float y);
