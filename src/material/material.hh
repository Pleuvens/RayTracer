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

        inline const Color& getColor(void) const { return _color; }
        inline float getAmbient(void) const { return _ambient; }
        inline float getDiffuse(void) const { return _diffuse; }
        inline float getSpecular(void) const { return _specular; }
        inline float getShininess(void) const { return _shininess; }
        inline float getReflective(void) const { return _reflective; }

        inline void setColor(const Color& c) { _color = c; }
        inline void setAmbient(const float v) { _ambient = v; }
        inline void setDiffuse(const float v) { _diffuse = v; }
        inline void setSpecular(const float v) { _specular = v; }
        inline void setShininess(const float v) { _shininess = v; }
        inline void setReflective(const float v) { _reflective = v; }

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
};
