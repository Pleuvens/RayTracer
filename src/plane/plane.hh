#pragma once

#include "object.hh"

class Plane : public Object {
    public:
        Plane() = default;

        Plane(Plane&& p) = default;

        Plane(Plane& p) = default;
        Plane(const Plane& p) = default;
        Plane& operator=(Plane& p) = default;
        Plane& operator=(const Plane& p) = default;

        ~Plane() = default;

        std::vector<Intersection> localIntersect(Ray ray);
        Vector localNormalAt(Point p) const;
};
