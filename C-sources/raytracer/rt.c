#include <stdlib.h>

#include "rt.h"

struct scene *init_scene(void)
{
  struct scene *scene = malloc(sizeof (struct scene));
  if (!scene)
    return NULL;
  scene->cam = malloc(sizeof (struct cam));
  scene->a_light = NULL;
  scene->p_lights = NULL;
  scene->d_lights = NULL;
  scene->objects = NULL;
  scene->rays = NULL;
  scene->pixels = NULL;
  scene->d_size = 0;
  scene->p_size = 0;
  scene->obj_count = 0;
  scene->r_width = 0;
  scene->r_height = 0;
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
      free(scene->objects[i]->triangles);
      free(scene->objects[i]);
    }
  }
  if (scene->objects)
    free(scene->objects);

  free(scene->a_light);
  
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

  for (int i = 0; i < scene->r_height; ++i)
    if (scene->pixels[i])
      free(scene->pixels[i]);
  if (scene->pixels)
    free(scene->pixels);
  if (scene->rays)
    free(scene->rays);
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
  set_scene(scene);
  create_output(argv[2], scene->cam->width, scene->cam->height, scene->pixels);
  delete_scene(scene);
  return 0;
}
