#include <cmath>

#include "constants.hh"
#include "ray.hh"

#include "test_ray.hpp"

Ray::Ray(const Point& origin, const Vector& direction)
    : _origin(origin), _direction(direction)
{}

std::vector<Intersection> Ray::intersect(Object& s)
{
    auto local_ray = transform(s.getTransform().invert());
    return s.intersect(local_ray);
}

Intersection Ray::prepareComputations(Intersection i)
{
    i.setPoint(position(i.getT()));
    i.setEyeVector(getDirection() * -1);
    i.setNormalVector(i.getObject().normalAt(i.getPoint()));
    i.setInside(false);
    if (Vector::dot(i.getNormalVector(), i.getEyeVector()) < 0)
    {
        i.setInside(true);
        i.setNormalVector(i.getNormalVector() * -1);
    }
    i.setOverPoint(Point(i.getPoint() + i.getNormalVector() * EPSILON));
    i.setReflectVector(_direction.reflect(i.getNormalVector()));
    return i;
}

Ray Ray::transform(const Matrix& m)
{
    Point origin = m * _origin; 
    Vector direction = m * _direction;
    return Ray(origin, direction);
}
