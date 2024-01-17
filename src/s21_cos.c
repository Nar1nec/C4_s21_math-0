#include "s21_math.h"

long double s21_cos(double x) {
  long double sum_cos = 0.;
  if (s21_fabs(x) == s21_INF) {
    sum_cos = s21_NAN;
  } else {
    for (; (x < -2 * s21_PI) || (2 * s21_PI < x);) {
      if (x > s21_PI)
        x -= 2 * s21_PI;
      else
        x += 2 * s21_PI;
    }
    sum_cos = 1.;
    int i = 1.;
    long double add_val = 1.;
    while (s21_fabs(add_val) > 1e-16) {
      add_val = (-add_val * x * x) / ((2.0 * i - 1) * (2.0 * i));
      sum_cos += add_val;
      i++;
    }
  }
  return sum_cos;
}