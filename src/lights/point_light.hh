#pragma once

#include "color.hh"
#include "point.hh"

class PointLight {
    public:
        PointLight(const Point& position, const Color& intensity);

        inline Point getPosition(void) const { return _position; }
        inline Color getIntensity(void) const { return _intensity; }

        inline void setPosition(const Point& p) { _position = p; }
        inline void setIntensity(const Color& i) { _intensity = i; }

        bool operator==(const PointLight& p) const;
    private:
        Point _position;
        Color _intensity;
};
