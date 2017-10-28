#include "rt.h"

struct vector3 surface_normal(struct triangle t)
{
  struct vector3 sn = vector3_cross_product(vector3_add(t.B, vector3_scale(-1, t.A)),
                                            vector3_add(t.C, vector3_scale(-1, t.A)));
  return vector3_normalize(sn);
}

void set_scene(struct scene *scene)
{
  scene->cam->u = vector3_normalize(scene->cam->u);
  scene->cam->v = vector3_normalize(scene->cam->v);
  
  struct vector3 w = vector3_cross_product(scene->cam->u, scene->cam->v);
  w = vector3_scale(-1, w);
  float L = tan(scene->cam->fov / 2) * (scene->cam->width / 2);

  struct vector3 c = vector3_add(cam_pos, vector3_scale(L, w));
  
  scene->r_width = scene->cam->width;
  scene->r_height = scene->cam->height;

  scene->cam->rays = malloc(sizeof (struct ray) * scene->r_width * scene->r_height);
  
  for (int x = -scene->cam->width / 2; x < scene->cam->width / 2; ++x)
  {
    for (int y = -scene->cam->height / 2; y < scene->cam->height / 2; ++y)
    {
      struct vector3 p = vector3_add(c,
                         vector3_add(vector3_scale(x, scene->cam->u), 
                                     vector3_scale(y, scene->cam->v)));
      struct vector3 d = vector3_from_points(c, p);
      struct ray r;
      r.origin = p;
      r.direction = d;
      scene->cam->rays[x * scene->r_height + y] = r;
      if (is_obj_point(scene, ray))
      {
        scene->objects[index]->color = scene->objects[index]->color
                                       * scene->a_lights->color;
        for (int i = 0; i < scene->d_lights; ++i)
        {
          scene->objects[index]->color = scene->d_lights[];
        }
      }
    }
  }
}

int is_obj_point(struct scene *scene, struct ray ray)
{
  for (int i = 0; i < scene->obj_count; ++i)
  {
    for (int j = 0; j < scene->objects[i]->v_size / 3; ++j)
    {
      if ()
        return 1;
    }
  }
  return 0;
}
