#include "rt.h"

struct color color_clamp(struct color c)
{
  if (c.r > 1)
    c.r = 1;
  if (c.r < 0)
    c.r =  0;
  if (c.g > 1)
    c.g = 1;
  if (c.g < 0)
    c.g =  0;
  if (c.b > 1)
    c.b = 1;
  if (c.b < 0)
    c.b =  0;
  return c;
}

struct color color_add(struct color c1, struct color c2)
{
  struct color res;
  res.r = c1.r + c2.r;
  res.g = c1.g + c2.g;
  res.b = c1.b + c2.b;
  return color_clamp(res);
}

struct color color_mult(struct color c1, struct color c2)
{
  struct color res;
  res.r = c1.r * c2.r;
  res.g = c1.g * c2.g;
  res.b = c1.b * c2.b;
  return color_clamp(res);
}

struct color color_lambda(float lambda, struct color c1)
{
  struct color res;
  res.r = c1.r * lambda;
  res.g = c1.g * lambda;
  res.b = c1.b * lambda;
  return color_clamp(res);
}

int color_scale(float c)
{
  c *= 255;
  if (c > 255)
    return 255;
  if (c < 0)
    return 0;
  return c;
}
