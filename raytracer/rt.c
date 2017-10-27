#include "rt.h"

struct scene *init_scene(void)
{
  struct scene *scene = malloc(sizeof (struct scene));
  if (!scene)
    return NULL;
  scene->a_lights = NULL;
  scene->p_lights = NULL;
  scene->d_lights = NULL;
  scene->vertex_count = 0;
  scene->vertex = NULL;

  return scene;
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
  return 0;
}
