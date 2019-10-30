#pragma once

#include "color.hh"
#include "point.hh"

class PointLight {
    public:
        PointLight() = default;
        PointLight(const Point& position, const Color& intensity);

        PointLight(PointLight&& p) = default;

        PointLight(PointLight& p) = default;
        PointLight& operator=(PointLight& p) = default;
        PointLight& operator=(const PointLight& p) = default;

        ~PointLight() = default;

        inline const Point& getPosition(void) const { return _position; }
        inline const Color& getIntensity(void) const { return _intensity; }

        inline void setPosition(const Point& p) { _position = p; }
        inline void setIntensity(const Color& i) { _intensity = i; }

        bool operator==(const PointLight& p) const;
    private:
        Point _position;
        Color _intensity;
};
