#include <stdlib.h>

#include "rt.h"

void parse_selector(FILE *f, char *s, struct scene *scene)
{
  if (my_strncmp(s, "camera", 6))
  {
    printf("%s ", s);
    parse_camera(f, scene);
  }
  if (my_strncmp(s, "a_light", 7) 
      || my_strncmp(s, "d_light", 7)
      || my_strncmp(s, "p_light", 7))
    parse_light(f, s, scene);
  else
    parse_primitive(f, scene);
}

int parse_input(char *path, struct scene *scene)
{
  FILE *f = fopen(path, "r");
  if (!f)
    return 0;
  char *s = calloc(512, sizeof (char));
  while (fscanf(f, "%s", s) != EOF)
    parse_selector(f, s, scene);
  free(s);
  fclose(f);
  return 1;
}
