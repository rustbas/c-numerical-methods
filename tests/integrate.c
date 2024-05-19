#define INTEGRATE_SM_IMPLEMENTATION
#include "../integrate/simple-methods.c"

#define CTESTS_IMPLEMENTATION
#include "ctests.c"

#define TEST_LIST                                                              \
  X(result_f1, f1, results1)                                                   \
  X(result_f2, f2, results2)

float f1(float x) { return x; }
float f2(float x) { return x * x; }

float limits_a[] = {0, -5, 0};
float limits_b[] = {1, 5, 10};
float results1[] = {0.5f, 0.0f, 50.0f};
float results2[] = {1.0f / 3.0f, 83.33333333f, 333.333333333f};

size_t n_limits = sizeof(limits_a) / sizeof(limits_a[0]);
#define N 1000
#define EPS 0.001f

int main() {

  ct_verbose = 2;

  // TODO: Use X-macros

  size_t i;
  float result_f1;
  float result_f2;

  for (i = 0; i < n_limits; i++) {
#define X(res, fun, I)                                                         \
  res = squares(limits_a[i], limits_b[i], N, fun);                             \
  ct_assert_float(res, I[i], EPS);
    TEST_LIST
#undef X
  }

  for (i = 0; i < n_limits; i++) {
#define X(res, fun, I)                                                         \
  res = trapecia(limits_a[i], limits_b[i], N, fun);                            \
  ct_assert_float(res, I[i], EPS);
    TEST_LIST
#undef X
  }

  ct_stat();

  return 0;
}
