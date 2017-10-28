#include "rt.h"

struct vector3 surface_normal(struct triangle t)
{
  struct vector3 sn = vector3_cross_product(vector3_add(t.B, vector3_scale(-1, t.A)),
                                            vector3_add(t.C, vector3_scale(-1, t.A)));
  return vector3_normalize(sn);
}

int is_obj_point(struct scene *scene, struct ray ray, int i, int *t)
{
  for (int j = 0; j < scene->objects[i]->v_size / 3; ++j)
  {
    if (ray_triangle_intersection(scene->objects[i]->triangles[j], ray))
    {
      *t = j;
      return 1;
    }
  }
  return 0;
}

void set_scene(struct scene *scene)
{
  scene->cam->u = vector3_normalize(scene->cam->u);
  scene->cam->v = vector3_normalize(scene->cam->v);
  struct vector3 w = vector3_cross_product(scene->cam->u, scene->cam->v);
  w = vector3_scale(-1, w);
  float L =  (scene->cam->width / 2) / tan(scene->cam->fov / 2);
  printf("%f\n", L);

  struct vector3 c = vector3_add(scene->cam->pos, vector3_scale(L, w));

  scene->r_width = scene->cam->width;
  scene->r_height = scene->cam->height;

  scene->pixels = malloc(sizeof (struct color *) * scene->r_height);
  for (int i = 0; i < scene->r_height; ++i)
    scene->pixels[i] = malloc(sizeof (struct color) * scene->r_width);

  scene->rays = malloc(sizeof (struct ray) * scene->r_width * scene->r_height);
  
  for (int y = -scene->cam->height / 2; y < scene->cam->height / 2; ++y)
  {
    for (int x = -scene->cam->width / 2; x < scene->cam->width / 2; ++x)
    {
      struct vector3 p = vector3_add(c,
                         vector3_add(vector3_scale(x, scene->cam->u), 
                                     vector3_scale(y, scene->cam->v)));
      
      struct vector3 d = vector3_from_points(scene->cam->pos, p);
      struct ray r;
      r.origin = scene->cam->pos;
      r.direction = vector3_normalize(d);
      int m = y + scene->cam->height / 2;  
      int n = x + scene->cam->width / 2;
      scene->rays[m * scene->r_width + n] = r;
      for (int i = 0; i < scene->obj_count; ++i)
      {
        int index = 0;
        if (is_obj_point(scene, r, i, &index))
        {
          scene->pixels[m][n] = color_mult(scene->objects[i]->color,
                                           scene->a_light->color);
          for (int k = 0; k < scene->d_size; ++k)
          {
            float ld = vector3_dot_product(scene->d_lights[k]->pos,
                                surface_normal(scene->objects[index]->triangles[index]));
            scene->pixels[m][n] = color_mult(scene->d_lights[k]->color,
                                     color_lambda(ld, scene->objects[i]->m.kd));
          }
        }
        else
        {
          struct color col;
          col.r = 0;
          col.g = 0;
          col.b = 0;
          scene->pixels[m][n] = col;
        }
     }
    }
  }
}
