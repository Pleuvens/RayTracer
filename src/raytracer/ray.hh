#pragma once

#include "../utils/vector3.hh"
#include "../objects/triangle.hh"

class Ray
{
    public:
        Ray(Vector3 origin_, Vector3 direction_);

        Vector3 getOrigin();
        Vector3 getDirection();

        void setOrigin(Vector3 origin_);
        void setDirection(Vector3 direction_);

        bool triangleIntersection(Triangle triangle, Vector3 &p);

    protected:
        Vector3 origin;
        Vector3 direction;
};