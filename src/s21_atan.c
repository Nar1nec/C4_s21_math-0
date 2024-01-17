#include "s21_math.h"

long double s21_atan_taylor(double x);

long double s21_atan(double x) {
  long double final_atan = 0.0;

  if (x != x) {
    final_atan = x;
  } else if (x < 0) {
    x = -x;
    final_atan = -s21_atan(x);
  } else if (x == 1) {
    final_atan = 0.7853981633974483;
  } else if (x == -1) {
    final_atan = -0.7853981633974483;
  } else {
    final_atan = s21_atan_taylor(x);
  }
  return final_atan;
}

long double s21_atan_taylor(double x) {
  long double final_atan = 0.0;
  long double prev_val = -1;
  long double i = 0.0;
  int sign = 1;
  long double add_number = 0;
  while (s21_fabs(final_atan - prev_val) > s21_EPS) {
    if (s21_fabs(x) < 1) {
      add_number = sign * s21_pow(x, 2 * i + 1) / (2 * i + 1);
    } else {
      add_number = sign * s21_pow(x, (-1 - 2 * i)) / (2 * i + 1);
    }
    prev_val = final_atan;
    final_atan += add_number;
    i++;
    sign *= -1;
  }
  if (s21_fabs(x) > 1) final_atan = s21_PI / 2 - final_atan;
  return final_atan;
}