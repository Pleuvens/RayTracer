#include <stdlib.h>

#include "rt.h"

int parse_camera(FILE *f)
{
  int width = 0;
  int height = 0;
  float pos_x = 0;
  float pos_y = 0;
  float pos_z = 0;
  float u_x = 0;
  float u_y = 0;
  float u_z = 0;
  float v_x = 0;
  float v_y = 0;
  float v_z = 0;
  float field_of_view = 0;
  fscanf(f, "%d %d %f %f %f %f %f %f %f %f %f %f", &width, &height, &pos_x,
    &pos_y, &pos_z, &u_x, &u_y, &u_z, &v_x, &v_y, &v_z, &field_of_view);
  printf("%d %d %f %f %f %f %f %f %f %f %f %f\n", width, height, pos_x,
    pos_y, pos_z, u_x, u_y, u_z, v_x, v_y, v_z, field_of_view);
  return 1;
}
