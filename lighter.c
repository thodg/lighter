#include <stdio.h>
#include <string.h>
#include "../fb/fb.h"
#include "easy.h"

unsigned g_loop = 1;

void quit () {
  g_loop = 0;
}

s_kb_event g_kb[] = {
  {"\x3", quit},
  {"q", quit},
  {"", 0}
};

static void kb_events () {
  unsigned k;
  while ((k = kb_poll())) {
    s_kb_event *e;
    kb_in(k);
    e = kb_handler();
    if (e)
      e->fun();
  }
}

/*
e43 *g_model;

e3 model (e3 a)
{
  return e43_e3(g_model, a);
}

e3 model_e3 (easy x, easy y, easy z)
{
  return model(xyz(x, y, z));
}

typedef struct ray {
  e3 o;
  e3 d;
} s_ray;

e3 ray_point (s_ray *r, easy l)
{
  return xyz_add(r->o, xyz_s(r->d, l));
}

typedef struct checker {
  e3 o;
  e3 u;
  e3 v;
  e3 n;
} s_checker;

e3 checker_point (s_checker *c, long u, long v)
{
  return xyz_add(c->o, xyz_add(xyz_s(c->u, u),
                               xyz_s(c->v, v)));
}

s_rgba checker_color (s_checker *c, e3 i)
{
  e3 ci = xyz_sub(i, c->o);
  long u = xyz_along(ci, c->u) U;
  long v = xyz_along(ci, c->v) U;
  if ((u + v) % 2)
    return (s_rgba) {255, 255, 255, 255};
  return (s_rgba) {80, 80, 80, 255};
}
*/
/*
  (rox + l rdx - cox) * nx + (roy + l rdy - coy) ny + (roz + l rdz - coz) nz = 0;
  l rdx nx + (rox - cox) nx + l rdy ny + (roy - coy) ny + l rdz nz + (roz - coz) nz = 0;
  l (rdx nx + rdy ny + rdz nz) + (rox - cox) nx + (roy - coy) ny + (roz - coz) nz = 0;
  l = ((cox - rox) nx + (coy - roy) ny + (coz - roz) nz) / (rdx nx + rdy ny + rdz nz);
  l = (co - ro).n / rd.n;
  p = ro + (co - ro).n / rd.n * rd;
  rc = co - ro;
  p = ro + rc.n * rd / rd.n;
*/
/*
s_rgba ray_checker (s_ray *r, s_checker *c)
{
  easy rdn = xyz_dot_product(r->d, c->n);
  if (rdn) {
    e3 rc = xyz_sub(c->o, r->o);
    easy rcn = xyz_dot_product(rc, c->n);
    e3 i = { r->o.x + rcn * r->d.x / rdn,
                r->o.y + rcn * r->d.y / rdn,
                r->o.z + rcn * r->d.z / rdn };
    s_rgba ic = checker_color(c, i);
    return ic;
  }
  return (s_rgba) {32, 0, 0, 0};
}

long g_depth = 2;

s_ray fb_ray (struct fb *fb, unsigned long x, unsigned long y)
{
  easy w2 = fb->w / 2 * A;
  easy h2 = fb->h / 2 * A;
  easy z = g_depth * fb->w * A;
  return (s_ray) {
    .o = { w2,
           h2,
           -z },
    .d = { x * A - w2,
           y * A - h2,
           z }
  };
}

static void checker_scene (struct fb *fb)
{
  static s_m43 checker_model;
  unsigned long x;
  unsigned long y;
  fb_clear(fb);
  g_model = &checker_model;
  m43_identity(g_model);
  m43_scale(g_model, xyz(3 * A, A, A));
  m43_rotate(g_model, xyz(0, 0, A), A / 3);
  {
    s_checker c = { .o = model_xyz(0, 0, 0),
                    .u = model_xyz(10 * A, 0, 0),
                    .v = model_xyz(0, 10 * A, 0),
                    .n = model_xyz(0, 0, 10 * A) };
    for (y = 0; y < fb->h; y++) {
      for (x = 0; x < fb->w; x++) {
        s_rgba *p = fb->buffer + fb_pixel(fb, x, y);
        s_ray r = fb_ray(fb, x, y);
        *p = ray_checker(&r, &c);
      }
    }
  }
}
*/

static void tangent_scene (struct fb *fb)
{
  unsigned long x;
  relative x_scale = SUP_ANGLE / fb->w;
  relative y_scale = SUP_EASY / (fb->h / 2);
  /*  static e43 tangent_model;
  g_model = &tangent_model;
  e43_identity(g_model); */
  fb_clear(fb);
  fb_move_to(fb, (s_xy){0, fb->h / 2});
  for (x = 0; x < fb->w; x++) {
    unsigned long y = fb->h / 2 + e_tangent(x * x_scale) / y_scale;
    fb_line_to(fb, (s_xy){x, y});
  }
}

static void draw (struct fb *fb)
{
  tangent_scene(fb);
  fb_swap(fb);
}

#define BUFFER_SIZE (1400 * 1050 * 5)

int main ()
{
  struct fb fb;
  s_rgba back[BUFFER_SIZE / 4];
  if (fb_open(&fb, "/dev/fb0", back, BUFFER_SIZE))
    return 1;
  while (g_loop) {
    draw(&fb);
    kb_events();
  }
  fb_close(&fb);
  return 0;
}
