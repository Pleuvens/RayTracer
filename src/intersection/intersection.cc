#include "intersection.hh"
#include "sphere.hh"
#include "op_overloading.hh"
#include "test_intersection.hpp"

Intersection::Intersection(const float t, const Sphere& obj)
    : _t(t), _object(obj)
{}

std::vector<Intersection>
Intersection::intersections(std::initializer_list<Intersection> list)
{
    return std::vector<Intersection> (list);
}

std::optional<Intersection> Intersection::hit(std::vector<Intersection> xs)
{
    std::optional<Intersection> min = std::nullopt;
    for (size_t i = 0; i < xs.size(); i++)
    {
        if (xs[i].getT() < 0)
            continue;
        if (min == std::nullopt)
            min = xs[i];
        else if (min != std::nullopt && min->getT() > xs[i].getT())
            min = xs[i];
    }
    return min;
}

bool Intersection::operator==(const Intersection& i) const
{
    return isEqual(_t, i._t) && _object == i._object;
}
