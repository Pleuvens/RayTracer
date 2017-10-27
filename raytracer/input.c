#include <stdlib.h>
#include <stdio.h>

#include "rt.h"

int parse_camera(char *s, int len)
{
  if (!s || !*s)
    return 0;
  int index = 0;
  char *token = my_strtok(s, &index);
  if (!my_strncmp(s, "camera", 6))
    return 0;
  int tab[12] = { 0 };
  int val = 0;
  while (index < len && s[index])
  {
    free(token);
    token = my_strtok(s, &index);
    tab[val++] = my_atoi(token);
  }
  printf("camera ");
  for (int i = 0; i < 12; ++i)
    printf("%d ", tab[i]);
  printf("\n");
  free(token);
  return 1;
}

int parse_input(char *path)
{
  FILE *f = fopen(path, "r");
  if (!f)
    return 0;
  char *line = NULL;
  size_t c = 0;
  if (getline(&line, &c, f) == -1)
    return 0;
  int p_c = parse_camera(line, c);
  free(line);
  return p_c;
}
