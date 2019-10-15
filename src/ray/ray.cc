#include <cmath>

#include "ray.hh"
#include "test_ray.hpp"

Ray::Ray(const Point& origin, const Vector& direction)
    : _origin(origin), _direction(direction)
{}

std::vector<Intersection> Ray::intersect(const Sphere& s)
{
    Vector sphere_to_ray(_origin - Point(0, 0, 0));
    float a = Vector::dot(_direction, _direction);
    float b = 2 * Vector::dot(_direction, sphere_to_ray);
    float c = Vector::dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = b * b - 4 * a * c;

    std::vector<Intersection> xs;

    if (discriminant < 0)
        return xs;
    xs.reserve(2);
    xs.emplace_back((-b - std::sqrt(discriminant)) / (2 * a), s);
    xs.emplace_back((-b + std::sqrt(discriminant)) / (2 * a), s);
    return xs;
}
