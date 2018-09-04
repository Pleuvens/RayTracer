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


int create_output(char *path, int width, int height, struct color **pixels)
{
  FILE *f = fopen(path, "w");
  if (!f)
    return 0;
  fprintf(f, "P3\n%d %d\n255\n", width, height);
  for (int i = 0; i < height; ++i)
  {
    int r = 0;
    int g = 0;
    int b = 0;
    for (int j = 0; j < width - 1; ++j)
    {
      r = color_scale(pixels[i][j].r);
      g = color_scale(pixels[i][j].g);
      b = color_scale(pixels[i][j].b);
      int size = int_width(r);
    //  printf("size: %f %f %f %d\n", r, g, b, size);
      fprintf(f, "%d%*s ", r, 3 - size, "");
      size = int_width(g);
      fprintf(f, "%d%*s ", g, 3 - size, "");
      size = int_width(b);
      fprintf(f, "%d%*s ", b, 3 - size, "");
    }
    r = color_scale(pixels[i][width - 1].r);
    g = color_scale(pixels[i][width - 1].g);
    b = color_scale(pixels[i][width - 1].b);
    int size = int_width(r);
    fprintf(f, "%d%*s ", r, 3 - size, "");
    size = int_width(g);
    fprintf(f, "%d%*s ", g, 3 - size, "");
    fprintf(f, "%d\n", b);
  }

  fclose(f);
  return 1;
}
