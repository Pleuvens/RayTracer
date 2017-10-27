#include <stdlib.h>

#include "rt.h"

int parse_camera(char *s)
{
  if (!s || !*s)
    return 0;
  int index = 0;
  char *token = my_strtok(s, &index);
  if (!my_strncmp(s, "camera", 6))
    return 0;
  int len = my_strlen(s);
  int tab[12] = { 0 };
  int val = 0;
  while (index < len)
  {
    free(token);
    token = my_strtok(s, &index);
    tab[val++] = my_atoi(token);
  }
}

void parse_input(char *path)
{
}
