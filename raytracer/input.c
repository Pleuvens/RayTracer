#include <stdlib.h>

#include "rt.h"

int parse_input(char *path)
{
  FILE *f = fopen(path, "r");
  if (!f)
    return 0;
  if (parse_camera(f))
    return 0;
  return 1;
}
