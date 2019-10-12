#ifdef _TESTS

#include "point.hh"
#include "vector.hh"
#include "catch.hpp"

TEST_CASE("POINT: creates tuple with w=1", "[multi-file:point]") {
    REQUIRE(Point(0, 0, 0) == Tuple(0, 0, 0, 1));
    REQUIRE(Point(12, 0, 0) == Tuple(12, 0, 0, 1));
    REQUIRE(Point(0, 21, -1) == Tuple(0, 21, -1, 1));
}

TEST_CASE("POINT: substract two points", "[multi-file:point]") {
    REQUIRE((Point(3, 2, 1) - Point(5, 6, 7)) == Vector(-2, -4, -6));
    Point p = Point(3, 2, 1);
    REQUIRE((p -= Point(5, 6, 7)) == Vector(-2, -4, -6));
}

TEST_CASE("POINT: substract a vector from a point", "[multi-file:point]") {
    REQUIRE((Point(3, 2, 1) - Vector(5, 6, 7)) == Point(-2, -4, -6));
}

#endif
