#pragma once

#include "../utils/vector3.hh"

class Triangle
{
    public:
        Triangle();
        Triangle(Vector3 A_, Vector3 B_, Vector3 C_,
        Vector3 normalA_, Vector3 normalB_, Vector3 normalC_);

        Vector3 getA() const;
        Vector3 getB() const;
        Vector3 getC() const;
        Vector3 getNormalA() const;
        Vector3 getNormalB() const;
        Vector3 getNormalC() const;

        void setA(const Vector3& A_);
        void setB(const Vector3& B_);
        void setC(const Vector3& C_);
        void setNormalA(const Vector3& normalA_);
        void setNormalB(const Vector3& normalB_);
        void setNormalC(const Vector3& normalC_);

        Vector3 surfaceNormal();

    protected:
        Vector3 A;
        Vector3 B;
        Vector3 C;

        Vector3 normalA;
        Vector3 normalB;
        Vector3 normalC;
};