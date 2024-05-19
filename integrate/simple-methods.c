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

float squaresf(float a, float b, unsigned N, float (*f)(float));
float trapeciaf(float a, float b, unsigned N, float (*f)(float));

double squares(double a, double b, unsigned N, double (*f)(double));
double trapecia(double a, double b, unsigned N, double (*f)(double));
#endif

// ----------------------------------------
// ----------------------------------------
// ----------------------------------------

#ifdef INTEGRATE_SM_IMPLEMENTATION

float squaresf(float a, float b, unsigned N, float (*f)(float)) {
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

float trapeciaf(float a, float b, unsigned N, float (*f)(float)) {
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

double squares(double a, double b, unsigned N, double (*f)(double)) {
  double h = (b - a) / (N - 1);
  double result = 0.0;
  double *xs = (double *)malloc(sizeof(double) * N);
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

double trapecia(double a, double b, unsigned N, double (*f)(double)) {
  double h = (b - a) / (N - 1);
  double result = 0.0;

  double *xs = (double *)malloc(sizeof(double) * N);
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

#ifdef _INTEGRATE_SM_IMPLEMENTATION
#undef INTEGRATE_SM_IMPLEMENTATION
#undef _INTEGRATE_SM_IMPLEMENTATION
#endif
