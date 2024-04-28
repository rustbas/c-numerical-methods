#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

float **runge_kutta(unsigned M, unsigned N, float *t,
                    float *(*dxdt)(float *, float, unsigned), float *X0);
