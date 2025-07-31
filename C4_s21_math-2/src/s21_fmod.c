#include "s21_math.h"

long double s21_fmod(double x, double y) {
  double res = 0.0;

  if (x != x || y != y || y == 0.0) {
    res = 0.0 / 0.0;
  } else if (x == S21_POS_INF || x == S21_NEG_INF) {
    res = S21_NAN;
  } else if (y == S21_POS_INF || y == S21_NEG_INF) {
    res = x;
  } else {
    double quotient = s21_floor(x / y);
    res = x - (quotient * y);
  }

  return res;
}