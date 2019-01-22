#pragma once

#include "../utils/color.hh"

class Material
{
    public:
        Material();
        Material(Color ambient_reflectivity_, Color diffuse_reflectivity_, Color specular_reflectivity_, 
        float specular_exponent_, float optical_density_, float reflection_coefficient_, float dissolve_);

        Color getAmbientReflectivity() const;
        Color getDiffuseReflectivity() const;
        Color getSpecularReflectivity() const;
        float getSpecularExponent() const;
        float getOpticalDensity() const;
        float getReflectionCoefficient() const;
        float getDissolve() const;

        void setAmbientReflectivity(const Color& ambient_reflectivity_);
        void setDiffuseReflectivity(const Color& diffuse_reflectivity_);
        void setSpecularReflectivity(const Color& specular_reflectivity_);
        void setSpecularExponent(const float& specular_exponent_);
        void setOpticalDensity(const float& optical_density_);
        void setReflectionCoefficient(const float& reflection_coefficient_);
        void setDissolve(const float& dissolve_);

    protected:
        Color ambient_reflectivity; // ka
        Color diffuse_reflectivity; // kd
        Color specular_reflectivity; // ks

        float specular_exponent; // ns
        float optical_density; // ni
        float reflection_coefficient; // nr
        float dissolve;  // d
};