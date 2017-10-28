#include "rt.h"

struct color apply_directional(struct scene *scene, int i, int k, int index)
{
  float ld = vector3_dot_product(vector3_scale(-1, scene->d_lights[k]->pos),
             scene->objects[i]->triangles[index].nA);
  return color_mult(scene->d_lights[k]->color, color_lambda(ld, scene->objects[i]->m.kd));
}
