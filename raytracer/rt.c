#include <stdlib.h>

#include "rt.h"

struct scene *init_scene(void)
{
  struct scene *scene = malloc(sizeof (struct scene));
  if (!scene)
    return NULL;
  scene->cam = malloc(sizeof (struct cam));
  scene->a_lights = NULL;
  scene->p_lights = NULL;
  scene->d_lights = NULL;
  scene->objects = NULL;
  scene->a_size = 0;
  scene->d_size = 0;
  scene->p_size = 0;
  scene->obj_count = 0;
  return scene;
}

void delete_scene(struct scene *scene)
{
  free(scene->cam);
  
  for (int i = 0; i < scene->obj_count; ++i)
  {
    if (scene->objects[i])
    {
      free(scene->objects[i]->v);
      free(scene->objects[i]->vn);
      free(scene->objects[i]);
    }
  }
  if (scene->objects)
    free(scene->objects);

  for (int i = 0; i < scene->a_size; ++i)
    if (scene->a_lights[i])
      free(scene->a_lights[i]);
  if (scene->a_lights)
    free(scene->a_lights);
  
  for (int i = 0; i < scene->p_size; ++i)
    if (scene->p_lights[i])
      free(scene->p_lights[i]);
  if (scene->p_lights)
    free(scene->p_lights);
  
  for (int i = 0; i < scene->d_size; ++i)
    if (scene->d_lights[i])
      free(scene->d_lights[i]);
  if (scene->d_lights)
    free(scene->d_lights);
  free(scene);
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./rt input.svati output.ppm\n");
    return 1;
  }
  struct scene *scene = init_scene();
  parse_input(argv[1], scene);
  delete_scene(scene);
  return 0;
}
