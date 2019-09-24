#pragma once

#include "tuple.hh"

class Vector : public Tuple {
    public:
        Vector(const float x, const float y, const float z);

        float magnitude(void) const;
};
