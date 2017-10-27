#include <stdlib.h>

#include "rt.h"

int parse_light(FILE *f, char *s)
{
  float r = 0;
  float g = 0;
  float b = 0;
  float x = 0;
  float y = 0;
  float z = 0;
  if (*s == 'a')
  {
    fscanf(f, "%f %f %f", &r, &g, &b); 
    printf("%s %f %f %f\n", s, r, g, b);
  }
  else
  {
    fscanf(f, "%f %f %f %f %f %f", &r, &g, &b, &x, &y, &z); 
    printf("%s %f %f %f %f %f %f\n", s, r, g, b, x, y, z);
  }
  return 1;
}
