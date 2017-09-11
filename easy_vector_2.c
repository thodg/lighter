#include "easy.h"

easy e2_dot_product (e2 a, e2 b)
{
  return a.x EASY_TIMES b.x + a.y EASY_TIMES b.y;
}

e2 e2_add (e2 a, e2 b)
{
  return E2(a.x + b.x, a.y + b.y);
}

e2 e2_subtract (e2 a, e2 b)
{
  return E2(a.x - b.x, a.y - b.y);
}
