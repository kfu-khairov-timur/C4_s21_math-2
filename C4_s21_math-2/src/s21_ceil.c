#include "s21_math.h"

long double s21_ceil(double x) {
  double res = (int)x;

  if (x != x) {
    res = S21_NAN;
  } else if (x == S21_POS_INF || x == S21_NEG_INF) {
    res = x;
  } else {
    if (res < x) {
      res++;
    }
  }

  return res;
}