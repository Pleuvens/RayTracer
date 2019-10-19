#pragma once

#include <vector>

#include "matrix.hh"
#include "vector.hh"
#include "point.hh"
#include "material.hh"

class Sphere {
    public:
        Sphere();

        inline Matrix getTransform(void) const { return _transform; }
        inline Material getMaterial(void) const { return _material; }

        inline void setTransform(const Matrix& m) { _transform = m; }
        inline void setMaterial(const Material& m) { _material = m; }

        Vector normalAt(Point& p);

        bool operator==(const Sphere& s) const { (void)s; return true; }

    private:
        Matrix _transform;
        Material _material;
};
