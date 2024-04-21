#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integrate/simple-methods.h"
#include "solvers/simple.h"

#define N 10000

float f(float x) {
    return x*x;
}

float* dxdt(float* X, float t, unsigned M) {
    float *dx = (float*) malloc(sizeof(float) * M);
    dx[0] = X[0];

    return dx;
}

int main() {
    float* t = (float*) malloc(sizeof(float) * N);
    for (int i=0; i<N;i++) {
        t[i] = (float) i / 1000.0f;
        //printf("%f\n", t[i]);
    }

    float X0[] = {1.0f};

    float** res = solve(1, N, t, dxdt, X0);


    for (int i=0; i<N;i++) {
        printf("%f\t", t[i]);
        for (int j=0; j<1;j++) {
            printf("%f\n", res[i][j]);
        }
    }

    for (int i=0; i<1; i++) {
        free(res[i]);
    }
    free(res);

}
