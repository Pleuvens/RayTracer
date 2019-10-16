#pragma once

#include "tuple.hh"
#include "vector.hh"

class Point : public Tuple {
    public:
        Point(const float x, const float y, const float z);
        Point(const Tuple& t);
};
