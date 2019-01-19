#pragma once

#include "../utils/vector3.hh"

class Triangle
{
    public:
        Triangle();
        Triangle(Vector3 A_, Vector3 B_, Vector3 C_,
        Vector3 nA_, Vector3 nB_, Vector3 nC_);

        Vector3 getA() const;
        Vector3 getB() const;
        Vector3 getC() const;
        Vector3 getNA() const;
        Vector3 getNB() const;
        Vector3 getNC() const;

        void setA(const Vector3& A_);
        void setB(const Vector3& B_);
        void setC(const Vector3& C_);
        void setNA(const Vector3& nA_);
        void setNB(const Vector3& nB_);
        void setNC(const Vector3& nC_);

        Vector3 surfaceNormal();

    protected:
        Vector3 A;
        Vector3 B;
        Vector3 C;

        Vector3 nA;
        Vector3 nB;
        Vector3 nC;
};