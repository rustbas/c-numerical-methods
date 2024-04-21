#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integrate/simple-methods.h"
#include "solvers/simple.h"
#include "solvers/runge-kutta.h"

#define N 100000

float f(float x) {
    return x*x;
}

void dxdt(float* X, float t, unsigned M, float* dx) {
    //float *dx = (float*) malloc(sizeof(float) * M);

    dx[0] = X[1];
    dx[1] = -2*X[0];

    //return dx;
}

float true_f(float t) {
    return 2*sin(t) + 1*cos(t);
}

int main() {
    float* t = (float*) malloc(sizeof(float) * N);
    for (int i=0; i<N;i++) {
        t[i] = (float) i / 1000000.0f;
        //printf("%f\n", t[i]);
    }

    float X0[] = {1.0f, 1.0f};

    float** res1 = runge_kutta(2, N, t, dxdt, X0);
    float** res2 = solve(2, N, t, dxdt, X0);


    for (int i=0; i<N;i++) {
        printf("%f,%f,%f,\n",
                res1[i][0]-true_f(t[i]),
                res2[i][0]-true_f(t[i]),
                res2[i][0]-res1[i][0]);
    }

    for (int i=0; i<2; i++) {
        free(res1[i]);
    }
    free(res1);
    for (int i=0; i<2; i++) {
        free(res2[i]);
    }
    free(res2);

}
