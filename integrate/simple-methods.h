#ifndef _INTEGRATE_SIMPLE_METHODS
#define _INTEGRATE_SIMPLE_METHODS

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

float squares(float a, float b, unsigned N, float (*f)(float));
float trapecia(float a, float b, unsigned N, float (*f)(float));
#endif

// ----------------------------------------
// ----------------------------------------
// ----------------------------------------

#ifdef INTEGRATE_SM_IMPLEMENTATION
// TODO: Add dirty hack
// TODO: Fix error accumulation
float squares(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / N;
  float result = 0.0;

  while (a < b) {
    result += h * f(a + h / 2);
    a += h;
  }

  return result;
}

float trapecia(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / N;
  float result = 0.0;

  while (a < b) {
    result += h * (f(a) + f(a + h)) / 2;
    a += h;
  }

  return result;
}

#endif
