#include <cmath>
#include "tuple.hh"
#include "constants.hh"
#ifdef _TESTS
#include "catch.hpp"
#endif

Tuple::Tuple(const float x, const float y, const float z, const float w)
    : _x(x), _y(y), _z(z), _w(w)
{}

Tuple Tuple::operator+(const Tuple& b)
{
    return Tuple(_x + b._x, _y + b._y, _z + b._z, _w + b._w);
}

Tuple Tuple::operator+=(const Tuple& b)
{
    _x += b._x;
    _y += b._y;
    _z += b._z;
    _w += b._w;
    return *this;
}

#ifdef _TESTS
TEST_CASE("TUPLE: add 2 tuples", "[multi-file:tuple]") {
    REQUIRE((Tuple(3, -2, 5, 1) + Tuple(-2, 3, 1, 0)) == Tuple(1, 1, 6, 1));
    Tuple t = Tuple(3, -2, 5, 1);
    REQUIRE((t += Tuple(-2, 3, 1, 0)) == Tuple(1, 1, 6, 1));
}
#endif

Tuple Tuple::operator-(const Tuple& b)
{
    return Tuple(_x - b._x, _y - b._y, _z - b._z, _w - b._w);
}

Tuple Tuple::operator-=(const Tuple& b)
{
    _x -= b._x;
    _y -= b._y;
    _z -= b._z;
    _w -= b._w;
    return *this;
}

Tuple Tuple::operator-()
{
    return Tuple(-_x, -_y, -_z, -_w);
}

#ifdef _TESTS
TEST_CASE("TUPLE: negating a tuple", "[multi-file:tuple]") {
    REQUIRE(-Tuple(1, -2, 3, -4) == Tuple(-1, 2, -3, 4));
}
#endif

Tuple Tuple::operator*(const float lambda)
{
    return Tuple(lambda * _x, lambda * _y, lambda * _z, lambda * _w);
}

Tuple Tuple::operator*=(const float lambda)
{
    _x *= lambda;
    _y *= lambda;
    _z *= lambda;
    _w *= lambda;
    return *this;
}

#ifdef _TESTS
TEST_CASE("TUPLE: multiplying a tuple by a scalar", "[multi-file:tuple]") {
    REQUIRE((Tuple(1, -2, 3, -4) * 3.5) == Tuple(3.5, -7, 10.5, -14));
    Tuple t = Tuple(1, -2, 3, -4);
    REQUIRE((t * 3.5) == Tuple(3.5, -7, 10.5, -14));
}

TEST_CASE("TUPLE: multiplying a tuple by a fraction", "[multi-file:tuple]") {
    REQUIRE((Tuple(1, -2, 3, -4) * 0.5) == Tuple(0.5, -1, 1.5, -2));
    Tuple t = Tuple(1, -2, 3, -4);
    REQUIRE((t * 0.5) == Tuple(0.5, -1, 1.5, -2));
}
#endif

Tuple Tuple::operator/(const float lambda)
{
    return Tuple(_x / lambda,  _y / lambda, _z / lambda, _w / lambda);
}

Tuple Tuple::operator/=(const float lambda)
{
    _x /= lambda;
    _y /= lambda;
    _z /= lambda;
    _w /= lambda;
    return *this;
}

#ifdef _TESTS
TEST_CASE("TUPLE: dividing a tuple by a scalar", "[multi-file:tuple]") {
    REQUIRE((Tuple(1, -2, 3, -4) / 2) == Tuple(0.5, -1, 1.5, -2));
    Tuple t = Tuple(1, -2, 3, -4);
    REQUIRE((t /= 2) == Tuple(0.5, -1, 1.5, -2));
}
#endif

bool Tuple::operator==(const Tuple& b) const
{
    return std::abs(_x - b._x) < EPSILON && std::abs(_y - b._y) < EPSILON
        && std::abs(_z - b._z) < EPSILON && std::abs(_w - b._w) < EPSILON;
}

bool Tuple::operator!=(const Tuple& b) const
{
    return std::abs(_x - b._x) > EPSILON || std::abs(_y - b._y) > EPSILON
        || std::abs(_z - b._z) > EPSILON || std::abs(_w - b._w) > EPSILON;
}
