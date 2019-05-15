#include <cmath>

#include "vector3.hh"

Vector3::Vector3()
{}

Vector3::Vector3(float x_, float y_, float z_)
{
    x = x_;
    y = y_;
    z = z_;
}

float Vector3::dotProduct(const Vector3& u, const Vector3& v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

float Vector3::distance(const Vector3& u, const Vector3& v)
{
    return sqrt(pow(v.x - u.x, 2) + pow(v.y - u.y, 2) + pow(u.z - v.z, 2)); 
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

void Vector3::setX(const float& value)
{
    x = value;
}

void Vector3::setY(const float& value)
{
    y = value;
}

void Vector3::setZ(const float& value)
{
    z = value;
}

Vector3 Vector3::inverse()
{
    float new_x = x == 0 ? 0 : 1 / x;
    float new_y = y == 0 ? 0 : 1 / y;
    float new_z = z == 0 ? 0 : 1 / z;
    return Vector3(new_x, new_y, new_z);
}

Vector3 Vector3::normalize()
{
    float nx = x / sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    float ny = y / sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    float nz = z / sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    x = nx;
    y = ny;
    z = nz;
    return *this;
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

Vector3 Vector3::operator*(const float& lambda)
{
    return Vector3(lambda * x, lambda * y, lambda * z);
}

Vector3 Vector3::operator*=(const float& lambda)
{
    x *= lambda;
    y *= lambda;
    z *= lambda;
    return *this;
}
