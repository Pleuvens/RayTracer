#include "rt.h"

struct vector3 *normalize(float x, float y, float z)
{
  struct vector3 *norm = malloc(sizeof (struct vector3));
  if (!norm)
    return NULL;
  float div = sqrt(x * x + y * y + z * z);
  norm->x = x / div;
  norm->y = y / div;
  norm->z = z / div;
  return norm;
}

struct vector3 *cross_product(struct vector3 u, struct vector3 v)
{
  struct vector3 *prod = malloc(sizeof (struct vector3));
  if (!norm)
    return NULL;

  prod->x = u->y * v->z - u->z * v->y;
  prod->y = u->z * v->x - u->x * v->z;
  prod->z = u->x * v->y - y->y * v->x;
  return prod;
}
