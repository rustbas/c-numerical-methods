#define INTEGRATE_SM_IMPLEMENTATION
#include "../integrate/simple-methods.c"

#define CTESTS_IMPLEMENTATION
#include "ctests.c"

#define TEST_LIST                                                              \
  X(f1, results_f1)                                                            \
  X(f2, results_f2)                                                            \
  X(f3, results_f3)                                                            \
  X(f4, results_f4)                                                            \
  X(f5, results_f5)                                                            \
  X(f6, results_f6)

#define N 100000
#define EPS 0.0001

double f1(double x) { return x; }
double f2(double x) { return x * x; }
double f3(double x) { return sin(x); }
double f4(double x) { return exp(x); }
double f5(double x) { return sin(x) * exp(x); }
double f6(double x) { return x * x + x - 2; }

double limits_a[] = {
    0,
    -5,
    0,
    -5,
};
double limits_b[] = {
    1,
    5,
    10,
    -3,
};

float results_f1[] = {
    0.5,
    0.0,
    50.0,
    -8.0,
};
float results_f2[] = {
    0.33333333333333337,
    83.33333333333334,
    333.33333333333326,
    32.66666666666667,
};
float results_f3[] = {
    0.45969769413186023,
    0.0,
    1.8390715290764525,
    1.2736546820636718,
};
float results_f4[] = {
    1.7182818284590453,
    148.40642115557753,
    22025.465794806725,
    0.043049121368778476,
};
float results_f5[] = {
    0.9093306736314788,
    -92.2103659428046,
    3249.9589719705905,
    0.01885649622752392,
};

float results_f6[] = {
    -1.1666666666666667,
    63.33333333333334,
    363.33333333333337,
    20.666666666666668,
};

size_t num_limits = sizeof(limits_a) / sizeof(limits_a[0]);

int main() {

  ct_verbose = 2;
  double I_est_sq, I_est_tr, I_true;
  int i;

  for (i = 0; i < num_limits; i++) {
#define X(f, results_f)                                                        \
  I_est_sq = squares(limits_a[i], limits_b[i], N, f);                          \
  I_est_tr = trapecia(limits_a[i], limits_b[i], N, f);                         \
  I_true = results_f[i];                                                       \
  ct_assert_float(I_est_sq, I_true, EPS);                                      \
  ct_assert_float(I_est_tr, I_true, EPS);
    TEST_LIST
#undef X
  }

  ct_stat();

  return 0;
}
