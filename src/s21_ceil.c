#include "s21_math.h"

// Nan x != x

long double s21_ceil(double x) {
  long double x1 = (long long int)x;
  if (x != x || s21_fabs(x) == s21_INF)
    x1 = x;
  else if (x1 != x && x >= 0.)
    x1 += 1;
  return x1;
}
