#include "s21_math.h"

long double s21_floor(double x) {
  long double res = (long long int)x;
  if (s21_fabs(x) == s21_INF || x != x)
    res = x;
  else if (s21_fabs(x - res) > 0. && s21_fabs(x) > 0. && x < 0.)
    res -= 1;
  return res;
}
