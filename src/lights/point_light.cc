#include "point_light.hh"

PointLight::PointLight(Color color_, Vector3 pos_)
    : Light(color_, pos_)
{}

Color PointLight::apply(Object object, int triangle_index, float distance)
{
    Vector3 L = direction.inverse();

    Color diffuse = object.getMaterial().getDiffuseReflectivity() * color;

    float light_direction = Vector3::dotProduct(L, object.getTriangles()[triangle_index].getNormalA());

    if (light_direction)
        light_direction = 0;

    light_direction = light_direction / distance;

    return diffuse * light_direction;
}

Vector3 PointLight::getDirection()
{
    return direction;
}

void PointLight::setDirection(const Vector3& direction_)
{
    direction = direction_;
}