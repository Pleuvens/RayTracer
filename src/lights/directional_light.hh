#pragma once

#include "light.hh"

class DirectionalLight : Light
{
    public:
        DirectionalLight(Color color_, Vector3 pos_);

        void apply() override;

};