#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0;
  if (s21_fabs(x) > 1 || s21_isNan(x))
    res = s21_NAN;
  else if (x >= 0) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x < 0) {
    res = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return res;
}
