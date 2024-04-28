# c-numerical-methods
Some numeric methods on C.

# Integration

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

1. [x] Include all libs with inclusions guards;
2. [x] Fix k\_i;
3. [ ] Create `makefile`;
4. [ ] Create `*.c` files with function;
