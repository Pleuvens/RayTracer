#include "rt.h"

int parse_primitive(FILE *f)
{
  char s[1024] = { 0 };
  float r = 0;
  float g = 0;
  float b = 0;
  int n = 0;
  fscanf(f, "%s %d", s, &n);
  printf("%s %d\n", s, n);
  fscanf(f, "%s %f", s, &r);
  printf("%s %f\n", s, r);
  fscanf(f, "%s %f %f %f", s, &r, &g, &b);
  printf("%s %f %f %f\n", s, r, g, b);
  fscanf(f, "%s %f %f %f", s, &r, &g, &b);
  printf("%s %f %f %f\n", s, r, g, b);
  fscanf(f, "%s %f %f %f", s, &r, &g, &b);
  printf("%s %f %f %f\n", s, r, g, b);
  //fscanf(f, "%s %f %f %f", s, &r, &g, &b);
  //printf("%s %f %f %f\n", s, r, g, b);
  //fscanf(f, "%s %f %f %f", s, &r, &g, &b);
  //printf("%s %f %f %f\n", s, r, g, b);
  //fscanf(f, "%s %f %f %f", s, &r, &g, &b);
  
  int er = fscanf(f, "%s", s);
  while (er != EOF && s[0] != '.')
  {
    float x = 0;
    float y = 0;
    float z = 0;

    fscanf(f, "%f %f %f", &x, &y, &z);
    printf("%s %f %f %f\n", s, x, y, z);
    er = fscanf(f, "%s", s);
  }
  return 1;
}
