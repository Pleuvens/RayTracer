#include <stdlib.h>

#include "rt.h"

int parse_selector(FILE *f, char *s, struct scene *scene)
{
  if (my_strncmp(s, "camera", 6))
  {
    printf("%s ", s);
    return parse_camera(f, scene);
  }
  if (my_strncmp(s, "a_light", 7) 
      || my_strncmp(s, "d_light", 7)
      || my_strncmp(s, "p_light", 7))
    return parse_light(f, s, scene);
  else
    return parse_primitive(f, scene, s);
 return 1;
}

int parse_input(char *path, struct scene *scene)
{
  FILE *f = fopen(path, "r");
  if (!f)
    return 0;
  char s[512] = { 0 };
  while (fscanf(f, "%s", s) != EOF)
  {
    if (!parse_selector(f, s, scene))
      break;
  }
  fclose(f);
  return 1;
}
