#include <memory>

#include "constants.hh"
#include "intersection.hh"
#include "plane.hh"
#include "ray.hh"

#include "test_plane.hpp"

std::vector<Intersection> Plane::intersect(Ray ray)
{
    std::vector<Intersection> res;
    _saved_ray = std::make_shared<Ray>(ray);
    if (std::abs(ray.getDirection().getY() < EPSILON))
        return res;
    auto t = -ray.getOrigin().getY() / ray.getDirection().getY();
    res.push_back(Intersection(t,
                std::make_shared<Plane>(*this)));
    return res;
}

Vector Plane::localNormalAt(__attribute__((unused)) Point p) const
{
    return Vector(0, 1, 0);
}
