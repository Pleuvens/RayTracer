#include "triangle.hh"

Triangle::Triangle()
{}

Triangle::Triangle(Vector3 A_, Vector3 B_, Vector3 C_,
        Vector3 normalA_, Vector3 normalB_, Vector3 normalC_)
{
    A = A_;
    B = B_;
    C = C_;
    normalA = normalA_;
    normalB = normalB_;
    normalC = normalC_;
}

Vector3 Triangle::getA() const
{
    return A;
}

Vector3 Triangle::getB() const
{
    return B;
}

Vector3 Triangle::getC() const
{
    return C;
}

Vector3 Triangle::getNormalA() const
{
    return normalA;
}

Vector3 Triangle::getNormalB() const
{
    return normalB;
}

Vector3 Triangle::getNormalC() const
{
    return normalC;
}

void Triangle::setA(const Vector3& A_)
{
    A = A_;
}

void Triangle::setB(const Vector3& B_)
{
    B = B_;
}

void Triangle::setC(const Vector3& C_)
{
    C = C_;
}

void Triangle::setNormalA(const Vector3& normalA_)
{
    normalA = normalA_;
}

void Triangle::setNormalB(const Vector3& normalB_)
{
    normalB = normalB_;
}

void Triangle::setNormalC(const Vector3& normalC_)
{
    normalC = normalC_;
}

Vector3 Triangle::surfaceNormal()
{
    return ((B + A * -1) * (C + A * -1)).normalize();
}
