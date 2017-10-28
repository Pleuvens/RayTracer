#include <stdlib.h>

#include "rt.h"

int parse_light(FILE *f, char *s, struct scene *scene)
{
  if (*s == 'a')
  {
    scene->a_lights = realloc(scene->a_lights,
                              sizeof (struct light*) * (scene->a_size + 1));
    if (!scene->a_lights)
      return 0;
    struct light *new = malloc(sizeof (struct light));
    if (!new)
      return 0;
    new->light = AMBIENT;
    fscanf(f, "%f %f %f", &(new->color.r), &(new->color.g), &(new->color.b));
    new->pos.x = 0;
    new->pos.y = 0;
    new->pos.z = 0;
    printf("%s %f %f %f\n", s, new->color.r, new->color.g, new->color.b);
    scene->a_lights[scene->a_size++] = new;
  }
  else if (*s == 'd')
  {
    scene->d_lights = realloc(scene->d_lights,
                              sizeof (struct light*) * (scene->d_size + 1));
    if (!scene->d_lights)
      return 0;
    struct light *new = malloc(sizeof (struct light));
    if (!new)
      return 0;
    new->light = DIRECTIONAL;
    fscanf(f, "%f %f %f %f %f %f", &(new->color.r), &(new->color.g),
           &(new->color.b), &(new->pos.x), &(new->pos.y), &(new->pos.z));
    printf("%s %f %f %f %f %f %f\n", s, new->color.r, new->color.g,
    new->color.b, new->pos.x, new->pos.y, new->pos.z);
    scene->d_lights[scene->d_size++] = new;
  }
  else
  {
    scene->p_lights = realloc(scene->p_lights,
                              sizeof (struct light*) * (scene->p_size + 1));
    if (!scene->p_lights)
      return 0;
    struct light *new = malloc(sizeof (struct light));
    if (!new)
      return 0;
    new->light = POINT;
    fscanf(f, "%f %f %f %f %f %f", &(new->color.r), &(new->color.g),
    &(new->color.b), &(new->pos.x), &(new->pos.y), &(new->pos.z));
    printf("%s %f %f %f %f %f %f\n", s, new->color.r, new->color.g,
           new->color.b, new->pos.x, new->pos.y, new->pos.z);
    scene->p_lights[scene->p_size++] = new;
  }
  return 1;
}
