#include <cmath>

#include "vector3.hh"

Vector3::Vector3(float x_, float y_, float z_)
{
    x = x_;
    y = y_;
    z = z_;
}

float Vector3::getX() const
{
    return x;
}

float Vector3::getY() const
{
    return y;
}

float Vector3::getZ() const
{
    return z;
}

void Vector3::setX(float value)
{
    x = value;
}

void Vector3::setY(float value)
{
    y = value;
}

void Vector3::setZ(float value)
{
    z = value;
}

void Vector3::inverse()
{
    x = 1 / x;
    y = 1 / y;
    z = 1 / z;
}

void Vector3::normalize()
{
    float nx = x / sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    float ny = y / sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    float nz = z / sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    x = nx;
    y = ny;
    z = nz;
}

float Vector3::distance(Vector3 const& b)
{
    return sqrt(pow(b.x - x, 2) + pow(b.y - y, 2) + pow(b.z - z, 2)); 
}

Vector3 Vector3::fromPoints(Vector3 const& p1, Vector3 const& p2)
{
    return Vector3(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

Vector3 Vector3::operator+(const Vector3& b)
{
    return Vector3(x + b.getX(), y + b.getY(), z + b.getZ());
}

Vector3 Vector3::operator+=(const Vector3& b)
{
    x += b.getX();
    y += b.getY();
    z += b.getZ();
    return *this;
}

Vector3 Vector3::operator-(const Vector3& b)
{
    return Vector3(x - b.getX(), y - b.getY(), z - b.getZ());
}

Vector3 Vector3::operator-=(const Vector3& b)
{
    x -= b.getX();
    y -= b.getY();
    z -= b.getZ();
    return *this;
}

Vector3 Vector3::operator*(const Vector3& b)
{
    return Vector3(y * b.getZ() - z * b.getY(), z * b.getX() - x * b.getZ(), x * b.getY() - x * b.getX());
}

Vector3 Vector3::operator*=(const Vector3& b)
{
    float cx = y * b.z - z * b.y;
    float cy = z * b.x - x * b.z;
    float cz = x * b.y - y * b.x;
    x = cx;
    y = cy;
    z = cz;
    return *this;
}

Vector3 Vector3::operator*(float lambda)
{
    return Vector3(lambda * x, lambda * y, lambda * z);
}

Vector3 Vector3::operator*=(float lambda)
{
    x *= lambda;
    y *= lambda;
    z *= lambda;
    return *this;
}