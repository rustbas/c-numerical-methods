#define INTEGRATE_SM_IMPLEMENTATION
#include "../integrate/simple-methods.c"
#include <stdio.h>

#define MAX_N 25000

#if 0
#define STREAM result_file
#else
#define STREAM stdout
#endif

#define RESULT_PATH "result.csv"

float fun(float x) { return x * x; }

int main() {

  FILE *result_file = fopen(RESULT_PATH, "w");
  int i;
  float result1, result2;
  float result3, result4;
  float a = 0.0f;
  float b = 10.0f;
  float true_I = (b * b * b) / 3.0f - (a * a * a) / 3.0f;

  fprintf(STREAM, "N,old_method_error,new_method_error\n");
  for (i = 2; i < MAX_N; i++) {
    result2 = squares(a, b, i, fun);
    result4 = trapecia(a, b, i, fun);
    fprintf(STREAM, "%d,%f,%f\n", i, fabs(result2 - true_I),
            fabs(result4 - true_I));
  }

  fclose(result_file);

  return 0;
}
