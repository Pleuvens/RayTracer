#include "sphere.hh"
#include "test_sphere.hpp"

Sphere::Sphere()
    : _transform(Matrix::identity(4))
{}

Vector Sphere::normalAt(Point& p)
{
    Point origin(0, 0, 0);
    return Vector(p - origin).normalize();
}
