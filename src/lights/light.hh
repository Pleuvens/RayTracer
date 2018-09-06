#pragma once

#include "../utils/vector3.hh"
#include "../utils/color.hh"

class Light
{
    public:
        Light(Color color_, Vector3 pos_);

        Color getColor();
        Vector3 getPos();

        void setColor(Color color_);
        void setPos(Vector3 pos_);

        virtual void apply() = 0;

    protected:
        Color color;
        Vector3 pos;
};