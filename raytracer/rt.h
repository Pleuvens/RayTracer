#ifndef RT_H
# define RT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
  struct K ka;
  struct K kd;
  struct K ks;

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
};

struct vertex_normal
{
  float x;
  float y;
  float z;
};

struct object
{
  int v_size;
  int vn_size;
  struct material m;
  struct vertex *v;
  struct vertex_normal *vn;
};

struct scene
{
  struct cam *cam;

  int obj_count;
  struct object **objects;

  struct light **a_lights;
  int a_size;

  struct light **p_lights;
  int p_size;

  struct light **d_lights;
  int d_size;
};

int my_strlen(char *s);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, size_t n);

char *my_strtok(char *s, size_t *index);

int my_strcontains(char *s, char *subs, size_t len, size_t slen);

int my_atoi(char *s);

int parse_camera(FILE *f, struct scene *scene);

int parse_light(FILE *f, char *s, struct scene *scene);

int parse_primitive(FILE *f, struct scene *scene, char *s);

int parse_input(char *path, struct scene *scene);

#endif /* !RT_H */
