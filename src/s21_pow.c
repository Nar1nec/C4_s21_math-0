#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res;
  if (exp == 0) {
    res = 1;
  } else if (base == 1 || ((s21_fabs(base)) == 1 && exp == -s21_INF)) {
    res = 1;
  } else if (s21_isNan(base) || s21_isNan(exp)) {
    res = s21_NAN;
  } else if (base == 0) {
    res = exp < 0 ? s21_INF : 0;
  } else if (exp == -s21_INF) {
    res = s21_fabs(base) < 1 ? s21_INF : 0;
  } else if (base == -s21_INF) {
    res = exp > 0 ? s21_INF : 0;
  } else if (s21_fabs(exp) == s21_INF) {
    res = s21_fabs(base) < 1 ? 0 : s21_INF;
  } else if (base < 0) {
    if (s21_fabs(exp - (int)exp) > s21_EPS) {
      res = s21_NAN;
    } else {
      base = -base;
      res = s21_exp(exp * s21_log(base));
      if (s21_fmod(exp, 2) != 0) res = -res;
    }
  } else {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}