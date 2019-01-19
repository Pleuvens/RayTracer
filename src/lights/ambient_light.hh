#pragma once

#include "light.hh"

class AmbientLight : Light
{
    public:
        AmbientLight();
        AmbientLight(Color color_, Vector3 pos_);

        void apply() override;
};