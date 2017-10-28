#include "rt.h"

int parse_camera(FILE *f, struct scene *scene)
{
  fscanf(f, "%d %d %f %f %f %f %f %f %f %f %f %f", &(scene->cam->width),
  &(scene->cam->height), &(scene->cam->pos_x), &(scene->cam->pos_y),
  &(scene->cam->pos_z), &(scene->cam->u_x), &(scene->cam->u_y),
  &(scene->cam->u_z), &(scene->cam->v_x), &(scene->cam->v_y),
  &(scene->cam->v_z), &(scene->cam->fov));
  printf("\n");
  return 1;
}
