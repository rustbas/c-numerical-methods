#ifndef _INTEGRATE_SIMPLE_METHODS
#define _INTEGRATE_SIMPLE_METHODS

// Dirty hack
#ifndef INTEGRATE_SM_IMPLEMENTATION
#define INTEGRATE_SM_IMPLEMENTATION
#define _INTEGRATE_SM_IMPLEMENTATION
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#include <stdio.h>

float old_squares(float a, float b, unsigned N, float (*f)(float));
float new_squares(float a, float b, unsigned N, float (*f)(float));

float old_trapecia(float a, float b, unsigned N, float (*f)(float));
float new_trapecia(float a, float b, unsigned N, float (*f)(float));
#endif

// ----------------------------------------
// ----------------------------------------
// ----------------------------------------

#ifdef INTEGRATE_SM_IMPLEMENTATION
// TODO: Fix error accumulation
float old_squares(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / N;
  float result = 0.0;

  while (a < b) {
    result += h * f(a + h / 2);
    a += h;
  }

  return result;
}

float new_squares(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / (N - 1);
  float result = 0.0;
  float *xs = (float *)malloc(sizeof(float) * N);
  int i;
  for (i = 0; i < N; i++) {
    xs[i] = a + h * i;
  }

  for (i = 0; i < N - 1; i++) {
    // result += (xs[i] - xs[i - 1]) * f((xs[i] + xs[i - 1]) / 2);
    result += h * f((xs[i] + xs[i + 1]) / 2);
  }

  free(xs);

  return result;
}

float old_trapecia(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / N;
  float result = 0.0;

  while (a < b) {
    result += h * (f(a) + f(a + h)) / 2;
    a += h;
  }

  return result;
}

float new_trapecia(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / (N - 1);
  float result = 0.0;

  float *xs = (float *)malloc(sizeof(float) * N);
  int i;
  for (i = 0; i < N; i++) {
    xs[i] = a + h * i;
  }

  for (i = 0; i < N - 1; i++) {
    // result += (xs[i] - xs[i - 1]) * f((xs[i] + xs[i - 1]) / 2);
    result += h * (f(xs[i]) + f(xs[i + 1])) / 2.0f;
  }

  free(xs);
  return result;
}

#endif
