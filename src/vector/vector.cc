#include <cmath>

#include "vector.hh"
#include "test_vector.hpp"

Vector::Vector(const float x, const float y, const float z)
    : Tuple(x, y, z, 0.0)
{}

Vector::Vector(const Tuple& t)
    : Tuple(t.getX(), t.getY(), t.getZ(), 0.0)
{}

float Vector::dot(const Vector& v1, const Vector& v2)
{
    return v1.getX() * v2.getX() + v1.getY() * v2.getY()
        + v1.getZ() * v2.getZ() + v1.getW() * v2.getW();
}

float Vector::magnitude(void) const
{
    return std::sqrt(_x * _x + _y * _y
            + _z * _z + _w * _w);
}

Vector Vector::normalize(void)
{
    auto mgtude = this->magnitude();
    _x =_x / mgtude;
    _y =_y / mgtude;
    _z =_z / mgtude;
    _w =_w / mgtude;
    return *this;
}

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
