#include "integrate/test.c"
#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x;
}

int main() {
    printf("n,error\n");
    for (int i=1; i<=1000; i++) {
        printf("%2d,%6f\n", i, fabs(squares(0,5,i,f)-125.0/3));
    }
}
