#include <stdlib.h>

#include "rt.h"

int parse_light(FILE *f, char *s, struct scene *scene)
{
  if (*s == 'a')
  {
    scene->a_light = malloc(sizeof (struct light));
    if (!scene->a_light)
      return 0;
    scene->a_light->light = AMBIENT;
    fscanf(f, "%f %f %f", &(scene->a_light->color.r), 
                          &(scene->a_light->color.g), &(scene->a_light->color.b));
    scene->a_light->pos.x = 0;
    scene->a_light->pos.y = 0;
    scene->a_light->pos.z = 0;
    printf("%s %f %f %f\n", s, scene->a_light->color.r, scene->a_light->color.g,
                               scene->a_light->color.b);
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
