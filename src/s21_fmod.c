#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  if (s21_fabs(y) == s21_INF && (s21_fabs(x) != s21_INF)) {
    res = x;
  } else if (s21_fabs(x) == s21_INF) {
    res = s21_NAN;
  } else if (y != 0.0) {
    res = x - (long long int)(x / y) * y;
  } else {
    res = s21_NAN;
  }
  return res;
}
