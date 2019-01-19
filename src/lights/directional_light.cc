#include "directional_light.hh"

DirectionalLight::DirectionalLight(Color color_, Vector3 pos_)
    : Light(color_, pos_)
{}

void DirectionalLight::apply()
{}