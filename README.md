# c-numerical-methods
Some numeric methods in C.

# Usage

This is Single-file header-only libraries. 
General usage:
```c
#define FLAG_IMPLEMENTATION
#include "/path/to/file.h"
```

List of flags you can find on the corresponding page.

# Description

## Integration

### Interface

Integration functions with following syntax: 
```c
float integrate(float a, float b, unsigned N, float (*f)(float))
```
where:
- `a` -- begin of integration;
- `b` -- end of integration;
- `N` -- number of points;
- `*f` -- pointer to float function with `f(float x)` syntax.

These funtions return float number. 

**N.B.**: don't forget to `free` result.

### List of methods

- [Rectange method](https://en.wikipedia.org/wiki/Riemann_sum)
- [Trapezoids method](https://en.wikipedia.org/wiki/Trapezoidal_rule)

## Solvers

Here will be functions that solve ordinary differential equations. 

Syntax:
```c
float **solve(unsigned M, unsigned N, float *t,
                    float *(*dxdt)(float *, float, unsigned), float *X0);
```
where:

- `M` -- number of equations in system;
- `N` -- number of points to integrate
- `*t` -- pointer to time array size of `N`
- `*(*dxdt)(float, *float, unsigned)` --  pointer to function that compute **dX**:
    - first argument is pointer to array of **X**;
    - second argument is `t`;
    - third argument is `M`;
- `*X0` -- pointer to array of initial conditions size of `M`.

These funtions return pointer to float array size of `N`x`M`. 

**N.B.**: don't forget to `free` result.

# TODO

1. [ ] Think about `IMPLEMENTATION`-flags.
