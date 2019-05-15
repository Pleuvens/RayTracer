#include "ray.hh"

Ray::Ray(Vector3 origin_, Vector3 direction_)
{
    origin = origin_;
    direction = direction_;
}

Vector3 Ray::getOrigin() const
{
    return origin;
}

Vector3 Ray::getDirection() const
{
    return direction;
}

void Ray::setOrigin(const Vector3& origin_)
{
    origin = origin_;
}

void Ray::setDirection(const Vector3& direction_)
{
    direction = direction_;
}

bool Ray::triangleIntersection(Triangle triangle, Vector3 &p)
{
    Vector3 e1 = Vector3::fromPoints(triangle.getA(), triangle.getB());
    Vector3 e2 = Vector3::fromPoints(triangle.getA(), triangle.getC());

    Vector3 h = direction * e2;
    float a = Vector3::dotProduct(e1, h);

    if (a > -epsilon && a < epsilon)
        return false;

    float f = 1 / a;

    Vector3 s = origin + triangle.getA() * -1;
    float u = f * Vector3::dotProduct(s, h);

    if (u < 0.0 || u > 1.0)
        return false;

    Vector3 q = s * e1;
    float v = f * Vector3::dotProduct(direction, q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    float t = f * Vector3::dotProduct(e2, q);

    if (t > epsilon)
    {
        p = origin + (direction.normalize() * t);
        return true;
    }

    return false;
}
