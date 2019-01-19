#include "point_light.hh"

PointLight::PointLight(Color color_, Vector3 pos_)
    : Light(color_, pos_)
{}

void PointLight::apply()
{}