# c-numerical-methods
Some numeric methods on C.

# integrate

Integration functions with following syntax: 
```
float integrate(float a, float b, unsigned N, float (*f)(float))
```
where:
- `a` -- begin of integration;
- `b` -- end of integration;
- `N` -- number of points;
- `*f` -- pointer to float function with `f(float x)` syntax.
