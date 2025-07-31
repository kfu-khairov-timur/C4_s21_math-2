#include "s21_math.h"

long double s21_atan(double x) {
  long double atan = 0;

  if (x != x) {
    atan = S21_NAN;
  }
  if (x == S21_POS_INF) {
    atan = S21_M_PI / 2;
  }
  if (x == S21_NEG_INF) {
    atan = -S21_M_PI / 2;
  }
  if (x == 0) {
    atan = 0;
  }

  return atan;
}