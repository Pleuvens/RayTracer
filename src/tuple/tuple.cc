#include <cmath>
#include "tuple.hh"
#include "test_tuple.hpp"

Tuple::Tuple(const float x, const float y, const float z, const float w)
    : _x(x), _y(y), _z(z), _w(w)
{}

float Tuple::getValue(const int index) const
{
    switch (index)
    {
        case 0:
            return _x;
        case 1:
            return _y;
        case 2:
            return _z;
        case 3:
            return _w;
        default:
            throw "TUPLE: Invalid index";
    }
}

void Tuple::setValue(const int index, const float value)
{
    switch (index)
    {
        case 0:
            _x = value;
            break;
        case 1:
            _y = value;
            break;
        case 2:
            _z = value;
            break;
        case 3:
            _w = value;
            break;
        default:
            throw "TUPLE: Invalid index";
    }
}

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

Tuple Tuple::operator-()
{
    return Tuple(-_x, -_y, -_z, -_w);
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

bool Tuple::operator==(const Tuple& b) const
{
    return _x == b._x && _y == b._y && _z == b._z && _w == b._w;
}

bool Tuple::operator!=(const Tuple& b) const
{
    return _x != b._x || _y != b._y || _z != b._z || _w != b._w;
}
