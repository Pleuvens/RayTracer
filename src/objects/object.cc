#include "object.hh"

Object::Object(int vsize, int vnsize, Material m_,
        std::vector<Vector3> v_, std::vector<Vector3> vn_,
        std::vector<Triangle> triangles_, Color color_, Material material_)
{
    v_size = vsize;
    vn_size = vnsize;
    v = v_;
    vn = vn_;
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

std::vector<Vector3> Object::getV() const
{
    return v;
}

std::vector<Vector3> Object::getVn() const
{
    return vn;
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

void Object::setV(const std::vector<Vector3>& v_)
{
    v = v_;
}

void Object::setVn(const std::vector<Vector3>& vn_)
{
    vn = vn_;
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