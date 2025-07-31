#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = S21_NAN;
  double x = base;
  if (x == S21_NAN) {
    if (exp == S21_NEG_INF || exp == S21_POS_INF) {
      result = S21_NAN;
    }
  }
  if (exp == 0) {
    result = 1;
  } else if (x == S21_NEG_INF) {
    if (exp == S21_NAN) {
      result = S21_NAN;
    } else if (exp == S21_NEG_INF) {
      result = 0;
    } else if (exp == S21_POS_INF) {
      result = S21_POS_INF;
    }
  } else {
    if (x < 0) {
      x = -x;
    }
    result = s21_exp(exp * s21_log(x));
    if (base < 0 && (s21_fmod(exp, 2) != 0)) {
      result = -result;
    }
  }
  return result;
}
