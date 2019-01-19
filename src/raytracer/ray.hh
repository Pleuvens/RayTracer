#pragma once

#include "../utils/vector3.hh"
#include "../objects/triangle.hh"

class Ray
{
    public:
        Ray();
        Ray(Vector3 origin_, Vector3 direction_);

        Vector3 getOrigin() const;
        Vector3 getDirection() const;

        void setOrigin(const Vector3& origin_);
        void setDirection(const Vector3& direction_);

        bool triangleIntersection(Triangle triangle, Vector3 &p);

    protected:
        Vector3 origin;
        Vector3 direction;
    
    private:
        const float epsilon = 0.0000001;
};