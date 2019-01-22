#include "material.hh"

Material::Material(Color ambient_reflectivity_, Color diffuse_reflectivity_, Color specular_reflectivity_, 
        float specular_exponent_, float optical_density_, float reflection_coefficient_, float dissolve_)
{
    ambient_reflectivity = ambient_reflectivity_;
    diffuse_reflectivity = diffuse_reflectivity_;
    specular_reflectivity = specular_reflectivity_;
    specular_exponent = specular_exponent_;
    optical_density = optical_density_;
    reflection_coefficient = reflection_coefficient_;
    dissolve = dissolve_;
}

Color Material::getAmbientReflectivity() const
{
    return ambient_reflectivity;
}

Color Material::getDiffuseReflectivity() const
{
    return diffuse_reflectivity;
}

Color Material::getSpecularReflectivity() const
{
    return specular_reflectivity;
}

float Material::getSpecularExponent() const
{
    return specular_exponent;
}

float Material::getOpticalDensity() const
{
    return optical_density;
}

float Material::getReflectionCoefficient() const
{
    return reflection_coefficient;
}

float Material::getDissolve() const
{
    return dissolve;
}

void Material::setAmbientReflectivity(const Color& ambient_reflectivity_)
{
    ambient_reflectivity = ambient_reflectivity_;
}

void Material::setDiffuseReflectivity(const Color& diffuse_reflectivity_)
{
    diffuse_reflectivity = diffuse_reflectivity_;
}

void Material::setSpecularReflectivity(const Color& specular_reflectivity_)
{
    specular_reflectivity = specular_reflectivity_;
}

void Material::setSpecularExponent(const float& specular_exponent_)
{
    specular_exponent = specular_exponent_;
}

void Material::setOpticalDensity(const float& optical_density_)
{
    optical_density = optical_density_;
}

void Material::setReflectionCoefficient(const float& reflection_coefficient_)
{
    reflection_coefficient = reflection_coefficient_;
}

void Material::setDissolve(const float& dissolve_)
{
    dissolve = dissolve_;
}