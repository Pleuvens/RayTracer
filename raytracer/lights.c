#include "rt.h"

void apply_directional(struct scene *scene, int i, int k, int index)
{
  float ld = vector3_dot_product(scene->d_lights[k]->pos,
             surface_normal(scene->objects[index]->triangles[index]));
  return color_mult(scene->d_lights[k]->color, color_lambda(ld, scene->objects[i]->m.kd))
}
