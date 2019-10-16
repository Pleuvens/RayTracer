#pragma once

#include <vector>

#include "point.hh"
#include "vector.hh"
#include "sphere.hh"
#include "intersection.hh"

class Ray
{
    public:
        Ray(const Point& origin, const Vector& direction);

        inline Point getOrigin(void) const { return _origin; }
        inline Vector getDirection(void) const { return _direction; }
        inline void setOrigin(const Point& origin) { _origin = origin; }
        inline void setDirection(const Vector& direction) { _direction = direction; }
        
        inline Tuple position(const float t) { return _origin + _direction * t; }

        std::vector<Intersection> intersect(const Sphere& s);

        Ray transform(Matrix& m);

    private:
        Point _origin;
        Vector _direction;
};