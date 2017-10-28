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
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct vector3 vector3_inverse(struct vector3 v1)
{
  struct vector3 new;
  new.x = 1 / v1.x;
  new.y = 1 / v1.y;
  new.z = 1 / v1.z;
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

struct vector3 vector3_normalize(struct vector3 v1)
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
  v.x = p2.x - p1.x;
  v.y = p2.y - p1.y;
  v.z = p2.z - p1.z;
  return v;
}

int intersect(struct triangle triangle, struct ray ray, struct vector3 p)
{
  (void) ray;
  struct vector3 AB = vector3_from_points(triangle.A, triangle.B);
  struct vector3 AC = vector3_from_points(triangle.A, triangle.C);
  struct vector3 BA = vector3_from_points(triangle.B, triangle.A);
  struct vector3 BC = vector3_from_points(triangle.B, triangle.C);
  struct vector3 CA = vector3_from_points(triangle.C, triangle.A);
  struct vector3 CB = vector3_from_points(triangle.C, triangle.B);
  struct vector3 AP = vector3_from_points(triangle.A, p);
  struct vector3 BP = vector3_from_points(triangle.B, p);
  struct vector3 CP = vector3_from_points(triangle.C, p);
  struct vector3 first = vector3_cross_product(AC, AB);
  struct vector3 second = vector3_cross_product(AP, AB);

  if (vector3_dot_product(first, second) < 0)
    return 0;

  first = vector3_cross_product(BA, BC);
  second = vector3_cross_product(BP, BC);

  if (vector3_dot_product(first, second) < 0)
    return 0;

  first = vector3_cross_product(CB, CA);
  second = vector3_cross_product(CP, CA);

  return vector3_dot_product(first, second) > 0;
}

int ray_triangle_intersection(struct triangle triangle, struct ray ray)
{
  struct vector3 n = triangle.nA;
  struct vector3 A = triangle.A;
  float d = - (n.x * A.x) - (n.y * A.y) - (n.z * A.z);
  float t0 = - ((vector3_dot_product(n, ray.origin) + d) /
  (vector3_dot_product(n, ray.direction)));
  struct vector3 P = vector3_add(ray.origin, vector3_scale(t0, ray.direction));
  return intersect(triangle, ray, P);
}
