#define INTEGRATE_SM_IMPLEMENTATION
#include "../integrate/simple-methods.c"

#define CTESTS_IMPLEMENTATION
#include "ctests.c"

float f1(float x) { return x; }

float limits_a[] = {0, -5, 0};
float limits_b[] = {1, 5, 10};
float results1[] = {0.5f, 0.0f, 50.0f};

size_t n_limits = sizeof(limits_a) / sizeof(limits_a[0]);
#define N 1000
#define EPS 0.001f

int main() {

  ct_verbose = 1;

  // TODO: Use X-macros

  size_t i;
  float result1;
  float result2;

  for (i = 0; i < n_limits; i++) {
    result1 = squares(limits_a[i], limits_b[i], N, f1);
    ct_assert_float(result1, results1[i], EPS);
  }

  for (i = 0; i < n_limits; i++) {
    result2 = trapecia(limits_a[i], limits_b[i], N, f1);
    ct_assert_float(result2, results1[i], EPS);
  }

  ct_stat();

  return 0;
}
