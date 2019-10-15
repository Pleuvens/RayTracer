#include "intersection.hh"
#include "sphere.hh"

Intersection::Intersection(const float t, const Sphere& obj)
    : _t(t), _object(obj)
{}
