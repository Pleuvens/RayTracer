#include <stdlib.h>

#include "rt.h"

void set_obj_mat(FILE *f, char *s, struct material *m)
{
  if (my_strncmp(s, "Ka", 2))
  {
    fscanf(f, "%f %f %f", &(m->ka.r), &(m->ka.g), &(m->ka.b));
    printf("%s %f %f %f\n", s, m->ka.r, m->ka.g, m->ka.b);
  }
  else if (my_strncmp(s, "Kd", 2))
  {
    fscanf(f, "%f %f %f", &(m->kd.r), &(m->kd.g), &(m->kd.b));
    printf("%s %f %f %f\n", s, m->kd.r, m->kd.g, m->kd.b);
  }
  else if (my_strncmp(s, "Ks", 2))
  {
    fscanf(f, "%f %f %f", &(m->ks.r), &(m->ks.g), &(m->ks.b));
    printf("%s %f %f %f\n", s, m->ks.r, m->ks.g, m->ks.b);
  }
  else if (my_strncmp(s, "Ns", 2))
  {
    fscanf(f, "%f", &(m->ns));
    printf("%s %f\n", s, m->ns);
  }
  else if (my_strncmp(s, "Nr", 2))
  {
    fscanf(f, "%f", &(m->nr));
    printf("%s %f\n", s, m->nr);
  }
  else if (my_strncmp(s, "Ni", 2))
  {
    fscanf(f, "%f", &(m->ni));
    printf("%s %f\n", s, m->ni);
  }
  else if (my_strncmp(s, "d", 1))
  {
    fscanf(f, "%f", &(m->d));
    printf("%s %f\n", s, m->d);
  }
}

int parse_primitive(FILE *f, struct scene *scene, char *s)
{
  int n = 0;
  int er = 0;

  while (er != EOF)
  {
    scene->obj_count += 1;
    scene->objects = realloc(scene->objects,
                            sizeof (struct object *) * (scene->obj_count));
    if (!scene->objects)
      return 0;
    struct object *o = malloc(sizeof (struct object));
    if (!o)
      return 0;
    o->v = NULL;
    o->vn = NULL;
    o->v_size = 0; 
    o->vn_size = 0;
    struct material m;
    fscanf(f, "%d", &n);
    printf("%s %d\n", s, n);

    er = fscanf(f, "%s", s);
    while (!my_strncmp(s, "vn", 2) && !my_strncmp(s, "v", 1))
    {
      set_obj_mat(f, s, &m);
      er = fscanf(f, "%s", s);
    }

    o->m = m;
    
    while (er != EOF && !my_strncmp(s, "object", 6))
    {
      if (my_strncmp(s, "v", 1))
      {
        o->v_size += 1;
        o->v = realloc(o->v, sizeof (struct vertex) * (o->v_size));
        if (!o->v)
          return 0;
        fscanf(f, "%f %f %f", &(o->v[o->v_size - 1].x), &(o->v[o->v_size - 1].y),
                              &(o->v[o->v_size - 1].z));
        printf("%s %f %f %f\n", s, o->v[o->v_size - 1].x, o->v[o->v_size - 1].y,
                                   o->v[o->v_size - 1].z);
      }
      else
      {
        o->vn_size += 1;
        o->vn = realloc(o->vn, sizeof (struct vertex) * (o->vn_size));
        if (!o->vn)
          return 0;
        fscanf(f, "%f %f %f", &(o->vn[o->vn_size - 1].x), &(o->vn[o->vn_size - 1].y), 
                              &(o->vn[o->vn_size].z));
        printf("%s %f %f %f\n", s, o->vn[o->vn_size - 1].x, o->vn[o->vn_size - 1].y,
                              o->vn[o->vn_size - 1].z);
      }
      er = fscanf(f, "%s", s);
    }
    o->vn_size += 1;
    o->v_size += 1;
    scene->objects[scene->obj_count - 1] = o;
  }
  return 1;
}
