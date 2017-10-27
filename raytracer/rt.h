#ifndef RT_H
# define RT_H

#include <stdio.h>

struct cam
{
  int width;
  int height;

  float pos_x;
  float pos_y;
  float pos_z;

  float u_x;
  float u_y;
  float u_z;

  float v_x;
  float v_y;
  float v_z;
}

int my_strlen(char *s);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, size_t n);

char *my_strtok(char *s, size_t *index);

int my_atoi(char *s);

int parse_camera(FILE *f);

int parse_input(char *path);

#endif /* !RT_H */
