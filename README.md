# c-numerical-methods
Some numeric methods on C.

# Usage

1. You need to compile libraries. Just run `make` in root directory.
2. To link with them:
    1. Add object directory with `-L/path/to/obj`
    2. Link with library. For `libname.so` you need add parameter `-lname`.

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

These funtions return pointer to float array. **N.B.**: don't forget to `free` result.

# TODO

1. [x] Include all libs with inclusions guards;
2. [x] Fix k\_i;
3. [x] Create `makefile`;
4. [x] Create `*.c` files with function;
