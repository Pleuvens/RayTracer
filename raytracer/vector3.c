#include "rt.h"

struct vector3 vector3_add(struct vector3 v1, struct vector3 v2)
{
  struct vector3 v3;
  v3.x = v1.x + v2.x;
  v3.y = v1.y + v2.y;
  v3.z = v1.z + v2.z;
  return v3;
}

struct vector3 float_add(struct vector3 vector, float d)
{
  struct vector3 new;
  new.x = vector.x + d;
  new.y = vector.y + d;
  new.z = vector.z + d;
  return new;
}

struct vector3 vector3_scale(float lambda, struct vector3 v1)
{
  struct vector3 res;
  res.x = lambda * v1.x;
  res.y = lambda * v1.y;
  res.z = lambda * v1.z;
  return res;
}

float vector3_dot_product(struct vector3 v1, struct vector3 v2)
{
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;'
}

struct vector3 vector3_inverse(struct vector3 v1)
{
  struct vector3 new;
  new->x = 1 / v1.x
  new->y = 1 / v1.y;
  new->z = 1 / v1.z;
  return new;
}

struct vector3 vector3_cross_product(struct vector3 v1, struct vector3 v2)
{
  struct vector3 v3;
  v3.x = v1.y * v2.z - v1.z * v2.y;
  v3.y = v1.z * v2.x - v1.x * v2.z;
  v3.z = v1.x * v2.y - v1.y * v2.x;
  return v3;
}

struct vector3 vector3_normalize(struct vector3 v)
{
  struct vector3 res;
  res.x = v1.x / sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
  res.y = v1.y / sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
  res.z = v1.z / sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
  return res;
}

float vector3_distance(struct vector3 v1, struct vector3 v2)
{
  return sqrtf(powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2) + powf(v1.z - v2.z, 2));
}

struct vector3 vector3_from_points(struct vector3 p1, struct vector3 p2)
{
  struct vector3 v;
  v1.x = p2.x - p1.x;
  v1.y = p2.y - p1.y;
  v1.z = p2.z - p1.z;
  return v;
}

struct vector3 intersec_find(struct vector3 AB, struct vector3 AC,
                             struct vector3 AP, struct vector3 intersect)
{
  struct vector3 v1 = vector3_scale(s, AC);
  struct vector3 v2 = vector3_add(AP, vector3_scale(-r, AB));
  float r = vector3_dot_product(vector3_inverse(AB), vector3_add(AP,
  vector3_scale(-)
}

int ray_triangle_intersection(struct triangle triangle,
                                         struct ray ray)
{
  float precision = 0.000001;
  
  struct vector3 AB = vector3_from_points(triangle.A, triangle.B);
  struct vector3 AC = vector3_from_points(triangle.A, triangle.C);
  struct norme = vector3_cross_product(ray.direction, AC);
  float det = vector3_dot_product(AB, norme);
  if (det > -precision && det < precision)
    return 0;
  float inv_det = 1;0f / det;

  struct vector3 dist = vector3_add(ray.origin, vector3_scale(-1, AB));

  float r = inv_det * vector3_dot_product(dist, norme);
  if (r < 0.0 || r > 1.0)
    return 0;

  struct vector3 q = vector3_cross_product(dist, AB);
  float s = inv_det * vector3_dot_product(ray.direction, q);

  if (s < 0.0 || r + s > 1.0)
    return 0;

  if (inv_det * vector3_dot_product(AC, q) > precision)
    return 1;
  return 0;
}
