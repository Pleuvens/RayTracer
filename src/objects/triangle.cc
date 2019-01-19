#include "triangle.hh"

Triangle::Triangle(Vector3 A_, Vector3 B_, Vector3 C_,
        Vector3 nA_, Vector3 nB_, Vector3 nC_)
{
    A = A_;
    B = B_;
    C = C_;
    nA = nA_;
    nB = nB_;
    nC = nC_;
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

Vector3 Triangle::getNA() const
{
    return nA;
}

Vector3 Triangle::getNB() const
{
    return nB;
}

Vector3 Triangle::getNC() const
{
    return nC;
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

void Triangle::setNA(const Vector3& nA_)
{
    nA = nA_;
}

void Triangle::setNB(const Vector3& nB_)
{
    nB = nB_;
}

void Triangle::setNC(const Vector3& nC_)
{
    nC = nC_;
}

Vector3 Triangle::surfaceNormal()
{
    Vector3 normal = (B + A.inverse()) * (C + A.inverse());
}