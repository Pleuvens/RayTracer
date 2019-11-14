#pragma once

#include <vector>

#include "intersection.hh"
#include "point.hh"
#include "object.hh"
#include "vector.hh"

class Ray
{
    public:
        Ray(const Point& origin, const Vector& direction);

        inline Point getOrigin(void) const { return _origin; }
        inline Vector getDirection(void) const { return _direction; }
        inline void setOrigin(const Point& origin) { _origin = origin; }
        inline void setDirection(const Vector& direction) { _direction = direction; }
        
        inline Tuple position(const float t) { return _origin + _direction * t; }

        std::vector<Intersection> intersect(Object& s);
        Intersection prepareComputations(Intersection i,
                std::vector<Intersection> xs = std::vector<Intersection>());

        Ray transform(const Matrix& m);

    private:
        Point _origin;
        Vector _direction;
};
