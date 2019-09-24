#pragma once

class Color {
    public:
        Color(float red, float green, float blue);

        inline float getRed(void) const { return _red; }
        inline float getGreen(void) const { return _green; }
        inline float getBlue(void) const { return _blue; }

        inline void setRed(const float red) { _red = red; }
        inline void setGreen(const float green) { _green = green; }
        inline void setBlue(const float blue) { _blue = blue; }

    private:
        float _red;
        float _green;
        float _blue;
};
