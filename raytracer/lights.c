#include "rt.h"

struct color apply_directional(struct scene *scene, int i, int k, int index)
{
  struct vector3 L = vector3_scale(-1, scene->d_lights[k]->pos);

  struct color diff = color_mult(scene->objects[i]->m.kd, scene->d_lights[k]->color);

  float ld = vector3_dot_product(L,
             scene->objects[i]->triangles[index].nA);

  if (ld < 0)
    ld = 0;

  return color_lambda(ld, diff);
}

struct color apply_point(struct scene *scene, int i, int k, int index, int distance, 
                         struct vector3 dir)
{
  struct vector3 L = vector3_scale(-1, dir);
  struct color diff = color_mult(scene->objects[i]->m.kd, scene->p_lights[k]->color);
  float ld = vector3_dot_product(L,
             scene->objects[i]->triangles[index].nA);
  if (ld < 0)
    ld = 0;
  ld = ld / distance;
  return color_lambda(ld, diff);
}
