#pragma once

#include "../utils/vector3.hh"
#include "../utils/color.hh"

class Light
{
    public:
        Light();
        Light(Color color_, Vector3 pos_);

        Color getColor() const;
        Vector3 getPos() const;

        void setColor(const Color& color_);
        void setPos(const Vector3& pos_);

        virtual void apply() = 0;

    protected:
        Color color;
        Vector3 pos;
};