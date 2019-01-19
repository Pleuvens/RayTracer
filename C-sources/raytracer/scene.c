#include "rt.h"

struct vector3 surface_normal(struct triangle t)
{
  struct vector3 sn = vector3_cross_product(vector3_add(t.B, vector3_scale(-1,
                                                                          t.A)),
                                            vector3_add(t.C, vector3_scale(-1,
                                                                         t.A)));
  return vector3_normalize(sn);
}

void set_scene(struct scene *scene)
{
  scene->cam->u = vector3_normalize(scene->cam->u);
  scene->cam->v = vector3_normalize(scene->cam->v);
  struct vector3 w = vector3_cross_product(scene->cam->u, scene->cam->v);
  w = vector3_scale(-1, w);
  float L =  (scene->cam->width / 2) / tan(scene->cam->fov / 2);

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
      struct color col;
      col.r = 0;
      col.g = 0;
      col.b = 0;
      scene->pixels[m][n] = col;
      int index_obj = -1;
      int index_t = -1;
      float distance = 0;
      struct vector3 inters = d;
      for (int i = 0; i < scene->obj_count; ++i)
      {
        for (int j = 0; j < scene->objects[i]->v_size / 3; ++j)
        {
          if (ray_triangle_intersection(scene->objects[i]->triangles[j], r,
                                        &inters))
          { 
            if (index_obj < 0 || distance > vector3_distance(r.origin, inters))
            {
              index_obj = i;
              index_t = j;
              distance = vector3_distance(r.origin, inters);
            }
          }
        } 
      }
      if (index_obj > -1)
      {
        struct color ak = color_mult(scene->objects[index_obj]->m.ka,
                                        scene->a_light->color);
        for (int l = 0; l < scene->d_size; ++l)
        {
            ak = color_add(ak, apply_directional(scene, index_obj, l, index_t));
        }
        for (int l = 0; l < scene->p_size; ++l)
        {
            ak = color_add(ak, apply_point(scene, index_obj, l, index_t,
                            vector3_distance(scene->p_lights[l]->pos, inters),
                            vector3_from_points(scene->p_lights[l]->pos,
                                                inters)));
        }
        scene->pixels[m][n] = ak;
      }
    }
  }
}