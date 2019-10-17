#include "sphere.hh"
#include "test_sphere.hpp"

Sphere::Sphere()
    : _transform(Matrix::identity(4))
{}

Vector Sphere::normalAt(Point& p)
{
    Point origin(0, 0, 0);
    Point object_point(_transform.invert() * p);
    Vector object_normal = Vector(object_point - origin);
    Vector world_normal(_transform.invert().transpose() * object_normal);
    world_normal.setW(0);
    return world_normal.normalize();
}
