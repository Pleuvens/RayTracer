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
      int size = int_width(pixels[i][j].r);
      fprintf(f, "%d%*s ", pixels[i][j].r, 3 - size, "");
      size = int_width(pixels[i][j].g);
      fprintf(f, "%d%*s ", pixels[i][j].g, 3 - size, "");
      size = int_width(pixels[i][j].b);
      fprintf(f, "%d%*s ", pixels[i][j].b, 3 - size, "");
    }
    int size = int_width(pixels[i][width - 1].r);
    fprintf(f, "%d%*s ", pixels[i][width - 1].r, 3 - size, "");
    size = int_width(pixels[i][width - 1].g);
    fprintf(f, "%d%*s ", pixels[i][width - 1].g, 3 - size, "");
    fprintf(f, "%d\n ", pixels[i][width - 1].b);
  }

  fclose(f);
  return 1;
}
