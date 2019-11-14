#pragma once

#include "object.hh"
#include "ray.hh"

class Sphere : public Object {
    public:
        Sphere();

        Sphere(Sphere&& s) = default;

        Sphere(Sphere& s) = default;
        Sphere(const Sphere& s) = default;
        Sphere& operator=(Sphere& s) = default;
        Sphere& operator=(const Sphere& s) = default;

        ~Sphere() = default;

        static const Sphere& glassSphere() noexcept;

        std::vector<Intersection> localIntersect(Ray ray);
        Vector localNormalAt(Point p) const;
};
