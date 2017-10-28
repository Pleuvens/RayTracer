#include <math.h>
#include "rt.h"

struct vector3 vector3_add(struct vector3 v1, struct vector3 v2)
{
  struct vector3 v3;
  v3.x = v1.x + v2.x;
  v3.y = v1.y + v2.y;
  v3.z = v1.z + v2.z;
  return v3;
}

struct vector3 vector3_scale(float lambda, struct vector3 v1)
{
  struct vector3 res;
  res.x = lambda * v1.x;
  res.y = lambda * v1.y;
  res.z = lambda * v1.z;
  return res;
}

struct vector3 vector3_dot_product(struct vector3 v1, struct vector3 v2)
{
  struct vector3 v3;
  v3.x = v1.x * v2.x;
  v3.y = v1.y * v2.y;
  v3.z = v1.z * v2.z;
  return v3;
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
