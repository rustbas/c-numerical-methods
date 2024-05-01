# Integration

## Interface

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

## Flags

| Method | File to include | `FLAG` |
|-|-|-|
| Rectangles method | `simple-method.h` |`INTEGRATE_SM_IMPLEMENTATION` | 
| Trapezoid method | `simple-method.h` |`INTEGRATE_SM_IMPLEMENTATION` | 
