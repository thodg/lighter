#include "easy.h"

easy e_absolute_value (easy e)
{
  if (e < 0)
    return -e;
  return e;
}

easy e_squared (easy e)
{
  return e EASY_TIMES e;
}

easy e_squares (easy e1, easy e2)
{
  return e1 EASY_TIMES e1 + e2 EASY_TIMES e2;
}

easy e_inverse (easy e)
{
  return EASY_ONE EASY_BY e;
}
