#include "simple-methods.h"

float squares(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / N;
  float result = 0.0;

  while (a < b) {
    result += h * f(a + h / 2);
    a += h;
  }

  return result;
}

float trapecia(float a, float b, unsigned N, float (*f)(float)) {
  float h = (b - a) / N;
  float result = 0.0;

  while (a < b) {
    result += h * (f(a) + f(a + h)) / 2;
    a += h;
  }

  return result;
}