#pragma once

#include <vector>

#include "matrix.hh"
#include "vector.hh"
#include "point.hh"

class Sphere {
    public:
        Sphere();

        inline Matrix getTransform(void) const { return _transform; }
        inline void setTransform(const Matrix& m) { _transform = m; }

        Vector normalAt(Point& p);

        bool operator==(const Sphere& s) const { (void)s; return true; }
    private:
        Matrix _transform;
};
