#include "easy.h"

long e_dot_product_2 (easy *a, easy *b)
{
  return a[0] EASY_TIMES b[0] + a[1] EASY_TIMES b[1];
}

long e_dot_product_3 (easy *a, easy *b)
{
  return a[0] EASY_TIMES b[0] + a[1] EASY_TIMES b[1];
}

s_xyz xyz (s_t x, s_t y, s_t z)
{
  return (s_xyz) { x, y, z };
}

s_xyz xyz_s (s_xyz a, s_t b)
{
  return xyz(a.x * b U, a.y * b U, a.z * b U);
}

s_xyz xyz_add (s_xyz a, s_xyz b)
{
  return xyz(a.x + b.x, a.y + b.y, a.z + b.z);
}

s_xyz xyz_sub (s_xyz a, s_xyz b)
{
  return xyz(a.x - b.x, a.y - b.y, a.z - b.z);
}

s_t xyz_along (s_xyz a, s_xyz b)
{
  if (b.x > b.y && b.x > b.z)
    return a.x * A / b.x;
  if (b.y > b.x && b.y > b.z)
    return a.y * A / b.y;
  return a.z * A / b.z;
}

*/
