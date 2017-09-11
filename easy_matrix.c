#include "easy.h"

void e43_identity (e43 *m)
{
  m->n[0] = EASY_ONE; m->n[1] = 0; m->n[ 2] = 0; m->n[ 3] = 0;
  m->n[4] = 0; m->n[5] = EASY_ONE; m->n[ 6] = 0; m->n[ 7] = 0;
  m->n[8] = 0; m->n[9] = 0; m->n[10] = EASY_ONE; m->n[11] = 0;
}

void e43_translate (e43 *m, e3 d)
{
  m->n[ 3] += d.x;
  m->n[ 7] += d.y;
  m->n[11] += d.z;
}

void e43_scale (e43 *m, e3 s)
{
  m->n[ 0] = m->n[ 0] EASY_TIMES s.x;
  m->n[ 5] = m->n[ 5] EASY_TIMES s.y;
  m->n[10] = m->n[10] EASY_TIMES s.z;
}

/*
void e43_rotate (e43 *m, e3 a, s_t b)
{
  (void) a;
  m->n[0] = m->n[0] EASY_TIMES  e_cosinus(b);
  m->n[1] = m->n[5] EASY_TIMES -e_sinus(b);
  m->n[4] = m->n[0] EASY_TIMES  e_sinus(b);
  m->n[5] = m->n[5] EASY_TIMES  e_cosinus(b);
}
*/

e3 e43_e3 (e43 *m, e3 a)
{
  easy *n = m->n;
  return xyz(n[0] EASY_TIMES a.x + n[1] EASY_TIMES a.y +
             n[2] EASY_TIMES a.z + n[3],
             n[4] EASY_TIMES a.x + n[5] EASY_TIMES a.y +
             n[6] EASY_TIMES a.z + n[7],
             n[8] EASY_TIMES a.x + n[9] EASY_TIMES a.y +
             n[10] EASY_TIMES a.z + n[11]);
}
