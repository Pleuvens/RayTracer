#include "object.hh"

Object::Object()
{}

Object::Object(std::vector<Vector3> vertex_, std::vector<Vector3> vertex_normal_,
        std::vector<Triangle> triangles_, Color color_, Material material_)
{
    vertex = vertex_;
    vertex_normal = vertex_normal_;
    triangles = triangles_;
    color = color_;
    material = material_;
}

int Object::getVSize() const
{
    return vertex.size();
}

int Object::getVnSize() const
{
    return vertex_normal.size();
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


void Object::setVertex(const std::vector<Vector3>& vertex_)
{
    vertex = vertex_;
}

void Object::setVertexNormal(const std::vector<Vector3>& vertex_normal_)
{
    vertex_normal = vertex_normal_;
}

void Object::setTriangles()
{
    for (size_t i = 0; i < vertex.size(); i += 3)
    {
        triangles.push_back(Triangle(vertex[i], vertex[i+1], vertex[i+2],
            vertex_normal[i], vertex_normal[i+1], vertex_normal[i+2]));
    }
}

void Object::setColor(const Color& color_)
{
    color = color_;
}

void Object::setMaterial(const Material& material_)
{
    material = material_;
}