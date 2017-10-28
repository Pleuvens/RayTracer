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
  for (int j = 0; j < height; ++j)
  {
    int r = 0;
    int g = 0;
    int b = 0;
    for (int i = 0; i < width - 1; ++i)
    {
      r = (int)(pixels[i][j].r * 255) % 256;
      g = (int)(pixels[i][j].g * 255) % 256;
      b = (int)(pixels[i][j].b * 255) % 256;
      int size = int_width(r);
    //  printf("size: %f %f %f %d\n", r, g, b, size);
      fprintf(f, "%d%*s ", r, 3 - size, "");
      size = int_width(g);
      fprintf(f, "%d%*s ", g, 3 - size, "");
      size = int_width(b);
      fprintf(f, "%d%*s ", b, 3 - size, "");
    }
    r = (int)(pixels[j][width - 1].r * 255) % 256;
    g = (int)(pixels[j][width - 1].g * 255) % 256;
    b = (int)(pixels[j][width - 1].b * 255) % 256;
    int size = int_width(r);
    fprintf(f, "%d%*s ", r, 3 - size, "");
    size = int_width(g);
    fprintf(f, "%d%*s ", g, 3 - size, "");
    fprintf(f, "%d\n", b);
  }

  fclose(f);
  return 1;
}
