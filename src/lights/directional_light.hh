#pragma once

#include "light.hh"
#include "../objects/object.hh"

class DirectionalLight : public Light
{
    public:
        DirectionalLight();
        DirectionalLight(Color color_, Vector3 pos_);

        Color apply(Object object, int triangle_index);

};