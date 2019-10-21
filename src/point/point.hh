#pragma once

#include "tuple.hh"
#include "vector.hh"

class Point : public Tuple {
    public:
        Point() = default;
        Point(const float x, const float y, const float z);
        Point(const Tuple& t);
};
