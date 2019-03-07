#include "light.hh"

Light::Light()
{}

Light::Light(Color color_, Vector3 pos_)
{
    color = color_;
    pos = pos_;
}

Color Light::getColor() const
{
    return color;
}

Vector3 Light::getPos() const
{
    return pos;
}

void Light::setColor(const Color& color_)
{
    color = color_;
}

void Light::setPos(const Vector3& pos_)
{
    pos = pos_;
}