# Solvers

Here will be functions that solve ordinary differential equations. 

## Interface

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

These funtions return pointer to float 2D-array size of `N`x`M`. 

**N.B.**: don't forget to `free` result.

## Flags

| Method | File to include | `FLAG` |
|-|-|-|
| Euler's method | `euler.h` |`SOLVER_EULER_IMPLEMENTATION` | 
| Runge-Kutta | `runge-kutta.h` | `SOLVER_RUNGE_KUTTA_IMPLEMENTATION` | 
