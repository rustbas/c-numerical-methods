# c-numerical-methods
Some numeric methods in C.

# Usage

1. You need to compile libraries. Just run `make` in root directory.
2. To link with them:
    1. Add object directory with `-L/path/to/obj`
    2. Link with library. For `libname.so` you need add parameter `-lname`.

# Description

## Integration

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

1. [x] Include all libs with inclusions guards;
2. [x] Fix k\_i;
3. [x] Create `makefile`;
4. [x] Create `*.c` files with function;
