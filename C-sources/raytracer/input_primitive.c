#include <stdlib.h>

#include "rt.h"

void set_obj_mat(FILE *f, char *s, struct material *m)
{
  if (my_strncmp(s, "Ka", 2))
    fscanf(f, "%f %f %f", &(m->ka.r), &(m->ka.g), &(m->ka.b));
  else if (my_strncmp(s, "Kd", 2))
    fscanf(f, "%f %f %f", &(m->kd.r), &(m->kd.g), &(m->kd.b));
  else if (my_strncmp(s, "Ks", 2))
    fscanf(f, "%f %f %f", &(m->ks.r), &(m->ks.g), &(m->ks.b));
  else if (my_strncmp(s, "Ns", 2))
    fscanf(f, "%f", &(m->ns));
  else if (my_strncmp(s, "Nr", 2))
    fscanf(f, "%f", &(m->nr));
  else if (my_strncmp(s, "Ni", 2))
    fscanf(f, "%f", &(m->ni));
  else if (my_strncmp(s, "d", 1))
    fscanf(f, "%f", &(m->d));
}

int make_triangles(struct scene *scene)
{
  for (int i = 0; i < scene->obj_count; ++i)
  {
    scene->objects[i]->triangles = malloc(sizeof (struct triangle)
                                          * (scene->objects[i]->v_size / 3));
    if (!scene->objects[i]->triangles)
      return 0;
    scene->objects[i]->v_size += 1;
    scene->objects[i]->vn_size += 1;
    for (int j = 0, k = 0; j < scene->objects[i]->v_size - 2; j += 3, ++k)
    {
      struct triangle t; 
      struct vector3 A;
      struct vector3 B;
      struct vector3 C;
      struct vector3 nA;
      struct vector3 nB;
      struct vector3 nC;

      A.x = scene->objects[i]->v[j].x;
      A.y = scene->objects[i]->v[j].y;
      A.z = scene->objects[i]->v[j].z;
      
      B.x = scene->objects[i]->v[j + 1].x;
      B.y = scene->objects[i]->v[j + 1].y;
      B.z = scene->objects[i]->v[j + 1].z;

      C.x = scene->objects[i]->v[j + 2].x;
      C.y = scene->objects[i]->v[j + 2].y;
      C.z = scene->objects[i]->v[j + 2].z;

      nA.x = scene->objects[i]->vn[j].x;
      nA.y = scene->objects[i]->vn[j].y;
      nA.z = scene->objects[i]->vn[j].z;
      
      nB.x = scene->objects[i]->vn[j + 1].x;
      nB.y = scene->objects[i]->vn[j + 1].y;
      nB.z = scene->objects[i]->vn[j + 1].z;

      nC.x = scene->objects[i]->vn[j + 2].x;
      nC.y = scene->objects[i]->vn[j + 2].y;
      nC.z = scene->objects[i]->vn[j + 2].z;
      
      t.A = A;
      t.B = B;
      t.C = C;
      t.nA = nA;
      t.nB = nB;
      t.nC = nC;

      scene->objects[i]->triangles[k] = t;
    }
  }
  return 1;
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
    
    o->color.r = 1;
    o->color.g = 0;
    o->color.b = 0;

    er = fscanf(f, "%s", s);
    while (!my_strncmp(s, "vn", 2) && !my_strncmp(s, "v", 1))
    {
      set_obj_mat(f, s, &m);
      er = fscanf(f, "%s", s);
    }

    o->m = m;
    
    while (er != EOF && !my_strncmp(s, "object", 6))
    {
      if (my_strcmp(s, "v"))
      {
        o->v_size += 1;
        o->v = realloc(o->v, sizeof (struct vector3) * (o->v_size + 1));
        if (!o->v)
          return 0;
        fscanf(f, "%f %f %f", &(o->v[o->v_size - 1].x), &(o->v[o->v_size - 1].y),
                              &(o->v[o->v_size - 1].z));
      }
      else
      {
        o->vn_size += 1;
        o->vn = realloc(o->vn, sizeof (struct vector3) * (o->vn_size + 1));
        if (!o->vn)
          return 0;
        fscanf(f, "%f %f %f", &(o->vn[o->vn_size - 1].x), &(o->vn[o->vn_size - 1].y), 
                              &(o->vn[o->vn_size - 1].z));
      }
      er = fscanf(f, "%s", s);
    }
    o->vn_size += 1;
    o->v_size += 1;
    scene->objects[scene->obj_count - 1] = o;
  }
  return make_triangles(scene);
}