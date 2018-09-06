#pragma once

#include "light.hh"

class PointLight : Light
{
    public:
        PointLight(Color color_, Vector3 pos_);
        
        void apply() override;
};