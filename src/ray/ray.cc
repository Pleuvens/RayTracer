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

Intersection Ray::prepareComputations(Intersection i,
        std::vector<Intersection> xs = std::vector<Intersection>())
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
    i.setUnderPoint(Point(i.getPoint() - i.getNormalVector() * EPSILON));
    i.setReflectVector(_direction.reflect(i.getNormalVector()));

    std::vector<std::shared_ptr<Object>> containers;

    for (size_t i = 0; i < xs.size(); i++)
    {
        if (xs[i] == i)
        {
            if (!containers.size())
                i.setN1(1);
            else
                i.setN1(containers[containers.size() - 1].getMaterial().
                        getRefractiveIndex());
        }
        auto inter = std::find(containers.begin(), containers.end());
        if (inter != containers.end())
            containers.erase(inter);
        else
            containers.push_back(xs[i].getObject());
        if (xs[i] == i)
        {
            if (!containers.size())
                i.setN2(1);
            else
                i.setN2(containers[containers.size() - 1].getMaterial().
                        getRefractiveIndex());
            break;
        }
    }

    return i;
}

Ray Ray::transform(const Matrix& m)
{
    Point origin = m * _origin; 
    Vector direction = m * _direction;
    return Ray(origin, direction);
}
