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

  float fov;
};

enum x_light
{
  AMBIENT,
  DIRECTIONAL,
  POINT
};

struct light
{
  enum x_light light;

  float r;
  float g;
  float b;

  float pos_x;
  float pos_y;
  float pos_z;
};

struct K
{
  float r;
  float g;
  float b;
};

struct material
{
  struct K *ka;
  struct K *kd;
  struct K *ks;

  float ns;
  float ni;
  float nr;
  float d;
};

struct vertex
{
  float x;
  float y;
  float z;

  float vec_x;
  float vec_y;
  float vec_z;
};

struct scene
{
  struct cam *cam;

  int vertex_count;
  struct vertex **vertex;

  struct light **a_lights;
  struct light **p_lights;
  struct light **d_lights;
};

int my_strlen(char *s);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, size_t n);

char *my_strtok(char *s, size_t *index);

int my_strcontains(char *s, char *subs, size_t len, size_t slen);

int my_atoi(char *s);

int parse_camera(FILE *f);

int parse_light(FILE *f, char *s);

int parse_primitive(FILE *f);

int parse_input(char *path);

#endif /* !RT_H */
