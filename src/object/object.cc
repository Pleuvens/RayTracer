#include "object.hh"

#include "test_object.hpp"

Object::Object()
    : _transform(Matrix::identity(4)), _material(Material())
{}

Vector Object::normalAt(Point p) const
{
    auto local_point = Point(_transform.invert() * p);
    auto local_normal = localNormalAt(local_point);
    auto world_normal = Vector(_transform.invert().transpose() * local_normal);
    world_normal.setW(0);
    return world_normal.normalize();
}

Object& Object::operator=(Object& o)
{
    _transform = o._transform;
    _material = o._material;
    return *this;
}

Object& Object::operator=(const Object& o)
{
    _transform = o._transform;
    _material = o._material;
    return *this;
}

std::vector<Intersection> Object::intersect(Ray ray)
{
    auto local_ray = ray.transform(_transform.invert());
    return localIntersect(local_ray);
}

std::vector<Intersection> TestShape::localIntersect(Ray ray)
{
    std::vector<Intersection> res;
    _saved_ray = std::make_shared<Ray>(ray);
    return res;
}

Vector TestShape::localNormalAt(Point p) const
{
    return Vector(p.getX(), p.getY(), p.getZ());
}
