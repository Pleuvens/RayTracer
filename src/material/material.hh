#pragma once

#include "color.hh"
#include "point.hh"

class PointLight;

class Material {
    public:
        Material();

        Material(Material&& m) = default;

        Material(Material& m) = default;
        Material(const Material& m) = default;
        Material& operator=(Material& m) = default;
        Material& operator=(const Material& m) = default;
        
        ~Material() = default;

        inline const Color& getColor(void) const noexcept { return _color; }
        inline float getAmbient(void) const noexcept { return _ambient; }
        inline float getDiffuse(void) const noexcept { return _diffuse; }
        inline float getSpecular(void) const noexcept { return _specular; }
        inline float getShininess(void) const noexcept { return _shininess; }
        inline float getReflective(void) const noexcept { return _reflective; }
        inline float getReflective(void) const noexcept { return _reflective; }
        inline float getTransparency(void) const noexcept { return _transparency; }
        inline float getRefractiveIndex(void) const noexcept {return _refractive_index;}

        inline void setColor(const Color& c) noexcept { _color = c; }
        inline void setAmbient(const float v) noexcept { _ambient = v; }
        inline void setDiffuse(const float v) noexcept { _diffuse = v; }
        inline void setSpecular(const float v) noexcept { _specular = v; }
        inline void setShininess(const float v) noexcept { _shininess = v; }
        inline void setReflective(const float v) noexcept { _reflective = v; }
        inline void setTransparency(const float v) noexcept { _transparency = v; }
        inline void setRefractiveIndex(const float v) noexcept { _refractive_index = v; }

        Color lighting(const PointLight& light, const Point& point, const Vector& eye,
                Vector normal, bool in_shadow=false) const;

        bool operator==(const Material& m) const;
    private:
        Color _color;
        float _ambient;
        float _diffuse;
        float _specular;
        float _shininess;
        float _reflective;
        float _transparency;
        float _refractive_index;
};
