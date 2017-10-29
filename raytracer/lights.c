#include "rt.h"

struct color apply_directional(struct scene *scene, int i, int k, int index)
{
  struct vector3 L = vector3_scale(-1, scene->d_lights[k]->pos);
  struct color light = color_add(scene->a_light->color, scene->d_lights[k]->color);
  struct color diff = color_mult(scene->objects[i]->m.kd, light);
  float ld = vector3_dot_product(L,
             scene->objects[i]->triangles[index].nA);
  return color_lambda(ld, diff);
}
