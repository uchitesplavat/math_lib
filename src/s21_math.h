#include <stdio.h>
#include <stdlib.h>

#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_LN10 2.30258509299404568401799145468436421
#define S21_LN2 0.693147180559945309417232121458176568
#define PRECISION 1e-15
#define S21_PI_6 0.52359877559829881565889309058547951
#define S21_PI_4 0.785398163397448309615660845819875721
#define S21_PI_3 1.04719755119659763131778618117095903
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_PI 3.14159265358979323846264338327950288
#define S21_SQRT_3_DIV_2 0.86602540378443859658830206171842292
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0


int s21_abs(int x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_sqrt(double x);
long double s21_exp(double x);
long double s21_pow(double base, double exp);
long double s21_log(double x);
long double s21_atan(double x);
static int check_input(double *x, double n, int *z, long double *result);
static long double not_int(double x, double n, int *z_n, int *z_x, long double result);
static long double s21_floor_ceil(double x, int c, int f);
int s21_isinf(double x);
int s21_isnan(double x);

#endif  // SRC_S21_MATH_H_
