#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdio.h>

#define S21_EXP 2.71828182845904523536028747
#define S21_EPSILON 1000
#define S21_MAX_DOUBLE 1.79769313486231570e+308d
#define S21_NAN 0.0 / 0.0
#define S21_POS_INF 1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0
#define S21_M_PI 3.141592653589793238462643383279502884L
#define S21_M_PI_2 1.570796326794896619231321691639751442L

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
