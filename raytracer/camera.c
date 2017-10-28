#include "rt.h"

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
    for (int y = -scene->cam->height / 2; y < scene->cam->width / 2; ++y)
    {
      struct vector3 p;
      p.x = x / u.x;
      p.y = y / u.y;
      p.z = 0;
      struct vector3 r = vector3_from_points(p, c);
    }
  }
}
