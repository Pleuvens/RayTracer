#include "rt.h"

struct color color_add(struct color c1, struct color c2)
{
  struct color res;
  res.r = c1.r + c2.r;
  res.g = c1.g + c2.g;
  res.b = c1.b + c2.b;
  return res;
}

struct color color_mult(struct color c1, struct color c2)
{
  struct color res;
  res.r = c1.r * c2.r;
  res.g = c1.g * c2.g;
  res.b = c1.b * c2.b;
  return res;
}

struct color color_lambda(float lambda, struct color c1)
{
  struct color res;
  res.r = c1.r * lambda;
  res.g = c1.g * lambda;
  res.b = c1.b * lambda;
  return res;
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
