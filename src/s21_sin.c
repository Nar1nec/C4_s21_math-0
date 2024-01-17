#include "s21_math.h"

long double s21_sin(double x) {
  long double res;
  if (s21_fabs(x) == s21_INF) {
    res = s21_NAN;
  } else {
    for (; (x < -2 * s21_PI) || (2 * s21_PI < x);) {
      if (x > s21_PI)
        x -= 2 * s21_PI;
      else
        x += 2 * s21_PI;
    }
    res = x;
    long double y = x, fac = 1.;
    while (s21_fabs(y) > 1e-16) {
      y = -1 * y * x * x / (2 * fac * (2 * fac + 1));
      fac += 1.;
      res += y;
    }
  }
  return res;
}
