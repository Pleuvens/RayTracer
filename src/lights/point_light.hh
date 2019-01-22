#pragma once

#include "light.hh"
#include "../objects/object.hh"

class PointLight : public Light
{
    public:
        PointLight();
        PointLight(Color color_, Vector3 pos_);
        
        Color apply(Object object, int triangle_index, float distance);

        Vector3 getDirection();
        void setDirection(const Vector3& direction_);

    protected:
        Vector3 direction;
};