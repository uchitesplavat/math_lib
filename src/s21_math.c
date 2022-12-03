#include "s21_math.h"

long double s21_acos(double x) {
  long double y;
  if (x != x || x > 1.0 || x < -1.0) {
    y = S21_NAN;
  } else if (x == 1) {
    y = 0;
  } else if (x == -1) {
    y = S21_PI;
  } else {
    y = S21_PI_2 - s21_asin(x);
  }
  return y;
}

long double s21_asin(double x) {
    long double result = 1.0;
    if ((!(x >= 0) && !(x < 0)) || (x == S21_INF) || (x == -S21_INF)) {
        result = S21_NAN;
    } else {
        if (x > 1 || x < -1) {
            result = -S21_NAN;
        } else {
            double x0 = -S21_PI_2;
            double x1 = S21_PI_2;
            while (s21_fabs(s21_sin(result) - x) > PRECISION) {
                result = (x0 + x1) / 2;
                if ((s21_sin(result) - x) <= 0.0) {
                    x0 = result;
                } else {
                    x1 = result;
                }
            }
        }
    }
    return result;
}

int s21_abs(int x) {
        int temp = x;
    if ((x > 0 && x < 1) || (x < 0 && x > -1)) {
        temp = (long double)x;
    }
        return temp < 0 ? -temp : temp;
}

long double s21_ceil(double x) {
    double temp;
    if ((!(x >= 0) && !(x < 0))) {
        temp = x;
    } else if (x == S21_INF) {
        temp = S21_INF;
    } else if (x == -S21_INF) {
        temp = -S21_INF;
    } else if ((x > 0 && x < 1) || (x < 0 && x > -1)) {
        temp = (long long int)x;
    } else {
        x = (long long int)x;
        temp = x <= 0 ? x : ++x;
    }
    return temp;
}

long double s21_fabs(double x) {
    return x < 0 ? -x : x;
}

long double s21_floor(double x) {
    return s21_floor_ceil(x, 0, 1);
}

static long double s21_floor_ceil(double x, int c, int f) {
    double r = x;
    if (x != S21_INF && x != -S21_INF) {
        if (x > 1e6) {
            long double e = 1e308;
            for (int k = 308; k > 5; k--) {
                while (x > e) {
                    x -= e;
                }
                e /= 10;
            }
        }
        if ((int)x != x) {
            if (x > 0) r += (int)x - x + c;
            else
                r += (int)x - x - f;
        }
    }
    return r;
}

long double s21_fmod(double x, double y) {
    double result = S21_NAN;
    if (s21_isinf(x)) {
    } else if (s21_isinf(y)) {
        result = x;
    } else {
        int znak = 1;
        if (x < 0) {
            znak = -1;
            x *= -1;
        }
        y = s21_fabs(y);
        if (y != 0) result = (x - s21_floor(x / y) * y) * znak;
    }
    return result;
}

long double s21_sin(double x) {
    long double sin;
    int flag = 0;
    if (x == 2 * S21_PI) {
        sin = -1 * PRECISION;
        flag = 1;
    }
    int i = 1;
    long double acc = 1;
    long double fact = 1;
    long double pow;
    x = s21_fmod(x, 2 * S21_PI);
    sin = x;
    pow = x;
    while (s21_fabs(acc) > PRECISION) {
        fact *= ((2*i)*(2*i+1));
        pow *= -1 * x * x;
        acc =  pow / fact;
        sin += acc;
        i++;
    }
    if (s21_fmod(x, 2 * S21_PI) == 0 && x > 0.00) {
        sin = -1 * PRECISION;
    } else if (s21_fmod(x, 2 * S21_PI) == 0 && x < 0.00) {
        sin = PRECISION;
    }
    return flag != 1 ? sin : (-1 * PRECISION);
}

long double s21_cos(double x) {
    return s21_sin((S21_PI / 2) - x);
}

long double s21_tan(double x) {
    x = s21_fmod(x, 2 * S21_PI);
    return s21_sin(x) / s21_cos(x);

    // if ()
    // return s21_fmod(x, 2 * S21_PI) == 0 ? -1 * s21_sin(x) /
    // s21_cos(x) : s21_sin(x) / s21_cos(x);
}

long double s21_sqrt(double x) {
    long double result;
    long double sqrt = x / 2;
    long double temp = 0;
    if (x == S21_INF) {
            result = S21_INF;
    } else if (x >= 0) {
        while (sqrt != temp) {
            temp = sqrt;
            sqrt = (x/temp + temp) / 2;
        }
            result = sqrt;
    } else {
        result = S21_NAN;
    }
    return result;
}

long double s21_exp(double x) {
    if (!(x >= 0) && !(x < 0)) return S21_NAN;
    if ((x == S21_INF) || (x == -S21_INF)) return x < 0 ? 0 : S21_INF;
    long double d = 1;
    long double result = 1;
    if (x == S21_INF) {
        result = x;
        return result;
    } else {
        for (int i = 1; d >= PRECISION; ++i) {
            d *= s21_fabs(x) / i;
            result += d;
        }
    }
    return x < 0 ? 1/result : result;
}

