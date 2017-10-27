#include "rt.h"

int int_width(int i)
{
    double tmp = i;
    if (tmp == 0)
        return 1;
    int total = 0;

    if (tmp < 0)
    {
        total++;
        tmp = -tmp;
    }
    total += log10(tmp) + 1;
    return total;
}


int create_output(char *path, int width, int height, int **pixels)
{
  FILE *f = fopen(path, "w");
  if (!f)
    return 0;
  fprintf(f, "P3\n%d %d\n255\n", width, height);
  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width - 1; ++j)
    {
      int size = int_width(pixels[i][j]);
      fprintf(f, "%d%*s ", pixels[i][j], 3 - size, "");
    }
    fprintf(f, "%d\n", pixels[i][width - 1]);
  }

  fclose(f);
  return 1;
}
