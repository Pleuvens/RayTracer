#include <cmath>

#include "material.hh"
#include "op_overloading.hh"

#include "test_material.hpp"

Material::Material()
    : _color(Color(1, 1, 1)), _ambient(0.1), _diffuse(0.9), _specular(0.9),
            _shininess(200.0)
{}

Color Material::lighting(const PointLight& light, const Point& point, const Vector& eye,
        Vector& normal)
{
    // combine surface color with light color/intensity
    auto effective_color = _color * light.getIntensity();
    // find direction to light source
    auto light_v = Vector(light.getPosition() - point).normalize();
    auto ambient = effective_color * _ambient;
    Color diffuse = Color::black();
    Color specular = Color::black();
    // light_dot_normal is the cosine of the angle between
    // the light vector and the normal vector
    // negative means light is on the other side of the surface
    auto light_dot_normal = Vector::dot(light_v, normal);
    if (light_dot_normal >= 0)
    {
        // compute diffuse distribution
        diffuse = effective_color * _diffuse * light_dot_normal;
        // reflect_dot_eye is the cosine of the angle between
        // the reflection vector and the eye vector
        // negative means light reflects away from the eye
        auto reflect_v = (light_v * -1).reflect(normal);
        auto reflect_dot_eye = Vector::dot(reflect_v, eye);
        if (reflect_dot_eye <= 0)
            specular = Color::black();
        else {
            // compute specular contribution
            auto factor = std::pow(reflect_dot_eye, _shininess);
            specular = light.getIntensity() * _specular * factor;
        }
    }

    return ambient + diffuse + specular; // add the three for final shading
}

bool Material::operator==(const Material& m) const
{
    return _color == m._color && isEqual(_ambient, m._ambient)
        && isEqual(_diffuse, m._diffuse) && isEqual(_specular, m._specular)
        && isEqual(_shininess, m._shininess);
}
