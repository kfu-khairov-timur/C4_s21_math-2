#include "s21_math.h"

long double s21_sin(double x) {
  long double result;

  if (x == S21_POS_INF || x == S21_NEG_INF || x != x) {
    result = S21_NAN;
  } else {
    x = x - ((int)(x / (2 * S21_M_PI))) * (2 * S21_M_PI);
    long double sin = x;
    long double term = x;
    long double precision = 0.000001;
    int max_iterations = 100000;

    int n;
    for (n = 1; n < max_iterations && (term > precision || term < -precision);
         n += 2) {
      term *= -((x * x) / ((n + 1) * (n + 2)));
      sin += term;

      if (term < precision && term > -precision) {
        break;
      }
    }

    result = sin;
  }

  return result;
}
