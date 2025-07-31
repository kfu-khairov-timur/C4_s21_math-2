#include "s21_math.h"

long double s21_tan(double x) {
  long double tan = 0;
  long double sin_x = s21_sin(x);
  long double cos_x = s21_cos(x);

  if (x == S21_POS_INF || x == S21_NEG_INF) {
    tan = S21_NAN;
  } else if (sin_x == 0) {
    tan = 0;
  } else if (cos_x > 1e-6 || cos_x < -1e-6) {
    tan = sin_x / cos_x;
  } else if (x != x) {
    tan = S21_NAN;
  } else {
    tan = S21_NAN;
  }
  return tan;
}
