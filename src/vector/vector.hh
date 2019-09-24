#pragma once

#include "tuple.hh"

class Vector : public Tuple {
    public:
        Vector(const float x, const float y, const float z);

        static float dot(const Vector& v1, const Vector& v2);

        float magnitude(void) const;
        Vector normalize(void);

        Vector operator*(const Vector& v);
        Vector operator*=(const Vector& v);
};
