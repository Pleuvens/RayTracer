#include "object.hh"

Object::Object()
{}

Object::Object(int vsize, int vnsize,
        std::vector<Vector3> vertex_, std::vector<Vector3> vertex_normal_,
        std::vector<Triangle> triangles_, Color color_, Material material_)
{
    v_size = vsize;
    vn_size = vnsize;
    vertex = vertex_;
    vertex_normal = vertex_normal_;
    triangles = triangles_;
    color = color_;
    material = material_;
}

int Object::getVSize() const
{
    return v_size;
}

int Object::getVnSize() const
{
    return vn_size;
}

std::vector<Vector3> Object::getVertex() const
{
    return vertex;
}

std::vector<Vector3> Object::getVertexNormal() const
{
    return vertex_normal;
}

std::vector<Triangle> Object::getTriangles() const
{
    return triangles;
}

Color Object::getColor() const
{
    return color;
}

Material Object::getMaterial() const
{
    return material;
}

void Object::setVSize(const int& vsize)
{
    v_size = vsize;
}

void Object::setVnSize(const int& vnsize)
{
    vn_size = vnsize;
}

void Object::setVertex(const std::vector<Vector3>& vertex_)
{
    vertex = vertex_;
}

void Object::setVertexNormal(const std::vector<Vector3>& vertex_normal_)
{
    vertex_normal = vertex_normal_;
}

void Object::setTriangles(const std::vector<Triangle>& triangles_)
{
    triangles = triangles_;
}

void Object::setColor(const Color& color_)
{
    color = color_;
}

void Object::setMaterial(const Material& material_)
{
    material = material_;
}