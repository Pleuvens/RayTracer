#ifndef RT_H
# define RT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct color
{
  float r;
  float g;
  float b;
};

struct vector3
{
  float x;
  float y;
  float z;
};

struct cam
{
  int width;
  int height;

  struct vector3 pos;

  struct vector3 u;

  struct vector3 v;

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

  struct color color;

  struct vector3 pos;
};

struct material
{
  struct color ka;
  struct color kd;
  struct color ks;

  float ns;
  float ni;
  float nr;
  float d;
};

struct triangle
{
  struct vector3 A;
  struct vector3 B;
  struct vector3 C;

  struct vector3 nA;
  struct vector3 nB;
  struct vector3 nC;
};

struct object
{
  int v_size;
  int vn_size;
  struct material m;
  struct vector3 *v;
  struct vector3 *vn;
  struct  triangle *triangles;
  struct color color;
  struct material material;
};

struct ray
{
  struct vector3 origin;
  struct vector3 direction;
};

struct scene
{
  struct cam *cam;

  int obj_count;
  struct object **objects;

  struct light *a_light;

  struct light **p_lights;
  int p_size;

  struct light **d_lights;
  int d_size;

  struct ray *rays;
  int r_width;
  int r_height;

  struct color **pixels;
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

struct vector3 vector3_add(struct vector3 v1, struct vector3 v2);

struct vector3 float_add(struct vector3 vector, float d);

struct vector3 vector3_scale(float lambda, struct vector3 v1);

float vector3_dot_product(struct vector3 v1, struct vector3 v2);

struct vector3 vector3_inverse(struct vector3 v1);

struct vector3 vector3_cross_product(struct vector3 v1, struct vector3 v2);

struct vector3 vector3_normalize(struct vector3 v);

float vector3_distance(struct vector3 v1, struct vector3 v2);

struct vector3 vector3_from_points(struct vector3 p1, struct vector3 p2);

struct vector3 intersec_find(struct vector3 AB, struct vector3 AC,
                             struct vector3 AP, struct vector3 intersect);

int ray_triangle_intersection(struct triangle triangle,
                              struct ray ray, struct vector3 *p);

struct color color_add(struct color c1, struct color c2);

struct color color_mult(struct color c1, struct color c2);

struct color color_lambda(float lambda, struct color c1);

int create_output(char *path, int width, int height, struct color **pixels);

void set_scene(struct scene *scene);

struct color apply_directional(struct scene *scene, int i, int k, int index); 

struct vector3 surface_normal(struct triangle t);

int color_scale(float c);

struct color color_clamp(struct color c);

#endif /* !RT_H */
