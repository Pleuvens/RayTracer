#include <cmath>

#include "sphere.hh"
#include "test_sphere.hpp"

Sphere::Sphere()
    : Object()
{}

std::vector<Intersection> Sphere::localIntersect(Ray ray)
{
    _saved_ray = std::make_shared<Ray>(ray);
    Vector sphere_to_ray(ray.getOrigin() - Point(0, 0, 0));
    float a = Vector::dot(ray.getDirection(), ray.getDirection());
    float b = 2 * Vector::dot(ray.getDirection(), sphere_to_ray);
    float c = Vector::dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = b * b - 4 * a * c;

    std::vector<Intersection> xs;

    if (discriminant < 0)
        return xs;
    xs.reserve(2);
    xs.emplace_back((-b - std::sqrt(discriminant)) / (2 * a),
            std::make_shared<Sphere>(*this));
    xs.emplace_back((-b + std::sqrt(discriminant)) / (2 * a),
            std::make_shared<Sphere>(*this));
    return xs;
}

Vector Sphere::localNormalAt(Point p) const
{
    Point origin(0, 0, 0);
    Point object_point(_transform.invert() * p);
    Vector object_normal = Vector(object_point - origin);
    Vector world_normal(_transform.invert().transpose() * object_normal);
    world_normal.setW(0);
    return world_normal.normalize();
}