long double s21_pow(double x, double n) {
    long double result = 1;
    int z = 1;
    if (check_input(&x, n, &z, &result)) {
        int z = 1;
        if (s21_ceil(n) == n) {
            if (n < 0) {
                n *= -1;
                z = -1;
            }
            for (int k = 0; k < n; k++) result *= x;
        } else {
            result = not_int(x, n, &z, &z, result);
        }
        if (z == -1) result = 1 / result;
    }
    return result * z;
}

static long double not_int(double x, double n, int *z_n, int *z_x, long double result) {
    int n_big = 1;
    long double a = 1;
    if (x < 0) {
        x *= -1;
        if (s21_floor(n / 2) != n / 2) *z_x = -1;
    }
    if (x > 2) {
        long double pow_2_n = s21_pow(2, n);
        while (x > 2) {
            result *= pow_2_n;
            x /= 2;
        }
        if (!s21_isinf(result)) result *= s21_pow(x, n);
    } else if (x < 1) {
        long double pow_2_n = s21_pow(2, n);
        while (x < 1) {
            result /= pow_2_n;
            x *= 2;
        }
        if (!s21_isinf(result)) result *= s21_pow(x, n);
    } else {
        a = 1;
        x -= 1;
        if (n < 0) {
            n *= -1;
            *z_n = -1;
        }
        if (n < 1 && n > 0) {
            n += 1;
            n_big = 0;
        }
        long double mnoj = (n * x) * result / a;
        result += mnoj;
        long double buff = 0;
        for (int k = 2; k < 1e7; k++) {
            mnoj *= (x * (n - k + 1)) / (k * a);
            result += mnoj;
            if (result == buff) break;
            buff = result;
        }
    }
    if (n_big == 0) result /= x + a;
    return result;
}

int s21_isnan(double x) {
    int result = 0;
    if (!(x >= 0) && !(x < 0)) result = 1;
    return result;
}

int s21_isinf(double x) {
    int result = 0;
    if (x == S21_INF || x == -S21_INF) result = 1;
    return result;
}

static int check_input(double *x, double n, int *z, long double *result) {
    int res = 0;
    if (n == 0 || *x == 1) {
        *result = 1;
    } else if (s21_isnan(n)) {
        *result = S21_NAN;
    } else if (*x == -1) {
        if (s21_ceil(n / 2) == n / 2) *result = 1;
        else
            *result = -1;
    } else if (*x == 0) {
        if (n < 0) *result = S21_INF;
        else
            *result = 0;
    } else if (s21_isnan(*x)) {
        *result = S21_NAN;
    } else if (*x == S21_INF) {
        if (n > 0) *result = S21_INF;
        else
            *result = 0;
    } else if (*x == -S21_INF) {
        if (n < 0) *result = 0;
        else if (s21_ceil(n / 2) == n / 2) *result = S21_INF;
        else
            *result = -S21_INF;
    } else if (n == S21_INF) {
        if (*x > 1) *result = n;
        else if (*x < 1 && *x > -1) *result = 0;
        else if (*x < -1 && s21_ceil(n / 2) != n / 2) *result = -S21_INF;
        else
            *result = S21_INF;
    } else if (n == -S21_INF) {
        if (*x > 1 || *x < -1) *result = 0;
        else if (*x < 0) *result = -S21_INF;
        else
            *result = S21_INF;
    } else if (n == 1) {
        if (*x < 0) {
            *z = -1;
            *x = -1 * (*x);
        }
        *result = *x;
    } else if (n == -1) {
        if (*x < 0) {
            *z = -1;
            *x = -1 * (*x);
        }
        *result = 1 / (*x);
    } else if (*x < 0 && s21_floor(n) != n) {
        *result = -S21_NAN;
    } else {
        res = 1;
    }
    return res;
}


long double s21_log(double x) {
    long double result;
    if (x < 0) {
        result = -S21_NAN;
    } else if (s21_isnan(x) || s21_isinf(x)) {
        result = x;
    } else if (x == 0) {
        result = -S21_INF;
    } else if (x == 2) {
        result = S21_LN2;
    } else {
        int exp = 0;
        while (x > 2) {
            x /= 2;
            exp++;
        }
        while (x < 1) {
            x *= 2;
            exp--;
        }
        x--;
        result = x;
        double m = x;
        long int k = 2;
        while (s21_fabs(m / k) > 2e-7) {
            m *= (-1) * (x);
            result += m / k;
            k++;
        }
        result += exp * S21_LN2;
    }
    return result;
}

long double s21_atan(double x) {
    long double result;
    if (x == S21_INF) result = S21_PI / 2;
    else if (x == -S21_INF) result = -S21_PI / 2;
    else
        result = s21_asin(x / s21_pow(x * x + 1, 0.5));
    return result;
}
