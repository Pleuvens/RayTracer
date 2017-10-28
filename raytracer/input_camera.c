#include "rt.h"

int parse_camera(FILE *f, struct scene *scene)
{
  fscanf(f, "%d %d %f %f %f %f %f %f %f %f %f %f", &(scene->cam->width),
  &(scene->cam->height), &(scene->cam->pos.x), &(scene->cam->pos.y),
  &(scene->cam->pos.z), &(scene->cam->u.x), &(scene->cam->u.y),
  &(scene->cam->u.z), &(scene->cam->v.x), &(scene->cam->v.y),
  &(scene->cam->v.z), &(scene->cam->fov));
  scene->cam->fov = scene->cam->fov * M_PI / 180;
  return 1;
}
