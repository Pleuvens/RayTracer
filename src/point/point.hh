#pragma once

#include "tuple.hh"
#include "vector.hh"

class Point : public Tuple {
    public:
        Point() = default;
        Point(const float x, const float y, const float z);
        Point(const Tuple& t);

        Point(Point&& p) = default;

        Point(Point& p) = default;
        Point& operator=(Point& p) = default;
        Point& operator=(const Point& p) = default;

        ~Point() = default;
};
