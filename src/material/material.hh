#pragma once

#include "color.hh"
#include "point.hh"
#include "point_light.hh"

class Material {
    public:
        Material();

        inline Color getColor(void) const { return _color; }
        inline float getAmbient(void) const { return _ambient; }
        inline float getDiffuse(void) const { return _diffuse; }
        inline float getSpecular(void) const { return _specular; }
        inline float getShininess(void) const { return _shininess; }

        inline void setColor(const Color& c) { _color = c; }
        inline void setAmbient(const float v) { _ambient = v; }
        inline void setDiffuse(const float v) { _diffuse = v; }
        inline void setSpecular(const float v) { _specular = v; }
        inline void setShininess(const float v) { _shininess = v; }

        Color lighting(const PointLight& light, const Point& point, const Vector& eye,
                Vector normal);

        bool operator==(const Material& m) const;
    private:
        Color _color;
        float _ambient;
        float _diffuse;
        float _specular;
        float _shininess;
};
