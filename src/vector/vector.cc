#include <cmath>

#include "vector.hh"
#include "constants.hh"

#ifdef _TESTS
#include "catch.hpp"
#endif

Vector::Vector(const float x, const float y, const float z)
    : Tuple(x, y, z, 0.0)
{}

#ifdef _TESTS
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
#endif

float Vector::dot(const Vector& v1, const Vector& v2)
{
    return v1.getX() * v2.getX() + v1.getY() * v2.getY()
        + v1.getZ() * v2.getZ() + v1.getW() * v2.getW();
}

#ifdef _TESTS
TEST_CASE("VECTOR: dot product of two vectors", "[multi-file:vector]")
{
    REQUIRE(Vector::dot(Vector(1, 2, 3), Vector(2, 3, 4)) - 20 < EPSILON);
}
#endif

float Vector::magnitude(void) const
{
    return std::sqrt(_x * _x + _y * _y
            + _z * _z + _w * _w);
}

#ifdef _TESTS
TEST_CASE("VECTOR: computing the magnitude", "[multi-file:vector]") {
    REQUIRE(Vector(1, 0, 0).magnitude() == 1);
    REQUIRE(Vector(0, 1, 0).magnitude() == 1);
    REQUIRE(Vector(0, 0, 1).magnitude() == 1);
    REQUIRE((Vector(1, 2, 3).magnitude() - std::sqrt(14)) < EPSILON);
    REQUIRE((Vector(-1, -2, -3).magnitude() - std::sqrt(14)) < EPSILON);
}
#endif

Vector Vector::normalize(void)
{
    auto mgtude = this->magnitude();
    _x =_x / mgtude;
    _y =_y / mgtude;
    _z =_z / mgtude;
    _w =_w / mgtude;
    return *this;
}

#ifdef _TESTS
TEST_CASE("VECTOR: normalize a vector", "[multi-file:vector]") {
    REQUIRE(Vector(4, 0, 0).normalize() == Vector(1, 0, 0));
    REQUIRE(Vector(1, 2, 3).normalize()
            == Vector(1 / std::sqrt(14), 2 / std::sqrt(14), 3 / std::sqrt(14)));
}

TEST_CASE("magnitude of a normalize vector", "[multi-file:vector]")
{
    REQUIRE(Vector(1, 2, 3).normalize().magnitude() - 1 < EPSILON);
}
#endif

Vector Vector::operator*(const Vector& v)
{
    return Vector(_y * v._z - _z * v._y, _z * v._x - _x * v._z, _x * v._y - _y * v._x);
}

Vector Vector::operator*=(const Vector& v)
{
    float cx = _y * v._z - _z * v._y;
    float cy = _z * v._x - _x * v._z;
    float cz = _x * v._y - _y * v._x;
    _x = cx;
    _y = cy;
    _z = cz;
    return *this;
}

#ifdef _TESTS
TEST_CASE("cross product of two vectors", "[multi-file:vector]") {
    REQUIRE((Vector(1, 2, 3) * Vector(2, 3, 4)) == Vector(-1, 2, -1));
    REQUIRE((Vector(2, 3, 4) * Vector(1, 2, 3)) == Vector(1, -2, 1));
}
#endif

Vector Vector::operator*(const float lambda)
{
    return Vector(lambda * _x, lambda * _y, lambda * _z);
}

Vector Vector::operator*=(const float lambda)
{
    _x *= lambda;
    _y *= lambda;
    _z *= lambda;
    _w *= lambda;
    return *this;
}
