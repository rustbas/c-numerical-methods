# c-numerical-methods
Some numeric methods on C.

# integrate

Integration functions with following syntax: 
```c
float integrate(float a, float b, unsigned N, float (*f)(float))
```
where:
- `a` -- begin of integration;
- `b` -- end of integration;
- `N` -- number of points;
- `*f` -- pointer to float function with `f(float x)` syntax.

# TODO

1. [ ] ./solvers/simple.h:// TODO: include all libs with inclusions guards
2. [ ] ./solvers/runge-kutta.h:// TODO: Fix k_i
