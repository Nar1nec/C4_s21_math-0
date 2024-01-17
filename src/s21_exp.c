#include "s21_math.h"

long double s21_exp(double x) {
  int neg_flag = (x < 0) ? 1 : 0;
  x = s21_fabs(x);
  long double i = 1.;
  long double add_num = 1.;
  long double final_value = 1.;
  long double prev_value = 0.;

  while (s21_fabs(final_value - prev_value) > 1e-16 &&
         s21_fabs(final_value) <= s21_MAX_DOUBLE) {
    prev_value = final_value;
    add_num *= x / i;
    final_value += add_num;
    i += 1.;
    if (final_value > s21_MAX_DOUBLE) final_value = s21_INF;
  }
  if (neg_flag) final_value = 1 / final_value;
  return final_value;
}
