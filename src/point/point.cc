#include "point.hh"
#include "vector.hh"
#include "test_point.hpp"

Point::Point(const float x, const float y, const float z)
    : Tuple(x, y, z, 1.0)
{}
