// #include "s21_math.h"

// long double s21_log(double x) {
//     double res = 0.0;
//     if(x == 0) {
//         res = S21_NEG_INF;
//     } else if (x == S21_POS_INF) {
//         res = x;
//     } else {
//         double term = (x - 1) / x;
//         int i = 1;
//         if(x > 0) {
//         while (term > 1e-10 || term < -1e-10) {
//             res += term;
//             term *= -(x - 1) / (x * i);
//             i++;
//         }
//         } else {
//             res = 0.0 / 0.0;
//         }
//     }

//     return res;
// }

#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;

  if (x < 0)
    result = S21_NAN;
  else if (x == 0)
    result = S21_NEG_INF;
  else if (x == S21_POS_INF)
    result = x;
  else if (x == 1)
    result = 0;
  else {
    double integerPart = 0.0, fractionalPart = x;
    while (fractionalPart >= S21_EXP) {
      fractionalPart /= S21_EXP;
      integerPart++;
    }
    integerPart += fractionalPart / S21_EXP;
    fractionalPart = x;

    double leftBound, rightBound;
    for (int i = 0; i < 1000; i++) {
      leftBound = (fractionalPart / s21_exp(integerPart - 1.0));
      rightBound = ((integerPart - 1.0) * S21_EXP);
      integerPart = ((leftBound + rightBound) / S21_EXP);
    }
    result = integerPart;
  }
  return result;
}
