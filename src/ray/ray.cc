#include <cmath>

#include "ray.hh"
#include "test_ray.hpp"

Ray::Ray(const Point& origin, const Vector& direction)
    : _origin(origin), _direction(direction)
{}

std::vector<Intersection> Ray::intersect(const Sphere& s)
{
    Matrix m = s.getTransform().invert();
    Ray r = transform(m); 
    Vector sphere_to_ray(r._origin - Point(0, 0, 0));
    float a = Vector::dot(r._direction, r._direction);
    float b = 2 * Vector::dot(r._direction, sphere_to_ray);
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

Ray Ray::transform(Matrix& m)
{
    Point origin = m * _origin; 
    Vector direction = m * _direction;
    return Ray(origin, direction);
}