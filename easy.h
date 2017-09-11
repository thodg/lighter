#ifndef EASY_H
#define EASY_H

#define SUP(bits) ((1 << bits) - 1)

typedef unsigned long long natural;
#define NATURAL_BITS (sizeof(natural) << 3)
#define SUP_NATURAL (SUP(NATURAL_BITS))

typedef long long relative;
#define RELATIVE_BITS ((sizeof(relative) << 3) - 1)
#define SUP_RELATIVE (SUP(RELATIVE_BITS))

typedef long long easy;
#define EASY_BITS ((sizeof(easy) << 3) - 1)
#define SUP_EASY (SUP(EASY_BITS))

#define EASE 15
#define EASY_ONE (1 << EASE)
#define EASES / easy_one

#define EASY_RELATIVE_BITS (RELATIVE_BITS - EASE)
#define SUP_EASY_RELATIVE (SUP(EASY_RELATIVE_BITS))

#define EASY_TIMES / EASY_ONE *
#define EASY_BY * EASY_ONE /

typedef unsigned long angle;
#define ANGLE_BITS (sizeof(angle) << 3)
#define SUP_ANGLE (SUP(ANGLE_BITS))

easy e_absolute_value (easy e);
easy e_squared (easy e);
easy e_squares (easy e1, easy e2);
easy e_inverse (easy e);
easy e_tangent (angle y);

typedef struct {
  easy x;
  easy y;
} e2;

#define E2(x, y) ((e2){(x),(y)})
easy e2_dot_product (e2 a, e2 b);
e2 e2_add (e2 a, e2 b);
e2 e2_subtract (e2 a, e2 b);

typedef struct {
  easy x;
  easy y;
  easy z;
} e3;

#define E3(x, y, z) ((e3){(x),(y),(z)})
easy e3_dot_product (e3 a, e3 b);
e3 e3_times (e3 a, easy b);
e3 e3_add (e3 a, e3 b);
e3 e3_sub (e3 a, e3 b);
easy e3_along (e3 a, e3 b);

typedef struct
{
  easy n[12];
} e43;

void e43_identity (e43 *m);
void e43_translate (e43 *m, e3 d);
void e43_scale (e43 *m, e3 s);
e3 e43_e3 (e43 *m, e3 a);

#endif /* EASY_H */
