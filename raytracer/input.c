#include <stdlib.h>

#include "rt.h"

void parse_selector(FILE *f, char *s)
{
  if (my_strncmp(s, "camera", 6))
  {
    printf("%s ", s);
    parse_camera(f);
  }
  if (my_strncmp(s, "a_light", 7) 
      || my_strncmp(s, "d_light", 7)
      || my_strncmp(s, "p_light", 7))
    parse_light(f, s);
  else
    parse_primitive(f);
}

int parse_input(char *path)
{
  FILE *f = fopen(path, "r");
  if (!f)
    return 0;
  char *s = calloc(512, sizeof (char));
  while (fscanf(f, "%s", s) != EOF)
    parse_selector(f, s);
  free(s);
  fclose(f);
  return 1;
}
