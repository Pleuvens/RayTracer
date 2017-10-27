#include <stdlib.h>

#include "rt.h"

int parse_camera(FILE *f)
{
  char *s = NULL;
  size_t len = 0;
  if (getline(&s, &len, f) == -1)
    return 0;
  if (!s || !*s)
    return 0;
  size_t index = 0;
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
  free(s);
  return 1;
}
