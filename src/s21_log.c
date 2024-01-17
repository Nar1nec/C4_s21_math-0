#include "s21_math.h"

// Nan x != x

long double s21_log(double x) {
  long double sum_log = 0;
  long double value = 0;
  int exp_p = 0;

  if (x == s21_NAN || x < 0)
    sum_log = s21_NAN;
  else if (x == 0)
    sum_log = -s21_INF;
  else if (s21_fabs(x) == s21_INF)
    sum_log = x;
  else {
    for (; x >= s21_EXP; x /= s21_EXP, exp_p++) {
    }
    for (int i = 0; i < 50; i++) {
      value = sum_log;
      sum_log = value + 2 * ((x - s21_exp(value)) / (x + s21_exp(value)));
    }
  }
  return sum_log + exp_p;
}
