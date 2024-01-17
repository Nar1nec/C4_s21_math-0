#include "s21_math.h"

long double s21_sqrt(double x) {
  long double left, right, mid = 0;
  if (x >= 0) {
    left = 0;
    right = s21_fmax(1, x);
    mid = (left + right) / 2;

    while (s21_fabs(mid - left) > s21_EPS) {
      if (mid * mid > x)
        right = mid;
      else
        left = mid;
      mid = (left + right) / 2;
    }
  } else
    mid = 0.0 / 0.0;
  return mid;
}
