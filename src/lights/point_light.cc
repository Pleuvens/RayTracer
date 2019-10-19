#include "point_light.hh"

PointLight::PointLight(const Point& position, const Color& intensity)
    : _position(position), _intensity(intensity)
{}

bool PointLight::operator==(const PointLight& p) const
{
    return _position == p._position && _intensity == p._intensity;
}
