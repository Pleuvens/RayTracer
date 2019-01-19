#include "ambient_light.hh"

AmbientLight::AmbientLight(Color color_, Vector3 pos_)
    : Light(color_, pos_)
{}

void AmbientLight::apply()
{}