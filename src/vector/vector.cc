#include "vector.hh"
#include "catch.hpp"

Vector::Vector(const float x, const float y, const float z)
    : Tuple(x, y, z, 0.0)
{}

TEST_CASE("VECTOR: creates tuple with w=0", "[multi-file:vector]") {
    REQUIRE(Vector(0, 0, 0) == Tuple(0, 0, 0, 0));
    REQUIRE(Vector(12, 0, 0) == Tuple(12, 0, 0, 0));
    REQUIRE(Vector(0, 21, -1) == Tuple(0, 21, -1, 0));
}
