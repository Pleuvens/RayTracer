#include "point.hh"
#include "catch.hpp"

Point::Point(const float x, const float y, const float z)
    : Tuple(x, y, z, 1.0)
{}

TEST_CASE("POINT: creates tuple with w=1", "[multi-file:point]") {
    REQUIRE(Point(0, 0, 0) == Tuple(0, 0, 0, 1));
    REQUIRE(Point(12, 0, 0) == Tuple(12, 0, 0, 1));
    REQUIRE(Point(0, 21, -1) == Tuple(0, 21, -1, 1));
}
