#pragma once

#include "tuple.hh"

class Vector : public Tuple {
    public:
        Vector() = default;
        Vector(const float x, const float y, const float z);
        Vector(const Tuple& t);

        Vector(Vector&& v) = default;

        Vector(Vector& v) = default;
        Vector& operator=(Vector& v) = default;
        Vector& operator=(const Vector& v) = default;
        
        ~Vector() = default;

        static float dot(const Vector& v1, const Vector& v2);

        float magnitude(void) const;
        Vector normalize(void);
        Vector reflect(Vector v);

        Vector operator*(const Vector& v);
        Vector operator*=(const Vector& v);
        Vector operator*(const float lambda);
        Vector operator*=(const float lambda);
        Vector operator=(const Tuple& t);
};
