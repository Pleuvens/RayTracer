#include "intersection.hh"
#include "sphere.hh"
#include "test_intersection.hpp"

Intersection::Intersection(const float t, const Sphere& obj)
    : _t(t), _object(obj)
{}

std::vector<Intersection>
Intersection::intersections(std::initializer_list<Intersection> list)
{
    return std::vector<Intersection> (list);
}
