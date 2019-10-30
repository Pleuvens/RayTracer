#include "intersection.hh"
#include "sphere.hh"
#include "op_overloading.hh"
#include "test_intersection.hpp"

Intersection::Intersection(const float t, Object_p obj)
    : _t(t), _object(obj)
{}

Intersection::Intersection(Intersection& i)
    : _t(i._t), _object(i._object), _point(i._point), _eye_v(i._eye_v),
    _normal_v(i._normal_v), _inside(i._inside), _over_point(i._over_point),
    _reflect_v(i._reflect_v)
{}

Intersection::Intersection(const Intersection& i)
    : _t(i._t), _object(i._object), _point(i._point), _eye_v(i._eye_v),
    _normal_v(i._normal_v), _inside(i._inside), _over_point(i._over_point),
    _reflect_v(i._reflect_v)
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

bool Intersection::operator<(const Intersection& i) const
{
    return _t < i._t;
}

bool Intersection::operator<=(const Intersection& i) const
{
    return _t < i._t || isEqual(_t, i._t);
}

bool Intersection::operator>(const Intersection& i) const
{
    return _t > i._t;
}

bool Intersection::operator>=(const Intersection& i) const
{
    return _t > i._t || isEqual(_t, i._t);
}

Intersection& Intersection::operator=(Intersection& i)
{
    _t = i._t;
    _object = i._object;
    _point = i._point;
    _eye_v = i._eye_v;
    _normal_v = i._normal_v;
    _inside = i._inside;
    _over_point = i._over_point;
    _reflect_v = i._reflect_v;
    return *this;
}

Intersection& Intersection::operator=(const Intersection& i)
{
    _t = i._t;
    _object = i._object;
    _point = i._point;
    _eye_v = i._eye_v;
    _normal_v = i._normal_v;
    _inside = i._inside;
    _over_point = i._over_point;
    _reflect_v = i._reflect_v;
    return *this;
}
