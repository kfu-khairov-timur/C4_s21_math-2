#include "s21_math.h"

long double s21_cos(double x) {
  long double result;

  if (x == S21_POS_INF || x == S21_NEG_INF || x != x) {
    result = S21_NAN;
  } else {
    x = x - ((int)(x / (2 * S21_M_PI))) * (2 * S21_M_PI);
    long double cos = 1.0;
    long double term = 1.0;
    long double precision = 0.0000001;
    int max_iterations = 1000000;

    int n;
    for (n = 1; n < max_iterations && (term > precision || term < -precision);
         n += 2) {
      term *= -((x * x) / (n * (n + 1)));
      cos += term;

      if (term < precision && term > -precision) {
        break;
      }
    }

    result = cos;
  }

  return result;
}
