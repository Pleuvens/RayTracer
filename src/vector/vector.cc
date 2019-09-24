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

TEST_CASE("VECTOR: substract two vectors", "[multi-file:vector]") {
    REQUIRE((Vector(3, 2, 1) - Vector(5, 6, 7)) == Vector(-2, -4, -6));
}

TEST_CASE("VECTOR: substract a vector from the zero vector", "[multi-file:vector]") {
    REQUIRE((Vector(0, 0, 0) - Vector(1, -2, 3)) == Vector(-1, 2, -3));
}
