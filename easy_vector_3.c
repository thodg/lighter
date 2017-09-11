#include "easy.h"

easy e3_dot_product (e3 a, e3 b)
{
  return a.x EASY_TIMES b.x + a.y EASY_TIMES b.y + a.z EASY_TIMES b.z;
}

e3 e3_times (e3 a, easy b)
{
  return (a.x EASY_TIMES b, a.y EASY_TIMES b, a.z EASY_TIMES b);
}

e3 e3_add (e3 a, e3 b)
{
  return E3(a.x + b.x, a.y + b.y, a.z + b.z);
}

e3 e3_sub (e3 a, e3 b)
{
  return E3(a.x - b.x, a.y - b.y, a.z - b.z);
}

easy e3_along (e3 a, e3 b)
{
  if (b.x > b.y && b.x > b.z)
    return a.x EASY_BY b.x;
  if (b.y > b.x && b.y > b.z)
    return a.y EASY_BY b.y;
  return a.z EASY_BY b.z;
}
