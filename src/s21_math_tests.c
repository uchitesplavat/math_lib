#include "s21_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>

START_TEST(absTest) {
  ck_assert_int_eq(s21_abs(-15), abs(-15));
  ck_assert_int_eq(s21_abs(15), abs(15));
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(fabsTest) {
  ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01));
  ck_assert_ldouble_eq(s21_fabs(15.01), fabs(15.01));
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));

  double num = NAN;
  long double orig_res = fabs(num), our_res = s21_fabs(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(ceilTest) {
  ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01));
  ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01));
  ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12));

  long double num = NAN;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  printf("------------   %lf\n", ceil(NAN));
  printf("------------   %lf\n", s21_ceil(NAN));
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
  // ck_assert_ldouble_eq(ceil(NAN), s21_ceil(NAN));
}
END_TEST

START_TEST(floorTest) {
  ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01));
  ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01));
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));

  double num = NAN;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sqrtTest) {
  double num = INFINITY;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -15.01;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.9999;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atanTest) {
  ck_assert_float_eq(s21_atan(-15.01), atan(-15.01));

  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(-9999999999, -9999999999);

  ck_assert_ldouble_eq(s21_atan(INFINITY), atan(INFINITY));
  ck_assert_ldouble_eq(s21_atan(-INFINITY), atan(-INFINITY));

  num = NAN;
  orig_res = s21_atan(num), our_res = atan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acosTest) {
  double num = 0.55;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.99;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -9;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = s21_acos(num), our_res = acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(asinTest) {
  double num = 0.55;
  long double orig_res = asin(num), our_res = s21_asin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.99;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -9;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sinTest) {
  double num = 0.55;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(s21_sin(0), sin(0));

  num = 1;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -1;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.999999;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.999999;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = sin(num), our_res = s21_sin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = sin(num), our_res = s21_sin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = sin(num), our_res = s21_sin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cosTest) {
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.999999;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 628;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(s21_cos(0), cos(0));
  ck_assert_float_eq(s21_cos(-1), cos(-1));

  num = NAN;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tanTest) {
  ck_assert_float_eq(s21_tan(-15.01), tan(-15.01));

  double num = 0.55;
  long double orig_res = s21_tan(num), our_res = s21_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(-9999999999, -9999999999);

  num = NAN;
  orig_res = tan(num), our_res = s21_tan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = tan(num), our_res = s21_tan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = tan(num), our_res = s21_tan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(expTest) {
  ck_assert_float_eq(s21_exp(2), exp(2));
  ck_assert_float_eq(s21_exp(-750), exp(-750));
  ck_assert_float_eq(s21_exp(-2), exp(-2));

  double num = NAN;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = exp(num), our_res = s21_exp(num);
  suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = exp(num), our_res = s21_exp(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(logTest) {
  double num = 456.789;
  long double orig_res = log(num), our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.001;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.4;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(powTest) {
  double num = 456.789;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  ck_assert_float_eq(our_res, orig_res);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  ex = 1.1;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  ex = 1.1;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  ex = NAN;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.001;
  ex = NAN;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  ex = INFINITY;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  ex = INFINITY;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(fmodTest) {
  ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
  ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
  ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));

  double num = NAN;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));

  num = INFINITY;
  orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));

  num = -INFINITY;
  orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(test_s21_abs) {
    ck_assert_int_eq(s21_abs(21), abs(21));
    ck_assert_int_eq(s21_abs(-21), abs(-21));
    ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
    ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
}
END_TEST

// s21_ceil
START_TEST(test_s21_ceil) {
    ck_assert_msg(s21_ceil(0.0) == ceil(0.0), "s21_ceil");
    ck_assert_msg(s21_ceil(21.21) == ceil(21.21), "s21_ceil");
    ck_assert_msg(s21_ceil(21.91) == ceil(21.91), "s21_ceil");
    ck_assert_msg(s21_ceil(-21.21) == ceil(-21.21), "s21_ceil");
    ck_assert_msg(s21_ceil(-21.91) == ceil(-21.91), "s21_ceil");
}
END_TEST

// s21_fabs
START_TEST(test_s21_fabs) {
    ck_assert_msg(s21_fabs(0.000001) == fabs(0.000001), "s21_fabs");
    ck_assert_msg(s21_fabs(-21.000345) == fabs(-21.000345), "s21_fabs");
    ck_assert_msg(s21_fabs(-2147483600.543) == fabs(-2147483600.543), "s21_fabs");
    ck_assert_msg(s21_fabs(2147483600.4857) == fabs(2147483600.4857), "s21_fabs");
}
END_TEST

// s21_floor
START_TEST(test_s21_floor) {
    //   printf("======== %lf\n", s21_floor(0.0));
    // printf("======== %lf\n", floor(0.0));
    // ck_assert_msg(s21_floor(0.0) == floor(0.0), "s21_floor");
    // printf("======== %lf\n", s21_floor(0.0));
    // printf("======== %lf\n", floor(0.0));
    char c[255] = {};
    char d[255] = {};
    long double x = s21_floor(NAN);
    long double y = floor(NAN);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    ck_assert_msg(s21_floor(21.21) == floor(21.21), "s21_floor");
    ck_assert_msg(s21_floor(21.91) == floor(21.91), "s21_floor");
    ck_assert_msg(s21_floor(-21.21) == floor(-21.21), "s21_floor");
    ck_assert_msg(s21_floor(-21.91) == floor(-21.91), "s21_floor");
}
END_TEST

// s21_fmod
START_TEST(test_s21_fmod) {
    ck_assert_msg(s21_fmod(21.21, 3) == fmod(21.21, 3), "s21_fmod");
    ck_assert_msg(s21_fmod(3, 21.21) == fmod(3, 21.21), "s21_fmod");
    ck_assert_msg(s21_fmod(-21.21, 3) == fmod(-21.21, 3), "s21_fmod");
    ck_assert_msg(s21_fmod(3, -21.21) == fmod(3, -21.21), "s21_fmod");
    ck_assert_msg(s21_fmod(100500, 9) == fmod(100500, 9), "s21_fmod");
    ck_assert_msg(s21_fmod(-100500, -9) == fmod(-100500, -9), "s21_fmod");
    ck_assert_msg(s21_fmod(-9, -100500) == fmod(-9, -100500), "s21_fmod");
    ck_assert_msg(s21_fmod(-9, -9) == fmod(-9, -9), "s21_fmod");
    ck_assert_msg(s21_fmod(10, 5) == fmod(10, 5), "s21_fmod");
}
END_TEST

// s21_sin
START_TEST(test_s21_sin) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_sin(0.0);
    long double y;
    y = sin(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 6);  // sin 30
    y = sin(M_PI / 6);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 4);  // sin 45
    y = sin(M_PI / 4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 3);  // sin 60
    y = sin(M_PI / 3);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 2);  // sin 90
    y = sin(M_PI / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(sqrt((3 * M_PI) / 2));  // sin 270
    y = sin(sqrt((3 * M_PI) / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(2 * M_PI);  // sin 360
    y = sin(2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(-2 * M_PI);  // sin 360
    y = sin(-2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(-3 * M_PI);  // sin 360
    y = sin(-3 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(174.532925199433);  // sin 10000
    y = sin(174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(-174.532925199433);  // sin 10000
    y = sin(-174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_cos
START_TEST(test_s21_cos) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_cos(0.0);
    long double y;
    y = cos(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 6);  // sin 30
    y = cos(M_PI / 6);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 4);  // sin 45
    y = cos(M_PI / 4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 3);  // sin 60
    y = cos(M_PI / 3);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 2);  // sin 90
    y = cos(M_PI / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(sqrt((3 * M_PI) / 2));  // sin 270
    y = cos(sqrt((3 * M_PI) / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(2 * M_PI);  // sin 360
    y = cos(2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(174.532925199433);  // sin 10000
    y = cos(174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(-174.532925199433);  // sin 10000
    y = cos(-174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_tan
START_TEST(test_s21_tan) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_tan(0.0);
    long double y;
    y = tan(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI / 6);  // sin 30
    y = tan(M_PI / 6);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI / 4);  // sin 45
    y = tan(M_PI / 4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI);
    y = tan(M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(-2 * M_PI);
    y = tan(-2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI / 3);  // sin 60
    y = tan(M_PI / 3);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(sqrt((3 * M_PI) / 2));  // sin 270
    y = tan(sqrt((3 * M_PI) / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(174.532925199433);  // sin 10000
    y = tan(174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(-174.532925199433);  // sin 10000
    y = tan(-174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST
// START_TEST(pow_test_1) {
//     for (double k = -9; k <= 9; k += 1.7) {
//         for (double g = -5; g < 5; g +=1) {
//             long double a = s21_pow(k, g);
//             long double b = pow(k, g);
//             if ((!isnan(a) && !isnan(b)) \
//             && !(a == INFINITY && b == INFINITY) \
//             && !(a == -INFINITY && b == -INFINITY)) {
//                 ck_assert_double_eq_tol(a, b, 1e-6);
//             }
//             a = s21_pow(g, k);
//             b = pow(g, k);
//             if ((!isnan(a) && !isnan(b)) \
//             && !(a == INFINITY && b == INFINITY) \
//             && !(a == -INFINITY && b == -INFINITY)) {
//                 ck_assert_double_eq_tol(a, b, 1e-6);
//             }
//         }
//     }
// }
// END_TEST

// START_TEST(pow_test_2) {
//     for (double k = -1e-1; k <= 1; k += 1.1e-1) {
//         for (double g = -2.55; g < 2; g +=1.1) {
//             long double a = s21_pow(k, g);
//             long double b = pow(k, g);
//             if ((!isnan(a) && !isnan(b)) \
//             && !(a == INFINITY && b == INFINITY) \
//             && !(a == -INFINITY && b == -INFINITY)) {
//                 ck_assert_double_eq_tol(a, b, 1e-6);
//             }
//             a = s21_pow(g, k);
//             b = pow(g, k);
//             if ((!isnan(a) && !isnan(b)) \
//             && !(a == INFINITY && b == INFINITY) \
//             && !(a == -INFINITY && b == -INFINITY)) {
//                 ck_assert_double_eq_tol(a, b, 1e-6);
//             }
//         }
//     }
// }
// END_TEST

START_TEST(pow_test_3) {
    ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
    ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
    ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
    ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
    ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
    ck_assert_double_eq(pow(INFINITY, 0), s21_pow(S21_INF, 0));
    ck_assert_double_eq(pow(INFINITY, -1), s21_pow(S21_INF, -1));
    ck_assert_double_eq(pow(-1, -INFINITY), s21_pow(-1, -S21_INF));
    ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, S21_INF));
    ck_assert_double_nan(s21_pow(0, S21_NAN));
    ck_assert_double_eq(pow(NAN, 0), s21_pow(S21_NAN, 0));
    ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
    ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(S21_INF, S21_INF));
    ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(S21_INF, -S21_INF));
    ck_assert_double_eq(pow(-INFINITY, INFINITY), s21_pow(-S21_INF, S21_INF));
    ck_assert_double_eq(pow(-INFINITY, -INFINITY), s21_pow(-S21_INF, -S21_INF));
    ck_assert_double_eq(pow(1, -INFINITY), s21_pow(1, -S21_INF));
    ck_assert_double_eq(pow(1, NAN), s21_pow(1, S21_NAN));
    ck_assert_double_nan(s21_pow(S21_NAN, S21_INF));
    ck_assert_double_nan(s21_pow(S21_INF, S21_NAN));
    ck_assert_double_nan(s21_pow(S21_NAN, -S21_INF));
    ck_assert_double_nan(s21_pow(-S21_INF, S21_NAN));
    ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, S21_INF));
    ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, S21_INF));
    ck_assert_double_eq(pow(-2, INFINITY), s21_pow(-2, S21_INF));
    ck_assert_double_eq(pow(2, -INFINITY), s21_pow(2, -S21_INF));
    ck_assert_double_eq(pow(0.5, -INFINITY), s21_pow(0.5, -S21_INF));
    ck_assert_double_eq(pow(-2, -INFINITY), s21_pow(-2, -S21_INF));
}
END_TEST

START_TEST(log_test_1) {
    for (double k = 1; k < 100; k += 13.2) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(log_test_2) {
    for (double k = 0.1; k < 4; k += 0.24) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(log_test_3) {
    for (double k = 0.1; k < 10000; k += 123) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(log_test_4) {
    for (double k = 0.000005; k < 1; k *= 5) {
        double a = s21_log(k);
        double b = log(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(log_test_5) {
    double x = 0.0;
    ck_assert_double_nan(s21_log(S21_NAN));
    ck_assert_double_eq(log(x), s21_log(x));
    ck_assert_double_nan(s21_log(-3));
    ck_assert_double_eq(log(INFINITY), s21_log(S21_INF));
    ck_assert_double_nan(s21_log(-S21_INF));
    ck_assert_double_eq(log(1), s21_log(1));
    ck_assert_double_eq_tol(log(2), s21_log(2), 1e-6);
}
END_TEST

START_TEST(sin_test_1) {
    for (int R = 20; R >= -20; R -= 4) {
        for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
            ck_assert_double_eq_tol(sin(k + R * S21_PI), s21_sin(k + R * S21_PI), 1e-6);
        }
    }
}
END_TEST

START_TEST(cos_test_1) {
    for (int R = 20; R >= -20; R -= 4) {
        for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
            ck_assert_double_eq_tol(cos(k + R * S21_PI), s21_cos(k + R * S21_PI), 1e-6);
        }
    }
}
END_TEST

START_TEST(tan_test_1) {
    for (int R = 20; R >= -20; R -= 4) {
        for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 9) {
            ck_assert_double_eq_tol(tan(k + R * S21_PI), s21_tan(k + R * S21_PI), 1e-6);
        }
    }
}
END_TEST

START_TEST(sin_cos_tan_test) {
    ck_assert_double_nan(s21_sin(S21_NAN));
    ck_assert_double_nan(s21_cos(S21_NAN));
    ck_assert_double_nan(s21_tan(S21_NAN));
    ck_assert_double_nan(s21_sin(S21_INF));
    ck_assert_double_nan(s21_cos(S21_INF));
    ck_assert_double_nan(s21_tan(S21_INF));
    ck_assert_double_nan(s21_sin(-S21_INF));
    ck_assert_double_nan(s21_cos(-S21_INF));
    ck_assert_double_nan(s21_tan(-S21_INF));
}
END_TEST

START_TEST(exp_test_1) {
    for (double k = -21; k < 21; k += 1) {
        double a = s21_exp(k);
        double b = exp(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(exp_test_2) {
    for (double k = -15; k < 15; k += 0.123) {
        double a = s21_exp(k);
        double b = exp(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(exp_test_3) {
    for (double k = -5; k < 5; k += 0.00573) {
        double a = s21_exp(k);
        double b = exp(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(exp_test_4) {
    ck_assert_double_nan(s21_exp(S21_NAN));
    ck_assert_double_eq(exp(INFINITY), s21_exp(S21_INF));
    ck_assert_double_eq(exp(-INFINITY), s21_exp(-S21_INF));
    ck_assert_double_eq(exp(0), s21_exp(0));
    ck_assert_double_eq(exp(1), s21_exp(1));
}
END_TEST

START_TEST(asin_test_1) {
    for (float k = -1; k <= 1; k += 0.1) {
        double a = s21_asin(k);
        double b = asin(k);
        ck_assert_double_eq_tol(a, b, 1e-7);
    }
    ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-7);
}
END_TEST

START_TEST(asin_test_2) {
    for (float k = -1; k <= 1; k += 0.0771) {
        double a = s21_asin(k);
        double b = asin(k);
        ck_assert_double_eq_tol(a, b, 1e-7);
    }
}
END_TEST

START_TEST(acos_test_1) {
    for (float k = -1; k <= 1; k += 0.1) {
        double a = s21_acos(k);
        double b = acos(k);
        ck_assert_double_eq_tol(a, b, 1e-7);
    }
}
END_TEST

START_TEST(acos_test_2) {
    for (float k = -1; k <= 1; k += 0.0305) {
        double a = s21_acos(k);
        double b = acos(k);
        ck_assert_double_eq_tol(a, b, 1e-7);
    }
}
END_TEST

START_TEST(atan_test_1) {
    for (float k = -10; k <= 10; k += 4) {
        double a = s21_atan(k);
        double b = atan(k);
        ck_assert_double_eq_tol(a, b, 1e-7);
    }
}
END_TEST

START_TEST(sqrt_test_1) {
    for (double k = 0; k < 21; k += 3) {
        double a = s21_sqrt(k);
        double b = sqrt(k);
        ck_assert_double_eq_tol(a, b, 1e-6);
    }
}
END_TEST

START_TEST(sqrt_test_2) {
    ck_assert_double_nan(s21_sqrt(S21_NAN));
    ck_assert_double_nan(sqrt(NAN));
    ck_assert_double_eq(s21_sqrt(S21_INF), sqrt(INFINITY));
    ck_assert_double_nan(s21_sqrt(-S21_INF));
    ck_assert_double_nan(sqrt(-INFINITY));
    ck_assert_double_nan(s21_sqrt(-5));
    ck_assert_double_nan(sqrt(-5));
    ck_assert_double_eq_tol(s21_sqrt(1000), sqrt(1000), 1e-7);
}
END_TEST

START_TEST(atan_test_2) {
    double a = 12;
    ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
    a = 0.4;
    ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
    a = -0.333;
    ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
    a = 55;
    ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
    a = 13.54;
    ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
}
END_TEST

START_TEST(asin_acos_atan_test) {
    ck_assert_double_nan(s21_asin(S21_NAN));
    ck_assert_double_nan(s21_acos(S21_NAN));
    ck_assert_double_nan(s21_atan(S21_NAN));
    ck_assert_double_nan(s21_asin(S21_INF));
    ck_assert_double_nan(s21_acos(S21_INF));
    ck_assert_double_eq(atan(INFINITY), s21_atan(S21_INF));
    ck_assert_double_nan(s21_asin(-S21_INF));
    ck_assert_double_nan(s21_acos(-S21_INF));
    ck_assert_double_eq(atan(-INFINITY), atan(-S21_INF));
    ck_assert_double_nan(s21_asin(5));
    ck_assert_double_nan(s21_acos(6));
    ck_assert_double_nan(s21_asin(-8));
    ck_assert_double_nan(s21_acos(-4));
}
END_TEST

START_TEST(abs_test) {
    ck_assert_double_eq(abs(-7), s21_abs(-7));
    ck_assert_double_eq(abs(-98), s21_abs(-98));
    ck_assert_double_eq(abs(123), s21_abs(123));
    ck_assert_double_eq(abs(10009), s21_abs(10009));
    ck_assert_double_eq(abs(-10009), s21_abs(-10009));
}
END_TEST

START_TEST(fabs_test) {
    ck_assert_double_eq(fabs(INFINITY), s21_fabs(S21_INF));
    ck_assert_double_eq(fabs(-INFINITY), s21_fabs(-S21_INF));
    ck_assert_double_nan(fabs(NAN));
    ck_assert_double_nan(s21_fabs(S21_NAN));
    ck_assert_double_eq(fabs(-7.0), s21_fabs(-7.0));
    ck_assert_double_eq(fabs(-98.1), s21_fabs(-98.1));
    ck_assert_double_eq(fabs(123.02), s21_fabs(123.02));
    ck_assert_double_eq(fabs(10009.0), s21_fabs(10009.0));
    ck_assert_double_eq(fabs(-10009.555), s21_fabs(-10009.555));
    ck_assert_double_eq(fabs(-0.10009), s21_fabs(-0.10009));
    ck_assert_double_eq(fabs(-1e23), s21_fabs(-1e23));
}
END_TEST

START_TEST(floor_test) {
    ck_assert_double_eq(floor(INFINITY), s21_floor(S21_INF));
    ck_assert_double_eq(floor(-INFINITY), s21_floor(-S21_INF));
    ck_assert_double_nan(floor(NAN));
    ck_assert_double_nan(s21_floor(S21_NAN));
    ck_assert_double_eq(floor(-7.0), s21_floor(-7.0));
    ck_assert_double_eq(floor(-98.1), s21_floor(-98.1));
    ck_assert_double_eq(floor(123.02), s21_floor(123.02));
    ck_assert_double_eq(floor(10009.00123), s21_floor(10009.00123));
    ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
    ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
    ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
    ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
}
END_TEST

START_TEST(ceil_test) {
    ck_assert_double_eq(ceil(INFINITY), s21_ceil(S21_INF));
    ck_assert_double_eq(ceil(-INFINITY), s21_ceil(-S21_INF));
    ck_assert_double_nan(ceil(NAN));
    ck_assert_double_nan(s21_ceil(S21_NAN));
    ck_assert_double_eq(ceil(-7.0), s21_ceil(-7.0));
    ck_assert_double_eq(ceil(-98.1), s21_ceil(-98.1));
    ck_assert_double_eq(ceil(123.02), s21_ceil(123.02));
    ck_assert_double_eq(ceil(10009.00123), s21_ceil(10009.00123));
    ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
    ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
    ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23));
}
END_TEST

START_TEST(fmod_test_1) {
    ck_assert_double_nan(fmod(1, 0));
    ck_assert_double_nan(s21_fmod(1, 0));
    ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
    ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
    ck_assert_double_nan(fmod(INFINITY, -1));
    ck_assert_double_nan(s21_fmod(INFINITY, -1));
    ck_assert_double_eq(fmod(-1, -INFINITY), s21_fmod(-1, -S21_INF));
    ck_assert_double_eq(fmod(0, INFINITY), s21_fmod(0, S21_INF));
    ck_assert_double_nan(s21_fmod(0, S21_NAN));
    ck_assert_double_nan(fmod(0, NAN));
    ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
    ck_assert_double_nan(fmod(NAN, NAN));
    ck_assert_double_nan(s21_fmod(S21_NAN, S21_INF));
    ck_assert_double_nan(s21_fmod(S21_INF, S21_NAN));
    ck_assert_double_nan(s21_fmod(S21_NAN, -S21_INF));
    ck_assert_double_nan(s21_fmod(-S21_INF, S21_NAN));
    ck_assert_double_nan(fmod(NAN, INFINITY));
    ck_assert_double_nan(fmod(INFINITY, NAN));
    ck_assert_double_nan(fmod(NAN, -INFINITY));
    ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(fmod_test_2) {
    for (double a = -1500; a < 1500; a += 123) {
        for (double b = -12; b < 12; b += 1.25) {
        ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
        ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
        }
    }
}
END_TEST


Suite *s21_math_suite(void) {
    Suite *suite;

    suite = suite_create("s21_math");
    TCase *tcase_core = tcase_create("test");

    // tcase_add_test(tcase_core, pow_test_1);
    // tcase_add_test(tcase_core, pow_test_2);
    tcase_add_test(tcase_core, absTest);
    tcase_add_test(tcase_core, fabsTest);
    tcase_add_test(tcase_core, ceilTest);
    tcase_add_test(tcase_core, floorTest);
    tcase_add_test(tcase_core, asinTest);
    tcase_add_test(tcase_core, acosTest);
    tcase_add_test(tcase_core, sqrtTest);
    tcase_add_test(tcase_core, atanTest);
    tcase_add_test(tcase_core, sinTest);
    tcase_add_test(tcase_core, cosTest);
    tcase_add_test(tcase_core, tanTest);
    tcase_add_test(tcase_core, expTest);
    tcase_add_test(tcase_core, logTest);
    tcase_add_test(tcase_core, powTest);
    tcase_add_test(tcase_core, fmodTest);
    tcase_add_test(tcase_core, test_s21_tan);
    tcase_add_test(tcase_core, test_s21_cos);
    tcase_add_test(tcase_core, test_s21_sin);
    tcase_add_test(tcase_core, test_s21_fmod);
    tcase_add_test(tcase_core, test_s21_floor);
    tcase_add_test(tcase_core, test_s21_fabs);
    tcase_add_test(tcase_core, test_s21_ceil);
    tcase_add_test(tcase_core, test_s21_abs);
    tcase_add_test(tcase_core, pow_test_3);
    tcase_add_test(tcase_core, log_test_1);
    tcase_add_test(tcase_core, log_test_2);
    tcase_add_test(tcase_core, log_test_3);
    tcase_add_test(tcase_core, log_test_4);
    tcase_add_test(tcase_core, log_test_5);
    tcase_add_test(tcase_core, sin_test_1);
    tcase_add_test(tcase_core, cos_test_1);
    tcase_add_test(tcase_core, tan_test_1);
    tcase_add_test(tcase_core, sin_cos_tan_test);
    tcase_add_test(tcase_core, exp_test_1);
    tcase_add_test(tcase_core, exp_test_2);
    tcase_add_test(tcase_core, exp_test_3);
    tcase_add_test(tcase_core, exp_test_4);
    tcase_add_test(tcase_core, asin_test_1);
    tcase_add_test(tcase_core, asin_test_2);
    tcase_add_test(tcase_core, acos_test_1);
    tcase_add_test(tcase_core, acos_test_2);
    tcase_add_test(tcase_core, atan_test_1);
    tcase_add_test(tcase_core, atan_test_2);
    tcase_add_test(tcase_core, asin_acos_atan_test);
    tcase_add_test(tcase_core, sqrt_test_1);
    tcase_add_test(tcase_core, sqrt_test_2);
    tcase_add_test(tcase_core, abs_test);
    tcase_add_test(tcase_core, fabs_test);
    tcase_add_test(tcase_core, floor_test);
    tcase_add_test(tcase_core, ceil_test);
    tcase_add_test(tcase_core, fmod_test_1);
    tcase_add_test(tcase_core, fmod_test_2);

    suite_add_tcase(suite, tcase_core);

    return suite;
}

int main(void) {
    Suite *suite = s21_math_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_VERBOSE);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
