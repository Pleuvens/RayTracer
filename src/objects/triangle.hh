#pragma once

#include "../utils/vector3.hh"

class Triangle
{
    public:
        Triangle(Vector3 A_, Vector3 B_, Vector3 C_,
        Vector3 nA_, Vector3 nB_, Vector3 nC_);

        Vector3 getA();
        Vector3 getB();
        Vector3 getC();
        Vector3 getNA();
        Vector3 getNB();
        Vector3 getNC();

        void setA(Vector3 A_);
        void setB(Vector3 B_);
        void setC(Vector3 C_);
        void setNA(Vector3 nA_);
        void setNB(Vector3 nB_);
        void setNC(Vector3 nC_);

        Vector3 surfaceNormal();

    protected:
        Vector3 A;
        Vector3 B;
        Vector3 C;

        Vector3 nA;
        Vector3 nB;
        Vector3 nC;
};