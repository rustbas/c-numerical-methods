#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

// TODO: Fix k_i
float **runge_kutta(unsigned M, unsigned N, float *t,
                    float *(*dxdt)(float *, float, unsigned), float *X0) {
  float **result = (float **)malloc(sizeof(float *) * N);
  for (int i = 0; i < N; i++) {
    result[i] = (float *)malloc(sizeof(float) * M);
  }

  for (int i = 0; i < M; i++) {
    result[0][i] = X0[i];
  }

  float *k1 = (float *)malloc(sizeof(float) * M);
  float *k2 = (float *)malloc(sizeof(float) * M);
  float *k3 = (float *)malloc(sizeof(float) * M);
  float *k4 = (float *)malloc(sizeof(float) * M);

  float *tmp = (float *)malloc(sizeof(float) * M);

  for (int i = 1; i < N; i++) {

    float h = t[i] - t[i - 1];

    // compute k_i
    // k_1
    for (int j = 0; j < M; j++) {
      tmp[j] = result[i - 1][j];
    }
    k1 = dxdt(tmp, t[i - 1], M);

    // k_2
    for (int j = 0; j < M; j++) {
      tmp[j] = result[i - 1][j] + h / 2.0f * k1[j];
    }
    k2 = dxdt(tmp, t[i - 1] + h / 2.0, M);

    // k_3
    for (int j = 0; j < M; j++) {
      tmp[j] = result[i - 1][j] + h / 2.0f * k2[j];
    }
    k3 = dxdt(tmp, t[i - 1] + h / 2.0, M);

    // k_4
    for (int j = 0; j < M; j++) {
      tmp[j] = result[i - 1][j] + h * k3[j];
    }
    k4 = dxdt(tmp, t[i - 1] + h, M);

    // compute result[i][j]
    for (int j = 0; j < M; j++) {
      result[i][j] = result[i - 1][j] +
                     h / 6.0f * (k1[j] + 2.0f * k2[j] + 2.0f * k3[j] + k4[j]);
    }
    free(k1);
    k1 = NULL;
    free(k2);
    k2 = NULL;
    free(k3);
    k3 = NULL;
    free(k4);
    k4 = NULL;
  }

  free(tmp);
  // free(tmpd);

  return result;
}
