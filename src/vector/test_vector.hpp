#ifdef _TESTS

#include "vector.hh"
#include "op_overloading.hh"
#include "catch.hpp"

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

TEST_CASE("VECTOR: dot product of two vectors", "[multi-file:vector]")
{
    REQUIRE(isEqual(Vector::dot(Vector(1, 2, 3), Vector(2, 3, 4)), 20));
}

TEST_CASE("VECTOR: computing the magnitude", "[multi-file:vector]") {
    REQUIRE(isEqual(Vector(1, 0, 0).magnitude(), 1));
    REQUIRE(isEqual(Vector(0, 1, 0).magnitude(), 1));
    REQUIRE(isEqual(Vector(0, 0, 1).magnitude(), 1));
    REQUIRE(isEqual(Vector(1, 2, 3).magnitude(), std::sqrt(14)));
    REQUIRE(isEqual(Vector(-1, -2, -3).magnitude(), std::sqrt(14)));
}

TEST_CASE("VECTOR: normalize a vector", "[multi-file:vector]") {
    REQUIRE(Vector(4, 0, 0).normalize() == Vector(1, 0, 0));
    REQUIRE(Vector(1, 2, 3).normalize()
            == Vector(1 / std::sqrt(14), 2 / std::sqrt(14), 3 / std::sqrt(14)));
}

TEST_CASE("VECTOR: magnitude of a normalize vector", "[multi-file:vector]")
{
    REQUIRE(isEqual(Vector(1, 2, 3).normalize().magnitude(), 1));
}

TEST_CASE("VECTOR: cross product of two vectors", "[multi-file:vector]") {
    REQUIRE((Vector(1, 2, 3) * Vector(2, 3, 4)) == Vector(-1, 2, -1));
    REQUIRE((Vector(2, 3, 4) * Vector(1, 2, 3)) == Vector(1, -2, 1));
}

TEST_CASE("VECTOR: Reflecting a vector approaching at 45deg", "[multi-file:vector]")
{
    Vector v(1, -1, 0);
    Vector n(0, 1, 0);
    Vector r = v.reflect(n);
    REQUIRE(r == Vector(1, 1, 0));
}

TEST_CASE("VECTOR: Reflecting a vector off a slanted surface", "[multi-file:vector]")
{
    Vector v(0, -1, 0);
    const float value = std::sqrt(2) / 2;
    Vector n(value, value, 0);
    Vector r = v.reflect(n);
    REQUIRE(r == Vector(1, 0, 0));
}

#endif
