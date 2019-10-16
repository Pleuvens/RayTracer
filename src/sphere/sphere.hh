#pragma once

#include <vector>

#include "matrix.hh"

class Sphere {
    public:
        Sphere();

        inline Matrix getTransform(void) const { return _transform; }
        inline void setTransform(const Matrix& m) { _transform = m; }

        bool operator==(const Sphere& s) const { (void)s; return true; }
    private:
        Matrix _transform;
};
