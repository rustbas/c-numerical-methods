#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

float **solve(unsigned M, unsigned N, float *t,
              float *(*dxdt)(float *, float, unsigned), float *X0);
