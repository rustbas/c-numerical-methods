#define INTEGRATE_SM_IMPLEMENTATION
#include "../integrate/simple-methods.c"

#define CTESTS_IMPLEMENTATION
#include "ctests.c"

#define TESTS_LIST                                                             \
  X(f1, I_est_sq, I_est_trap, I_true)                                          \
  X(f2, I_est_sq, I_est_trap, I_true)

#define N 1000
#define EPS 0.001f

int main() {

  ct_verbose = 2;
  float I_est_sq, I_est_trap, I_true;

  // TODO: Use X-macros

  ct_stat();

  return 0;
}
