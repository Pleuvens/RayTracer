#include "directional_light.hh"

DirectionalLight::DirectionalLight(Color color_, Vector3 pos_)
    : Light(color_, pos_)
{}

Color DirectionalLight::apply(Object object, int triangle_index)
{
    Vector3 L = pos.inverse();

    Color diffuse = object.getMaterial().getDiffuseReflectivity() * color;

    float light_direction =  Vector3::dotProduct(L, object.getTriangles()[triangle_index].getNormalA());

    if (light_direction < 0)
        light_direction = 0;
    
    return diffuse * light_direction;
}