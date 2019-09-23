#include <cmath>
#include "tuple.hh"
#include "catch.hpp"
#include "constants.hh"

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

Tuple Tuple::operator*(const Tuple& b)
{
    return Tuple(_y * b._z - _z * b._y, _z * b._x - _x * b._z, _x * b._y - _x * b._x, _w);
}

Tuple Tuple::operator*=(const Tuple& b)
{
    float cx = _y * b._z - _z * b._y;
    float cy = _z * b._x - _x * b._z;
    float cz = _x * b._y - _y * b._x;
    _x = cx;
    _y = cy;
    _z = cz;
    return *this;
}

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
